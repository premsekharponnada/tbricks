#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Combination classificator type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Strategy.h"

#include "strategy/SparseHash.h"
#include "strategy/Instrument.h"

#include <memory>

namespace tbricks {

namespace protocol {
class Instrument;
}
class CombinationCreatorStructureImpl;

class STRATEGY_EXPORT CombinationCreator
{
public:
    /**
     * Class for description combination structure.
     * Contains set of InstrumentComponents and optionally
     * "Underlying price level" parameter.
     */
    class STRATEGY_EXPORT Structure : public Printable
    {
    public:
        Structure();
        Structure(const Structure & structure);
        Structure(Structure && structure);
        Structure & operator=(const Structure & structure);
        Structure & operator=(Structure && structure);
        virtual ~Structure();

    public:
        /**
         * Adds new component to combination structure if component with same identifier
         * not existed and replaces existed one in otherwise.
         *
         * @param   component               InstrumentComponent for add or replace
         *
         * @return  boolean                 true, if component not existed before add and
         *                                  false in otherwise
         */
        bool AddComponent(const InstrumentComponent & component);

        /**
         * %Set list of components for combination structure.
         *
         * @param   components              List of InstrumentComponent's
         *
         */
        void SetComponents(const std::vector<InstrumentComponent> & components);

        /**
         * Get available markets where combination can be created.
         *
         * @param markets                       Result vector
         *
         */
        void GetAvailableMarkets(std::vector<Venue> & markets) const;

        /**
         * Method for checking combination on correctness and support on market.
         *
         * @param   status_text                 String with possible error
         *
         * @return  boolean                     true, if combination structure is correct and supported on market and
         *                                      false in otherwise
         */
        bool CanBeCreatedOnMarket(String & status_text) const;

        /**
         * Select market when legs are multi-listed.
         *
         * @param market                        Market definition
         *
         * @return boolean                      true if combination structure is correct and supported on market,
         *                                      false otherwise
         *
         */
        bool SetMarket(const Venue & market, String & status_text);

        /**
         * Returns combination type of structure.
         *
         * @return  type                        Combination type
         */
        bool GetCombinationType(CombinationType & type) const;

        /**
         * Returns combination type of structure with opposite sign of ratios (inverted structure)
         *
         * @return type                        Combination type
         */
        bool GetInvertedCombinationType(CombinationType & type) const;

    public:
        void Clear();
        bool Empty() const;

    public:
        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        friend STRATEGY_EXPORT class Converter;

        friend STRATEGY_EXPORT class CombinationCreator;

        friend STRATEGY_EXPORT class CombinationCreatorStructureImpl;

        static const protocol::Instrument & GetInstrumentMessage(const Instrument & instrument);

    private:
        std::unique_ptr<CombinationCreatorStructureImpl> m_impl;
    };

public:
    /**
     * Send combination create request.
     *
     * @param   structure                   Structure of combination
     * @param   handler                     Request reply handler
     *
     * @return  Identifier                  Request identifier
     */
    static Identifier SendCreateRequest(const Structure & structure, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Returns any of existing combination with specified structure.
     *
     * @param   structure                   Structure of combination
     *
     * @return  Instrument                  Non-empty instrument if combination already exists
     *                                      in the system, and empty instrument in otherwise
     */
    static Instrument GetExistingCombination(const Structure & structure);

    /**
     * Finds existing combinations with specified structure.
     *
     * @param   structure                   Structure of combination
     *
     * @param   instruments                 Vector of already existing combinations in the system,
     *                                      empty if no such combinations exist
     */
    static void GetExistingCombinations(const Structure & structure, std::vector<Instrument> & instruments);

private:
    CombinationCreator();
};

} // namespace tbricks
