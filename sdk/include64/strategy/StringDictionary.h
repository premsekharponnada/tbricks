#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Additional data, available as a strategy property.
//****************************************************************************************

#include <vector>
#include <string>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/String.h"

#include <memory>

namespace tbricks {

class Variant;
namespace types {
class Dictionary;
class DictionaryRef;
}
namespace types {
class StrategyInstance;
}
namespace strategy {
struct DataRef;
}
namespace protocol {
class StrategyInstance;
}

class STRATEGY_EXPORT StringDictionary : public Printable
{
public:
    StringDictionary();
    StringDictionary(const StringDictionary & src);
    StringDictionary(StringDictionary && src) noexcept;
    ~StringDictionary();

    StringDictionary & operator=(const StringDictionary & src);
    StringDictionary & operator=(StringDictionary && src) noexcept;

    bool operator==(const StringDictionary & extra_data) const;
    bool operator!=(const StringDictionary & extra_data) const;

public:
    StringDictionary(const tbricks::types::Dictionary & value);
    StringDictionary(tbricks::types::Dictionary && value) noexcept;

    StringDictionary & operator=(const tbricks::types::Dictionary & src);
    StringDictionary & operator=(tbricks::types::Dictionary && src) noexcept;

public:
    /**
     * Get value into a variable of a simple type.
     * This method can corrupt value on failed execution.
     *
     * @param key                       Key
     * @param value                     Value
     */
    bool GetValue(const String & key, AnyType & value) const;

    /**
     * %Set value by name from a variable of a simple type.
     *
     * If data with such key already exists in the container, its value
     * is overriden.
     * Update flag isn't set, if new and old values are the same.
     *
     * @param key                       Key
     * @param value                     Value
     */
    void SetValue(const String & key, const AnyType & value);

    /**
     * Check if key exists in the container.
     *
     * Method returns 'true' if and only if a data was assigned with
     * a non-empty value.
     *
     * @param key                       Key
     *
     * @return                          True if parameter was set and has
     *                                  non-empty value, false otherwise.
     */
    bool HasValue(const String & key) const;

    /**
     * Check if extra data value is set.
     *
     * Method returns 'true' if there is a record for the key, even if its
     * value is empty.
     *
     * @param key                       Key
     *
     * @return                          True if parameter was set and has
     *                                  non-empty value, false otherwise.
     */
    bool FindValue(const String & key) const;

    /**
     * Return all keys available in the container.
     *
     * If container is empty, argument value is cleared.
     *
     * @param keys                      Vector of keys available in the
     *                                  container
     */
    void GetKeys(std::vector<String> & keys) const;

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param dictionary                String dictionary
     */

    void Merge(const StringDictionary & dictionary);

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no data in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear container data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator() override;
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        // Empty string if cannot resolve
        String GetKey() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class StringDictionary;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    operator types::DictionaryRef() const;
    types::DictionaryRef get_impl() const;
    bool update(types::Dictionary & value);

protected:
    StringDictionary(tbricks::types::DictionaryRef && value) noexcept;

private:
    void * m_ext_data;
    size_t m_ext_size;
    bool m_allocated;
    bool m_update;
};
}
