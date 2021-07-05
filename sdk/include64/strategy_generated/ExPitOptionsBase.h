#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// ExPitOptionsBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class String;
class TreeNodeIdentifier;


namespace protocol { class Expit; }

class STRATEGY_EXPORT ExPitOptionsBase : public Printable
{
protected:
    ExPitOptionsBase();
    ExPitOptionsBase(const ExPitOptionsBase & value);
    ExPitOptionsBase(ExPitOptionsBase && value) noexcept;
    ExPitOptionsBase & operator=(const ExPitOptionsBase & value);
    ExPitOptionsBase & operator=(ExPitOptionsBase && value) noexcept;
    virtual ~ExPitOptionsBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasPackageIdentifier() const;

    /**
     * Get expit package identifier.
     *
     *
     * @return                          expit package identifier
     */
    String GetPackageIdentifier() const;

    /**
     * %Set expit package identifier.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     expit package identifier
     */
    void SetPackageIdentifier(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasHandler() const;

    /**
     * Get handler.
     *
     *
     * @return                          handler
     */
    TreeNodeIdentifier GetHandler() const;

    /**
     * %Set handler.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     handler
     */
    void SetHandler(const TreeNodeIdentifier & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasMatchingCode() const;

    /**
     * Get matching code.
     *
     *
     * @return                          matching code
     */
    String GetMatchingCode() const;

    /**
     * %Set matching code.
     *
     *    
     * Delete field from request if field is empty 
     *  
     * @param value                     matching code
     */
    void SetMatchingCode(const String & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    ExPitOptionsBase(const protocol::Expit & value);
    ExPitOptionsBase(std::unique_ptr<protocol::Expit> && value);

    std::unique_ptr<protocol::Expit> & get_impl_wr() const;
    const std::unique_ptr<protocol::Expit> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::Expit> m_impl;
};

}
