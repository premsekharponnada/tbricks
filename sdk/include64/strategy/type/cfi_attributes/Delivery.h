#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CFI attribute: Delivery.
// This is an automated-generated file. Please do not edit it manually.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/CFI.h"

namespace tbricks {

class STRATEGY_EXPORT CFI::Delivery : public Printable
{
public:
    enum DeliveryAttribute
    {
        Cash = 'C',
        Physical = 'P',
        Unknown = 'X'
    };

public:
    Delivery();
    Delivery(const Delivery & value);
    Delivery(const DeliveryAttribute & value);
    Delivery(const char & value);

    Delivery & operator=(const Delivery & value);
    Delivery & operator=(const DeliveryAttribute & value);
    Delivery & operator=(const char & value);

    bool operator==(const Delivery & value);
    bool operator==(const DeliveryAttribute & value);
    bool operator==(const char & value);

    const DeliveryAttribute & Get() const;

    operator const DeliveryAttribute &() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    DeliveryAttribute m_value;
};

} // namespace tbricks {
