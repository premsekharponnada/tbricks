#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentStream::Filters::ByAttributesFilter, matches instrument updates
// by specified attribute selection.
//****************************************************************************************

#include <vector>

#include "strategy/type/String.h"
#include "strategy/type/CFIMask.h"
#include "strategy/Instrument.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/stream/InstrumentStream.h"

namespace tbricks {

/**
 * InstrumentStream::Filters::ByAttributesFilter matches concrete instrument instance updates
 * having specific instrument attribute/attributes.
 */
class STRATEGY_EXPORT InstrumentStream::Filters::ByAttributesFilter : public InstrumentStream::Filters::FilterCondition
{
public:
    ByAttributesFilter();
    ByAttributesFilter(const ByAttributesFilter & filter) = default;

    ByAttributesFilter & operator=(const ByAttributesFilter & filter) = default;

    /**
     * %Set the CFI code for the filter.
     *
     * @param cfi                   The CFi code. Use "X" for wildcards.
     *
     * E.g. "XSXXXX" matches all CFI codes with "S" as the second letter.
     *
     * @deprecated Deprecated in 2.14.0, use SetCFIMask
     */
    [[deprecated(DEPRECATE_LINK)]] void SetCFI(const CFI & cfi);

    /**
     * %Set the CFIMask code for the filter.
     *
     * @param cfi                   The CFi code. Use "X" for wildcards.
     */
    void SetCFIMask(const CFIMask & mask);

    /**
     * %Set the CFI variant for the filter.
     *
     * @param cfi_variant           Value of type CFI_Variant enumeration.
     */
    void SetCFI_Variant(Instrument::CFI_Variant cfi_variant);

    /**
     * %Set the instrument short name for the filter.
     *
     * @param short_name            instrument's short name
     */
    void SetShortName(const String & short_name);

    /**
     * %Set the instrument log name for the filter.
     *
     * @param long_name             instrument's long name
     */
    void SetLongName(const String & long_name);

    /**
     * %Set the instrument mnemonic for the filter.
     *
     * @param mnemonic              instrument's mnemonic
     */
    void SetMnemonic(const String & mnemonic);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    CFIMask m_cfi_mask;
    Instrument::CFI_Variant m_cfi_variant;
    String m_short_name;
    String m_long_name;
    String m_mnemonic;
};
}
