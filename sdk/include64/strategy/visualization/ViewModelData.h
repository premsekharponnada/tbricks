#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// View Model Data public header
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/type/Uuid.h"
#include "strategy/type/Variant.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/calculated_property/CalculatedPropertyDefinition.h"

namespace tbricks::visualization {

class RemoteAppView;
class RemoteGridView;
class RemoteViewModelImpl;

class STRATEGY_EXPORT ViewModelData : public Printable
{
public:
    /**
     * Default constructor and destructor
     */
    ViewModelData();
    ~ViewModelData() = default;

    /**
     * Copy/Move constructors. Copy/Move assignment operators
     */
    ViewModelData(const ViewModelData & data) = default;
    ViewModelData(ViewModelData &&) = default;
    ViewModelData & operator=(const ViewModelData & data) = default;
    ViewModelData & operator=(ViewModelData && data) = default;

    /**
     * Add view model data entry to target view model
     *
     * @param [in] rowIdentifier Row to set value to
     * @param [in] definition    Parameter definition, used as a key to
     *                           the container
     * @param [in] value         Variable to store parameter value
     *
     */
    void SetViewModelDataParameter(const RowEntityIdentifier & rowIdentifier, const CalculatedPropertyDefinition & definition, const Variant & value);

    /**
     * Add source identifiers to target view model from app view model
     *
     * @param [in] sourceViewModel Source app view model
     *
     */
    void SetSourceViewModel(const RemoteAppView & sourceViewModel);

    /**
     * Add source identifiers to target view model from grid view model
     *
     * @param [in] sourceViewModel Source grid view model
     *
     */
    void SetSourceViewModel(const RemoteGridView & sourceViewModel);

    /**
     * Prints contents of this object ot the stream
     *
     * @param [in] stream Where to write data
     *
     * @return std::ostream populated with data
     */
    std::ostream & Print(std::ostream & stream) const override;

protected:
    friend STRATEGY_EXPORT RemoteViewModelImpl;

    struct TableEntry
    {
        RowEntityIdentifier rowIdentifier;
        CalculatedPropertyDefinition definition;
        Variant value;
    };

    void SetSourceIdentifiers(const StrategyIdentifier & sourceStrategyId, const Uuid & sourceViewModelId);
    const std::vector<TableEntry> & GetTableValues() const;
    const StrategyIdentifier & GetSourceStrategyIdentifier() const;
    const Uuid & GetSourceViewModelIdentifier() const;

private:
    std::vector<TableEntry> m_tableValues;

    StrategyIdentifier m_sourceStrategyId;
    Uuid m_sourceViewModelId;
};

} // namespace tbricks::visualization
