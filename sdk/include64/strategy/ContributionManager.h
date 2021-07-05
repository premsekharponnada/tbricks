#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Contribution Manager.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Strategy.h"

// \namespace tbricks
namespace tbricks {

class InstrumentVenueIdentification;
class Identifier;
class StringDictionary;

class STRATEGY_EXPORT ContributionManager
{
public:
    ContributionManager();
    virtual ~ContributionManager();

public:
    /**
     * Contribute is a remote operation and its status is delivered
     * to HandleRequestReply() as soon as the operation result is available.
     *
     * @param ivid                      Instrument venue identification data.
     * @param content                   Defined in contribution service configuration,
     *                                  values can be of types supported by specific
     *                                  contribution service.
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received.
     *
     * @return                          Request identifier
     */
    Identifier Contribute(const InstrumentVenueIdentification & ivid,
                          const StringDictionary & content,
                          const IRequestReplyHandler & handler = IRequestReplyHandler::Default()) const;

    /**
     * Can contribute
     *
     * @param ivid                      Instrument venue identification data.
     *
     * @return                          True if Contribute() is possible for this ivid,
     *                                  false otherwise
     */
    bool CanContribute(const InstrumentVenueIdentification & ivid) const;

private:
    ContributionManager(const ContributionManager & src) = delete;
    ContributionManager & operator=(const ContributionManager & src) = delete;
};

} // \namespace tbricks
