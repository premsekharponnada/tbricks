#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Block Order.
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/ExtraData.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/type/BlockOrderLegIdentifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Double.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/ParticipationPolicy.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/Price.h"
#include "strategy/type/PricePolicy.h"
#include "strategy/type/Side.h"
#include "strategy/type/String.h"
#include "strategy/type/TransitionType.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/Volume.h"
#include "strategy_generated/BlockOrderLegBase.h"

namespace tbricks {

/**
 * Representing information about specific leg inside block order.
 */
class STRATEGY_EXPORT BlockOrderLeg : public BlockOrderLegBase
{
public:
    BlockOrderLeg();
    BlockOrderLeg(const BlockOrderLeg & block_order_leg);
    BlockOrderLeg(BlockOrderLeg && block_order_leg) noexcept;

    ~BlockOrderLeg() override;

    BlockOrderLeg & operator=(const BlockOrderLeg & block_order_leg);
    BlockOrderLeg & operator=(BlockOrderLeg && block_order_leg) noexcept;

    BlockOrderLeg(const protocol::BlockOrderLeg & block_order_leg);

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * %Set extra data.
     *
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get side.
     *
     * @return                          side
     */
    Side GetSide() const;

    /**
     * %Set side.
     *
     * @param value                     side
     */
    void SetSide(const Side & value);

    /**
     * %Set side.
     *
     * @param value                     instrument venue identification
     */
    void SetInstrumentVenueIdentification(const InstrumentVenueIdentification & ivid);

    /**
     * Get instrument venue identification.
     *
     * @return                          instrument venue identification
     */
    InstrumentVenueIdentification GetInstrumentVenueIdentification() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentVenueIdentification() const;
};
}
