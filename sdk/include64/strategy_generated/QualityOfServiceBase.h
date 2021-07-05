#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// QualityOfServiceBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class DateTime;
class Double;
class Integer;
class ServiceIdentifier;
class String;
enum class LogEntryLevel;
enum class ServiceSelfTestStatus;


namespace protocol { class QualityOfService; }

class STRATEGY_EXPORT QualityOfServiceBase : public Printable
{
protected:
    QualityOfServiceBase();
    QualityOfServiceBase(const QualityOfServiceBase & value);
    QualityOfServiceBase(QualityOfServiceBase && value) noexcept;
    QualityOfServiceBase & operator=(const QualityOfServiceBase & value);
    QualityOfServiceBase & operator=(QualityOfServiceBase && value) noexcept;
    virtual ~QualityOfServiceBase();

public:
    /**
     * Check if field is set.
     *
     * The service instance identifier is used to uniquely identify a
     * service instance.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasServiceIdentifier() const;

    /**
     * Get service instance identifier.
     *
     * The service instance identifier is used to uniquely identify a
     * service instance.
     *
     *
     * @return                          service instance identifier
     */
    ServiceIdentifier GetServiceIdentifier() const;

    /**
     * Check if field is set.
     *
     * The current number of connected client sessions, regardless of type.
     * This includes all             internal behind-the-scenes
     * connections as well (any session connections to AA, tblog, QoS,
     * ...).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasConnectedUsersNumber() const;

    /**
     * Get qos connected sessions.
     *
     * The current number of connected client sessions, regardless of type.
     * This includes all             internal behind-the-scenes
     * connections as well (any session connections to AA, tblog, QoS,
     * ...).
     *
     *
     * @return                          qos connected sessions
     */
    Integer GetConnectedUsersNumber() const;

    /**
     * Check if field is set.
     *
     * The amount of user CPU consumed by the process in milliseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcessorTimeUsage() const;

    /**
     * Get qos cpu time used.
     *
     * The amount of user CPU consumed by the process in milliseconds.
     *
     *
     * @return                          qos cpu time used
     */
    Double GetProcessorTimeUsage() const;

    /**
     * Check if field is set.
     *
     * The ratio of CPU time used  recently  to CPU  time  available in
     * the same period, expressed as a percentage.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcessorUsage() const;

    /**
     * Get qos pcpu used.
     *
     * The ratio of CPU time used  recently  to CPU  time  available in
     * the same period, expressed as a percentage.
     *
     *
     * @return                          qos pcpu used
     */
    Double GetProcessorUsage() const;

    /**
     * Check if field is set.
     *
     * The number of error log messages output by the service for the last
     * minute.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasErrorMessageCountOneMinute() const;

    /**
     * Get qos error message count one minute.
     *
     * The number of error log messages output by the service for the last
     * minute.
     *
     *
     * @return                          qos error message count one minute
     */
    Integer GetErrorMessageCountOneMinute() const;

    /**
     * Check if field is set.
     *
     * The number of error log messages output by the service for the last
     * five minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasErrorMessageCountFiveMinute() const;

    /**
     * Get qos error message count five minutes.
     *
     * The number of error log messages output by the service for the last
     * five minutes.
     *
     *
     * @return                          qos error message count five minutes
     */
    Integer GetErrorMessageCountFiveMinute() const;

    /**
     * Check if field is set.
     *
     * The number of error log messages output by the service for the last
     * fifteen minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasErrorMessageCountFifteenMinute() const;

    /**
     * Get qos error message count fifteen minutes.
     *
     * The number of error log messages output by the service for the last
     * fifteen minutes.
     *
     *
     * @return                          qos error message count fifteen minutes
     */
    Integer GetErrorMessageCountFifteenMinute() const;

    /**
     * Check if field is set.
     *
     * Is true if all the external connections used by the service have
     * been successfully established.             This means
     * connections to external services, such as exchanges or brokers.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExternalConnectionsEstablished() const;

    /**
     * Get qos external connections established.
     *
     * Is true if all the external connections used by the service have
     * been successfully established.             This means
     * connections to external services, such as exchanges or brokers.
     *
     *
     * @return                          qos external connections established
     */
    Boolean GetExternalConnectionsEstablished() const;

    /**
     * Check if field is set.
     *
     * The min latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundLatencyMin() const;

    /**
     * Get qos inbound latency min.
     *
     * The min latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos inbound latency min
     */
    Integer GetInboundLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundLatencyAvg() const;

    /**
     * Get qos inbound latency avg.
     *
     * The average latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos inbound latency avg
     */
    Integer GetInboundLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundLatencyMax() const;

    /**
     * Get qos inbound latency max.
     *
     * The max latency of processing inbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos inbound latency max
     */
    Integer GetInboundLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The minimum externally detected latency measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExternalInboundLatencyMin() const;

    /**
     * Get qos external inbound latency min.
     *
     * The minimum externally detected latency measured in microseconds.
     *
     *
     * @return                          qos external inbound latency min
     */
    Integer GetExternalInboundLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average externally detected latency measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExternalInboundLatencyAvg() const;

    /**
     * Get qos external inbound latency avg.
     *
     * The average externally detected latency measured in microseconds.
     *
     *
     * @return                          qos external inbound latency avg
     */
    Integer GetExternalInboundLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The maximum externally detected latency measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasExternalInboundLatencyMax() const;

    /**
     * Get qos external inbound latency max.
     *
     * The maximum externally detected latency measured in microseconds.
     *
     *
     * @return                          qos external inbound latency max
     */
    Integer GetExternalInboundLatencyMax() const;

    /**
     * Check if field is set.
     *
     * Is true if all the internal connections used by the service have
     * been successfully established.             This means
     * connections to Tbricks services.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInternalConnectionsEstablished() const;

    /**
     * Get qos internal connections established.
     *
     * Is true if all the internal connections used by the service have
     * been successfully established.             This means
     * connections to Tbricks services.
     *
     *
     * @return                          qos internal connections established
     */
    Boolean GetInternalConnectionsEstablished() const;

    /**
     * Check if field is set.
     *
     * The load on the system for the last minute.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcessorQueueLengthOneMinute() const;

    /**
     * Get qos load one minute.
     *
     * The load on the system for the last minute.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          qos load one minute
     */
    Double GetProcessorQueueLengthOneMinute() const;

    /**
     * Check if field is set.
     *
     * The load on the system for the last five minutes.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcessorQueueLengthFiveMinute() const;

    /**
     * Get qos load five minutes.
     *
     * The load on the system for the last five minutes.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          qos load five minutes
     */
    Double GetProcessorQueueLengthFiveMinute() const;

    /**
     * Check if field is set.
     *
     * The load on the system for the last fifteen minutes.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProcessorQueueLengthFifteenMinute() const;

    /**
     * Get qos load fifteen minutes.
     *
     * The load on the system for the last fifteen minutes.
     * http://en.wikipedia.org/wiki/Load_(computing)
     *
     *
     * @return                          qos load fifteen minutes
     */
    Double GetProcessorQueueLengthFifteenMinute() const;

    /**
     * Check if field is set.
     *
     * The size of the order throttle queue within the TR service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrderQueueSize() const;

    /**
     * Get qos order queue size.
     *
     * The size of the order throttle queue within the TR service.
     *
     *
     * @return                          qos order queue size
     */
    Integer GetOrderQueueSize() const;

    /**
     * Check if field is set.
     *
     * The number of non-deleted orders active in the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrdersNumber() const;

    /**
     * Get qos active orders.
     *
     * The number of non-deleted orders active in the service.
     *
     *
     * @return                          qos active orders
     */
    Integer GetOrdersNumber() const;

    /**
     * Check if field is set.
     *
     * Number of new orders sent to a market
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrdersCreated() const;

    /**
     * Get qos orders created.
     *
     * Number of new orders sent to a market
     *
     *
     * @return                          qos orders created
     */
    Integer GetOrdersCreated() const;

    /**
     * Check if field is set.
     *
     * Number of order modifications sent to a market for existing orders
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOrdersModified() const;

    /**
     * Get qos orders modified.
     *
     * Number of order modifications sent to a market for existing orders
     *
     *
     * @return                          qos orders modified
     */
    Integer GetOrdersModified() const;

    /**
     * Check if field is set.
     *
     * Number of received trades done at a market
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradesDone() const;

    /**
     * Get qos trades done.
     *
     * Number of received trades done at a market
     *
     *
     * @return                          qos trades done
     */
    Integer GetTradesDone() const;

    /**
     * Check if field is set.
     *
     * The min latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundLatencyMin() const;

    /**
     * Get qos outbound latency min.
     *
     * The min latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos outbound latency min
     */
    Integer GetOutboundLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundLatencyAvg() const;

    /**
     * Get qos outbound latency avg.
     *
     * The average latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos outbound latency avg
     */
    Integer GetOutboundLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundLatencyMax() const;

    /**
     * Get qos outbound latency max.
     *
     * The max latency of processing outbound messages measured in
     * microseconds.
     *
     *
     * @return                          qos outbound latency max
     */
    Integer GetOutboundLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The current amount of memory in use exclusively by the process,
     * which is not backed by a file in bytes (calculated as RSS -
     * SHR).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasResidentMemorySize() const;

    /**
     * Get qos real memory used.
     *
     * The current amount of memory in use exclusively by the process,
     * which is not backed by a file in bytes (calculated as RSS -
     * SHR).
     *
     *
     * @return                          qos real memory used
     */
    Integer GetResidentMemorySize() const;

    /**
     * Check if field is set.
     *
     * The size of the process virtual memory address space in bytes
     * (SIZE).
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVirtualMemorySize() const;

    /**
     * Get qos virtual memory used.
     *
     * The size of the process virtual memory address space in bytes
     * (SIZE).
     *
     *
     * @return                          qos virtual memory used
     */
    Integer GetVirtualMemorySize() const;

    /**
     * Check if field is set.
     *
     * The number of non-deleted strategies active in the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategiesNumber() const;

    /**
     * Get qos strategies.
     *
     * The number of non-deleted strategies active in the service.
     *
     *
     * @return                          qos strategies
     */
    Integer GetStrategiesNumber() const;

    /**
     * Check if field is set.
     *
     * The size of the callbacks queue for strategies.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyCallbackQueueSize() const;

    /**
     * Get qos strategy callbacks queue size.
     *
     * The size of the callbacks queue for strategies.
     *
     *
     * @return                          qos strategy callbacks queue size
     */
    Integer GetStrategyCallbackQueueSize() const;

    /**
     * Check if field is set.
     *
     * The size of the operations queue for strategies.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyOperationsQueueSize() const;

    /**
     * Get qos strategy operations queue size.
     *
     * The size of the operations queue for strategies.
     *
     *
     * @return                          qos strategy operations queue size
     */
    Integer GetStrategyOperationsQueueSize() const;

    /**
     * Check if field is set.
     *
     * The size of the validations queue for strategies.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasStrategyValidationsQueueSize() const;

    /**
     * Get qos strategy validations queue size.
     *
     * The size of the validations queue for strategies.
     *
     *
     * @return                          qos strategy validations queue size
     */
    Integer GetStrategyValidationsQueueSize() const;

    /**
     * Check if field is set.
     *
     * The number of warning log messages output by the service for the
     * last minute.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWarningMessageCountOneMinute() const;

    /**
     * Get qos warning message count one minute.
     *
     * The number of warning log messages output by the service for the
     * last minute.
     *
     *
     * @return                          qos warning message count one minute
     */
    Integer GetWarningMessageCountOneMinute() const;

    /**
     * Check if field is set.
     *
     * The number of warning log messages output by the service for the
     * last five minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWarningMessageCountFiveMinute() const;

    /**
     * Get qos warning message count five minutes.
     *
     * The number of warning log messages output by the service for the
     * last five minutes.
     *
     *
     * @return                          qos warning message count five minutes
     */
    Integer GetWarningMessageCountFiveMinute() const;

    /**
     * Check if field is set.
     *
     * The number of warning log messages output by the service for the
     * last fifteen minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasWarningMessageCountFifteenMinute() const;

    /**
     * Get qos warning message count fifteen minutes.
     *
     * The number of warning log messages output by the service for the
     * last fifteen minutes.
     *
     *
     * @return                          qos warning message count fifteen minutes
     */
    Integer GetWarningMessageCountFifteenMinute() const;

    /**
     * Check if field is set.
     *
     * The number of log messages output by the service for the last
     * minute.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLogMessageCountOneMinute() const;

    /**
     * Get qos log message count one minute.
     *
     * The number of log messages output by the service for the last
     * minute.
     *
     *
     * @return                          qos log message count one minute
     */
    Integer GetLogMessageCountOneMinute() const;

    /**
     * Check if field is set.
     *
     * The number of log messages output by the service for the last five
     * minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLogMessageCountFiveMinute() const;

    /**
     * Get qos log message count five minutes.
     *
     * The number of log messages output by the service for the last five
     * minutes.
     *
     *
     * @return                          qos log message count five minutes
     */
    Integer GetLogMessageCountFiveMinute() const;

    /**
     * Check if field is set.
     *
     * The number of log messages output by the service for the last
     * fifteen minutes.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLogMessageCountFifteenMinute() const;

    /**
     * Get qos log message count fifteen minutes.
     *
     * The number of log messages output by the service for the last
     * fifteen minutes.
     *
     *
     * @return                          qos log message count fifteen minutes
     */
    Integer GetLogMessageCountFifteenMinute() const;

    /**
     * Check if field is set.
     *
     * The time the previous self-test was run.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSelfTestDateTime() const;

    /**
     * Get qos self test datetime.
     *
     * The time the previous self-test was run.
     *
     *
     * @return                          qos self test datetime
     */
    DateTime GetSelfTestDateTime() const;

    /**
     * Check if field is set.
     *
     * The status of the previous/current self-test of the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSelfTestStatus() const;

    /**
     * Get qos self test status.
     *
     * The status of the previous/current self-test of the service.
     *
     *
     * @return                          qos self test status
     */
    std::optional<ServiceSelfTestStatus> GetSelfTestStatus() const;

    /**
     * Check if field is set.
     *
     * The number of non-deleted active quotes in the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasQuotesCount() const;

    /**
     * Get qos quotes.
     *
     * The number of non-deleted active quotes in the service.
     *
     *
     * @return                          qos quotes
     */
    Integer GetQuotesCount() const;

    /**
     * Check if field is set.
     *
     * The current max log severity that is persisted.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasLogLevelPersisted() const;

    /**
     * Get qos log severity persisted.
     *
     * The current max log severity that is persisted.
     *
     *
     * @return                          qos log severity persisted
     */
    std::optional<LogEntryLevel> GetLogLevelPersisted() const;

    /**
     * Check if field is set.
     *
     * The current max log severity that is being provided by the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasActiveLogLevel() const;

    /**
     * Get qos log severity.
     *
     * The current max log severity that is being provided by the service.
     *
     *
     * @return                          qos log severity
     */
    std::optional<LogEntryLevel> GetActiveLogLevel() const;

    /**
     * Check if field is set.
     *
     * True if the service currently is in panic stop mode.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPanicStopMode() const;

    /**
     * Get qos strategy engine in panic stop mode.
     *
     * True if the service currently is in panic stop mode.
     *
     *
     * @return                          qos strategy engine in panic stop mode
     */
    Boolean GetPanicStopMode() const;

    /**
     * Check if field is set.
     *
     * The venue status for the service, true if the venue status is 'ok',
     * otherwise it is 'fail'.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenueStatus() const;

    /**
     * Get qos venue status.
     *
     * The venue status for the service, true if the venue status is 'ok',
     * otherwise it is 'fail'.
     *
     *
     * @return                          qos venue status
     */
    Boolean GetVenueStatus() const;

    /**
     * Check if field is set.
     *
     * A textual description of the venue status for the service.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasVenueStatusDescription() const;

    /**
     * Get qos venue status description.
     *
     * A textual description of the venue status for the service.
     *
     *
     * @return                          qos venue status description
     */
    String GetVenueStatusDescription() const;

    /**
     * Check if field is set.
     *
     * The min latency for an outgoing order add, measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderAddLatencyMin() const;

    /**
     * Get qos outbound order add latency min.
     *
     * The min latency for an outgoing order add, measured in microseconds.
     *
     *
     * @return                          qos outbound order add latency min
     */
    Integer GetOutboundOrderAddLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency for an outgoing order add, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderAddLatencyAvg() const;

    /**
     * Get qos outbound order add latency avg.
     *
     * The average latency for an outgoing order add, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order add latency avg
     */
    Integer GetOutboundOrderAddLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency for an outgoing order add, measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderAddLatencyMax() const;

    /**
     * Get qos outbound order add latency max.
     *
     * The max latency for an outgoing order add, measured in microseconds.
     *
     *
     * @return                          qos outbound order add latency max
     */
    Integer GetOutboundOrderAddLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The min latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderModifyLatencyMin() const;

    /**
     * Get qos outbound order modify latency min.
     *
     * The min latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order modify latency min
     */
    Integer GetOutboundOrderModifyLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderModifyLatencyAvg() const;

    /**
     * Get qos outbound order modify latency avg.
     *
     * The average latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order modify latency avg
     */
    Integer GetOutboundOrderModifyLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderModifyLatencyMax() const;

    /**
     * Get qos outbound order modify latency max.
     *
     * The max latency for an outgoing order modify, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order modify latency max
     */
    Integer GetOutboundOrderModifyLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The min latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderDeleteLatencyMin() const;

    /**
     * Get qos outbound order delete latency min.
     *
     * The min latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order delete latency min
     */
    Integer GetOutboundOrderDeleteLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderDeleteLatencyAvg() const;

    /**
     * Get qos outbound order delete latency avg.
     *
     * The average latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order delete latency avg
     */
    Integer GetOutboundOrderDeleteLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasOutboundOrderDeleteLatencyMax() const;

    /**
     * Get qos outbound order delete latency max.
     *
     * The max latency for an outgoing order delete, measured in
     * microseconds.
     *
     *
     * @return                          qos outbound order delete latency max
     */
    Integer GetOutboundOrderDeleteLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The min latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundOrderUpdateLatencyMin() const;

    /**
     * Get qos inbound order update latency min.
     *
     * The min latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          qos inbound order update latency min
     */
    Integer GetInboundOrderUpdateLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundOrderUpdateLatencyAvg() const;

    /**
     * Get qos inbound order update latency avg.
     *
     * The average latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          qos inbound order update latency avg
     */
    Integer GetInboundOrderUpdateLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundOrderUpdateLatencyMax() const;

    /**
     * Get qos inbound order update latency max.
     *
     * The max latency for an incoming order update, measured in
     * microseconds.
     *
     *
     * @return                          qos inbound order update latency max
     */
    Integer GetInboundOrderUpdateLatencyMax() const;

    /**
     * Check if field is set.
     *
     * The min latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundTradeLatencyMin() const;

    /**
     * Get qos inbound trade latency min.
     *
     * The min latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          qos inbound trade latency min
     */
    Integer GetInboundTradeLatencyMin() const;

    /**
     * Check if field is set.
     *
     * The average latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundTradeLatencyAvg() const;

    /**
     * Get qos inbound trade latency avg.
     *
     * The average latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          qos inbound trade latency avg
     */
    Integer GetInboundTradeLatencyAvg() const;

    /**
     * Check if field is set.
     *
     * The max latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasInboundTradeLatencyMax() const;

    /**
     * Get qos inbound trade latency max.
     *
     * The max latency for an incoming trade, measured in microseconds.
     *
     *
     * @return                          qos inbound trade latency max
     */
    Integer GetInboundTradeLatencyMax() const;

    /**
     * Check if field is set.
     *
     * Bytes sent.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBytesSent() const;

    /**
     * Get qos bytes sent.
     *
     * Bytes sent.
     *
     *
     * @return                          qos bytes sent
     */
    Integer GetBytesSent() const;

    /**
     * Check if field is set.
     *
     * Bytes received.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasBytesReceived() const;

    /**
     * Get qos bytes received.
     *
     * Bytes received.
     *
     *
     * @return                          qos bytes received
     */
    Integer GetBytesReceived() const;

    /**
     * Check if field is set.
     *
     * Messages sent.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMessagesSent() const;

    /**
     * Get qos messages sent.
     *
     * Messages sent.
     *
     *
     * @return                          qos messages sent
     */
    Integer GetMessagesSent() const;

    /**
     * Check if field is set.
     *
     * Messages received.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMessagesReceived() const;

    /**
     * Get qos messages received.
     *
     * Messages received.
     *
     *
     * @return                          qos messages received
     */
    Integer GetMessagesReceived() const;

    /**
     * Check if field is set.
     *
     * True if the service is running using a debug binary, false if
     * running a proper optimized binary.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDebugMode() const;

    /**
     * Get qos debug mode.
     *
     * True if the service is running using a debug binary, false if
     * running a proper optimized binary.
     *
     *
     * @return                          qos debug mode
     */
    Boolean GetDebugMode() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

protected:
    void Merge(const QualityOfServiceBase & update);

/** @cond PRIVATE */
public:
    QualityOfServiceBase(const protocol::QualityOfService & value);
    QualityOfServiceBase(std::shared_ptr<protocol::QualityOfService> && value);

    std::shared_ptr<protocol::QualityOfService> & get_impl_wr() const;
    const std::shared_ptr<protocol::QualityOfService> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::QualityOfService> m_impl;
};

}
