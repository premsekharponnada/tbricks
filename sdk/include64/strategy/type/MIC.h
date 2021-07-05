#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market identification code.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/type/TimeZone.h"
#include "strategy/type/Time.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT MIC : public AnyType
{
public:
    MIC() : m_empty(true) { Clear(); }
    MIC(const MIC & value);
    MIC(const String & value);
    MIC(const char * code);

    void Set(const char * mic, size_t size);

    MIC & operator=(const MIC & value);
    MIC & operator=(const String & value);
    MIC & operator=(const char * mic);

    bool Empty() const override { return m_empty; }
    void Clear();

    const char * GetMIC() const { return m_mic; }

    MIC GetOperatingMIC() const;

    /*
     * Get market timezone. If timezone for the market is not specified,
     * throw exception.
     *
     * @throws EmptyValueException if mic, market for the mic or timezone for the market is not specified
     */
    TimeZone GetMarketTimeZone() const;

    /*
     * Get time of business day end.
     *
     * @throws EmptyValueException if mic, market for the mic or timezone for the market is not specified
     */
    Time GetBusinessDayEnd() const;

    /*
     * Get DateTime next end of business day.
     *
     * @throws EmptyValueException if mic, market for the mic or timezone for the market is not specified
     */
    DateTime GetCurrentBusinessDayEnd() const;

    /*
     * Check if market is active.
     *
     * @throws EmptyValueException if mic or market for the mic is not specidied
     */
    bool IsActive() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_MIC; }

public:
    bool operator==(const MIC & value) const
    {
        if (m_empty) {
            return value.m_empty;
        }
        return (!value.m_empty) && (m_mic[0] == value.m_mic[0]) && (m_mic[1] == value.m_mic[1]) && (m_mic[2] == value.m_mic[2]) &&
               (m_mic[3] == value.m_mic[3]);
    }
    bool operator!=(const MIC & value) const { return !operator==(value); }

    bool operator<(const MIC & value) const;
    bool operator>(const MIC & value) const;

    bool operator<=(const MIC & value) const;
    bool operator>=(const MIC & value) const;

public:
    bool operator==(const String & value) const;
    bool operator!=(const String & value) const;

    bool operator<(const String & value) const;
    bool operator>(const String & value) const;

    bool operator<=(const String & value) const;
    bool operator>=(const String & value) const;

public:
    bool operator==(const char * mic) const;
    bool operator!=(const char * mic) const;

    bool operator<(const char * mic) const;
    bool operator>(const char * mic) const;

    bool operator<=(const char * mic) const;
    bool operator>=(const char * mic) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    bool m_empty;
    char m_mic[5];
};

STRATEGY_EXPORT
bool operator==(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator!=(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator<(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator>(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator<=(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator>=(const String & v1, const MIC & v2);

STRATEGY_EXPORT
bool operator==(const char * v1, const MIC & v2);

STRATEGY_EXPORT
bool operator!=(const char * v1, const MIC & v2);

STRATEGY_EXPORT
bool operator<(const char * v1, const MIC & v2);

STRATEGY_EXPORT
bool operator>(const char * v1, const MIC & v2);

STRATEGY_EXPORT
bool operator<=(const char * v1, const MIC & v2);

STRATEGY_EXPORT
bool operator>=(const char * v1, const MIC & v2);

} // \namespace tbricks
