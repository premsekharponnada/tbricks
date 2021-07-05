#pragma once

//*****************************************************************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2017 Itiviti Group AB. Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights
// reserved.
//
// External view model public interface.
//
//*****************************************************************************************************************************

#include "strategy/Linkage.h"

#include <memory>

namespace tbricks {

class Uuid;
class StrategyIdentifier;

namespace visualization {

class STRATEGY_EXPORT ExternalViewModel
{
public:
    Uuid GetViewModelIdentifier() const;
    StrategyIdentifier GetStrategyIdentifier() const;

private:
    friend class StrategyViewModelListener;
    ExternalViewModel(const std::pair<uint64_t, uint64_t> & view_id, const std::pair<uint64_t, uint64_t> & app_id);

private:
    std::pair<uint64_t, uint64_t> m_view_id;
    std::pair<uint64_t, uint64_t> m_app_id;
};
}
}
