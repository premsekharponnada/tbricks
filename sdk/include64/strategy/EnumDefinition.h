#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// EnumDefinition class.
//****************************************************************************************

#include <vector>
#include "strategy/type/String.h"
#include "strategy/type/Identifier.h"
#include "strategy/Printable.h"
#include "strategy/Linkage.h"

namespace tbricks {

namespace protocol {
class Enumeration;
class EnumerationItem;
}

/**
 * Information about a enumeration
 */
class STRATEGY_EXPORT EnumDefinition : public Printable
{
public:
    /**
     * Information about an enumeration item
     */
    class STRATEGY_EXPORT Item : public Printable
    {
    public:
        /**
         * Constructor
         *
         * Constructs new, empty EnumDefinition instance
         */
        Item();

        Item(const Item & item);
        Item(Item && item) noexcept;
        ~Item();

        Item & operator=(const Item & item);
        Item & operator=(Item && item) noexcept;

    public:
        /**
         * Get enumeration item name.
         *
         * @return                          item name
         */
        const String & GetName() const;

        /**
         * Get enumeration item description.
         *
         * @return                          item description
         */
        const String & GetDescription() const;

        /**
         * Get enumeration item value.
         *
         * @return                          item value
         */
        int GetValue() const;

    public:
        virtual std::ostream & Print(std::ostream & strm) const override;

        /**
         * Check object for emptiness.
         *
         * @return                          True if there are no data in the
         *                                  object, false otherwise.
         */
        bool Empty() const;

        /**
         * Clear object.
         */
        void Clear();

    private:
        void Init(const protocol::EnumerationItem & item);
        friend class EnumDefinition;

    private:
        Integer m_value;
        String m_description;
        String m_name;
    };

public:
    /**
     * Constructor.
     *
     * Constructs new, empty EnumDefinition instance.
     */
    EnumDefinition();

    /**
     * Constructor.
     *
     * Creates new EnumDefinition instance with specified enumeration
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @param id                        Enumeration identifier
     */
    EnumDefinition(const Identifier & id);

    EnumDefinition(const EnumDefinition & ed);
    EnumDefinition(EnumDefinition && ed) noexcept;
    ~EnumDefinition();

    EnumDefinition & operator=(const EnumDefinition & ed);
    EnumDefinition & operator=(EnumDefinition && ed) noexcept;

public:
    /**
     * Get enumeration identifier.
     *
     * Returns system enumeration identifier the object is associated with.
     *
     * @return                          Enumeration identifier
     */
    const Identifier & GetIdentifier() const;

    /**
     * Get enumeration description.
     *
     * @return                          description
     */
    const String & GetDescription() const;

    /**
     * Get enumeration items
     *
     * @return                          Vector of enumeration items
     */
    const std::vector<EnumDefinition::Item> & GetItems() const;

    /**
     * Get enumeration item by value
     *
     * @section performance Medium - O(n) algorithm
     *
     * @return                          Item if found, empty item otherwise
     */
    Item GetItemByValue(int value) const;

    /**
     * Get enumeration item by name
     *
     * @section performance Medium - O(n) algorithm
     *
     * @return                          Item if found, empty item otherwise
     */
    Item GetItemByName(const String & name) const;

    /**
     * Check if enumeration has item with @value
     *
     * @section performance Medium - O(n) algorithm
     *
     * @return                          true if found, false otherwise
     */
    bool IsValidValue(int value) const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

    /**
     * Check object for emptiness.
     *
     * @return                          True if there are no data in the
     *                                  object, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear object.
     */
    void Clear();

public:
    /**
     * Resolve enumeration information.
     *
     * Synchronously fetches full of the enumeration
     * identified by the parameter.
     *
     * @param enum_id                   Enumeration identifier
     *
     * @return                          'true' if enumeration is available,
     *                                  'false' otherwise
     */
    bool Resolve(const Identifier & enum_id);

private:
    void Init(const protocol::Enumeration & enumeration);

private:
    Identifier m_identifier;
    String m_description;
    std::vector<EnumDefinition::Item> m_items;
};

} // namespace tbricks
