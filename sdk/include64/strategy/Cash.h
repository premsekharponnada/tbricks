#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Cash object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include <memory>

#include "strategy/User.h"
#include "strategy/Types.h"
#include "strategy/Strategy.h"

namespace tbricks {

class Trade;

namespace protocol {
class Cash;
class CashModifyRequest;
}

namespace visualization {
class CashRowEntityImpl;
}

class StrategyData;

class STRATEGY_EXPORT Cash : public Printable
{
public:
    enum AggregationType
    {
        AGGREGATION_TYPE_BY_CURRENCY = 1,
        AGGREGATION_TYPE_BY_CURRENCY_AND_TYPE = 2,
        AGGREGATION_TYPE_EMPTY = 3,
        AGGREGATION_TYPE_BY_CURRENCY_AND_INSTRUMENT = 4,
        AGGREGATION_TYPE_BY_CURRENCY_AND_SETTLEMENT = 5,
        AGGREGATION_TYPE_BY_CURRENCY_AND_INSTRUMENT_AND_SETTLEMENT = 6
    };

    enum AggregationKey
    {
        AGGREGATION_KEY_CURRENCY = 13,
        AGGREGATION_KEY_CASH_TYPE = 1190,
        AGGREGATION_KEY_INSTRUMENT = 65,
        AGGREGATION_KEY_SETTLEMENT_DATE = 155,
        AGGREGATION_KEY_PORTFOLIO = 122,
        AGGREGATION_KEY_CLIENT = 1611
    };

    /**
     *  A cash position definition.
     */
    enum CashType
    {
        CASH_TYPE_UNKNOWN = 0,
        CASH_TYPE_DIVIDEND = 1,      /**< Dividend payout from equity instrument. */
        CASH_TYPE_FEE = 2,           /**< Fee received or paid. */
        CASH_TYPE_MARGIN = 3,        /**< Margin deposit. */
        CASH_TYPE_CASH_DELIVERY = 4, /**< The cash position is due to a cash delivery of e.g. an option. Cash entries of this type will usually have
                                        instrument/strategy identifier fields populated. */
        CASH_TYPE_FINANCING = 5,     /**< Proceeds from financing position or cash balance. */
        CASH_TYPE_DEPOSIT_OR_WITHDRAWAL = 6, /**< A deposit or withdrawal of money into/from the portfolio. The sign of the volume signifies which. */
        CASH_TYPE_CORRECTION = 7,            /**< A manual correction of the portfolios cash position. */
        CASH_TYPE_FX = 8,                    /**< Exchange cash position. */
        CASH_TYPE_POSITION_ADJUSTMENT = 9,   /**< Change in cash balance driven by external system. */
        CASH_TYPE_COUPON = 10,               /**< Coupon payout from fixed income instrument. */
        CASH_TYPE_LENDING = 11               /**< Proceeds from lending a security. */
    };

public:
    class Options;
    class Modifier;
    class Update;
    class Stream;

public:
    class RequestResult;

public:
    Cash();
    Cash(const Cash & cash);
    Cash(Cash && cash) noexcept;
    Cash & operator=(const Cash & cash);
    Cash & operator=(Cash && cash) noexcept;
    virtual ~Cash();

    Identifier GetRequestIdentifier() const;
    bool HasRequestIdentifier() const;

    Identifier GetIdentifier() const;
    bool HasIdentifier() const;

    PortfolioIdentifier GetPortfolioIdentifier() const;
    bool HasPortfolioIdentifier() const;

    UserIdentifier GetCreator() const;
    void GetCreator(User & user) const;
    bool HasCreator() const;

    TreeNodeIdentifier GetClient() const;
    bool HasClient() const;

    AggregationType GetAggregationType() const;
    bool HasAggregationType() const;

    CashType GetType() const;
    bool HasType() const;

    DateTime GetHostCreatedDatetime() const;
    bool HasHostCreatedDatetime() const;

    DateTime GetCashDatetime() const;
    bool HasCashDatetime() const;

    DateTime GetSettlementDate() const;
    bool HasSettlementDate() const;

    DateTime GetHostModifiedDatetime() const;
    bool HasHostModifiedDatetime() const;

    Double GetCashValue() const;
    bool HasCashValue() const;

    Double GetCashValueDaily() const;
    bool HasCashValueDaily() const;

    Double GetCashValueMonthly() const;
    bool HasCashValueMonthly() const;

    Double GetCashValueYearly() const;
    bool HasCashValueYearly() const;

    Currency GetCurrency() const;
    bool HasCurrency() const;

    Identifier GetExpirationIdentifier() const;
    bool HasExpirationIdentifier() const;

    StrategyIdentifier GetStrategyIdentifier() const;
    bool HasStrategyIdentifier() const;

    InstrumentIdentifier GetInstrumentIdentifier() const;
    bool HasInstrumentIdentifier() const;

    String GetDescription() const;
    bool HasDescription() const;

    Boolean GetDeleted() const;
    bool HasDeleted() const;

    ExtraData GetExtraData() const;
    bool HasExtraData() const;

    /**
     * Get root strategy identifier.
     *
     * @return                          Strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;
    bool HasRootStrategyIdentifier() const;

    /**
     * Get strategy identifier path.
     *
     * Returns a vector of strategy identifiers that describe the path of
     * strategies used to create this entity starting from the root strategy
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyPath(std::vector<StrategyIdentifier> & path) const;
    bool HasStrategyPath() const;

    /**
     * Get strategy definition identifier path.
     *
     * Returns a vector of strategy definition identifiers that describe the path of
     * strategie types used to create this entity starting from the root strategy
     * definition identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;
    bool HasStrategyDefinitionPath() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasBusinessDate() const;

    /**
     * Get business date.
     *
     * @return                          Date
     */
    Date GetBusinessDate() const;

    void Merge(const Cash::Update & cash);

    void Clear();
    bool Empty() const;

public:
    static RequestResult SendCreateRequest(const Cash::Options & options, IRequestReplyHandler & handler);
    static RequestResult SendModifyRequest(const Cash::Modifier & modifier, IRequestReplyHandler & handler);

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;
    friend STRATEGY_EXPORT class Cash::Options;

    friend STRATEGY_EXPORT class visualization::CashRowEntityImpl;
    const protocol::Cash * get_cash() const { return m_msg.get(); }

private:
    std::unique_ptr<protocol::Cash> m_msg;
};

//****************************************************************************
// RequestResult class
//****************************************************************************
class STRATEGY_EXPORT Cash::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const Identifier & cash_identifier);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetCashIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_cash_identifier;
};

//****************************************************************************
// Cash::Update class
//****************************************************************************
class STRATEGY_EXPORT Cash::Update : public Printable
{
public:
    Update();
    Update(const Update & update);
    Update(Update && update) noexcept;
    Update(const std::shared_ptr<protocol::Cash> & update);

    virtual ~Update();

    Update & operator=(const Update & update);
    Update & operator=(Update && update) noexcept;

    Identifier GetRequestIdentifier() const;
    bool HasRequestIdentifier() const;

    Identifier GetIdentifier() const;
    bool HasIdentifier() const;

    PortfolioIdentifier GetPortfolioIdentifier() const;
    bool HasPortfolioIdentifier() const;

    UserIdentifier GetCreator() const;
    void GetCreator(User & user) const;
    bool HasCreator() const;

    TreeNodeIdentifier GetClient() const;
    bool HasClient() const;

    AggregationType GetAggregationType() const;
    bool HasAggregationType() const;

    CashType GetType() const;
    bool HasType() const;

    DateTime GetHostCreatedDatetime() const;
    bool HasHostCreatedDatetime() const;

    DateTime GetCashDatetime() const;
    bool HasCashDatetime() const;

    DateTime GetSettlementDate() const;
    bool HasSettlementDate() const;

    DateTime GetHostModifiedDatetime() const;
    bool HasHostModifiedDatetime() const;

    Double GetCashValue() const;
    bool HasCashValue() const;

    Double GetCashValueDaily() const;
    bool HasCashValueDaily() const;

    Double GetCashValueMonthly() const;
    bool HasCashValueMonthly() const;

    Double GetCashValueYearly() const;
    bool HasCashValueYearly() const;

    Currency GetCurrency() const;
    bool HasCurrency() const;

    Identifier GetExpirationIdentifier() const;
    bool HasExpirationIdentifier() const;

    StrategyIdentifier GetStrategyIdentifier() const;
    bool HasStrategyIdentifier() const;

    InstrumentIdentifier GetInstrumentIdentifier() const;
    bool HasInstrumentIdentifier() const;

    String GetDescription() const;
    bool HasDescription() const;

    Boolean GetDeleted() const;
    bool HasDeleted() const;

    ExtraData GetExtraData() const;
    bool HasExtraData() const;

    StrategyIdentifier GetOperatingStrategyIdentifier() const;
    bool HasOperatingStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     * @return                          Strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;
    bool HasRootStrategyIdentifier() const;

    /**
     * Get strategy identifier path.
     *
     * Returns a vector of strategy identifiers that describe the path of
     * strategies used to create this entity starting from the root strategy
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyPath(std::vector<StrategyIdentifier> & path) const;
    bool HasStrategyPath() const;

    /**
     * Get strategy definition identifier path.
     *
     * Returns a vector of strategy definition identifiers that describe the path of
     * strategie types used to create this entity starting from the root strategy
     * definition identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;
    bool HasStrategyDefinitionPath() const;

    /**
     * Check if field is set.
     *
     * @return                          "true" if field is set, "false"
     *                                  otherwise
     */
    bool HasBusinessDate() const;

    /**
     * Get business date.
     *
     * @return                          Date
     */
    Date GetBusinessDate() const;

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class tbricks::Cash;

private:
    std::unique_ptr<protocol::Cash> m_msg;
};

/**
 * Cash::Options class allows to create a cash position definition.
 * The expiration identifier is only set for cash positions directly resulting
 * from an expiration action.
 */
class STRATEGY_EXPORT Cash::Options : public Printable
{
public:
    /// Default constructor.
    Options();
    Options(const Options & options);
    Options(Options && options) noexcept;

    virtual ~Options();

    Options & operator=(const Options & options);
    Options & operator=(Options && options) noexcept;

    /**
     * %Set portfolio of the cash.
     *
     * @param portfolio_identifier  Instance of PortfolioIdentifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);

    /**
     * Get portfolio identifier of the cash.
     *
     * @return                      PortfolioIdentifier set on the cash.
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * Check if portofolio is set on the cash.
     *
     * @return                      true if portfolio is set, false otherwise.
     */
    bool HasPortfolioIdentifier() const;

    /**
     * %Set the creator of the cash using UserIdentifier.
     *
     * @param user_identifier       Instance of UserIdentifier
     */
    void SetCreator(const UserIdentifier & user_identifier);

    /**
     * %Set the creator of the cash.
     *
     * @param user                  Instance of User
     */
    void SetCreator(const User & user);

    /**
     * Get the cash creator.
     *
     * @return                      Instance of User
     */
    UserIdentifier GetCreator() const;

    /**
     * Get the cash creator.
     *
     * @param user                  Instance of User
     */
    void GetCreator(User & user) const;

    /**
     * Check if creator is set on the cash.
     *
     * @return                      true if creator is set, false otherwise.
     */
    bool HasCreator() const;

    /**
     * %Set the client of the cash.
     *
     * @param treenode_identifier   Instance of TreeNodeIdentifier
     *                              to set client of the cash.
     */
    void SetClient(const TreeNodeIdentifier & treenode_identifier);

    /**
     * Get client of the cash.
     *
     * @return                      TreeNodeIdentifier of the client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * Check if client is set on the cash.
     *
     * @return                      true if client is set, false otherwise.
     */
    bool HasClient() const;

    /**
     * %Set Cash aggregation type.
     * AggregationType is an enumeration in Cash class.
     *
     * @param aggregation_type      Value of type AggregationType enumeration.
     */
    void SetAggregationType(const AggregationType & aggregation_type);

    /**
     * Get the  aggregation type of the cash.
     *
     * @return                      Value of type AggregationType enumeration.
     */
    AggregationType GetAggregationType() const;

    /**
     * Check if aggregation type is set on the cash.
     *
     * @return                      true if aggregation type is set, false otherwise.
     */
    bool HasAggregationType() const;

    /**
     * %Set Cash type.
     *
     * @param cash_type             Value of type CashType enumeration.
     */
    void SetType(const CashType & cash_type);

    /**
     * Get the type of the cash.
     *
     * @return                      Value of type CashType enumeration.
     */
    CashType GetType() const;

    /**
     * Check if cash type is set on the cash.
     *
     * @return                      true if cash type is set, false otherwise.
     */
    bool HasType() const;

    /**
     * %Set cash creation date time.
     *
     * @param host_created_datetime Instance of DateTime
     */
    void SetCashDatetime(const DateTime & host_created_datetime);

    /**
     * Get the cash creation date time.
     *
     * @return                      Cash created date time.
     */
    DateTime GetCashDatetime() const;

    /**
     * Check if cash creation date time is set on the cash.
     *
     * @return                      true if cash creation date time is set, false otherwise.
     */
    bool HasCashDatetime() const;

    /**
     * %Set cash settlement date.
     *
     * @param settlement_datetime   Instance of DateTime
     */
    void SetSettlementDate(const DateTime & settlement_datetime);

    /**
     * Get the cash creation date time.
     *
     * @return                      Cash created date time.
     */
    DateTime GetSettlementDate() const;

    /**
     * Check if cash settlement date time is set on the cash.
     *
     * @return                      true if cash settlement date time is set, false otherwise.
     */
    bool HasSettlementDate() const;

    /**
     * %Set cash value.
     *
     * @param cash_value            Instance of Double.
     */
    void SetCashValue(const Double & cash_value);

    /**
     * Get the cash value.
     *
     * @return                      Cash value.
     */
    Double GetCashValue() const;

    /**
     * Check if cash value is set on the cash.
     *
     * @return                      true if cash value is set, false otherwise.
     */
    bool HasCashValue() const;

    /**
     * %Set the currency of the cash.
     *
     * @param currency              Instance of Currency
     */
    void SetCurrency(const Currency & currency);

    /**
     * Get cash currency.
     *
     * @return                      Cash currency
     */
    Currency GetCurrency() const;

    /**
     * Check if cash currency is set on the cash.
     *
     * @return                      true if cash currency is set, false otherwise.
     */
    bool HasCurrency() const;

    /**
     * %Set the expiration of cash.
     * A unique identifier for a given expiration entry,
     * used to tag up cash positions and trades resulting from an expiration process.
     *
     * @param expiration_identifier Identifier of the Expiration.
     */
    void SetExpirationIdentifier(const Identifier & expiration_identifier);

    /**
     * Get the cash expiration.
     *
     * @return                      Identifier of the Expiration.
     */
    Identifier GetExpirationIdentifier() const;

    /**
     * Check if cash expiration is set on the cash.
     *
     * @return                      true if cash expiration is set, false otherwise.
     */
    bool HasExpirationIdentifier() const;

    /**
     * %Set the cash instrument identifier.
     *
     * @param instrument_identifier Instance of InstrumentIdentifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & instrument_identifier);

    /**
     * Get the cash instrument identifier.
     *
     * @return                      InstrumentIdentifier of the cash.
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * Check if cash instrument identifier is set on the cash.
     *
     * @return                      true if cash instrument identifier is set, false otherwise.
     */
    bool HasInstrumentIdentifier() const;

    /**
     * %Set description of the cash.
     *
     * @param description           Instance of String. Description of cash.
     */
    void SetDescription(const String & description);

    /**
     * Get the cash description.
     *
     * @return                      cash description
     */
    String GetDescription() const;

    /**
     * Check if cash description is set on the cash.
     *
     * @return                      true if cash description is set, false otherwise.
     */
    bool HasDescription() const;

    /**
     * %Set the cash extra data.
     *
     * @param data                  Instance of ExtraData
     */
    void SetExtraData(const ExtraData & data);

    /**
     * Get the cash extra data.
     *
     * @return                      cash extra data
     */
    ExtraData GetExtraData() const;

    /**
     * Check if cash extra data is set on the cash.
     *
     * @return                      true if cash extra data is set, false otherwise.
     */
    bool HasExtraData() const;

    /**
     * Set strategy identifier, root strategy identifier,
     * strategy path, strategy definition path fields.
     *
     * @param value                     Cash
     */
    void SetParentApp(const Trade & value);

    /**
     * Set strategy identifier, root strategy identifier,
     * strategy path, strategy definition path fields.
     *
     * @param value                     Strategy data
     */
    void SetParentApp(const StrategyData & value);

    /**
     * %Set strategy identifier.
     *
     * @deprecated use SetParentApp method instead.
     *             Deprecated in 2.11.0, will be deleted in 2.12.0
     *
     * @param id                        Strategy identifier
     */
    [[deprecated(DEPRECATE_LINK)]] void SetStrategyIdentifier(const StrategyIdentifier & strategy_identifier);

    /**
     * Get cash strategy identifier.
     *
     * @return			cash strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * Check if strategy identifier is set on the cash.
     *
     * @return			 true if cash strategy identifier is set, false otherwise.
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     * @return                          Strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * Check if root strategy identifier is set on the cash.
     *
     * @return			 true if root strategy identifier is set, false otherwise.
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get strategy identifier path.
     *
     * Returns a vector of strategy identifiers that describe the path of
     * strategies used to create this entity starting from the root strategy
     * identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Check if strategy path is set on the cash.
     *
     * @return			 true if strategy path is set, false otherwise.
     */
    bool HasStrategyPath() const;

    /**
     * Get strategy definition identifier path.
     *
     * Returns a vector of strategy definition identifiers that describe the path of
     * strategies types used to create this entity starting from the root strategy
     * definition identifier.
     *
     * @param path                      vector of StrategyIdentifier
     *
     * @return                          True if field is exist, otherwise false
     */
    bool GetStrategyDefinitionPath(std::vector<StrategyIdentifier> & path) const;

    /**
     * Check if strategy definition identifier path is set on the cash.
     *
     * @return			 true if  strategy definition identifier path is set, false otherwise.
     */
    bool HasStrategyDefinitionPath() const;

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class tbricks::Cash;

private:
    std::unique_ptr<protocol::Cash> m_msg;
};

//****************************************************************************
// Cash::Modifier class
//****************************************************************************
class STRATEGY_EXPORT Cash::Modifier : public Printable
{
public:
    Modifier(const Identifier & id);
    Modifier(const Modifier & modifier);
    Modifier(Modifier && modifier) noexcept;

    virtual ~Modifier();

    Modifier & operator=(const Modifier & modifier);
    Modifier & operator=(Modifier && modifier) noexcept;

    Identifier GetCashIdentifier() const;

    void SetPortfolioIdentifier(const PortfolioIdentifier & portfolio_identifier);
    PortfolioIdentifier GetPortfolioIdentifier() const;
    bool HasPortfolioIdentifier() const;

    void SetCashDatetime(const DateTime & host_created_datetime);
    DateTime GetCashDatetime() const;
    bool HasCashDatetime() const;

    void SetSettlementDate(const DateTime & settlement_datetime);
    DateTime GetSettlementDate() const;
    bool HasSettlementDate() const;

    void SetCashValue(const Double & cash_value);
    Double GetCashValue() const;
    bool HasCashValue() const;

    void SetCurrency(const Currency & currency);
    Currency GetCurrency() const;
    bool HasCurrency() const;

    void SetDeleted(const Boolean & is_deleted);
    Boolean GetDeleted() const;
    bool HasDeleted() const;

    void SetInstrumentIdentifier(const InstrumentIdentifier & instrument_identifier);
    InstrumentIdentifier GetInstrumentIdentifier() const;
    Value<InstrumentIdentifier> GetInstrumentIdentifierValue() const;
    bool HasInstrumentIdentifier() const;

    void SetDescription(const String & description);
    String GetDescription() const;
    bool HasDescription() const;

    void SetExtraData(const ExtraData & data);
    ExtraData GetExtraData() const;
    bool HasExtraData() const;

    void Clear();
    bool Empty() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class tbricks::Cash;

private:
    std::unique_ptr<protocol::CashModifyRequest> m_msg;
};
}
