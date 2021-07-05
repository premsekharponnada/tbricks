#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Expiration object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"

#include "strategy_generated/DeliveryOperationBase.h"
#include "strategy_generated/ExpirationBase.h"
#include "strategy_generated/ExpirationUpdateBase.h"

#include <vector>

namespace tbricks {

namespace protocol {
class Expiration2;
}

class STRATEGY_EXPORT Expiration : public ExpirationBase
{
public:
    class DeliveryOperation;
    class Options;
    class RequestResult;
    class Stream;
    class Update;

public:
    Expiration();
    Expiration(const Expiration & other);
    Expiration(Expiration && other) noexcept;
    ~Expiration() override;

    Expiration & operator=(const Expiration & other);
    Expiration & operator=(Expiration && other) noexcept;

    void GetCreator(User & user) const;

    /**
     * @deprecated Please use "GetDeleted()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool Deleted() const;

    std::vector<DeliveryOperation> GetDeliveryOperations() const;

    void Merge(const Update & update);

public:
    static RequestResult SendCreateRequest(const Expiration::Options & options, IRequestReplyHandler & handler);
    static RequestResult SendModifyRequest(const Identifier & identifier, const Expiration::Options & options, IRequestReplyHandler & handler);
};

//****************************************************************************
// Expiration::RequestResult class
//****************************************************************************

class STRATEGY_EXPORT Expiration::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const Identifier & expiration_identifier);

    const Identifier & GetRequestIdentifier() const;
    const Identifier & GetExpirationIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_expiration_identifier;
};

//****************************************************************************
// Expiration::DeliveryOperation class
//****************************************************************************

class STRATEGY_EXPORT Expiration::DeliveryOperation : public DeliveryOperationBase
{
public:
    DeliveryOperation();
    DeliveryOperation(const DeliveryOperation & other);
    DeliveryOperation(DeliveryOperation && other) noexcept;

    ~DeliveryOperation() override;

    DeliveryOperation & operator=(const DeliveryOperation & other);
    DeliveryOperation & operator=(DeliveryOperation && other) noexcept;

    /**
     * @deprecated Please use "GetDeleted()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool Deleted() const;

    /**
     * @deprecated Please use "GetTradeByTradeDelivery()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool IsTradeByTradeDelivery() const;

    /**
     * @deprecated Please use "GetResidualCashApplicable()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool IsResidualCashApplicable() const;

    /**
     * @deprecated Please use "GetUnderlyingVenueIdentifier() and GetUnderlyingMIC()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool IsUseVenueAndMicForDeliveryInstrument() const;

    /**
     * @deprecated Please use "GetEarlyExercise()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool IsEarlyExercise() const;

    /**
     * @deprecated Please use "GetUnderlyingInstrumentIdentifier()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] InstrumentIdentifier GetUnderlyingIdentifier() const;

    /**
     * @deprecated Please use "SetUnderlyingInstrumentIdentifier()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] void SetUnderlyingIdentifier(const InstrumentIdentifier & instrument);

private:
    friend class Expiration::Update;

    using DeliveryOperationBase::DeliveryOperationBase;
};

//****************************************************************************
// Expiration::Options class
//****************************************************************************

class STRATEGY_EXPORT Expiration::Options : public Printable
{
public:
    Options();
    Options(const Options & other);
    Options(Options && other) noexcept;
    ~Options() override;

    Options & operator=(const Options & other);
    Options & operator=(Options && other) noexcept;

    const Boolean & GetDeleted() const;
    const Integer & GetExpirationSet() const;
    const DateTime & GetExpirationDate() const;
    const String & GetComment() const;
    const std::vector<DeliveryOperation> & GetDeliveryOperations() const;

    void SetDeleted(const Boolean & deleted);
    void SetExpirationSet(const Integer & expiration_set);
    void SetExpirationDate(const DateTime & date);
    void SetComment(const String & comment);
    void SetDeliveryOperations(const std::vector<DeliveryOperation> & operations);

    /**
     * @deprecated Please use "SetDeliveryOperations()".
     *             Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] std::vector<DeliveryOperation> & GetDeliveryOperations();

    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Boolean m_deleted;
    Integer m_expiration_set;
    DateTime m_expiration_date;
    String m_comment;
    std::vector<DeliveryOperation> m_delivery_operations;
};

//****************************************************************************
// Expiration::Update class
//****************************************************************************

class STRATEGY_EXPORT Expiration::Update : public ExpirationUpdateBase
{
public:
    Update();
    Update(const Update & other);
    Update(Update && other) noexcept;
    ~Update() override;

    Update & operator=(const Update & other);
    Update & operator=(Update && other) noexcept;

    std::vector<DeliveryOperation> GetDeliveryOperations() const;

public:
    using ExpirationUpdateBase::ExpirationUpdateBase;
};

} // namespace tbricks
