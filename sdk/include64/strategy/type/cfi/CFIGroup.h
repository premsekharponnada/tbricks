#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Classification of Financial Instruments.
//****************************************************************************************

namespace tbricks {

enum class CFIGroup
{
    // E - Equity
    COMMON_SHARES = 21317,                        // ES
    PREFERRED_SHARES = 20549,                     // EP
    COMMON_CONVERTIBLE_SHARES = 17221,            // EC
    PREFERRED_CONVERTIBLE_SHARES = 17989,         // EF
    LIMITED_PARTNERSHIP_UNITS = 19525,            // EL
    DEPOSITARY_RECEIPTS_ON_EQUITIES = 17477,      // ED
    STRUCTURED_INSTRUMENTS_PARTICIPATION = 22853, // EY
    OTHERS_EQUITIES = 19781,                      // EM

    // C - Collective investment vehicles
    STANDARD_INVESTMENT_FUNDS = 18755, // CI
    HEDGE_FUNDS = 18499,               // CH
    REIT = 16963,                      // CB
    ETF = 17731,                       // CE
    PENSION_FUNDS = 21315,             // CS
    FUNDS_OF_FUNDS = 17987,            // CF
    PRIVATE_EQUITY_FUNDS = 20547,      // CP
    OTHERS_VEHICLES = 19779,           // CM

    // D - Debt instruments
    BONDS = 16964,                                          // DB
    CONVERTIBLE_BONDS = 17220,                              // DC
    BONDS_WITH_WARRANTS_ATTACHED = 22340,                   // DW
    MEDIUM_TERM_NOTES = 21572,                              // DT
    STRUCTURED_PRODUCTS_WITH_CAPITAL_PROTECTION = 21316,    // DS
    STRUCTURED_PRODUCTS_WITHOUT_CAPITAL_PROTECTION = 17732, // DE
    MORTGAGE_BACKED_SECURITIES = 18244,                     // DG
    ASSET_BACKED_SECURITIES = 16708,                        // DA
    MUNICIPAL_BONDS = 20036,                                // DN
    DEPOSITARY_RECEIPTS_ON_DEBT_INSTRUMENTS = 17476,        // DD
    OTHER_DEBTS = 19780,                                    // DM
    MONEY_MARKET_INSTRUMENTS = 22852,                       // DY

    // R - Entitlements (rights)
    BONUS_RIGHTS = 16722,                        // RA
    SUBSCRIPTION_RIGHTS = 21330,                 // RS
    PURCHASE_RIGHTS = 20562,                     // RP
    WARRANTS = 22354,                            // RW
    MINI_FUTURE_CERTIFICATES = 18002,            // RF
    DEPOSITARY_RECEIPTS_ON_ENTITLEMENTS = 17490, // RD
    OTHER_RIGHTS = 19794,                        // RM

    // O - Listed options
    CALL_OPTIONS = 17231,  // OC
    PUT_OPTIONS = 20559,   // OP
    OTHER_OPTIONS = 19791, // OM

    // F - Futures
    FINANCIAL_FUTURES = 17990,   // FF
    COMMODITIES_FUTURES = 17222, // FC

    // S - Swaps
    RATES_SWAPS = 21075,       // SR
    COMMODITIES_SWAPS = 21587, // ST
    EQUITY_SWAPS = 17747,      // SE
    CREDIT_SWAPS = 17235,      // SC
    FX_SWAPS = 18003,          // SF
    OTHER_SWAPS = 19795,       // SM

    // H - Non-listed and complex listed options
    RATES_OPTIONS = 21064,                       // HR
    COMMODITIES_OPTIONS = 21576,                 // HT
    EQUITY_OPTIONS = 17736,                      // HE
    CREDIT_OPTIONS = 17224,                      // HC
    FX_OPTIONS = 17992,                          // HF
    OTHER_NON_OR_COMPLEX_LISTED_OPTIONS = 19784, // HM

    // I - Spot
    FX_SPOT = 17993,          // IF
    COMMODITIES_SPOT = 21577, // IT

    // J - Forwards
    EQUITY_FORWARDS = 17738,      // JE
    FX_FORWARDS = 17994,          // JF
    CREDIT_FORWARDS = 17226,      // JC
    RATES_FORWARDS = 21066,       // JR
    COMMODITIES_FORWARDS = 21578, // JT

    // K - Strategies
    RATES_STRATEGIES = 21067,        // KR
    COMMODITIES_STRATEGIES = 21579,  // KT
    EQUITY_STRATEGIES = 17739,       // KE
    CREDIT_STRATEGIES = 17227,       // KC
    FX_STRATEGIES = 17995,           // KF
    MIXED_ASSETS_STRATEGIES = 22859, // KY
    OTHER_STRATEGIES = 19787,        // KM

    // L - Financing
    LOAN_LEASE = 19532,            // LL
    REPURCHASE_AGREEMENTS = 21068, // LR
    SECURITIES_LENDING = 21324,    // LS

    // T - Reference instruments
    CURRENCIES_REFERENCE_INSTRUMENTS = 17236,      // TC
    COMMODITIES_REFERENCE_INSTRUMENTS = 21588,     // TT
    INTEREST_RATES_REFERENCE_INSTRUMENTS = 21076,  // TR
    INDICES_REFERENCE_INSTRUMENTS = 18772,         // TI
    BASKETS_REFERENCE_INSTRUMENTS = 16980,         // TB
    STOCK_DIVIDENDS_REFERENCE_INSTRUMENTS = 17492, // TD
    OTHERS_REFERENCE_INSTRUMENTS = 19796,          // TM

    // M - Others (miscellaneous)
    COMBINED_INSTRUMENTS = 17229, // MC
    OTHER_ASSETS = 19789          // MM
};
}
