#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Limit settings parameters container
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"

namespace tbricks {

/** @cond PRIVATE */
namespace types {
class Parameters;
}
/** @endcond */

/**
 * LimitSettingsParameters class
 */
class STRATEGY_EXPORT LimitSettingsParameters : public Printable
{
public:
    LimitSettingsParameters();
    LimitSettingsParameters(const LimitSettingsParameters & conditions);
    LimitSettingsParameters(LimitSettingsParameters && conditions) noexcept;
    LimitSettingsParameters & operator=(const LimitSettingsParameters & conditions);
    LimitSettingsParameters & operator=(LimitSettingsParameters && conditions) noexcept;
    ~LimitSettingsParameters() override;

    /**
     * Equality operator
     *
     * @param filter_conditions         Filter conditions checked for equality with the current ones
     * @return                          True if compared filter conditions are equal, false otherwise
     */
    bool operator==(const LimitSettingsParameters & filter_conditions) const;

    /**
     * Inequality operator
     *
     * @param filter_conditions         Filter conditions checked for inequality with the current ones
     * @return                          True if compared filter conditions are not equal, false otherwise
     */
    bool operator!=(const LimitSettingsParameters & filter_conditions) const;

    /**
     * Get limit filter conditions hash
     *
     * @return                          Hash for limit filter conditions
     */
    size_t GetHash() const;

public:
    /**
     * Check if a particular filter condition exists
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    bool HasParameter(const ParameterDefinition & definition) const;

    /**
     * Fetch a particular limit filter condition
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Result
     *
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Set particular limit filter condition
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Limit filter condition value
     */
    void SetParameter(const ParameterDefinition & definition, const AnyType & value);

public:
    /**
     * LimitSettings::LimitSettingsParameters::const_iterator, helper class
     * providing the ability to iterate over the filter conditions.
     */
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        /**
         * Default constructor, creates an empty object
         */
        const_iterator();

        /**
         * Copy constructor
         */
        const_iterator(const const_iterator & it);

        /**
         * Copy assignment
         */
        const_iterator & operator=(const const_iterator & it);

        /**
         * Destructor
         */
        ~const_iterator() override;

        /**
         * Equality operator
         *
         * @param it                    Iterator checked for equality with the current one
         * @return                      True if compared iterators are equal, false otherwise
         */
        bool operator==(const const_iterator & it) const;

        /**
         * Inequality operator
         *
         * @param it                    Iterator checked for inequality with the current one
         * @return                      True if compared iterators are not equal, false otherwise
         */
        bool operator!=(const const_iterator & it) const;

        /**
         * Prefix increment operator
         */
        const_iterator & operator++();

        /**
         * Postfix increment operator
         */
        const_iterator operator++(int);

        /**
         * Dereferencing operator - returns the iterator itself, is required for range based for
         */
        const_iterator & operator*();

        /**
         * Clear the iterator i.e. reset it to empty state
         */
        void Clear();

        /**
         * Check the iterator for emptiness
         *
         * @return                      True if iterator is empty i.e. doesn't point anywhere, false otherwise
         */
        bool Empty() const;

    public:
        /**
         * Get limit filter condition definition
         *
         * @return                      Limit filter condition definition, empty if the definition cannot be resolved
         */
        ParameterDefinition GetDefinition() const;

        /**
         * Get limit filter condition value
         *
         * @param value                 Result
         * @return                      True if limit filter condition value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(AnyType & value) const;

        /**
         * Get limit filter condition value
         *
         * @param value                 Result
         * @return                      True if limit filter condition value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(Variant & value) const;

        /**
         * Print limit filter conditions iterator to the output stream
         *
         * @param                           Output stream
         */
        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class LimitSettingsParameters;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    /**
     * Get begin iterator for limit filter conditions
     *
     * @return                          Begin iterator for limit filter conditions
     */
    const_iterator begin() const;

    /**
     * Get end iterator for limit filter conditions
     *
     * @return                          End iterator for limit filter conditions
     */
    const_iterator end() const;

public:
    /**
     * Check limit filter conditions for emptiness
     *
     * @return                          True if limit filter conditions are empty, false otherwise
     */
    bool Empty() const;

    /**
     * Clear all contents from limit filter conditions i.e. reset them to the same state as the one right after calling
     * the default constructor
     */
    void Clear();

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const LimitSettingsParameters & parameters);

public:
    /**
     * Print limit filter conditions to the output stream
     *
     * @param                           Output stream
     */
    std::ostream & Print(std::ostream & strm) const override;

public:
    /** @cond PRIVATE */
    LimitSettingsParameters(const types::Parameters & parameters);
    LimitSettingsParameters(types::Parameters && parameters);
    types::Parameters & impl() const;
    /** @endcond */

private:
    std::unique_ptr<types::Parameters> m_parameters;
};

inline size_t hash_value(const LimitSettingsParameters & value)
{
    return value.GetHash();
}
}
