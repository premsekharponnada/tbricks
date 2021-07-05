#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Calculated properties container
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"
#include "strategy/calculated_property/CalculatedPropertyDefinition.h"

namespace tbricks {
namespace protocol {
class IMessage;
}

class STRATEGY_EXPORT CalculatedPropertiesDictionary : public Printable
{
public:
    CalculatedPropertiesDictionary();
    CalculatedPropertiesDictionary(const CalculatedPropertiesDictionary & parameters);
    CalculatedPropertiesDictionary(CalculatedPropertiesDictionary && parameters) noexcept;
    ~CalculatedPropertiesDictionary();

    CalculatedPropertiesDictionary & operator=(const CalculatedPropertiesDictionary & parameters);
    CalculatedPropertiesDictionary & operator=(CalculatedPropertiesDictionary && parameters) noexcept;

    bool operator==(const CalculatedPropertiesDictionary & parameters) const;
    bool operator!=(const CalculatedPropertiesDictionary & parameters) const { return !operator==(parameters); }

    /** Fetch calculated property value from the container.
     *
     * @param definition                Calculated property definition, used as a key to
     *                                  the container
     * @param value                     Variable to store calculated property value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetCalculatedProperty(const CalculatedPropertyDefinition & definition, AnyType & value) const;

    /**
     * Store calculated property value in the container.
     *
     * @param definition                Calculated property definition, used as a key to
     *                                  the container
     * @param value                     Variable to store calculated property value
     */
    void SetCalculatedProperty(const CalculatedPropertyDefinition & definition, const AnyType & value);

    /**
     * Check if container has a value for the key.
     *
     * Method returns 'true' if only if container has a value for the
     * provided calculated property definition.
     *
     * @param definition                Calculated property definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasCalculatedProperty(const CalculatedPropertyDefinition & definition) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;
    void Clear();

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const CalculatedPropertiesDictionary & parameters);

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator();
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        CalculatedPropertyDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class CalculatedPropertiesDictionary;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    class Impl;
    const Impl & impl() const { return *m_calculated_properties; }
    Impl & impl() { return *m_calculated_properties; }
    void get_reference(strategy::DataRef & ref) const;

    void init_calculated_properties(unsigned char * data, size_t size, const std::shared_ptr<protocol::IMessage> & msg);

private:
    std::unique_ptr<Impl> m_calculated_properties;
};

} // \namespace tbricks
