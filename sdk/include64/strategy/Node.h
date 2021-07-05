#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Node
//****************************************************************************************

#include "strategy_generated/NodeBase.h"

namespace tbricks {

/**
 * Node object informs about changes in a node state, such as when
 * mode goes online or offline and so on.
 *
 */
class STRATEGY_EXPORT Node : public NodeBase
{
public:
    class Stream;

    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    Node() = default;

    Node(const NodeIdentifier & identifier);

    static const Node GetCurrent();

    using NodeBase::NodeBase;
};

} // namespace tbricks