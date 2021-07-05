#pragma once

//******************************************************************************
// Tbricks Strategy Framework
//
// Copyright (c) 2018 Tbricks AB
//
// FIX MessageBuilder
// UNDER DEVELOPMENT. PLEASE, DON'T USE
//
//******************************************************************************

#include "strategy/fix/Enums.h"

namespace tbricks {
namespace fix {
class MessageBuilder;
}
class Boolean;
class Currency;
class Date;
class DateTime;
class Double;
class Identifier;
class Integer;
class MIC;
class Price;
class Side;
class StrategyIdentifier;
class String;
class Time;
class Uuid;
class Volume;
}

namespace tbricks { namespace FIX {

class Session;
class Message;

class STRATEGY_EXPORT MessageBuilder
{
    friend class Session;

public:
    MessageBuilder(const MessageBuilder &);
    ~MessageBuilder();

public:
    bool Empty() const;

    bool SetField(unsigned int id, const Boolean & v);
    bool SetField(unsigned int id, const Currency & v);
    bool SetField(unsigned int id, const Date & v);
    bool SetField(unsigned int id, const DateTime & v);
    bool SetField(unsigned int id, const Double & v);
    bool SetField(unsigned int id, const Price & v);
    bool SetField(unsigned int id, const Volume & v);
    bool SetField(unsigned int id, const Integer & v);
    bool SetField(unsigned int id, const String & v);
    bool SetField(unsigned int id, const Time & v);
    bool SetField(unsigned int id, const Uuid & v);
    bool SetField(unsigned int id, const Identifier & v);
    bool SetField(unsigned int id, const StrategyIdentifier & v);
    bool SetField(unsigned int id, const Side & v);
    bool SetField(unsigned int id, const MIC & v);

    bool SetField(unsigned int id, char v);
    bool SetField(unsigned int id, bool v);
    bool SetField(unsigned int id, const char * v);
    bool SetField(unsigned int id, int v);
    bool SetField(unsigned int id, size_t v);
    bool SetField(unsigned int id, double v);

    bool StartSequence(unsigned int id, size_t n);
    bool NextSequence();
    void EndSequence();
    Message EndMessage();

private:
    static int GetSideValue(const Side & side);

    MessageBuilder() = default;
    fix::MessageBuilder * get_data();
    void set_data(fix::MessageBuilder *);

private:
    fix::MessageBuilder * m_impl{nullptr};
};

}} // namespace FIX, namespace tbricks
