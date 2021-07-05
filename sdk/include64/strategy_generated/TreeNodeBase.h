#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNodeBase object
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
class Identifier;
class StrategyIdentifier;
class String;
class TreeNodeIdentifier;
class TreeTypeIdentifier;
class UserIdentifier;


namespace protocol { class TreeNode; }

class STRATEGY_EXPORT TreeNodeBase : public Printable
{
protected:
    TreeNodeBase();
    TreeNodeBase(const TreeNodeBase & value);
    TreeNodeBase(TreeNodeBase && value) noexcept;
    TreeNodeBase & operator=(const TreeNodeBase & value);
    TreeNodeBase & operator=(TreeNodeBase && value) noexcept;
    virtual ~TreeNodeBase();

public:
    /**
     * Get tree node identifier.
     *
     *
     * @return                          tree node identifier
     */
    TreeNodeIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasParentIdentifier() const;

    /**
     * Get parent tree node identifier.
     *
     *
     * @return                          parent tree node identifier
     */
    TreeNodeIdentifier GetParentIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasType() const;

    /**
     * Get tree type.
     *
     *
     * @return                          tree type
     */
    TreeTypeIdentifier GetType() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get tree node name.
     *
     *
     * @return                          tree node name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDescription() const;

    /**
     * Get tree node description.
     *
     *
     * @return                          tree node description
     */
    String GetDescription() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperator() const;

    /**
     * Get operator.
     *
     *
     * @return                          operator
     */
    UserIdentifier GetOperator() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperatingServiceInstanceIdentifier() const;

    /**
     * Get operating service instance identifier.
     *
     *
     * @return                          operating service instance identifier
     */
    Identifier GetOperatingServiceInstanceIdentifier() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOperatingStrategyIdentifier() const;

    /**
     * Get operating strategy identifier.
     *
     *
     * @return                          operating strategy identifier
     */
    StrategyIdentifier GetOperatingStrategyIdentifier() const;

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


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const TreeNodeBase & update);

/** @cond PRIVATE */
public:
    TreeNodeBase(const protocol::TreeNode & value);
    TreeNodeBase(std::shared_ptr<protocol::TreeNode> && value);

    std::shared_ptr<protocol::TreeNode> & get_impl_wr() const;
    const std::shared_ptr<protocol::TreeNode> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::TreeNode> m_impl;
};

}
