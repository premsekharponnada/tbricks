#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Alert
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/User.h"
#include "strategy/Types.h"

#include "strategy/AlertParameters.h"

#include <memory>
#include <ostream>
#include <sstream>
#include <vector>

#define TBALERT_BASE(severity, description, related)                  \
    do {                                                              \
        ::tbricks::Alert __tb_alert;                                  \
        __tb_alert.SetSeverity(::tbricks::Alert::severity);           \
        std::ostringstream __tb_descr_sstrm;                          \
        __tb_descr_sstrm << description;                              \
        ::tbricks::AlertRelatedStream __tb_alert_strm(__tb_alert);    \
        __tb_alert_strm << related;                                   \
        __tb_alert.SetDescription(std::move(__tb_descr_sstrm).str()); \
        ::tbricks::Alert::SendCreateRequest(__tb_alert);              \
    } while (0)

#define TBALERT(description, related) TBALERT_BASE(SeverityNormal, description, related)
#define TBALERT_CRITICAL(description, related) TBALERT_BASE(SeverityCritical, description, related)

namespace tbricks {

namespace types {
class StrategyAlert;
}
namespace protocol {
class StrategyAlert;
}

class STRATEGY_EXPORT Alert : public Printable
{
public:
    class Modifier;
    class RequestResult;
    class Stream;

    enum Severity
    {
        SeverityNormal = 0,
        SeverityCritical = 1
    };

public:
    Alert();
    Alert(const String & description, const Severity & severity = SeverityNormal);
    Alert(const Alert & alert);
    Alert(const protocol::StrategyAlert & alert);

    Alert & operator=(const Alert & alert);
    virtual ~Alert();

    /**
     * Send alert create request.
     *
     * @param alert                     Alert
     */
    static void SendCreateRequest(const Alert & alert);

    /**
     * Send alert modify request.
     *
     * Argument "modifier" allows to alter alert attributes as well as
     * alert parameter values.
     *
     * @param modifier                  Modification request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Alert::RequestResult object
     */
    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler);

    Uuid GetIdentifier() const;
    void SetDescription(const String & description);
    void SetSeverity(const Severity & severity);

    String GetDescription() const;
    Severity GetSeverity() const;

    DateTime GetHostCreatedDatetime() const;
    DateTime GetHostModifiedDatetime() const;

    StrategyIdentifier GetStrategyIdentifier() const;
    StrategyIdentifier GetStrategyDefinitionIdentifier() const;

    UserIdentifier GetCreator() const;

    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & value);

    AlertParameters GetParameters() const;
    void SetParameters(const AlertParameters & parameters);

    std::vector<InstrumentIdentifier> GetRelatedInstruments() const;
    std::vector<PortfolioIdentifier> GetRelatedPortfolios() const;
    std::vector<ServiceIdentifier> GetRelatedServices() const;
    std::vector<StrategyIdentifier> GetRelatedStrategies() const;
    std::vector<TradeIdentifier> GetRelatedTrades() const;
    std::vector<UserIdentifier> GetRelatedUsers() const;

    void AddRelatedInstrument(const InstrumentIdentifier & instrument_id);
    void AddRelatedPortfolio(const PortfolioIdentifier & portfolio_id);
    void AddRelatedService(const ServiceIdentifier & service_id);
    void AddRelatedStrategy(const StrategyIdentifier & strategy_id);
    void AddRelatedTrade(const TradeIdentifier & trade_id);
    void AddRelatedUser(const UserIdentifier & user_id);
    void AddRelatedUser(const User & user);

    void AddRelatedInstruments(const std::vector<InstrumentIdentifier> & ids);
    void AddRelatedPortfolios(const std::vector<PortfolioIdentifier> & ids);
    void AddRelatedServices(const std::vector<ServiceIdentifier> & ids);
    void AddRelatedStrategies(const std::vector<StrategyIdentifier> & ids);
    void AddRelatedTrades(const std::vector<TradeIdentifier> & ids);
    void AddRelatedUsers(const std::vector<UserIdentifier> & ids);
    void AddRelatedUsers(const std::vector<User> & users);

    void SetAlertType(const AlertType & alert_type);

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void Init();

private:
    std::unique_ptr<tbricks::protocol::StrategyAlert> m_alert;
};

class STRATEGY_EXPORT Alert::Modifier : public Printable
{
public:
    Modifier(const Uuid & alertIdentifier);
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    virtual ~Modifier();

    const Uuid & GetIdentifier() const;

    bool HasParameters() const;
    void SetParameters(const AlertParameters & data);
    const AlertParameters & GetParameters() const;

    bool HasDeleted() const;
    void SetDeleted(const Boolean & deleted);
    const Boolean & GetDeleted() const;

public:
    void Clear();
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Uuid m_identifier;
    Boolean m_deleted;
    AlertParameters m_parameters;
};

class STRATEGY_EXPORT Alert::RequestResult : public Printable
{
public:
    RequestResult() {}
    RequestResult(const Identifier & requestIdentifier, const Uuid & alertIdentifier);
    const Identifier & GetRequestIdentifier() const;
    const Uuid & GetAlertIdentifier() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_requestIdentifier;
    Uuid m_alertIdentifier;
};

class AlertRelatedStream
{
public:
    AlertRelatedStream(Alert & alert) : m_alert(alert) {}

    AlertRelatedStream & operator<<(const InstrumentIdentifier & instrument_id)
    {
        m_alert.AddRelatedInstrument(instrument_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const PortfolioIdentifier & portfolio_id)
    {
        m_alert.AddRelatedPortfolio(portfolio_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const ServiceIdentifier & service_id)
    {
        m_alert.AddRelatedService(service_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const StrategyIdentifier & strategy_id)
    {
        m_alert.AddRelatedStrategy(strategy_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const TradeIdentifier & trade_id)
    {
        m_alert.AddRelatedTrade(trade_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const UserIdentifier & user_id)
    {
        m_alert.AddRelatedUser(user_id);
        return *this;
    }
    AlertRelatedStream & operator<<(const User & user)
    {
        m_alert.AddRelatedUser(user);
        return *this;
    }

    AlertRelatedStream & operator<<(const std::vector<InstrumentIdentifier> & instrument_ids)
    {
        m_alert.AddRelatedInstruments(instrument_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<PortfolioIdentifier> & portfolio_ids)
    {
        m_alert.AddRelatedPortfolios(portfolio_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<ServiceIdentifier> & service_ids)
    {
        m_alert.AddRelatedServices(service_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<StrategyIdentifier> & strategy_ids)
    {
        m_alert.AddRelatedStrategies(strategy_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<TradeIdentifier> & trade_ids)
    {
        m_alert.AddRelatedTrades(trade_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<UserIdentifier> & user_ids)
    {
        m_alert.AddRelatedUsers(user_ids);
        return *this;
    }
    AlertRelatedStream & operator<<(const std::vector<User> & users)
    {
        m_alert.AddRelatedUsers(users);
        return *this;
    }

    AlertRelatedStream & operator<<(int * /* nil */) { return *this; }

private:
    Alert & m_alert;
};
}
