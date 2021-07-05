#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// IVirtualService
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Types.h"

namespace tbricks { namespace test {
class VSBase;

class STRATEGY_EXPORT IVirtualService
{
public:
    explicit IVirtualService(const VSBase * impl, const ServiceIdentifier & id) : m_base_impl(impl), m_id(id){};
    virtual ~IVirtualService(){};

    const ServiceIdentifier & GetIdentifier() const { return m_id; }

    /**
     * Get size of pending updates queue.
     * Return summary size of all queries as default.
     *
     * @param update_type    Update type. UpdateTypeValue enumeration
     *                       is defined at specified virtual service
     *                       and can be used as an argument here.
     *
     * @return               Queue size.
     */
    int HasPendingUpdates(int update_type = 0);

private:
    const VSBase * m_base_impl;

protected:
    ServiceIdentifier m_id;
};

} // \namespace test

} // \namespace tbricks
