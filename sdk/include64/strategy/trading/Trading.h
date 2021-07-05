#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trading
//****************************************************************************************

#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/type/QuoteIdentifier.h"
#include "strategy/type/QuoteRequestIdentifier.h"
#include "strategy/type/TradeAttributes.h"
#include "strategy/ExtraData.h"
#include "strategy/Order.h"
#include "strategy/BlockOrder.h"
#include "strategy/ExPit.h"
#include "strategy/QuoteRequest.h"
#include "strategy/RequestForTradeOptions.h"
#include "strategy/directed_quoting/DirectedQuote.h"
#include "strategy/directed_quoting/DirectedQuoteRequest.h"
#include <map>

namespace tbricks {

class DirectedQuoteReject;
class DirectedQuoteResponse;
class DirectedRequestForQuote;

class STRATEGY_EXPORT ITrading
{
public:
    virtual ~ITrading();

    enum OrderModifyResult
    {
        OrderModifyOk,
        OrderModifyError,
        OrderModifyNotFound,
        OrderModifyNotActive
    };

    struct STRATEGY_EXPORT Fill : tbricks::Printable
    {
        enum class Type;
        const Type type;
        const uint64_t data0;
        const uint64_t data1;
        const uint64_t data2;
        const uint64_t data3;
        const Identifier dealId;
        const Side side;
        const double price;
        const double volume;
        const double remainingActiveVolume;
        const TradeAttributes tradeAttributes;

        Fill(const Identifier & _dealId,
             const OrderIdentifier & _orderId,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             const TradeAttributes & _tradeAttributes);
        Fill(const Identifier & _dealId,
             const OrderIdentifier & _orderId,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             TradeAttributes && _tradeAttributes);
        Fill(const Identifier & _dealId,
             const BlockOrderIdentifier & _orderId,
             const BlockOrderLegIdentifier & _legId,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             const TradeAttributes & _tradeAttributes);
        Fill(const Identifier & _dealId,
             const BlockOrderIdentifier & _orderId,
             const BlockOrderLegIdentifier & _legId,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             TradeAttributes && _tradeAttributes);
        Fill(const Identifier & _dealId,
             const QuoteIdentifier & _quoteId,
             const Side & _side,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             const TradeAttributes & _tradeAttributes);
        Fill(const Identifier & _dealId,
             const QuoteIdentifier & _quoteId,
             const Side & _side,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             TradeAttributes && _tradeAttributes);
        Fill(const Identifier & _dealId,
             const DirectedQuoteIdentifier & _dqId,
             const DirectedQuoteLegIdentifier & _dqLegId,
             const Side & _side,
             double _price,
             double _volume,
             const TradeAttributes & _tradeAttributes);
        /**
         * %Construct trade for expit.
         *
         * @deprecated Deprecated in 2.14.1, use Fill constructor accepting both expit and instrument identifiers.
         */
        [[deprecated(DEPRECATE_LINK)]] Fill(const Identifier & _dealId,
                                            const ExPitIdentifier & _dqId,
                                            const Side & _side,
                                            double _price,
                                            double _volume,
                                            double _remainingActiveVolume,
                                            const TradeAttributes & _tradeAttributes);

        Fill(const Identifier & _dealId,
             const ExPitIdentifier & _exPitId,
             const InstrumentIdentifier & _legId,
             const Side & _side,
             double _price,
             double _volume,
             double _remainingActiveVolume,
             const TradeAttributes & _tradeAttributes);

        /**
         * To be used when it needs to create a trade
         * without liquidity provider object (like order or quote).
         * Trade will be linked with the instrument and linked with
         * other fills with the same match identifier.
         *
         * @param _dealId deal identifier
         * @param _instrumentId instrument identifiner
         * @param _mic instrument MIC
         * @param _side trade side
         * @param _price trade price
         * @param _volume trade volume
         * @param _tradeAttributes trade attributes
         */

        Fill(const Identifier & _dealId,
             const InstrumentIdentifier & _instrumentId,
             const MIC & _mic,
             const Side & _side,
             double _price,
             double _volume,
             TradeAttributes _tradeAttributes);

        OrderIdentifier GetOrderIdentifier() const;
        BlockOrderIdentifier GetBlockOrderIdentifier() const;
        BlockOrderLegIdentifier GetBlockOrderLegIdentifier() const;
        QuoteIdentifier GetQuoteIdentifier() const;
        DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;
        DirectedQuoteLegIdentifier GetDirectedQuoteLegIdentifier() const;
        ExPitIdentifier GetExPitIdentifier() const;
        InstrumentIdentifier GetInstrumentIdentifier() const;

        virtual ~Fill();
        virtual std::ostream & Print(std::ostream & strm) const override;
    };

    struct Match : public std::vector<Fill>
    {
        friend std::ostream & operator<<(std::ostream & strm, const Match & match) { return ITrading::PrintMatch(strm, match); }
    };

    virtual void AcceptOrder(const OrderIdentifier & orderId, bool fill = false) = 0;
    virtual void AcceptOrder(const OrderIdentifier & orderId, const ExtraData & venueExtraData, bool fill = false) = 0;
    virtual void AcceptOrder(const OrderIdentifier & orderId, const Order::Modifier & om, bool fill = false) = 0;
    virtual void DeleteOrder(const OrderIdentifier & orderId, const String & reason) = 0;
    virtual void DeleteOrder(const OrderIdentifier & orderId, const String & reason, const Order::Modifier & modifier) = 0;
    virtual void FailOrder(const OrderIdentifier & orderId, const String & reason) = 0;
    virtual void FailOrder(const OrderIdentifier & orderId, const String & reason, const Order::Modifier & modifier) = 0;
    virtual size_t FailOrders(const std::vector<OrderIdentifier> & orders, const String & reason) = 0;
    virtual OrderModifyResult ModifyOrder(const OrderIdentifier & orderId, const Order::Modifier & orderModify) = 0;

    virtual void AcceptBlockOrder(const BlockOrderIdentifier & orderId) = 0;
    virtual void FailBlockOrder(const BlockOrderIdentifier & orderId, const String & reason) = 0;

    virtual const Order & GetOrder(const OrderIdentifier & orderId) const = 0;
    virtual const Order * GetOrderEx(const OrderIdentifier & orderId) const = 0;

    virtual void SendMatch(const Match & match) = 0;
    virtual void SendMatch(const Match & match, const TradeAttributes & tradeAttributes) = 0;

    static std::ostream & PrintMatch(std::ostream & strm, const Match & match);
};

class STRATEGY_EXPORT Trading : public ITrading
{
private:
    class Impl;
    std::shared_ptr<Impl> m_impl;

public:
    struct STRATEGY_EXPORT Quote
    {
        struct STRATEGY_EXPORT Side
        {
            Side(double _price, double _volume) : price(_price), volume(_volume) {}
            double price;
            double volume;

            void print(std::ostream & strm) const;
            friend std::ostream & operator<<(std::ostream & strm, const Side & side)
            {
                side.print(strm);
                return strm;
            }
        };

        Quote(QuoteIdentifier _id, const Side & _bid, const Side & _ask) : id(_id), bid(_bid), ask(_ask) {}

        const QuoteIdentifier id;
        Side bid;
        Side ask;

        double GetOppositePrice(const tbricks::Side & side) const
        {
            if (side.IsBuy()) {
                return ask.price;
            } else {
                return bid.price;
            }
        }

        double GetOppositeVolume(const tbricks::Side & side) const
        {
            if (side.IsBuy()) {
                return ask.volume;
            } else {
                return bid.volume;
            }
        }

        friend std::ostream & operator<<(std::ostream & strm, const Quote & quote)
        {
            strm << quote.id << ": " << quote.bid.volume << "@" << quote.bid.price << "-" << quote.ask.volume << "@" << quote.ask.price << std::endl;
            return strm;
        }
    };

    struct QuoteAcknowledgement
    {
        QuoteAcknowledgement(const QuoteIdentifier & _quoteId, double _bidVolume, const double _askVolume) :
            quoteId(_quoteId),
            bidVolume(_bidVolume),
            askVolume(_askVolume)
        {}
        const QuoteIdentifier quoteId;
        const double bidVolume;
        const double askVolume;
    };

    struct Quotes : public std::map<InstrumentIdentifier, std::vector<Quote>>
    {
        Quotes(const LiquidityPoolIdentifier & lp_id_, const PortfolioIdentifier & p_id_) : lp_id(lp_id_), p_id(p_id_) {}

        friend std::ostream & operator<<(std::ostream & strm, const Quotes & quotes) { return Trading::PrintQuotes(strm, quotes); }

        const LiquidityPoolIdentifier & GetLiquidityPoolIdentifier() const { return lp_id; }
        const PortfolioIdentifier & GetPortfolioIdentifier() const { return p_id; }

    private:
        const LiquidityPoolIdentifier lp_id;
        const PortfolioIdentifier p_id;
    };

    static std::ostream & PrintQuotes(std::ostream & strm, const Quotes & quotes);

    Trading();
    virtual ~Trading();

    const VenueIdentifier GetTradingVenueIdentifier() const;
    const TimeZone GetTradingVenueTimeZone() const;

    virtual bool HandleIsTradingSupported(const InstrumentVenueIdentification & ivid) = 0;
    virtual void HandleRecovery(const std::vector<Order> & orders) = 0;

    virtual void HandleOrder(const Order & order) = 0; // deprecated
    virtual void HandleOrder(const OrderIdentifier & orderId, const Order & order);
    virtual void HandleOrderModify(const Order::Modify & orderModify) = 0;
    virtual void HandleOrderDelete(const OrderIdentifier & orderId) = 0; // deprecated
    virtual void HandleOrderDelete(const OrderIdentifier & orderId, const Order & order);
    virtual void HandleOrdersMassDelete(const InstrumentVenueIdentification & ivid) = 0;

    virtual void HandleBlockOrder(const BlockOrderIdentifier & orderId, const BlockOrder & order);
    virtual void HandleBlockOrderDelete(const BlockOrderIdentifier & orderId);

    virtual void HandleQuotes(const Quotes & quotes) = 0;

    /// @deprecated Deprecated in 2.14.0
    [[deprecated(DEPRECATE_LINK)]] void CreateDirectedRequestForQuote(const DirectedQuoteRequestIdentifier & rfq_id,
                                                                      const DirectedRequestForQuote & rfq);
    /// @deprecated Deprecated in 2.14.3
    [[deprecated(DEPRECATE_LINK)]] DirectedQuoteRequestIdentifier CreateDirectedRequestForQuote(const DirectedRequestForQuote & rfq);

    /**
     * The function creates and sends new DirectedRequestForQuote.
     * Also, new DirectedQuoteRequestIdentifier value is generated, then set to DirectedRequestForQuote 'rfq' object and returned from the function.
     */
    DirectedQuoteRequestIdentifier CreateDirectedRequestForQuote(DirectedRequestForQuote & rfq);
    void ModifyDirectedRequestForQuote(const DirectedQuoteRequestIdentifier & rfq_id, const DirectedRequestForQuote & rfq);
    void DeleteDirectedRequestForQuote(const DirectedQuoteRequestIdentifier & rfq_id);
    void DeleteDirectedRequestForQuote(const DirectedQuoteRequestIdentifier & rfq_id, const DirectedRequestForQuote & rfq);

    virtual void HandleDirectedQuote(const DirectedQuote & directed_quote);
    void AcceptDirectedQuote(const DirectedQuoteIdentifier & directQuoteId);
    void RejectDirectedQuote(const DirectedQuoteIdentifier & directQuoteId, const String & reason = String());

    void ModifyDirectedQuote(const DirectedQuoteIdentifier & directedQuoteId, const DirectedQuote::Modifier & modifier);
    void ModifyDirectedQuote(const DirectedQuoteIdentifier & directedQuoteId, const DirectedQuote & quote);
    void DeleteDirectedQuote(const DirectedQuoteIdentifier & directedQuoteId, const String & reason = String());

    virtual void HandleDirectedQuoteRejectRequest(const DirectedQuoteReject & directedQuoteReject);

    virtual void HandleDirectedQuoteModify(const DirectedQuote::Modify & directed_quote);
    void AcceptDirectedQuoteModify(const Identifier & requestId, const DirectedQuote & quote);
    void AcceptDirectedQuoteModify(const Identifier & requestId, const DirectedQuote::Modifier & quote);
    void RejectDirectedQuoteModify(const Identifier & requestId, const String & reason = String());

    virtual void HandleDirectedQuoteDelete(const DirectedQuoteIdentifier & directedQuoteId, const Identifier & request_id);
    void AcceptDirectedQuoteDelete(const DirectedQuoteIdentifier & id);
    void RejectDirectedQuoteDelete(const DirectedQuoteIdentifier & id, const String & reason = String());

    /* ITrading */

    virtual void AcceptOrder(const OrderIdentifier & orderId, bool fill = false) override;
    virtual void AcceptOrder(const OrderIdentifier & orderId, const ExtraData & venueExtraData, bool fill = false) override;
    virtual void AcceptOrder(const OrderIdentifier & orderId, const Order::Modifier & om, bool fill = false) override;

    /**
     * Delete order and set <OrderTransactionStateOk> order transaction state.
     *
     * @param orderId       order identifier
     *
     * @param statusText    status text
     */
    virtual void DeleteOrder(const OrderIdentifier & orderId, const String & reason) override;

    /**
     * Delete order, set <OrderTransactionStateOk> order transaction state
     * and apply the modifier at the same time atomically. Only <strategy parameters> and <extra data>
     * fields from the modifier are applied to the order, these fields are updated with merge semantic.
     *
     * @param orderId       order identifier
     *
     * @param statusText    status text
     */
    virtual void DeleteOrder(const OrderIdentifier & orderId, const String & reason, const Order::Modifier & modifier) override;

    /**
     * Delete order and set <OrderTransactionStateFail> order transaction state.
     *
     * @param orderId       order identifier
     *
     * @param statusText    status text
     */
    virtual void FailOrder(const OrderIdentifier & orderId, const String & statusText) override;

    /**
     * Delete order, set <OrderTransactionStateFail> order transaction state
     * and apply the modifier at the same time atomically. Only <strategy parameters> and <extra data>
     * fields from the modifier are applied to the order, these fields are updated with merge semantic.
     *
     * @param orderId       order identifier
     *
     * @param statusText    status text
     *
     * @param modifier      order modifier to be applied
     */
    virtual void FailOrder(const OrderIdentifier & orderId, const String & statusText, const Order::Modifier & modifier) override;
    virtual size_t FailOrders(const std::vector<OrderIdentifier> & orders, const String & reason) override;
    virtual OrderModifyResult ModifyOrder(const OrderIdentifier & orderId, const Order::Modifier & orderModify) override;

    virtual void AcceptBlockOrder(const BlockOrderIdentifier & orderId) override;
    virtual void FailBlockOrder(const BlockOrderIdentifier & orderId, const String & reason) override;
    void DeleteBlockOrder(const BlockOrderIdentifier & orderId, const String & reason);

    virtual const Order & GetOrder(const OrderIdentifier & orderId) const override;
    virtual const Order * GetOrderEx(const OrderIdentifier & orderId) const override;

    /**
     * Create set of trades linked together with the same match identifier.
     *
     * @param match             trades to create
     */
    virtual void SendMatch(const Match & match) override;

    /**
     * Create set of trades linked together with the same match identifier.
     *
     * @param match             trades to create
     * @param tradeAttributes   attributes to be applied to all created trades
     */
    virtual void SendMatch(const Match & match, const TradeAttributes & tradeAttributes) override;

    void AcknowledgeQuotes(const std::vector<QuoteAcknowledgement> & acks, const std::vector<std::pair<QuoteIdentifier, String>> & fails);

    void CancelTrade(const String & exchangeTradeIdentifier, const String & reason);

    /**
     * Method supposed to be used as a reaction on HandleOrderModify().
     * Order modify request can contain many order's fields at once,
     * so the app can accept only subset of them. orderUpdate suppsoed
     * to contain a set of fields that app accepts, so the data from the
     * order update will be merged to the system order.
     *
     * Only <active volume> and <price> fields in orderUpdate are supported for now.
     *
     * In a case if trading framework configured with <max_pending_modifications>
     * then app can receive new order modification request even while previous
     * was not accepted or rejected. If an app accepts (or rejects) some modify
     * request while some previous requests are pending then all previous requests
     * are considered having the same status and should not be accepted or rejected further.
     *
     * @param orderId                   order identifier
     *
     * @param orderUpdate               data to be applied to the persisted order
     */

    /// @deprecated Deprecated in 2.14.4
    [[deprecated(DEPRECATE_LINK)]] void AcceptOrderModify(const Identifier & requestId, const Order & orderUpdate);

    /// @deprecated Deprecated in 2.14.4
    [[deprecated(DEPRECATE_LINK)]] void RejectOrderModify(const Identifier & requestId, const String & reason);

    void AcceptOrderModify(const OrderIdentifier & orderId, const Order::Modifier & orderModifier);
    void RejectOrderModify(const OrderIdentifier & orderId, const String & reason);

    void AcceptOrderDelete(const OrderIdentifier & orderId);
    void RejectOrderDelete(const OrderIdentifier & orderId, const String & reason);

    virtual void HandleDirectedQuoteRequest(const DirectedQuoteRequest & request);

    void AcceptDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & quoteRequestId);
    void AcceptDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & quoteRequestId, const DirectedQuoteRequest::Modifier & modifier);
    void RejectDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & quoteRequestId, const String & reason);

    virtual void HandleDirectedQuoteRequestModify(const DirectedQuoteRequest::Modifier & request);

    void AcceptDirectedQuoteRequestModify(const Identifier & requestId, const DirectedQuoteRequest::Modifier & modifier);
    void RejectDirectedQuoteRequestModify(const Identifier & requestId, const String & reason);

    virtual void HandleDirectedQuoteRequestDelete(const DirectedQuoteRequestIdentifier & identifier);

    void AcceptDirectedQuoteRequestDelete(const DirectedQuoteRequestIdentifier & identifier);
    void RejectDirectedQuoteRequestDelete(const DirectedQuoteRequestIdentifier & identifier, const String & reason);

    void CloseDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & id, const String & status);
    void CloseDirectedQuoteRequest(const DirectedQuoteRequestIdentifier & id, const DirectedQuoteRequest::Modifier & modifier, const String & status);

    /**
     * Method supposed to be used as a reaction on HandleQuoteRequest().
     *
     * @param quoteRequestId            quote request identifier
     */
    virtual void HandleQuoteRequest(const QuoteRequest & request);
    void AcceptQuoteRequest(const QuoteRequestIdentifier & quoteRequestId);
    void RejectQuoteRequest(const QuoteRequestIdentifier & quoteRequestId, const String & status);

    virtual void HandleQuoteRequestDelete(const QuoteRequestIdentifier & quoteRequestId);
    void AcceptQuoteDeleteRequest(const QuoteRequestIdentifier & quoteRequestId);
    void RejectQuoteDeleteRequest(const QuoteRequestIdentifier & quoteRequestId, const String & status);

    void CloseQuoteRequest(const QuoteRequestIdentifier & id, const String & status);

    DirectedQuoteResponseIdentifier
    CreateDirectedQuoteResponse(const QuoteRequestIdentifier & qr_id, const DirectedQuoteResponseGeneration & dqr_gen, DirectedQuoteResponse & dqr);
    DirectedQuoteResponseIdentifier CreateDirectedQuoteResponse(const DirectedQuoteRequestIdentifier & qr_id,
                                                                const DirectedQuoteResponseGeneration & dqr_gen,
                                                                DirectedQuoteResponse & dqr);
    void ModifyDirectedQuoteResponse(const DirectedQuoteResponseIdentifier & dqr_id,
                                     const DirectedQuoteResponseGeneration & dqr_gen,
                                     DirectedQuoteResponse & dqr);
    void DeleteDirectedQuoteResponse(const DirectedQuoteResponseIdentifier & dqr_id, const String & status);

    /**
     * Method supposed to be used for sending Request for trades. If Expit service is disabled nothing will happen.
     *
     * @param requestForTrade           request for trade
     */
    void SendRequestForTrade(const RequestForTradeOptions & rft);
    void DeleteRequestForTrade(const RequestForTradeIdentifier & rft_id);

    /**
     * Handle ExPit
     */
    virtual void HandleExPit(const ExPit & expit);
    void AcceptExPit(const ExPitIdentifier & id);
    void RejectExPit(const ExPitIdentifier & id, const String & status);

    virtual void HandleExPitDelete(const ExPitIdentifier & expitId);
    void AcceptExPitDelete(const ExPitIdentifier & id);
    void RejectExPitDelete(const ExPitIdentifier & id, const String & status);

    virtual void HandleRequestForTradeDecline(const RequestForTradeIdentifier &);
    void AcceptRequestForTradeDecline(const RequestForTradeIdentifier &);
    void RejectRequestForTradeDecline(const RequestForTradeIdentifier & id, const String & status);

    void DeleteExPit(const ExPitIdentifier & id, const String & reason);
};

} /* namespace tbricks { */
