#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// XSLT transformation.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/String.h"
#include "strategy/SafePointer.h"

namespace tbricks {
namespace config {
class XsltTransformation;
}

/**
 * XSLTTransformation represents a class for XSLT transformation
 */
class STRATEGY_EXPORT XSLTTransformation
{
public:
    /**
     * Default constructor.
     */
    XSLTTransformation();
    XSLTTransformation(const XSLTTransformation & transformation);
    virtual ~XSLTTransformation();

    XSLTTransformation & operator=(const XSLTTransformation & transformation);

    /**
     * Parse XSL stylesheet.
     *
     * @param file_name                 Path to XSL file
     */
    void SetStylesheetFile(const String & file_name);

    /**
     * Apply the stylesheet to the XML document
     *
     * @param document                  XML document
     * @return                          Result XML document
     */
    String ApplyStylesheet(const String & document);

private:
    SafePointer<config::XsltTransformation> m_transformation;
};
}
