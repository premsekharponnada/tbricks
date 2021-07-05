#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class CFI;
class Currency;
class DateTime;
class ExtraData;
class InstrumentComponent;
class PriceStructure;
class String;
class SymbologyKey;


namespace protocol { class Instrument; }

class STRATEGY_EXPORT InstrumentBase : public Printable
{
protected:
    InstrumentBase();
    InstrumentBase(const InstrumentBase & value);
    InstrumentBase(InstrumentBase && value) noexcept;
    InstrumentBase & operator=(const InstrumentBase & value);
    InstrumentBase & operator=(InstrumentBase && value) noexcept;
    virtual ~InstrumentBase();

public:
    /**
     * Check if field is set.
     *
     * The exchange short name of the instrument, could be similar to
     * exchange mnemonic but could also be the company name or similar
     * (e.g. IBM Ltd.).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasShortName() const;

    /**
     * Get exchange short name.
     *
     * The exchange short name of the instrument, could be similar to
     * exchange mnemonic but could also be the company name or similar
     * (e.g. IBM Ltd.).
     *
     *
     * @return                          exchange short name
     */
    String GetShortName() const;

    /**
     * Check if field is set.
     *
     * The exchange long name of the instrument, full description (e.g.
     * International Business Machines, Global Operations Ltd.).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLongName() const;

    /**
     * Get exchange long name.
     *
     * The exchange long name of the instrument, full description (e.g.
     * International Business Machines, Global Operations Ltd.).
     *
     *
     * @return                          exchange long name
     */
    String GetLongName() const;

    /**
     * Check if field is set.
     *
     * The exchange mnemonic of the instrument, generally the ticker symbol
     * (e.g. IBM).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMnemonic() const;

    /**
     * Get exchange mnemonic.
     *
     * The exchange mnemonic of the instrument, generally the ticker symbol
     * (e.g. IBM).
     *
     *
     * @return                          exchange mnemonic
     */
    String GetMnemonic() const;

    /**
     * Check if field is set.
     *
     * Classification of Financial Instruments, ISO 10962.             This
     * is a six character taxonomy describing the instrument class and
     * some of its properties.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCFI() const;

    /**
     * Get cfi code.
     *
     * Classification of Financial Instruments, ISO 10962.             This
     * is a six character taxonomy describing the instrument class and
     * some of its properties.
     *
     *
     * @return                          cfi code
     */
    CFI GetCFI() const;

    /**
     * Check if field is set.
     *
     * Field indicating if a given item is deleted or no / scheduled for
     * removal.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     * Field indicating if a given item is deleted or no / scheduled for
     * removal.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * Check if field is set.
     *
     * Indicates that instrument is to be removed at start of day.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTemporary() const;

    /**
     * Get temporary instrument.
     *
     * Indicates that instrument is to be removed at start of day.
     *
     *
     * @return                          temporary instrument
     */
    Boolean GetTemporary() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

    /**
     * Check if field is set.
     *
     * A specific date or date/time for how long an order/strategy should
     * be considered valid before being withdrawn.             A date
     * stipulates validity for the full and inclusive date and a
     * date/time the full and inclusive time.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasValidUntilDatetime() const;

    /**
     * Get valid until datetime.
     *
     * A specific date or date/time for how long an order/strategy should
     * be considered valid before being withdrawn.             A date
     * stipulates validity for the full and inclusive date and a
     * date/time the full and inclusive time.
     *
     *
     * @return                          valid until datetime
     */
    DateTime GetValidUntilDatetime() const;

    /**
     * Check if field is set.
     *
     * Specifies how a price should be structured for input/output for an
     * end-user.             As all data is normalized within the
     * system, this is required to allow for expected
     * presentation for end-users (e.g. penny-noted stocks or
     * fractions).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPriceStructure() const;

    /**
     * Get price structure.
     *
     * Specifies how a price should be structured for input/output for an
     * end-user.             As all data is normalized within the
     * system, this is required to allow for expected
     * presentation for end-users (e.g. penny-noted stocks or
     * fractions).
     *
     *
     * @return                          price structure
     */
    PriceStructure GetPriceStructure() const;

    /**
     * Check if field is set.
     *
     * The components, or legs, of a combination instrument expressed in
     * internal instrument identifier representation.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentComponents() const;

    /**
     * Get instrument components.
     *
     * The components, or legs, of a combination instrument expressed in
     * internal instrument identifier representation.
     *
     *
     * @return                          instrument components
     */
    std::vector<InstrumentComponent> GetInstrumentComponents() const;

    /**
     * Check if field is set.
     *
     * Extra persistent data associated with the orders/quotes/trades.
     * All modification operations that contains dictionaries (such as
     * 'extra data', 'strategy parameters') operates on a per-key
     * basis.              This means that only the specified keys
     * will be impacted by modifications. Any existing keys in the
     * target dictionary will remain untouched.             Setting
     * the value of a key to 'nil' is semantically equivalent to
     * removing it.              All keys should be unique, and to
     * ensure that there is no namespace conflicts a DNS-like standard
     * naming convention has been adopted.             The prefix of a
     * unique key is always written in all-lowercase ASCII letters and
     * should be one of the top-level domain names or             one
     * of the English two-letter codes identifying countries as
     * specified in the ISO Standard 3166, 1981.
     * Subsequent components of the key vary according to the adopted
     * naming conventions of the creator. Typically this will be the
     * company name.              Examples:
     * com.bigbucksareus.orderrouting.destination
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     * Extra persistent data associated with the orders/quotes/trades.
     * All modification operations that contains dictionaries (such as
     * 'extra data', 'strategy parameters') operates on a per-key
     * basis.              This means that only the specified keys
     * will be impacted by modifications. Any existing keys in the
     * target dictionary will remain untouched.             Setting
     * the value of a key to 'nil' is semantically equivalent to
     * removing it.              All keys should be unique, and to
     * ensure that there is no namespace conflicts a DNS-like standard
     * naming convention has been adopted.             The prefix of a
     * unique key is always written in all-lowercase ASCII letters and
     * should be one of the top-level domain names or             one
     * of the English two-letter codes identifying countries as
     * specified in the ISO Standard 3166, 1981.
     * Subsequent components of the key vary according to the adopted
     * naming conventions of the creator. Typically this will be the
     * company name.              Examples:
     * com.bigbucksareus.orderrouting.destination
     *
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * Check if field is set.
     *
     * Take care about currency group yourself if you use InstrumnetService
     * version less then 2.14.5
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     * Take care about currency group yourself if you use InstrumnetService
     * version less then 2.14.5
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSymbologyKeys() const;

    /**
     * Get symbology keys.
     *
     *
     * @return                          symbology keys
     */
    std::vector<SymbologyKey> GetSymbologyKeys() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    InstrumentBase(const protocol::Instrument & value);
    InstrumentBase(std::shared_ptr<protocol::Instrument> && value);

    std::shared_ptr<protocol::Instrument> & get_impl_wr() const;
    const std::shared_ptr<protocol::Instrument> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Instrument> m_impl;
};

}
