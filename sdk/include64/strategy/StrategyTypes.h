#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//****************************************************************************************

#include "strategy/type/OrderBookChangeReason.h"
#include "strategy/type/LiquidityIndicator.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/Volume.h"
#include "strategy/type/CFIMask.h"
#include "strategy/type/TransactionState.h"
#include "strategy/type/String.h"
#include "strategy/type/Venue.h"
#include "strategy/type/OrderStatus.h"
#include "strategy/type/PublicTradeIdentifier.h"
#include "strategy/type/CombinationType.h"
#include "strategy/type/MarketCommandType.h"
#include "strategy/type/cfi_attributes/Delivery.h"
#include "strategy/type/Uuid.h"
#include "strategy/type/TimeZone.h"
#include "strategy/type/TransitionType.h"
#include "strategy/type/PluginType.h"
#include "strategy/type/PostingActionType.h"
#include "strategy/type/PriceStructure.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Trend.h"
#include "strategy/type/Double.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/CFIAttributes.h"
#include "strategy/type/SmartDouble.h"
#include "strategy/type/TableActions.h"
#include "strategy/type/OwnQuoteBookType.h"
#include "strategy/type/AlertType.h"
#include "strategy/type/MIC.h"
#include "strategy/type/TypeWithError.h"
#include "strategy/type/TimeZoneIdentifiers.h"
#include "strategy/type/AlgoLabelType.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/MMTFlags.h"
#include "strategy/type/SymbologyKey.h"
#include "strategy/type/Duration.h"
#include "strategy/type/Field.h"
#include "strategy/type/LegalEntityIdentifier.h"
#include "strategy/type/Currency.h"
#include "strategy/type/MMTFlags_2_2.h"
#include "strategy/type/Binary.h"
#include "strategy/type/TickCount.h"
#include "strategy/type/MMTFlags_3_04.h"
#include "strategy/type/ParticipationPolicy.h"
#include "strategy/type/PricePolicy.h"
#include "strategy/type/ExecutionPolicy.h"
#include "strategy/type/VenueInstrumentIdentifier.h"
#include "strategy/type/AlgoType.h"
#include "strategy/type/Price.h"
#include "strategy/type/Integer.h"
#include "strategy/type/TradeType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/LiquidityPool.h"
#include "strategy/type/TypeInfo.h"
#include "strategy/type/BinaryTable.h"
#include "strategy/type/LicenseType.h"
#include "strategy/type/StrategyState.h"
#include "strategy/type/UniqueTradeIdentifier.h"
#include "strategy/type/OrderTemplateIdentifier.h"
#include "strategy/type/CalendarDate.h"
#include "strategy/type/Validity.h"
#include "strategy/type/OrderCapacity.h"
#include "strategy/type/CFI.h"
#include "strategy/type/StdInt.h"
#include "strategy/type/Side.h"
#include "strategy/type/InstrumentGroup.h"
#include "strategy/type/cfi/CFICategory.h"
#include "strategy/type/cfi/CFIAttribute.h"
#include "strategy/type/cfi/CFIGroup.h"
#include "strategy/type/LiquiditySource.h"
#include "strategy/type/Time.h"
#include "strategy/type/MMTFlag.h"
#include "strategy/type/TradeAttributes.h"
#include "strategy/type/Status.h"
#include "strategy/type/Enumeration.h"
#include "strategy/type/StrategyTransactionOperation.h"
#include "strategy/type/ServiceType.h"
#include "strategy/type/HandlingInstruction.h"
#include "strategy/type/Date.h"
#include "strategy/type/MarketDataToUse.h"
#include "strategy/type/Table.h"
#include "strategy/type/QualifiedRole.h"
#include "strategy/type/UserAuthenticationType.h"
#include "strategy/Enums.h"
#include "strategy/type/BlockOrderLegIdentifier.h"
#include "strategy/type/RowEntityIdentifier.h"
#include "strategy/type/CarveoutIdentifier.h"
#include "strategy/type/VenueIdentifier.h"
#include "strategy/type/RequestForTradeIdentifier.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/DirectedQuoteLegIdentifier.h"
#include "strategy/type/BlockOrderIdentifier.h"
#include "strategy/type/StrategyIdentifier.h"
#include "strategy/type/QuoteIdentifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/DirectedQuoteIdentifier.h"
#include "strategy/type/RequestForTradeLegIdentifier.h"
#include "strategy/type/EventIdentifier.h"
#include "strategy/type/DirectedQuoteGeneration.h"
#include "strategy/type/StreamItemIdentifier.h"
#include "strategy/type/TradeIdentifier.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/QuoteRequestIdentifier.h"
#include "strategy/type/ColumnIdentifier.h"
#include "strategy/type/DirectedQuoteResponseIdentifier.h"
#include "strategy/type/DirectedQuoteRequestIdentifier.h"
#include "strategy/type/UserIdentifier.h"
#include "strategy/type/RoleIdentifier.h"
#include "strategy/type/RankingIdentifier.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/AuditableIdentifier.h"
#include "strategy/type/DirectedQuoteResponseGeneration.h"
#include "strategy/type/StreamIdentifier.h"
#include "strategy/type/TreeTypeIdentifier.h"
#include "strategy/type/SystemIdentifier.h"
#include "strategy/type/ExPitDealIdentifier.h"
#include "strategy/type/ExPitIdentifier.h"
#include "strategy/type/NodeIdentifier.h"
#include "strategy/type/OrderIdentifier.h"
#include "strategy/type/ComponentIdentifier.h"
#include "strategy/type/SubsystemIdentifier.h"
#include "strategy/type/ContextIdentifier.h"
#include "strategy/type/ServiceIdentifier.h"