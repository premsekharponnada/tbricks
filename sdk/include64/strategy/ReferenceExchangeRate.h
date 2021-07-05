#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Reference exchange rate object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"

namespace tbricks {

namespace protocol {
class ReferenceExchangeRate;
}

class STRATEGY_EXPORT ReferenceExchangeRate : public Printable
{
public:
    class Options;
    class Update;
    class Stream;

public:
    class RequestResult;

public:
    ReferenceExchangeRate();
    ReferenceExchangeRate(const ReferenceExchangeRate & rate);
    ReferenceExchangeRate & operator=(const ReferenceExchangeRate & rate);
    virtual ~ReferenceExchangeRate();

    const Identifier & GetIdentifier() const;

    const Currency & GetCounterCurrency() const;
    const Currency & GetCurrency() const;
    const Date & GetDate() const;

    const Double & GetRate() const;

    const Double & GetRateDaily() const;
    const Double & GetRateMonthly() const;
    const Double & GetRateYearly() const;

    void Merge(const ReferenceExchangeRate::Update & cash);

    void Clear();
    bool Empty() const;

public:
    static RequestResult SendModifyRequest(const ReferenceExchangeRate::Options & options, IRequestReplyHandler & handler);
    static RequestResult SendDeleteRequest(const Currency & counter_currency,
                                           const Currency & currency,
                                           const Date & reference_exchange_rate_date,
                                           IRequestReplyHandler & handler);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_id;

    Currency m_counter_currency;
    Currency m_currency;
    Date m_reference_exchange_rate_date;
    Double m_reference_exchange_rate;
    Double m_reference_exchange_rate_daily;
    Double m_reference_exchange_rate_monthly;
    Double m_reference_exchange_rate_yearly;
};

//****************************************************************************
// RequestResult class
//****************************************************************************
class STRATEGY_EXPORT ReferenceExchangeRate::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_id, const Identifier & reference_exchange_rate_id);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetReferenceExchangeRateIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_id;
    Identifier m_reference_exchange_rate_id;
};

//****************************************************************************
// ReferenceExchangeRate::Update class
//****************************************************************************
class STRATEGY_EXPORT ReferenceExchangeRate::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    virtual ~Update();

    Update & operator=(const Update & update);

    const Identifier & GetIdentifier() const;

    const Currency & GetCounterCurrency() const;
    const Currency & GetCurrency() const;
    const Date & GetDate() const;

    const Double & GetRate() const;

    const Double & GetRateDaily() const;
    const Double & GetRateMonthly() const;
    const Double & GetRateYearly() const;

    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    Update(const protocol::ReferenceExchangeRate & msg);

private:
    Identifier m_id;

    Currency m_counter_currency;
    Currency m_currency;
    Date m_reference_exchange_rate_date;
    Double m_reference_exchange_rate;
    Double m_reference_exchange_rate_daily;
    Double m_reference_exchange_rate_monthly;
    Double m_reference_exchange_rate_yearly;
};

//****************************************************************************
// ReferenceExchangeRate::Options class
//****************************************************************************
class STRATEGY_EXPORT ReferenceExchangeRate::Options : public Printable
{
public:
    Options();
    Options(const Options & options);
    virtual ~Options();

    Options & operator=(const Options & options);

    void SetCounterCurrency(const Currency & currency);
    const Currency & GetCounterCurrency() const;
    Currency & GetCounterCurrency();

    void SetCurrency(const Currency & currency);
    const Currency & GetCurrency() const;
    Currency & GetCurrency();

    void SetDate(const Date & date);
    const Date & GetDate() const;
    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Date & GetDate();

    void SetRate(const Double & rate);
    const Double & GetRate() const;
    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Double & GetRate();

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Currency m_counter_currency;
    Currency m_currency;
    Date m_reference_exchange_rate_date;
    Double m_reference_exchange_rate;
};
}
