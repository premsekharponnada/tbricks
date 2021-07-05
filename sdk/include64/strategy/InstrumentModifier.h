#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument::Modifier class.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Instrument.h"

#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentAggregateParameters.h"

namespace tbricks {

namespace types {
class Attributes;
}

/**
 * Instrument::Modifier object.
 *
 * Defined modify options for sending modify request.
 *
 * Fill members Modifier class and call:
 *
 *     Instrument::SendModifyRequest(modifier, request_handler);
 *
 * for modify instrument.
 *
 * @deprecated Deprecated in 2.14.5, use InstrumentModifier instead
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] Instrument::Modifier : public Printable
{
public:
    Modifier(const InstrumentIdentifier & identifier);
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    virtual ~Modifier();

    const InstrumentIdentifier & GetInstrumentIdentifier() const;

    bool HasShortName() const;
    void SetShortName(const String & short_name);
    const String & GetShortName() const;

    bool HasLongName() const;
    void SetLongName(const String & long_name);
    const String & GetLongName() const;

    bool HasMnemonic() const;
    void SetMnemonic(const String & mnemonic);
    const String & GetMnemonic() const;

    bool HasCFI() const;
    void SetCFI(const CFI & cfi);
    const CFI & GetCFI() const;

    bool HasCFI_Variant() const;
    void SetCFI_Variant(const Value<CFI_Variant> & cfi);
    const Value<CFI_Variant> & GetCFI_Variant() const;

    bool HasCurrency() const;
    void SetCurrency(const Currency & currency);
    const Currency & GetCurrency() const;

    bool HasExtraData() const;
    /**
     * extra data will be deleted from modify request if value is empty
     *
     * @deprecated Deprecated in 2.14.0, will be removed in the next release.
     *             Use "void SetExtraData(const std::optional<ExtraData> & value)"
     */
    [[deprecated(DEPRECATE_LINK)]] void SetExtraData(const ExtraData & value);
    /**
     * extra data will be deleted from modify request if value is empty
     */
    void SetExtraData(const std::optional<ExtraData> & value);
    const ExtraData & GetExtraData() const;

    /**
     * @deprecated Deprecated in 2.14.0, will be removed in the next release.
     *             Use "const ExtraData & GetExtraData() const"
     */
    [[deprecated(DEPRECATE_LINK)]] ExtraData & GetExtraData();

    bool HasComponents() const;
    void SetComponents(const std::vector<InstrumentComponent> & components);
    void GetComponents(std::vector<InstrumentComponent> & components) const;

    bool HasInstrumentGroups() const;
    bool SetInstrumentGroups(const std::vector<InstrumentGroup> & groups);
    void GetInstrumentGroups(std::vector<InstrumentGroup> & groups) const;
    bool AddInstrumentGroup(const InstrumentGroup & group);
    bool DeleteInstrumentGroup(const InstrumentGroup & group);

    bool HasSymbologyKeys() const;
    /**
     * %Set SymbologyKey's.
     *
     * Duplicates will be skiped.
     *
     * @return true, if all SymbologyKey's are valid (SecurityIdentifier and SecurityIdentifierSource are not empty).
     */
    bool SetSymbologyKeys(const std::vector<SymbologyKey> & symbology_keys);
    void GetSymbologyKeys(std::vector<SymbologyKey> & symbology_keys) const;
    /**
     * Add SymbologyKey.
     *
     * symbology_key will be skiped, if it already exist.
     *
     * @return true, if symbology_key is valid (SecurityIdentifier and SecurityIdentifierSource are not empty).
     */
    bool AddSymbologyKey(const SymbologyKey & symbology_key);
    /**
     * Delete SymbologyKey.
     *
     * If there are no SymbologyKey's, it will call Instrument::Resolve(), to get SymbologyKey's.
     *
     * @return true, if symbology_key is valid (SecurityIdentifier and SecurityIdentifierSource are not empty).
     */
    bool DeleteSymbologyKey(const SymbologyKey & symbology_key);

    bool HasVenueInstrumentIdentifiers() const;
    bool SetVenueInstrumentIdentifiers(const std::vector<VenueInstrumentIdentifier> & viids);
    void GetVenueInstrumentIdentifiers(std::vector<VenueInstrumentIdentifier> & viids) const;
    bool AddVenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);
    bool DeleteVenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);

    bool HasDeleted() const;
    void SetDeleted(const Boolean & is_deleted);
    const Boolean & GetDeleted() const;

    bool HasTemporary() const;
    void SetTemporary(const Boolean & is_temporary);
    const Boolean & GetTemporary() const;

    bool HasPriceDisplayFormat() const;
    void SetPriceDisplayFormat(const Value<Instrument::PriceDisplayFormat> & format);
    const Value<Instrument::PriceDisplayFormat> & GetPriceDisplayFormat() const;

    bool HasPriceDisplayDecimals() const;
    void SetPriceDisplayDecimals(const Integer & decimals);
    const Integer & GetPriceDisplayDecimals() const;

    bool HasComment() const;
    void SetComment(const String & comment);
    const String & GetComment() const;

    /**
     * Check if field is set.
     *
     * @return                "true" if field is set, "false"
     *                        otherwise
     */
    bool HasValidUntilDatetime() const;

    /**
     * %Set valid until date time
     *
     * @param value           valid until date time
     */
    void SetValidUntilDatetime(const DateTime & value);

    /**
     * Get valid until date time of instrument.
     *
     * @return                valid until date time
     */
    const DateTime & GetValidUntilDatetime() const;

    void SetAttributes(const InstrumentAttributes & attributes);
    void SetLegAttributes(const std::vector<InstrumentAttributes> & attributes);
    void SetUnderlyingAttributes(const std::vector<InstrumentAttributes> & attributes);
    void SetAttributes(InstrumentAttributes::AttributeType type, const std::vector<InstrumentAttributes> & attributes);

    /**
     * Get price structure
     *
     * @return                                  price structure
     */
    const PriceStructure & GetPriceStructure() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasPriceStructure() const;

    /**
     * %Set price structure
     *
     * @param                                   price structure
     */
    void SetPriceStructure(const PriceStructure & value);

    bool HasAttributes() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_identifier;
    String m_short_name;
    String m_long_name;
    String m_mnemonic;
    CFI m_cfi;
    Value<CFI_Variant> m_cfi_variant;
    Currency m_currency;
    ExtraData m_extra_data;
    bool m_has_extra_data = false;
    Value<std::vector<InstrumentComponent>> m_components;
    Value<std::vector<InstrumentGroup>> m_instrument_groups;
    Value<std::vector<SymbologyKey>> m_symbology_keys;
    Value<std::vector<VenueInstrumentIdentifier>> m_viids;
    String m_fixml;
    Boolean m_deleted;
    Boolean m_temporary;
    Value<Instrument::PriceDisplayFormat> m_price_display_format;
    Integer m_price_display_decimals;
    String m_comment;
    DateTime m_valid_until_datetime;
    PriceStructure m_price_structure;

    friend STRATEGY_EXPORT class Converter;

    types::Attributes * m_attributes;
};

} // namespace tbricks
