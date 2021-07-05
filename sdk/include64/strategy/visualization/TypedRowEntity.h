#pragma once
//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Typed Row Entity.
//****************************************************************************************

#include <variant>

namespace tbricks::visualization {

using TypedRowEntity = std::variant<std::monostate,
                                    class AggregateRowEntity,
                                    class AuditDataRowEntity,
                                    class CashRowEntity,
                                    class CustomPropertiesRowEntity,
                                    class InstrumentGroupRowEntity,
                                    class InstrumentRowEntity,
                                    class OrderRowEntity,
                                    class PortfolioRowEntity,
                                    class PositionRowEntity,
                                    class RequestForQuoteRowEntity,
                                    class ServiceRowEntity,
                                    class StrategyRowEntity,
                                    class TradeRowEntity,
                                    class TreeRowEntity,
                                    class UserRowEntity,
                                    class ValueProviderRowEntity>;

} // namespace tbricks::visualization
