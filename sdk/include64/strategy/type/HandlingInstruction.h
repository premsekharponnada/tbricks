#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// HandlingInstruction
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT HandlingInstruction : public AnyType
{
public:
    enum HandlingInstructionValue
    {
        None = 0,
        AutomatedExecution = 1,
        AutomatedInterventionOK = 2,
        Manual = 3
    };

public:
    HandlingInstruction();
    HandlingInstruction(HandlingInstructionValue value);
    HandlingInstruction(const HandlingInstruction & value);

    HandlingInstruction & operator=(HandlingInstructionValue value);
    HandlingInstruction & operator=(const HandlingInstruction & value);

    bool Empty() const override { return m_value == None; }
    void Clear();
    HandlingInstructionValue Get() const;

    bool IsAutomatedExecution() const;
    bool IsAutomatedInterventionOK() const;
    bool IsManual() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator HandlingInstructionValue() const { return Get(); }

public:
    bool operator==(HandlingInstructionValue value) const;
    bool operator!=(HandlingInstructionValue value) const;

    bool operator==(const HandlingInstruction & value) const;
    bool operator!=(const HandlingInstruction & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    HandlingInstructionValue m_value;
};

STRATEGY_EXPORT
bool operator==(HandlingInstruction::HandlingInstructionValue v1, const HandlingInstruction & v2);

STRATEGY_EXPORT
bool operator!=(HandlingInstruction::HandlingInstructionValue v1, const HandlingInstruction & v2);

} // \namespace tbricks
