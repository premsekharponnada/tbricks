#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in QuoteSet streams.
//****************************************************************************************

#include "strategy/stream_filter/AnyFilter.h"
#include "strategy/stream/QuoteSetStream.h"
#include "strategy/quoting/QuoteSet.h"
#include "strategy/quoting/QuoteSetProxy.h"

namespace tbricks {

class STRATEGY_EXPORT QuoteSet::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    QuoteSet::Stream::Filters::Filter operator||(const QuoteSet::Stream::Filters::FilterCondition & cond) const;
    QuoteSet::Stream::Filters::Filter operator&&(const QuoteSet::Stream::Filters::FilterCondition & cond) const;
    QuoteSet::Stream::Filters::Filter operator||(const QuoteSet::Stream::Filters::Filter & cond) const;
    QuoteSet::Stream::Filters::Filter operator&&(const QuoteSet::Stream::Filters::Filter & cond) const;
    QuoteSet::Stream::Filters::Filter operator!() const;
    operator QuoteSet::Stream::Filters::Filter() const;
};

/**
 * QuoteSet::Stream::Filters::ByIdentifierFilter matches quote set by quote set identifier.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByIdentifierFilter : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to matches the quote set having identifier
     * as specified in the input parameter.
     *
     * @param instance              Instance of Identifier
     */
    ByIdentifierFilter(const Identifier & instance);
    ByIdentifierFilter(const ByIdentifierFilter & filter);

    ByIdentifierFilter & operator=(const ByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_instance;
};

/**
 * QuoteSet::Stream::Filters::ByPortfolioFilte matches quote set
 * by quote set portfolio identifier.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByPortfolioFilter : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote sets having
     * portfolio identifier as specified in the input parameter.
     *
     * @param identifier            Instance of PortfolioIdentifier
     */
    ByPortfolioFilter(const PortfolioIdentifier & identifier);
    ByPortfolioFilter(const ByPortfolioFilter & filter);

    ByPortfolioFilter & operator=(const ByPortfolioFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_portfolio_identifier;
};

/**
 * QuoteSet::Stream::Filters::Active filters all the active quote sets.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::Active : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    Active();
    Active(const Active & filter);

    Active & operator=(const Active & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;
};

/**
 * QuoteSet::Stream::Filters::ByOwner matches quote set by
 * the quote set owner.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByOwner : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set having
     * owner as specified in the input parameter.
     *
     * @param identifier            Instance of UserIdentifier
     */
    ByOwner(const UserIdentifier & identifier);
    ByOwner(const ByOwner & filter);

    ByOwner & operator=(const ByOwner & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_value;
};

/**
 * QuoteSet::Stream::Filters::ByCreator matches quote set
 * by the quote set creator.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByCreator : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set created
     * by the creator as specified in the input parameter.
     *
     * @param identifier            Instance of UserIdentifier
     */
    ByCreator(const UserIdentifier & identifier);
    ByCreator(const ByCreator & filter);

    ByCreator & operator=(const ByCreator & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    UserIdentifier m_value;
};

/**
 * QuoteSet::Stream::Filters::ByParentStrategy matches quote set with
 * the specified parent strategy.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByParentStrategy : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set having
     * parent strategy as specified in the input parameter.
     *
     * @param identifier            Instance of StrategyIdentifier
     */
    ByParentStrategy(const StrategyIdentifier & identifier);
    ByParentStrategy(const ByParentStrategy & filter);

    ByParentStrategy & operator=(const ByParentStrategy & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_value;
};

/**
 * QuoteSet::Stream::Filters::ByParentStrategy matches quote set with
 * the specified ancestor strategy.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByAncestorStrategy : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set having
     * ancestor strategy as specified in the input parameter.
     *
     * @param identifier            Instance of StrategyIdentifier
     */
    ByAncestorStrategy(const StrategyIdentifier & identifier);
    ByAncestorStrategy(const ByAncestorStrategy & filter);

    ByAncestorStrategy & operator=(const ByAncestorStrategy & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_value;
};

/**
 * QuoteSet::Stream::Filters::ByMIC matches quote set with MIC.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByMIC : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set having
     * MIC as specified in the input parameter.
     *
     * @param identifier            Instance of MIC
     */
    ByMIC(const MIC & identifier);
    ByMIC(const ByMIC & filter);

    ByMIC & operator=(const ByMIC & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    MIC m_value;
};

/**
 * QuoteSet::Stream::Filters::ByVenue matches quote set by
 * venue.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByVenue : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the quote set having venue
     * as specified in the input parameter.
     *
     * @param identifier            Instance of VenueIdentifier
     */
    ByVenue(const VenueIdentifier & identifier);
    ByVenue(const ByVenue & filter);

    ByVenue & operator=(const ByVenue & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    VenueIdentifier m_value;
};

/**
 * QuoteSet::Stream::Filters::ByAlgoLabel matches quote set by
 * algo label.
 */
class STRATEGY_EXPORT QuoteSet::Stream::Filters::ByAlgoLabel : public QuoteSet::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match quote sets having algo
     * label as specified in the input parameter.
     *
     * @param algo_label            Instance of uint32_t
     */
    ByAlgoLabel(uint32_t algo_label);
    ByAlgoLabel(const ByAlgoLabel & filter);

    ByAlgoLabel & operator=(const ByAlgoLabel & filter);

    virtual void Clear();
    virtual filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    uint32_t m_algo_label;
};
}
