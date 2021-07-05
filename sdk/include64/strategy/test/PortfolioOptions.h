#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Portfolio Options.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Portfolio.h"

namespace tbricks {

namespace protocol {
class Portfolio;
}

namespace test {

class STRATEGY_EXPORT PortfolioOptions : public Printable
{
public:
    PortfolioOptions();
    PortfolioOptions(const PortfolioOptions & portfolio);

    PortfolioOptions & operator=(const PortfolioOptions & portfolio);

    ~PortfolioOptions();

public:
    bool HasChildPortfolios() const;
    std::vector<PortfolioIdentifier> GetChildPortfolios() const;
    void SetChildPortfolios(const std::vector<PortfolioIdentifier> & ids);

    bool HasCreator() const;
    UserIdentifier GetCreator() const;
    void SetCreator(const UserIdentifier & creator);

    bool HasDeleted() const;
    Boolean GetDeleted() const;
    void SetDeleted(const Boolean & deleted);

    bool HasName() const;
    String GetName() const;
    void SetName(const String & name);

    bool HasOwner() const;
    UserIdentifier GetOwner() const;
    void SetOwner(const UserIdentifier & owner);

    bool HasPortfolioIdentifier() const;
    PortfolioIdentifier GetPortfolioIdentifier() const;
    void SetPortfolioIdentifier(const PortfolioIdentifier & id);

    bool HasPortfolioParameters() const;
    StrategyParameters GetPortfolioParameters() const;
    void SetPortfolioParameters(const StrategyParameters & parameters);

    /**
     * Check expit options for emptiness.
     *
     * @return                          True if expit options is empty, false otherwise.
     */
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

    void Merge(const PortfolioOptions & options);

public:
    const protocol::Portfolio & get_portfolio() const;
    protocol::Portfolio & get_portfolio();

private:
    std::unique_ptr<protocol::Portfolio> m_impl;
};

} // \namespace test

} // \namespace tbricks
