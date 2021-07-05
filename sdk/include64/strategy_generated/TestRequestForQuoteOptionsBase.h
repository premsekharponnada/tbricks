#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestRequestForQuoteOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Identifier;
class LiquidityPoolIdentifier;
class MarketDataParameters;
class Side;
class String;
class TreeNodeIdentifier;
class Volume;
enum class RequestForQuoteType;


namespace protocol { class RequestForQuote; }

class STRATEGY_EXPORT TestRequestForQuoteOptionsBase : public Printable
{
protected:
    TestRequestForQuoteOptionsBase();
    TestRequestForQuoteOptionsBase(const TestRequestForQuoteOptionsBase & value);
    TestRequestForQuoteOptionsBase(TestRequestForQuoteOptionsBase && value) noexcept;
    TestRequestForQuoteOptionsBase & operator=(const TestRequestForQuoteOptionsBase & value);
    TestRequestForQuoteOptionsBase & operator=(TestRequestForQuoteOptionsBase && value) noexcept;
    virtual ~TestRequestForQuoteOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get quote request identifier.
     *
     *
     * @return                          quote request identifier
     */
    Identifier GetIdentifier() const;

    /**
     * %Set quote request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     quote request identifier
     */
    void SetIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCounterpart() const;

    /**
     * Get counterpart.
     *
     *
     * @return                          counterpart
     */
    String GetCounterpart() const;

    /**
     * %Set counterpart.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     counterpart
     */
    void SetCounterpart(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeRequestForQuoteReference() const;

    /**
     * Get exchange request for quote reference.
     *
     *
     * @return                          exchange request for quote reference
     */
    String GetExchangeRequestForQuoteReference() const;

    /**
     * %Set exchange request for quote reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange request for quote reference
     */
    void SetExchangeRequestForQuoteReference(const String & value);

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

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasType() const;

    /**
     * Get request for quote type.
     *
     *
     * @return                          request for quote type
     */
    std::optional<RequestForQuoteType> GetType() const;

    /**
     * %Set request for quote type.
     *
     *
     * @param value                     request for quote type
     */
    void SetType(std::optional<RequestForQuoteType> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParameters() const;

    /**
     * Get market data parameters.
     *
     *
     * @return                          market data parameters
     */
    MarketDataParameters GetParameters() const;

    /**
     * %Set market data parameters.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     market data parameters
     */
    void SetParameters(const MarketDataParameters & value);

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
     * %Set client.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     client
     */
    void SetClient(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLiquidityPoolIdentifier() const;

    /**
     * Get liquidity pool identifier.
     *
     *
     * @return                          liquidity pool identifier
     */
    LiquidityPoolIdentifier GetLiquidityPoolIdentifier() const;

    /**
     * %Set liquidity pool identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     liquidity pool identifier
     */
    void SetLiquidityPoolIdentifier(const LiquidityPoolIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeCreatedDatetime() const;

    /**
     * Get exchange created datetime.
     *
     *
     * @return                          exchange created datetime
     */
    DateTime GetExchangeCreatedDatetime() const;

    /**
     * %Set exchange created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange created datetime
     */
    void SetExchangeCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidUntilDatetime() const;

    /**
     * Get valid until datetime.
     *
     *
     * @return                          valid until datetime
     */
    DateTime GetValidUntilDatetime() const;

    /**
     * %Set valid until datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     valid until datetime
     */
    void SetValidUntilDatetime(const DateTime & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestRequestForQuoteOptionsBase & update);

/** @cond PRIVATE */
public:
    TestRequestForQuoteOptionsBase(const protocol::RequestForQuote & value);
    TestRequestForQuoteOptionsBase(std::shared_ptr<protocol::RequestForQuote> && value);

    std::shared_ptr<protocol::RequestForQuote> & get_impl_wr() const;
    const std::shared_ptr<protocol::RequestForQuote> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::RequestForQuote> m_impl;
};

}
