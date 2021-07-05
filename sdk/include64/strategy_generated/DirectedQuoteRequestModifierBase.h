#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequestModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DirectedQuoteRequestLeg;
class ExtraData;
class Identifier;
class Price;
class RegulatoryParameters;
class Side;
class String;
class Volume;
enum class DirectedRequestForQuoteRejectReason;


namespace protocol { class DirectedQuoteRequestModifyRequest; }

class STRATEGY_EXPORT DirectedQuoteRequestModifierBase : public Printable
{
protected:
    DirectedQuoteRequestModifierBase();
    DirectedQuoteRequestModifierBase(const DirectedQuoteRequestModifierBase & value);
    DirectedQuoteRequestModifierBase(DirectedQuoteRequestModifierBase && value) noexcept;
    DirectedQuoteRequestModifierBase & operator=(const DirectedQuoteRequestModifierBase & value);
    DirectedQuoteRequestModifierBase & operator=(DirectedQuoteRequestModifierBase && value) noexcept;
    virtual ~DirectedQuoteRequestModifierBase();

public:
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
     * @throw Exception if passed value is empty
     *  
     * @param value                     volume
     */
    void SetVolume(const Volume & value);

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
     * @throw Exception if passed value is empty
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
    bool HasRequestedBidPrice() const;

    /**
     * Get requested bid price.
     *
     *
     * @return                          requested bid price
     */
    Price GetRequestedBidPrice() const;

    /**
     * %Set requested bid price.
     *
     *    
     *  
     * @param value                     requested bid price
     */
    void SetRequestedBidPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestedAskPrice() const;

    /**
     * Get requested ask price.
     *
     *
     * @return                          requested ask price
     */
    Price GetRequestedAskPrice() const;

    /**
     * %Set requested ask price.
     *
     *    
     *  
     * @param value                     requested ask price
     */
    void SetRequestedAskPrice(const Price & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLegs() const;

    /**
     * Get directed quote request legs.
     *
     *
     * @return                          directed quote request legs
     */
    std::vector<DirectedQuoteRequestLeg> GetLegs() const;

    /**
     * %Set directed quote request legs.
     * The field will be set into object even if the field is empty.
     *
     *
     * @param value                     directed quote request legs
     */
    void SetLegs(const std::vector<DirectedQuoteRequestLeg> & value);

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
     * %Set request identifier.
     *
     *    
     *  
     * @param value                     request identifier
     */
    void SetRequestIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * %Set comment.
     *
     *    
     *  
     * @param value                     comment
     */
    void SetComment(const String & value);

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
     void SetRejectReason(DirectedRequestForQuoteRejectReason value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory parameters.
     *
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * %Set regulatory parameters.
     *
     *    
     *  
     * @param value                     regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * %Set extra data.
     *
     *    
     *  
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNegotiateDelta() const;

    /**
     * Get negotiate delta.
     *
     *
     * @return                          negotiate delta
     */
    Boolean GetNegotiateDelta() const;

    /**
     * %Set negotiate delta.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     negotiate delta
     */
    void SetNegotiateDelta(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasNegotiateUnderlyingPriceLevel() const;

    /**
     * Get negotiate underlying price level.
     *
     *
     * @return                          negotiate underlying price level
     */
    Boolean GetNegotiateUnderlyingPriceLevel() const;

    /**
     * %Set negotiate underlying price level.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     negotiate underlying price level
     */
    void SetNegotiateUnderlyingPriceLevel(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteRequestModifierBase(const protocol::DirectedQuoteRequestModifyRequest & value);
    DirectedQuoteRequestModifierBase(std::unique_ptr<protocol::DirectedQuoteRequestModifyRequest> && value);

    std::unique_ptr<protocol::DirectedQuoteRequestModifyRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::DirectedQuoteRequestModifyRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::DirectedQuoteRequestModifyRequest> m_impl;
};

}
