#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceInstrument is a
// system virtual Instrument service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/Instrument.h"
#include "strategy/test/InstrumentParametersUpdate.h"
#include "strategy/test/InstrumentGroupParametersUpdate.h"
#include "strategy/type/InstrumentGroup.h"
#include "strategy/Types.h"

#include "strategy/test/IVirtualService.h"

namespace tbricks { namespace test {
class ISImpl;

/**
 * VirtualServiceInstrument provide possibility to work with instruments,
 * instrument groups and their parameters from Instrument Service side.
 * Note that there is no aggregation logic. Aggregated parameters should
 * be configured manually (see InstrumentParametersUpdate and
 * InstrumentGroupParametersUpdate classes for details).
 */
class STRATEGY_EXPORT VirtualServiceInstrument : public IVirtualService
{
public:
    /**
     * Create instrument.
     *
     * @param io         Instrument options.
     *
     * @return           Created instrument.
     */
    Instrument CreateInstrument(const Instrument::Options & io);

    /**
     * Modify instrument.
     *
     * @param im         Instrument modifier.
     *
     * @deprecated Deprecated in 2.14.5, use ModifyInstrument(const InstrumentModifier &) instead
     */
    [[deprecated(DEPRECATE_LINK)]] void ModifyInstrument(const Instrument::Modifier & im);

    /**
     * Modify instrument.
     *
     * @param im         Instrument modifier.
     */
    void ModifyInstrument(const InstrumentModifier & im);

    /**
     * Create instrument group.
     *
     * @param igo        Instrument group options.
     *
     * @param params     Instrument group parameters.
     */
    InstrumentGroup CreateInstrumentGroup(const InstrumentGroup::Options & igo);

    /**
     * Modify instrument group.
     *
     * @param igm       Instrument group modifier.
     */
    void ModifyInstrumentGroup(const InstrumentGroup::Modifier & igm);

    /**
     * Update instrument parameters.
     *
     * @param update     Instrument parameters update.
     */
    void UpdateInstrumentParameters(const InstrumentParametersUpdate & update);

    /**
     * Update instrument group parameters.
     *
     * @param update     Instrument group parameters update.
     */
    void UpdateInstrumentGroupParameters(const InstrumentGroupParametersUpdate & update);

    /**
     * Configure filters for instrument to match to.
     * If app uses parameters filters (HasParameterFilter, ByParameterFilter, etc.),
     * these filters should be explicitly assigned to an instrument.
     *
     * Other plain filters (ByVenueInstrumentIdentifierFilter, ByCurrencyFilter, etc.) match by default.
     *
     * @param id         Instrument/InstrumentGroup identifier.
     *
     * @param filters    Instrument stream filters.
     */
    void AssignFiltersForInstrument(const InstrumentIdentifier & id, const std::vector<InstrumentStream::Filters::Filter> & filters);

    void AssignFiltersForInstrumentGroup(const InstrumentGroupIdentifier & id, const std::vector<InstrumentGroupFilter> & filters);

    /**
     * Wait until instrument parameters is modified.
     *
     * @return           InstrumentParametersUpdate.
     */
    test::InstrumentParametersUpdate WaitInstrumentParametersUpdate();

    /**
     * Wait until instrument group parameters is modified.
     *
     * @return           InstrumentParametersUpdate.
     */
    test::InstrumentGroupParametersUpdate WaitInstrumentGroupParametersUpdate();

    enum UpdateTypeValue
    {
        InstrumentParametersUpdateType = 1,
        InstrumentGroupParametersUpdateType = 2
    };

public:
    /**
     * VirtualServiceInstrument constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceInstrument(ISImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceInstrument();

private:
    VirtualServiceInstrument() = delete;
    VirtualServiceInstrument(const VirtualServiceInstrument & is) = delete;
    VirtualServiceInstrument & operator=(const VirtualServiceInstrument &) = delete;
    ISImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
