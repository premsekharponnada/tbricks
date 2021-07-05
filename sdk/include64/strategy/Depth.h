#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Depth
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Integer.h"
#include "strategy/type/OrderBookChangeReason.h"
#include "strategy/type/Price.h"
#include "strategy/type/Side.h"
#include "strategy/type/String.h"
#include "strategy/type/Volume.h"

#include "strategy_generated/DepthBase.h"

namespace tbricks {

class PriceLevelOrderBook;

namespace protocol {
class Depth;
}

/**
 * Depth entry.
 */
class STRATEGY_EXPORT Depth : public DepthBase
{
public:
    enum UpdateAction
    {
        UA_Empty = 0,
        UA_New = 1,
        UA_Change = 2,
        UA_Delete = 3
    };

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    Depth() = default;

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param depth     Object to copy from
     */
    Depth(const Depth & depth) = default;

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param depth     Object to copy from
     * @return          Updated object
     */
    Depth & operator=(const Depth & depth) = default;

    ~Depth() override = default;

    /**
     * Check if a depth entry is deleted from the market.
     *
     * This field is usually checked in Depth stream callbacks.
     *
     * @return          "true" if depth entry was deleted,
     *                  "false" otherwise
     */
    bool Deleted() const;

    OrderBookChangeReason GetChangeReason() const;
    bool HasChangeReason() const;

    /**
     * Get state of depth.
     *
     * @return          update action
     */
    UpdateAction GetUpdateAction() const;

    /**
     * Mark as deleted if passed parameter is true, mark as new otherwise.
     *
     * @param value  deleted flag
     */
    void SetDeleted(bool value);

    /**
     * %Set depth identifier.
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value depth identifier
     */
    void SetDepthIdentifier(const Integer & value);

    /**
     * %Set participant.
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value participant
     */
    void SetParticipant(const String & value);

    /**
     * %Set price
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value price
     */
    void SetPrice(const Price & value);

    /**
     * %Set volume
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value volume
     */
    void SetVolume(const Volume & value);

    /**
     * %Set volume implied
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value volume implied
     */
    void SetVolumeImplied(const Volume & value);

    /**
     * %Set participant volume
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value participant volume
     */
    void SetParticipantVolume(const Volume & value);

    /**
     * %Set order count
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value order count
     */
    void SetOrderCount(const Integer & value);

    /**
     * %Set side
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value side
     */
    void SetSide(const Side & value);

    /**
     * %Set sorting key
     *
     * @deprecated Now it marks the action as change.
     *             In the future version the method will not change it.
     *
     * @param value sorting key
     */
    void SetSortingKey(const String & value);

public:
    bool Empty() const;

private:
    friend class PriceLevelOrderBook;
    friend class OrderBook;
    friend class OwnQuoteBook;
    friend class OwnPriceLevelQuoteBook;

    void SetUpdateAction(UpdateAction action);
    void merge(const Depth & depth);
};
}
