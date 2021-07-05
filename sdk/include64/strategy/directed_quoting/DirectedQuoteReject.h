#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteReject object
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/directed_quoting/DirectedQuote.h"
#include "strategy/type/QuoteRequestIdentifier.h"
#include "strategy/type/String.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/type/Integer.h"
#include "strategy/type/DirectedRequestForQuoteRejectReason.h"
#include "strategy/ExtraData.h"
#include "strategy/directed_quoting/DirectedRequestForQuote.h"

namespace tbricks {

namespace protocol {
class DirectedQuoteReject;
}

class STRATEGY_EXPORT DirectedQuoteReject : public Printable
{
public:
    /**
     * Create directed quote reject with
     * specified directed request for quote identifier.
     *
     * @param drfq_id                   directed request for quote identifier
     */
    DirectedQuoteReject(const Identifier & drfq_id);
    DirectedQuoteReject(const DirectedRequestForQuote & value);
    DirectedQuoteReject(const DirectedQuoteReject & value);
    DirectedQuoteReject(DirectedQuoteReject && value) noexcept;
    DirectedQuoteReject & operator=(const DirectedQuoteReject & value);
    DirectedQuoteReject & operator=(DirectedQuoteReject && value) noexcept;
    virtual ~DirectedQuoteReject();

public:
    /**
     * Check if field is set.
     *
     * @return                           True if field is set, false otherwise
     */
    bool HasRegulatoryParameters() const;
    /**
     * Get regulatory parameters.
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;
    /**
     * %Set regulatory parameters.
     *
     * @param value                     regulatory parameters
     */
    void SetRegulatoryParameters(const RegulatoryParameters & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuoteRequestIdentifier() const;
    /**
     * Get quote request identifier.
     *
     * @return                          quote request identifier
     */
    QuoteRequestIdentifier GetQuoteRequestIdentifier() const;
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExtraData() const;
    /**
     * Get extra data.
     *
     * @return                          extra data
     */
    ExtraData GetExtraData() const;
    /**
     * %Set extra data.
     *
     * @param value                     extra data
     */
    void SetExtraData(const ExtraData & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStatusText() const;
    /**
     * Get status text.
     *
     * @return                          status text
     */
    String GetStatusText() const;
    /**
     * %Set status text.
     *
     * @param value                     status text
     */
    void SetStatusText(const String & value);
    /**
     * Get host created datetime
     *
     * @return                          host created datetime
     */
    DateTime GetHostCreatedDatetime() const;
    /**
     * Get host modified datetime
     *
     * @return                          host modified datetime
     */
    DateTime GetHostModifiedDatetime() const;
    /**
     * Get creator
     *
     * @return                          creator
     */
    UserIdentifier GetCreator() const;
    /**
     * Get operator
     *
     * @return                          operator
     */
    UserIdentifier GetOperator() const;
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;
    /**
     * Get comment
     *
     * @return                          comment
     */
    String GetComment() const;
    /**
     * %Set comment.
     *
     * @param value                     comment
     */
    void SetComment(const String & value);
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRejectReason() const;
    /**
     * Get reject reason
     *
     * @return                          reject reason
     */
    std::optional<DirectedRequestForQuoteRejectReason> GetRejectReason() const;
    /**
     * %Set reject reason.
     *
     * @param value                     reject reason
     */
    void SetRejectReason(std::optional<DirectedRequestForQuoteRejectReason> value);

public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

public:
    DirectedQuoteReject(const protocol::DirectedQuoteReject & value);

private:
    friend class DirectedQuoteManager;

private:
    std::unique_ptr<protocol::DirectedQuoteReject> m_impl;
};
}
