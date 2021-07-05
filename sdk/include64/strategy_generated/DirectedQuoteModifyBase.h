#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// DirectedQuoteModifyBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class DirectedQuoteIdentifier;
class ExtraData;
class Identifier;
class RegulatoryParameters;
class String;
class Volume;


namespace protocol { class DirectedQuoteModifyRequest; }

class STRATEGY_EXPORT DirectedQuoteModifyBase : public Printable
{
protected:
    DirectedQuoteModifyBase();
    DirectedQuoteModifyBase(const DirectedQuoteModifyBase & value);
    DirectedQuoteModifyBase(DirectedQuoteModifyBase && value) noexcept;
    DirectedQuoteModifyBase & operator=(const DirectedQuoteModifyBase & value);
    DirectedQuoteModifyBase & operator=(DirectedQuoteModifyBase && value) noexcept;
    virtual ~DirectedQuoteModifyBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDirectedQuoteIdentifier() const;

    /**
     * Get directed quote identifier.
     *
     *
     * @return                          directed quote identifier
     */
    DirectedQuoteIdentifier GetDirectedQuoteIdentifier() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidActiveVolume() const;

    /**
     * Get bid active volume.
     *
     *
     * @return                          bid active volume
     */
    Volume GetBidActiveVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidFilledVolume() const;

    /**
     * Get bid filled volume.
     *
     *
     * @return                          bid filled volume
     */
    Volume GetBidFilledVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBidTotalVolume() const;

    /**
     * Get bid volume.
     *
     *
     * @return                          bid volume
     */
    Volume GetBidTotalVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskActiveVolume() const;

    /**
     * Get ask active volume.
     *
     *
     * @return                          ask active volume
     */
    Volume GetAskActiveVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskFilledVolume() const;

    /**
     * Get ask filled volume.
     *
     *
     * @return                          ask filled volume
     */
    Volume GetAskFilledVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasAskTotalVolume() const;

    /**
     * Get ask volume.
     *
     *
     * @return                          ask volume
     */
    Volume GetAskTotalVolume() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasRegulatoryParameters() const;

    /**
     * Get regulatory parameters.
     *
     *
     * @return                          regulatory parameters
     */
    RegulatoryParameters GetRegulatoryParameters() const;

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
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasComment() const;

    /**
     * Get comment.
     *
     *
     * @return                          comment
     */
    String GetComment() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    DirectedQuoteModifyBase(const protocol::DirectedQuoteModifyRequest & value);
    DirectedQuoteModifyBase(std::shared_ptr<protocol::DirectedQuoteModifyRequest> && value);

    std::shared_ptr<protocol::DirectedQuoteModifyRequest> & get_impl_wr() const;
    const std::shared_ptr<protocol::DirectedQuoteModifyRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::DirectedQuoteModifyRequest> m_impl;
};

}
