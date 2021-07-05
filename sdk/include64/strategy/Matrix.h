#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Matrix object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"

namespace tbricks {

class STRATEGY_EXPORT Matrix : public Printable
{
public:
    Matrix();
    Matrix(const Matrix & matrix);
    Matrix(size_t height, size_t width);
    Matrix & operator=(const Matrix & matrix);
    virtual ~Matrix();

    enum SortOrder
    {
        SortOrder_Ascending,
        SortOrder_Descending
    };

public:
    void Clear();
    bool Empty() const;

public:
    void UpdateCell(size_t row, size_t column, const AnyType & value);
    Variant GetCell(size_t row, size_t column) const;

    size_t GetHeight() const;
    size_t GetWidth() const;

    typedef std::pair<size_t, SortOrder> ColumnOrder;
    void Sort(size_t column, SortOrder sort_order, size_t first_row = 0);
    void Sort(const std::vector<ColumnOrder> & columns, size_t first_row = 0);

public:
    std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    class MatrixImpl;
    MatrixImpl * m_matrix;
};
}
