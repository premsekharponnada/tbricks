#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// FX object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Pair.h"

namespace tbricks {

/**
 * FX object
 *
 */
class STRATEGY_EXPORT FX : public Printable
{
public:
    class Update;
    class Stream;

public:
    FX();
    FX(const Currency & currency_1, const Currency & currency_2);
    FX(const FX & fx);
    FX & operator=(const FX & fx);
    virtual ~FX();

public:
    static Pair<Currency, Currency> CreateCurrencyPair(const Currency & currency_1, const Currency & currency_2);

    const Pair<Currency, Currency> & GetCurrencyPair() const;
    void SetCurrencyPair(const Currency & currency_1, const Currency & currency_2);

    const Value<Double> & GetBid(const Currency & from, const Currency & to) const;
    const Value<Double> & GetAsk(const Currency & from, const Currency & to) const;
    const Value<Double> & GetMiddle(const Currency & from, const Currency & to) const;

public:
    void Clear();
    bool Empty() const;

public:
    void Merge(const FX::Update & update);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Pair<Currency, Currency> m_currency_pair;

    Value<Double> m_bid;
    Value<Double> m_ask;
    Value<Double> m_middle;

    Value<Double> m_reverse_bid;
    Value<Double> m_reverse_ask;
    Value<Double> m_reverse_middle;
};

/**
 * FX::Update object
 *
 */
class STRATEGY_EXPORT FX::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);
    virtual ~Update();

public:
    const Pair<Currency, Currency> & GetCurrencyPair() const;

    const Value<Double> & GetBid(const Currency & from, const Currency & to) const;
    const Value<Double> & GetAsk(const Currency & from, const Currency & to) const;
    const Value<Double> & GetMiddle(const Currency & from, const Currency & to) const;

public:
    bool Empty() const;
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    Pair<Currency, Currency> m_currency_pair;

    Value<Double> m_bid;
    Value<Double> m_ask;
    Value<Double> m_middle;

    Value<Double> m_reverse_bid;
    Value<Double> m_reverse_ask;
    Value<Double> m_reverse_middle;
};

} // namespace tbricks
