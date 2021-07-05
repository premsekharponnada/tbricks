#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TestEngine is a Plugin Engine representation,
// which can be used for plugin execution.
//****************************************************************************************

#include "strategy/Types.h"
#include "strategy/Filters.h"
#include "strategy/Parameters.h"
#include "strategy/StrategyTypes.h"
#include "strategy/Streams.h"
#include "strategy/Component.h"
#include "strategy/Alert.h"
#include "strategy/AlertParameterDefinition.h"
#include "strategy/AlertParameters.h"
#include "strategy/AlgoLabel.h"
#include "strategy/AlgoLabelManualOperations.h"
#include "strategy/AuditData.h"
#include "strategy/AuditPolicy.h"
#include "strategy/Auditable.h"
#include "strategy/BestPrice.h"
#include "strategy/BlockOrder.h"
#include "strategy/BlockOrderLeg.h"
#include "strategy/BlockOrderManager.h"
#include "strategy/CSVParser.h"
#include "strategy/CalculatedPropertiesDictionary.h"
#include "strategy/Carveout.h"
#include "strategy/Cash.h"
#include "strategy/CashFlow.h"
#include "strategy/CircuitBreaker.h"
#include "strategy/CombinationCreator.h"
#include "strategy/ComparisonResult.h"
#include "strategy/ContributionManager.h"
#include "strategy/DefinitionBase.h"
#include "strategy/Action.h"
#include "strategy/Depth.h"
#include "strategy/DirectedQuoteRequestCapabilities.h"
#include "strategy/DllInterface.h"
#include "strategy/EnumDefinition.h"
#include "strategy/ErrorProcessing.h"
#include "strategy/Event.h"
#include "strategy/EventProcessor.h"
#include "strategy/ExPit.h"
#include "strategy/ExPitManager.h"
#include "strategy/Exception.h"
#include "strategy/Exceptions.h"
#include "strategy/ExecutionPolicySet.h"
#include "strategy/Expiration.h"
#include "strategy/ExpirationOld.h"
#include "strategy/ExtraData.h"
#include "strategy/FX.h"
#include "strategy/GermanHFTAlgoLabel.h"
#include "strategy/GridParameterDefinition.h"
#include "strategy/Hash.h"
#include "strategy/InitializationReason.h"
#include "strategy/Instrument.h"
#include "strategy/InstrumentComponent.h"
#include "strategy/InstrumentModifier.h"
#include "strategy/InstrumentOptions.h"
#include "strategy/InstrumentStatus.h"
#include "strategy/InstrumentTradingInformation.h"
#include "strategy/InstrumentVenueIdentification.h"
#include "strategy/Instruments.h"
#include "strategy/IrdXmlPrinter.h"
#include "strategy/LatencyTimer.h"
#include "strategy/License.h"
#include "strategy/LimitSettings.h"
#include "strategy/LimitSettingsParameters.h"
#include "strategy/Linkage.h"
#include "strategy/LogEntry.h"
#include "strategy/Logger.h"
#include "strategy/MarketCommandCapabilities.h"
#include "strategy/MarketCommandRequest.h"
#include "strategy/MarketDataCapabilities.h"
#include "strategy/MarketDataParameterDefinition.h"
#include "strategy/MarketDataParameters.h"
#include "strategy/MarketMessage.h"
#include "strategy/Matrix.h"
#include "strategy/MemoryGuard.h"
#include "strategy/Order.h"
#include "strategy/OrderBook.h"
#include "strategy/OrderCapacitySet.h"
#include "strategy/OrderManager.h"
#include "strategy/OwnPriceLevelQuoteBook.h"
#include "strategy/OwnQuoteBook.h"
#include "strategy/Pair.h"
#include "strategy/ParameterContext.h"
#include "strategy/Percentiles.h"
#include "strategy/PerformanceEventTree.h"
#include "strategy/Portfolio.h"
#include "strategy/PortfolioParameterDefinition.h"
#include "strategy/PortfolioParameters.h"
#include "strategy/Position.h"
#include "strategy/PriceLevelOrderBook.h"
#include "strategy/Printable.h"
#include "strategy/PublicTrade.h"
#include "strategy/QoS.h"
#include "strategy/QuoteRequest.h"
#include "strategy/Ranking.h"
#include "strategy/ReferenceExchangeRate.h"
#include "strategy/ReferencePrice.h"
#include "strategy/RegulatoryParameterDefinition.h"
#include "strategy/RegulatoryParameters.h"
#include "strategy/Report.h"
#include "strategy/RequestForQuote.h"
#include "strategy/RequestForTrade.h"
#include "strategy/RequestForTradeLeg.h"
#include "strategy/RequestForTradeOptions.h"
#include "strategy/Resource.h"
#include "strategy/ResourceModifier.h"
#include "strategy/ResourceOptions.h"
#include "strategy/Role.h"
#include "strategy/SafePointer.h"
#include "strategy/SchedulingPolicy.h"
#include "strategy/Service.h"
#include "strategy/ServiceStatus.h"
#include "strategy/Set.h"
#include "strategy/SettlementCalendar.h"
#include "strategy/SharedPointer.h"
#include "strategy/SparseHash.h"
#include "strategy/SparseSet.h"
#include "strategy/StackTrace.h"
#include "strategy/Statistics.h"
#include "strategy/Strategy.h"
#include "strategy/StrategyAttributes.h"
#include "strategy/StrategyData.h"
#include "strategy/StrategyInstruments.h"
#include "strategy/StrategyModifier.h"
#include "strategy/StrategyOptions.h"
#include "strategy/StrategyStateSet.h"
#include "strategy/StrategyType.h"
#include "strategy/StrategyTypeUpdate.h"
#include "strategy/StrategyUpdate.h"
#include "strategy/StringDictionary.h"
#include "strategy/Subsystem.h"
#include "strategy/System.h"
#include "strategy/TCPAcceptor.h"
#include "strategy/TickRule.h"
#include "strategy/Timer.h"
#include "strategy/Trade.h"
#include "strategy/TreeNode.h"
#include "strategy/Types.h"
#include "strategy/calculated_property/CalculatedPropertiesRequest.h"
#include "strategy/calculated_property/CalculatedPropertiesTable.h"
#include "strategy/calculated_property/CalculatedPropertyDefinition.h"
#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/calculated_property/CalculatedPropertyFilter.h"
#include "strategy/calculated_property/GridSelection.h"
#include "strategy/directed_quoting/DirectedQuoteManager.h"
#include "strategy/directed_quoting/DirectedQuoteReject.h"
#include "strategy/directed_quoting/DirectedQuoteRequest.h"
#include "strategy/directed_quoting/DirectedQuoteRequestLeg.h"
#include "strategy/directed_quoting/DirectedQuoteRequestManager.h"
#include "strategy/directed_quoting/DirectedQuoteResponse.h"
#include "strategy/directed_quoting/DirectedRequestForQuote.h"
#include "strategy/directed_quoting/CounterpartInformation.h"
#include "strategy/directed_quoting/DirectedQuote.h"
#include "strategy/directed_quoting/DirectedQuoteLeg.h"
#include "strategy/distributed_values/DistributedValueDefinition.h"
#include "strategy/distributed_values/DistributedValueIdentification.h"
#include "strategy/distributed_values/DistributedValues.h"
#include "strategy/distributed_values/DistributedValuesRequest.h"
#include "strategy/distributed_values/IDistributionApp.h"
#include "strategy/fix/Enums.h"
#include "strategy/fix/Group.h"
#include "strategy/fix/Message.h"
#include "strategy/fix/MessageBuilder.h"
#include "strategy/fix/Session.h"
#include "strategy/flow/AppRequestContext.h"
#include "strategy/flow/AppResponseContext.h"
#include "strategy/flow/BlockOrderRequestContext.h"
#include "strategy/flow/CarveoutRequestContext.h"
#include "strategy/flow/DirectedQuoteRequestContext.h"
#include "strategy/flow/ExPitRequestContext.h"
#include "strategy/flow/FlowApp.h"
#include "strategy/flow/OrderRequestContext.h"
#include "strategy/flow/PartitioningType.h"
#include "strategy/flow/BlockOrderResponseContext.h"
#include "strategy/flow/CarveoutResponseContext.h"
#include "strategy/flow/DirectedQuoteResponseContext.h"
#include "strategy/flow/ExPitResponseContext.h"
#include "strategy/flow/OrderResponseContext.h"
#include "strategy/generated/OrderModifyBase.h"
#include "strategy/instrument/InstrumentAggregateParameters.h"
#include "strategy/instrument/InstrumentAttributeDefinition.h"
#include "strategy/instrument/InstrumentAttributes.h"
#include "strategy/instrument/InstrumentGroupAggregateParameters.h"
#include "strategy/instrument/InstrumentParameterDefinition.h"
#include "strategy/instrument/InstrumentParameters.h"
#include "strategy/instrument/InstrumentParametersStreamOptions.h"
#include "strategy/instrument/ParameterSource.h"
#include "strategy/instrument/InstrumentGroupParameters.h"
#include "strategy/instrument/CalculatedInstrumentValues.h"
#include "strategy/limit/LimitsWarmupRequest.h"
#include "strategy/limit/TradingAggregatedLimitRule.h"
#include "strategy/limit/TradingLimitResult.h"
#include "strategy/limit/TradingLimitRule.h"
#include "strategy/limit/TradingLimitRuleProvider.h"
#include "strategy/limit/TradingLimitRuleUpdate.h"
#include "strategy/limit/TradingLimitState.h"
#include "strategy/limit/TradingLimitRuleRequest.h"
#include "strategy/mdp/MarketDataItem.h"
#include "strategy/mdp/MarketDataProvider.h"
#include "strategy/mdp/OrderBookItem.h"
#include "strategy/pricing/CalculatedValue.h"
#include "strategy/pricing/CalculatedValuesRequest.h"
#include "strategy/pricing/CalculatedValuesRequestFull.h"
#include "strategy/pricing/CalculatedValuesRequestUpdate.h"
#include "strategy/pricing/InstrumentCalculatedValueDefinition.h"
#include "strategy/pricing/OverrideValue.h"
#include "strategy/pricing/Pricing.h"
#include "strategy/pricing/PricingRequest.h"
#include "strategy/quote_information/CurrentQuotes.h"
#include "strategy/quote_information/QuoteIdentifierMapping.h"
#include "strategy/quoting/Quote.h"
#include "strategy/quoting/QuoteAudit.h"
#include "strategy/quoting/QuoteFill.h"
#include "strategy/quoting/QuoteIdentification.h"
#include "strategy/quoting/QuoteSet.h"
#include "strategy/quoting/QuoteSetProxy.h"
#include "strategy/quoting/QuoteTable.h"
#include "strategy/quoting/QuoteVolumesTable.h"
#include "strategy/rankings/EnumerationRanking.h"
#include "strategy/rankings/ParameterContextRanking.h"
#include "strategy/rankings/RankingBase.h"
#include "strategy/rbac/RbacOperation.h"
#include "strategy/rbac/RbacPrivilege.h"
#include "strategy/stream_throttle/BestPriceThrottle.h"
#include "strategy/stream_throttle/CommonThrottle.h"
#include "strategy/stream_throttle/InstrumentParametersThrottle.h"
#include "strategy/stream_throttle/InstrumentThrottle.h"
#include "strategy/stream_throttle/ParametersThrottle.h"
#include "strategy/stream_throttle/StatisticsThrottle.h"
#include "strategy/stream_throttle/StrategyParametersThrottle.h"
#include "strategy/stream_throttle/Throttle.h"
#include "strategy/stream_throttle/TradingLimitRuleThrottle.h"
#include "strategy/test/VirtualServiceExpitTrading.h"
#include "strategy/test/VirtualServiceOrderPersistence.h"
#include "strategy/test/VirtualServiceQuoting.h"
#include "strategy/test/VirtualServiceTrading.h"
#include "strategy/test/VirtualServiceTradingReferenceData.h"
#include "strategy/test/VirtualXRayEngine.h"
#include "strategy/test/OrderBook.h"
#include "strategy/test/CalculatedInstrumentValuesTable.h"
#include "strategy/test/CalculatedPropertiesTableUpdate.h"
#include "strategy/test/CalculatedValuesRequest.h"
#include "strategy/test/DirectedQuoteRequestOptions.h"
#include "strategy/test/InstrumentParametersUpdate.h"
#include "strategy/test/OrderOptions.h"
#include "strategy/test/RequestForTrade.h"
#include "strategy/test/RequestForTradeOptions.h"
#include "strategy/test/VirtualServiceRequestForQuote.h"
#include "strategy/test/PositionOptions.h"
#include "strategy/test/VirtualServiceMatchingEngine.h"
#include "strategy/test/TimerController.h"
#include "strategy/test/CashOptions.h"
#include "strategy/test/DirectedRequestForQuoteOptions.h"
#include "strategy/test/PluginOptions.h"
#include "strategy/test/PortfolioOptions.h"
#include "strategy/test/QuoteFill.h"
#include "strategy/test/VirtualCalculationStream.h"
#include "strategy/test/IVirtualService.h"
#include "strategy/test/DirectedQuoteOptions.h"
#include "strategy/test/VirtualServiceTradePersistence.h"
#include "strategy/test/test_environment/FakeStrategyHandle.h"
#include "strategy/test/test_environment/IStrategyResponder.h"
#include "strategy/test/ExpirationDeliveryOperation.h"
#include "strategy/test/ExpirationOldOptions.h"
#include "strategy/test/ExpirationOptions.h"
#include "strategy/test/ExtraCalculatedInstrumentValuesOptions.h"
#include "strategy/test/IMatchingEngine.h"
#include "strategy/test/InstrumentGroupParametersUpdate.h"
#include "strategy/test/InstrumentTradingInformation.h"
#include "strategy/test/PluginEvent.h"
#include "strategy/test/PublicTrade.h"
#include "strategy/test/QuoteTableUpdate.h"
#include "strategy/test/UserPreferences.h"
#include "strategy/test/VirtualOrderEntryClient.h"
#include "strategy/test/ValidationContext.h"
#include "strategy/test/VirtualLimitEngine.h"
#include "strategy/test/VirtualLimitRuleStream.h"
#include "strategy/test/VirtualServiceDirectedQuoteRequest.h"
#include "strategy/test/ExPitOptions.h"
#include "strategy/test/Quote.h"
#include "strategy/test/QuoteData.h"
#include "strategy/test/QuoteSetOptions.h"
#include "strategy/test/RequestForQuoteOptions.h"
#include "strategy/test/VirtualCalculationEngine.h"
#include "strategy/test/VirtualDistributionEngine.h"
#include "strategy/test/VirtualServiceDirectedQuoting.h"
#include "strategy/test/VirtualServiceInstrument.h"
#include "strategy/test/VirtualServiceMarketData.h"
#include "strategy/test/DirectedQuoteResponse.h"
#include "strategy/test/VirtualPluginEngine.h"
#include "strategy/test/EventManager.h"
#include "strategy/trading/Matching.h"
#include "strategy/trading/RequestForQuoteProvider.h"
#include "strategy/trading/Trading.h"
#include "strategy/validation/ValidationContext.h"
#include "strategy/validation/ValidationItem.h"
#include "strategy/validation/ValidityValidationItem.h"
#include "strategy/Node.h"
#include "strategy/TradingBlockCondition.h"
#include "strategy/TradingCalendar.h"
#include "strategy/TradingCapabilities.h"
#include "strategy/TreeNodeParameterDefinition.h"
#include "strategy/TreeNodeParameters.h"
#include "strategy/User.h"
#include "strategy/UserParameterDefinition.h"
#include "strategy/UserParameters.h"
#include "strategy/UserPreferences.h"
#include "strategy/UserStatus.h"
#include "strategy/VWAPPrice.h"
#include "strategy/ValidityTypeSet.h"
#include "strategy/Value.h"
#include "strategy/VenueAndMIC.h"
#include "strategy/VenueInstrumentIdentifierStructure.h"
#include "strategy/VenueManager.h"
#include "strategy/VenueStatus.h"
#include "strategy/XML.h"
#include "strategy/XMLReader.h"
#include "strategy/XMLWriter.h"
#include "strategy/XSLTTransformation.h"
#include "strategy/TradeModifier.h"
#include "strategy/TradeParameterDefinition.h"
#include "strategy/TradeParameters.h"
#include "strategy/TradingBlock.h"

namespace tbricks { namespace test {

class ITestEngine;
class TestEngine;
typedef void (*TestCode)(TestEngine &);

/**
 * TestEngine is a Plugin Engine representation,
 * which can be used for plugin execution.
 */
class STRATEGY_EXPORT TestEngine
{
public:
    enum EngineType
    {
        StrategyEngineType,
        LimitEngineType,
        CalculationEngineType,
        AccessoryEngineType,
        IntegrationEngineType,
        DistributionEngineType,
    };

    /**
     * Enumeration of system setup variations.
     *
     * 1. Trading system has IS, CE, IE, QS, MD, TR, TRD services.
     * 2. MultiTrading system contains IS, SE, TP
     *     and triple set of MD, TR, TRD services.
     * 3. Pricing system: IS, MD, TP services.
     *
     * All of this contains one node and one subsystem.
     * Service names is associated with its type
     *  ("qs" for QS, "md1"  for first MD, etc).
     * For other setup xml file can be used.
     */
    enum SystemType
    {
        TradingSystem,
        MultiTradingSystem,
        PricingSystem
    };

    /**
     * TestEngine constructor, performs initialization.
     * Only one TestEngine per program can be created.
     * TB_APPS and SDK environment variables must be set.
     * Test program can exit with codes:
     *       2  initialization problem
     *       3  exit due operation error
     *       4  critical error at service get
     *       5  test hung and was killed
     *       6  exception on test code execution
     *       7  external sigint was received
     *           (other errors may occurs at unexpected shutdown)
     * Backtrace can be found in logs if test hangs and the process is killed.
     * Config path can be specified with APPS repository root.
     *
     * @param system     Path to the xml file, which describes the system configuration
     *                   ( system, nodes, components, etc )
     *
     * @param engine     Path to the xml file, which describes TestEngine configuration
     *                   ( engine type, log level, etc )
     *
     * @param engine_type   Engine type with default configs.
     *
     * @param system_type   One of predefined system setup.
     */
    TestEngine(const char * system, const char * engine);
    TestEngine(const char * system, EngineType engine_type);
    TestEngine(SystemType system_type, EngineType engine_type);

    /**
     * Execute test scenario, handles exceptions and timeouts
     *
     * Please, use only one scenario per program,
     * because they can affect each other.
     *
     * @param tc         Name of function with test scenario.
     *
     * @param timeout    Test timeout. Program will exit with code 5 if it is reached.
     */
    void RunTest(TestCode tc, const Duration & timeout = Duration());

    //-------------------Plugins operations---------------------------
    /**
     * Load plugin binary and metadata.
     * Plugin should be built before execution or added to dependencies of the test
     * Do not load plugin one more times, it may cause undefined behavior
     *
     * @param path       Path to the plugin directory, which contains manifest file.
     *                   Path can be absolute or relative based on root of apps repository.
     *
     * @code
     * te.LoadPlugin( "production/strategy/order" );
     * @endcode
     */
    void LoadPlugin(const char * path);

    /**
     * Load metadata. Can load plugin or shared metadata.
     * shared metadata is loaded by default.
     *
     * @param path       Path to metadata file or to the directory,
     *                   which contains *metadata.xml file.
     *                   Path can be absolute or relative based on root of apps repository.
     */
    void LoadMetadata(const char * path);

    /**
     * Load resource. Can be used to defines custom venues, etc.
     *
     * @param path       Path to resource file.
     *                   Path can be absolute or relative based on root of apps repository.
     */
    void LoadResource(const char * path);

    /**
     * Creating FIX sessions. Can be used to create FIX session in Integration engine
     *
     */
    void CreateFixSessions();

    /**
     * Assign EventManager for plugin.
     * EventManager will be used for plugins that will be created in future.
     *
     * @param definition_id  Plugin definition identifier.
     *
     * @param manager        EventManager with defined event sequence.
     */
    void AssignEventManager(const StrategyIdentifier & definition_id, const tbricks::test::EventManager & manager);

    /**
     * Create plugin instance.
     *
     * @param options    Plugin options, provides plugin
     *                   creation flags and attributes.
     * @param parameters Plugin parameters.
     *
     * @param wait       Wait for operation complete.
     *
     * @return           Identifier of the created plugin instance.
     */
    StrategyIdentifier CreatePlugin(const StrategyOptions & options, const StrategyParameters & parameters = StrategyParameters(), bool wait = false);

    /**
     * Create plugin instance.
     *
     * @param id         Strategy identifier of the created instance.
     *                   Should be used for further operations.
     *
     * @param definition_id  Plugin definition identifier.
     *                       Should be taken from tbricks_definitions.h
     *
     * @param parameters Plugin parameters at creation.
     *
     * @param state      Target app state.
     *
     * @param wait       Wait for operation complete.
     */
    void CreatePlugin(StrategyIdentifier & id,
                      const StrategyIdentifier & definition_id,
                      const StrategyParameters & parameters = StrategyParameters(),
                      const StrategyState::StateValue & state = StrategyState::PAUSED,
                      const Boolean & wait = false);

    /**
     * Run plugin.
     *
     * @param id         Plugin instance identifier.
     *
     * @param wait       Wait for operation complete.
     */
    void RunPlugin(const StrategyIdentifier & id, const Boolean & wait = false);

    /**
     * Pause plugin.
     *
     * @param id         Plugin instance identifier.
     *
     * @param wait       Wait for operation complete.
     */
    void PausePlugin(const StrategyIdentifier & id, const Boolean & wait = false);

    /**
     * Delete plugin.
     *
     * @param id         Plugin instance identifier.
     *
     * @param wait       Wait for operation complete.
     *
     * @param force      Force delete if true.
     */
    void DeletePlugin(const StrategyIdentifier & id, const Boolean & force = false, const Boolean & wait = false);

    /**
     * Modify plugin.
     *
     * @param id         Plugin instance identifier.
     *
     * @param modifier   Modification options.
     *
     * @param wait       Wait for operation complete.
     */
    void ModifyPlugin(const StrategyIdentifier & id, const StrategyModifier & modifier, const Boolean & wait = false);

    /**
     * Wait until the plugin match the filter.
     * Any condition comes completed at app deletion.
     *
     * @param id         Plugin instance identifier.
     *
     * @param filter     Plugin filter.
     */
    void WaitPluginCondition(const StrategyIdentifier & id, const StrategyFilter & filter);

    /**
     * Wait until any of plugins match the filter.
     * Any condition comes completed at app deletion.
     *
     * @param filter     Plugin filter.
     *
     * @return           StrategyIdentifier of first plugin that matches the filter
     */
    StrategyIdentifier WaitPluginCondition(const StrategyFilter & filter);

    /**
     * Get StrategyData for plugin analyse.
     *
     * @param id         Plugin instance identifier.
     *
     * @return           StrategyData object
     */
    StrategyData GetPlugin(const StrategyIdentifier & id);

    /**
     * Get plugin history for plugin analyse.
     *
     * @param id         Plugin instance identifier.
     *
     * @return           List for filling plugin events.
     */
    std::vector<test::PluginEvent> GetPluginHistory(const StrategyIdentifier & id);

    /**
     * Get a list of alive plugins with definition identifier.
     *
     * @param id             Plugin definition identifier.
     *
     * @return               Vector of plugin identifiers.
     */
    std::vector<StrategyIdentifier> GetPluginInstanceIdentifiers(const StrategyIdentifier & id);

    /**
     * Get a list of plugins which was initiated by stream (Calculation or MDP).
     *
     * @param id             Stream identifier.
     *
     * @return               Vector of plugin identifiers.
     */
    std::vector<StrategyIdentifier> GetPluginInstanceIdentifiers(const StreamIdentifier & id);

    /**
     * Wait until all plugin events are completed.
     *
     * @param id         Plugin instance identifier.
     */
    void FlushPluginQueue(const StrategyIdentifier & id);

    /**
     * Simulate plugin recovery. Plugin will be destroyed
     * and then recovered from current state.
     *
     * @param id         Plugin instance identifier.
     */
    void RecoverPlugin(const StrategyIdentifier & id);

    /**
     * Trigger HandleValidateRequest callback at app side.
     *
     * @param id         Plugin instance identifier.
     *
     * @param context    Plugin validation context input.
     *
     * @return           Plugin validation context after validation.
     */
    test::ValidationContext ValidatePlugin(const StrategyIdentifier & id, const test::ValidationContext & context);

    //--------------------Services operations----------------------------------
    /**
     * Get system virtual service by VenueIdentifier.
     * The first service will be taken if there are several.
     *
     * @param vid        Service venue identifier.
     *
     * @return           Virtual service object
     */
    VirtualServiceMarketData & GetMD(const VenueIdentifier & vid);
    VirtualServiceTradingReferenceData & GetTRD(const VenueIdentifier & vid);
    VirtualServiceTrading & GetTR(const VenueIdentifier & vid);
    VirtualServiceExpitTrading & GetET(const VenueIdentifier & vid);
    VirtualServiceQuoting & GetQS(const VenueIdentifier & vid);
    VirtualServiceMatchingEngine & GetME(const VenueIdentifier & vid);
    VirtualServiceDirectedQuoteRequest & GetDQR(const VenueIdentifier & vid);
    VirtualServiceDirectedQuoting & GetDQ(const VenueIdentifier & vid);
    VirtualServiceRequestForQuote & GetRFQ(const VenueIdentifier & vid);
    /**
     * Get system virtual service by name.
     * The first service will be taken if there are several.
     *
     * @param name       Service name.
     *
     * @return           Virtual service object
     */
    VirtualServiceMarketData & GetMD(const char * name);
    VirtualServiceTradingReferenceData & GetTRD(const char * name);
    VirtualServiceTrading & GetTR(const char * name);
    VirtualServiceExpitTrading & GetET(const char * name);
    VirtualServiceQuoting & GetQS(const char * name);
    VirtualServiceMatchingEngine & GetME(const char * name);
    VirtualServiceDirectedQuoteRequest & GetDQR(const char * name);
    VirtualServiceDirectedQuoting & GetDQ(const char * name);
    VirtualServiceRequestForQuote & GetRFQ(const char * name);

    /**
     * Get system virtual service by identifier.
     *
     * @param id         Service identifier.
     *
     * @return           Virtual service object
     */
    VirtualServiceMarketData & GetMD(const Uuid & id);
    VirtualServiceTradingReferenceData & GetTRD(const Uuid & id);
    VirtualServiceTrading & GetTR(const Uuid & id);
    VirtualServiceExpitTrading & GetET(const Uuid & id);
    VirtualServiceQuoting & GetQS(const Uuid & id);
    VirtualPluginEngine & GetPE(const Uuid & id);
    VirtualServiceMatchingEngine & GetME(const Uuid & id);
    VirtualServiceDirectedQuoteRequest & GetDQR(const Uuid & id);
    VirtualServiceDirectedQuoting & GetDQ(const Uuid & id);
    VirtualServiceRequestForQuote & GetRFQ(const Uuid & id);

    /**
     * Get unique system service.
     *
     * @return           Virtual service object
     */
    VirtualServiceInstrument & GetIS();
    VirtualServiceTradePersistence & GetTP();
    VirtualServiceOrderPersistence & GetOP();
    VirtualCalculationEngine & GetCE();
    VirtualDistributionEngine & GetDE();
    VirtualXRayEngine & GetXE();

    VirtualLimitEngine & GetLE();

    /**
     * Get system virtual plugin engine by type.
     * The first service will be taken if there are several.
     *
     * @param type       Engine type.
     *
     * @return           Virtual service object
     */
    /// @deprecated Deprecated in 2.14.3 use tbricks::ServiceType
    [[deprecated(DEPRECATE_LINK)]] VirtualPluginEngine & GetPE(Service::Type type) { return GetPE(static_cast<ServiceType>(type)); }

    VirtualPluginEngine & GetPE(ServiceType type);

    /**
     * Control of service connection.
     * Disconnect will cause all streams opened to this service to become stale.
     * Opening a new streams will fail.
     *
     * @param service    Service representation object.
     */
    void Disconnect(const IVirtualService & service);
    void Reconnect(const IVirtualService & service);

    /**
     * Wait until all plugin events are completed and
     * all messages are received by virtual services.
     */
    void FlushAllQueues();

    /**
     * Execute all API pending events for main thread.
     *
     * @return          Count executed events.
     */
    size_t ExecutePendingApiEvents();

    //------------------Execution operations------------------------------
    /**
     * Register User in system. User will be created on first registration.
     * Registered user will be used as operator
     * for TestEngine operations (like RunPlugin).
     *
     * @param id         User identifier. Used to identify the user.
     *
     * @param name       User name. Used on creation.
     *
     * @param roles      User roles. Used on creation.
     *
     * @return           User object.
     */
    User
    RegisterUser(const UserIdentifier & id, const char * name = "user", const std::vector<RoleIdentifier> & roles = std::vector<RoleIdentifier>());

    /**
     * Enable manual timer control.
     * All plugin timers will work via TimerController object after it is called.
     * This method should be called before any plugin creation.
     * Otherwise behavior undefined.
     */
    void EnableTimerControl();

    /**
     * Get TimerController object, used for timers control.
     */
    TimerController & GetTimerController();

    /**
     * Get MatchingEngine interface for testing of matching apps.
     * Available only with matching engine type.
     */
    IMatchingEngine GetIME();

    /**
     * Immediately stop the test.
     * Should be called on wrong asserts.
     */
    void Stop(const int rc, const char * status_text);

    /**
     * Get instance of TestEngine.
     * TestEngine should be initialized before.
     * Otherwise test will fail.
     */
    static TestEngine & Get();

    /**
     * TestEngine destructor.
     */
    ~TestEngine();

private:
    TestEngine() = delete;
    TestEngine(const TestEngine &) = delete;
    TestEngine & operator=(const TestEngine &) = delete;

    friend class ITestEngine;

    ITestEngine * m_impl;
    TimerController * m_tc;
    SparseHash<Uuid, IVirtualService *> m_services;
};

} // \namespace test

} // \namespace tbricks
