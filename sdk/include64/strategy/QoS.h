#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Quality of service updates, provides useful runtime information about
// service state and healthiness.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Logger.h"

namespace tbricks {

namespace protocol {
class QualityOfService;
}

/**
 * QoS object informs about runtime state of a service, including information
 * about CPU usage, order processing latency, service healthiness and more.
 *
 * Only identifier field is guaranteed to always be present in the message.
 * Set of fields provided in the message are service specific (for instance,
 * all order related fields will only be defined by those services that work
 * with orders directly, for all other services the fields will not be filled
 * in).
 */
/// @deprecated Deprecated in 2.14.5 use QualityOfService
class STRATEGY_EXPORT[[deprecated(DEPRECATE_LINK)]] QoS : public Printable
{
public:
    enum SelfTestStatus
    {
        NotRun = 1,
        Ok = 2,
        Failed = 3,
        InProgress = 4,
        Unknown = 5
    };

public:
    /**
     * Default constructor.
     *
     * Initializes object to default value -- no fields present, all returned
     * values are empty.
     *
     * This is mostly for use in STL containers.
     */
    QoS();

    /**
     * Copy constructor.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param src                       Object to copy from
     */
    QoS(const QoS & src);

    /**
     * Assignment operator.
     *
     * Performs full copy, destination object does not depend on the
     * source one after operation is over.
     *
     * @param src                       Object to copy from
     * @return                          Updated object
     */
    QoS & operator=(const QoS & src);
    ~QoS();

    /**
     * Merge data from extern source.
     *
     * Object fields are updated from the argument, old values (if any) are
     * replaced.
     *
     * Method only fails when both source and target objects have service
     * identifier set, and identifiers are not equal. If this is the case,
     * the method throws an exception.
     *
     * @param src                      Data source
     * @return                         "true" if merge succeeded, "false"
     *                                 otherwise
     */
    void Merge(const QoS & src);

    /**
     * Get service identifier.
     *
     * Returns service identifier of a service a message was sent
     * from.
     *
     * @return                          Service identifier
     */
    ServiceIdentifier GetServiceIdentifier() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasConnectedUsersNumber() const;

    /**
     * Get number of connected users.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetConnectedUsersNumber() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasProcessorUsage() const;

    /**
     * Get amount of user CPU consumed by the process in milliseconds
     * and in percents.
     *
     * If field is not available, parameter values are cleared.
     *
     * @param msecs                     CPU time, in milliseconds, consumed by
     *                                  the service
     * @param percent                   Current CPU utilization, in percent
     */
    void GetProcessorUsage(double & msecs, double & percent) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasErrorMessageCount() const;

    /**
     * Get number of error log messages output by the service for the last one,
     * five and fifteen minutes.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param one                       Number of messages for the last one
     *                                  minute
     * @param five                      Number of messages for the last five
     *                                  minutes
     * @param fifteen                   Number of messages for the last fifteen
     *                                  minutes
     */
    void GetErrorMessageCount(uint64_t & one, uint64_t & five, uint64_t & fifteen) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasExternalConnectionsEstablished() const;

    /**
     * Get "external connections established" flag.
     *
     * Flag value is true if all the external connections used by the service
     * have been successfully established -- this means connections to external
     * services, such as exchanges or brokers.
     *
     * For services that have no external connections, this flag is never set.
     *
     * @return                          Field value, or an empty object if
     *                                  the field is not set
     */
    Boolean GetExternalConnectionsEstablished() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasInboundLatency() const;

    /**
     * Get inbound latency.
     *
     * Method returns minimal, maximal and average latency of processing
     * inbound messages measured in microseconds.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param min                       Minimal latency value
     * @param max                       Maximal latency value
     * @param avg                       Average latency value
     */
    void GetInboundLatency(uint64_t & min, uint64_t & max, uint64_t & avg) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasExternalInboundLatency() const;

    /**
     * Get external inbound latency.
     *
     * Method returns minimal, maximal and average externally detected
     * latencies of inbound messages processing measured in microseconds.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param min                       Minimal latency value
     * @param max                       Maximal latency value
     * @param avg                       Average latency value
     */
    void GetExternalInboundLatency(uint64_t & min, uint64_t & max, uint64_t & avg) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasInternalConnectionsEstablished() const;

    /**
     * Get "internal connections established" flag.
     *
     * Flag value is true if all the internal connections used by the service
     * have been successfully established.  This means connections to Tbricks
     * services.
     *
     * @return                          Field value, or an empty object if
     *                                  the field is not set
     */
    Boolean GetInternalConnectionsEstablished() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasProcessorQueueLength() const;

    /**
     * Get system load.
     *
     * Returns average number of jobs in the processor's run queue for the last
     * one, five and fifteen minutes. On many systems, this value is used to
     * indicate overall system load.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param one                       System load for the last one minute
     * @param five                      System load for the last five minutes
     * @param fifteen                   System load for the last fifteen minutes
     */
    void GetProcessorQueueLength(double & one, double & five, double & fifteen) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasOrderQueueSize() const;

    /**
     * Get size of the order throttle queue within the TR service.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetOrderQueueSize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasOrdersNumber() const;

    /**
     * Get number of non-deleted orders active in the service.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */

    uint32_t GetOrdersNumber() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasOrdersCreated() const;

    /**
     * Number of new orders sent to a market
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */

    uint32_t GetOrdersCreated() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasOrdersModified() const;

    /**
     * Number of order modifications sent to a market for existing orders
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */

    uint32_t GetOrdersModified() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasTradesDone() const;

    /**
     * Number of received trades done at a market
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */

    uint32_t GetTradesDone() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasOutboundLatency() const;

    /**
     * Get outbound latency.
     *
     * Method returns minimal, maximal and average latency of processing
     * inbound messages measured in microseconds.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param min                       Minimal latency value
     * @param max                       Maximal latency value
     * @param avg                       Average latency value
     */
    void GetOutboundLatency(uint64_t & min, uint64_t & max, uint64_t & avg) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasResidentMemorySize() const;

    /**
     * Get resident set size of the process.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetResidentMemorySize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasVirtualMemorySize() const;

    /**
     * Get virtual memory footprint of the process.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetVirtualMemorySize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasStrategiesNumber() const;

    /**
     * Get number of non-deleted strategies active in the service.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetStrategiesNumber() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasStrategyCallbackQueueSize() const;

    /**
     * Get size of the callbacks queue for strategies.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetStrategyCallbackQueueSize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasStrategyOperationsQueueSize() const;

    /**
     * Get size of the operations queue for strategies.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetStrategyOperationsQueueSize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasStrategyValidationsQueueSize() const;

    /**
     * Get size of the validations queue for strategies.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    uint64_t GetStrategyValidationsQueueSize() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasWarningMessageCount() const;

    /**
     * Get number of warning log messages output by the service for the last
     * one, five and fifteen minutes.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param one                       Number of messages for the last one
     *                                  minute
     * @param five                      Number of messages for the last five
     *                                  minutes
     * @param fifteen                   Number of messages for the last fifteen
     *                                  minutes
     */
    void GetWarningMessageCount(uint64_t & one, uint64_t & five, uint64_t & fifteen) const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasLogMessageCount() const;

    /**
     * Get number of log messages output by the service for the last
     * one, five and fifteen minutes.
     *
     * If data is not available for either of the parameters, parameter value
     * is cleared.
     *
     * @param one                       Number of messages for the last one
     *                                  minute
     * @param five                      Number of messages for the last five
     *                                  minutes
     * @param fifteen                   Number of messages for the last fifteen
     *                                  minutes
     */
    void GetLogMessageCount(uint64_t & one, uint64_t & five, uint64_t & fifteen) const;
    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasSelfTestDateTime() const;

    /**
     * Get datetime of the latest self test run.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    DateTime GetSelfTestDateTime() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasSelfTestStatus() const;

    /**
     * Get status of the latest self test run.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    SelfTestStatus GetSelfTestStatus() const;

    /**
     * Get count of quotes on markets.
     *
     * @return                          count of quotes
     */
    uint32_t GetQuotesCount() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasLogLevelPersisted() const;

    /**
     * Get log level persisted.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    Logger::Level GetLogLevelPersisted() const;

    /**
     * Check field presence.
     *
     * @return                          'true' if field value is set,
     *                                  'false' otherwise
     */
    bool HasActiveLogLevel() const;

    /**
     * Get active log level for service.
     *
     * Result is undefined if the field is not present (that is, if
     * corresponding Has method returns 'false').
     *
     * @return                          Field value
     */
    Logger::Level GetActiveLogLevel() const;

    std::ostream & Print(std::ostream & strm) const override;

    /** @cond PRIVATE */
public:
    QoS(protocol::QualityOfService * qos);
    const protocol::QualityOfService * get_impl_rd() const { return m_qos; }
    /** @endcond */

private:
    bool m_alloc;
    protocol::QualityOfService * m_qos;
};
}
