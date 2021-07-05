#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SubsystemBase object
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
class SubsystemIdentifier;
class SystemIdentifier;


namespace protocol { class Subsystem; }

class STRATEGY_EXPORT SubsystemBase : public Printable
{
protected:
    SubsystemBase();
    SubsystemBase(const SubsystemBase & value);
    SubsystemBase(SubsystemBase && value) noexcept;
    SubsystemBase & operator=(const SubsystemBase & value);
    SubsystemBase & operator=(SubsystemBase && value) noexcept;
    virtual ~SubsystemBase();

public:
    /**
     * Check if field is set.
     *
     * Get subsystem identifier.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasIdentifier() const;

    /**
     * Get subsystem identifier.
     *
     * Get subsystem identifier.
     *
     *
     * @return                          subsystem identifier
     */
    SubsystemIdentifier GetIdentifier() const;

    /**
     * Check if field is set.
     *
     * System identifier which associated with this subsystem.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasSystemIdentifier() const;

    /**
     * Get system identifier.
     *
     * System identifier which associated with this subsystem.
     *
     *
     * @return                          system identifier
     */
    SystemIdentifier GetSystemIdentifier() const;

    /**
     * Check if field is set.
     *
     * Get subsystem short name.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get subsystem name.
     *
     * Get subsystem short name.
     *
     *
     * @return                          subsystem name
     */
    String GetName() const;

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasProperties() const;

    /**
     * Get subsystem properties.
     *
     *
     * @return                          subsystem properties
     */
    StringDictionary GetProperties() const;


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    SubsystemBase(const protocol::Subsystem & value);
    SubsystemBase(std::shared_ptr<protocol::Subsystem> && value);

    std::shared_ptr<protocol::Subsystem> & get_impl_wr() const;
    const std::shared_ptr<protocol::Subsystem> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::shared_ptr<protocol::Subsystem> m_impl;
};

}
