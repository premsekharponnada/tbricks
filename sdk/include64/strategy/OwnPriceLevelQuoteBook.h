#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnPriceLevelQuoteBook
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Value.h"
#include "strategy/Depth.h"

namespace tbricks {

namespace protocol {
class PriceLevelOrderBook;
}

//****************************************************************************
// OwnPriceLevelQuoteBook class
//****************************************************************************
class STRATEGY_EXPORT OwnPriceLevelQuoteBook : public Printable
{
public:
    class Update;
    class Stream;

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    OwnPriceLevelQuoteBook();

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param quote_book                Object to copy from
     */
    OwnPriceLevelQuoteBook(const OwnPriceLevelQuoteBook & quote_book);

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param quote_book                Object to copy from
     * @return                          Updated object
     */
    OwnPriceLevelQuoteBook & operator=(const OwnPriceLevelQuoteBook & quote_book);

    /**
     * Destructor.
     */
    virtual ~OwnPriceLevelQuoteBook() override;

    void Clear();
    bool Empty() const;

public:
    /**
     * Getting depth.
     *
     * Getting the bid and ask Depth objects for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param bid                       The bid Depth for the level
     * @param ask                       The ask Depth for the level
     * @return                          true if at least one of bid or ask had such a depth level
     */
    bool GetDepth(size_t depth, Depth & bid, Depth & ask) const;

    size_t GetBidSideSize() const;

    /**
     * Getting bid depth.
     *
     * Getting the bid Depth object for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param bid                       The bid Depth for the level
     * @return                          true if there was such a level (i.e. if depth < GetBidSideSize() )
     */
    bool GetBidDepth(size_t depth, Depth & bid) const;

    size_t GetAskSideSize() const;

    /**
     * Getting ask depth.
     *
     * Getting the ask Depth object for the specified depth level.
     * If there is no such level, returns false
     *
     * @param depth                     The depth level for which to get the Depth information
     * @param ask                       The ask Depth for the level
     * @return                          true if there was such a level (i.e. if depth < GetAskSideSize() )
     */
    bool GetAskDepth(size_t depth, Depth & ask) const;

    /**
     * Getting the average bid price for the specified volume.
     *
     * Returns the volume-weighted average bid price for the specified volume.
     *
     * @param volume                    The volume for which to calculate the price
     * @return                          The volume-weighted average price.
     *                                  If the volume is not available, the Price will be empty.
     */
    Price GetWeightedBidPrice(const Volume & volume) const;

    /**
     * Getting the average ask price for the specified volume.
     *
     * Returns the volume-weighted average ask price for the specified volume.
     *
     * @param volume                    The volume for which to calculate the price
     * @return                          The volume-weighted average price.
     *                                  If the volume is not available, the Price will be empty.
     */
    Price GetWeightedAskPrice(const Volume & volume) const;

    Volume GetTotalBidVolume() const;
    Volume GetTotalAskVolume() const;

    /**
     * Getting the price, volume, participant volume of bid depth.
     *
     * @param level                     The depth level for which to get the Depth information
     * @param price                     The bid price for level
     * @param volume                    The bid volume for level
     * @param participant_volume        The bid participant volume for level
     * @return                          True if possible to extract prameters from OwnPriceLevelQuoteBook, false
     * otherwise
     */
    bool GetBidLevel(size_t level, Price & price, Volume & volume, Volume & participant_volume) const;

    /**
     * Getting the price, volume, participant volume of ask depth.
     *
     * @param level                     The depth level for which to get the Depth information
     * @param price                     The ask price for level
     * @param volume                    The ask volume for level
     * @param participant_volume        The ask participant volume for level
     * @return                          True if possible to extract prameters from OwnPriceLevelQuoteBook, false
     * otherwise
     */
    bool GetAskLevel(size_t level, Price & price, Volume & volume, Volume & participant_volume) const;

public:
    void Merge(const OwnPriceLevelQuoteBook::Update & update);

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    friend class Stream;
    std::unique_ptr<protocol::PriceLevelOrderBook> m_impl;
};

//****************************************************************************
// OwnPriceLevelQuoteBook::Update class
//****************************************************************************
class STRATEGY_EXPORT OwnPriceLevelQuoteBook::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);

    bool Empty() const;

    /**
     * Get depths from update
     *
     * @params vector of depths          Depths from update would be stored inside vector
     * @return                           true if own price level quotebook contains updated depths
     *                                   false otherwise, for example update is full
     */
    bool GetDepths(std::vector<Depth> & depths) const;

    bool IsFullUpdate() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const override;

public:
    Update(std::shared_ptr<protocol::PriceLevelOrderBook> && msg);

private:
    friend class OwnPriceLevelQuoteBook;
    std::shared_ptr<protocol::PriceLevelOrderBook> m_impl;
};
}
