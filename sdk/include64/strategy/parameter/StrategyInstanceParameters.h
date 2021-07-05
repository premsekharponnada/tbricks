#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Local strategy instance parameters container.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/Variant.h"
#include "strategy/parameter/StrategyParameters.h"

// \namespace tbricks
namespace tbricks {

namespace protocol {
class StrategyInstance;
class ParameterDefinition;
}
namespace util {
class Buffer;
}

class ParameterDefinition;
class ParameterImpl;

/**
 * StrategyInstanceParameters provide read/write access to a local strategy
 * parameter container. Because every alteration of the container may result in
 * a network traffic, this container is somewhat limited if compared to its
 * mutable counterpart -- massive alterations like Clear(), Swap() and such are
 * not allowed here.
 *
 * @see Strategy
 */
class STRATEGY_EXPORT StrategyInstanceParameters : public Printable
{
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
    bool SetParameter(const ParameterDefinition & definition, const AnyType & value);

    bool SetParameter(const ParameterDefinition & definition, const Variant & value);

    /**
     * Check if container has a non-empty value for the key.
     *
     * Method returns 'true' if value is found, 'false' otherwise.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const ParameterDefinition & definition) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

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
     * Get tbricks::StrategyParameters&.
     *
     * Method allows to use StrategyInstanceParameters as StrategyParameters
     * container where possible -- that is, where massive data alteration
     * is not allowed, which is particularly true for constant objects.
     *
     * @return                          Current container state
     */
    void Get(StrategyParameters & parameters) const;

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator
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
        const ParameterDefinition & GetDefinition() const;
        bool Get(AnyType & value) const;
        bool IsValueEmpty() const;
        const AnyType & Get() const;

        friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, const const_iterator & it);
        std::ostream & Print(std::ostream & strm) const;
        String ToString() const;

    private:
        friend class StrategyInstanceParameters;
        void init(const StrategyInstanceParameters * m_owner, size_t pos);

    private:
        const StrategyInstanceParameters * m_owner;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

    friend class const_iterator;

public:
    void update(protocol::StrategyInstance & partial_si, util::Buffer & persist_data, bool & need_to_update, bool & need_to_persist);

    void init(const std::vector<std::shared_ptr<protocol::ParameterDefinition>> & definitions);

    ParameterImpl * add(const TypeInfo & type, const ParameterDefinition & definition);

protected:
    StrategyInstanceParameters();
    ~StrategyInstanceParameters();

private:
    void set_updated();

    friend class ParameterImpl;
    friend class AppEventHandler;

private:
    // copying prohibited
    StrategyInstanceParameters(const StrategyInstanceParameters &);
    StrategyInstanceParameters & operator=(const StrategyInstanceParameters &);

private:
    class Impl;
    Impl * m_impl;
};

} // \namespace tbricks
