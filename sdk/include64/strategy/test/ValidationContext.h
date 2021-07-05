#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy validation API.
// ValidationContext wrapper is using for app tests.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Parameters.h"
#include "strategy/validation/ValidationItem.h"
#include "strategy/validation/ValidityValidationItem.h"

// \namespace tbricks
namespace tbricks {

namespace strategy {
class ValidationContextImpl;
}

namespace test {
class ValidationContext;

class STRATEGY_EXPORT ValidationItem : public tbricks::ValidationItem
{
public:
    virtual ~ValidationItem();

public:
    void SetIncrementCount(int count);

    ParameterDefinition::Direction GetDirection() const;
    void GetValidValues(std::vector<tbricks::Variant> & values);

private:
    ValidationItem() = delete;
    ValidationItem(const test::ValidationItem &) = delete;
    ValidationItem(const tbricks::ValidationItem & vi);
    ValidationItem & operator=(const ValidationItem &) = delete;
    friend class test::ValidationContext;
};

class STRATEGY_EXPORT ValidityValidationItem : public tbricks::ValidityValidationItem
{
public:
    virtual ~ValidityValidationItem();

public:
    const ValidityTypeSet & GetAllowedValidityTypes() const;

private:
    ValidityValidationItem() = delete;
    ValidityValidationItem(const test::ValidityValidationItem &) = delete;
    ValidityValidationItem(const tbricks::ValidityValidationItem & vvi);
    ValidityValidationItem & operator=(const ValidityValidationItem &) = delete;
    friend class test::ValidationContext;
};

/**
 * ValidationContext is like tbricks::ValidationContext but with
 * possibility to specify Validation Items.
 */
class STRATEGY_EXPORT ValidationContext : public Printable
{
public:
    ValidationContext();
    ~ValidationContext();

public:
    bool HasItem(const Parameter & parameter) const;
    bool HasItem(const ParameterDefinition & definition) const;

    test::ValidationItem & GetItem(const Parameter & parameter);
    test::ValidationItem & GetItem(const ParameterDefinition & definition);

    void RemoveItem(const Parameter & parameter);
    void RemoveItem(const ParameterDefinition & definition);
    void RemoveItem(const ValidationItem & item);

    test::ValidityValidationItem & GetValidityItem();

public:
    ValidationContext & operator=(const ValidationContext & vc);

    virtual std::ostream & Print(std::ostream & strm) const;

    bool Empty() const;

    strategy::ValidationContextImpl * get_impl() const;
    ValidationContext(const std::shared_ptr<strategy::ValidationContextImpl> & impl);

private:
    std::shared_ptr<strategy::ValidationContextImpl> m_impl;
    std::shared_ptr<test::ValidityValidationItem> m_validityItem;
    std::vector<std::shared_ptr<test::ValidationItem>> m_items;
};

} // \namespace test
} // \namespace tbricks
