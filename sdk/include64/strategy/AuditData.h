#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AuditData
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Uuid.h"

#include "strategy/type/DateTime.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/StrategyIdentifier.h"

// \namespace tbricks
namespace tbricks {

namespace types {
class Parameters;
}

namespace protocol {
class StrategyCustomAuditEntry;
}

class ParameterDefinition;
class Variant;

/**
 * AuditData object stores plugin custom audit data.
 */
class STRATEGY_EXPORT AuditData : public Printable
{
public:
    class Stream;

public:
    AuditData();
    AuditData(const AuditData & audit_data);
    AuditData(AuditData && audit_data);
    virtual ~AuditData();
    AuditData & operator=(const AuditData & audit_data);
    AuditData & operator=(AuditData && audit_data);

    bool operator==(const AuditData & audit_data) const;
    bool operator!=(const AuditData & audit_data) const { return !operator==(audit_data); }

public:
    /**
     * Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const ParameterDefinition & definition, const AnyType & value);

    /**
     * Update parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if value was changed actually
     */
    bool UpdateParameter(const ParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a non-empty value for the key.
     *
     * Method returns 'true' if and only if container has a value for the
     * provided parameter definition and the value is not empty.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const ParameterDefinition & definition) const;

    /**
     * Extract parameter value from the parameter container.
     *
     * Method stores parameter value (if any exists in the container) in the
     * variable provided as a second argument and removes the parameter from
     * the container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool ExtractParameter(const ParameterDefinition & definition, AnyType & value);

    /**
     * Remove parameter value from the container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     */
    void RemoveParameter(const ParameterDefinition & definition);

    /**
     * %Set associated instrument.
     *
     * @param instrument                Instrument identifier
     */
    void SetInstrument(const InstrumentIdentifier & instrument);

    /**
     * Get associated instrument.
     *
     * @return                          Instrument identifier
     */
    const InstrumentIdentifier & GetInstrument() const;

    /**
     * Find out when the audit data entry was registered.
     *
     * This is the date and time the audit data entry was registered within the system.
     * For just created AuditData object this function will return empty date.
     *
     * @return                          Timestamp
     */
    const DateTime & GetHostCreatedDatetime() const;

    /**
     * %Set associated app identifier.
     *
     * @param id                app identifier
     */
    void SetAppIdentifier(const StrategyIdentifier & id);

    /**
     * Get associated app identifier.
     *
     * @return                          app identifier
     */
    const StrategyIdentifier & GetAppIdentifer() const;

    /**
     * %Set associated app type identifier.
     *
     * @param id                app type identifier
     */
    void SetAppTypeIdentifier(const Uuid & id);

    /**
     * Get associated app type identifier.
     *
     * @return                          app type identifier
     */
    const Uuid & GetAppTypeIdentifer() const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;
    void Clear();

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator() override;
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        ParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class AuditData;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    void Encode(protocol::StrategyCustomAuditEntry & audit_entry) const;
    void Decode(const protocol::StrategyCustomAuditEntry & audit_entry);

private:
    std::unique_ptr<types::Parameters> m_parameters;
    InstrumentIdentifier m_instrument;
    DateTime m_host_created_datetime;
    StrategyIdentifier m_app_identifier;
    Uuid m_app_type_identifier;
};

} // \namespace tbricks
