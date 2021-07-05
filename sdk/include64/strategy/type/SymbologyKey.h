#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Symbology Key
//****************************************************************************************

#include <memory>

#include "strategy/Printable.h"

#include "strategy/type/Currency.h"
#include "strategy/type/MIC.h"
#include "strategy/type/String.h"

namespace tbricks {

namespace types {
class SymbologyKey;
}

//****************************************************************************
// SymbologyKey Class
//****************************************************************************

class STRATEGY_EXPORT SymbologyKey : public Printable
{
public:
    SymbologyKey();
    SymbologyKey(const String & security_id, const String & security_id_source, const Currency & currency = Currency(), const MIC & mic = MIC());
    SymbologyKey(const SymbologyKey & other);
    SymbologyKey(SymbologyKey && other) noexcept;

    SymbologyKey & operator=(const SymbologyKey & other);
    SymbologyKey & operator=(SymbologyKey && other) noexcept;

    ~SymbologyKey() override;

    /**
     * Security identifier, ie ISIN or SYMBOL value
     */
    String GetSecurityIdentifier() const;
    /**
     * Type of security identifier, ie 4 for ISIN, 8 for SYMBOL, etc
     */
    String GetSecurityIdentifierSource() const;
    Currency GetCurrency() const;
    /**
     * Primary MIC
     */
    MIC GetMIC() const;

    void SetSecurityIdentifier(const String & security_id);
    void SetSecurityIdentifierSource(const String & security_id_source);
    void SetCurrency(const Currency & currency);
    void SetMIC(const MIC & mic);

    void ClearCurrency();
    void ClearMIC();

    void Clear();
    bool Empty() const;

    size_t GetHash() const;

    bool operator<(const SymbologyKey & other) const;
    bool operator<=(const SymbologyKey & other) const;
    bool operator>(const SymbologyKey & other) const;
    bool operator>=(const SymbologyKey & other) const;
    bool operator==(const SymbologyKey & other) const;
    bool operator!=(const SymbologyKey & other) const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    SymbologyKey(types::SymbologyKey && other);
    SymbologyKey & operator=(const types::SymbologyKey & other);
    SymbologyKey & operator=(types::SymbologyKey && other) noexcept;

private:
    friend STRATEGY_EXPORT class Converter;
    std::unique_ptr<types::SymbologyKey> m_impl;
};

inline size_t hash_value(const SymbologyKey & value)
{
    return value.GetHash();
}
}
