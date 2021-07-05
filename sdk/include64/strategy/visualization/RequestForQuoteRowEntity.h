#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Request For Quote Row Entity public interface.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class RequestForQuote;

namespace visualization {

/**
 * RowEntity implementation containing RequestForQuoteRowEntity object.
 *
 */
class STRATEGY_EXPORT RequestForQuoteRowEntity final : public RowEntity
{
public:
    RequestForQuoteRowEntity();

    RequestForQuoteRowEntity(const RequestForQuoteRowEntity & other) = default;
    RequestForQuoteRowEntity(RequestForQuoteRowEntity && other) noexcept = default;
    RequestForQuoteRowEntity & operator=(const RequestForQuoteRowEntity & other) = default;
    RequestForQuoteRowEntity & operator=(RequestForQuoteRowEntity && other) noexcept = default;

    /**
     * Get request for quote object stored in row entity.
     *
     * @return request for quote
     */
    const RequestForQuote & GetRequestForQuote() const;

    /**
     * Get order object stored in row entity.
     *
     * @return request for quote
     */
    void SetRequestForQuote(const RequestForQuote & rfq);

    ~RequestForQuoteRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks
