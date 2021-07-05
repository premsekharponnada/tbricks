#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualCalculationEngine is
// system virtual Plugin Engine.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/PluginOptions.h"
#include "strategy/test/IVirtualService.h"
#include "strategy/ServiceStatus.h"

namespace tbricks { namespace test {
class PEImpl;

class STRATEGY_EXPORT VirtualPluginEngine : public IVirtualService
{
public:
    /**
     * Get type of plugin engine.
     *
     * @return           Engine type;
     */
    /// @deprecated Deprecated in 2.14.3 use GetEngineServiceType
    [[deprecated(DEPRECATE_LINK)]] Service::Type GetEngineType() { return static_cast<Service::Type>(GetEngineServiceType()); }

    ServiceType GetEngineServiceType();

    /**
     * Wait until a new plugin is created.
     *
     * @return           PluginOptions
     */
    test::PluginOptions WaitPluginCreateRequest();

    /**
     * Wait until plugin is modified.
     *
     * @return           PluginOptions
     */
    test::PluginOptions WaitPluginModifyRequest();

    /**
     * Wait until plugin is started.
     *
     * @return           PluginOptions
     */
    test::PluginOptions WaitPluginRunRequest();

    /**
     * Wait until plugin is paused.
     *
     * @return           PluginOptions
     */
    test::PluginOptions WaitPluginPauseRequest();

    /**
     * Wait until plugin is deleted.
     *
     * @return           PluginOptions
     */
    test::PluginOptions WaitPluginDeleteRequest();

    /**
     * Send plugin update.
     *
     * @params update    Plugin update
     */
    void UpdatePlugin(const test::PluginOptions & update);

    /**
     * Override default request reply result.
     * HandleRequestReply() event is scheduled automatically on an plugin side for each incoming request.
     *
     * @param status       StatusOk as a default value
     *             StatusFail if engine couldn't process request
     *
     * @param status_text  Failure reason if status == StatusFail,
     *             empty string otherwise.
     */
    void SetRequestReply(const Status::StatusValue & status, const char * status_text);

    enum UpdateTypeValue
    {
        PluginCreateRequestType = 1,
        PluginModifyRequestType = 2,
        PluginRunRequestType = 3,
        PluginPauseRequestType = 4,
        PluginDeleteRequestType = 5
    };

public:
    /**
     * VirtualPluginEngine constructor,
     * can be called inside TestEngine only.
     */
    VirtualPluginEngine(PEImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualPluginEngine();

private:
    VirtualPluginEngine() = delete;
    VirtualPluginEngine(const VirtualPluginEngine &) = delete;
    VirtualPluginEngine & operator=(const VirtualPluginEngine &) = delete;
    PEImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
