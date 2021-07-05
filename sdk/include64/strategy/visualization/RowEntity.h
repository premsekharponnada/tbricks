#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// View Model Row base.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/visualization/TypedRowEntity.h"

#include <functional>
#include <memory>
#include <optional>

namespace tbricks {
class StrategyParameters;
namespace visualization {

class IRowEntityImpl;
class Grid;

/**
 * RowEntity is base object operated by view model and used to calculate values of properties.
 */
class STRATEGY_EXPORT RowEntity
{
public:
    class Options
    {
    public:
        /**
         * Enable or disable subscription to remote view model for app related properties.
         *
         * @param subscribe        indicates if subscription is allowed
         */
        void SetSubscribeForRemoteViewModel(bool subscribe);

        /**
         * Check if subscription to remote view model is allowed in Options object.
         *
         * @return true is subscription is allowed, false otherwise
         */
        bool GetSubscribeForRemoteViewModel() const;

    private:
        bool m_subscribe_for_remote_view_model{true};
    };

    RowEntity() = delete;

    RowEntity(RowEntity && other) noexcept;

    RowEntity(const RowEntity & other) = default;

    RowEntity & operator=(const RowEntity & other) = default;

    RowEntity & operator=(RowEntity && other) noexcept;

    explicit operator const std::shared_ptr<IRowEntityImpl> &() const;

    friend bool operator==(const RowEntity & lhs, const RowEntity & rhs) { return lhs.m_row_impl == rhs.m_row_impl; }

    /**
     * Get unique entity identifier.
     *
     * @return row entity identifier
     */
    RowEntityIdentifier GetRowIdentifier() const;

    /**
     * Set row parameters for calculated values request.
     *
     * @param parameters        calculated value row parameters
     */
    void SetCalculatedValueParameters(const StrategyParameters & parameters);

    virtual ~RowEntity() = default;

    /**
     * Allows getting std::variant object containing specific row entity type.
     *
     * @return variant object containing row entity with concrete type
     */
    TypedRowEntity GetTypedRowEntity() const;

protected:
    using InitializerType = std::function<std::shared_ptr<IRowEntityImpl>()>;

    RowEntity(std::shared_ptr<IRowEntityImpl> && impl, InitializerType && initializer);

    explicit RowEntity(InitializerType && initializer);

    std::shared_ptr<IRowEntityImpl> & get_base_entity();
    const std::shared_ptr<IRowEntityImpl> & get_base_entity() const;

private:
    friend class AppViewModelManagerImpl;
    friend class AggregateRowEntity;
    friend class VisualizationAppRowEntity;
    friend class IRowEntityImpl;
    friend class Grid;

    InitializerType m_initializer;
    mutable std::shared_ptr<IRowEntityImpl> m_row_impl;
};

} // namespace visualization
} // namespace tbricks
