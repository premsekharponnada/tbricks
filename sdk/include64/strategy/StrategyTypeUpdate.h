#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// StrategyTypeUpdate object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/StrategyType.h"

#include <memory>

namespace tbricks {

namespace protocol {
class Plugin;
}

class String;
class PluginType;
class StrategyIdentifier;
class Boolean;

class STRATEGY_EXPORT StrategyType::Update : public Printable
{
public:
    Update();
    ~Update() override;
    Update(const Update & strategyType);
    Update(Update && strategyType) noexcept;

    Update & operator=(const Update & strategyType);
    Update & operator=(Update && strategyType) noexcept;

public:
    bool Empty() const;

public:
    String GetName() const;
    bool HasName() const;

    String GetDescription() const;
    bool HasDescription() const;

    StrategyIdentifier GetIdentifier() const;
    bool HasIdentifier() const;

    PluginType GetClass() const;
    bool HasClass() const;

    Boolean GetDeleted() const;
    bool HasDeleted() const;

    AlgoType GetAlgoType() const;
    bool HasAlgoType() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

public:
    Update(std::shared_ptr<protocol::Plugin> update);

private:
    friend class StrategyType;
    std::shared_ptr<protocol::Plugin> m_msg;
};
}
