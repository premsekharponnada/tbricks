#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Simple XML reader.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/type/String.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Uuid.h"

namespace tbricks {
namespace config {
class XmlXReader;
}

/**
 *  XML streaming reader
 */
class STRATEGY_EXPORT XMLReader
{
public:
    XMLReader();
    ~XMLReader();

    /**
     * Parse a XML file from the filesystem or the network
     * @param name a file or URL
     * @return false in case of error
     */
    bool ParseFile(const String & name);

    /**
     * Parse a XML in-memory document
     * @param buffer a pointer to a char array
     * @return false in case of error
     */
    bool ParseMemory(const String & buffer);

    /**
     * Moves the position of the current instance to the next node in the stream
     * @return false if there is no more nodes to read or in case of error
     */
    bool Read();

    /**
     * Moves the position of the current instance to the next node in the stream.
     * All nodes except elements and CDATA will be skipped
     * @return false if there is no more nodes to read or in case of error
     */
    bool ReadToElement();

    /**
     * Moves the position of the current instance until the named element is found
     * @params name the qualified name of the element
     * @return false if there is no more nodes to read or in case of error
     */
    bool ReadToFollowing(const String & name);

    /**
     * Returns a new XmlReader instance that can be used to read the current node, and all its descendants
     * @params reader a new XmlReader instance
     * @return false if there is no more nodes to read or in case of error
     */
    bool ReadSubtree(XMLReader & reader);

    /**
     * Skips the children of the current node
     * @return false if there is no more nodes to read or in case of error
     */
    bool Skip();

    /**
     * Skips the children of the current node.
     * All next nodes except elements and CDATA will be skipped too
     * @return false if there is no more nodes to read or in case of error
     */
    bool SkipToElement();

    /**
     * Skips the children of the current node until the named element is found
     * @params name the qualified name of the element
     * @return false if there is no more nodes to read or in case of error
     */
    bool SkipToFollowing(const String & name);

    /**
     * Provides the value of the attribute with the specified qualified name
     * @param name the qualified name of the attribute
     * @value value of attribute
     * @return false if there is no specified attribute
     */
    bool GetAttribute(const String & name, String & value);
    bool GetAttribute(const String & name, Integer & value);
    bool GetAttribute(const String & name, Uuid & value);
    bool GetAttribute(const String & name, int & value);
    bool GetAttribute(const String & name, unsigned int & value);

    /**
     * Reads the contents of the current node, including child nodes and markup.
     * @value inner XML
     * @return true if operation succeeded
     */
    bool ReadInnerXml(String & value);

    /**
     * Reads the contents of the current node, including child nodes and markup,
     * representing this node and all its children
     * @value outer XML
     * @return true if operation succeeded
     */
    bool ReadOuterXml(String & value);

public:
    /**
     * The depth of the node in the tree
     * @return the depth or -1 in case of error
     */
    int GetDepth();

    /**
     * The qualified name of the node
     * @name name
     * @return true if operation succeeded
     */
    bool GetName(String & name);

    /**
     * Provides the text value of the node if present
     * @value text value
     * @return true if operation succeeded
     */
    bool GetValue(String & value);

    /**
     * Check if the current node is empty
     * <item num="123"/> (IsEmptyElement() is true)
     * <item num="123"></item> (IsEmptyElement() is false, although element content is empty)
     */
    bool IsEmptyElement();

    /**
     * Check if the current content node is an end tag
     */
    bool IsEndElement();

    /**
     * Check if the current content node is a CDATA
     */
    bool IsCDATA();

private:
    XMLReader(const XMLReader & reader);
    XMLReader & operator=(const XMLReader & reader);

private:
    config::XmlXReader * m_reader;
};
}
