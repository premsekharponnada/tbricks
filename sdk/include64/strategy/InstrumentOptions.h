#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument::Options class.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Instrument.h"

namespace tbricks {

namespace types {
class Attributes;
}

/**
 * Instrument::Options object.
 *
 * Defined options for the creation of instruments from strategies.
 *
 * Fill members Options class and call SendCreateRequest method
 * to create Instrument as shown below:
 * \code{.cpp}
 *     Instrument::SendCreateRequest(options, request_handler);
 * \endcode
 */
class STRATEGY_EXPORT Instrument::Options : public Printable
{
public:
    /// Default constructor
    Options();
    Options(const Options & options);

    Options & operator=(const Options & options);
    virtual ~Options();

    /**
     * Get the Instrument CFI.
     *
     * @return          const CFI
     */
    const CFI & GetCFI() const;

    /**
     * Get the instrument CFI variant.
     *
     * @return          const value of CFI_Variants enumeration type.
     */
    const Value<CFI_Variant> & GetCFI_Variant() const;

    /**
     * Get instrument currency.
     *
     * @return          const Instrument currency
     */
    const Currency & GetCurrency() const;

    /**
     * Check if instrument is deleted.
     *
     * @return          const Boolean value.
     *                  True if instrument is deleted, false otherwise.
     */
    const Boolean & GetDeleted() const;

    /**
     * Check if instrument is temporary.
     *
     * @return          const Boolean value.
     *                  True if instrument is temporary, false otherwise.
     */
    const Boolean & GetTemporary() const;

    /**
     * Get long name of the instrument.
     *
     * @return          const Instrument's long name
     */
    const String & GetLongName() const;

    /**
     * Get mnemonic of the instrument.
     *
     * @return          const Instrumenr's mnemonic
     */
    const String & GetMnemonic() const;

    /**
     * Get short name of the instrument.
     *
     * @return          const Instrument's short name
     */
    const String & GetShortName() const;

    /**
     * Get instrument extra data.
     *
     * @return          const Instrument extra data
     */
    const ExtraData & GetExtraData() const;

    /**
     * Get Instrument component vector.
     * InstrumentComponent represents an instrument in a composite instrument.
     *
     * @return          const vector of InstrumentComponent
     */
    const std::vector<InstrumentComponent> & GetComponents() const;

    /**
     * Get instrument groups.
     *
     * @return          const Vector of instrument group
     */
    const std::vector<InstrumentGroup> & GetInstrumentGroups() const;

    /**
     * Get instrument price display format.
     *
     * @return          const value of PriceDisplayFormat enumeration type.
     */
    const Value<Instrument::PriceDisplayFormat> & GetPriceDisplayFormat() const;

    /**
     * Get the instrument decimal price display.
     *
     * @return          const Price decimals
     */
    const Integer & GetPriceDisplayDecimals() const;

    /**
     * Get valid until date time of instrument.
     *
     * @return          const valid date time
     */
    const DateTime & GetValidUntilDatetime() const;

    /**
     * Get vector of SymbologyKey.
     *
     * The primary security identifier is kept in the Symbology Key 0
     * vector and is displayed in the Instrument: Security Identifier column,
     * while the security identifier attributes from other venues are stored
     * in subsequent vectors (Symbology Key 1, Symbology Key 2, and so on).
     *
     * @return          const vector of SymbologyKey
     */
    const std::vector<SymbologyKey> & GetSymbologyKeys() const;

    /**
     * Get VenueInstrumentIdentifier of the instrument.
     *
     * @returns         const Vector of VenueInstrumentIdentifier
     */
    const std::vector<VenueInstrumentIdentifier> & GetVenueInstrumentIdentifiers() const;

    /**
     * Get the description of the instrument or comment.
     *
     * @return			const description of the instrument.
     */
    const String & GetComment() const;

    /**
     * Get CFI code of the instrument.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instrument CFI code
     */
    [[deprecated(DEPRECATE_LINK)]] CFI & GetCFI();

    /**
     * Get CFI variant of the instrument
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Value of CFI_Variant enumeration type
     */
    [[deprecated(DEPRECATE_LINK)]] Value<CFI_Variant> & GetCFI_Variant();

    /**
     * Get Instrument Currency.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instrument currency
     */
    [[deprecated(DEPRECATE_LINK)]] Currency & GetCurrency();

    /**
     * Check if instrument is deleted.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			true if instrument is deleted, false otherwise.
     */
    [[deprecated(DEPRECATE_LINK)]] Boolean & GetDeleted();

    /**
     * Check if instrument is set as temporary.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			true if instrument is set as temporary, false otherwise.
     */
    [[deprecated(DEPRECATE_LINK)]] Boolean & GetTemporary();

    /**
     * Get Instrument long name.
     * Any instrument having Long Name as passed to SetLongName
     * method will be provided to the stream. Long Name does not
     * work with wildcards or regex.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instrument long name
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetLongName();

    /**
     * Get Instrument Mnemonic.
     * Any instrument having Mnemonic as passed to SetMnemonic method
     * will be provided to the stream.
     * Mnemonic does not work with wildcards or regex.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instrument mnemonic
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetMnemonic();

    /**
     * Get Instrument short name.
     * Any instrument having Short Name as passed to
     * SetShortName method will be provided to the stream.
     * Short Name does not work with wildcards or regex.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instrument short name
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetShortName();

    /**
     * Get extra data set on the instrument.
     * The extra data consists of a simple dictionary-like object,
     * where you can set key = value for arbitrary string keys and values.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			ExtraData set on the instrument
     */
    [[deprecated(DEPRECATE_LINK)]] ExtraData & GetExtraData();

    /**
     * Get the vector of instruments in a composite instrument.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Vector of InstrumentComponent
     */
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentComponent> & GetComponents();

    /**
     * Get instrument groups.
     * An instrument can belong to several groups.
     * All instruments in Tbricks are organized in group hierarchy trees.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Vector of InstrumentGroup
     */
    [[deprecated(DEPRECATE_LINK)]] std::vector<InstrumentGroup> & GetInstrumentGroups();

    /**
     * Get price display format of the instrument.
     * Fox example,
     * Decimal,
     * Wholes,
     * Halves2, etc
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Value of Instrument::PriceDisplayFormat enumeration type.
     */
    [[deprecated(DEPRECATE_LINK)]] Value<Instrument::PriceDisplayFormat> & GetPriceDisplayFormat();

    /**
     * Get Instrument price display decimals.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Price display of decimals number set on the instrument.
     */
    [[deprecated(DEPRECATE_LINK)]] Integer & GetPriceDisplayDecimals();

    /**
     * Get valid until date time of the instrument.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Instance of DateTime to show instrument valid date time.
     */
    [[deprecated(DEPRECATE_LINK)]] DateTime & GetValidUntilDatetime();

    /**
     * Get symbology keys of the instrument
     *
     * The primary security identifier is kept in the Symbology Key 0
     * vector and is displayed in the Instrument: Security Identifier column,
     * while the security identifier attributes from other venues are stored
     * in subsequent vectors (Symbology Key 1, Symbology Key 2, and so on).
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			vector of SymbologyKey
     */
    [[deprecated(DEPRECATE_LINK)]] std::vector<SymbologyKey> & GetSymbologyKeys();

    /**
     * Get VenueInstrumentIdentifier of the instrument.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @returns          Vector of VenueInstrumentIdentifier
     */
    [[deprecated(DEPRECATE_LINK)]] std::vector<VenueInstrumentIdentifier> & GetVenueInstrumentIdentifiers();

    /**
     * Get the vector of instruments in a composite instrument.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return			Vector of InstrumentComponent
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetComment();

    /**
     * Check if the specified InstrumentAttributes are set on the
     * instrument.
     *
     * @return                 true if the specified InstrumentAttributes  passed
     *                         as the parameter are set on the instrument, false otherwise.
     */
    bool GetAttributes(InstrumentAttributes & attrs) const;

    /**
     * Check if the specified leg attributes are set on the
     * instrument.
     *
     * @return                 true if the specified vector of InstrumentAttributes passed
     *                         as the parameter are set on the instrument, false otherwise.
     */
    bool GetLegAttributes(std::vector<InstrumentAttributes> & attrs) const;

    /**
     * Check if the specified underlying attributes are set on the
     * instrument.
     *
     * @return                 true if the specified vector of InstrumentAttributes passed
     *                         as the parameter are set on the instrument, false otherwise.
     */
    bool GetUnderlyingAttributes(std::vector<InstrumentAttributes> & attrs) const;

    /**
     * Get the vector of instrument attributes of the specified attribute type.
     * Specify the AttributeType and vector of InstrumentAttributes as the
     * parameter.
     *
     * @param type             value of type InstrumentAttributes::AttributeType enumeration.
     *                         Specify the type you are interested in.
     *
     * @param attrs            vector of InstrumentAttributes.
     *                         All the instrument attributes of the
     *                         specified type will be received in vector.
     *
     * @return                 true if instrument have attributes of the specified
     *                         type, false otherwise.
     */
    bool GetAttributes(InstrumentAttributes::AttributeType type, std::vector<InstrumentAttributes> & attrs) const;

    /**
     * %Set Instrument CFI code.
     *
     * @param cfi              const CFI.
     *                         If the string has less then 6 characters,
     *                         the missed characters changed by 'X'.
     */
    void SetCFI(const CFI & cfi);

    /**
     * %Set CFI variant of the instrument.
     *
     * @param cfi_variant	const value of CFI_Variants enumeration type.
     */
    void SetCFI_Variant(const Value<CFI_Variant> & cfi_variant);

    /**
     * %Set instrument currency.
     *
     * @param currency		const instance of currency
     */
    void SetCurrency(const Currency & currency);

    /**
     * %Set instrument state as deleted.
     *
     * @param deleted          const instance of Boolean.
     *                         true to set instrument deleted,
     *                         false otherwise.
     */
    void SetDeleted(const Boolean & deleted);

    /**
     * %Set instrument as temporary.
     *
     * @param deleted          const instance of Boolean.
     *                         true to set instrument deleted,
     *                         false otherwise.
     */
    void SetTemporary(const Boolean & temporary);

    /**
     * %Set instrument long name.
     *
     *@param exchange_long_name	const instance of String.
     */
    void SetLongName(const String & exchange_long_name);

    /**
     * %Set instrument mnemonic.
     *
     * @param exchange_mnemonic	const instance of String.
     */
    void SetMnemonic(const String & exchange_mnemonic);

    /**
     * %Set instrument short name.
     *
     * @param exchange_short_name       const instance of String.
     */
    void SetShortName(const String & exchange_short_name);

    /**
     * %Set extra data of the instrument.
     * The extra data consists of a simple dictionary-like object,
     * where you can set key = value for arbitrary string keys and values.
     *
     * @param extra_data                const instance of ExtraData
     */
    void SetExtraData(const ExtraData & extra_data);

    /**
     * %Set component of the instrument.
     * InstrumentComponent represents an instrument in a composite instrument.
     *
     * @param instrument_components     const vector of InstrumentComponent
     */
    void SetComponents(const std::vector<InstrumentComponent> & instrument_components);

    /**
     * %Set instrument group of the instrument.
     *
     * @param instrument_groups         const vector of InstrumentGroup
     */
    void SetInstrumentGroups(const std::vector<InstrumentGroup> & instrument_groups);

    /**
     * %Set instrument price display format.
     *
     * @param format                    const value of PriceDisplayFormat enumeration type.
     */
    void SetPriceDisplayFormat(const Value<Instrument::PriceDisplayFormat> & format);

    /**
     * %Set the instrument decimal price display.
     *
     * @param decimals                  const Integer which specifies price display decimals value.
     */
    void SetPriceDisplayDecimals(const Integer & decimals);

    /**
     * %Set valid until date time of instrument.
     *
     * @param valid_until_datetime      const instance of DateTime
     */
    void SetValidUntilDatetime(const DateTime & valid_until_datetime);

    /**
     * %Set SymbologyKeys of the instrument.
     *
     * The primary security identifier is kept in the 'Symbology Key 0'
     * vector and is displayed in the 'Instrument: Security Identifier' column,
     * while the security identifier attributes from other venues are stored
     * in subsequent vectors ('Symbology Key 1', 'Symbology Key 2', and so on).
     *
     * @param m_symbology_keys          const vector of SymbologyKey
     */
    void SetSymbologyKeys(const std::vector<SymbologyKey> & m_symbology_keys);

    /**
     * %Set VenueInstrumentIdentifier of the instrument.
     *
     * @param m_viids			const Vector of VenueInstrumentIdentifier
     */
    void SetVenueInstrumentIdentifiers(const std::vector<VenueInstrumentIdentifier> & m_viids);

    /**
     * %Set the description of the instrument or add a comment.
     *
     * @param comment			const instance of String
     */
    void SetComment(const String & comment);
    void Clear();
    bool Empty() const;

    /**
     * %Set the instrument attributes.
     *
     * @param attributes		Instance of InstrumentAttributes
     */
    void SetAttributes(const InstrumentAttributes & attributes);

    /**
     * %Set leg attributes of the instrument.
     *
     * @param attrs                     vector of InstrumentAttributes
     */
    void SetLegAttributes(const std::vector<InstrumentAttributes> & attrs);

    /**
     * %Set underlying attributes of the instrument.
     *
     * @param attrs                     vector of InstrumentAttributes
     */
    void SetUnderlyingAttributes(const std::vector<InstrumentAttributes> & attrs);

    /**
     * %Set instrument attributes of the specified attribute type.
     *
     * @param type                              value of the AttributeType enumeration type.
     *
     * @param attrs                             vector of InstrumentAttributes
     */
    void SetAttributes(InstrumentAttributes::AttributeType type, const std::vector<InstrumentAttributes> & attrs);

    /**
     * Get price structure
     *
     * @return                                  price structure
     */
    const PriceStructure & GetPriceStructure() const;

    /**
     * %Set price structure
     *
     * @param                                   price structure
     */
    void SetPriceStructure(const PriceStructure & value);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    CFI m_cfi;
    Value<CFI_Variant> m_cfi_variant;
    Currency m_currency;
    Boolean m_deleted;
    Boolean m_temporary;
    String m_exchange_long_name;
    String m_exchange_mnemonic;
    String m_exchange_short_name;
    ExtraData m_extra_data;
    std::vector<InstrumentComponent> m_instrument_components;
    std::vector<InstrumentGroup> m_instrument_groups;
    Value<Instrument::PriceDisplayFormat> m_price_display_format;
    Integer m_price_display_decimals;
    DateTime m_valid_until_datetime;
    std::vector<SymbologyKey> m_symbology_keys;
    std::vector<VenueInstrumentIdentifier> m_viids;
    String m_comment;
    friend STRATEGY_EXPORT class Converter;
    types::Attributes * m_attributes;
    PriceStructure m_price_structure;
};

} // namespace tbricks
