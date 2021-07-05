#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Modifiable strategy attributes.
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include "strategy/ExtraData.h"
#include "strategy/parameter/StrategyParameters.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/Types.h"

#include "strategy/User.h"

namespace tbricks {

namespace protocol {
class StrategyModifyRequest;
class StrategyAddRequest;
}

/**
 * StrategyAttributes class represents a set of strategy attributes available
 * for modifications from the outside, either when strategy is created (in this
 * case, the class contains initial attribute values a child strategy will be
 * created with) or by means of strategy modify request.
 *
 * @see Strategy::SendCreateRequest
 * @see Strategy::SendModifyRequest
 */
class STRATEGY_EXPORT StrategyAttributes : public Printable
{
public:
    StrategyAttributes();
    StrategyAttributes(const StrategyAttributes & attributes);
    ~StrategyAttributes();

    StrategyAttributes & operator=(const StrategyAttributes & attributes);

    StrategyAttributes(const protocol::StrategyModifyRequest & message);
    StrategyAttributes(const protocol::StrategyAddRequest & message);

public:
    void SetOwner(const UserIdentifier & owner);
    void SetOwner(const User & owner);
    const UserIdentifier & GetOwner() const;
    void GetOwner(User & user) const;

    void SetName(const String & name);
    const String & GetName() const;

    /**
     * %Set strategy priority.
     *
     * @see Strategy::SetPriority
     *
     * @param priority                  Strategy priority
     */
    void SetPriority(const Integer & priority);

    /**
     * Get strategy priority.
     *
     * @see Strategy::SetPriority
     * @see Strategy::GetPriority
     *
     * @return                          Strategy priority
     */
    const Integer & GetPriority() const;

    /**
     * %Set strategy validity.
     *
     * If argument is empty, validity will not become a part
     * of create/modify requests.
     *
     * @param validity                  Strategy validity
     */
    void SetValidity(const Validity & validity);

    /**
     * Get strategy validity.
     *
     * @return                          Current strategy validity value,
     *                                  or an empty object if it is not set
     */
    const Validity & GetValidity() const;

    /**
     * Get strategy validity.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Current strategy validity value,
     *                                  or an empty object if it is not set
     */
    [[deprecated(DEPRECATE_LINK)]] Validity & GetValidity();

    /**
     * %Set extra data.
     *
     * Includes a vector of user-defined data in key-value form
     * into strategy create and modify requests for analysis
     * by the target strategy.
     *
     * If argument is empty, extra data will not become a part
     * of the requests.
     *
     * @param extra_data                Extra data container
     */
    void SetExtraData(const ExtraData & extra_data);

    /**
     * Get extra data.
     *
     * Returns a vector of user-defined data in key-value form.
     *
     * @return                          Current extra data container values
     *                                  or an empty object if values were
     *                                  not set
     */
    const ExtraData & GetExtraData() const;

    /**
     * Get extra data.
     *
     * Returns a vector of user-defined data in key-value form.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                          Current extra data container values
     *                                  or an empty object if values were
     *                                  not set
     */
    [[deprecated(DEPRECATE_LINK)]] ExtraData & GetExtraData();

    /**
     * %Set forward parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @param parameters                 Forward parameters
     */
    void SetForwardParameters(const StrategyParameters & parameters);

    /**
     * Get forward parameters which should be passed to venue alongside with an order.
     * Used to represent additional parameters for algo orders available on
     * FIX venues or on Tbricks Matching Engine.
     *
     * @return                          Forward parameters
     */
    const StrategyParameters & GetForwardParameters() const;

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] StrategyParameters & GetForwardParameters();

    void SetRegulatoryParameters(const RegulatoryParameters & parameters);
    const RegulatoryParameters & GetRegulatoryParameters() const;

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] RegulatoryParameters & GetRegulatoryParameters();

    void SetComment(const String & comment);

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] String & GetComment();

    const String & GetComment() const;

    bool Merge(const StrategyAttributes & attributes);

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear container data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_owner;
    String m_name;

    Integer m_priority;
    ExtraData m_extra_data;
    StrategyParameters m_forward_parameters;
    RegulatoryParameters m_regulatory_parameters;
    Validity m_validity;

    String m_comment;
};
}
