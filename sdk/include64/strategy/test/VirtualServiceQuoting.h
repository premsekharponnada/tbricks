#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceQuoting is a
// system virtual Quoting service.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/test/IVirtualService.h"
#include "strategy/test/QuoteSetOptions.h"
#include "strategy/test/QuoteTableUpdate.h"
#include "strategy/test/QuoteFill.h"
#include "strategy/test/Quote.h"
#include "strategy/test/QuoteAudit.h"

namespace tbricks::test {
class QSImpl;

class STRATEGY_EXPORT VirtualServiceQuoting : public IVirtualService
{
public:
    /**
     * Get venue identifier of service.
     *
     * @return           Venue identifier.
     */
    VenueIdentifier GetVenueId() const;

    /**
     * Quote Set interface
     */

    /**
     * Wait until a new quote set is created.
     *
     * @return           QuoteSetOptions.
     */
    test::QuoteSetOptions WaitQuoteSetCreateRequest();

    /**
     * Wait until quotes set is modified.
     * Including quote volume table modifications
     *
     * @return           QuoteSetOptions.
     */
    test::QuoteSetOptions WaitQuoteSetModifyRequest();

    /**
     * Wait until quote set is activated.
     *
     * @return           QuoteSet Operation Options.
     */
    test::QuoteSetOperation WaitQuoteSetDeleteRequest();

    /**
     * Wait until quote set is activated.
     *
     * @return           QuoteSet Operation Options.
     */
    test::QuoteSetOperation WaitQuoteSetStartRequest();

    /**
     * Wait until quote set is paused.
     *
     * @return           QuoteSet Operation Options.
     */
    test::QuoteSetOperation WaitQuoteSetStopRequest();

    /**
     * Send quote set update.
     *
     * @param update     Quote set update.
     */
    void UpdateQuoteSet(const test::QuoteSetOptions & update);

    /**
     * Quote Table interface
     */

    /**
     * Wait until quote price table is created or modified.
     *
     * @return           QuoteTableModifier.
     */
    test::QuoteTableUpdate WaitQuotePriceTableUpdate();

    /**
     * Wait until quote price table is deleted.
     *
     * @return           TableIdentification.
     */
    test::QuoteTableIdentification WaitQuotePriceTableDeleteRequest();

    /**
     * Wait until quote price table is selected.
     *
     * @return           TableIdentification.
     */
    test::QuoteTableIdentification WaitQuoteSetActiveTableRequest();

    /**
     * Send quote fill.
     *
     * @param update     Quote fill.
     */
    void UpdateQuoteFill(test::QuoteFill & update);

    /**
     * Send quote
     *
     * @param update Quote
     **/
    void UpdateQuote(test::Quote & update);

    /**
     * Send quote
     *
     * @param update Quote
     **/
    void UpdateRegulatoryAudit(test::QuoteAudit & update);

    enum UpdateTypeValue
    {
        QuoteSetCreateRequestType = 1,
        QuoteSetModifyRequestType = 2,
        QuoteSetDeleteRequestType = 3,
        QuoteSetStartRequestType = 4,
        QuoteSetStopRequestType = 5,
        QuotePriceTableUpdateType = 6,
        QuotePriceTableDeleteRequestType = 7,
        QuoteSetActiveTableRequestType = 8
    };

public:
    /**
     * VirtualServiceQuoting constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceQuoting(QSImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceQuoting();

private:
    VirtualServiceQuoting() = delete;
    VirtualServiceQuoting(const VirtualServiceQuoting &) = delete;
    VirtualServiceQuoting & operator=(const VirtualServiceQuoting &) = delete;
    QSImpl * m_impl;
};
}
