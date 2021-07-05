#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Portfolio
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"
#include "strategy/PortfolioParameters.h"
#include "strategy/stream_filter/PortfolioFilter.h"
#include "strategy/Value.h"
#include "strategy/Set.h"
#include <vector>

namespace tbricks {

namespace strategy {
class PortfolioStreamImpl;
}
namespace protocol {
class Portfolio;
}

/**
 * Portfolio object.
 */
class STRATEGY_EXPORT Portfolio : public Printable
{
public:
    class RequestResult;
    typedef Set<PortfolioIdentifier> Identifiers;
    typedef Value<Identifiers> IdentifiersValue;

public:
    class Options;
    class Update;
    class Modifier;

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    Portfolio();

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param portfolio                 Object to copy from
     */
    Portfolio(const Portfolio & portfolio);

    /**
     * Constructor.
     *
     * Creates new Portfolio instance with specified portfolio
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @param portfolio_id              Portfolio identifier
     */
    Portfolio(const PortfolioIdentifier & identifier);

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param portfolio                 Object to copy from
     * @return                          Updated object
     */
    Portfolio & operator=(const Portfolio & portfolio);

    virtual ~Portfolio();

public:
    /**
     * Resolve portfolio.
     *
     * Synchronously fetches full description of the portfolio
     * identified by the parameter.
     *
     * @param portfolio_id              Portfolio identifier
     *
     * @return                          'true' if portfolio is available,
     *                                  'false' otherwise
     */
    bool Resolve(const PortfolioIdentifier & portfolio_id);

    /**
     * Resolve portfolio identifiers.
     *
     * Synchronously fetches portfolios.
     *
     * @param filter                    Portfolio filter
     * @param portfolios                Vector of portfolio identifiers
     */
    static void Resolve(const PortfolioFilter & filter, std::vector<PortfolioIdentifier> & portfolios);

    /**
     * Get portfolio name.
     *
     * @return                          Portfolio name
     */
    const String & GetName() const;

    /**
     * Get portfolio identifier.
     *
     * Value of this field uniquely identifies the portfolio in the system.
     *
     * @return                          Portfolio identifier
     */
    const PortfolioIdentifier & GetIdentifier() const;

    /**
     * Get creator of an item.
     *
     * @return                          Creator identifier
     */
    const UserIdentifier & GetCreator() const;

    void GetCreator(User & user) const;

    /**
     * Get owner of an item.
     *
     * @return                          Owner identifier
     */
    const UserIdentifier & GetOwner() const;

    void GetOwner(User & user) const;

    /**
     * Check if portfolio is marked as deleted.
     *
     * @return                          Deleted flag
     */
    const Boolean & GetDeleted() const;

    /**
     * Get portfolio identifiers.
     *
     * For summation portfolio, this method returns a set of portfolio
     * identifiers the portfolio consists of. If there are no portfolio
     * identifiers, an empty set returned.
     *
     * @code
     * Portfolio::IdentifiersValue & ids_val = portfolio.GetChildPortfolios();
     * if (!ids_val.Empty()) {
     *     // process summation portfolio
     *     Portfolio::Identifiers::iterator it = ids_val->begin();
     *     for( ; it != ids_val->end(); ++it) {
     *         PortfolioIdentifier curr = *it;
     *         // process child portfolio
     *     }
     * } else {
     *     // process portfolio
     * }
     * @endcode
     */
    const IdentifiersValue & GetChildPortfolios() const;

    /**
     * Get portfolio parameters
     *
     * @return                          Portfolio parameter container.
     */
    const PortfolioParameters & GetParameters() const;

    bool Empty() const;
    void Clear();

    /**
     * Merge portfolio changes.
     *
     * Updates container data with values from the argument.
     *
     * @param update                Parameter delta change
     */
    void Merge(const Update & update);

    virtual std::ostream & Print(std::ostream & strm) const;

public:
    static RequestResult SendCreateRequest(const Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    static RequestResult SendDeleteRequest(const PortfolioIdentifier & identifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Do position reset.
     *
     * @param identifier           reset only specified portfolio, if empty or Total then
     *                             reset each non-deleted portfolio.
     */
    static Identifier SendPositionResetRequest(const PortfolioIdentifier & identifier,
                                               IRequestReplyHandler & handler = IRequestReplyHandler::Default());

protected:
    void initialize(const protocol::Portfolio & portfolio);

private:
    PortfolioIdentifier m_identifier;

    String m_name;
    UserIdentifier m_creator;
    UserIdentifier m_owner;
    Boolean m_deleted;
    IdentifiersValue m_ids;
    PortfolioParameters m_parameters;
};

/**
 * Portfolio::RequestResult object.
 */
class STRATEGY_EXPORT Portfolio::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const PortfolioIdentifier & portfolio_identifier);

    const Identifier & GetRequestIdentifier() const;
    const PortfolioIdentifier & GetPortfolioIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    PortfolioIdentifier m_portfolio_identifier;
};

/**
 * A portfolio is a grouping of financial assets such as stocks,
 * bonds and cash equivalents, as well as their funds counterparts,
 * including mutual, exchange-traded and closed funds.
 *
 * Portfolio::Options allows us to create portfolio by setting various parameters
 * and properties of portfolio.
 * SendCreateRequest method of Portfolio is to create portfolio.
 *
 */
class STRATEGY_EXPORT Portfolio::Options : public Printable
{
    friend class Portfolio;

public:
    /// Default constructor
    Options();
    Options(const Options & options);
    Options & operator=(const Options & options);
    virtual ~Options();

public:
    /**
     * %Set the portfolio name.
     *
     * @param name              Instance of String.
     *                          Portfolio name.
     */
    void SetName(const String & name);

    /**
     * Get the portfolio name.
     *
     * @return                  const Portfolio name
     */
    const String & GetName() const;

    /**
     * Get the portofolio name.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @retrun                  Portfolio name
     */
    [[deprecated(DEPRECATE_LINK)]] String & GetName();

    /**
     * %Set the child portolfios for the portfolio.
     * One or more child portfolios can be set using this method.
     *
     * @param ids               Child portfolio identifiers
     */
    void SetPortfolioIdentifiers(const Portfolio::IdentifiersValue & ids);

    /**
     * Get the child portfolios of the portfolio.
     *
     * @return                  Child portoflios identifiers.
     *                          const Portfolio IdentifiersValue.
     */
    const Portfolio::IdentifiersValue & GetChildPortfolios() const;

    /**
     * Get the child portfolios of the portfolio.
     *
     * @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
     *
     * @return                  Child portoflios identifiers.
     */
    [[deprecated(DEPRECATE_LINK)]] Portfolio::IdentifiersValue & GetChildPortfolios();

    /**
     * %Set the portfolio parameters and its value.
     * Setting the value of a key to 'nil' is semantically equivalent to removing it.
     *
     * @param def               Instance of PortfolioParameterDefinition
     *                          Portfolio parameter.
     *
     * @param value             Instance of AnyType.
     *                          portfolio parmeter value.
     */
    void SetParameter(const PortfolioParameterDefinition & def, const AnyType & value);

    /**
     * Get the portfolio parameter value by providing
     * the specific portfolio parameter definition.
     * Pass the key that is PortfolioParameterDefinition to get the
     * value of that key.
     * This method will return true if the specified parameter is
     * set on the portfolio, false otherwise.
     *
     * @param def               Instance of PortfolioParameterDefinition
     *                          to specify the portoflio parameter.
     *
     * @param value             Value of the set portfolio parameter will
     *                          be returned in this parameter.
     *
     * @return                  True if the specified portfolio parameter is
     *                          set on the portolfio, false otherwise
     */
    bool GetParameter(const PortfolioParameterDefinition & def, AnyType & value) const;

    /**
     * Get the portfolio parameter value by providing
     * the specific portfolio parameter Uuid.
     * Pass the key that is parameter uuid to get the
     * value of that key.
     * This method will return true if the specified parameter is
     * set on the portfolio, false otherwise.
     *
     * @param def               Instance of Uuid
     *                          to specify the portoflio parameter.
     *
     * @param value             Value of the set portfolio parameter will
     *                          be returned in this parameter.
     *
     * @return                  True if the specified portfolio parameter is
     *                          set on the portolfio, false otherwise
     */
    bool GetParameter(const Uuid & identifier, AnyType & value) const;

public:
    void Clear();
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    String m_name;
    Portfolio::IdentifiersValue m_ids;
    PortfolioParameters m_parameters;
};

/**
 * Portfolio::Update object.
 */
class STRATEGY_EXPORT Portfolio::Update : public Printable
{
    friend class strategy::PortfolioStreamImpl;

public:
    Update();
    Update(const Update & obj);
    Update & operator=(const Update & obj);
    virtual ~Update();

public:
    const PortfolioIdentifier & GetIdentifier() const;
    const String & GetName() const;
    const Boolean & GetDeleted() const;

    /**
     * Check if child portfolios field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasChildPortfolios() const;

    /**
     * Get child portfolios
     *
     * If HasChildPortfolios() returns true and return value is empty,
     * child portfolios were removed.
     *
     * @return                          child portfolios if exist, <empty> otherwise
     */
    const Portfolio::Identifiers & GetChildPortfolios() const;

    const PortfolioParameters & GetParameters() const;

    /**
     * Get portfolio owner
     *
     * @return                          Owner identifier
     */
    const UserIdentifier & GetOwner() const;

    /**
     * Get portfolio creator
     *
     * @return                          Creator identifier
     */
    const UserIdentifier & GetCreator() const;

    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

public:
    Update(const protocol::Portfolio & portfolio);

private:
    PortfolioIdentifier m_identifier;

    String m_name;
    Boolean m_deleted;
    Portfolio::IdentifiersValue m_ids;
    PortfolioParameters m_parameters;
    UserIdentifier m_creator;
    UserIdentifier m_owner;
};

/**
 * Portfolio::Modifier object.
 */
class STRATEGY_EXPORT Portfolio::Modifier : public Printable
{
    friend class Portfolio;

public:
    Modifier(const PortfolioIdentifier & identifier);
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    virtual ~Modifier();

public:
    const PortfolioIdentifier & GetIdentifier() const;

    void SetName(const String & name);
    const String & GetName() const;

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] String & GetName();

    void SetDeleted(const Boolean & deleted);
    const Boolean & GetDeleted() const;

    void SetPortfolioIdentifiers(const Portfolio::IdentifiersValue & ids);
    const Portfolio::IdentifiersValue & GetChildPortfolios() const;

    /// @deprecated Deprecated in 2.14.0 use 'Set*()' and 'const Get*()' functions instead.
    [[deprecated(DEPRECATE_LINK)]] Portfolio::IdentifiersValue & GetChildPortfolios();

    void SetParameter(const PortfolioParameterDefinition & def, const AnyType & value);

    bool GetParameter(const PortfolioParameterDefinition & def, AnyType & value) const;
    bool GetParameter(const Uuid & identifier, AnyType & value) const;

public:
    void Clear();
    bool Empty() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    PortfolioIdentifier m_identifier;

    String m_name;
    Boolean m_deleted;
    Portfolio::IdentifiersValue m_ids;
    PortfolioParameters m_parameters;
};
}
