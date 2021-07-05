#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Exceptions
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Exception.h"
#include "strategy/type/Uuid.h"

namespace tbricks {

#define STRING_EXCEPTION(Name)                               \
    struct STRATEGY_EXPORT Name : public Exception           \
    {                                                        \
        Name(const String & message) : Exception(message) {} \
    };

STRING_EXCEPTION(MemberAccessException)
STRING_EXCEPTION(MissingFieldException)
STRING_EXCEPTION(InvalidCastException)
STRING_EXCEPTION(EmptyValueException)
STRING_EXCEPTION(NullReferenceException)
STRING_EXCEPTION(TypeMismatchException)
STRING_EXCEPTION(TypeInitializationException)
STRING_EXCEPTION(NotSupportedException)
STRING_EXCEPTION(InvalidTimeZoneException)
STRING_EXCEPTION(InvalidTimeOperationException)
STRING_EXCEPTION(InvalidDateOperationException)
STRING_EXCEPTION(BadTimeStringException)
STRING_EXCEPTION(BadDateException)
STRING_EXCEPTION(IndexOutOfBoundsException)
STRING_EXCEPTION(IOStreamException)
STRING_EXCEPTION(UnsupportedPriceFormatException)
STRING_EXCEPTION(EntityCircularDependencyException)
STRING_EXCEPTION(NotFoundException)
STRING_EXCEPTION(CallbackNotSetException)
STRING_EXCEPTION(BatchIsAlreadySetException)
STRING_EXCEPTION(RowIsPresentInGridParameterException)

/**
 * @deprecated Please use CallbackNotSetException instead of this class
 *             Deprecated in 2.13.0
 */
struct STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] CallbackDoesNotSetException
    : public Exception{CallbackDoesNotSetException(const String & message) : Exception(message){}};

struct STRATEGY_EXPORT TableInternalError : public Exception
{
    TableInternalError(String && error_msg) : Exception(error_msg) {}
    TableInternalError(Integer error_code) : Exception(String("Table exception code: " + error_code.ToString()).GetCString()) {}
    TableInternalError(Integer error_code, const String & descr) :
        Exception(String(descr + " Table exception code: " + error_code.ToString()).GetCString())
    {}
    TableInternalError(Integer error_code, const String & descr, const String & extra_info) :
        Exception(String(descr + " " + extra_info + " Table exception code: " + error_code.ToString()).GetCString())
    {}
};

struct STRATEGY_EXPORT InvalidParameterDefinitionException : public Exception
{
    InvalidParameterDefinitionException(const Uuid & id) : Exception(String("Strategy parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidInstrumentParameterDefinitionException : public Exception
{
    InvalidInstrumentParameterDefinitionException(const Uuid & id) :
        Exception(String("Instrument parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidInstrumentParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidInstrumentAttributeDefinitionException : public Exception
{
    InvalidInstrumentAttributeDefinitionException(const Uuid & id) :
        Exception(String("Instrument attribute " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidInstrumentAttributeDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidPortfolioParameterDefinitionException : public Exception
{
    InvalidPortfolioParameterDefinitionException(const Uuid & id) :
        Exception(String("Portfolio parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidPortfolioParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidUserParameterDefinitionException : public Exception
{
    InvalidUserParameterDefinitionException(const Uuid & id) : Exception(String("User parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidUserParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidAlertParameterDefinitionException : public Exception
{
    InvalidAlertParameterDefinitionException(const Uuid & id) : Exception(String("Alert parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidAlertParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidMarketDataParameterDefinitionException : public Exception
{
    InvalidMarketDataParameterDefinitionException(const Uuid & id) :
        Exception(String("Market data parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidMarketDataParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidTreeNodeParameterDefinitionException : public Exception
{
    InvalidTreeNodeParameterDefinitionException(const Uuid & id) :
        Exception(String("Tree node parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidTreeNodeParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidTradeParameterDefinitionException : public Exception
{
    InvalidTradeParameterDefinitionException(const Uuid & id) : Exception(String("Trade parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidTradeParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidInstrumentCalculatedValueDefinitionException : public Exception
{
    InvalidInstrumentCalculatedValueDefinitionException(const Uuid & id) :
        Exception(String("Instrument calculated value " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidInstrumentCalculatedValueDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidRegulatoryParameterDefinitionException : public Exception
{
    InvalidRegulatoryParameterDefinitionException(const Uuid & id) :
        Exception(String("Regulatory parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidRegulatoryParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidGridParameterDefinitionException : public Exception
{
    InvalidGridParameterDefinitionException(const Uuid & id) : Exception(String("Grid parameter " + id.ToString() + " does not exist").GetCString())
    {}
    InvalidGridParameterDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT InvalidExtraDataDefinitionException : public Exception
{
    InvalidExtraDataDefinitionException(const char * message) : Exception(message) {}
};

struct STRATEGY_EXPORT StreamNotOpenException : public Exception
{
    StreamNotOpenException(const Uuid & stream_id) : Exception("Stream " + stream_id.ToString() + " is not open") {}
};

struct STRATEGY_EXPORT NotMarketDataStreamException : public Exception
{
    NotMarketDataStreamException(const Uuid & stream_id) : Exception("Stream " + stream_id.ToString() + " is not market data stream") {}
};
}
