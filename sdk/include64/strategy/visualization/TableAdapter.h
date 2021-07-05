#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TableAdapter
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/VisualizationApp.h"
#include "strategy/type/Table.h"

namespace tbricks { namespace visualization {

class TableHandler;

class STRATEGY_EXPORT TableAdapter
{
public:
    TableAdapter(VisualizationApp & manager, const ParameterDefinition & pd);

    ~TableAdapter();

    void Decode(const tbricks::Binary & buffer, size_t & offset);

    void InsertColumn(const tbricks::Uuid & column_id, const tbricks::TypeInfo & type, bool indexed);

    void InsertColumn(const tbricks::DefinitionBase & def, bool indexed);

    bool RemoveColumn(const tbricks::Uuid & column_id);

    bool RemoveColumn(const tbricks::DefinitionBase & def);

    void InsertRow(size_t row_id);

    void AddRow();

    bool RemoveRow(size_t row_id);

    bool RemoveRow(const tbricks::Uuid & key_column_id, const tbricks::AnyType & key_cell);

    bool RemoveRow(const tbricks::DefinitionBase & key_def, const tbricks::AnyType & key_cell);

    void UpdateRow(size_t row_id, const tbricks::StrategyParameters & parameters);

    void UpdateCell(const tbricks::Uuid & column_id, size_t row_id, const tbricks::AnyType & cell);

    void UpdateCell(const tbricks::DefinitionBase & def, size_t row_id, const tbricks::AnyType & cell);

    void UpdateCell(const tbricks::TablePosition & pos, const tbricks::AnyType & cell);

    void UpdateCell(const tbricks::Uuid & key_column_id,
                    const tbricks::AnyType & key_cell,
                    const tbricks::Uuid & column_id,
                    const tbricks::AnyType & cell);

    void UpdateCell(const tbricks::DefinitionBase & key_def,
                    const tbricks::AnyType & key_cell,
                    const tbricks::DefinitionBase & def,
                    const tbricks::AnyType & cell);

    void ClearCell(const tbricks::Uuid & column_id, size_t row_idx);

    void ClearCell(const tbricks::DefinitionBase & def, size_t row_id);

    void ClearCell(const tbricks::TablePosition & pos);

    void ClearAllCells();

    void MoveCell(const tbricks::Uuid & column_id_from, size_t row_id_from, const tbricks::Uuid & column_id_to, size_t row_id_to);

    void MoveCell(const tbricks::DefinitionBase & def_from, size_t row_id_from, const tbricks::DefinitionBase & def_to, size_t row_id_to);

    void MoveCell(const tbricks::TablePosition & pos_from, const tbricks::TablePosition & pos_to);

    void Clear();

    void Merge(const tbricks::Table & other);

    const DefinitionBase & GetDefinition() const { return m_cpd; }

private:
    std::shared_ptr<TableHandler> m_table;

    VisualizationApp & m_manager;
    GridParameterDefinition m_cpd;
};

} // namespace visualization
} // namespace tbricks
