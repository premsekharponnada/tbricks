#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// View Model Values Provider Row Entity.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/Variant.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/visualization/RowEntity.h"

namespace tbricks::visualization {

class IRowEntityImpl;

/**
 * Row entity values provider interface
 */
class STRATEGY_EXPORT ValueProviderRowEntity : public RowEntity
{
public:
    /**
     * Values provider for ValueProviderRowEntity. Can provide data for one or multiple entities.
     */
    class IRowValuesProvider : public std::enable_shared_from_this<IRowValuesProvider>
    {
    public:
        /**
         * Cell values calculation callback.
         *
         * @return value must be absolute
         */
        virtual std::optional<Variant> GetValue(const RowEntityIdentifier & row_id, const CalculatedProperty & property) = 0;

        virtual ~IRowValuesProvider() = default;
    };

    ValueProviderRowEntity();
    explicit ValueProviderRowEntity(std::shared_ptr<IRowValuesProvider> &&);

    ValueProviderRowEntity(const ValueProviderRowEntity & other) = default;
    ValueProviderRowEntity(ValueProviderRowEntity && other) noexcept = default;
    ValueProviderRowEntity & operator=(const ValueProviderRowEntity & other) = default;
    ValueProviderRowEntity & operator=(ValueProviderRowEntity && other) noexcept = default;

    /**
     * Get data provider of this row entity.
     *
     * @note can be equal to nullptr
     */
    const std::shared_ptr<IRowValuesProvider> & GetDataProvider() const;

    /**
     * Assign data provider to this row entity.
     *
     * @note pass nullptr to reset data provider.
     */
    void SetDataProvider(const std::shared_ptr<IRowValuesProvider> & data);

    /**
     * Update data in view model.
     *
     * Should be called when IRowValuesProvider state changed.
     */
    void DataChanged();

    ~ValueProviderRowEntity() = default;
};

} // namespace tbricks::visualization
