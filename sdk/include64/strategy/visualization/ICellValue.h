#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Visualization cell interface.
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/type/ColumnIdentifier.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/calculated_property/CalculatedProperty.h"

namespace tbricks {

class Uuid;
class Variant;

namespace visualization {

enum class CellValueDirection
{
    INPUT = 1,
    OUTPUT = 2,
    INPUT_OUTPUT = 3
};

class STRATEGY_EXPORT ICellValue
{
public:
    /**
     * Unique column identifier
     *
     * @returns ColumnIdentifier
     */
    virtual const ColumnIdentifier & GetColumnIdentifier() const = 0;

    /**
     * Column's CalculatedProperty
     */
    virtual const CalculatedProperty & GetCalculatedProperty() const = 0;

    /**
     * Unique row identifier
     *
     * @returns RowEntityIdentifier
     */
    virtual const RowEntityIdentifier & GetRowIdentifier() const = 0;

    /**
     *  Check if cell value is included into the update
     */
    virtual bool HasCellValue() const = 0;

    /**
     * Get value of the current cell
     */
    virtual const Variant & GetCellValue() const = 0;

    /**
     *  Check if cell display value is included into the update
     */
    virtual bool HasCellDisplayValue() const = 0;

    /**
     * Get display value of the current cell
     */
    virtual const Variant & GetCellDisplayValue() const = 0;

    /**
     * Is cell removed from current view
     */
    virtual bool IsRemove() const = 0;

    /**
     * Get CellValueDirection for current cell
     */
    virtual CellValueDirection GetDirection() const = 0;

    virtual ~ICellValue() = default;
};

class STRATEGY_EXPORT ICellValue;

class STRATEGY_EXPORT CellValue
{
public:
    CellValue(std::shared_ptr<ICellValue> && cell_value) : m_cell_value(std::move(cell_value)) {}

    CellValue(const CellValue & other) = default;
    CellValue(CellValue && other) noexcept = default;
    CellValue & operator=(const CellValue & other) = default;
    CellValue & operator=(CellValue && other) noexcept = default;

    /**
     * Unique column identifier
     *
     * @returns ColumnIdentifier
     *
     */
    const ColumnIdentifier & GetColumnIdentifier() const { return m_cell_value->GetColumnIdentifier(); }

    /**
     * Unique row identifier
     *
     * @returns RowEntityIdentifier
     */
    const RowEntityIdentifier & GetRowIdentifier() const { return m_cell_value->GetRowIdentifier(); }

    /**
     * Column's CalculatedProperty
     */
    const CalculatedProperty & GetCalculatedProperty() const { return m_cell_value->GetCalculatedProperty(); }

    /**
     * Get value of the current cell
     */
    const Variant & GetCellValue() const { return m_cell_value->GetCellValue(); }

    /**
     * Is cell removed from current view
     */
    bool IsRemove() const { return m_cell_value->IsRemove(); }

    /**
     * Get CellValueDirection for current cell
     */
    CellValueDirection GetDirection() const { return m_cell_value->GetDirection(); }

    virtual ~CellValue() = default;

private:
    std::shared_ptr<ICellValue> m_cell_value;
};

} // namespace visualization
} // namespace tbricks
