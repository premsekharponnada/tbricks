#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Table updates list
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Variant.h"

namespace tbricks {

class STRATEGY_EXPORT TablePosition : public Printable
{
public:
    TablePosition();
    TablePosition(const Uuid & column, size_t row);

    const Uuid & GetColumn() const;
    void SetColumn(const Uuid & column);

    size_t GetRow() const;
    void SetRow(size_t row);

    std::ostream & Print(std::ostream & strm) const override;

private:
    Uuid m_col_id;
    size_t m_row_id;
};

class STRATEGY_EXPORT TableAction : public Printable
{
public:
    TableAction();
    ~TableAction() override;

    virtual int GetType() const = 0;
    std::ostream & Print(std::ostream & strm) const override = 0;

    std::ostream & PrintWithType(std::ostream & strm) const;
};

class STRATEGY_EXPORT SetCellTableAction : public TableAction
{
public:
    SetCellTableAction();
    SetCellTableAction(const TablePosition & pos, bool increment, const Variant & value);

    int GetType() const override;

    const TablePosition & GetPosition() const;
    void SetPosition(const TablePosition & pos);

    const Variant & GetKeyValue() const;
    void SetKeyValue(const Variant & value);

    const Variant & GetValue() const;
    void SetValue(const Variant & value);

    const Integer & GetIncrement() const;
    void SetIncrement(const Integer & value);

    std::ostream & Print(std::ostream & strm) const override;

private:
    TablePosition m_pos;
    Variant m_key_value;
    Variant m_value;
    Integer m_increment;
};

class STRATEGY_EXPORT MoveCellTableAction : public TableAction
{
public:
    MoveCellTableAction();
    MoveCellTableAction(const TablePosition & pos_from, const TablePosition & pos_to);

    int GetType() const override;

    const TablePosition & GetPositionFrom();
    void SetPositionFrom(const TablePosition & pos);

    const TablePosition & GetPositionTo();
    void SetPositionTo(const TablePosition & pos);

    std::ostream & Print(std::ostream & strm) const override;

private:
    TablePosition m_pos_from;
    TablePosition m_pos_to;
};

class STRATEGY_EXPORT InsertColumnTableAction : public TableAction
{
public:
    InsertColumnTableAction();
    InsertColumnTableAction(const Uuid & col_id, const TypeInfo & type);

    int GetType() const override;

    const Uuid & GetColumn() const;
    void SetColumn(const Uuid & col_id);

    const TypeInfo & GetColumnType() const;
    void SetColumnType(const TypeInfo & type);

    std::ostream & Print(std::ostream & strm) const override;

private:
    Uuid m_col_id;
    TypeInfo m_type;
};

class STRATEGY_EXPORT RemoveColumnTableAction : public TableAction
{
public:
    RemoveColumnTableAction();
    RemoveColumnTableAction(const Uuid & col_id);

    int GetType() const override;

    const Uuid & GetColumn() const;
    void SetColumn(const Uuid & col_id);

    std::ostream & Print(std::ostream & strm) const override;

private:
    Uuid m_col_id;
};

class STRATEGY_EXPORT InsertRowTableAction : public TableAction
{
public:
    InsertRowTableAction();
    InsertRowTableAction(size_t row_id);

    int GetType() const override;

    size_t GetRow() const;
    void SetRow(size_t row_id);

    std::ostream & Print(std::ostream & strm) const override;

private:
    size_t m_row_id;
};

class STRATEGY_EXPORT RemoveRowTableAction : public TableAction
{
public:
    RemoveRowTableAction();
    RemoveRowTableAction(size_t row_id);

    int GetType() const override;

    size_t GetRow() const;
    void SetRow(size_t row_id);

    std::ostream & Print(std::ostream & strm) const override;

private:
    size_t m_row_id;
};

class STRATEGY_EXPORT ClearAction : public TableAction
{
public:
    ClearAction();

    int GetType() const override;
    std::ostream & Print(std::ostream & strm) const override;
};

class STRATEGY_EXPORT RemoveRowByKeyTableAction : public TableAction
{
public:
    RemoveRowByKeyTableAction();
    RemoveRowByKeyTableAction(const Uuid & key_col_id, const Variant & key_value);

    int GetType() const override;

    const Uuid & GetKeyColumn() const;
    void SetKeyColumn(const Uuid & column);

    const Variant & GetKeyValue() const;
    void SetKeyValue(const Variant & value);

    std::ostream & Print(std::ostream & strm) const override;

private:
    Uuid m_col_id;
    Variant m_value;
};

} // \namespace tbricks
