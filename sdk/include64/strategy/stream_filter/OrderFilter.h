#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OrderFilter objects.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/OrderStream.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

/**
 * Base instrument order filter class.
 */
class STRATEGY_EXPORT Order::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    virtual ~Filter();

    Filter & operator=(const Filter & filter);

    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);

    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);

    Filter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT Order::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Order::Stream::Filters::Filter operator||(const FilterCondition & cond) const;
    Order::Stream::Filters::Filter operator&&(const FilterCondition & cond) const;
    Order::Stream::Filters::Filter operator||(const Filter & cond) const;
    Order::Stream::Filters::Filter operator&&(const Filter & cond) const;
    Order::Stream::Filters::Filter operator!() const;
    operator Order::Stream::Filters::Filter() const;
};

/// By Identifier

class STRATEGY_EXPORT Order::Stream::Filters::ByIdentifier : public Order::Stream::Filters::FilterCondition
{
public:
    ByIdentifier(const OrderIdentifier & portfolio_id);

    virtual void Clear() { m_order_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_order_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    OrderIdentifier m_order_id;
};

/// By Portfolio

class STRATEGY_EXPORT Order::Stream::Filters::ByPortfolio : public Order::Stream::Filters::FilterCondition
{
public:
    ByPortfolio(const PortfolioIdentifier & portfolio_id);

    virtual void Clear() { m_portfolio_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_portfolio_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_portfolio_id;
};

/// By Instrument

class STRATEGY_EXPORT Order::Stream::Filters::ByInstrument : public Order::Stream::Filters::FilterCondition
{
public:
    ByInstrument(const InstrumentIdentifier & instrument_id);

    virtual void Clear() { m_instrument_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_instrument_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    InstrumentIdentifier m_instrument_id;
};

/// By Owner

class STRATEGY_EXPORT Order::Stream::Filters::ByOwner : public Order::Stream::Filters::FilterCondition
{
public:
    ByOwner(const UserIdentifier & owner_id);

    virtual void Clear() { m_owner_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_owner_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_owner_id;
};

/// By Creator

class STRATEGY_EXPORT Order::Stream::Filters::ByCreator : public Order::Stream::Filters::FilterCondition
{
public:
    ByCreator(const UserIdentifier & creator_id);

    virtual void Clear() { m_creator_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_creator_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_creator_id;
};

/// By Parent Strategy

class STRATEGY_EXPORT Order::Stream::Filters::ByParentStrategy : public Order::Stream::Filters::FilterCondition
{
public:
    ByParentStrategy(const Strategy & strategy);
    ByParentStrategy(const StrategyIdentifier & strategy_id);

    virtual void Clear() { m_strategy_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_strategy_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_strategy_id;
};

/// By Root Strategy

class STRATEGY_EXPORT Order::Stream::Filters::ByRootStrategy : public Order::Stream::Filters::FilterCondition
{
public:
    ByRootStrategy(const Strategy & strategy);
    ByRootStrategy(const StrategyIdentifier & strategy_id);

    virtual void Clear() { m_strategy_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_strategy_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_strategy_id;
};

/// By Ancestor Strategy

class STRATEGY_EXPORT Order::Stream::Filters::ByAncestorStrategy : public Order::Stream::Filters::FilterCondition
{
public:
    ByAncestorStrategy(const Strategy & strategy);
    ByAncestorStrategy(const StrategyIdentifier & strategy_id);

    virtual void Clear() { m_strategy_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_strategy_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_strategy_id;
};

/// Active orders

class STRATEGY_EXPORT Order::Stream::Filters::Active : public Order::Stream::Filters::FilterCondition
{
public:
    Active() = default;

    virtual void Clear() {}
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return false; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/// ByHostModifiedDateTime
class STRATEGY_EXPORT Order::Stream::Filters::ByHostModifiedDateTime : public Order::Stream::Filters::FilterCondition
{
public:
    ByHostModifiedDateTime(const tbricks::Filter::Relation & relation, const DateTime & datetime) : m_impl(relation, datetime) {}

    virtual bool Empty() const { return m_impl.Empty(); }
    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<order by host modified datetime filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeWithRelationConditionImpl m_impl;
};

/// ByHostCreatedDateTime
class STRATEGY_EXPORT Order::Stream::Filters::ByHostCreatedDateTime : public Order::Stream::Filters::FilterCondition
{
public:
    ByHostCreatedDateTime(const tbricks::Filter::Relation & relation, const DateTime & datetime) : m_impl(relation, datetime) {}

    virtual bool Empty() const { return m_impl.Empty(); }
    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<order by host created datetime filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeWithRelationConditionImpl m_impl;
};

/// BySide

class STRATEGY_EXPORT Order::Stream::Filters::BySide : public Order::Stream::Filters::FilterCondition
{
public:
    BySide(const Side & side) : m_side(side) {}

    virtual void Clear() { m_side.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_side.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Side m_side;
};

/// ByTransactionState

class STRATEGY_EXPORT Order::Stream::Filters::ByTransactionState : public Order::Stream::Filters::FilterCondition
{
public:
    ByTransactionState(const TransactionState & transaction_state) : m_transaction_state(transaction_state) {}

    virtual void Clear() { m_transaction_state.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_transaction_state.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TransactionState m_transaction_state;
};

/// ByPrice

class STRATEGY_EXPORT Order::Stream::Filters::ByPrice : public Order::Stream::Filters::FilterCondition
{
public:
    ByPrice(const tbricks::Filter::Relation & relation, const Price & price);

    virtual void Clear() { m_empty = true; }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_empty; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    tbricks::Filter::Relation m_relation;
    double m_price;
    bool m_empty;
};

/// ByTotalVolume

class STRATEGY_EXPORT Order::Stream::Filters::ByTotalVolume : public Order::Stream::Filters::FilterCondition
{
public:
    ByTotalVolume(const tbricks::Filter::Relation & relation, const Volume & volume);

    virtual void Clear() { m_volume.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_volume.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    tbricks::Filter::Relation m_relation;
    Volume m_volume;
};

/// ByFilledVolume

class STRATEGY_EXPORT Order::Stream::Filters::ByFilledVolume : public Order::Stream::Filters::FilterCondition
{
public:
    ByFilledVolume(const tbricks::Filter::Relation & relation, const Volume & volume);

    virtual void Clear() { m_volume.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_volume.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    tbricks::Filter::Relation m_relation;
    Volume m_volume;
};

/// ByMIC

class STRATEGY_EXPORT Order::Stream::Filters::ByMIC : public Order::Stream::Filters::FilterCondition
{
public:
    ByMIC(const MIC & mic) : m_mic(mic) {}

    virtual void Clear() { m_mic.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_mic.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    MIC m_mic;
};

/// ByExtraData

class STRATEGY_EXPORT Order::Stream::Filters::ByExtraData : public Order::Stream::Filters::FilterCondition
{
public:
    ByExtraData(const tbricks::Filter::Relation & relation, const String & name, const AnyType & value);
    ByExtraData(const String & name, const AnyType & any);
    ByExtraData(const ByExtraData & filter);
    virtual ~ByExtraData();

    ByExtraData & operator=(const ByExtraData & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    std::unique_ptr<tbricks::filter::ICondition> m_condition;
};

/// ByClient

class STRATEGY_EXPORT Order::Stream::Filters::ByClient : public Order::Stream::Filters::FilterCondition
{
public:
    ByClient(const TreeNodeIdentifier & client_id);

    virtual void Clear() { m_client_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_client_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_client_id;
};

/// ByHandler

class STRATEGY_EXPORT Order::Stream::Filters::ByHandler : public Order::Stream::Filters::FilterCondition
{
public:
    ByHandler(const TreeNodeIdentifier & client_id);

    virtual void Clear() { m_handler_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_handler_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    TreeNodeIdentifier m_handler_id;
};

/// ByVenue

class STRATEGY_EXPORT Order::Stream::Filters::ByVenue : public Order::Stream::Filters::FilterCondition
{
public:
    ByVenue(const VenueIdentifier & venue_id);

    virtual void Clear() { m_venue_id.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_venue_id.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    VenueIdentifier m_venue_id;
};

// ByAlgoLabel

class STRATEGY_EXPORT Order::Stream::Filters::ByAlgoLabel : public Order::Stream::Filters::FilterCondition
{
public:
    ByAlgoLabel(uint32_t algo_label) : m_algo_label(algo_label) {}

    virtual void Clear() { m_algo_label = 0; }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_algo_label == 0; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    uint32_t m_algo_label;
};

/// FromOrder

class STRATEGY_EXPORT Order::Stream::Filters::FromOrder : public Order::Stream::Filters::FilterCondition
{
public:
    virtual void Clear() {}
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return false; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/// FromQuote

class STRATEGY_EXPORT Order::Stream::Filters::FromQuote : public Order::Stream::Filters::FilterCondition
{
public:
    FromQuote() = default;
    FromQuote(QuoteMode value) : m_mode(value), m_empty(false) {}

    virtual void Clear() { m_empty = true; }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_empty; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    QuoteMode m_mode;
    bool m_empty = true;
};

/**
 * @deprecated Deprecated in 2.12.0.
 *             Use Order::Stream::Filters::FromOrder and Order::Stream::Filters::FromQuote instead.
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] Order::Stream::Filters::ByType : public Order::Stream::Filters::FilterCondition
{
public:
    ByType(Order::Type type) : m_type(type), m_empty(false) {}

    virtual void Clear() { m_empty = true; }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_empty; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Order::Type m_type;
    bool m_empty;
};

/**
 * @deprecated Deprecated in 2.12.0.
 *             Use Order::Stream::Filters::FromOrder and Order::Stream::Filters::FromQuote instead.
 */
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] Order::Stream::Filters::Quote : public Order::Stream::Filters::FilterCondition
{
public:
    Quote() = default;

    virtual void Clear() { m_empty = true; }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_empty; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_empty = false;
};

/**
 * ByRootPortfolio matches all orders originated from portfolio tree.
 */
class STRATEGY_EXPORT Order::Stream::Filters::ByRootPortfolio : public Order::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the orders instanciated at
     * root portfolio as specified in the input parameter.
     *
     * @param root                          Portfolio Identifier to specify the root portfolio.
     */
    ByRootPortfolio(const PortfolioIdentifier & root);

    virtual void Clear() { m_root.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_root.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_root;
};
}
