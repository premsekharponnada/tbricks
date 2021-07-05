#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CalculatedPropertyFilter
//****************************************************************************************

#include <optional>
#include "strategy/type/AnyType.h"
#include "strategy/type/Binary.h"
#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/stream_filter/Filter.h"
#include "strategy/stream_filter/FilterOperation.h"
#include "strategy/Value.h"

namespace tbricks {

namespace types {
class CalculatedPropertyFilter;
class CalculatedPropertyCondition;
}

/**
 * CalculatedPropertyFilter object allows filtering on specific CalculatedProperty values.
 * If not empty, filter contains either condition (in that case filter operation is MATCH)
 * or vector of child filters connected by logical AND/OR operation.
 */
class STRATEGY_EXPORT CalculatedPropertyFilter : public AnyType
{
public:
    enum class ConditionType
    {
        Base,
        String,
        Relative
    };

    /**
     * Base condition class that stores value of most common types.
     */
    class STRATEGY_EXPORT Condition
    {
    public:
        Condition();
        Condition(const CalculatedProperty & prop, const AnyType & value);
        Condition(const CalculatedProperty & prop, Filter::Relation relation, const AnyType & value);
        virtual ~Condition() = default;

        Condition(const Condition & c) = default;
        Condition(Condition && c) = default;
        Condition & operator=(const Condition & c) = default;
        Condition & operator=(Condition && c) = default;

        CalculatedPropertyFilter operator||(const CalculatedPropertyFilter & filter) const;
        CalculatedPropertyFilter operator&&(const CalculatedPropertyFilter & filter) const;
        CalculatedPropertyFilter operator||(const Condition & cond) const;
        CalculatedPropertyFilter operator&&(const Condition & cond) const;
        CalculatedPropertyFilter operator!() const;

        operator CalculatedPropertyFilter() const;

        /**
         * Get type of condition value.
         * @return                          Type of condition value.
         */
        TypeInfo GetValueType() const;

        /**
         * Get condition value.
         * @param value                     Must be of type that GetValueType() returns.
         */
        void GetValue(AnyType & value) const;

        /**
         * Get condition relation.
         * @return                          Condition relation or std::nullopt if relation is not specified.
         */
        std::optional<Filter::Relation> GetRelation() const;

        /**
         * Get calculated property.
         * @return                         Calculated property.
         */
        const CalculatedProperty & GetProperty() const;

    protected:
        friend class CalculatedPropertyFilter;
        virtual bool get_condition(types::CalculatedPropertyCondition & condition) const;
        virtual bool Decode(const types::CalculatedPropertyCondition & condition);

        CalculatedProperty m_property;
        Binary m_value;
        Value<Filter::Relation> m_relation;
    };

    /**
     * Condition type that stores values of text high level type.
     */
    class STRATEGY_EXPORT StringCondition : public Condition
    {
    public:
        enum class Relation
        {
            Equal = 0,
            StartsWith = 1,
            Contains = 2,
            EndsWith = 3,
            MatchesPattern = 4
        };

        StringCondition() = default;
        StringCondition(const CalculatedProperty & prop, Relation relation, bool case_sensitive, const String & value);
        StringCondition(const StringCondition & c) = default;
        StringCondition(StringCondition && c) = default;
        StringCondition & operator=(const StringCondition & c) = default;
        StringCondition & operator=(StringCondition && c) = default;
        ~StringCondition() = default;

        /**
         * Get specific string relation.
         * @return                          String relation of Relation::Equal if not specified.
         */
        Relation GetStringRelation() const { return m_string_relation; }

        /**
         * Indicates if condition depends on register.
         * @return                          Case sensitive value.
         */
        bool CaseSensitive() const { return m_case_sensitive; }

    private:
        bool Decode(const types::CalculatedPropertyCondition & condition) override;
        bool get_condition(types::CalculatedPropertyCondition & condition) const override;

        Relation m_string_relation{Relation::Equal};
        bool m_case_sensitive{false};
    };

    /**
     * Condition type that shows time passed from current moment.
     */
    class STRATEGY_EXPORT RelativeCondition : public Condition
    {
    public:
        enum class Type
        {
            InTheLast,
            InTheNext
        };

        RelativeCondition() = default;
        RelativeCondition(const CalculatedProperty & prop, const Duration & duration, Type type);
        RelativeCondition(const RelativeCondition & c) = default;
        RelativeCondition(RelativeCondition && c) = default;
        RelativeCondition & operator=(const RelativeCondition & c) = default;
        RelativeCondition & operator=(RelativeCondition && c) = default;
        ~RelativeCondition() = default;

        /**
         * Indicates if condition refers to future or past.
         * @return                          Relative type.
         */
        Type GetRelativeType() const { return m_type; }

    private:
        bool Decode(const types::CalculatedPropertyCondition & condition) override;
        bool get_condition(types::CalculatedPropertyCondition & condition) const override;

        Type m_type{Type::InTheLast};
    };

public:
    CalculatedPropertyFilter();
    explicit CalculatedPropertyFilter(const types::CalculatedPropertyFilter & filter);
    CalculatedPropertyFilter(const CalculatedPropertyFilter & other);
    CalculatedPropertyFilter(CalculatedPropertyFilter && other) noexcept;
    virtual ~CalculatedPropertyFilter();

    CalculatedPropertyFilter & operator=(const CalculatedPropertyFilter & filter);
    CalculatedPropertyFilter & operator=(CalculatedPropertyFilter && filter) noexcept;

    CalculatedPropertyFilter & operator|=(const CalculatedPropertyFilter & filter);
    CalculatedPropertyFilter & operator&=(const CalculatedPropertyFilter & filter);

    CalculatedPropertyFilter operator||(const CalculatedPropertyFilter & filter) const;
    CalculatedPropertyFilter operator&&(const CalculatedPropertyFilter & filter) const;
    CalculatedPropertyFilter operator!() const;

    bool operator<(const CalculatedPropertyFilter & other) const;
    bool operator>(const CalculatedPropertyFilter & other) const;
    bool operator==(const CalculatedPropertyFilter & other) const;
    bool operator!=(const CalculatedPropertyFilter & other) const;

    bool Empty() const override;
    void Clear();

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_CP_FILTER; }

    void Encode(types::CalculatedPropertyFilter & filter) const;

    class STRATEGY_EXPORT const_iterator
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & iterator);
        ~const_iterator();

        const_iterator & operator=(const const_iterator & iterator);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        CalculatedPropertyFilter operator*() const;

        CalculatedPropertyFilter GetFilter() const;

    private:
        friend class CalculatedPropertyFilter;
        const_iterator(const types::CalculatedPropertyFilter & filter, bool begin);

        class IteratorImpl;
        std::unique_ptr<IteratorImpl> m_impl;
    };

    const_iterator begin() const;
    const_iterator end() const;

    /**
     * Get filter operation type.
     * @return                          Filter operation.
     */
    FilterOperation GetOperation() const;

    /**
     * Get condition type.
     * @return                          Enumeration item corresponding to stored condition type
                                        or std::nullopt if filter contains no condition.
     */
    std::optional<ConditionType> GetConditionType() const;

    /**
     * Get condition.
     * @param condition                 Must be of type that GetConditionType() returns.
     * @return                          true if filter contains any condition and parameter has
                                        same type as stored condition, false otherwise.
     */
    bool GetCondition(Condition & condition) const;

protected:
    friend class Filter;
    types::CalculatedPropertyFilter & getImpl();

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    std::unique_ptr<types::CalculatedPropertyFilter> m_filter;
};
}
