#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Direct quoting class
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy_generated/DirectedQuoteBase.h"
#include "strategy_generated/DirectedQuoteOptionsBase.h"
#include "strategy_generated/DirectedQuoteModifierBase.h"
#include "strategy_generated/DirectedQuoteModifyBase.h"

#include "strategy/directed_quoting/DirectedQuoteLeg.h"

#include "strategy/RegulatoryParameters.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/DirectedQuoteIdentifier.h"
#include "strategy/type/OrderCapacity.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/Price.h"
#include "strategy/type/QuoteRequestIdentifier.h"
#include "strategy/type/String.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/type/Volume.h"
#include "strategy/type/DirectedQuoteLegIdentifier.h"

#include <vector>
#include <memory>

namespace tbricks {

namespace pe {
class DirectedQuoteListener;
}

//****************************************************************************
// Direct quoting class
//****************************************************************************

/**
 * Directed quote class can be used in Matching Engine.
 */
class STRATEGY_EXPORT DirectedQuote : public DirectedQuoteBase
{
public:
    class Options;
    class Modifier;
    class Stream;
    class Modify;

public:
    DirectedQuote(const DirectedQuoteIdentifier & id);
    DirectedQuote(const protocol::DirectedQuote & quote);
    DirectedQuote(std::shared_ptr<protocol::DirectedQuote> quote);
    DirectedQuote() = default;
    DirectedQuote(const DirectedQuote & value) = default;
    DirectedQuote & operator=(const DirectedQuote & value) = default;

    ~DirectedQuote() = default;

public:
    /**
     * @deprecated Deprecated in 2.14.0.
     *             Use SetLegs(...) instead of SetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] void GetDirectedQuoteLegs(std::vector<DirectedQuoteLeg> & legs) const;

    /**
     * Get vector of Directed Quote legs
     */
    void GetLegs(std::vector<DirectedQuoteLeg> & legs) const;

    /**
     * Get validity
     */
    bool GetValidity(Validity & validity) const;

    Currency GetDealtCurrency() const;
    bool GetDealtCurrency(Currency & dealtCurrency) const;

    bool Merge(const Modify & update);

    bool Merge(const Modifier & update);

    /**
     *  Overrides local copy with received update
     */
    bool Merge(const DirectedQuote & update);

private:
    friend class DirectedQuoteManager;
    friend class Trading;
    friend class pe::DirectedQuoteListener;
};

/**
 * Directed quote options class must be used for creating directed quotes from directed quote manager.
 */
class STRATEGY_EXPORT DirectedQuote::Options : public DirectedQuoteOptionsBase
{
public:
    Options();
    ~Options();

public:
    /**
     * @deprecated Deprecated in 2.14.0.
     *             Use SetLegs(...) instead of SetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] bool SetDirectedQuoteLegs(const std::vector<DirectedQuoteLeg> & legs);

    /**
     * Set Directed Quote legs
     *
     * Identifiers of legs will be recreate.
     *
     * @return    true if success,
     *            false otherwise
     */
    bool SetLegs(const std::vector<DirectedQuoteLeg> & legs);

    /**
     * Set validity
     */
    void SetValidity(const Validity & validity);

    void SetDealtCurrency(const Currency & dealtCurrency);

private:
    friend class DirectedQuoteManager;
};

/**
 * Directed quote modify class must be used for creating directed quotes from directed quote manager.
 */
class STRATEGY_EXPORT DirectedQuote::Modifier : public DirectedQuoteModifierBase
{
public:
    Modifier();

    /**
     * @deprecated Deprecated in 2.14.0.
     */
    [[deprecated(DEPRECATE_LINK)]] Modifier(const DirectedQuoteIdentifier & id);

    ~Modifier();

    /**
     * @deprecated Deprecated in 2.14.0.
     */
    [[deprecated(DEPRECATE_LINK)]] DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

    /**
     * @deprecated Deprecated in 2.14.0.
     *             Use SetLegs(...) instead of SetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] bool SetDirectedQuoteLegs(const std::vector<DirectedQuoteLeg> & legs);

    /**
     * Set Directed Quote legs
     */
    bool SetLegs(const std::vector<DirectedQuoteLeg> & legs);

private:
    friend class DirectedQuoteManager;
};

/**
 * Directed quote class can be used in Matching Engine.
 */
class STRATEGY_EXPORT DirectedQuote::Modify : public DirectedQuoteModifyBase
{
public:
    Modify(const protocol::DirectedQuoteModifyRequest & quote);

    ~Modify();

    /**
     * @deprecated Deprecated in 2.14.0.
     *             Use SetLegs(...) instead of SetDirectedQuoteLegs(...).
     */
    [[deprecated(DEPRECATE_LINK)]] void GetDirectedQuoteLegs(std::vector<DirectedQuoteLeg> & legs) const;

    /**
     * Get vector of Directed Quote legs
     */
    void GetLegs(std::vector<DirectedQuoteLeg> & legs) const;

private:
    friend class DirectedQuote;
};
}
