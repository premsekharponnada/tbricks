#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SystemBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class String;
class StringDictionary;
class SystemIdentifier;
enum class SystemState;


namespace protocol { class System; }

class STRATEGY_EXPORT SystemBase : public Printable
{
protected:
    SystemBase();
    SystemBase(const SystemBase & value);
    SystemBase(SystemBase && value) noexcept;
    SystemBase & operator=(const SystemBase & value);
    SystemBase & operator=(SystemBase && value) noexcept;
    virtual ~SystemBase();

public:
    /**
     * Check if field is set.
     *
     * Get system identifier.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get system identifier.
     *
     * Get system identifier.
     *
     *
     * @return                          system identifier
     */
    SystemIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get service short name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get system name.
     *
     * Get service short name.
     *
     *
     * @return                          system name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     * Get state of this system.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasState() const;

    /**
     * Get system state.
     *
     * Get state of this system.
     *
     *
     * @return                          system state
     */
    std::optional<SystemState> GetState() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get system properties.
     *
     *
     * @return                          system properties
     */
    StringDictionary GetProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    SystemBase(const protocol::System & value);
    SystemBase(std::shared_ptr<protocol::System> && value);

    std::shared_ptr<protocol::System> & get_impl_wr() const;
    const std::shared_ptr<protocol::System> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::System> m_impl;
};

}
