#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// View Model Updates carrier.
//****************************************************************************************

#include <variant>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"
#include "strategy/visualization/ICellValue.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/type/ColumnIdentifier.h"
#include "strategy/visualization/RowEntityType.h"

namespace tbricks {

class STRATEGY_EXPORT Converter;

namespace types {
class Any;
}

namespace visualization {
class AppViewModelManagerImpl;
class AppLayoutViewModel;
class GridViewModel;

/**
 * CalculatedInstrumentValues::Update, collection of updated values.
 */
class STRATEGY_EXPORT ViewModelUpdate : public Printable
{
public:
    ViewModelUpdate();
    ViewModelUpdate(const ViewModelUpdate & update);
    ViewModelUpdate & operator=(const ViewModelUpdate & update);

    class Impl;
    ViewModelUpdate(Impl * impl);

    ~ViewModelUpdate() override;

public:
    bool Empty() const;
    void Clear();

public:
    class STRATEGY_EXPORT Iterator
    {
    public:
        Iterator(const ViewModelUpdate & update);
        Iterator(const Iterator & update);
        Iterator & operator=(const Iterator & iterator);
        ~Iterator();

        const ICellValue & GetCell() const;

        using IsSelected = bool;
        /**
         * Get information about cell selection (if presented)
         *
         * @returns true if cell is selected
         *          false if selection was removed
         *          empty if selection was not changed
         */
        std::optional<IsSelected> GetCellSelection() const;

        Iterator & operator++();
        bool IsLast() const;

        const ICellValue & operator*() const;
        bool operator!=(const Iterator & other);

        std::optional<RowEntityType> GetRowType() const;

    private:
        friend GridViewModel;
        friend AppLayoutViewModel;
        const types::Any & get_raw_value();

        class IteratorImpl;
        class BufferIteratorImpl;
        class RangeIteratorImpl;
        std::unique_ptr<IteratorImpl> m_impl;
    };

    Iterator begin() const;
    Iterator end() const;

    class SelectionUpdate
    {
    public:
        enum class SelectOperation
        {
            /**
             * Selection not changed
             */
            NONE,

            /**
             * Replace current selection
             */
            SELECT,

            /**
             * Extend current selection
             */
            EXTEND
        };

        enum Scope
        {
            ALL
        };

        using Cell = std::pair<RowEntityIdentifier, ColumnIdentifier>;
        using IsSelected = bool;

        /**
         * Get selection update type
         */
        SelectOperation GetSelectOperation() const { return m_operation; }

        /**
         * Modify SelectionUpdate type
         */
        void SetSelectOperation(SelectOperation operation) { m_operation = operation; }

        /**
         * Get range-based selected columns
         */
        std::map<ColumnIdentifier, IsSelected> & GetSelectedCellsColumns() { return m_columns; }

        /**
         * Get range-based selected columns
         */
        const std::map<ColumnIdentifier, IsSelected> & GetSelectedCellsColumns() const { return m_columns; }

        /**
         * Check if all rows affected
         */
        bool IsAllRowsSelected() const { return std::holds_alternative<Scope>(m_rows) && std::get<Scope>(m_rows) == ALL; }

        /**
         * Get range-based selection rows
         */
        auto & GetSelectedCellsRows() { return m_rows; }

        /**
         * Get range-based selection rows
         */
        auto & GetSelectedCellsRows() const { return m_rows; }

        /**
         * Clear selection
         */
        void Clear();

        /**
         * Check empty
         */
        bool IsEmpty() const;

        /**
         * Get information about cell selection (if presented)
         *
         * @returns true if cell is selected
         *          false if selection was removed
         *          empty if selection was not changed
         */
        std::optional<IsSelected> GetCellSelection(const Cell &) const;

    private:
        SelectOperation m_operation{SelectOperation::NONE};
        std::map<ColumnIdentifier, IsSelected> m_columns;
        std::variant<Scope, std::set<RowEntityIdentifier>> m_rows;
    };

    const SelectionUpdate & GetSelectionUpdate() const { return m_selection_update; }

    std::ostream & Print(std::ostream & strm) const override;

private:
    friend AppViewModelManagerImpl;
    friend Converter;
    SelectionUpdate & GetSelectionUpdate() { return m_selection_update; }

    SelectionUpdate m_selection_update;
    Impl * m_impl;
};

} // namespace visualization
} // namespace tbricks
