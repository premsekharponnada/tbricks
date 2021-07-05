#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Exception
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/StackTrace.h"

namespace tbricks {

class STRATEGY_EXPORT Exception : public Printable
{
public:
    Exception(const String & message);
    Exception(const Exception &) = default;

    ~Exception() override;

    const String & GetErrorMessage() const;
    const StackTrace & GetStackTrace() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    String m_message;
    StackTrace m_stacktrace;
};
}
