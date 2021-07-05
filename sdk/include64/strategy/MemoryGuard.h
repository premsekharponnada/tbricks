#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Memory handler
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Integer.h"

namespace tbricks {

/**
 * Memory handler
 */
class STRATEGY_EXPORT MemoryHandler : public Printable
{
public:
    struct STRATEGY_EXPORT Bytes : public Printable
    {
        Bytes(const Integer & bytes);

        virtual std::ostream & Print(std::ostream & strm) const;

        Integer m_bytes;
    };

public:
    MemoryHandler();
    MemoryHandler(const MemoryHandler & handler);
    MemoryHandler & operator=(const MemoryHandler & handler);
    virtual ~MemoryHandler();

public:
    Bytes GetMemoryInUse() const;
    Bytes GetMemoryTotal() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class MemoryGuard;

private:
    class MemoryHandlerImpl;
    MemoryHandlerImpl * m_impl;
};

/**
 * Memory guard
 */
class STRATEGY_EXPORT MemoryGuard
{
public:
    MemoryGuard(MemoryHandler & handler);
    virtual ~MemoryGuard();

private:
    MemoryGuard(const MemoryGuard & guard);
    MemoryGuard & operator=(const MemoryGuard & guard);

private:
    class MemoryGuardImpl;
    MemoryGuardImpl * m_impl;
};
}
