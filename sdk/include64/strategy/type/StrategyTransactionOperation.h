#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy transaction operation type.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

/**
 * Strategy transaction operation.
 *
 * When a strategy is in transaction, transaction operation field identifies
 * what kind of operations the strategy performs.
 *
 * Note that it is purely strategy developer's task to set this
 * field appropriately.
 *
 * @see TransactionState
 */
class STRATEGY_EXPORT StrategyTransactionOperation : public AnyType
{
public:
    enum OperationValue
    {
        NONE = 0,
        STRATEGY_ADD = 1,
        STRATEGY_MODIFY = 2,
        STRATEGY_DELETE = 3,
        STRATEGY_PAUSE = 4,
        STRATEGY_RUN = 5
    };

public:
    StrategyTransactionOperation();
    StrategyTransactionOperation(OperationValue value);
    StrategyTransactionOperation(const StrategyTransactionOperation & value);

    StrategyTransactionOperation & operator=(OperationValue value);
    StrategyTransactionOperation & operator=(const StrategyTransactionOperation & value);

    bool Empty() const override { return m_value == NONE; }
    void Clear();
    OperationValue Get() const;

    bool IsAdd() const;
    bool IsModify() const;
    bool IsDelete() const;
    bool IsPause() const;
    bool IsRun() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator OperationValue() const { return Get(); }

public:
    bool operator==(OperationValue value) const;
    bool operator!=(OperationValue value) const;

    bool operator==(const StrategyTransactionOperation & value) const;
    bool operator!=(const StrategyTransactionOperation & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    OperationValue m_value;
};

STRATEGY_EXPORT
bool operator==(StrategyTransactionOperation::OperationValue v1, const StrategyTransactionOperation & v2);

STRATEGY_EXPORT
bool operator!=(StrategyTransactionOperation::OperationValue v1, const StrategyTransactionOperation & v2);

} // \namespace tbricks
