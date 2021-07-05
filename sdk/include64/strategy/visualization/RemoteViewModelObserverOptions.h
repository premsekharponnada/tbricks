#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Remote app view model options public header
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/SparseHash.h"
#include "strategy/visualization/RemoteViewModelObserver.h"

namespace tbricks {
class CalculatedProperty;
class Uuid;

namespace visualization {

class STRATEGY_EXPORT RemoteViewModelObserver::Options : public Printable
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

    /**
     * Prints contents of this object ot the stream
     *
     * @param [in] stream Where to write data
     *
     * @return std::ostream populated with data
     */
    std::ostream & Print(std::ostream & stream) const override;

private:
    friend STRATEGY_EXPORT RemoteViewModelObserver;
    // Alias to Calculated property
    SparseHash<Uuid, CalculatedProperty> m_columns;
};

} // namespace visualization
} // namespace tbricks
