#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Complete type description, including codec type, high-level user
// representation and more.
//****************************************************************************************

#include <vector>
#include <string>

#include "strategy/Linkage.h"

// namespace tbricks
namespace tbricks {

class String;

class STRATEGY_EXPORT TypeInfo
{
public:
    enum CodecType
    {
        INT32 = 1,
        UINT32 = 2,
        INT64 = 3,
        UINT64 = 4,
        DATE_TIME = 5,
        DOUBLE = 6,
        STRING = 7,
        BINARY = 8,
        BOOLEAN = 9,
        UUID = 10,
        TABLE = 11,
        CURRENCY = 12,
        DATE = 13,
        TIME = 14,
        DURATION = 18,
        GRID_SELECTION = 19,
        CALCULATED_PROPERTY = 20,
        CP_FILTER = 21,
        LEGAL_ENTITY_IDENTIFIER = 22,
        MMT_FLAGS = 23,
        CFI_MASK = 24,
        TABLE_VALUES = 25
    };

    enum HighLevelType
    {
        HLT_NONE = 0,
        HLT_PORTFOLIO = 1,
        HLT_INSTRUMENT = 2,
        HLT_PRICE = 3,
        HLT_VOLUME = 4,
        HLT_TEXT = 5,
        HLT_DOUBLE = 6,
        HLT_BOOLEAN = 7,
        HLT_ENUM = 8,
        HLT_VENUE = 9,
        HLT_INTEGER = 10,
        HLT_DATE_TIME = 11,
        HLT_TRADE = 12,
        HLT_MIC = 13,
        HLT_CURRENCY = 14,
        HLT_DURATION = 15,
        HLT_IDENTIFIER = 16,
        HLT_INSTRUMENT_GROUP = 17,
        HLT_TABLE = 18,
        HLT_BINARY = 19,
        HLT_CFI = 20,
        HLT_DATE = 21,
        HLT_TIME = 22,
        HLT_PARAMETER_CONTEXT = 31,
        HLT_RANKING = 32,
        HLT_GRID_SELECTION = 33,
        HLT_CALCULATED_PROPERTY = 34,
        HLT_CP_FILTER = 35,
        HLT_TREE_NODE = 36,
        HLT_LIQUIDITY_POOL = 40,
        HLT_SUBSYSTEM = 41,
        HLT_LEGAL_ENTITY_IDENTIFIER = 42,
        HLT_TREE_TYPE = 43,
        HLT_MMT_FLAGS = 45,
        HLT_CFI_MASK = 46,
        HLT_BINARY_TABLE = 47
    };

    enum Type
    {
        SFT_NONE,
        SFT_PORTFOLIO,
        SFT_INSTRUMENT,
        SFT_PRICE,
        SFT_VOLUME,
        SFT_TEXT,
        SFT_DOUBLE,
        SFT_BOOLEAN,
        SFT_ENUM,
        SFT_SIDE,
        SFT_VENUE,
        SFT_INTEGER,
        SFT_DATE_TIME,
        SFT_TRADE,
        SFT_MIC,
        SFT_CURRENCY,
        SFT_DURATION,
        SFT_IDENTIFIER,
        SFT_INSTRUMENT_GROUP,
        SFT_TABLE,
        SFT_BINARY,
        SFT_CFI,
        SFT_DATE,
        SFT_TIME,
        SFT_VARIANT,
        SFT_GRID_SELECTION,
        SFT_CALCULATED_PROPERTY,
        SFT_CP_FILTER,
        SFT_SMARTDOUBLE,
        SFT_TREE_NODE,
        SFT_LIQUIDITY_POOL,
        SFT_SUBSYSTEM,
        SFT_LEGAL_ENTITY_IDENTIFIER,
        SFT_TREE_TYPE,
        SFT_QUOTE,
        SFT_DIRECTED_QUOTE,
        SFT_QUOTE_REQUEST,
        SFT_MMT_FLAGS,
        SFT_REMOVE,
        SFT_CFI_MASK,
        SFT_BINARY_TABLE,
        SFT_RANKING
    };

public:
    constexpr TypeInfo(Type type) : m_type(type) {}
    constexpr TypeInfo(const TypeInfo & type_info) = default;
    constexpr TypeInfo & operator=(const TypeInfo & type_info) = default;

    bool operator==(const TypeInfo & type_info) const;
    bool operator!=(const TypeInfo & type_info) const { return !operator==(type_info); }

    constexpr Type GetType() const { return m_type; }
    HighLevelType GetHighLevelType() const;
    CodecType GetCodecType() const;

    const char * GetTypeName() const;
    static const char * GetTypeName(Type type);
    const char * GetCodecTypeName() const;
    const char * GetHighLevelTypeName() const;

    std::ostream & Print(std::ostream & strm) const;
    String ToString() const;
    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const TypeInfo & type_info);

private:
    Type m_type;
};

} // \namespace tbricks
