#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::BySymbologyKeyFilter, matches updates of
// instrument with symbology key.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/type/Currency.h"
#include "strategy/type/MIC.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * BySymbologyKeyFilter matches concrete instrument instance updates
 * having specified security identifier, security identifier source,
 * currency and MIC instrument attributes value.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::BySymbologyKeyFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    /// Default constructor.
    BySymbologyKeyFilter();
    BySymbologyKeyFilter(const BySymbologyKeyFilter & filter);

    BySymbologyKeyFilter & operator=(const BySymbologyKeyFilter & filter);

    ~BySymbologyKeyFilter();

public:
    /**
     * %Set security id of instrument for the filter.
     *
     * @param security_id               security identifier
     */
    void SetSecurityIdentifier(const String & security_id);

    /**
     * %Set security identifier source of instrument for the filter
     *
     * @param security_id_source        security identifier source
     */
    void SetSecurityIdentifierSource(const String & security_id_source);

    /**
     * %Set currency for the filter.
     *
     * @param currency                  instrument currency
     */
    void SetCurrency(const Currency & currency);

    /**
     * %Set MIC code for the filter.
     *
     * @param mic                       MIC code
     */
    void SetMIC(const MIC & mic);

protected:
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual void Clear();
    virtual bool Empty() const;
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_security_id;
    String m_security_id_source;
    Currency m_currency;
    MIC m_mic;
};
}
