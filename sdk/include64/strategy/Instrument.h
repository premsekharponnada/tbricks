#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Instrument type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/InstrumentGroup.h"
#include "strategy/type/CFI.h"
#include "strategy/type/VenueInstrumentIdentifier.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/SymbologyKey.h"
#include "strategy/InstrumentComponent.h"
#include "strategy/Strategy.h"
#include "strategy/ExtraData.h"
#include "strategy/type/CombinationType.h"
#include "strategy/stream/InstrumentStream.h"
#include "strategy/instrument/InstrumentAttributes.h"
#include "strategy_generated/InstrumentModifierBase.h"

namespace tbricks {

namespace protocol {
class Instrument;
}

class InstrumentModifier;
class XMLDocument;
class PriceStructure;

/**
 * Instrument object.
 *
 * Represents instrument data as it is known in the system. Typical usage of
 * instrument objects requires an instrument identifier and an additional
 * resolution step to fetch the data from the instrument server.
 *
 * @code
 * if (m_instrument.Resolve(instrumentIdentifier))
 * {
 *      std::vector<InstrumentVenueIdentification> ivids;
 *      m_instrument.GetMarketDataIdentifications(ivids);
 *      for (size_t i = 0; i < ivids.size(); i++)
 *      {
 *          StatisticsStream stream(m_owner);
 *          stream.Open(Stream::SNAPSHOT_AND_LIVE, ivids[i]);
 *      }
 * }
 * @endcode
 */
class STRATEGY_EXPORT Instrument : public Printable
{
public:
    class RequestResult;

public:
    class Options;
    class Modifier;

public:
    /*
     * Enumeration of possible CFI variants
     */
    enum CFI_Variant
    {
        Undefined = 0,
        Forward = 1,
        Turbo = 2,
        DownAndIn = 3,
        DownAndOut = 4,
        UpAndIn = 5,
        UpAndOut = 6,
        BinaryAsset = 7,
        BinaryCash = 8,
        AveragePriceOption = 9,
        EUSIPA1200 = 10,
        EUSIPA2299 = 11,
        FX = 12,
        CappedCall = 13,
        MiniFuture = 14,
        DividendFutures = 15,
        EquityReturn = 16,
        InterestRateSwap = 17,
        EquitySwap = 18,
        ForwardStart = 19,
        EUSIPA1300 = 20,
        CappedPut = 21,
        EUSIPA1250 = 22,
        EUSIPA1320 = 23,
        CBBC = 24,
        EUSIPA2300 = 25,
        EUSIPA1260 = 26,
        InlineWarrant = 27,
        CalendarSpreadOption = 28
    };

    /**
     * Enumeration of supported price display formats
     */
    enum PriceDisplayFormat
    {
        Decimal = 0,
        Wholes = 1,
        Halves = 2,
        Quarters = 4,
        Eights = 8,
        Sixteenths = 16,
        ThirtySeconds = 32,
        ThirtySeconds_half_ = 33,
        ThirtySeconds_quarter_ = 34,
        ThirtySeconds_eighth_ = 35,
        SixtyFourths = 64,
        SixtyFourths_half_ = 65,
        Percentage = 100,
        HundredAndTwentyEighths = 128,
        TwoHundredAndFiftySixths = 256,
        FiveHundredAndTwelfths = 512,
        BasisPoints = 10000
    };

public:
    /**
     * Constructor.
     *
     * Constructs new, empty Instrument instance.
     */
    Instrument();
    Instrument(const Instrument & instrument);

    /**
     * Constructor.
     *
     * Creates new Instrument instance with specified instrument
     * identifier and immediately tries to resolve it.
     *
     * @see Resolve
     *
     * @param instrument_id             Instrument identifier
     */
    Instrument(const InstrumentIdentifier & instrument_id);
    Instrument(std::shared_ptr<protocol::Instrument> instrument);
    const std::shared_ptr<protocol::Instrument> & get_message() const;
    Instrument & operator=(const protocol::Instrument & msg);

    /**
     * Destructor.
     */
    ~Instrument();

    Instrument & operator=(const Instrument & instrument);

    bool operator<(const Instrument & instrument) const;

public:
    /**
     * Resolve instrument.
     *
     * Synchronously fetches full description of the instrument
     * identified by the parameter.
     *
     * @param instrument_id             Instrument identifier
     *
     * @return                          'true' if instrument is available,
     *                                  'false' otherwise
     */
    bool Resolve(const InstrumentIdentifier & instrument_id);

    /**
     * Resolve instrument identifiers.
     *
     * Synchronously fetches instrument identifiers by filter.
     * Instruments symbology keys remain unchanged until flushing the cache that is performed at engine restart.
     * I.e. before engine restart, if instrument no longer matches the filter,
     * it will still be returned by this method, but if a new instrument start matches the filter,
     * it will be added to the returned values.
     *
     * @param filter                    Instrument filter.
     *                                  Instrument filter must contain only one condition.
     *                                  Condition can be filter on Venue Instrument identifier (
     * tbricks::InstrumentStream::Filters::ByVenueInstrumentIdentifierFilter ) or by Symbology Key (
     * tbricks::InstrumentStream::Filters::BySymbologyKeyFilter )
     *
     * @param instruments               Vector of instrument identifiers
     *                                  to be returned for requested Instrument
     */
    static void Resolve(const InstrumentStream::Filters::Filter & filter, std::vector<InstrumentIdentifier> & instruments);

    /**
     * Get instrument identifier.
     *
     * Returns system instrument identifier the object is associated with.
     *
     * @return                          System instrument identifier
     */
    InstrumentIdentifier GetIdentifier() const;

    /**
     * Get datetime of creation.
     *
     * Returns datetime of instrument creation.
     *
     * @return                          Created datetime
     */
    DateTime GetHostCreatedDatetime() const;

    /**
     * Get datetime of last modification.
     *
     * Returns datetime of last instrument modification.
     *
     * @return                          Modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    /**
     * Retrieve short instrument name.
     *
     * The method returns exchange short name of the instrument, which could be
     * similar to exchange mnemonic but could also be the company name or
     * similar (e.g. IBM Ltd.).
     *
     * For unresolved instruments returns empty string.
     *
     * @return                          Short instrument name, or an empty
     *                                  instance if instrument is not resolved
     *                                  or short name is not set.
     */
    String GetShortName() const;

    /**
     * Retrieve long instrument name.
     *
     * The method returns exchange long name of the instrument, full
     * description (e.g. International Business Machines, Global Operations
     * Ltd.).
     *
     * For unresolved instruments returns empty string.
     *
     * @return                          Long instrument name, or an empty
     *                                  instance if instrument is not resolved
     *                                  or short name is not set.
     */
    String GetLongName() const;

    /**
     * Retrieve instrument mnemonic.
     *
     * The method returns exchange mnemonic of the instrument, generally the
     * ticker symbol (e.g. IBM).
     *
     * For unresolved instruments returns empty string.
     *
     * @return                          Instrument mnemonic, or an empty
     *                                  instance if instrument is not resolved
     *                                  or short name is not set.
     */
    String GetMnemonic() const;

    /**
     * Retrieve instrument CFI code.
     *
     * Returns Classification of Financial Instruments (CFI) code, according to
     * ISO 10962. This is a six character taxonomy describing the instrument
     * class and some of its properties.
     *
     * For unresolved instruments returns empty string.
     *
     * @return                          Instrument CFI code, or an empty
     *                                  instance if instrument is not resolved
     *                                  or short name is not set.
     */
    CFI GetCFI() const;

    /**
     * Retrieve instrument CFI variant.
     *
     *
     * For unresolved instruments returns Undefined.
     *
     * @return                          Instrument CFI variant, or an empty
     *                                  instance if instrument is not resolved
     *                                  or short name is not set.
     */
    CFI_Variant GetCFI_Variant() const;

    /**
     * Retrieve instrument currency.
     *
     * For unresolved instruments returns empty currency.
     *
     * @return                          Instrument currency, or an empty
     */
    Currency GetCurrency() const;

    /**
     * Get base currency attribute
     *
     * @return                          Base currency if exists, <empty> otherwise
     */
    Currency GetBaseCurrency() const;

    /**
     * Get instrument factor attribute
     *
     * @return                          Factor value if exists, 1.0 otherwise
     */
    Double GetFactor() const;

    /**
     * Get instrument multiplier attribute
     *
     * @return                          Multiplier value if exists, 1.0 otherwise
     */
    Double GetMultiplier() const;

    /**
     * Get strike price attribute
     *
     * @return                          Strike price value if exists, <empty> otherwise
     */
    Price GetStrikePrice() const;

    /**
     * Get upper strike price attribute
     *
     * @return                          Upper strike price value if exists, <empty> otherwise
     */
    Price GetUpperStrikePrice() const;

    /**
     * Get lower strike price attribute
     *
     * @return                          Lower strike price value if exists, <empty> otherwise
     */
    Price GetLowerStrikePrice() const;

    /**
     * Get cap price attribute
     *
     * @return                          Cap price value if exists, <empty> otherwise
     */
    Price GetCapPrice() const;

    /**
     * Get Maturity month year attribute as string
     *
     * @return                          MMY value if exists, <empty> otherwise
     */
    String GetMaturityMonthYear() const;

    /**
     * Get maturity date attribute
     *
     * @return                          Maturity date value if exists, <empty> otherwise
     */
    CalendarDate GetMaturityDate() const;

    /**
     * Get barrier level attribute
     *
     * @return                          BarrierLevel value if exists, <empty> otherwise
     */
    Double GetBarrierLevel() const;

    /**
     * Get barrier rebate period attribute
     *
     * @return                          BarrierRebatePeriod value if exists, <empty> otherwise
     */
    Double GetBarrierRebatePeriod() const;

    /**
     * Get BarrierRebate
     *
     * @return                          BarrierRebate value if exists, <empty> otherwise
     */
    Double GetBarrierRebate() const;

    /**
     * Get home exchange attribute
     * The main exchange for an instrument if it's multilisted
     *
     * @return                         PrimaryMarket value if exists, <empty> otherwise
     */
    MIC GetPrimaryMarket() const;

    /**
     * Check if "deleted" field available.
     *
     * @return                          'true' if field is set,
     *                                  'false' otherwise
     */
    bool HasDeleted() const;

    /**
     * Get value of "deleted" field.
     *
     * If "deleted" field is not set, the method returns empty object.
     *
     * @return                          Value of "deleted" field
     */
    Boolean GetDeleted() const;

    /**
     * Get number of components.
     *
     * @return                          Number of component if instrument
     *                                  is not empty and zero otherwise.
     */
    size_t GetComponentNumber() const;

    /**
     * Get instrument component from the components vector by its number.
     *
     * @throws tbricks::IndexOutOfBoundsException
     *                                  If passing parameter is greater than
     *                                  the components vector length
     *
     * @param index                     component number
     * @return                          InstrumentComponent
     */
    InstrumentComponent GetComponent(size_t i) const;

    /**
     * Check if instrument in specified instrument group
     *
     * @param                           Instrument group identifier
     *
     * @return                          true if instrument in specified groups and false in otherwise
     */
    bool HasInstrumentGroup(const InstrumentGroupIdentifier & identifier) const;

    /**
     * Get instrument composites.
     *
     * If instrument is not resolved or is not associated with any group, the
     * argument is shrunk  to a zero size.
     *
     * @return                          Vector of instrument groups
     */
    void GetInstrumentGroups(std::vector<InstrumentGroup> & groups) const;

    /**
     * Get instrument groups.
     *
     * If instrument is not resolved or is not associated with any group, the
     * argument is shrunk  to a zero size.
     *
     * @return                          Vector of instrument groups
     */
    void GetInstrumentGroups(std::vector<InstrumentGroupIdentifier> & groups) const;

    bool HasCombinationType() const;
    void GetCombinationType(CombinationType & combination) const;

    /**
     * Get existence of instrument composites.
     *
     * Returns true of instrument has components and false for not composite instruments.
     *
     * @return                          true if instrument is composite and false in otherwise.
     */
    bool HasComponents() const;

    /**
     * Get instrument composites.
     *
     * Returns a vector of instrument components for composite instruments.
     * If instrument is not resolved or has no components, the argument
     * is shrunk to a zero size.
     *
     * @return                          Vector of instrument's composites
     */
    void GetComponents(std::vector<InstrumentComponent> & components) const;

    /**
     * Get leg ratio from composite instrument.
     *
     * Returns a ration of related leg.
     *
     * @return                          false if related leg was not found
     * @return                          related ratio
     */
    bool GetRatio(const InstrumentIdentifier & instrument_id, Double & ratio) const;

    /**
     * Get instrument symbology keys.
     *
     * Returns a vector of symbology keys.
     *
     * @return                          Vector of symbology keys
     */
    void GetSymbologyKeys(std::vector<SymbologyKey> & symbology_keys) const;

    /**
     * Get venue instrument identifiers.
     *
     * For resolved instrument, returns a vector of venue instrument identifiers
     * data for venues where instrument is available.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param viids                     Output vector
     */
    void GetVenueInstrumentIdentifiers(std::vector<VenueInstrumentIdentifier> & viids) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where instrument is available.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available from the venue identified by the
     * second parameter.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where the instrument can be traded.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetTradingIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available from the venue identified by the
     * second parameter. The call returns only those identifiers that
     * can be used to trade on the venue; if there are none, the first
     * parameter is shrunk to zero.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetTradingIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to trade the
     * instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetTradingIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get ex-pit instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where the expit can be sent.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetExPitIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get ex-pit instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available from the venue identified by the
     * second parameter. The call returns only those identifiers that
     * can be used to send expit to the venue; if there are none, the first
     * parameter is shrunk to zero.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetExPitIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get ex-pit instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to send the expit.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetExPitIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where the instrument can be traded.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetQuotingIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available from the venue identified by the
     * second parameter. The call returns only those identifiers that
     * can be used to trade on the venue; if there are none, the first
     * parameter is shrunk to zero.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetQuotingIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to trade the
     * instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetQuotingIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where the instrument can be traded.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetDirectedQuoteRequestIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for venues where the instrument can be traded.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetQuoteRequestIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available from the venue identified by the
     * second parameter. The call returns only those identifiers that
     * can be used to trade on the venue; if there are none, the first
     * parameter is shrunk to zero.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetQuoteRequestIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to trade the
     * instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetQuoteRequestIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for all available venues.
     *
     * The call returns only those identifiers that can be used to obtain
     * market data for the instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetMarketDataIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for the venue specified by the second parameter.
     * The call returns only those identifiers that can be used to obtain
     * market data for the instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetMarketDataIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to obtain
     * market data for the instrument.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetMarketDataIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for all available venues.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetContributionIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for the venue specified by the second parameter.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetContributionIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetContributionIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venue identifications.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for all available venues.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     */
    void GetMarketCommandIdentifications(std::vector<InstrumentVenueIdentification> & ids) const;

    /**
     * Get instrument venue identifications for a given venue.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data for the venue specified by the second parameter.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param venue_id                  Venue identifier
     */
    void GetMarketCommandIdentifications(std::vector<InstrumentVenueIdentification> & ids, const Venue & venue_id) const;

    /**
     * Get instrument venue identifications for a given MIC.
     *
     * For resolved instrument, returns a vector of instrument venue
     * identification data available for the MIC provided as the second
     * parameter.
     *
     * The call returns only those identifiers that can be used to contribute.
     *
     * If instrument is not resolved or the data is not available, parameter is
     * resized to zero.
     *
     * @param ids                       Output vector
     * @param MIC                       Market identification code
     */
    void GetMarketCommandIdentifications(std::vector<InstrumentVenueIdentification> & ids, const MIC & mic) const;

    /**
     * Get instrument venues.
     *
     * Returns venue identifiers of venues where the instrument is available
     * either for trading or for fetching market data.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     */
    void GetVenues(std::vector<Venue> & venue_ids) const;

    /**
     * Get instrument venues.
     *
     * Returns venue identifiers of venues where instrument is available for
     * trading.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     */
    void GetTradingVenues(std::vector<Venue> & venue_ids) const;

    /**
     * Get instrument venues for a given MIC.
     *
     * Returns venue identifiers of venues where instrument is available for
     * trading, filtered by a MIC.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     * @param MIC                       Market identification code
     */
    void GetTradingVenues(std::vector<Venue> & venue_ids, const MIC & mic) const;

    /**
     * Get liquidity pools.
     *
     * Returns liquidity pool identifiers for given IVID where instrument is available for
     * trading and has InstrumentTradingInformations
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param id                        Requested IVID
     * @param pool_ids                  Output vector
     */
    static void GetTradingLiquidityPools(const InstrumentVenueIdentification & id, std::vector<LiquidityPoolIdentifier> & pool_ids);

    /**
     * Get expit venues.
     *
     * Returns venue identifiers of venues where expit can be sent to.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     */
    void GetExPitVenues(std::vector<Venue> & venue_ids) const;

    /**
     * Get expit venues for a given MIC.
     *
     * Returns venue identifiers of venues where expit can be sent to,
     * filtered by a MIC.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     * @param MIC                       Market identification code
     */
    void GetExPitVenues(std::vector<Venue> & venue_ids, const MIC & mic) const;

    /**
     * Get instrument venues.
     *
     * Returns venue identifiers of venues where instrument is available for
     * quoting.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     */
    void GetQuotingVenues(std::vector<Venue> & venue_ids) const;

    /**
     * Get instrument venues for a given MIC.
     *
     * Returns venue identifiers of venues where instrument is available for
     * quoting, filtered by a MIC.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     * @param MIC                       Market identification code
     */
    void GetQuotingVenues(std::vector<Venue> & venue_ids, const MIC & mic) const;

    /**
     * Get instrument venues.
     *
     * Returns venue identifiers of venues that provide market data for the
     * instrument.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     */
    void GetMarketDataVenues(std::vector<Venue> & venue_ids) const;

    /**
     * Get instrument venues for a given MIC.
     *
     * Returns venue identifiers of venues that provide market data for the
     * instrument, filtered by a MIC.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param venue_ids                 Output vector
     * @param MIC                       Market identification code
     */
    void GetMarketDataVenues(std::vector<Venue> & venue_ids, const MIC & mic) const;

    /**
     * Get list of isntrument MICs.
     *
     * Returns market identification codes for the instrument.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetMICs(std::vector<MIC> & mics) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to trade the instrument.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetTradingMICs(std::vector<MIC> & mics) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to trade the instrument on the given venue.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     * @param venue_id                  Venue identifier
     */
    void GetTradingMICs(std::vector<MIC> & mics, const Venue & venue_id) const;

    /**
     * Get list of expit MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to send the expit.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetExPitMICs(std::vector<MIC> & mics) const;

    /**
     * Get list of expit MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to send the expit, filtered by a given venue.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     * @param venue_id                  Venue identifier
     */
    void GetExPitMICs(std::vector<MIC> & mics, const Venue & venue_id) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to trade the instrument.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetQuotingMICs(std::vector<MIC> & mics) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to trade the instrument on the given venue.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     * @param venue_id                  Venue identifier
     */
    void GetQuotingMICs(std::vector<MIC> & mics, const Venue & venue_id) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to obtain market data for the instrument.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetMarketDataMICs(std::vector<MIC> & mics) const;

    /**
     * Get list of instrument MICs.
     *
     * Returns market identification codes for the instrument that can be used
     * to obtain market data for the instrument from the given venue.
     *
     * If instrument is not available or there are no appropriate venues,
     * the parameter is resized to zero.
     *
     * @param mics                      Output vector
     */
    void GetMarketDataMICs(std::vector<MIC> & mics, const Venue & venue_id) const;

    /**
     * Get user data.
     *
     * @return                          User data container
     */
    ExtraData GetExtraData() const;

    /**
     * Get price structure
     *
     * @return                          Price structure
     */
    PriceStructure GetPriceStructure() const;

    /**
     * Get price display format.
     *
     * Price display format used for display purposes. Full documentation can be found
     * here - http://confluence.tbricks.com/display/Tbricks26/Fractions+and+prices.
     *
     * @return                          Price display format
     */
    PriceDisplayFormat GetPriceDisplayFormat() const;

    /**
     * Get default price display decimals.
     *
     * Price decimals used for display purposes. Full documentation can be found
     * here - http://confluence.tbricks.com/display/Tbricks26/Fractions+and+prices.
     *
     * @return                          Price format code
     */
    Integer GetPriceDisplayDecimals() const;

    /**
     * Returns double value for adjust price to integer hash-usability representation.
     *
     * If instrument price display format is 1/2^k and default price decimals is n,
     * than returned value will 2^k * 10^n.
     * The value (price * 2^k * 10^n) is good for using for chach key.
     *
     */
    Double GetPriceHashMultiplier() const;

    /**
     * Returns 1.0 / GetPriceHashMultiplier() value
     *
     */
    Double GetPricePrecision() const;

    /**
     * Format price.
     *
     * Get string that contains formatted price.
     *
     * @param price           Price
     *
     * @return                String that contains price
     *                        with number of decimal points
     *                        specific for this instrument
     */
    String FormatPrice(const Price & price) const;

    /**
     * Round price
     *
     * Round price according with format specific for this instrument.
     *
     * @param price           Price
     * @return                Rounded price
     */
    Price RoundPrice(const Price & price) const;

    /**
     * Get valid until date time of instrument.
     *
     * @return          const valid date time
     */
    DateTime GetValidUntilDatetime() const;

    /**
     * Has primary instrument attributes
     *
     * @return bool             True if instrument has primary attributes
     */
    bool HasAttributes() const;

    /**
     * Has instrument attribute
     *
     * @param  type             Attribute type(Instrument/Leg/Underlying/AlternativeID)
     * @return bool             True if instrument has attributes
     *                          of specified type taged with given definition, false otherwise
     *
     */
    bool HasAttributes(InstrumentAttributes::AttributeType type) const;

    /**
     *Get primary instrument attribute
     *
     * @param value             Attributes
     * @return                  True if instrument has attribute value
     *                          tagged with given name, false otherwise
     */
    bool GetAttributes(InstrumentAttributes & attributes) const;

    /**
     * Get instrument attributes for legs
     * @param value             Vector to store Attributes
     * @return                  True if instrument has leg attributes
     *                          false otherwise
     */
    bool GetLegAttributes(std::vector<InstrumentAttributes> & attributes) const;

    /**
     * Get instrument attributes for underlying
     * @param value             Vector to store Attributes
     * @return                  True if instrument has underlying attributes
     *                          false otherwise
     */
    bool GetUnderlyingAttributes(std::vector<InstrumentAttributes> & attributes) const;

    /**
     * Get instrument attributes by type
     * @param type              AttributeType(Instrument/Leg/Underlying/AlternativeID)
     * @param value             Vector to store Attributes
     * @return                  True if instrument has attributes with specified type
     *                          false otherwise
     *
     */
    bool GetAttributes(InstrumentAttributes::AttributeType type, std::vector<InstrumentAttributes> & attributes) const;

    /**
     * Get primary instrument attribute by definition
     * @param definition        Instrument attribute definition
     * @param value             Value to store result
     * @return                  True if instrument has primary attribute for given definition
     *
     */
    bool GetAttribute(const InstrumentAttributeDefinition & definition, AnyType & value) const;

    /**
     * Get instrument attribute by definition and type + index
     * @param type              Instrument attribute type
     * @param index             Instrument attributes index (2 for second leg as example)
     * @param definition        Instrument attribute definition
     * @param value             Value to store result
     * @return                  True if instrument has attribute for given type, index and definition
     *                          false otherwise
     */
    bool
    GetAttribute(InstrumentAttributes::AttributeType type, size_t index, const InstrumentAttributeDefinition & definition, AnyType & value) const;

    /// returns Empty identifier if not found
    static InstrumentIdentifier GetRelatedOption(const InstrumentIdentifier & id);

    String GetComment() const;

    bool IsDeltaNeutral() const;

    bool IsTemporary() const;

public:
    /**
     * Check if object has association with system instrument identifier.
     *
     * Unless associated with system identifier by means of SetIdentifier()
     * method, Instrument is considered to be empty.
     *
     * @return                          "true" if system instrument identifier
     *                                  is set and is not empty, "false"
     *                                  otherwise
     */
    bool Empty() const;

    /**
     * Drop association with system instrument identifier.
     *
     * After this call, the object becomes empty, and access to any resolved
     * data such as instrument components etc. yields undefined behavior.
     */
    void Clear();

    void Merge(const Instrument & instrument);

public:
    /**
     * Send instrument create request.
     *
     * Method sends a request to create instrument.
     *
     * Instrument create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Creation request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Instrument::RequestResult object
     */
    static RequestResult SendCreateRequest(const Instrument::Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send instrument modify request.
     *
     * Method sends a request to modify instrument.
     *
     * Instrument modify request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param modifier                  Modify request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     * @deprecated Deprecated in 2.14.5 use "RequestResult SendModifyRequest(const InstrumentModifier &, IRequestReplyHandler &)" instead
     *
     * @return                          Instrument::RequestResult object
     */
    [[deprecated(DEPRECATE_LINK)]] static RequestResult SendModifyRequest(const Instrument::Modifier & modifier,
                                                                          IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send instrument modify request.
     *
     * Method sends a request to modify instrument.
     *
     * Instrument modify request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param modifier                  Modify request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Instrument::RequestResult object
     */
    static RequestResult SendModifyRequest(const InstrumentModifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send instrument delete request.
     *
     * Method sends a request to delete instrument.
     *
     * Instrument delete request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param identifier                Instrument identifier
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Instrument::RequestResult object
     */
    static RequestResult SendDeleteRequest(const InstrumentIdentifier & identifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void get_fractions(double price, int32_t & fractions, int32_t & additional) const;

private:
    friend STRATEGY_EXPORT class CombinationCreator;

    friend STRATEGY_EXPORT class IrdXmlPrinter;

    friend STRATEGY_EXPORT class Converter;

private:
    std::shared_ptr<protocol::Instrument> m_msg;
};

STRATEGY_EXPORT
std::ostream & operator<<(std::ostream & strm, Instrument::PriceDisplayFormat format);

/**
 * InstrumentModifier object.
 * Defined modify options for sending modify request.
 *
 * Fill members Modifier class and call:
 * @code
 * Instrument::SendModifyRequest(modifier, request_handler);
 * @endcode
 * for modify instrument.
 */
class STRATEGY_EXPORT InstrumentModifier : public InstrumentModifierBase
{
public:
    /**
     * Create modifier for scpecified instrument
     */
    InstrumentModifier(const InstrumentIdentifier & identifier);

    /**
     * Get instrument identifier.
     *
     * @return                          instrument identifier
     */
    InstrumentIdentifier GetInstrumentIdentifier() const;

    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasCFI_Variant() const;

    /**
     * %Set cfi variant
     *
     * @param value                     cfi variant
     */
    void SetCFI_Variant(Instrument::CFI_Variant value);

    /**
     * Get cfi variant
     *
     * @return                          cfi variant or empty value if cfi variant is not set
     */
    std::optional<Instrument::CFI_Variant> GetCFI_Variant() const;

    /**
     * Check if field is set
     *
     * @return                          True if the field is set. false otherwise
     */
    bool HasPriceDisplayFormat() const;

    /**
     * %Set price display format
     *
     * @param value                     price display format
     */
    void SetPriceDisplayFormat(Instrument::PriceDisplayFormat value);

    /**
     * Get price display format
     *
     * @return                          price display format or empty value if price display format is not set
     */
    std::optional<Instrument::PriceDisplayFormat> GetPriceDisplayFormat() const;

    /**
     * Check if field is set
     *
     * @return                          True if the field is set. false otherwise
     */
    bool HasPriceDisplayDecimals() const;

    /**
     * %Set price display decimals.
     *
     * @throw Exception if passed value is empty
     * @param value                     price display decimals
     */
    void SetPriceDisplayDecimals(const Integer & value);

    /**
     * Get price display decimals
     *
     * @return                          price display decimals or empty Integer if price display decimals is not set
     */
    Integer GetPriceDisplayDecimals() const;

    /**
     * Check if field is set
     *
     * @return                          True if the field is set. false otherwise
     */
    bool HasAttributes() const;
    void SetAttributes(const InstrumentAttributes & attributes);
    void SetLegAttributes(const std::vector<InstrumentAttributes> & attributes);
    void SetUnderlyingAttributes(const std::vector<InstrumentAttributes> & attributes);
    void SetAttributes(InstrumentAttributes::AttributeType type, const std::vector<InstrumentAttributes> & attributes);

    /**
     * Add instrument group to the list of existing groups of the instrument
     * @param value                     instrument group
     */
    void AddGroup(const InstrumentGroupIdentifier & value);

    /**
     * Add instrument groups to the list of existing groups of the instrument
     * @param values                    container (vector, hash, map, ...) of instrument groups
     */
    template <typename TYPE>
    void AddGroups(const TYPE & values)
    {
        for (const auto & value : values) {
            AddGroup(value);
        }
    }

    /**
     * Remove instrument from the group
     * If the group does not contain the instrument, nothing happens
     * @param value                     instrument group
     */
    void DeleteGroup(const InstrumentGroupIdentifier & value);

    /**
     * Remove instrument from the groups
     * If the group does not contain the instrument, nothing happens
     * @param values                    container (vector, hash, map, ...) of instrument groups
     */
    template <typename TYPE>
    void DeleteGroups(const TYPE & values)
    {
        for (const auto & value : values) {
            DeleteGroup(value);
        }
    }

    /**
     * Add venue instrument identifier to the list of existing identifers of the instrument
     * @param value                     venue instrument identifier
     */
    void AddVenueInstrumentIdentifier(const VenueInstrumentIdentifier & value);

    /**
     * Add venue instrument identifiers to the list of existing identifers of the instrument
     * @param values                    container (vector, hash, map, ...) of venue instrument identifiers
     */
    template <typename TYPE>
    void AddVenueInstrumentIdentifiers(const TYPE & values)
    {
        for (const auto & value : values) {
            AddVenueInstrumentIdentifier(value);
        }
    }

    /**
     * Remove venue instrument identifier from the list of venue instrument identifiers of the instrument
     * If the instrument does not have the venue instrument identifier, nothing happens
     * @param value                     venue instrument identifier
     */
    void DeleteVenueInstrumentIdentifier(const VenueInstrumentIdentifier & value);

    /**
     * Remove venue instrument identifiers from the list of venue instrument identifiers of the instrument
     * If the instrument does not have the venue instrument identifiers, nothing happens
     * @param values                    container (vector, hash, map, ...) of venue instrument identifiers
     */
    template <typename TYPE>
    void DeleteVenueInstrumentIdentifiers(const TYPE & values)
    {
        for (const auto & value : values) {
            DeleteVenueInstrumentIdentifier(value);
        }
    }
};

/**
 * Instrument::RequestResult object.
 *
 * Defines feedback information after the creation of a instrument.
 * Consists of InstrumentIdentifier and request Identifier.
 *
 */
class STRATEGY_EXPORT Instrument::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const InstrumentIdentifier & instrument_identifier);

    const Identifier & GetRequestIdentifier() const;
    const InstrumentIdentifier & GetInstrumentIdentifier() const;

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    InstrumentIdentifier m_instrument_identifier;
};
}
