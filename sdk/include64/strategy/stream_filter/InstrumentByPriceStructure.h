#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByPriceStructure
//****************************************************************************************

#include "strategy/type/PriceStructure.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ByPriceStructure matches updates of
 * instrument with specified price structure
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByPriceStructure : public InstrumentStream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments created with
     * specified price structure.
     */
    ByPriceStructure(const PriceStructure & price_structure);
    ByPriceStructure(const ByPriceStructure & filter);

    ByPriceStructure & operator=(const ByPriceStructure & filter);

    /**
     * Get price structure
     *
     * @return                          Price structure
     */
    const PriceStructure & GetPriceStructure() const;

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PriceStructure m_price_structure;
};
}
