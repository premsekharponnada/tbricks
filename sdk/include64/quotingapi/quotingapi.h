#pragma once

#include "export.h"
#include <ostream>
#include <memory>

#include <sys/time.h>

namespace QuotingAPI {
/**
 * Container stores data which used to pass data to QuoteDataWriter's write method
 */
struct QuoteData
{
    std::string m_symbol;    /*!< Trading symbol */
    timeval m_timestamp;     /*!< Must be provided if heartbeat autogeneration is disabled */
    timeval m_send_time;     /*!< Time when quote was sent by trading system */
    timeval m_exchange_time; /*!< Time provided by market */
    timeval m_receive_time;  /*!< Time when quote ack was received by trading system */

    double m_ask_price,
           m_ask_volume,
           m_bid_price,
           m_bid_volume;

    std::string m_venue;
    std::string m_trader_id;
    std::string m_reference;

    QuoteData() : m_timestamp{0,0},
                  m_send_time{0,0},
                  m_exchange_time{0,0},
                  m_receive_time{0,0}
    {}
};

std::ostream & QUOTEDATA_EXPORT operator << (std::ostream & strm, const QuoteData & qd);

/**
 * Interface for QuoteData writers
 */
class IQuoteDataWriter {
public:
    virtual ~IQuoteDataWriter()
    {}
    /**
     * writes data from quote_data parameter into Onetick database
     * @param quote_data quote
     * @return true - succeed or false - not
     */
    virtual bool write(const QuoteData & quote_data) = 0;
    virtual void report_heartbeat(const timeval & tv) = 0;
};

/**
 * Used to setup classes that implement IQuoteDataWriter
 */
struct QuotingConfig
{
    uint32_t quote_data_flush_period; /*!< how often need to flush data to file (milliseconds)*/
    bool     auto_heartbeat_generation; /*!< enable or disable auto heartbeat generation */
    std::string onetick_db, /*!< path to Onetick database */
                onetick_context, /*!< context name */
                onetick_db_mount, /*!< Onetick database mount  */
                onetick_location, /*!< Subsection of database configuration used by tick dump writer */
                onetick_log_file; /*!< logfile name */

    /**
     * by default heartbeat is enabled and flush_period is set to 1000 ms
     */
    QuotingConfig() : quote_data_flush_period(1000),
                      auto_heartbeat_generation(true),
                      onetick_context("DEFAULT"),
                      onetick_log_file("/dev/null")
    {}

};

/**
 * Factory for IQuoteDataWriter objects
 * @param cfg   configuration for QuoteDataWriter
 * @param estrm std::ostream used to pass errors out
 * @return configured writer object used for writing QuoteData to Onetick database
 */
std::unique_ptr<IQuoteDataWriter> QUOTEDATA_EXPORT create_quote_data_collector(const QuotingConfig & cfg);

}
