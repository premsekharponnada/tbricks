#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Ranking parameters container
//****************************************************************************************

#include <string>
#include <map>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Hash.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"

#include <memory>

// \namespace tbricks
namespace tbricks {

namespace types {
class TradeParameters;
}

class RankingIdentifier;
class TradeParameterDefinition;

/**
 * TradeParameters class is a simple container of ranking parameters,
 *
 */
class STRATEGY_EXPORT TradeParameters : public Printable
{
public:
    TradeParameters();
    TradeParameters(const TradeParameters & parameters);
    TradeParameters(TradeParameters && parameters);
    TradeParameters(const types::TradeParameters & parameters);
    TradeParameters(types::TradeParameters && parameters);
    virtual ~TradeParameters();

    TradeParameters & operator=(const TradeParameters & parameters);
    TradeParameters & operator=(TradeParameters && parameters);

public:
    /**
     * Fetch parameter value from the parameter container.
     *
     * @param rank                      Rank identifier
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const RankingIdentifier & rank, const TradeParameterDefinition & definition, AnyType & value) const;

    bool GetParameter(const RankingIdentifier & rank, const TradeParameterDefinition & definition, Variant & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param rank                      Rank identifier
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const RankingIdentifier & rank, const TradeParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a non-empty value for the key.
     *
     * Method returns 'true' if and only if container has a value for the
     * provided parameter definition and the value is not empty.
     *
     * @param rank                      Rank identifier
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const RankingIdentifier & rank, const TradeParameterDefinition & definition) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;

    /**
     * Clear container data.
     *
     * After this call container is guaranteed to contain no data, and Empty()
     * method will return True if called.
     */
    void Clear();

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const TradeParameters & parameters);

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
        friend class TradeParameters;

    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator();
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        bool Empty() const;

    public:
        RankingIdentifier GetRanking() const;

        void GetRankingParameters(Hash<TradeParameterDefinition, Variant> & parameters) const;
        bool GetParameter(const TradeParameterDefinition & definition, AnyType & value) const;
        bool GetParameter(const TradeParameterDefinition & definition, Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        const_iterator(const tbricks::types::TradeParameters & parameters, int pos);

    private:
        struct Impl;
        std::unique_ptr<Impl> m_p_impl;
    };

    const_iterator begin() const;
    const_iterator end() const;

    const tbricks::types::TradeParameters & get_parameters() const;

private:
    struct Impl;
    std::unique_ptr<Impl> m_p_impl;
};

} // \namespace tbricks
