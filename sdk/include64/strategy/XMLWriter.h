#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Simple XML writer.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/type/Double.h"
#include "strategy/type/DateTime.h"

namespace tbricks {

namespace strategy {
class XMLWriterImpl;
}

class STRATEGY_EXPORT XMLWriter
{
public:
    XMLWriter();
    XMLWriter(const XMLWriter & writer);
    ~XMLWriter();

    XMLWriter & operator=(const XMLWriter & writer);

    void StartElement(const String & name);

    void AddAttribute(const String & name, const String & value);
    void AddAttribute(const String & name, const DateTime & value);

    void AddContent(const String & content);

    void EndElement();
    void EndDocument();

    void ToString(String & output) const;

protected:
    XMLWriter(strategy::XMLWriterImpl * writer);

private:
    strategy::XMLWriterImpl * m_writer;
};
}
