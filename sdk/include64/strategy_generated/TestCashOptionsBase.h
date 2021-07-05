#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestCashOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class Currency;
class DateTime;
class Double;
class ExtraData;
class Identifier;
class InstrumentIdentifier;
class PortfolioIdentifier;
class StrategyIdentifier;
class String;
class TreeNodeIdentifier;
class UserIdentifier;
enum class CashPositionAggregationType;
enum class CashPositionType;


namespace protocol { class Cash; }

class STRATEGY_EXPORT TestCashOptionsBase : public Printable
{
protected:
    TestCashOptionsBase();
    TestCashOptionsBase(const TestCashOptionsBase & value);
    TestCashOptionsBase(TestCashOptionsBase && value) noexcept;
    TestCashOptionsBase & operator=(const TestCashOptionsBase & value);
    TestCashOptionsBase & operator=(TestCashOptionsBase && value) noexcept;
    virtual ~TestCashOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestIdentifier() const;

    /**
     * Get request identifier.
     *
     *
     * @return                          request identifier
     */
    Identifier GetRequestIdentifier() const;

    /**
     * %Set request identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     request identifier
     */
    void SetRequestIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashIdentifier() const;

    /**
     * Get cash identifier.
     *
     *
     * @return                          cash identifier
     */
    Identifier GetCashIdentifier() const;

    /**
     * %Set cash identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash identifier
     */
    void SetCashIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPortfolioIdentifier() const;

    /**
     * Get portfolio identifier.
     *
     *
     * @return                          portfolio identifier
     */
    PortfolioIdentifier GetPortfolioIdentifier() const;

    /**
     * %Set portfolio identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     portfolio identifier
     */
    void SetPortfolioIdentifier(const PortfolioIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCreator() const;

    /**
     * Get creator.
     *
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;

    /**
     * %Set creator.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     creator
     */
    void SetCreator(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasClient() const;

    /**
     * Get client.
     *
     *
     * @return                          client
     */
    TreeNodeIdentifier GetClient() const;

    /**
     * %Set client.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     client
     */
    void SetClient(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashPositionAggregationType() const;

    /**
     * Get cash position aggregation type.
     *
     *
     * @return                          cash position aggregation type
     */
    std::optional<CashPositionAggregationType> GetCashPositionAggregationType() const;

    /**
     * %Set cash position aggregation type.
     *
     *
     * @param value                     cash position aggregation type
     */
    void SetCashPositionAggregationType(std::optional<CashPositionAggregationType> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashPositionType() const;

    /**
     * Get cash position type.
     *
     *
     * @return                          cash position type
     */
    std::optional<CashPositionType> GetCashPositionType() const;

    /**
     * %Set cash position type.
     *
     *
     * @param value                     cash position type
     */
    void SetCashPositionType(std::optional<CashPositionType> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashDatetime() const;

    /**
     * Get cash datetime.
     *
     *
     * @return                          cash datetime
     */
    DateTime GetCashDatetime() const;

    /**
     * %Set cash datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash datetime
     */
    void SetCashDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSettlementDate() const;

    /**
     * Get settlement date.
     *
     *
     * @return                          settlement date
     */
    DateTime GetSettlementDate() const;

    /**
     * %Set settlement date.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     settlement date
     */
    void SetSettlementDate(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashValue() const;

    /**
     * Get cash value.
     *
     *
     * @return                          cash value
     */
    Double GetCashValue() const;

    /**
     * %Set cash value.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash value
     */
    void SetCashValue(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashValueDaily() const;

    /**
     * Get cash value daily.
     *
     *
     * @return                          cash value daily
     */
    Double GetCashValueDaily() const;

    /**
     * %Set cash value daily.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash value daily
     */
    void SetCashValueDaily(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashValueMonthly() const;

    /**
     * Get cash value monthly.
     *
     *
     * @return                          cash value monthly
     */
    Double GetCashValueMonthly() const;

    /**
     * %Set cash value monthly.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash value monthly
     */
    void SetCashValueMonthly(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashValueYearly() const;

    /**
     * Get cash value yearly.
     *
     *
     * @return                          cash value yearly
     */
    Double GetCashValueYearly() const;

    /**
     * %Set cash value yearly.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash value yearly
     */
    void SetCashValueYearly(const Double & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCurrency() const;

    /**
     * Get currency.
     *
     *
     * @return                          currency
     */
    Currency GetCurrency() const;

    /**
     * %Set currency.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     currency
     */
    void SetCurrency(const Currency & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationIdentifier() const;

    /**
     * Get expiration identifier.
     *
     *
     * @return                          expiration identifier
     */
    Identifier GetExpirationIdentifier() const;

    /**
     * %Set expiration identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration identifier
     */
    void SetExpirationIdentifier(const Identifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInstrumentIdentifier() const;

    /**
     * Get instrument identifier.
     *
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * %Set instrument identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     instrument identifier
     */
    void SetInstrumentIdentifier(const InstrumentIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifier() const;

    /**
     * Get strategy identifier.
     *
     *
     * @return                          strategy identifier
     */
    StrategyIdentifier GetStrategyIdentifier() const;

    /**
     * %Set strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     strategy identifier
     */
    void SetStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExpirationDeliveryIdentifier() const;

    /**
     * Get expiration delivery identifier.
     *
     *
     * @return                          expiration delivery identifier
     */
    StrategyIdentifier GetExpirationDeliveryIdentifier() const;

    /**
     * %Set expiration delivery identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expiration delivery identifier
     */
    void SetExpirationDeliveryIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRootStrategyIdentifier() const;

    /**
     * Get root strategy identifier.
     *
     *
     * @return                          root strategy identifier
     */
    StrategyIdentifier GetRootStrategyIdentifier() const;

    /**
     * %Set root strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     root strategy identifier
     */
    void SetRootStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyIdentifierPath() const;

    /**
     * Get strategy identifier path.
     *
     *
     * @return                          strategy identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyIdentifierPath() const;

    /**
     * %Set strategy identifier path.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     strategy identifier path
     */
    void SetStrategyIdentifierPath(const std::vector<StrategyIdentifier> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyDefinitionIdentifierPath() const;

    /**
     * Get strategy definition identifier path.
     *
     *
     * @return                          strategy definition identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyDefinitionIdentifierPath() const;

    /**
     * %Set strategy definition identifier path.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     strategy definition identifier path
     */
    void SetStrategyDefinitionIdentifierPath(const std::vector<StrategyIdentifier> & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCashPositionDescription() const;

    /**
     * Get cash position description.
     *
     *
     * @return                          cash position description
     */
    String GetCashPositionDescription() const;

    /**
     * %Set cash position description.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     cash position description
     */
    void SetCashPositionDescription(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * %Set deleted.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;

    /**
     * Get extra data.
     *
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;

    /**
     * %Set extra data.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostCreatedDatetime() const;

    /**
     * Get host created datetime.
     *
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * %Set host created datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host created datetime
     */
    void SetHostCreatedDatetime(const DateTime & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostModifiedDatetime() const;

    /**
     * Get host modified datetime.
     *
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * %Set host modified datetime.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     host modified datetime
     */
    void SetHostModifiedDatetime(const DateTime & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TestCashOptionsBase & update);

/** @cond PRIVATE */
public:
    TestCashOptionsBase(const protocol::Cash & value);
    TestCashOptionsBase(std::shared_ptr<protocol::Cash> && value);

    std::shared_ptr<protocol::Cash> & get_impl_wr() const;
    const std::shared_ptr<protocol::Cash> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Cash> m_impl;
};

}
