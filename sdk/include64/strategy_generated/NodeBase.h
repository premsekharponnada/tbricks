#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// NodeBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class NodeIdentifier;
class String;
class StringDictionary;
enum class NodeState;


namespace protocol { class Node; }

class STRATEGY_EXPORT NodeBase : public Printable
{
protected:
    NodeBase();
    NodeBase(const NodeBase & value);
    NodeBase(NodeBase && value) noexcept;
    NodeBase & operator=(const NodeBase & value);
    NodeBase & operator=(NodeBase && value) noexcept;
    virtual ~NodeBase();

public:
    /**
     * Check if field is set.
     *
     * Get node identifier.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get node identifier.
     *
     * Get node identifier.
     *
     *
     * @return                          node identifier
     */
    NodeIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get node short name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get node name.
     *
     * Get node short name.
     *
     *
     * @return                          node name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     * Get node host name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostName() const;

    /**
     * Get host name.
     *
     * Get node host name.
     *
     *
     * @return                          host name
     */
    String GetHostName() const;

    /**
     * Check if field is set.
     *
     * Get list of node ip addreses.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHostIpAddreses() const;

    /**
     * Get inet addresses.
     *
     * Get list of node ip addreses.
     *
     *
     * @return                          inet addresses
     */
    std::vector<String> GetHostIpAddreses() const;

    /**
     * Check if field is set.
     *
     * Get state of this node.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasState() const;

    /**
     * Get node state.
     *
     * Get state of this node.
     *
     *
     * @return                          node state
     */
    std::optional<NodeState> GetState() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get node properties.
     *
     *
     * @return                          node properties
     */
    StringDictionary GetProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    NodeBase(const protocol::Node & value);
    NodeBase(std::shared_ptr<protocol::Node> && value);

    std::shared_ptr<protocol::Node> & get_impl_wr() const;
    const std::shared_ptr<protocol::Node> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Node> m_impl;
};

}
