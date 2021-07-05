#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Legal Entity Identifier (ISO 17442:2012)
//****************************************************************************************

#include "strategy/type/AnyType.h"

namespace tbricks {

/**
 * A Legal Entity Identifier (or LEI) is a 20-character identifier
 * that identifies distinct legal entities that engage in financial
 * transactions. It is defined by ISO 17442.
 *
 * An LEI consists of a 20-character alphanumeric string, with the
 * first 4 characters identifying the Local Operating Unit (LOU) that
 * issued the LEI. Characters 5 and 6 are reserved as '00'. Characters
 * 7-18 are the unique alphanumeric string assigned to the organisation
 * by the LOU. The final 2 characters are checksum digits.
 */
class STRATEGY_EXPORT LegalEntityIdentifier : public AnyType
{
public:
    LegalEntityIdentifier() { Clear(); }
    LegalEntityIdentifier(const LegalEntityIdentifier & value);

    /**
     * Constructor
     *
     * @param value                     string with an legal entity identifier
     */
    LegalEntityIdentifier(const String & value);

    /**
     * Constructor
     *
     * @param code                      pointer to a null-terminated cracter array
     *                                  with an legal entity identifier
     */
    LegalEntityIdentifier(const char * code);

    LegalEntityIdentifier & operator=(const LegalEntityIdentifier & value);
    LegalEntityIdentifier & operator=(const String & value);
    LegalEntityIdentifier & operator=(const char * lei);

    /**
     * Create LegalEntityIdentifier from string.
     *
     * @param str                       pointer to a character array with an legal
     *                                  entity identifier
     * @param size                      size of the array
     *
     * @return                          "true" if success, "false"
     *                                  otherwise
     */
    bool Set(const char * str, size_t size);

    /**
     * Create LegalEntityIdentifier from string.
     *
     * @param str                       pointer to a null-terminated cracter array
     *                                  with an legal entity identifier
     *
     * @return                          "true" if success, "false"
     *                                  otherwise
     */
    bool Set(const char * str);

    /**
     * Create LegalEntityIdentifier from string.
     *
     * @param str                       string with an legal entity identifier
     *
     * @return                          "true" if success, "false"
     *                                  otherwise
     */
    bool Set(const String & str);

    /**
     * Check whether the legal entity identifier is empty.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const override { return m_str[0] == 0; }

    /**
     *  Clears the contents.
     */
    void Clear() { m_str[0] = 0; }

    /**
     *  Returns a non-modifiable standard C character array version of the
     *  legal entity identifier
     *
     *  @return                     A pointer to a null-terminated character array with
     *                              data equivalent to those stored in the legal entity identifier.
     */
    const char * GetCString() const { return m_str; }

    size_t GetHash() const override;

    /**
     * Get type information
     *
     * @return                      LegalEntityIdentifier type information
     */
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_LEGAL_ENTITY_IDENTIFIER; }

public:
    bool operator<(const LegalEntityIdentifier & value) const;
    bool operator>(const LegalEntityIdentifier & value) const;
    bool operator<=(const LegalEntityIdentifier & value) const;
    bool operator>=(const LegalEntityIdentifier & value) const;
    bool operator==(const LegalEntityIdentifier & value) const;
    bool operator!=(const LegalEntityIdentifier & value) const { return !operator==(value); }

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    enum
    {
        e_value_size = 20
    };

private:
    char m_str[e_value_size + 1];
};
}
