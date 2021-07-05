#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntry class
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/ServiceIdentifier.h"

#include "strategy_generated/LogEntryBase.h"

namespace tbricks {

//****************************************************************************
// LogEntry class
//****************************************************************************

/**
 * LogEntry class.
 */
class STRATEGY_EXPORT LogEntry : public LogEntryBase
{
public:
    class Stream;

public:
    LogEntry() = default;
    LogEntry(std::shared_ptr<protocol::LogEntry> && value) : LogEntryBase(std::move(value)) {}
};
}
