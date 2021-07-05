#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RequestForTradeLegBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Price;
class RequestForTradeLegIdentifier;
class Side;
class Volume;


namespace protocol { class RequestForTradeLeg; }

class STRATEGY_EXPORT RequestForTradeLegBase : public Printable
{
protected:
    RequestForTradeLegBase();
    RequestForTradeLegBase(const RequestForTradeLegBase & value);
    RequestForTradeLegBase(RequestForTradeLegBase && value) noexcept;
    RequestForTradeLegBase & operator=(const RequestForTradeLegBase & value);
    RequestForTradeLegBase & operator=(RequestForTradeLegBase && value) noexcept;
    virtual ~RequestForTradeLegBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get request for trade leg identifier.
     *
     *
     * @return                          request for trade leg identifier
     */
    RequestForTradeLegIdentifier GetIdentifier() const;

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
     * %Set price.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     price
     */
    void SetPrice(const Price & value);

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
     * %Set side.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     side
     */
    void SetSide(const Side & value);

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
     * %Set volume.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     volume
     */
    void SetVolume(const Volume & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    RequestForTradeLegBase(const protocol::RequestForTradeLeg & value);
    RequestForTradeLegBase(std::shared_ptr<protocol::RequestForTradeLeg> && value);

    std::shared_ptr<protocol::RequestForTradeLeg> & get_impl_wr() const;
    const std::shared_ptr<protocol::RequestForTradeLeg> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::RequestForTradeLeg> m_impl;
};

}
