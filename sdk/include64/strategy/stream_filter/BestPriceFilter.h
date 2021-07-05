#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in best price streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/type/Price.h"
#include "strategy/type/Volume.h"

namespace tbricks {

/**
 * Default BestPrice filter, matches all the messages.
 */
class STRATEGY_EXPORT BestPriceFilter : public Filter
{
public:
    BestPriceFilter();
    BestPriceFilter(const BestPriceFilter & filter);
    ~BestPriceFilter();

    BestPriceFilter & operator=(const BestPriceFilter & filter);

    BestPriceFilter & operator|=(const BestPriceFilter & filter);
    BestPriceFilter & operator&=(const BestPriceFilter & filter);

    BestPriceFilter operator||(const BestPriceFilter & filter);
    BestPriceFilter operator&&(const BestPriceFilter & filter);

    BestPriceFilter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};
//----------------------------------------------------------------------------------------------------

/**
 * Convenience alias.
 */
typedef BestPriceFilter AnyBestPriceFilter;

class STRATEGY_EXPORT BestPriceFilterCondition : public FilterCondition
{
public:
    BestPriceFilter operator||(const BestPriceFilterCondition & cond) const;
    BestPriceFilter operator&&(const BestPriceFilterCondition & cond) const;
    BestPriceFilter operator||(const BestPriceFilter & cond) const;
    BestPriceFilter operator&&(const BestPriceFilter & cond) const;
    BestPriceFilter operator!() const;
    operator BestPriceFilter() const;
};

//----------------------------------------------------------------------------------------------------

/**
 * For the instrument with the specified instrument venue identifier,
 * BestPriceByBidFilter provides
 *  	- best bid volume
 *  	- best bid trend
 *  	- best ask trend
 * for the given price and Filter::Relation.
 */
class STRATEGY_EXPORT BestPriceByBidFilter : public BestPriceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to provide
     *      - best bid volume
     *      - best bid trend
     *      - best ask trend
     * for the price and Filter::Relation as specified in the
     * input parameters.
     *
     * @param price                Instance of Price to know the best bid.
     * @param relation             If its value is set to Filter::EQ (Equal), it will
                                   filter the best bid having price = price specified
                                   as the input parameter.
     */
    BestPriceByBidFilter(const Price & price, const Filter::Relation & relation);
    BestPriceByBidFilter(const BestPriceByBidFilter & filter) = default;
    BestPriceByBidFilter & operator=(const BestPriceByBidFilter & filter) = default;

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Price m_price;
    Filter::Relation m_relation;
};

//----------------------------------------------------------------------------------------------------

/**
 * For the instrument with the specified instrument venue identifier,
 * BestPriceByAskFilter provides
 *  	- best ask volume
 *  	- best ask trend
 *  	- best bid trend
 * for the given price and Filter::Relation.
 */
class STRATEGY_EXPORT BestPriceByAskFilter : public BestPriceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to provide
     *      - best ask volume
     *      - best ask trend
     *      - best bid trend
     * for the price and Filter::Relation as specified in the
     * input parameters.
     *
     * @param price                Instance of Price to know the best ask.
     * @param relation             If its value is set to Filter::EQ (Equal), it will
                                   filter the best ask having price = price specified
                                   as the input parameter.
     */
    BestPriceByAskFilter(const Price & price, const Filter::Relation & relation);
    BestPriceByAskFilter(const BestPriceByAskFilter & filter) = default;
    BestPriceByAskFilter & operator=(const BestPriceByAskFilter & filter) = default;

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Price m_price;
    Filter::Relation m_relation;
};

//----------------------------------------------------------------------------------------------------

/**
 * For the instrument with the specified instrument venue identifier,
 * BestPriceByBidVolumeFilter provides
 *  	- best bid price
 *  	- best bid trend
 *  	- best ask trend
 * for the given volume and Filter::Relation.
 */
class STRATEGY_EXPORT BestPriceByBidVolumeFilter : public BestPriceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to provide
     *      - best bid price
     *      - best bid trend
     *      - best ask trend
     * for the volume and Filter::Relation as specified in the
     * input parameters.
     *
     * @param volume               Instance of Volume to know the best bid volume.
     * @param relation             If its value is set to Filter::EQ (Equal), it will
                                   filter the best bid having volume = volume specified
                                   as the input parameter.
     */
    BestPriceByBidVolumeFilter(const Volume & volume, const Filter::Relation & relation);
    BestPriceByBidVolumeFilter(const BestPriceByBidVolumeFilter & filter) = default;
    BestPriceByBidVolumeFilter & operator=(const BestPriceByBidVolumeFilter & filter) = default;

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Volume m_volume;
    Filter::Relation m_relation;
};

//----------------------------------------------------------------------------------------------------

/**
 * For the instrument with the specified instrument venue identifier,
 * BestPriceByAskVolumeFilter provides
 *  	- best ask price
 *  	- best ask trend
 *  	- best bid trend
 * for the given volume and Filter::Relation.
 */
class STRATEGY_EXPORT BestPriceByAskVolumeFilter : public BestPriceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to provide
     *      - best ask price
     *      - best ask trend
     *      - best bid trend
     * for the volume and Filter::Relation as specified in the
     * input parameters.
     *
     * @param volume               Instance of Volume to know the best ask volume.
     * @param relation             If its value is set to Filter::EQ (Equal), it will
                                   filter the best ask having volume = volume specified
                                   as the input parameter.
     */
    BestPriceByAskVolumeFilter(const Volume & volume, const Filter::Relation & relation);
    BestPriceByAskVolumeFilter(const BestPriceByAskVolumeFilter & filter) = default;
    BestPriceByAskVolumeFilter & operator=(const BestPriceByAskVolumeFilter & filter) = default;

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Volume m_volume;
    Filter::Relation m_relation;
};
}
