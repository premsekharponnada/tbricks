#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// PublicTradeByIdentifierFilter, matches trades by trade identifier.
//****************************************************************************************

#include "strategy/type/PublicTradeIdentifier.h"
#include "strategy/stream_filter/PublicTradeFilter.h"

namespace tbricks {

/**
 * PublicTradeByIdentifierFilter matches all trades with trade identifier provided
 * as filter argument.
 */
class STRATEGY_EXPORT PublicTradeByIdentifierFilter : public PublicTradeFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the public trades having
     * identifier as specified in the input parameters.
     *
     * @param identifier                    Instance of PublicTradeIdentifier
     */
    PublicTradeByIdentifierFilter(const PublicTradeIdentifier & identifier);
    PublicTradeByIdentifierFilter(const PublicTradeByIdentifierFilter & filter);

    PublicTradeByIdentifierFilter & operator=(const PublicTradeByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PublicTradeIdentifier m_identifier;
};
}
