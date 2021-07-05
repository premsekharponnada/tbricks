#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// A UTI is a means of identifying a financial transaction and is required
// to be allocated to every derivative transaction that must be reported
// to a Trade repository under EMIR.
//****************************************************************************************

#include "strategy/type/String.h"

namespace tbricks {

class STRATEGY_EXPORT UniqueTradeIdentifier : public Printable
{
public:
    UniqueTradeIdentifier();
    UniqueTradeIdentifier(const char * full);
    UniqueTradeIdentifier(const char * namespace_id, const char * transaction_id);
    UniqueTradeIdentifier(const String & namespace_id, const String & transaction_id);

public:
    bool HasNamespaceID() const;
    const char * GetNamespaceID() const;
    void SetNamespaceID(const char * namespace_id);
    void SetNamespaceID(const String & namespace_id);

    bool HasTransactionID() const;
    const char * GetTransactionID() const;
    void SetTransactionID(const char * transaction_id);
    void SetTransactionID(const String & transaction_id);

public:
    String ToString() const;
    bool IsValid() const;
    bool Empty() const;
    void Clear();

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    char m_namespace_id[11];
    std::string m_transaction_id;
};

} // \namespace tbricks
