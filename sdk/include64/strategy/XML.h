#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Simple XML document reader.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/type/Double.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Variant.h"

#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"

namespace tbricks {

namespace strategy {
class XMLDocumentImpl;
class XMLNodeListImpl;
class XMLNodeImpl;
}

class XMLNode;

/**
 * XMLDocument represents the entire XML document.
 */
class STRATEGY_EXPORT XMLDocument : public Printable
{
public:
    /**
     * Default constructor.
     *
     * Constructs empty document.
     */
    XMLDocument();
    XMLDocument(const XMLDocument & document);
    virtual ~XMLDocument();

    XMLDocument & operator=(const XMLDocument & document);

    /**
     * Accessor for document root element.
     *
     * This is the entry point for further document evaluation, it represents
     * the document node.
     *
     * @return                          Document root element
     */
    XMLNode GetDocumentElement() const;

    /**
     * Parse XML document.
     *
     * @param document                  XML document
     * @return                          'true' if document is successfully
     *                                  parsed, 'false' otherwise
     */
    bool Parse(const String & document);

    /**
     * Check the object for emptiness.
     *
     * @return                          'true' if object is empty, i.e. doesn't
     *                                  contain root node, 'false' otherwise
     */
    bool Empty() const;

    /**
     * XML Document print function.
     *
     */
    virtual std::ostream & Print(std::ostream & strm) const;

    /**
     * Returns a string representation of XML. Will reformat the document.
     *
     * @return String                   XML document
     */
    String GetOuterXML() const;

    /**
     * Returns a string representation of XML without reformatting.
     *
     * @return String                   XML document
     */
    String GetRawOuterXML() const;

private:
    strategy::XMLDocumentImpl * m_document;
};

/**
 * XMLNodeList represents collection of XML nodes and provides for iterating
 * over selected node set.
 */
class STRATEGY_EXPORT XMLNodeList
{
public:
    /**
     * Constructs empty object.
     */
    XMLNodeList();
    XMLNodeList(const XMLNodeList & list);
    ~XMLNodeList();

    XMLNodeList & operator=(const XMLNodeList & list);

    /**
     * Get number of nodes in the node list.
     *
     * @return                          Number of nodes if object is not
     *                                  empty, zero otherwise
     */
    size_t GetLength() const;

    /**
     * Get node from the list by index.
     *
     * If index is greated than or equal to the value returned by GetLength()
     * the call has undefined behavior.
     *
     * @code
     * for (size_t i = 0; i < node_list.GetLength(); ++i) {
     *     XMLNode node = node_list.GetItem(i);
     *     if (node.Empty()) {
     *         // error
     *         return;
     *     }
     *     // process node
     * }
     * @endcode
     *
     * @return                          Node from node list
     */
    XMLNode GetItem(size_t index) const;

    /**
     * Check the object for emptiness.
     *
     * @return                          'true' if node list contains no nodes,
     *                                  'false' otherwise
     */
    bool Empty() const;

protected:
    XMLNodeList(strategy::XMLNodeListImpl * list);

private:
    strategy::XMLNodeListImpl * m_list;
};

/**
 * XMLNode represents a single element node in the document tree.
 *
 * XPath-based methods of XMLNode work with reduced set of XPath v1.0,
 * subject to restrictions documented in interface calls.
 */
class STRATEGY_EXPORT XMLNode
{
public:
    /**
     * Constructs empty object.
     */
    XMLNode();
    XMLNode(const XMLNode & node);
    ~XMLNode();

    XMLNode & operator=(const XMLNode & node);

    /**
     * Evaluate XPath expression into a value of simple type.
     *
     * The call fails if XPath expression does not evaluate to a simple type
     * (for instance, if it evaluates to a set of nodes).
     *
     * @code
     * XMLNode root_node = document.GetDocumentElement();
     * if (root_node.Empty()) {
     *     // error
     *     return;
     * }
     *
     * String value;
     * if (!root_node.GetValue("FIXML/Instrmt/SecAltID/@SecAltIDSrc", value)) {
     *     // error
     *     return;
     * }
     * // ok, attribute value was stored to the variable
     * @endcode
     *
     * @param xpe                       XPath expression
     * @param value                     Result of XPath evaluation, if the
     *                                  latter succeeded, untouched otherwise
     * @return                          'true' if XPath evaluation succeeded,
     *                                  'false' otherwise
     */
    bool GetValue(const String & xpe, String & value) const;
    bool GetValue(const String & xpe, Integer & value) const;
    bool GetValue(const String & xpe, Double & value) const;
    bool GetValue(const String & xpe, DateTime & value) const;
    bool GetValue(const String & xpe, const InstrumentParameterDefinition & def, Variant & value) const;
    bool GetValue(const String & xpe, const InstrumentParameterDefinition & def, InstrumentParameters::Modifier & modifier) const;
    bool GetValue(const String & xpe, int & value) const;
    bool GetValue(const String & xpe, unsigned int & value) const;

    /**
     * Find node by XPath expression and set it's value.
     * If XPath expression evaluated into multiple nodes, used first one.
     *
     * @code
     * XMLNode root_node = document.GetDocumentElement();
     * if (root_node.Empty()) {
     *     // error
     *     return;
     * }
     *
     * if (!root_node.SetValue("FIXML/Instrmt/SecAltID/@SecAltIDSrc", "Some new value ID")) {
     *     // error
     *     return;
     * }
     * // ok, node value did updated
     * @endcode
     *
     * @param xpe                       XPath expression
     * @param value                     New node value
     * @return                          'true' if XPath evaluation succeeded,
     *                                  'false' otherwise
     */
    bool SetValue(const String & xpe, const String & value);
    bool SetValue(const String & xpe, const Integer & value);
    bool SetValue(const String & xpe, const Double & value);
    bool SetValue(const String & xpe, const DateTime & value);
    bool SetValue(const String & xpe, int value);
    bool SetValue(const String & xpe, unsigned int value);

    /**
     * Create new node with name and append it to this node.
     *
     * @param name                      New node name value
     * @return                          New node, if it's created,
     *                                  empty node otherwise
     */
    XMLNode AddNode(const String & name);

    /**
     * Evaluate XPath expression into a node list.
     *
     * @code
     * XMLNodeList node_list = root_node.GetNodes("FIXML/Instrmt");
     * if (node_list.Empty() || (node_list.GetLength() == 0)) {
     *     // no nodes found
     *     return;
     * }
     *
     * for (size_t i = 0; i < node_list.GetLength(); ++i) {
     *     String name;
     *     if (node.GetName(name)) {
     *         if (name == "Instrmt") {
     *             // handle Instrmt element
     *         }
     *     }
     * }
     * @endcode
     *
     * @param xpe                       XPath expression
     * @return                          Node list if XPath expression results
     *                                  in non-empty node set, empty node list
     *                                  otherwise
     */
    XMLNodeList GetNodes(const String & xpe) const;

    /**
     * Get node name.
     *
     * @param name                      Node name value
     * @return                          'true' if node name was successfully
     *                                  fetched, 'false' otherwise
     */
    bool GetName(String & name) const;

    /**
     * Check if attribute exists in the node.
     *
     * @param name                      Attribute name
     * @return                          'true' if attribute exists,
     *                                  'false' otherwise
     */
    bool HasAttribute(const String & name) const;

    /**
     * Get attribute value.
     *
     * @param name                      Attribute name
     * @param value                     Attribute value
     * @return                          'true' if attribute exists and
     *                                  appropriate XPath expression had
     *                                  been successfully evaluated,
     *                                  'false' otherwise
     */
    bool GetAttribute(const String & name, String & value) const;
    bool GetAttribute(const String & name, int & value) const;
    bool GetAttribute(const String & name, unsigned int & value) const;

    /**
     * Set attribute value.
     *
     * @param name                      Attribute name
     * @param value                     Attribute value
     * @return                          'true' if create/update attribute
     *                                  value was successfully completed,
     *                                  'false' otherwise
     */
    bool SetAttribute(const String & name, const String & value);
    bool SetAttribute(const String & name, int value);
    bool SetAttribute(const String & name, unsigned int value);

    /**
     *  Remove attribute.
     *  @param name                 Attribute name
     *  @return                     'true' if attribute successfully remove,
     *                              'false' otherwise
     */
    bool RemoveAttribute(const String & name);

    /**
     * Check the object for emptiness.
     *
     * @return                          'true' if node object does not refer
     *                                  to a parsed XML document element node,
     *                                  'false' otherwise
     */
    bool Empty() const;

    /**
     * Remove node from DOM tree. Any links to this node will be invalidated.
     *
     * @return                          'true' if node removed from tree,
     *                                  'false' otherwise
     */
    bool Destroy();

protected:
    XMLNode(strategy::XMLNodeImpl * node);

private:
    strategy::XMLNodeImpl * m_node;
};
}
