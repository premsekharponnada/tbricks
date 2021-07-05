#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StackTrace
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/String.h"

#include <vector>

namespace tbricks {

class STRATEGY_EXPORT StackTrace : public Printable
{
public:
    StackTrace();
    StackTrace(const StackTrace & bt);
    StackTrace & operator=(const StackTrace & bt);

    const std::vector<String> & Get() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    std::vector<String> m_stacktrace;
};
}
