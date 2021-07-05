#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPitDeclineOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class ExtraData;
class RequestForTradeIdentifier;
enum class DirectedRequestForQuoteRejectReason;


namespace protocol { class ExpitDeclineRequest; }

class STRATEGY_EXPORT ExPitDeclineOptionsBase : public Printable
{
protected:
    ExPitDeclineOptionsBase();
    ExPitDeclineOptionsBase(const ExPitDeclineOptionsBase & value);
    ExPitDeclineOptionsBase(ExPitDeclineOptionsBase && value) noexcept;
    ExPitDeclineOptionsBase & operator=(const ExPitDeclineOptionsBase & value);
    ExPitDeclineOptionsBase & operator=(ExPitDeclineOptionsBase && value) noexcept;
    virtual ~ExPitDeclineOptionsBase();

public:
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
    bool HasRejectReason() const;

    /**
     * Get directed request for quote reject reason.
     *
     *
     * @return                          directed request for quote reject reason
     */
    std::optional<DirectedRequestForQuoteRejectReason> GetRejectReason() const;

    /**
     * %Set directed request for quote reject reason.
     *
     *
     * @param value                     directed request for quote reject reason
     */
    void SetRejectReason(std::optional<DirectedRequestForQuoteRejectReason> value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRequestForTradeIdentifier() const;

    /**
     * Get request for trade identifier.
     *
     *
     * @return                          request for trade identifier
     */
    RequestForTradeIdentifier GetRequestForTradeIdentifier() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ExPitDeclineOptionsBase(const protocol::ExpitDeclineRequest & value);
    ExPitDeclineOptionsBase(std::shared_ptr<protocol::ExpitDeclineRequest> && value);

    std::shared_ptr<protocol::ExpitDeclineRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::ExpitDeclineRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::ExpitDeclineRequest> m_impl;
};

}
