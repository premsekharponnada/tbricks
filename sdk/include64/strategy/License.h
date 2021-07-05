#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// License object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/LicenseType.h"

namespace tbricks {

class Date;
class Identifier;
class IRequestReplyHandler;
class String;

namespace license {
class License;
}

/**
 * License object describes Tbricks system license.
 */
class STRATEGY_EXPORT License : public Printable
{
public:
    class RequestResult;

public:
    /**
     * Empty constructor.
     *
     * Creates empty license object of Unknown type.
     */
    License();

    License(License && other) noexcept;

    License & operator=(License && other) noexcept;

    /**
     * Constructor from data and filename.
     *
     * Creates license object from separately provided data and filename.
     *
     * @param data                         License data
     * @param filename                     License file name
     *
     * @throws TypeInitializationException if the license cannot be created, e. g. if the
     *         license data or license signature in filename are invalid.
     */
    License(const String & data, const String & filename);

    ~License() override;

    /**
     * Get license type.
     *
     * @return license type
     */
    LicenseType GetType() const;

    /**
     * Get license target system name.
     *
     * @return target system name
     */
    String GetTargetSystem() const;

    /**
     * Get license customer.
     *
     * @return customer
     */
    String GetCustomer() const;

    /**
     * Get license expiration date.
     *
     * @return license expiration date
     */
    Date GetExpirationDate() const;

    /**
     * Check if license is suitable for any system.
     *
     * @return true if license is applicable to any system
     */
    bool IsMatchingAnySystem() const;

    /**
     * Check if license is expired.
     *
     * @return true if license is expired
     */
    bool IsExpired() const;

    /**
     * Resolve license.
     *
     * Synchronously fetches license of the current system.
     *
     * @return true if license is available, false otherwise
     */
    bool Resolve() const;

    /**
     * Send a request to bind new license to the current system.
     *
     * This method can only be used from Accessory Engine.
     *
     * @param license                      License to be bound

     * @param handler                      Reply handler
     *
     * @return request identifier
     */
    static Identifier SendUploadRequest(const String & data, const String & filename, IRequestReplyHandler & handler);

    std::ostream & Print(std::ostream & strm) const override;

private:
    std::unique_ptr<license::License> m_impl;
};
}
