#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AuditableByIdentifierFilter, matches auditables by their identifier.
//****************************************************************************************

#include "strategy/type/AuditableIdentifier.h"
#include "strategy/stream_filter/AuditableFilter.h"

namespace tbricks {

/**
 * AuditableByIdentifierFilter matches all auditables with their identifier provided
 * as filter argument.
 */
class STRATEGY_EXPORT AuditableByIdentifierFilter : public AuditableFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter a to match the auditable having identifier as
     * specified in the input parameter.
     *
     * @param identifier                    Instance of AuditableIdentifier
     */
    AuditableByIdentifierFilter(const AuditableIdentifier & identifier);
    AuditableByIdentifierFilter(const AuditableByIdentifierFilter & filter);

    AuditableByIdentifierFilter & operator=(const AuditableByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    AuditableIdentifier m_identifier;
};
}
