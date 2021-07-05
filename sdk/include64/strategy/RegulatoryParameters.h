#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Regulatory parameters container
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"

#include "strategy/RegulatoryParameterDefinition.h"

namespace tbricks {

namespace types {
class Parameters;
}

/**
 * RegulatoryParameters parameters class
 */
class STRATEGY_EXPORT RegulatoryParameters : public Printable
{
public:
    RegulatoryParameters();
    RegulatoryParameters(const RegulatoryParameters & parameters);
    RegulatoryParameters(RegulatoryParameters && parameters) noexcept;
    ~RegulatoryParameters();

    RegulatoryParameters & operator=(const RegulatoryParameters & parameters);
    RegulatoryParameters & operator=(RegulatoryParameters && parameters) noexcept;

    bool operator==(const RegulatoryParameters & parameters) const;
    bool operator!=(const RegulatoryParameters & parameters) const { return !operator==(parameters); }

    /* Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const RegulatoryParameterDefinition & definition, AnyType & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const RegulatoryParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a value for the key.
     *
     * Method returns 'true' if only if container has a value for the
     * provided parameter definition.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const RegulatoryParameterDefinition & definition) const;

    /**
     * Extract parameter value from the parameter container.
     *
     * Method stores parameter value (if any exists in the container) in the
     * variable provided as a second argument and removes the parameter from
     * the container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool ExtractParameter(const RegulatoryParameterDefinition & definition, AnyType & value);

    /**
     * Remove parameter value from the container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     */
    void RemoveParameter(const RegulatoryParameterDefinition & definition);

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
    void Merge(const RegulatoryParameters & parameters);

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

        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        RegulatoryParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class RegulatoryParameters;
        void init(const void * data, size_t size, size_t pos = 0);

        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

    RegulatoryParameters(const types::Parameters & value);
    RegulatoryParameters(types::Parameters && value);
    const types::Parameters & get_impl() const;
    types::Parameters & get_impl();

private:
    std::unique_ptr<types::Parameters> m_impl;
};
}
