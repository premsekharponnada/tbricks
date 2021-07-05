#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy transaction state type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

/**
 * Strategy transaction state.
 *
 * When strategy starts an operation it is said to be in transaction; for
 * instance, to pause a strategy could mean to delete a child strategy,
 * which is a (potentially) remote operation and operation result will not
 * be available immediately -- in this case, strategy should set its
 * transaction state to "Pending", and when operation is finished, state
 * should be set to "Ok" or "Failed", depending on operation result.
 *
 * It is important to understand that it is fully user responsibility to
 * update transaction state accordingly depending on operation progress.
 */
class STRATEGY_EXPORT TransactionState : public AnyType
{
public:
    enum StateValue
    {
        NONE = 0,
        PENDING = 1,
        OK = 2,
        FAIL = 3
    };

public:
    TransactionState();
    TransactionState(StateValue value);
    TransactionState(const TransactionState & value);

    TransactionState & operator=(StateValue value);
    TransactionState & operator=(const TransactionState & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    StateValue Get() const;

    bool IsPending() const;
    bool IsOk() const;
    bool IsFail() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator StateValue() const { return Get(); }

public:
    bool operator==(StateValue value) const;
    bool operator!=(StateValue value) const;

    bool operator==(const TransactionState & value) const;
    bool operator!=(const TransactionState & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    StateValue m_value;
};

STRATEGY_EXPORT
bool operator==(TransactionState::StateValue v1, const TransactionState & v2);

STRATEGY_EXPORT
bool operator!=(TransactionState::StateValue v1, const TransactionState & v2);

} // \namespace tbricks
