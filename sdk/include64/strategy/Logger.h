#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Logger object.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/String.h"

#define TBLOG_BASE(level, msg)                                                                \
    do {                                                                                      \
        if (TB_UNLIKELY(::tbricks::Logger::IsActive(::tbricks::Logger::level))) {             \
            ::tbricks::LogMessage __tb_log_msg(::tbricks::Logger::level, __FILE__, __LINE__); \
            __tb_log_msg.GetStream() << msg;                                                  \
            __tb_log_msg.Send();                                                              \
        }                                                                                     \
    } while (0)

#define TBERROR(msg) TBLOG_BASE(LEVEL_ERROR, msg)
#define TBWARNING(msg) TBLOG_BASE(LEVEL_WARNING, msg)
#define TBNOTICE(msg) TBLOG_BASE(LEVEL_NOTICE, msg)
#define TBSTATUS(msg) TBLOG_BASE(LEVEL_STATUS, msg)
#define TBDEBUG(msg) TBLOG_BASE(LEVEL_DEBUG, msg)
#define TBDUMP(msg) TBLOG_BASE(LEVEL_DUMP, msg)
#define TBFULLDUMP(msg) TBLOG_BASE(LEVEL_FULLDUMP, msg)

#define TBLOG_ACTION_BASE(level, msg, see, action)                                            \
    do {                                                                                      \
        if (::tbricks::Logger::IsActive(::tbricks::Logger::level)) {                          \
            ::tbricks::LogMessage __tb_log_msg(::tbricks::Logger::level, __FILE__, __LINE__); \
            __tb_log_msg.GetStream() << msg;                                                  \
            __tb_log_msg.SetSee(see);                                                         \
            __tb_log_msg.SetAction(action);                                                   \
            __tb_log_msg.Send();                                                              \
        }                                                                                     \
    } while (0)

#define TBERROR_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_ERROR, msg, see, action)
#define TBWARNING_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_WARNING, msg, see, action)
#define TBNOTICE_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_NOTICE, msg, see, action)
#define TBSTATUS_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_STATUS, msg, see, action)
#define TBDEBUG_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_DEBUG, msg, see, action)
#define TBDUMP_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_DUMP, msg, see, action)
#define TBFULLDUMP_ACTION(msg, see, action) TBLOG_ACTION_BASE(LEVEL_FULLDUMP, msg, see, action)
// \namespace tbricks
namespace tbricks {

/// This is experimental implementation.
/// The interface is subject to change
class STRATEGY_EXPORT Logger
{
public:
    enum Level
    {
        LEVEL_CRITICAL = 0,
        LEVEL_ERROR = 1,
        LEVEL_WARNING = 2,
        LEVEL_NOTICE = 3,
        LEVEL_STATUS = 4,
        LEVEL_DEBUG = 5,
        LEVEL_DUMP = 6,
        LEVEL_FULLDUMP = 7
    };

public:
    static bool IsActive(Level level);

    friend STRATEGY_EXPORT std::ostream & operator<<(std::ostream & strm, Logger::Level level)
    {
        switch (level) {
        case tbricks::Logger::LEVEL_CRITICAL:
            strm << "Critical";
            break;
        case tbricks::Logger::LEVEL_ERROR:
            strm << "Error";
            break;
        case tbricks::Logger::LEVEL_WARNING:
            strm << "Warning";
            break;
        case tbricks::Logger::LEVEL_NOTICE:
            strm << "Notice";
            break;
        case tbricks::Logger::LEVEL_STATUS:
            strm << "Status";
            break;
        case tbricks::Logger::LEVEL_DEBUG:
            strm << "Debug";
            break;
        case tbricks::Logger::LEVEL_DUMP:
            strm << "Dump";
            break;
        case tbricks::Logger::LEVEL_FULLDUMP:
            strm << "FullDump";
            break;
        default:
            strm << "Unknown";
            break;
        }
        return strm;
    }
};

namespace logging {
class Message;
}

/// Log message
class STRATEGY_EXPORT LogMessage : public Printable
{
public:
    LogMessage(Logger::Level level, const char * file, int line);

    ~LogMessage();

    std::ostream & GetStream();

    void AddAttribute(const String & name, const AnyType & value);

    void SetSee(const String & see);
    void SetSee(const char * see);

    void SetTbricksInternalSee(const String & see);
    void SetTbricksInternalSee(const char * see);

    void SetAction(const String & action);
    void SetAction(const char * action);

    void Send();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    LogMessage(const LogMessage & log);
    LogMessage & operator=(const LogMessage & log);

private:
    logging::Message * m_log_msg;
};

} // \namespace tbricks
