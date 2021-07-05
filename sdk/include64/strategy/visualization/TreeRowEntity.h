#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode Row Entity public interface.
//****************************************************************************************

#include "strategy/visualization/RowEntity.h"

namespace tbricks {

class Uuid;
class TreeNode;

namespace visualization {

/**
 * RowEntity implementation containing TreeNode object.
 *
 */
class STRATEGY_EXPORT TreeRowEntity final : public RowEntity
{
public:
    TreeRowEntity();

    TreeRowEntity(const TreeRowEntity & other) = default;
    TreeRowEntity(TreeRowEntity && other) noexcept = default;
    TreeRowEntity & operator=(const TreeRowEntity & other) = default;
    TreeRowEntity & operator=(TreeRowEntity && other) noexcept = default;

    /**
     * Get tree node object stored in row entity.
     *
     * @return tree node
     */
    const TreeNode & GetTreeNode() const;

    /**
     * Set tree node object and update view models containing row entity.
     *
     * @param treeNode        tree node
     */
    void SetTreeNode(const TreeNode & treeNode);

    virtual ~TreeRowEntity() = default;
};

} // namespace visualization
} // namespace tbricks
