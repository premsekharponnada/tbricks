#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QuoteAudit object
//****************************************************************************************

#include <memory>

#include "strategy/Types.h"
#include "strategy/Printable.h"
#include "strategy/Definitions.h"
#include "strategy/RegulatoryParameters.h"

namespace tbricks {

namespace protocol {
class QuoteAudit;
}

// API is draft, so subject to change
class STRATEGY_EXPORT QuoteAudit : public Printable
{
public:
    class Update;

public:
    /**
     * Constructor.
     *
     * Constructs new, empty QuoteAudit instance.
     */
    QuoteAudit();
    QuoteAudit(const QuoteAudit & quote_audit);
    QuoteAudit(QuoteAudit && quote_audit);
    QuoteAudit & operator=(const QuoteAudit & quote_audit);
    QuoteAudit & operator=(QuoteAudit && quote_audit);

    /**
     * Destructor.
     */
    virtual ~QuoteAudit();

    /**
     * Get instrument identifier
     *
     * @param identifier        InstrumentIdentifier
     * @return                  True if QuoteAudit has InstrumentIdentifier
     *                          field, false otherwise
     */
    bool GetInstrumentIdentifier(InstrumentIdentifier & identifier) const;

    /**
     * Get quote mode
     *
     * @param mode              QuoteMode
     * @return                  True if QuoteAudit has QuoteMode
     *                          field, false otherwise
     */
    bool GetQuoteMode(QuoteMode & mode) const;

    /**
     * Get quote identifier
     *
     * @param identifier        Identifier
     * @return                  True if QuoteAudit has QuoteIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteIdentifier(Identifier & identifier) const;

    /**
     * Get quote set indetifier
     *
     * @param identifier        Identifier
     * @return                  True if QuoteAudit has QuoteSetIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteSetIdentifier(Identifier & identifier) const;

    /**
     * Get transaction state
     *
     * @param state             TransactionState
     * @return                  True if QuoteAudit has TransactionState
     *                          field, false otherwise
     */
    bool GetTransactionState(TransactionState & state) const;

    /**
     * Get exchange quote reference
     *
     * @param reference         String
     * @return                  True if QuoteAudit has ExchangeQuoteReference
     *                          field, false otherwise
     */
    bool GetExchangeQuoteReference(String & reference) const;

    /**
     * Get exchange client quote reference
     *
     * @param reference         String
     * @return                  True if QuoteAudit has ExchangeClientQuoteReference
     *                          field, false otherwise
     */
    bool GetExchangeClientQuoteReference(String & reference) const;

    /**
     * Get side
     *
     * @param side              Side
     * @return                  True if QuoteAudit has Side
     *                          field, false otherwise
     */
    bool GetSide(Side & side) const;

    /**
     * Get price
     *
     * @param price             Price
     * @return                  True if QuoteAudit has Price
     *                          field, false otherwise
     */
    bool GetPrice(Price & price) const;

    /**
     * Get volume
     *
     * @param volume            Volume
     * @return                  True if QuoteAudit has Volume
     *                          field, false otherwise
     */
    bool GetVolume(Volume & volume) const;

    /**
     * Get HostModifiedDatetime
     *
     * @param time              DateTime
     * @return                  True if QuoteAudit has
     *                          HostModifierDatetime
     *                          field, false otherwise
     */
    bool GetHostModifiedDatetime(DateTime & time) const;

    /**
     * Get filled volume
     *
     * @param filled_volume     Volume
     * @return                  True if QuoteAudit
     *                          has FilledVolume
     *                          field, false otherwise
     */
    bool GetFilledVolume(Volume & filled_volume) const;

    /**
     * Get mass quote request identifier
     *
     * @param identifier        Variant
     * @return                  True if QuoteAudit
     *                          has MassQuoteRequestIdentifier
     *                          field, false otherwise
     */
    bool GetMassQuoteRequestIdentifier(Variant & identifier) const;

    /**
     * Get liquidity pool identifier.
     *
     * @param                   Returned liquidity pool identifier
     * @return                  True if QuoteAudit has LiquidityPool
     *                          field, false otherwise
     */
    bool GetLiquidityPool(LiquidityPoolIdentifier & identifier) const;

    /**
     * Get quote request identifier
     *
     * @param                   Returned quote request identifier
     * @return                  True if QuoteAudit has QuoteRequestIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteRequestIdentifier(QuoteRequestIdentifier & identifier) const;

    /**
     * Get regulatory audit parameters.
     *
     * @return                          Set of associated fields
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * Check if "InstrumentIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Check if "QuoteMode" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteMode() const;

    /**
     * Check if "QuoteIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteIdentifier() const;

    /**
     * Check if "QuoteSetIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteSetIdentifier() const;

    /**
     * Check if "TransactionState" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasTransactionState() const;

    /**
     * Check if "ExchangeQuoteReference" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasExchangeQuoteReference() const;

    /**
     * Check if "ExchangeClientQuoteReference" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasExchangeClientQuoteReference() const;

    /**
     * Check if "Side" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasSide() const;

    /**
     * Check if "Price" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasPrice() const;

    /**
     * Check if "Volume" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasVolume() const;

    /**
     * Check if "HostModifiedDatetime" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Check if "FilledVolume" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasFilledVolume() const;

    /**
     * Check if "MassQuoteRequestIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasMassQuoteRequestIdentifier() const;

    /**
     * Check if "LiquidityPool" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Check if "QuoteRequestIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteRequestIdentifier() const;

    /**
     * Check if object has association with system QuoteAudit message.
     *
     * @return                          "true" if QuoteAudit is not associated
     *                                  with message, "false"
     *                                  otherwise
     */
    bool Empty() const;

    /**
     * Merge QuoteAudit::Update.
     *
     * @param update                QuoteAudit::Update
     */
    void Merge(const QuoteAudit::Update & update);

protected:
    virtual std::ostream & Print(std::ostream & stream) const;

    std::unique_ptr<protocol::QuoteAudit> m_msg;
};

// API is draft, so subject to change
class STRATEGY_EXPORT QuoteAudit::Update : public Printable
{
public:
    /**
     * Constructor.
     *
     * Constructs new, empty QuoteAudit instance.
     */
    Update() = default;
    Update(const Update & quote_audit);
    Update & operator=(const Update & quote_audit);

    /**
     * Destructor.
     */
    virtual ~Update() = default;

    /**
     * Get instrument identifier
     *
     * @param identifier        InstrumentIdentifier
     * @return                  True if QuoteAudit has InstrumentIdentifier
     *                          field, false otherwise
     */
    bool GetInstrumentIdentifier(InstrumentIdentifier & identifier) const;

    /**
     * Get quote mode
     *
     * @param mode              QuoteMode
     * @return                  True if QuoteAudit has QuoteMode
     *                          field, false otherwise
     */
    bool GetQuoteMode(QuoteMode & mode) const;

    /**
     * Get quote identifier
     *
     * @param identifier        Identifier
     * @return                  True if QuoteAudit has QuoteIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteIdentifier(Identifier & identifier) const;

    /**
     * Get quote set indetifier
     *
     * @param identifier        Identifier
     * @return                  True if QuoteAudit has QuoteSetIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteSetIdentifier(Identifier & identifier) const;

    /**
     * Get transaction state
     *
     * @param state             TransactionState
     * @return                  True if QuoteAudit has TransactionState
     *                          field, false otherwise
     */
    bool GetTransactionState(TransactionState & state) const;

    /**
     * Get exchange quote reference
     *
     * @param reference         String
     * @return                  True if QuoteAudit has ExchangeQuoteReference
     *                          field, false otherwise
     */
    bool GetExchangeQuoteReference(String & reference) const;

    /**
     * Get exchange client quote reference
     *
     * @param reference         String
     * @return                  True if QuoteAudit has ExchangeClientQuoteReference
     *                          field, false otherwise
     */
    bool GetExchangeClientQuoteReference(String & reference) const;

    /**
     * Get side
     *
     * @param side              Side
     * @return                  True if QuoteAudit has Side
     *                          field, false otherwise
     */
    bool GetSide(Side & side) const;

    /**
     * Get price
     *
     * @param price             Price
     * @return                  True if QuoteAudit has Price
     *                          field, false otherwise
     */
    bool GetPrice(Price & price) const;

    /**
     * Get volume
     *
     * @param volume            Volume
     * @return                  True if QuoteAudit has Volume
     *                          field, false otherwise
     */
    bool GetVolume(Volume & volume) const;

    /**
     * Get HostModifiedDatetime
     *
     * @param time              DateTime
     * @return                  True if QuoteAudit has
     *                          HostModifierDatetime
     *                          field, false otherwise
     */
    bool GetHostModifiedDatetime(DateTime & time) const;

    /**
     * Get filled volume
     *
     * @param filled_volume     Volume
     * @return                  True if QuoteAudit
     *                          has FilledVolume
     *                          field, false otherwise
     */
    bool GetFilledVolume(Volume & filled_volume) const;

    /**
     * Get mass quote request identifier
     *
     * @param identifier        Variant
     * @return                  True if QuoteAudit
     *                          has MassQuoteRequestIdentifier
     *                          field, false otherwise
     */
    bool GetMassQuoteRequestIdentifier(Variant & identifier) const;

    /**
     * Get liquidity pool identifier.
     *
     * @param                   Returned liquidity pool identifier
     * @return                  True if QuoteAudit has LiquidityPool
     *                          field, false otherwise
     */
    bool GetLiquidityPool(LiquidityPoolIdentifier & identifier) const;

    /**
     * Get quote request identifier
     *
     * @param                   Returned quote request identifier
     * @return                  True if QuoteAudit has QuoteRequestIdentifier
     *                          field, false otherwise
     */
    bool GetQuoteRequestIdentifier(QuoteRequestIdentifier & identifier) const;

    /**
     * Get regulatory audit parameters.
     *
     * @return                          Set of associated fields
     */
    RegulatoryParameters GetRegulatoryParameters() const;

    /**
     * Check if "InstrumentIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Check if "QuoteMode" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteMode() const;

    /**
     * Check if "QuoteIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteIdentifier() const;

    /**
     * Check if "QuoteSetIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteSetIdentifier() const;

    /**
     * Check if "TransactionState" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasTransactionState() const;

    /**
     * Check if "ExchangeQuoteReference" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasExchangeQuoteReference() const;

    /**
     * Check if "ExchangeClientQuoteReference" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasExchangeClientQuoteReference() const;

    /**
     * Check if "Side" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasSide() const;

    /**
     * Check if "Price" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasPrice() const;

    /**
     * Check if "Volume" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasVolume() const;

    /**
     * Check if "HostModifiedDatetime" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Check if "FilledVolume" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasFilledVolume() const;

    /**
     * Check if "MassQuoteRequestIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasMassQuoteRequestIdentifier() const;

    /**
     * Check if "LiquidityPool" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasLiquidityPool() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Check if "QuoteRequestIdentifier" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasQuoteRequestIdentifier() const;

    /**
     * Check if object has association with system QuoteAudit message.
     *
     * @return                          "true" if QuoteAudit is not associated
     *                                  with message, "false"
     *                                  otherwise
     */
    bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & stream) const;

private:
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class QuoteAudit;

    std::shared_ptr<protocol::QuoteAudit> m_msg;
};

} // namespace tbricks
