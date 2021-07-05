#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DepthBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Integer;
class Price;
class Side;
class String;
class Volume;


namespace protocol { class Depth; }

class STRATEGY_EXPORT DepthBase : public Printable
{
protected:
    DepthBase();
    DepthBase(const DepthBase & value);
    DepthBase(DepthBase && value) noexcept;
    DepthBase & operator=(const DepthBase & value);
    DepthBase & operator=(DepthBase && value) noexcept;
    virtual ~DepthBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDepthIdentifier() const;

    /**
     * Get depth identifier.
     *
     *
     * @return                          depth identifier
     */
    Integer GetDepthIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSortingKey() const;

    /**
     * Get sorting key.
     *
     *
     * @return                          sorting key
     */
    String GetSortingKey() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParticipant() const;

    /**
     * Get participant.
     *
     *
     * @return                          participant
     */
    String GetParticipant() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPrice() const;

    /**
     * Get price.
     *
     *
     * @return                          price
     */
    Price GetPrice() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolume() const;

    /**
     * Get volume.
     *
     *
     * @return                          volume
     */
    Volume GetVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParticipantVolume() const;

    /**
     * Get participant volume.
     *
     *
     * @return                          participant volume
     */
    Volume GetParticipantVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVolumeImplied() const;

    /**
     * Get volume implied.
     *
     *
     * @return                          volume implied
     */
    Volume GetVolumeImplied() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSide() const;

    /**
     * Get side.
     *
     *
     * @return                          side
     */
    Side GetSide() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderCount() const;

    /**
     * Get order count.
     *
     *
     * @return                          order count
     */
    Integer GetOrderCount() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeDepthIdentifier() const;

    /**
     * Get venue depth identifier.
     *
     *
     * @return                          venue depth identifier
     */
    String GetExchangeDepthIdentifier() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DepthBase(const protocol::Depth & value);
    DepthBase(std::shared_ptr<protocol::Depth> && value);

    std::shared_ptr<protocol::Depth> & get_impl_wr() const;
    const std::shared_ptr<protocol::Depth> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Depth> m_impl;
};

}
