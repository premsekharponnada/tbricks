#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderBookHandler public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/type/RowEntityIdentifier.h"

namespace tbricks { namespace visualization {

class OrderBookHandlerImpl;
class Grid;

/**
 * OrderBookHandler opens order book streams for corresponded instrument venue identifications
 * and add depth level rows to all grids associated with specified grid parameter. Rows represent
 * depth data aggregated by price levels. If parent row identifier is set, rows will be attached
 * to it. Otherwise, rows will be added at root grid level
 */
class STRATEGY_EXPORT OrderBookHandler
{
public:
    /**
     * OrderBookHandler constructor
     *
     * @param handler                   grid handler
     * @param parentRowIdentifier       parent row entity id
     *
     */
    OrderBookHandler(const Grid & handler, const std::optional<RowEntityIdentifier> & parentRowIdentifier);

    OrderBookHandler();
    OrderBookHandler(const OrderBookHandler & handler) = default;
    OrderBookHandler(OrderBookHandler && handler) = default;
    OrderBookHandler & operator=(const OrderBookHandler & handler) = default;
    OrderBookHandler & operator=(OrderBookHandler && handler) = default;
    ~OrderBookHandler() = default;

    /**
     * Set grid handler
     *
     * @param handler                   grid handler
     *
     * @return true if successful, false is subscription is already requested
     */
    bool SetGridHandler(const Grid & handler);

    /**
     * Set parent row identifier
     *
     * @param parentRowIdentifier       parent row entity id
     *
     * @return true if successful, false is subscription is already requested
     */
    bool SetParentRowIdentifier(const std::optional<RowEntityIdentifier> & parentRowIdentifier);

    /**
     * Request subscription to order books and add depth level rows to all grids associated with
     * specified grid parameter
     *
     * @param ivids                     vector of instrument venue identifications
     *
     * @return true if subscription requested, false if already subscribed or vector is empty
     * @throws EmptyValueException if any of ivids is empty
     * @throws EmptyValueException if grid parameter is not set
     */
    bool RequestSubscription(const std::vector<InstrumentVenueIdentification> & ivids);

    /**
     * Revoke subscription and remove all depth level rows from grid
     *
     * @return true is subscription is revoked, false if subscription is not requested
     */
    bool RevokeSubscription();

    /**
     * Indicates if subscription is requested
     *
     * @return true if subscribed to order books, false otherwise
     */
    bool IsSubscribed() const;

    /**
     * Set limit to depth levels to be displayed in grid
     *
     * @param depthLimit                limit to depth levels. Limit will be reset if value is empty
     */
    void SetDepthLimit(std::optional<uint64_t> depthLimit);

private:
    std::shared_ptr<OrderBookHandlerImpl> m_order_book_impl;
};

} // namespace visualization
} // namespace tbricks
