#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNode
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/TreeNodeParameters.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/TreeTypeIdentifier.h"
#include "strategy/CalculatedPropertiesDictionary.h"
#include "strategy_generated/TreeNodeBase.h"
#include "strategy_generated/TreeNodeModifierBase.h"

namespace tbricks {

class IRequestReplyHandler;

class STRATEGY_EXPORT TreeNode : public TreeNodeBase
{
public:
    class Stream;
    class Options;
    class Modifier;
    class RequestResult;

public:
    TreeNode() = default;
    TreeNode(const TreeNodeIdentifier & id);
    using TreeNodeBase::TreeNodeBase;

public:
    bool Resolve(const TreeNodeIdentifier & id);

    Boolean Deleted() const { return GetDeleted(); }
    TreeNodeParameters GetParameters() const;
    CalculatedPropertiesDictionary GetCalculatedProperties() const;

public:
    void Merge(const TreeNode & update);

public:
    size_t GetHash() const;

public:
    /**
     * Send root tree node create request.
     *
     * Method sends a request for creation root tree node.
     *
     * Tree node create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param treeType                  type of created tree
     * @param modifier                  Creation request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          TreeNode::RequestResult object
     */
    static RequestResult CreateRootTreeNode(const TreeTypeIdentifier & treeType, const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send child tree node create request.
     *
     * Method sends a request for creation child of specified parent tree node
     *
     * Tree node create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param parentId                  Identifier of parent tree node
     * @param modifier                  Creation request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          TreeNode::RequestResult object
     */
    static RequestResult CreateChildTreeNode(const TreeNodeIdentifier & parentId, const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send sibling tree node create request.
     *
     * Method sends a request for creation sibling of specified tree node
     *
     * Tree node create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param siblingId                 Identifier tree node on the same level
     * @param modifier                  Creation request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          TreeNode::RequestResult object
     */
    static RequestResult CreateSiblingTreeNode(const TreeNodeIdentifier & siblingId, const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send tree node modify request.
     *
     * Method sends a request for modifying specified tree node
     *
     * Tree node modify request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     *
     * @param treeNodeId                Tree node identifier
     * @param modifier                  Modify request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          TreeNode::RequestResult object
     */
    static RequestResult ModifyTreeNode(const TreeNodeIdentifier & treeNodeId, const Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send set parent tree node request.
     *
     * Method sends a request for setting parent tree node for specified tree node. Tree nodes
     * GetParentIdentifier() should be empty, or NotSupportedException will be thrown.
     *
     * %Set parent tree node request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param parentTreeNodeId          Parent tree node id to set
     * @param treeNodeId                Tree node identifier
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          TreeNode::RequestResult object
     */
    static RequestResult
    SetParentTreeNode(const TreeNodeIdentifier & parentTreeNodeId, const TreeNodeIdentifier & treeNodeId, IRequestReplyHandler & handler);

public:
    static void GetRoles(std::vector<TreeNode> & roles);
    static void GetClients(std::vector<TreeNode> & accounts);
    static void GetAllTreeNodes(std::vector<TreeNode> & treeNodes);
    static void GetTreeNodesOfType(const TreeTypeIdentifier & type, std::vector<TreeNode> & treeNodes);
    static void GetChildTreeNodes(const TreeNodeIdentifier & parent, std::vector<TreeNode> & treeNodes);
};

inline size_t hash_value(const TreeNode & value)
{
    return value.GetHash();
}

class STRATEGY_EXPORT TreeNode::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const TreeNodeIdentifier & tree_node_identifier);

    const Identifier & GetRequestIdentifier() const;
    const TreeNodeIdentifier & GetTreeNodeIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    TreeNodeIdentifier m_tree_node_identifier;
};

class STRATEGY_EXPORT TreeNode::Modifier : public TreeNodeModifierBase
{
public:
    void SetParameter(const TreeNodeParameterDefinition & def, const AnyType & value);

    bool GetParameter(const TreeNodeParameterDefinition & def, AnyType & value) const;
    bool GetParameter(const Uuid & identifier, AnyType & value) const;

    TreeNodeParameters GetParameters() const;
    void SetParameters(const TreeNodeParameters & params) const;

    bool GetCalculatedProperty(const CalculatedPropertyDefinition & def, AnyType & value) const;
    void SetCalculatedProperty(const CalculatedPropertyDefinition & def, const AnyType & value) const;

    CalculatedPropertiesDictionary GetCalculatedProperties() const;
    void SetCalculatedProperties(const CalculatedPropertiesDictionary & params) const;
};
}
