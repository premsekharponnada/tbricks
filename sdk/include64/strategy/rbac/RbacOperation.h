#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// RbacOperation
//****************************************************************************************

#include "strategy/type/Identifier.h"
#include "strategy/Linkage.h"
#include "strategy/Printable.h"

namespace tbricks {

class STRATEGY_EXPORT RbacOperation : public Printable
{
public:
    RbacOperation();
    RbacOperation(const RbacOperation & operation);
    RbacOperation(const Identifier & id);
    RbacOperation(const Identifier & id, const String & name, const String & description);
    virtual ~RbacOperation();

    RbacOperation & operator=(const RbacOperation & operation);

    bool Resolve(const Identifier & id);

    bool Empty() const;

    Identifier GetIdentifier() const;
    String GetName() const;
    String GetDescription() const;

    size_t GetHash() const;
    virtual std::ostream & Print(std::ostream & strm) const;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] static RbacOperation AssignTradingLimits() { return ManageLimitSettings(); }

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] static RbacOperation ViewLimits() { return ViewLimitSettings(); }
    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] static RbacOperation ManageLimits() { return ManageLimitSettings(); }

    static RbacOperation ViewTrade();
    static RbacOperation ModifyTrade();
    static RbacOperation ManagePortfolio();
    static RbacOperation ManagePlugin();
    static RbacOperation ViewOrder();
    static RbacOperation ViewPlugin();
    static RbacOperation ViewPortfolio();
    static RbacOperation ViewMarketData();
    static RbacOperation ViewMarketOrderBook();
    static RbacOperation ManageUsersAndRoles();
    static RbacOperation UpdateSystemMetadata();
    static RbacOperation ManageInstrument();
    static RbacOperation ManageInstrumentParameter();
    static RbacOperation ManageGroupParameter();
    static RbacOperation PerformEmergencyStop();
    static RbacOperation ViewTree();
    static RbacOperation ManageTree();
    static RbacOperation ViewAlert();
    static RbacOperation ManageAlert();
    static RbacOperation ViewTradingBlock();
    static RbacOperation ManageTradingBlock();
    static RbacOperation ViewLimitSettings();
    static RbacOperation ManageLimitSettings();
    static RbacOperation SendMassCancel();

private:
    Identifier m_identifier;
    String m_name;
    String m_description;
};

inline size_t hash_value(const RbacOperation & value)
{
    return value.GetHash();
}
}
