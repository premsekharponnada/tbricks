#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Venue Instrument Identifier.
//****************************************************************************************

#include "strategy/Linkage.h"

#include "strategy/Printable.h"
#include "strategy/SparseHash.h"
#include "strategy/type/MIC.h"
#include "strategy/type/String.h"
#include "strategy/type/VenueIdentifier.h"

namespace tbricks {

namespace types {
class VIID;
}

class InstrumentVenueIdentification;

/**
 * VenueInstrumentIdentifier(VIID) object is the representation to an instrument
 * in the outside world of market data and trading.
 *
 * VIID id triplet of VenueIdentifier, MIC and set of pairs <key, value> defines
 * set of VIID fields.
 */
class STRATEGY_EXPORT VenueInstrumentIdentifier : public Printable
{
public:
    /**
     * Default constructor: creates empty VIID.
     *
     * Creates VIID with empty venue, set of fields and MIC.
     */
    VenueInstrumentIdentifier() = default;

    /**
     * Copy convstructor: creates copy of VIID.
     *
     * @param viid                  VenueInstrumentIdentifier
     */
    VenueInstrumentIdentifier(const VenueInstrumentIdentifier & viid);

    /**
     * Constructor by Venue and MIC.
     *
     * Creates VIID instance with specified venue identifier and MIC. The set of
     * fields will be empty.
     *
     * @param venue                 VenueIdentifer
     * @param mic                   MIC
     */
    VenueInstrumentIdentifier(const VenueIdentifier & venue, const MIC & mic);

    /**
     * Copy operator
     *
     * @param viid                  VenueInstrumentIdentifier
     */
    VenueInstrumentIdentifier & operator=(const VenueInstrumentIdentifier & viid);

    /**
     * Destructor
     */
    ~VenueInstrumentIdentifier() override;

public:
    /**
     * Resolve venue instrument identifier.
     *
     * Synchronously fetches venue instrument identifier by instrument venue
     * identification.
     *
     * @param ivid                      Instrument venue identification
     *
     * @return                          'true' if VIID is available,
     *                                  'false' otherwise
     */
    bool Resolve(const InstrumentVenueIdentification & ivid);

public:
    /**
     * Method for specifying VenueIdentifier of VIID.
     *
     * @param venue                 VenueIdentifer
     */
    void SetVenueIdentifier(const VenueIdentifier & venue);

    /**
     * Method for specifying MIC for VIID.
     *
     * @param mic                   MIC
     */
    void SetMIC(const MIC & mic);

    /**
     * Retrieve VenueIdentifier of VIID.
     *
     * Returns empty VenueIdentifier, if VenueIdentifier didn't specified.
     *
     * @return                      VenueIdentifier
     */
    VenueIdentifier GetVenueIdentifier() const;

    /**
     * Retrieve MIC of VIID.
     *
     * Returns empty MIC, if MIC didn't specified.
     *
     * @return                      MIC
     */
    MIC GetMIC() const;

    /**
     * Retrieve field value of VIID by string key.
     *
     * Takes a key and puts corresponding field to value.
     *
     * @param key                   String
     * @param value                 String
     *
     * @return                      'true' if field with such key exists,
     *                              'false' otherwise.
     */
    bool Get(const String & key, String & value) const;

    /**
     * Sets field key and corresponding value in VIID.
     *
     * @param key                   String
     * @param value                 String
     */
    void Add(const String & key, const String & value);

    /**
     * Deletes field value by key.
     *
     * @param key                   String
     */
    void Delete(const String & key);

    /**
     * Retrieve all keys defined for the venue.
     *
     * @param keys                  Key to Value hash map
     *
     */
    void GetKeys(SparseHash<String, String> & keys) const;

    /**
     * Clears VIID, after using VIID will be empty.
     *
     */
    void Clear();

    /**
     * Checks VIID emptiness.
     * VIID is empty, if VenueIdentifier, MIC and set of fields is empty.
     *
     * @return                      'true' if VIID is empty,
     *                              'false' otherwise
     */
    bool Empty() const;

    /**
     * Retrieve result of hash functions on VIID.
     *
     * @return                      result of hash function
     */
    size_t GetHash() const;

public:
    /**
     * Less operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this less than viid
     *                              'false' otherwise
     */
    bool operator<(const VenueInstrumentIdentifier & viid) const;

    /**
     * Less or equals operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this less of equals than viid
     *                              'false' otherwise
     */
    bool operator<=(const VenueInstrumentIdentifier & viid) const;

    /**
     * Equals operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this equals viid
     *                              'false' otherwise
     */
    bool operator==(const VenueInstrumentIdentifier & viid) const;

    /**
     * Not equals operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this not equals viid
     *                              'false' otherwise
     */
    bool operator!=(const VenueInstrumentIdentifier & viid) const;

    /**
     * Greater operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this greater than viid
     *                              'false' otherwise
     */
    bool operator>(const VenueInstrumentIdentifier & viid) const;

    /**
     * Greater or equals operator.
     *
     * @param viid                  VenueInstrumentIdentifier
     *
     * @return                      'true' if this greater or equals than viid
     *                              'false' otherwise
     */
    bool operator>=(const VenueInstrumentIdentifier & viid) const;

public:
    /**
     * Retrieve string representation of VIID.
     *
     * @return                      string representation of VIID
     */
    String ToString() const override;

    /**
     * Puts string representation of VIID to ostream buffer.
     *
     * @return                      ostream buffer with this VIID
     */
    std::ostream & Print(std::ostream & strm) const override;

public:
    VenueInstrumentIdentifier(const types::VIID & value);
    types::VIID get_impl() const;

private:
    void * m_data = nullptr;
    size_t m_size = 0;
};

using VIID = VenueInstrumentIdentifier;
}
