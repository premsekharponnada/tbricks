#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Abstract strategy parameter.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Uuid.h"

namespace tbricks {

namespace types {
class UUID;
class Parameters;
class StrategyInstance;
class ParametersRef;
}

namespace strategy {
struct DataRef;
}

class Parameter;
class ParameterDefinition;
class Variant;

/**
 * StrategyParameters class is a simple container of strategy parameters,
 * used at strategy create/modify time.
 *
 * @see CreateStrategy
 * @see Modify
 */
class STRATEGY_EXPORT StrategyParameters : public Printable
{
public:
    StrategyParameters() : m_alloc(true), m_data(nullptr), m_size(0), m_reserved_size(0) {}
    StrategyParameters(const StrategyParameters & parameters);
    StrategyParameters(StrategyParameters && parameters) noexcept;
    ~StrategyParameters() override;

    StrategyParameters & operator=(const StrategyParameters & parameters);
    StrategyParameters & operator=(StrategyParameters && parameters) noexcept;

    bool operator==(const StrategyParameters & parameters) const;
    bool operator!=(const StrategyParameters & parameters) const { return !operator==(parameters); }

    size_t GetHash() const;

public:
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
    bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

    bool GetParameter(const ParameterDefinition & definition, Variant & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const ParameterDefinition & definition, const AnyType & value);

    /**
     * @deprecated Deprecated in 2.14.6, use SetParameter() instead
     */
    [[deprecated(DEPRECATE_LINK)]] bool UpdateParameter(const ParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a non-empty value for the key.
     *
     * Method returns 'true' if and only if container has a value for the
     * provided parameter definition. The value could be checked for emptiness separately.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const ParameterDefinition & definition) const;

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
    bool ExtractParameter(const ParameterDefinition & definition, AnyType & value);

    /**
     * Remove parameter value from the container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     */
    void RemoveParameter(const ParameterDefinition & definition);

    /**
     * Get parameter value.
     *
     * @param a_parameter               Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(Parameter & a_parameter) const;

    /**
     * %Set parameter value.
     *
     * If parameter with such name already exists in the container, its value
     * is overriden.
     *
     * @param a_parameter               Variable to store parameter value
     */
    void SetParameter(const Parameter & a_parameter);

    /**
     * Check if parameter is set for the contaner.
     *
     * @param a_parameter               Parameter value
     *
     * @return                          True if parameter was set for this
     *                                  container, false otherwise.
     */
    bool HasParameter(const Parameter & a_parameter) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
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

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const StrategyParameters & parameters);

    /**
     * Merge a parameter value.
     *
     * Updates value of the parameter identified by the first argument in the
     * container.
     *
     * @param definition                Parameter definition
     * @param parameters                Parameter container
     */
    void Merge(const ParameterDefinition & definition, const StrategyParameters & parameters);

    /**
     * Swap parameters.
     *
     * Exchanges data of the current container with the data of the
     * argument, and vice versa.
     *
     * @param parameters                Parameter container
     */
    void Swap(StrategyParameters & parameters);

    void SetParameterIncrement(const ParameterDefinition & definition, int ticks);
    int GetParameterIncrement(const ParameterDefinition & definition) const;

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
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        ParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;
        bool Get(Parameter & value) const;

        int GetParameterIncrement() const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        friend class StrategyParameters;
        template <typename ValueT>
        friend class SimpleParameterImplT;
        template <typename ValueT, typename IncrementT>
        friend class IncrementParameterImplT;
        friend class TableParameter;

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

    const_iterator find(const ParameterDefinition & definition) const;

public:
    // internal encoding/decoding
    void steal_buffer(tbricks::types::Parameters & parameters);
    void set_reference(const strategy::DataRef & ref);
    void get_reference(strategy::DataRef & ref) const;
    bool get_parameter(const tbricks::types::UUID & id, AnyType & value) const;
    bool get_parameter(const ParameterDefinition & def, Variant & value) const;

    types::ParametersRef get_impl() const;
    StrategyParameters(const tbricks::types::Parameters & parameters);
    StrategyParameters(tbricks::types::Parameters && parameters);

private:
    friend class StrategyModifier;
    friend class StrategyAttributes;
    StrategyParameters(tbricks::types::ParametersRef && parameters);

private:
    friend class CalculatedProperty;

private:
    bool m_alloc;
    unsigned char * m_data;
    size_t m_size;
    size_t m_reserved_size;
};

inline size_t hash_value(const StrategyParameters & value)
{
    return value.GetHash();
}
}
