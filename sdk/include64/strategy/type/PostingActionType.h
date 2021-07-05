#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Posting action.
//****************************************************************************************

#include "strategy/type/AnyType.h"

// \namespace tbricks
namespace tbricks {

class STRATEGY_EXPORT PostingActionType : public AnyType
{
public:
    enum ActionValue
    {
        UNDEFINED = 0,
        OPEN = 1,
        CLOSE = 2
    };

public:
    PostingActionType();
    PostingActionType(ActionValue value);
    PostingActionType(const PostingActionType & value);

    PostingActionType & operator=(ActionValue value);
    PostingActionType & operator=(const PostingActionType & value);

    bool Empty() const override { return m_value == UNDEFINED; }
    void Clear();
    ActionValue Get() const;

    bool IsOpen() const;
    bool IsClose() const;

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_ENUM; }

    operator ActionValue() const { return Get(); }

public:
    bool operator==(ActionValue value) const;
    bool operator!=(ActionValue value) const;

    bool operator==(const PostingActionType & value) const;
    bool operator!=(const PostingActionType & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    ActionValue m_value;
};

STRATEGY_EXPORT
bool operator==(PostingActionType::ActionValue v1, const PostingActionType & v2);

STRATEGY_EXPORT
bool operator!=(PostingActionType::ActionValue v1, const PostingActionType & v2);

} // \namespace tbricks
