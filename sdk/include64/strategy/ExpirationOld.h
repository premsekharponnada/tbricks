#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExpirationOld object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"

#include <vector>

namespace tbricks {

namespace protocol {
class Expiration;
}

/// @deprecated Deprecated in 2.14.0, will be removed in the next release. Use tbricks::Expiration class.
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] ExpirationOld : public Printable
{
public:
    class Operation;
    class RequestResult;

public:
    class Options;
    class Update;
    class Stream;

public:
    ExpirationOld();
    ExpirationOld(const ExpirationOld & expiration);
    ExpirationOld & operator=(const ExpirationOld & expiration);
    virtual ~ExpirationOld();

    const UserIdentifier & GetCreator() const;
    void GetCreator(User & user) const;
    const DateTime & GetExpirationDate() const;
    const Identifier & GetIdentifier() const;
    const std::vector<Operation> & GetOperations() const;
    const DateTime & GetHostCreatedDate() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    const Price & GetPrice() const;
    const Identifier & GetRequestIdentifier() const;

    void Merge(const ExpirationOld::Update & update);

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    static RequestResult SendCreateRequest(const ExpirationOld::Options & options, IRequestReplyHandler & handler);
    static RequestResult SendDeleteRequest(const Identifier & identifier, IRequestReplyHandler & handler);

private:
    friend class ExpirationOldConverter;

private:
    UserIdentifier m_creator;
    DateTime m_expiration_date;
    Identifier m_expiration_identifier;
    std::vector<Operation> m_operations;
    DateTime m_host_created_date;
    InstrumentIdentifier m_instrument_identifier;
    Price m_price;
    Identifier m_request_identifier;
};

//****************************************************************************
// ExpirationOld::RequestResult class
//****************************************************************************
class STRATEGY_EXPORT ExpirationOld::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const Identifier & expiration_identifier);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetExpirationIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_expiration_identifier;
};

//****************************************************************************
// ExpirationOld::Operation class
//****************************************************************************
class STRATEGY_EXPORT ExpirationOld::Operation : public Printable
{
public:
    Operation();
    Operation(const Operation & operation);

    virtual ~Operation();

    Operation & operator=(const Operation & operation);

    const Double & GetCashValue() const;
    const Currency & GetCurrency() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    const PortfolioIdentifier & GetPortfolioIdentifier() const;
    const Price & GetPrice() const;
    const DateTime & GetSettlementDate() const;
    const Volume & GetVolume() const;
    const Double & GetMultiplier() const;
    const Price & GetExpirationPrice() const;
    const Volume & GetExpirationVolume() const;
    const Double & GetExpirationGrossTradeAmount() const;

    Double & GetCashValue();
    Currency & GetCurrency();
    InstrumentIdentifier & GetInstrumentIdentifier();
    PortfolioIdentifier & GetPortfolioIdentifier();
    Price & GetPrice();
    DateTime & GetSettlementDate();
    Volume & GetVolume();
    Double & GetMultiplier();
    Price & GetExpirationPrice();
    Volume & GetExpirationVolume();
    Double & GetExpirationGrossTradeAmount();

    void SetCashValue(const Double & cash_value);
    void SetCurrency(const Currency & currency);
    void SetInstrumentIdentifier(const InstrumentIdentifier & identifier);
    void SetPortfolioIdentifier(const PortfolioIdentifier & identifier);
    void SetPrice(const Price & price);
    void SetSettlementDate(const DateTime & date);
    void SetVolume(const Volume & volume);
    void SetMultiplier(const Double & mul);
    void SetExpirationPrice(const Price & price);
    void SetExpirationVolume(const Volume & volume);
    void SetExpirationGrossTradeAmount(const Double & gta);

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend class ExpirationOldConverter;

private:
    Double m_cash_value;
    Currency m_currency;
    InstrumentIdentifier m_instrument_identifier;
    PortfolioIdentifier m_portfolio_identifier;
    Price m_price;
    DateTime m_settlement_date;
    Volume m_volume;
    Double m_multiplier;
    Price m_expiration_price;
    Volume m_expiration_volume;
    Double m_expiration_gross_trade_amount;
};

//****************************************************************************
// ExpirationOld::Options class
//****************************************************************************
class STRATEGY_EXPORT ExpirationOld::Options : public Printable
{
public:
    Options();
    Options(const Options & options);

    Options & operator=(const Options & options);
    virtual ~Options();

    const DateTime & GetExpirationDate() const;
    const std::vector<Operation> & GetOperations() const;
    const DateTime & GetHostCreatedDate() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    const Price & GetPrice() const;

    DateTime & GetExpirationDate();
    std::vector<Operation> & GetOperations();
    DateTime & GetHostCreatedDate();
    InstrumentIdentifier & GetInstrumentIdentifier();
    Price & GetPrice();

    void SetExpirationDate(const DateTime & date);
    void SetOperations(const std::vector<Operation> & operations);
    void SetHostCreatedDate(const DateTime & date);
    void SetInstrumentIdentifier(const InstrumentIdentifier & identifier);
    void SetPrice(const Price & price);

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DateTime m_expiration_date;
    std::vector<Operation> m_operations;
    DateTime m_host_created_date;
    InstrumentIdentifier m_instrument_identifier;
    Price m_price;
};

//****************************************************************************
// ExpirationOld::Update class
//****************************************************************************
class STRATEGY_EXPORT ExpirationOld::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    virtual ~Update();

    Update & operator=(const Update & update);

    const UserIdentifier & GetCreator() const;
    void GetCreator(User & user) const;
    const DateTime & GetExpirationDate() const;
    const Identifier & GetIdentifier() const;
    const std::vector<Operation> & GetOperations() const;
    const DateTime & GetHostCreatedDate() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;
    const Price & GetPrice() const;
    const Identifier & GetRequestIdentifier() const;

    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    void Decode(const protocol::Expiration & msg);

private:
    UserIdentifier m_creator;
    DateTime m_expiration_date;
    Identifier m_expiration_identifier;
    std::vector<Operation> m_operations;
    DateTime m_host_created_date;
    InstrumentIdentifier m_instrument_identifier;
    Price m_price;
    Identifier m_request_identifier;
};
}
