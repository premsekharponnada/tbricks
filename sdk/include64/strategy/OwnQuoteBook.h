#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// OwnQuoteBook
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Value.h"
#include "strategy/Depth.h"
#include "strategy/SparseHash.h"
#include "strategy/type/OwnQuoteBookType.h"
#include "strategy/type/OwnQuoteBookSource.h"

namespace tbricks {

namespace protocol {
class OrderBook;
}

//****************************************************************************
// OwnQuoteBook class
//****************************************************************************
class STRATEGY_EXPORT OwnQuoteBook : public Printable
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
    OwnQuoteBook();

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param order_book                Object to copy from
     */
    OwnQuoteBook(const OwnQuoteBook & order_book);

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param order_book                Object to copy from
     * @return                          Updated object
     */
    OwnQuoteBook & operator=(const OwnQuoteBook & order_book);
    virtual ~OwnQuoteBook();

    void Clear();
    bool Empty() const;

public:
    /**
     * OwnQuoteBookType enum, used for setting options for OwnQuoteBook::Stream stream.
     * @deprecated Deprecated in 2.14.0, use tbricks::OwnQuoteBookType instead.
     */
    enum [[deprecated(DEPRECATE_LINK)]] OwnQuoteBookType
    {
        OwnQuoteBookTypeOrder = static_cast<int>(tbricks::OwnQuoteBookType::ORDER),
        OwnQuoteBookTypeOrderAndQuote = static_cast<int>(tbricks::OwnQuoteBookType::ORDER_AND_QUOTE),
        OwnQuoteBookTypeQuote = static_cast<int>(tbricks::OwnQuoteBookType::QUOTE),
        OwnQuoteBookTypeQuoteDesired = static_cast<int>(tbricks::OwnQuoteBookType::QUOTE_DESIRED)
    };

    /**
     * OwnQuoteBookSource enum, used for setting options for OwnQuoteBook::Stream stream.
     * @deprecated Deprecated in 2.14.0, use tbricks::OwnQuoteBookSource instead.
     */
    enum [[deprecated(DEPRECATE_LINK)]] OwnQuoteBookSource
    {
        OwnQuoteBookSourceQuoting = static_cast<int>(tbricks::OwnQuoteBookSource::QUOTING),
        OwnQuoteBookSourceMultiLevel = static_cast<int>(tbricks::OwnQuoteBookSource::QUOTING_MULTILEVEL),
        OwnQuoteBookSourceHidden = static_cast<int>(tbricks::OwnQuoteBookSource::HIDDEN),
        OwnQuoteBookSourcePeg = static_cast<int>(tbricks::OwnQuoteBookSource::PEG),
        OwnQuoteBookSourceResponder = static_cast<int>(tbricks::OwnQuoteBookSource::QUOTE_RESPONDER)
    };

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

private:
    friend STRATEGY_EXPORT class DepthComparator;

public:
    void Merge(const OwnQuoteBook::Update & update);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void DeleteDepth(const Integer & id);

private:
    std::vector<Integer> m_bid;
    std::vector<Integer> m_ask;
    SparseHash<Integer, size_t> m_indexes;
    SparseHash<Integer, Depth> m_depths;
};

//****************************************************************************
// OwnQuoteBook::Update class
//****************************************************************************
class STRATEGY_EXPORT OwnQuoteBook::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update & operator=(const Update & update);
    virtual ~Update();

    bool Empty() const;

    const std::vector<Depth> & GetDepths() const;

    bool IsFullUpdate() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    Update(std::shared_ptr<protocol::OrderBook> && msg);

private:
    bool m_full_update;
    std::vector<Depth> m_depths;
};

} // namespace tbricks {
