#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Portfolio Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Portfolio;

namespace visualization {

/**
 * RowEntity implementation containing Portfolio object.
 *
 */
class STRATEGY_EXPORT PortfolioRowEntity final : public RowEntity
{
public:
    PortfolioRowEntity();

    PortfolioRowEntity(const PortfolioRowEntity & other) = default;
    PortfolioRowEntity(PortfolioRowEntity && other) noexcept = default;
    PortfolioRowEntity & operator=(const PortfolioRowEntity & other) = default;
    PortfolioRowEntity & operator=(PortfolioRowEntity && other) noexcept = default;

    /**
     * Get portfolio object stored in row entity.
     *
     * @return portfolio
     */
    const Portfolio & GetPortfolio() const;

    /**
     * Set portfolio object and update view models containing row entity.
     *
     * @param portfolio        portfolio
     */
    void SetPortfolio(const Portfolio & portfolio);

    virtual ~PortfolioRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks
