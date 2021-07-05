#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AuditData Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class AuditData;

namespace visualization {

/**
 * RowEntity implementation containing AuditData object.
 *
 */
class STRATEGY_EXPORT AuditDataRowEntity final : public RowEntity
{
public:
    AuditDataRowEntity();

    AuditDataRowEntity(const AuditDataRowEntity & other) = default;
    AuditDataRowEntity(AuditDataRowEntity && other) noexcept = default;
    AuditDataRowEntity & operator=(const AuditDataRowEntity & other) = default;
    AuditDataRowEntity & operator=(AuditDataRowEntity && other) noexcept = default;

    /**
     * Get audit data object stored in row entity.
     *
     * @return audit data
     */
    const AuditData & GetAuditData() const;

    /**
     * Set audit data object and update view models containing row entity.
     *
     * @param audit        audit data
     */
    void SetAuditData(const AuditData & audit);

    virtual ~AuditDataRowEntity() = default;
};
} // namespace visualization
} // namespace tbricks
