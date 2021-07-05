#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// App view model options public header
//****************************************************************************************

#include "strategy/Definitions.h"
#include "strategy/visualization/RemoteGridView.h"

namespace tbricks {

class Uuid;
template <typename Type>
class Value;

namespace visualization {

class STRATEGY_EXPORT RemoteGridView::Options : public Printable
{
public:
    /**
     * Default constructor and destructor
     */
    Options() = default;
    ~Options() = default;

    /**
     * Copy/Move constructors. Copy/Move assignment operators
     */
    Options(const Options & options) = default;
    Options(Options && options) = default;
    Options & operator=(const Options & options) = default;
    Options & operator=(Options && options) = default;
    /**
     * Add sorting order to the target view model
     *
     * @param [in] columnProperty Absolute property of a visible column
     * @param [in] columnAlias    Unique identifier of the absolute property to distinguish
     *                            it from a duplicated absolute properties in one vm
     * @param [in] order          Sorting order for this column
     *
     * @return true if insertion was successful, false if such alias is already present
     *
     * @throws EmptyValueException if provided identifier is empty
     */
    bool AddSortingOrder(const CalculatedProperty & columnProperty, const Uuid & columnAlias, SortingOrder order);

    /**
     * Add grouping to the target view model
     *
     * @param [in] columnProperty Absolute property of a visible column
     * @param [in] columnAlias    Unique identifier of the absolute property to distinguish
     *                            it from a duplicated absolute properties in one vm
     *
     * @return true if insertion was successful, false if such alias is already present
     *
     * @throws EmptyValueException if provided identifier is empty
     */
    bool AddGrouping(const CalculatedProperty & columnProperty, const Uuid & columnAlias);

    /**
     * Set page options for this view model
     *
     * @param [in] pageStart Specifies the index of the first row in the page of an app view model
     * @param [in] pageSize  Number of rows in the page of an app view model
     */
    void SetPageOptions(const Integer & pageStart, const Integer & pageSize);

    /**
     * Gets current page start
     *
     * @return current page start value
     */
    Integer GetPageStart() const;

    /**
     * Gets current page size
     *
     * @return current page size value
     */
    Integer GetPageSize() const;

    /**
     * Prints contents of this object ot the stream
     *
     * @param [in] stream Where to write data
     *
     * @return std::ostream populated with data
     */
    std::ostream & Print(std::ostream & stream) const override;

    /**
     * Add visible column to the target view model
     *
     * @param [in] columnProperty Absolute property of a visible column
     * @param [in] columnAlias    Unique identifier of the absolute property to distinguish
     *                            it from a duplicated absolute properties in one vm
     *
     * @return true if insertion was successful, false if such alias is already present
     *
     * @throws EmptyValueException if provided identifier is empty
     */
    bool AddVisibleColumn(const CalculatedProperty & columnProperty, const Uuid & columnAlias);

    /**
     * Add visible column to the target view model
     *
     * @param [in] columnProperty Absolute property of a visible column
     *
     * @return column id of added property
     *
     */
    ColumnIdentifier AddVisibleColumn(const CalculatedProperty & columnProperty);

private:
    friend STRATEGY_EXPORT RemoteGridView;

    struct SortEntry
    {
        CalculatedProperty property;
        SortingOrder order;
    };

    Integer m_pageStart;
    Integer m_pageSize;

    // Alias to Calculated property
    SparseHash<Uuid, CalculatedProperty> m_columns;
    // Alias to Calculated property
    SparseHash<Uuid, SortEntry> m_sortings;
    SparseHash<Uuid, CalculatedProperty> m_groupings;
};

} // namespace visualization
} // namespace tbricks
