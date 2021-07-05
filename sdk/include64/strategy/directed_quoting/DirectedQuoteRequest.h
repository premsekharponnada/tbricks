#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteRequest
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy_generated/DirectedQuoteRequestBase.h"
#include "strategy_generated/DirectedQuoteRequestOptionsBase.h"
#include "strategy_generated/DirectedQuoteRequestModifierBase.h"

#include "strategy/directed_quoting/CounterpartInformation.h"
#include "strategy/directed_quoting/DirectedQuoteRequestLeg.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/DirectedQuoteRequestIdentifier.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/Price.h"
#include "strategy/type/Side.h"
#include "strategy/type/String.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/Volume.h"

namespace tbricks {

/**
 * Request towards venue to provide quotes.
 * Directed quote response can be sent by venue as a result of this request.
 */
class STRATEGY_EXPORT DirectedQuoteRequest : public DirectedQuoteRequestBase
{
public:
    class Options;
    class Modifier;
    class Stream;

public:
    DirectedQuoteRequest() = default;
    DirectedQuoteRequest(std::shared_ptr<protocol::DirectedQuoteRequestRequest> && value) : DirectedQuoteRequestBase(std::move(value)) {}

    using DirectedQuoteRequestBase::DirectedQuoteRequestBase;

    /**
     * @deprecated Deprecated in 2.13.1 use GetValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] DateTime GetValidUntilDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.1 use HasValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasValidUntilDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.2 use GetValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] DateTime GetRespondByDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.2 use HasValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasRespondByDatetime() const;

    Validity GetValidity() const;
    bool HasValidity() const;

public:
    void Merge(const DirectedQuoteRequest & update);
};

/**
 * Special class to create directed quote reuest.
 */
class STRATEGY_EXPORT DirectedQuoteRequest::Options : public DirectedQuoteRequestOptionsBase
{
public:
    /**
     * @deprecated Deprecated in 2.13.2 use GetValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] DateTime GetRespondByDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.2 use HasValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasRespondByDatetime() const;

    /**
     * @deprecated Deprecated in 2.13.2 use SetValidity instead
     */
    [[deprecated(DEPRECATE_LINK)]] void SetRespondByDatetime(const DateTime & value);

    Validity GetValidity() const;
    bool HasValidity() const;
    void SetValidity(const Validity & value);
};

/**
 * Special class to modify directed quote request.
 */
class STRATEGY_EXPORT DirectedQuoteRequest::Modifier : public DirectedQuoteRequestModifierBase
{
public:
    Modifier() = default;
    Modifier(std::unique_ptr<protocol::DirectedQuoteRequestModifyRequest> && value) : DirectedQuoteRequestModifierBase(std::move(value)) {}
};
}
