#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CarveoutBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/CarveoutUpdateBase.h"


#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class CarveoutIdentifier;
class Currency;
class Double;
class Identifier;
class InstrumentGroupIdentifier;
class InstrumentIdentifier;
class MIC;
class PortfolioIdentifier;
class StrategyIdentifier;
class TreeNodeIdentifier;
class UserIdentifier;
class VenueIdentifier;
class Volume;


namespace protocol { class Carveout; }

class STRATEGY_EXPORT CarveoutBase : public Printable
{
protected:
    CarveoutBase();
    CarveoutBase(const CarveoutBase & value);
    CarveoutBase(CarveoutBase && value) noexcept;
    CarveoutBase & operator=(const CarveoutBase & value);
    CarveoutBase & operator=(CarveoutBase && value) noexcept;
    virtual ~CarveoutBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get carveout identifier.
     *
     *
     * @return                          carveout identifier
     */
    CarveoutIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestIdentifier() const;

    /**
     * Get request identifier.
     *
     *
     * @return                          request identifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentStrategyIdentifier() const;

    /**
     * Get parent strategy identifier.
     *
     *
     * @return                          parent strategy identifier
     */
    StrategyIdentifier GetParentStrategyIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentGroupIdentifier() const;

    /**
     * Get instrument group identifier.
     *
     *
     * @return                          instrument group identifier
     */
    InstrumentGroupIdentifier GetInstrumentGroupIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenueIdentifier() const;

    /**
     * Get venue identifier.
     *
     *
     * @return                          venue identifier
     */
    VenueIdentifier GetVenueIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMIC() const;

    /**
     * Get mic.
     *
     *
     * @return                          mic
     */
    MIC GetMIC() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidActiveVolume() const;

    /**
     * Get bid active volume.
     *
     *
     * @return                          bid active volume
     */
    Volume GetBidActiveVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidFilledVolume() const;

    /**
     * Get bid filled volume.
     *
     *
     * @return                          bid filled volume
     */
    Volume GetBidFilledVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalVolume() const;

    /**
     * Get bid volume.
     *
     *
     * @return                          bid volume
     */
    Volume GetBidTotalVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidFilledValue() const;

    /**
     * Get bid filled value.
     *
     *
     * @return                          bid filled value
     */
    Double GetBidFilledValue() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalValue() const;

    /**
     * Get bid value.
     *
     *
     * @return                          bid value
     */
    Double GetBidTotalValue() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskActiveVolume() const;

    /**
     * Get ask active volume.
     *
     *
     * @return                          ask active volume
     */
    Volume GetAskActiveVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskFilledVolume() const;

    /**
     * Get ask filled volume.
     *
     *
     * @return                          ask filled volume
     */
    Volume GetAskFilledVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalVolume() const;

    /**
     * Get ask volume.
     *
     *
     * @return                          ask volume
     */
    Volume GetAskTotalVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskFilledValue() const;

    /**
     * Get ask filled value.
     *
     *
     * @return                          ask filled value
     */
    Double GetAskFilledValue() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalValue() const;

    /**
     * Get ask value.
     *
     *
     * @return                          ask value
     */
    Double GetAskTotalValue() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastQuoteIdentifier() const;

    /**
     * Get last quote identifier.
     *
     *
     * @return                          last quote identifier
     */
    Identifier GetLastQuoteIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLastInstrumentIdentifier() const;

    /**
     * Get last instrument identifier.
     *
     *
     * @return                          last instrument identifier
     */
    InstrumentIdentifier GetLastInstrumentIdentifier() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const CarveoutUpdateBase & update);

/** @cond PRIVATE */
public:
    CarveoutBase(const protocol::Carveout & value);
    CarveoutBase(std::shared_ptr<protocol::Carveout> && value);

    std::shared_ptr<protocol::Carveout> & get_impl_wr() const;
    const std::shared_ptr<protocol::Carveout> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Carveout> m_impl;
};

}
