#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestExPitOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class ExPitDeal;
class ExPitIdentifier;
class Identifier;
class Integer;
class StrategyIdentifier;
class String;
class TransactionState;
class TreeNodeIdentifier;
class UserIdentifier;


namespace protocol { class Expit; }

class STRATEGY_EXPORT TestExPitOptionsBase : public Printable
{
protected:
    TestExPitOptionsBase();
    TestExPitOptionsBase(const TestExPitOptionsBase & value);
    TestExPitOptionsBase(TestExPitOptionsBase && value) noexcept;
    TestExPitOptionsBase & operator=(const TestExPitOptionsBase & value);
    TestExPitOptionsBase & operator=(TestExPitOptionsBase && value) noexcept;
    virtual ~TestExPitOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAlgoLabel() const;

    /**
     * Get algo label.
     *
     *
     * @return                          algo label
     */
    Integer GetAlgoLabel() const;

    /**
     * %Set algo label.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     algo label
     */
    void SetAlgoLabel(const Integer & value);

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
    bool HasExPitIdentifier() const;

    /**
     * Get expit identifier.
     *
     *
     * @return                          expit identifier
     */
    ExPitIdentifier GetExPitIdentifier() const;

    /**
     * %Set expit identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit identifier
     */
    void SetExPitIdentifier(const ExPitIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitPackageIdentifier() const;

    /**
     * Get expit package identifier.
     *
     *
     * @return                          expit package identifier
     */
    String GetExPitPackageIdentifier() const;

    /**
     * %Set expit package identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit package identifier
     */
    void SetExPitPackageIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMatchingCode() const;

    /**
     * Get matching code.
     *
     *
     * @return                          matching code
     */
    String GetMatchingCode() const;

    /**
     * %Set matching code.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     matching code
     */
    void SetMatchingCode(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOwner() const;

    /**
     * Get owner.
     *
     *
     * @return                          owner
     */
    UserIdentifier GetOwner() const;

    /**
     * %Set owner.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     owner
     */
    void SetOwner(const UserIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentStrategyIdentifier() const;

    /**
     * Get parent strategy identifier.
     *
     *
     * @return                          parent strategy identifier
     */
    StrategyIdentifier GetParentStrategyIdentifier() const;

    /**
     * %Set parent strategy identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     parent strategy identifier
     */
    void SetParentStrategyIdentifier(const StrategyIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyDefinitionPath() const;

    /**
     * Get strategy definition identifier path.
     *
     *
     * @return                          strategy definition identifier path
     */
    std::vector<StrategyIdentifier> GetStrategyDefinitionPath() const;

    /**
     * %Set strategy definition identifier path.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     strategy definition identifier path
     */
    void SetStrategyDefinitionPath(const std::vector<StrategyIdentifier> & value);

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
    bool HasDeals() const;

    /**
     * Get expit deals.
     *
     *
     * @return                          expit deals
     */
    std::vector<ExPitDeal> GetDeals() const;

    /**
     * %Set expit deals.
     * If the value is empty field will delete from options.
     *
     *
     * @param value                     expit deals
     */
    void SetDeals(const std::vector<ExPitDeal> & value);

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
    bool HasExchangeClientExPitIdentifier() const;

    /**
     * Get exchange client expit reference.
     *
     *
     * @return                          exchange client expit reference
     */
    String GetExchangeClientExPitIdentifier() const;

    /**
     * %Set exchange client expit reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange client expit reference
     */
    void SetExchangeClientExPitIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExchangeExPitIdentifier() const;

    /**
     * Get exchange expit reference.
     *
     *
     * @return                          exchange expit reference
     */
    String GetExchangeExPitIdentifier() const;

    /**
     * %Set exchange expit reference.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     exchange expit reference
     */
    void SetExchangeExPitIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExPitTransactionState() const;

    /**
     * Get expit transaction state.
     *
     *
     * @return                          expit transaction state
     */
    TransactionState GetExPitTransactionState() const;

    /**
     * %Set expit transaction state.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit transaction state
     */
    void SetExPitTransactionState(const TransactionState & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;

    /**
     * Get status text.
     *
     *
     * @return                          status text
     */
    String GetStatusText() const;

    /**
     * %Set status text.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     status text
     */
    void SetStatusText(const String & value);

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TestExPitOptionsBase(const protocol::Expit & value);
    TestExPitOptionsBase(std::shared_ptr<protocol::Expit> && value);

    std::shared_ptr<protocol::Expit> & get_impl_wr() const;
    const std::shared_ptr<protocol::Expit> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Expit> m_impl;
};

}
