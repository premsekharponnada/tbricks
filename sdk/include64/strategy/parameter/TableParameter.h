#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Table type.
//****************************************************************************************

#include "strategy/type/Table.h"
#include "strategy/parameter/Parameter.h"

// \namespace tbricks
namespace tbricks {

class StrategyParameters;

class STRATEGY_EXPORT TableParameter : public Parameter
{
public:
    TableParameter(const ParameterDefinition & definition);
    TableParameter(const TableParameter & parameter);

    TableParameter & operator=(const Table & table);
    TableParameter & operator=(const TableParameter & parameter);

    const Table & GetTable() const;
    operator const Table &() const;

    /**
     * Get internal table type.
     *
     * @param value             Table type - primary or partial
     */
    Table::Type GetTableType() const;

    /**
     * Insert new column into table.
     *
     * @param column_id         Column identifier
     * @param type              Column data type information
     * @param indexed           Indicates whether the column can be as a key to search relevant data.
     *                          True - indexed, otherwise not. Not indexed by default.
     */
    void InsertColumn(const Uuid & column_id, const TypeInfo & type, bool indexed = false);

    /**
     * Insert new column into table.
     *
     * @param def               Parameter definition which would be used as column description
     * @param indexed           Indicates whether the column can be as a key to search relevant data.
     *                          True - indexed, otherwise not. Not indexed by default.
     */
    void InsertColumn(const ParameterDefinition & def, bool indexed = false);

    /**
     * Remove column from table.
     *
     * @param column_id         Column identifier
     *
     * @return                  True if column was successfully removed
     */
    bool RemoveColumn(const Uuid & column_id);

    /**
     * Remove column from table.
     *
     * @param def               Parameter definition
     *
     * @return                  True if column was successfully removed
     */
    bool RemoveColumn(const ParameterDefinition & def);

    /**
     * Insert new row into table
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *                          New row will be inserted before row specified in row_id
     */
    void InsertRow(size_t row_id);

    /**
     * Append row to the end of the table.
     *
     */
    void AddRow();

    /**
     * Remove row from table
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @return                  True if row was successfully removed
     *
     */
    bool RemoveRow(size_t row_id);

    /**
     * Remove row from table by key
     *
     * @param key_column_id     Column identifier of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @return                  True if row was successfully removed
     *
     */
    bool RemoveRow(const Uuid & key_column_id, const AnyType & key_cell);

    /**
     * Remove row from table by key
     *
     * @param key_def           Column parameter definition of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @return                  True if row was successfully removed
     *
     */
    bool RemoveRow(const DefinitionBase & key_def, const AnyType & key_cell);

    /**
     * Update cells for specific row from parameters container.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @param parameters        Strategy parameters container.
     *                          This function will try to match each parameter definition with table column
     *                          and then copy parameter value to table cell
     *
     */
    void UpdateRow(size_t row_id, const StrategyParameters & parameters);

    /**
     * Find placement of the cell value for specified column
     * For indexed columns this function works with O(log2(N)) complexity,
     * otherwise with O(N) complexity where N is number of rows in table.
     *
     * @param column_id         Column identifier
     * @param cell              Table cell value (value data type should be the same as column data type)
     * @param from_row          Row identifier to start search. Default value -1 indicates that the search
     *                          will be started from the beginning of column. If you pass the previous result
     *                          of FindRow function, then you can enumerate all duplicates for the specific value.
     *
     * @return                  Row identifier for succesfull search. Or -1 if specified value cannot be found.
     *
     */
    int FindRow(const Uuid & column_id, const AnyType & cell, int from_row = -1) const;

    /**
     * Find placement of the cell value for specified column
     * For indexed columns this function works with O(log2(N)) complexity,
     * otherwise with O(N) complexity where N is number of rows in table.
     *
     * @param def               Parameter definition which would be used as column description.
     * @param cell              Table cell value (value data type should be the same as column data type)
     * @param from_row          Row identifier to start search. Default value -1 indicates that the search
     *                          will be started from the beginning of column. If you pass the previous result
     *                          of FindRow function, then you can enumerate all duplicates for the specific value.
     *
     * @return                  Row identifier for succesfull search. Or -1 if specified value cannot be found.
     *
     */
    int FindRow(const ParameterDefinition & def, const AnyType & cell, int from_row = -1) const;

    /**
     * Modify table cell
     *
     * @param column_id         Column identifier.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @param cell              Table cell value (value data type should be the same as column data type)
     *
     */
    void UpdateCell(const Uuid & column_id, size_t row_id, const AnyType & cell);

    /**
     * Modify table cell.
     *
     * @param def               Parameter definition which would be used as column description.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @param cell              Table cell value (value data type should be the same as column data type)
     *
     */
    void UpdateCell(const ParameterDefinition & def, size_t row_id, const AnyType & cell);

    /**
     * Modify table cell
     *
     * @param pos               Table position object which contain column and row identifiers.
     *
     * @param cell              Table cell value (value data type should be the same as column data type)
     *
     */
    void UpdateCell(const TablePosition & pos, const AnyType & cell);

    /**
     * Modify table cell with key value.
     *
     * @param key_column_id     Column identifier of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @param column_id         Identifier of the column which data you want to modify.
     *
     * @param cell              Table cell value (value data type should be the same as column data type)
     *
     */
    void UpdateCell(const Uuid & key_column_id, const AnyType & key_cell, const Uuid & column_id, const AnyType & cell);

    /**
     * Modify table cell with key value.
     *
     * @param key_def           Column parameter definition of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @param def               Parameter definition for the column which data you want to modify.
     *
     * @param cell              Table cell value (value data type should be the same as column data type)
     *
     */
    void UpdateCell(const DefinitionBase & key_def, const AnyType & key_cell, const DefinitionBase & def, const AnyType & cell);

    /**
     * Modify table cell to empty state.
     *
     * @param column_id         Column identifier.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     */
    void ClearCell(const Uuid & column_id, size_t row_id);

    /**
     * Modify table cell to empty state.
     *
     * @param column_id         Column identifier.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     */
    void ClearCell(const ParameterDefinition & def, size_t row_id);

    /**
     * Modify table cell to empty state.
     *
     * @param pos               Table position object which contain column and row identifiers.
     *
     */
    void ClearCell(const TablePosition & pos);

    /**
     * Modify all table cells to empty state.
     *
     */
    void ClearAllCells();

    /**
     * Retrieve table cell value.
     *
     * @param column_id         Column identifier.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @param cell              Output value
     *
     * @return                  true - cell has value
     *                          false - cell value is empty
     *
     */
    bool GetCell(const Uuid & column_id, size_t row_id, AnyType & cell) const;

    /**
     * Retrieve table cell value.
     *
     * @param def               Parameter definition which would be used as column description.
     *
     * @param row_id            Row identifier.
     *                          Number of a row from 0 to N-1 where N is number of rows in table.
     *
     * @param cell              Output value
     *
     * @return                  true - cell has value
     *                          false - cell value is empty
     *
     */
    bool GetCell(const ParameterDefinition & def, size_t row_id, AnyType & cell) const;

    /**
     * Retrieve table cell value
     *
     * @param pos               Table position object which contain column and row identifiers.
     *
     * @param cell              Output value
     *
     * @return                  true - cell has value
     *                          false - cell value is empty
     *
     */
    bool GetCell(const TablePosition & pos, AnyType & cell) const;

    /**
     * Retrieve table cell value.
     *
     * @param key_column_id     Column identifier of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @param column_id         Identifier of the column which data you want to retrieve.
     *
     * @param cell              Output value
     *
     * @return                  true - if key column has value specified in key_cell
     *                          false - otherwise
     *
     */
    bool GetCell(const Uuid & key_column_id, const AnyType & key_cell, const Uuid & column_id, AnyType & cell) const;

    /**
     * Retrieve table cell value
     *
     * @param key_def           Column parameter definition of the column to search data.
     *                          Specified column should be indexed.
     *
     * @param key_cell          Cell value to search row.
     *                          (value data type should be the same as key column data type)
     *
     * @param def               Parameter definition for the column which data you want to retrieve.
     *
     * @param cell              Output value
     *
     * @return                  true - if key column has value specified in key_cell
     *                          false - otherwise
     *
     */
    bool GetCell(const DefinitionBase & key_def, const AnyType & key_cell, const DefinitionBase & def, AnyType & cell) const;

    /**
     * Move cell value from one position to another.
     *
     * @param column_id_from    Column identifier of the original cell position
     *
     * @param row_id_from       Row identifier of the original cell position
     *
     * @param column_id_to      Column identifier of the position which you want to move cell
     *
     * @param row_id_to         Row identifier of the position which you want to move cell
     *
     */
    void MoveCell(const Uuid & column_id_from, size_t row_id_from, const Uuid & column_id_to, size_t row_id_to);

    /**
     * Move cell value from one position to another.
     *
     * @param def_from          Parameter definition for column of the original cell position
     *
     * @param row_id_from       Row identifier of the original cell position
     *
     * @param def_to            Parameter definition for column of the position which you want to move cell
     *
     * @param row_id_to         Row identifier of the position which you want to move cell
     *
     */
    void MoveCell(const ParameterDefinition & def_from, size_t row_id_from, const ParameterDefinition & def_to, size_t row_id_to);

    /**
     * Move cell value from one position to another.
     *
     * @param pos_from          Original cell position
     *
     * @param pos_to            Position which you want to move cell
     *
     */
    void MoveCell(const TablePosition & pos_from, const TablePosition & pos_to);

    /**
     * Get table partial update actions list.
     *
     * @return                  Actions list object.
     *
     */
    const Table::Update & GetUpdate() const;

    /**
     * Get number of columns
     *
     * @return                  Number of columns.
     *
     */
    size_t GetColumnCount() const;

    /**
     * Retrieve table columns list.
     *
     * @param columns           Output value. Vector filled with column identifiers.
     *
     */
    void GetColumns(std::vector<Uuid> & columns) const;

    /**
     * Get number of rows.
     *
     * @return                  Number of rows.
     *
     */
    size_t GetRowCount() const;

    /**
     * Remove all columns and rows.
     *
     */
    void Clear();

    /**
     * Merge data with another table or table partial update.
     * In case of partial update table cells will be merged,
     * otherwise table will be replaced by 'other'
     *
     * @param other             Primary table parameter or partial update table parameter.
     *
     */
    void Merge(const TableParameter & other);

    /**
     * Merge data with another table or table partial update.
     * In case of partial update table cells will be merged,
     * otherwise table will be replaced by 'other'
     *
     * @param other             Primary table or partial update.
     *
     */
    void Merge(const Table & other);

    class Impl;

private:
    Impl * m_impl;
};

} // \namespace tbricks
