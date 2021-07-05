#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Cash Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class Cash;

namespace visualization {

/**
 * RowEntity implementation containing Cash object.
 *
 */
class STRATEGY_EXPORT CashRowEntity final : public RowEntity
{
public:
    CashRowEntity();

    CashRowEntity(const CashRowEntity & other) = default;
    CashRowEntity(CashRowEntity && other) noexcept = default;
    CashRowEntity & operator=(const CashRowEntity & other) = default;
    CashRowEntity & operator=(CashRowEntity && other) noexcept = default;

    /**
     * Get cash object stored in row entity.
     *
     * @return cash
     */
    const Cash & GetCash() const;

    /**
     * Set cash object and update view models containing row entity.
     *
     * @param cash        cash
     */
    void SetCash(const Cash & cash);

    virtual ~CashRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks
