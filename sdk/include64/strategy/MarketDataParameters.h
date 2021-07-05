#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Market data parameters container
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"

#include "strategy/MarketDataParameterDefinition.h"

namespace tbricks {

/** @cond PRIVATE */
namespace types {
class Parameters;
}
/** @endcond */

/**
 * MarketDataParameters class
 */
class STRATEGY_EXPORT MarketDataParameters : public Printable
{
public:
    MarketDataParameters();
    MarketDataParameters(const MarketDataParameters & parameters);
    MarketDataParameters(MarketDataParameters && parameters) noexcept;
    ~MarketDataParameters();

    MarketDataParameters & operator=(const MarketDataParameters & parameters);
    MarketDataParameters & operator=(MarketDataParameters && parameters) noexcept;

    bool operator==(const MarketDataParameters & parameters) const;
    bool operator!=(const MarketDataParameters & parameters) const { return !operator==(parameters); }

    /**
     * Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const MarketDataParameterDefinition & definition, AnyType & value) const;

    /**
     * Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const Uuid & identifier, AnyType & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const MarketDataParameterDefinition & definition, const AnyType & value);

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
    bool HasParameter(const MarketDataParameterDefinition & definition) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear parameters.
     */
    void Clear();

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const MarketDataParameters & parameters);

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
        MarketDataParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        friend class MarketDataParameters;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    /**
     * @returns An iterator to the beginning of the MarketDataParameters container.
     */
    const_iterator begin() const;

    /**
     * @return An iterator to the end of the MarketDataParameters container.
     */
    const_iterator end() const;

    // private:
    MarketDataParameters(types::Parameters && parameters);
    MarketDataParameters(const types::Parameters & parameters);
    types::Parameters & impl() const;

private:
    std::unique_ptr<types::Parameters> m_parameters;
};
}
