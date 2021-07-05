#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Currency code.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/type/InstrumentGroupIdentifier.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT Currency : public AnyType
{
public:
    Currency();
    Currency(const Currency & currency);
    Currency(const String & code);
    Currency(const char * code);

    Currency & operator=(const Currency & currency);
    Currency & operator=(const String & code);
    Currency & operator=(const char * code);

    bool Empty() const override { return m_empty; }
    void Clear();
    size_t GetHash() const override;

    const char * GetCode() const;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_CURRENCY; }

public:
    /// return related group identifier, <empty> if not found
    InstrumentGroupIdentifier GetInstrumentGroupIdentifier() const;

    /// init currency from currency instrument group identifier
    /// return false if cannot resolve currency
    bool Resolve(const InstrumentGroupIdentifier & group_id);

public:
    bool operator==(const Currency & currency) const;
    bool operator!=(const Currency & currency) const;

    bool operator<(const Currency & currency) const;
    bool operator>(const Currency & currency) const;

    bool operator<=(const Currency & currency) const;
    bool operator>=(const Currency & currency) const;

public:
    bool operator==(const String & code) const;
    bool operator!=(const String & code) const;

    bool operator<(const String & code) const;
    bool operator>(const String & code) const;

    bool operator<=(const String & code) const;
    bool operator>=(const String & code) const;

public:
    bool operator==(const char * code) const;
    bool operator!=(const char * code) const;

    bool operator<(const char * code) const;
    bool operator>(const char * code) const;

    bool operator<=(const char * code) const;
    bool operator>=(const char * code) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    char m_code[4];
};

STRATEGY_EXPORT
bool operator==(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator!=(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator<(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator>(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator<=(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator>=(const String & v1, const Currency & v2);

STRATEGY_EXPORT
bool operator==(const char * v1, const Currency & v2);

STRATEGY_EXPORT
bool operator!=(const char * v1, const Currency & v2);

STRATEGY_EXPORT
bool operator<(const char * v1, const Currency & v2);

STRATEGY_EXPORT
bool operator>(const char * v1, const Currency & v2);

STRATEGY_EXPORT
bool operator<=(const char * v1, const Currency & v2);

STRATEGY_EXPORT
bool operator>=(const char * v1, const Currency & v2);

} // \namespace tbricks
