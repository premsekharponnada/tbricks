#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CounterpartInformationBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class TreeNodeIdentifier;
enum class DirectedRequestForQuoteRejectReason;


namespace protocol { class CounterpartInformation; }

class STRATEGY_EXPORT CounterpartInformationBase : public Printable
{
protected:
    CounterpartInformationBase();
    CounterpartInformationBase(const CounterpartInformationBase & value);
    CounterpartInformationBase(CounterpartInformationBase && value) noexcept;
    CounterpartInformationBase & operator=(const CounterpartInformationBase & value);
    CounterpartInformationBase & operator=(CounterpartInformationBase && value) noexcept;
    virtual ~CounterpartInformationBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get counterpart identifier.
     *
     *
     * @return                          counterpart identifier
     */
    TreeNodeIdentifier GetIdentifier() const;

    /**
     * %Set counterpart identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart identifier
     */
    void SetIdentifier(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExposeSide() const;

    /**
     * Get expose side.
     *
     *
     * @return                          expose side
     */
    Boolean GetExposeSide() const;

    /**
     * %Set expose side.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expose side
     */
    void SetExposeSide(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExposeVolume() const;

    /**
     * Get expose volume.
     *
     *
     * @return                          expose volume
     */
    Boolean GetExposeVolume() const;

    /**
     * %Set expose volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expose volume
     */
    void SetExposeVolume(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRejectReason() const;

    /**
     * Get directed request for quote reject reason.
     *
     *
     * @return                          directed request for quote reject reason
     */
    std::optional<DirectedRequestForQuoteRejectReason> GetRejectReason() const;

    /**
     * %Set directed request for quote reject reason.
     *
     *
     * @param value                     directed request for quote reject reason
     */
    void SetRejectReason(std::optional<DirectedRequestForQuoteRejectReason> value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    CounterpartInformationBase(const protocol::CounterpartInformation & value);
    CounterpartInformationBase(std::shared_ptr<protocol::CounterpartInformation> && value);

    std::shared_ptr<protocol::CounterpartInformation> & get_impl_wr() const;
    const std::shared_ptr<protocol::CounterpartInformation> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::CounterpartInformation> m_impl;
};

}
