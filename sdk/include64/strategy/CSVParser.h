#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CSVParser
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Matrix.h"

#include <fstream>
#include <istream>

namespace tbricks {

class STRATEGY_EXPORT CSVParser
{
public:
    class IHandler
    {
    public:
        virtual ~IHandler() {}
        virtual Variant ConvertCSVCell(const String & cell, size_t row, size_t column) = 0;
    };

public:
    CSVParser(const String & file_name, const String & separator = ",");
    CSVParser(std::istream & stream, const String & separator = ",");
    ~CSVParser();

    void SetHandler(IHandler & handler);
    bool HasHandler() const;

    bool Ready() const;

    /// return true if not ready
    bool GetError(String & error_text) const;

public:
    const Matrix & GetMatrix();

private:
    class CSVParserImpl;
    CSVParserImpl * m_parser;

    String m_filename;
    std::ifstream m_ifstream;

    IHandler * m_handler;

    Matrix * m_matrix;
};

} // namespace tbricks
