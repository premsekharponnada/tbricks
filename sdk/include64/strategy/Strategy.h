#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy
//****************************************************************************************

#include <vector>

#include "strategy/Types.h"
#include "strategy/ExtraData.h"
#include "strategy/Service.h"
#include "strategy/StrategyOptions.h"
#include "strategy/StrategyModifier.h"
#include "strategy/StrategyInstruments.h"
#include "strategy/InitializationReason.h"
#include "strategy/ParameterContext.h"
#include "strategy/AuditData.h"
#include "strategy/RequestReplyHandler.h"

#include "strategy/Ranking.h"

#include "strategy/parameter/StrategyParameters.h"
#include "strategy/parameter/StrategyInstanceParameters.h"

#include "strategy/validation/ValidationContext.h"
#include "strategy/flow/AppRequestContext.h"
#include "strategy/flow/AppResponseContext.h"

#include "strategy/limit/TradingLimitState.h"
#include "strategy/limit/TradingLimitResult.h"

namespace tbricks {

namespace pe {
class Engine;
}

class Strategy;
class IStrategyHandle;
class StrategyFilter;
class OrderRequestContext;
class OrderResponseContext;

/**
 * Parallelization handler interface.
 */
class STRATEGY_EXPORT IParallelTask
{
public:
    /**
     * Plugin-defined callback to invoke simultaneously.
     *
     * @param iteration                 Current index of iteration
     */
    virtual void PerformIteration(size_t iteration) = 0;

    void * m_context;

protected:
    virtual ~IParallelTask() = default;
};

/**
 * Idle events handler interface
 */
class STRATEGY_EXPORT IIdleHandler
{
public:
    /**
     * Plugin-defined callback to invoke on Idle event.
     * This callback will be called only once starting from
     * Plugin::PerformIdleProcessing() registration.
     */
    virtual void HandleIdle() = 0;

protected:
    virtual ~IIdleHandler() = default;
};

/**
 * App control events handler interface.
 */
class STRATEGY_EXPORT IStrategyEventHandler
{
public:
    /**
     * Process "app delete" request.
     *
     * The method is called whenever request to delete an app is received
     * from the client. App developer is expected to initiate tasks
     * required to put app into deleted state (e.g. close opened streams,
     * delete child strategies) and it is pure developer responsibility to put
     * app into Deleted state by calling Strategy::SetState() if all
     * necessary actions succeed.
     *
     * If request cannot be fulfilled within this call but operation result is
     * expected to be calculated later on in the future (e.g. it depends on
     * success of a request to child strategies), app developer shall set
     * transaction state to Pending and pending operation to Delete by calling
     * Strategy::SetTransactionPending(StrategyTransactionOperationDelete).
     *
     * If however request cannot be processed for some reason, app
     * developer shall set app pending state to Failed.
     */
    virtual void HandleDeleteRequest() = 0;

    /**
     * Process "app run" request.
     *
     * The method is called whenever request to run an app is received from
     * the client. App developer is expected to initiate tasks required to
     * put app into running state (e.g. open up some streams, create child
     * strategies) and it is pure developer responsibility to put app into
     * Running state by calling Strategy::SetState() if all necessary actions
     * succeed.
     *
     * If request cannot be fulfilled within this call but operation result is
     * expected to be calculated later on in the future (e.g. it depends on
     * success of a request to child strategies), app developer shall set
     * transaction state to Pending and pending operation to Run by calling
     * Strategy::SetTransactionPending(StrategyTransactionOperationRun).
     *
     * If however request cannot be processed for some reason, app
     * developer shall set app pending state to Failed.
     */
    virtual void HandleRunRequest() = 0;

    /**
     * Process "app pause" request.
     *
     * The method is called whenever request to pause an app is received
     * from the client. App developer is expected to initiate tasks
     * required to put app into paused state (e.g. stop child strategies)
     * and it is pure developer responsibility to put app into Paused
     * state by calling Strategy::SetState() if all necessary actions succeed.
     *
     * If request cannot be fulfilled within this call but operation result is
     * expected to be calculated later on in the future (e.g. it depends on
     * success of a request to child strategies), app developer shall set
     * transaction state to Pending and pending operation to Pause by calling
     * Strategy::SetTransactionPending(StrategyTransactionOperationPause).
     *
     * If however request cannot be processed for some reason, app
     * developer shall set app pending state to Failed.
     */
    virtual void HandlePauseRequest() = 0;

    /**
     * Process "app modify" request.
     *
     * The method is called whenever request to modify an app is received
     * from the client. App developer is expected to initiate tasks
     * required to modify an app (e.g. modify child strategies, perform
     * some calculations) and it is pure developer responsibility to put
     * app into appropriate state by calling Strategy::SetState() if all
     * necessary actions succeed -- if needed at all.
     *
     * If request cannot be fulfilled within this call but operation result is
     * expected to be calculated later on in the future (e.g. it depends on
     * success of a request to child strategies), app developer shall set
     * transaction state to Pending and pending operation to current app
     * state by calling Strategy::SetTransactionPending(GetState()).
     *
     * If however request cannot be processed for some reason, app
     * developer shall set app pending state to Failed.
     *
     * Argument "modifier" contains either parameter values or attribute values
     * specified by originator in SendModifyRequest(), or both.
     *
     * @param modifier                  Object with new parameter values
     */
    virtual void HandleModifyRequest(const StrategyModifier & modifier) = 0;

    /**
     * Validate user input.
     *
     * Method takes an argument filled in with the parameter values provided by
     * user, and the app code should validate them and modify the argument
     * accordingly -- correct the values which are illegal to the app,
     * provide suggested values if they are missing in the incoming request and
     * so forth. When all values are validated and all data is stored in
     * ValidationContext object, the app code MUST call
     * ValidationContext::SendReply().
     *
     * If some values cannot be resolved in the callback (for instance, if
     * app code needs to open a stream to calculate a value, or any other
     * asynchronous request should be made), it is developer's responsibility
     * to copy method's argument elsewhere and to call SendReply() method
     * for this copy when all values are finally resolved.
     *
     * Calling ValidationContext::SendReply() more than once yields undefined
     * behavior.
     *
     * @param context                   Validation context, contains values
     *                                  provided by the user in the validation
     *                                  request
     */
    virtual void HandleValidateRequest(tbricks::ValidationContext & context) = 0;

    /**
     * User event handler.
     *
     * Method is called in response to user-generated event sent by means of
     * Strategy::SendScheduleEvent() method.
     * stream.
     *
     * @param data                     User-defined data passed previously as
     *                                 an argument to ScheduleStrategyEvent()
     */
    virtual void HandleScheduledEvent(UserData && /* data */) {}

    /**
     * Selective diagnostic information by level from the app instance and
     * print it in strm.
     *
     * @param strm                      Output stream
     * @param level                     Level of diagnostic
     */
    virtual void GetDiagnosticInformation(std::ostream & /* strm */, const String & /* level */) {}

    /**
     * Get all diagnostic levels for app instance.
     *
     * @param                           Diagnostic levels
     */
    virtual void GetDiagnosticLevels(std::vector<String> & /* levels */) {}

protected:
    virtual ~IStrategyEventHandler();
};

class STRATEGY_EXPORT Plugin : public IStrategyEventHandler
{
public:
    Plugin();
    virtual ~Plugin();

    /**
     * Get app identifier.
     *
     * Returns unique identifier of the app in the system.
     *
     * @code
     * if (m_currentOS == app.GetIdentifier()) {
     *     UpdateChildAppState(app);
     * }
     * @endcode
     *
     * @return                          System-wide unique app identifier
     */
    StrategyIdentifier GetIdentifier() const;

    /**
     * Get app name.
     *
     * Returns high-level informational app name, e.g.
     * "Tbricks Built-in Order App".
     *
     * @return                          High-level app name
     */
    String GetName() const;

    /**
     * Get app type name.
     *
     * Returns app type name, e.g. "Order".
     *
     * @return                          App type name
     */
    String GetTypeName() const;

    /**
     * Get app type name.
     *
     * @param definition_id             App type identifier
     *
     * @return                          App type name, e.g. "Order"
     */
    static String GetTypeName(const Uuid & definition_id);

    /**
     * %Set app name.
     *
     * Sets high-level app name, the one that may later be fetched with
     * Strategy::GetName().
     *
     * @code
     * SetName("New order app");
     * @endcode
     *
     * @warning Calling this method means to update a app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param a_name                    High-level app name
     */
    void SetName(const String & a_name);

    /**
     * Get app creation time.
     *
     * This is the date and time a app was created within Tbricks system.
     *
     * @return                          Time when app was created
     */
    DateTime GetCreationTime() const;

    /**
     * %Apply app template to the app.
     *
     * @throws EmptyValueException if app_template is empty
     *
     * @throws NotFoundException if there is no tree node with app_template identifier
     *
     * @throws TypeMismatchException if corresponding tree node is of the type other than App template
     *
     * @param app_template              App template identifier
     */
    void ApplyTemplate(const TreeNodeIdentifier & template_id);

    /**
     * This function submits IParallelTask to be executed simultaneously
     * and waits for all iterations of task to complete before returning
     *
     * @param iterations                The number of iterations to perform
     * @param task                      The plugin-defined interface to
     *                                  invoke simultaneously
     */
    void ConcurrentIteration(size_t iterations, IParallelTask & task);

    /**
     * Register IIdleHandler and start waiting for Idle events
     * @param handler                   The plugin-defined interface to
     *                                  receive idle events
     */
    void PerformIdleProcessing(IIdleHandler & handler);

    /**
     * Check for pending events in callback queue
     *
     * @return       true if a plugin has pending events in callback queue
     */
    bool HasPendingCallbacks() const;

    /**
     * Put app custom audit data in storage.
     */
    void PutCustomAuditData(const AuditData & data) const;

    /**
     * Begins pending operation.
     *
     * @return                          identifier which corresponds to current
     *                                  request identifier received in request
     * @throw Exception                 if there is no pending request
     */
    Identifier BeginPendingRequest() const;

    /**
     * Completes pending request and all pending requests which began before it
     *
     * @param request_identifier        request identifier
     * @throw Exception                 On invalid request id or completed request id
     */
    void CompletePendingRequest(const Identifier & request_identifier);

    /**
     * Get parent service.
     */
    const Service GetService() const;

    /**
     * Get app type
     *
     * Returned type of the app. Can be one of the following
     * Strategy, Accessory, Calculation, Limit or Report
     *
     * @return                          App type
     */
    PluginType GetPluginType() const;

    /**
     * Get app type by app identifier
     *
     * Returned type of the app. Can be one of the following
     * Strategy, Accessory, Calculation, Limit or Report
     *
     * @return                          App type
     */
    PluginType GetPluginType(const StrategyIdentifier & strategy_type_id) const;

    /**
     * Get app type identifier.
     *
     * Returned object uniquely identifies app class in a system
     * and can be used, for example, to start an app of this type
     * or to subscribe for updates for this app type.
     *
     * @code
     * if (app.GetType() == plug_ins::Order()) {
     *     m_myOrderApps++;
     * }
     * @endcode
     *
     * @return                          App type identifier
     */
    StrategyIdentifier GetType() const;

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const Plugin & plugin) { return plugin.Print(strm); }

    String ToString() const;

    virtual std::ostream & Print(std::ostream & strm) const = 0;

private:
    friend class Trade;

protected:
    IStrategyHandle * m_handle;
};

/**
 * Strategy class is a base class for all user-defined apps. Its
 * interface provides for app data access and manipulations, and all
 * app data changes are automatically become available for interested
 * app stream listeners.
 *
 * Descendants of the class may choose to handle events sent to the
 * app from the outside by overriding appropriate callbacks
 * that come from IStrategyEventHandler. App API guarantees
 * sequential execution of app events, i.e. no callbacks will
 * ever be launched in parallel. Any modifications to the app
 * instance are not propagated to the outside until the callback
 * is finished, that is, if a callback changes e.g. app state a few times,
 * only the last state will become visible to other strategies when the
 * callback methods exits.
 */
class STRATEGY_EXPORT Strategy : public Plugin
{
public:
    class RequestResult;

public:
    /**
     * Comparison operator.
     *
     * Two app objects are said to be equal if their identifiers
     * are equal, or, in other words, they refer to the same app instance.
     *
     * Note that two instances may be different -- user code derived from
     * app and an update for this app received over a stream will be
     * equal (app identifiers are equal), but they may well have different
     * set of parameters, or have different state etc.
     *
     * @return                          "true" if objects refer to the same
     *                                  app instance, "false" otherwise
     */
    bool operator==(const StrategyIdentifier & app_id) const;

    /**
     * Comparison operator.
     *
     * Two app objects are said to be unequal if their app
     * identifiers are not equal, or, in other words, they do not refer to the
     * same app instance.
     *
     * @return                          "false" if objects refer to the same
     *                                  app instance, "true" otherwise
     */
    bool operator!=(const StrategyIdentifier & app_id) const;

    /**
     * Default destructor.
     */
    virtual ~Strategy();

    /**
     * Get app root identifier.
     *
     * Strategies in the system are organized into inheritance trees, where
     * tree root can currently be instantiated only by external requests, e.g.
     * from the GUI client. For the root app, its root identifier is set
     * to app's identifier; otherwise, when app is created its root
     * identifier is set to inheritance tree root app's identifier.
     *
     * For instance, if app S1 is created from the outside, its root
     * identifier and root identifiers of all its direct and indirect
     * descendants will be set to S1 app identifier.
     *
     * @return                          App root identifier
     */
    StrategyIdentifier GetRootIdentifier() const;

    /**
     * Get app parent identifier.
     *
     * Strategies in the system are organized into inheritance trees, where
     * tree root can currently be instantiated only by external requests, e.g.
     * from the GUI client. For the root app, its parent identifier is set
     * to app's identifier; otherwise, when app is created its parent
     * identifier is set to the identifier of the app create request
     * originator.
     *
     * For instance, if app S1 is created from the outside and it created
     * S2 and S3, and S3 created S4, strategies S2 and S3 will have their
     * parent identifiers set to S1, and for S4 it will be S3.
     *
     * @return                          App parent identifier
     */
    StrategyIdentifier GetParentIdentifier() const;

    /**
     * Get app identifier path.
     *
     * Returns a vector of app identifiers that describe the path of
     * strategies used to create this entity starting from the root app
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Get app definition identifier path.
     *
     * Returns a vector of app definition identifiers that describe the path of
     * app definitions used to create this entity starting from the root app.
     *
     * @param path                      vector of StrategyIdentifier
     */
    void GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Get current app state.
     *
     * @return                          Current app state
     */
    StrategyState GetState() const;

    /**
     * Get current app transaction state.
     *
     * @see TransactionState
     *
     * @return                          Current app transaction state
     */
    TransactionState GetTransactionState() const;

    /**
     * Get current operation the app is working on.
     *
     * @see StrategyTransactionOperation
     *
     * @return                          Operation the app is working on
     */
    StrategyTransactionOperation GetTransactionOperation() const;

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    /**
     * Get app parameters.
     *
     * @see StrategyInstanceParameters
     *
     * @return                          App parameter container.
     */
    const StrategyInstanceParameters & GetParameters() const;

    /**
     * Get app parameters.
     *
     * @see StrategyInstanceParameters
     *
     * @return                          App parameter container.
     */
    StrategyInstanceParameters & GetParameters();

    /**
     * Get forward app parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @return                          App forward parameter container.
     */
    StrategyParameters GetForwardParameters() const;

    /**
     * Get regulatory parameters.
     *
     * @return                          Regulatory parameters container.
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * Get app associated instruments.
     *
     * Returns a vector of instrument identifiers an app is known or reports
     * to support.
     *
     * @param instruments              Vector of associated instruments
     */
    void GetInstruments(std::vector<InstrumentIdentifier> & instruments) const;

    /**
     * Get user data.
     *
     * @return                          User data container
     */
    const ExtraData & GetExtraData() const;

    /**
     * Get time of last app modification.
     *
     * This is the date and time an app was modified within Tbricks system.
     *
     * @return                          Time of last app modification
     */
    DateTime GetLastModificationTime() const;

    /**
     * Get app context.
     *
     * @return                          App context
     */
    ParameterContext GetContext() const;

    /**
     * Get app context identifier.
     *
     * @return                          App context identifier
     */
    Identifier GetContextIdentifier() const;

    /**
     * Get app ranking.
     *
     * @return                          App ranking
     */
    void GetRanking(Ranking & ranking) const;

    /**
     * Get app ranking identifier.
     *
     * @return                          App ranking identifier
     */
    RankingIdentifier GetRankingIdentifier() const;

public:
    void SetAlgoLabelingManualOperationsFlag(bool manual);
    bool GetAlgoLabelingManualOperationsFlag();

public:
    /**
     * Send create request.
     *
     * Sends create request to appropriate Engine and
     * immediately allocates app instance that represents the child app.
     * The instance can later be used as a target in
     * Send[Run|Pause|Delete|Modify]Request or in HandleStrategyUpdate()
     * callback.
     *
     * @param options                   %App options, provides app creation flags and attributes
     * @param parameters                %App parameters
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendCreateRequest(const StrategyOptions & options,
                                           const StrategyParameters & parameters,
                                           IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Sends async create request.
     *
     * Sends app create request asynchronously to appropriate Engine.
     * Asynchronously means return object will have empty app identifier, the identifier of
     * created app can be received via app update.
     * App instance will be taken from app pool if the pool
     * has appropriate configuration, otherwise, the app will
     * be created as usual.
     *
     * @see                             app pooling documentation
     *
     * @param options                   %App options, provides app creation flags and attributes
     * @param parameters                %App parameters
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendAsyncCreateRequest(const StrategyOptions & options,
                                                const StrategyParameters & parameters,
                                                IStrategyRequestReplyHandler & handler = IStrategyRequestReplyHandler::Default());

    /**
     * Send modify request.
     *
     * Argument "modifier" allows to alter app attributes as well as app parameter values.
     *
     * @param app_id                    Identifier of the request target
     * @param modifier                  Modification request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendModifyRequest(const StrategyIdentifier & app_id,
                                           const StrategyModifier & modifier,
                                           IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send run request.
     *
     * @param app_id                    Identifier of the request target
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendRunRequest(const StrategyIdentifier & app_id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send pause request.
     *
     * @param app_id                    Identifier of the request target
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendPauseRequest(const StrategyIdentifier & app_id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send delete request.
     *
     * @param app_id                    Identifier of the request target
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendDeleteRequest(const StrategyIdentifier & app_id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send delete request for all strategies matching the filter
     *
     * @param filter                    Request filter
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Strategy::RequestResult object
     */
    static RequestResult SendDeleteRequest(const StrategyFilter & filter, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send user-defined event to an app.
     *
     * Only works for user-derived strategies and only if they run on the
     * same Engine instance the request originates from.
     *
     * Allocation/deallocation of data object is sole responsibility of
     * a user.
     *
     * @param app_id                    Identifier of the request target
     * @param data                      User-defined data
     *
     * @code
     *
     * UserData user_data(data, size);
     *
     * SendScheduleEvent(id, user_data);
     * // or
     * SendScheduleEvent(id, std::move(user_data));
     *
     * @endcode
     */
    static void SendScheduleEvent(const StrategyIdentifier & app_id, UserData data);

protected:
    /**
     * %Set app state.
     *
     * Calling this method results in an app update on exit from
     * Handle[]Request() event handler.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param state                     New app state
     */
    void SetState(const StrategyState & state);

    /**
     * %Set app transaction state.
     *
     * Use this method to mark start of potentially long operation.  For
     * instance, changing from StrategyState::PAUSED to StrategyState::RUNNING
     * may mean to launch a child app and wait until it reaches requested
     * app state by monitoring app stream. In this case, app
     * operation should be set to "StrategyTransactionOperation::STRATEGY_RUN"
     * and app transaction state should become pending, or in code:
     *
     * @code
     * SetTransactionPending(StrategyTransactionOperationRun);
     * @endcode
     *
     * Calling this method results in a app update on exit from
     * Handle[]Request() event handler.
     *
     * @see StrategyTransactionOperation
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param operation                 Operation the app initiates
     */
    void SetTransactionPending(const StrategyTransactionOperation & operation);

    /**
     * Fail app transaction.
     *
     * Use this method to fail pending operation initiated by
     * SetTransactionPending() method. For example, if in transition between
     * StrategyState::PAUSED and StrategyState::RUNNING child app
     * invocation fails at some point of time, app state must be set to
     * state the app had before starting transaction, and transaction
     * state should be failed. If second argument is not specified, it means
     * that app state is not changed.
     *
     * @code
     * SetTransactionFail("Failed to launch child app",
     *                    m_savedState);
     * @endcode
     *
     * Calling this method results in an app update on exit from
     * Handle[]Request() event handler.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param reason                    Operation the app initiates
     * @param state                     State the app receives on
     *                                  transaction failure; if set to
     *                                  StrategyStateNone, the app
     *                                  retains its current state
     */
    void SetTransactionFail(const String & reason, const StrategyState & state = StrategyState::NONE);

    /**
     * Get user data for writing.
     *
     * Adding to or removing from the container results in an app update.
     *
     * @warning Any modification to the returned object means an update an
     * app record in a server database which usually adds around 100 us
     * execution time on a recommended hardware.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          User data container
     */
    [[deprecated(DEPRECATE_LINK)]] ExtraData & GetExtraData();

    /**
     * %Set user data.
     *
     * Fully replaces extra data stored in the app instance. If argument
     * has no items, the call clears the data.
     *
     * Results in an app update.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @extra_data                      User data container
     */
    void SetExtraData(const ExtraData & extra_data);

    /**
     * %Set forward parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @param parameters                 Forward parameters
     */
    void SetForwardParameters(const StrategyParameters & parameters);

    /**
     * %Set regulatory parameters
     *
     * Fully replaces regulatory parameters stored in the app instance. If argument
     * has no items, the call clears the data.
     *
     * Results in an app update.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @parameters                      Regulatory parameters data container
     */
    void SetRegulatoryParameters(const RegulatoryParameters & parameters);

    /**
     * %Merge regulatory parameters
     *
     * Argument merges with regulatory parameters stored in the app instance.
     *
     * Results in a app update.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @parameters                      Regulatory parameters data container
     */
    void MergeRegulatoryParameters(const RegulatoryParameters & parameters);

    /**
     * Merge with teh attributes
     * @return       true if a app was changed
     */
    bool MergeAttributes(const StrategyAttributes & attributes);

    bool GetAttributes(StrategyAttributes & attributes) const;

    /**
     * Associate an app with a set of instruments.
     *
     * Sets a dependency between a app and a set of instruments which can
     * later on be used for instrument-based app filtering in the
     * front-end or in other app-dependent actions.
     *
     * Setting an empty vector effectively removes all associations.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param instruments               Instruments an app will be
     *                                  associated with
     */
    void SetInstruments(const std::vector<InstrumentIdentifier> & instruments);

    /**
     * Remove all strategy/instrument associations.
     *
     * @warning Calling this method means to update a app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     */
    void DeleteInstruments();

    /**
     * %Set strategy/instrument association.
     *
     * Method removes all previously established associations, if any, and,
     * if parameter is not empty, associates the instrument with the app.
     *
     * @see SetInstruments
     *
     * @warning Calling this method means to update a app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param instrument                Instrument identifier
     */
    void SetInstrument(const InstrumentIdentifier & instrument);

    /**
     * Add strategy/instrument association.
     *
     * Method extends association list with provided identifier unless it is
     * empty.
     *
     * @see SetInstruments
     *
     * @warning Calling this method means to update a app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param instrument                Instrument identifier
     */
    void AddInstrument(const InstrumentIdentifier & instrument);

    /**
     * Remove strategy/instrument association.
     *
     * Method removes the instrument from association list. If instrument is not
     * in the list, operation has no effect.
     *
     * @see SetInstruments
     *
     * @warning Calling this method means to update a app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param instrument                Instrument identifier
     */
    void DeleteInstrument(const InstrumentIdentifier & instrument);

    /**
     * Container-based access to strategy/instrument associations.
     *
     * @see SetInstruments
     * @see StrategyInstruments
     *
     * @warning Any modification to the returned object means an update a
     * app record in a server database which usually adds around 100 us
     * execution time on a recommended hardware.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          User data container
     */
    [[deprecated(DEPRECATE_LINK)]] StrategyInstruments & GetInstruments();

    /**
     * Container-based access to strategy/instrument associations.
     *
     * @see SetInstruments
     * @see StrategyInstruments
     *
     * @return                          User data container
     */
    const StrategyInstruments & GetInstruments() const;

    /**
     * %Set app priority.
     *
     * App priority introduces precedence over app events. Events
     * from apps of higher priority are generally delivered before the
     * events with a lower priority.
     *
     * App priority can be changed at any time, and if app is open
     * this setting takes immediate effect.
     *
     * App priority is an interger value in a range of [0..100] where '0'
     * is the lowest priority possible and '100' is the highest one.  Default
     * priority value is 50.
     *
     * If argument does not fall into the range, it is automatically converted
     * to the closest valid value (-100 will become zero, 3000 will be reduced
     * to 100).
     *
     * @param priority                  App priority
     */
    void SetPriority(const Integer & priority);

    /**
     * Get app priority.
     *
     * @see Strategy::SetPriority
     *
     * @return                          App priority
     */
    Integer GetPriority() const;

    /**
     * %Set app validity. On validity expiration App receives Delete request and then deleted. From app pov its the
     * same as manual app deletion from eg UI. Only VALID_TODAY, VALID_UNTIL_DATE, VALID_UNTIL_ELAPSED_TIME,
     * VALID_UNTIL_DATETIME vilidity types considered.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param validity                  App validity
     */
    void SetValidity(const Validity & validity);

    /**
     * %Set current app validity.
     *
     * @return                          App validity
     */
    Validity GetValidity() const;

    /**
     * Get app owner.
     *
     * @return                          Owner's user identifier
     */
    UserIdentifier GetOwner() const;

    /**
     * Get app owner.
     *
     * @return                          Owner
     */
    void GetOwner(User & user) const;

    /**
     * %Set app owner.
     * Note: owner can be changed outside without any notification
     *
     * @param uid                       Owner's user identifier
     */
    void SetOwner(const UserIdentifier & uid);

    /**
     * %Set app owner.
     * Note: owner can be changed outside without any notification
     *
     * @param user                      Owner
     */
    void SetOwner(const User & user);

    /**
     * Get app creator.
     *
     * @return                          Creator's user identifier
     */
    UserIdentifier GetCreator() const;

    /**
     * Get app creator.
     *
     * @return                          Creator
     */
    void GetCreator(User & user) const;

    /**
     * Get app operator.
     *
     * @return                          Operator's user identifier
     */
    UserIdentifier GetOperator() const;

    /**
     * Get app operator.
     *
     * @return                          Operator
     */
    void GetOperator(User & user) const;

    /**
     * Get operating service instance identifier.
     *
     * @return                          Identifier of service instance
     */
    ServiceIdentifier GetOperatingServiceInstanceIdentifier() const;

    /**
     * Get operating app identifier.
     *
     * @return                          App identifier
     */
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

    /**
     * Trading Limit Framework
     */
    TradingLimitState GetTradingLimitState() const;

    /**
     * %Set trading limit state.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param state                     Trading limit state
     */
    void SetTradingLimitState(const TradingLimitState & state);

    bool GetTradingLimitResult(TradingLimitResult & result) const;

    /**
     * %Set trading limit result.
     *
     * @warning Calling this method means to update an app record in a
     * server database which usually adds around 100 us execution time on a
     * recommended hardware.
     *
     * @param result                    Trading limit result
     */
    void SetTradingLimitResult(const TradingLimitResult & result);

    /**
     * Get status text.
     *
     * @return                          Status text
     */
    String GetStatusText() const;

    /**
     * Clear status text.
     *
     */
    void ClearStatusText();

    /**
     * %Set comment
     *
     * @param comment                   Comment text
     */
    void SetComment(const String & comment);

    /**
     * Get comment
     *
     * @return                         Comment text
     */
    String GetComment() const;

    /**
     * Get limit breach flag
     *
     * @return                         true if limit breached
     */
    bool GetLimitBreach() const;

    virtual std::ostream & PrintInternal(std::ostream & strm) const;

protected:
    /**
     * Strategy constructor.
     *
     * Parameter "recover_state" defines whether an app should recover
     * it's previous stategy state when the SE service starts up / performs
     * recovery. If it is true, the state the app had during shutdown
     * (running/paused) will be restored.  If it is false, the state of the
     * app will be restored to paused, regardless of the previous state.
     *
     * @param recover_state            Recovery state
     */
    Strategy(const Boolean & recover_state = true);

private:
    ExtraData * m_extra_data;
    class UserStrategyInstruments * m_instruments;
};

class STRATEGY_EXPORT Strategy::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const StrategyIdentifier & strategy_identifier);
    const Identifier & GetRequestIdentifier() const;
    const StrategyIdentifier & GetStrategyIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    StrategyIdentifier m_strategy_identifier;
};
}
