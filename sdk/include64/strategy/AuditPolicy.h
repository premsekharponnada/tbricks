#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Strategy audit persistence policy, to be specified in strategy instantiation
// call.
//****************************************************************************************

#include <vector>
#include "strategy/Printable.h"
#include "strategy/Value.h"

namespace tbricks {

/**
 * Audit persistence policy specifies logic for storing updates.
 * The "default" is arbitrary logic. "All updates" ensures that all individual
 * discrete updates are stored.
 *
 * @see StrategyOptions
 */
class STRATEGY_EXPORT AuditPolicy : public Printable
{
public:
    enum PolicyType
    {
        DEFAULT,
        ALL_UPDATES
    };

    AuditPolicy();
    AuditPolicy(const AuditPolicy & src);
    AuditPolicy(PolicyType type);
    ~AuditPolicy();

    bool IsDefault() const;
    bool IsAllUpdates() const;

    inline bool Empty() const { return m_type.Empty(); }

    void Clear();

    AuditPolicy & operator=(const AuditPolicy & src);

    bool operator==(const AuditPolicy & src) const;
    bool operator!=(const AuditPolicy & src) const;

    void Merge(const AuditPolicy & policy);

    /**
     * Get persistence type.
     *
     * @return                          persistence type
     */
    PolicyType GetType() const;

    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Value<PolicyType> m_type;
};
}
