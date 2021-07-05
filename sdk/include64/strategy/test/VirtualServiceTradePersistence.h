#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// VirtualServiceTradePersistence is a
// system virtual TradePersistence service.
//****************************************************************************************

#include "strategy/test/IVirtualService.h"
#include "strategy/test/PositionOptions.h"
#include "strategy/ReferencePrice.h"
#include "strategy/ReferenceExchangeRate.h"
#include "strategy/test/PortfolioOptions.h"
#include "strategy/test/CashOptions.h"
#include "strategy/test/TradeOptions.h"
#include "ExpirationOldOptions.h"
#include "ExpirationOptions.h"

namespace tbricks { namespace test {
class TPImpl;

class STRATEGY_EXPORT VirtualServiceTradePersistence : public IVirtualService
{
public:
    /**
     * Wait until an trade is created.
     *
     * @return           Trade.
     */
    Trade WaitTradeCreateRequest();

    /**
     * Wait until an trade is modified or deleted.
     *
     * @return           Trade with updated fields.
     */
    Trade WaitTradeModifyRequest();

    /**
     * Wait until an portfolio is created.
     *
     * @return           PortfolioOptions.
     */
    test::PortfolioOptions WaitPortfolioCreateRequest();

    /**
     * Wait until an portfolio is modified or deleted.
     *
     * @return           PortfolioOptions with updated fields.
     */
    test::PortfolioOptions WaitPortfolioModifyRequest();

    /**
     * Wait until an cash is created.
     *
     * @return           CashOptions.
     */
    test::CashOptions WaitCashCreateRequest();

    /**
     * Wait until an cash is modified or deleted.
     *
     * @return           CashOptions with updated fields.
     */
    test::CashOptions WaitCashModifyRequest();

    /**
     * Wait until an expiration old is created.
     *
     * @return           ExpirationOldOptions.
     */
    test::ExpirationOldOptions WaitExpirationOldCreateRequest();

    /**
     * Wait until an expiration old is deleted.
     *
     * @return           ExpirationOldOperation with delete request.
     */
    test::ExpirationOldOperation WaitExpirationOldDeleteRequest();

    /**
     * Wait until an expiration is created.
     *
     * @return           ExpirationOptions.
     */
    test::ExpirationOptions WaitExpirationCreateRequest();

    /**
     * Wait until an expiration is modified or deleted.
     *
     * @return           ExpirationOptions with updated fields.
     */
    test::ExpirationOptions WaitExpirationModifyRequest();

    /**
     * Send trade update to schedule HandleTrade() event on an app side.
     *
     * @param trade     Trade.
     *
     *  @deprecated Deprecated in 2.14.4
     */
    [[deprecated(DEPRECATE_LINK)]] void UpdateTrade(const Trade & trade);

    /**
     * Send trade update to schedule HandleTrade() event on an app side.
     *
     * @param trade     Trade.
     */
    void UpdateTrade(const TradeOptions & trade);

    /**
     * Send position update to schedule HandlePosition() event on an app side.
     *
     * @param position     Position.
     */
    void UpdatePosition(const PositionOptions & position);

    /**
     * Send reference price update to schedule HandleReferencePrice() event on an app side.
     *
     * @param price     Reference price to update.
     */
    void UpdateReferencePrice(const ReferencePrice::Options & price);

    /**
     * Send Reference exchange rate update to schedule HandleReferenceExchangeRate() event on an app side.
     *
     * @param price     Reference exchange rate to update.
     */
    void UpdateReferenceExchangeRate(const ReferenceExchangeRate::Options & rate, bool deleted = false);

    /**
     * Send Portfolio update to schedule HandlePortfolioUpdate() event on an app side.
     *
     * @param portfolio Portfolio options to update.
     */
    void UpdatePortfolio(const test::PortfolioOptions & portfolio);

    /**
     * Send Cash update to schedule HandleCashUpdate() event on an app side.
     *
     * @param expiration Cash options to update.
     */
    void UpdateCash(const test::CashOptions & cash);

    /**
     * Send ExpirationOld update to schedule HandleExpiration() event on an app side.
     *
     * @param expiration ExpirationOld options to update.
     */
    void UpdateExpirationOld(const test::ExpirationOldOptions & expiration);

    /**
     * Send ExpirationOld delete request
     *
     * @param operation ExpirationOld operation to delete.
     */
    void DeleteExpirationOld(const test::ExpirationOldOperation & operation);

    /**
     * Send Expiration update to schedule HandleExpiration() event on an app side.
     *
     * @param expiration Expiration options to update.
     */
    void UpdateExpiration(const test::ExpirationOptions & expiration);

public:
    /**
     * VirtualServiceTradePersistence constructor,
     * can be called inside TestEngine only.
     */
    VirtualServiceTradePersistence(TPImpl * impl, const ServiceIdentifier & id);
    virtual ~VirtualServiceTradePersistence();

private:
    VirtualServiceTradePersistence() = delete;
    VirtualServiceTradePersistence(const VirtualServiceTradePersistence &) = delete;
    VirtualServiceTradePersistence & operator=(const VirtualServiceTradePersistence &) = delete;
    TPImpl * m_impl;
};

} // \namespace test
} // \namespace tbricks
