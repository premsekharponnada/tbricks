#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CashFlow object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Currency.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Double.h"

#include <memory>

namespace tbricks {

/** @cond PRIVATE */
namespace protocol {
class CashFlow;
}
/** @endcond */

class STRATEGY_EXPORT CashFlow : public Printable
{
public:
    CashFlow();
    CashFlow(const Currency & currency, const Double & cash_value, const DateTime & settlement_date);
    CashFlow(const CashFlow & cash_flow);
    CashFlow(CashFlow && cash_flow) noexcept;
    ~CashFlow() override;

    CashFlow & operator=(const CashFlow & cash_flow);
    CashFlow & operator=(CashFlow && cash_flow) noexcept;

    /**
     * Check if field is set.
     *
     * @return                       True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     * @return                       Currency.
     */
    Currency GetCurrency() const;

    /**
     * Check if field is set.
     *
     * @return                       True if field is set, false otherwise
     */
    bool HasCashValue() const;

    /**
     * Get hash value.
     *
     * @return                       %Cash value.
     */
    Double GetCashValue() const;

    /**
     * Check if field is set.
     *
     * @return                       True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     * @return                       Settlement date.
     */
    DateTime GetSettlemetDate() const;

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

    CashFlow(const protocol::CashFlow & impl);
    const protocol::CashFlow & get_impl() const;

private:
    std::unique_ptr<protocol::CashFlow> m_impl;
};
}
