#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Order Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class Order;

namespace visualization {

/**
 * RowEntity implementation containing Order object.
 *
 */
class STRATEGY_EXPORT OrderRowEntity final : public RowEntity
{
public:
    OrderRowEntity();

    OrderRowEntity(const OrderRowEntity & other) = default;
    OrderRowEntity(OrderRowEntity && other) noexcept = default;
    OrderRowEntity & operator=(const OrderRowEntity & other) = default;
    OrderRowEntity & operator=(OrderRowEntity && other) noexcept = default;

    /**
     * Get order object stored in row entity.
     *
     * @return order
     */
    const Order & GetOrder() const;

    /**
     * Set order object and update view models containing row entity.
     *
     * @param order        order
     */
    void SetOrder(const Order & order);

    ~OrderRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks
