#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument IRD XML printer.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Instrument.h"
#include "strategy/InstrumentModifier.h"
#include "strategy/Printable.h"
#include "strategy/type/InstrumentGroup.h"
#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentAggregateParameters.h"
#include "strategy/instrument/InstrumentGroupParameters.h"
#include "strategy/instrument/InstrumentGroupAggregateParameters.h"

namespace tbricks {

/**
 * NOTE: this class is deprecated and might be removed in the next release
 */
class STRATEGY_EXPORT IrdXmlPrinter : public Printable
{
public:
    /**
     * @deprecated Deprecated in 2.14.5
     */
    class [[deprecated(DEPRECATE_LINK)]] IInstrumentModifier
    {
    public:
        /**
         * Return InstrumentModifier, which will be applied to the instrument
         * before converting to XML.
         */
        virtual Instrument::Modifier GetModifier(const Instrument & instrument) = 0;

    protected:
        virtual ~IInstrumentModifier() = default;
    };

public:
    IrdXmlPrinter();
    /**
     * @deprecated Deprecated in 2.14.5
     */
    [[deprecated(DEPRECATE_LINK)]] IrdXmlPrinter(IInstrumentModifier & modifier);
    ~IrdXmlPrinter();

    void AddInstrument(const Instrument & instrument);
    void AddInstrumentAndParameters(const Instrument & instrument, const InstrumentParameters & parameters);
    void AddInstrumentAndParameters(const Instrument & instrument, const InstrumentAggregateParameters & parameters);

    void AddGroup(const InstrumentGroup & group);
    void AddGroupAndParameters(const InstrumentGroup & group, const InstrumentGroupParameters & parameters);
    void AddGroupAndParameters(const InstrumentGroup & group, const InstrumentGroupAggregateParameters & parameters);

    static std::ostream & Print(std::ostream & stream, const Instrument & instrument, const InstrumentParameters & parameters);

    static std::ostream & Print(std::ostream & stream, const InstrumentGroup & group, const InstrumentGroupParameters & parameters);

    /**
     * Return String with IRD XML.
     */
    virtual String ToString() const;

    /**
     * Print IRD XML to the stream.
     */
    virtual std::ostream & Print(std::ostream & stream) const;

private:
    class Impl;
    Impl * m_impl;
    [[deprecated(DEPRECATE_LINK)]] IInstrumentModifier * m_modifier;
};
}
