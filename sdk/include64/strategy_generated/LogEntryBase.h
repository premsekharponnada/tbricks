#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// LogEntryBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DateTime;
class Integer;
class StrategyIdentifier;
class String;
enum class LogEntryLevel;


namespace protocol { class LogEntry; }

class STRATEGY_EXPORT LogEntryBase : public Printable
{
protected:
    LogEntryBase();
    LogEntryBase(const LogEntryBase & value);
    LogEntryBase(LogEntryBase && value) noexcept;
    LogEntryBase & operator=(const LogEntryBase & value);
    LogEntryBase & operator=(LogEntryBase && value) noexcept;
    virtual ~LogEntryBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDateTime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDateTime() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasFile() const;

    /**
     * Get log file.
     *
     *
     * @return                          log file
     */
    String GetFile() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLine() const;

    /**
     * Get log line.
     *
     *
     * @return                          log line
     */
    Integer GetLine() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLayer() const;

    /**
     * Get log layer.
     *
     *
     * @return                          log layer
     */
    String GetLayer() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMessage() const;

    /**
     * Get log message.
     *
     *
     * @return                          log message
     */
    String GetMessage() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHost() const;

    /**
     * Get host name.
     *
     *
     * @return                          host name
     */
    String GetHost() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasApplication() const;

    /**
     * Get log application name.
     *
     *
     * @return                          log application name
     */
    String GetApplication() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcess() const;

    /**
     * Get log process identifier.
     *
     *
     * @return                          log process identifier
     */
    Integer GetProcess() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLWP() const;

    /**
     * Get log lwp.
     *
     *
     * @return                          log lwp
     */
    Integer GetLWP() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasThreadIdentifier() const;

    /**
     * Get log thread identifier.
     *
     *
     * @return                          log thread identifier
     */
    Integer GetThreadIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasThreadName() const;

    /**
     * Get log thread name.
     *
     *
     * @return                          log thread name
     */
    String GetThreadName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLevel() const;

    /**
     * Get log level.
     *
     *
     * @return                          log level
     */
    std::optional<LogEntryLevel> GetLevel() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    LogEntryBase(const protocol::LogEntry & value);
    LogEntryBase(std::shared_ptr<protocol::LogEntry> && value);

    std::shared_ptr<protocol::LogEntry> & get_impl_wr() const;
    const std::shared_ptr<protocol::LogEntry> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::LogEntry> m_impl;
};

}
