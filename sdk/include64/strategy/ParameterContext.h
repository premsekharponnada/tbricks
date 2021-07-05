#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter context.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/SafePointer.h"

#include "strategy/Types.h"
#include "strategy/Value.h"

#include <memory>

namespace tbricks {

namespace protocol {
class ParameterContext;
}

class STRATEGY_EXPORT ParameterContext : public Printable
{
public:
    ParameterContext() = default;
    ParameterContext(const Identifier & id);

    bool Resolve(const Identifier & id);

    Identifier GetIdentifier() const;
    String GetName() const;
    String GetDescription() const;
    bool Deleted() const;

    // returns all parameter contexts
    static void GetAllContexts(std::vector<ParameterContext> & contexts);

public:
    bool Empty() const;
    void Clear();

    virtual std::ostream & Print(std::ostream & ostrm) const;

private:
    ParameterContext(std::shared_ptr<protocol::ParameterContext> && context);

private:
    std::shared_ptr<protocol::ParameterContext> m_context;
};
}
