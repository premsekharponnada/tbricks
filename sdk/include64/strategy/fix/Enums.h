#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.

// This file was automatically generated. DO NOT CHANGE IT
//****************************************************************************************

#include <iostream>
#include "strategy/Linkage.h"
#undef DELETE
#undef GROUP_NAME
#undef STRICT
#undef DIFFERENCE

namespace tbricks { namespace FIX {

namespace Field {
enum ID
{
    BeginSeqNo = 7,
    BeginString = 8,
    BodyLength = 9,
    CheckSum = 10,
    EndSeqNo = 16,
    MsgSeqNum = 34,
    MsgType = 35,
    NewSeqNo = 36,
    PossDupFlag = 43,
    RefSeqNum = 45,
    SenderCompID = 49,
    SenderSubID = 50,
    SendingTime = 52,
    TargetCompID = 56,
    TargetSubID = 57,
    Text = 58,
    Signature = 89,
    SecureDataLen = 90,
    SecureData = 91,
    SignatureLength = 93,
    RawDataLength = 95,
    RawData = 96,
    PossResend = 97,
    EncryptMethod = 98,
    HeartBtInt = 108,
    TestReqID = 112,
    OnBehalfOfCompID = 115,
    OnBehalfOfSubID = 116,
    OrigSendingTime = 122,
    GapFillFlag = 123,
    DeliverToCompID = 128,
    DeliverToSubID = 129,
    ResetSeqNumFlag = 141,
    SenderLocationID = 142,
    TargetLocationID = 143,
    OnBehalfOfLocationID = 144,
    DeliverToLocationID = 145,
    XmlDataLen = 212,
    XmlData = 213,
    MessageEncoding = 347,
    EncodedTextLen = 354,
    EncodedText = 355,
    LastMsgSeqNumProcessed = 369,
    RefTagID = 371,
    RefMsgType = 372,
    SessionRejectReason = 373,
    MaxMessageSize = 383,
    NoMsgTypes = 384,
    MsgDirection = 385,
    TestMessageIndicator = 464,
    Username = 553,
    Password = 554,
    NoHops = 627,
    HopCompID = 628,
    HopSendingTime = 629,
    HopRefID = 630,
    NextExpectedMsgSeqNum = 789,
    ApplVerID = 1128,
    CstmApplVerID = 1129,
    RefApplVerID = 1130,
    RefCstmApplVerID = 1131,
    DefaultApplVerID = 1137,
    Account = 1,
    AdvId = 2,
    AdvRefID = 3,
    AdvSide = 4,
    AdvTransType = 5,
    AvgPx = 6,
    ClOrdID = 11,
    Commission = 12,
    CommType = 13,
    CumQty = 14,
    Currency = 15,
    ExecID = 17,
    ExecInst = 18,
    ExecRefID = 19,
    HandlInst = 21,
    SecurityIDSource = 22,
    IOIID = 23,
    IOIQltyInd = 25,
    IOIRefID = 26,
    IOIQty = 27,
    IOITransType = 28,
    LastCapacity = 29,
    LastMkt = 30,
    LastPx = 31,
    LastQty = 32,
    NoLinesOfText = 33,
    OrderID = 37,
    OrderQty = 38,
    OrdStatus = 39,
    OrdType = 40,
    OrigClOrdID = 41,
    OrigTime = 42,
    Price = 44,
    SecurityID = 48,
    Quantity = 53,
    Side = 54,
    Symbol = 55,
    TimeInForce = 59,
    TransactTime = 60,
    Urgency = 61,
    ValidUntilTime = 62,
    SettlType = 63,
    SettlDate = 64,
    SymbolSfx = 65,
    ListID = 66,
    ListSeqNo = 67,
    TotNoOrders = 68,
    ListExecInst = 69,
    AllocID = 70,
    AllocTransType = 71,
    RefAllocID = 72,
    NoOrders = 73,
    AvgPxPrecision = 74,
    TradeDate = 75,
    ExecBroker = 76,
    PositionEffect = 77,
    NoAllocs = 78,
    AllocAccount = 79,
    AllocQty = 80,
    ProcessCode = 81,
    NoRpts = 82,
    RptSeq = 83,
    CxlQty = 84,
    NoDlvyInst = 85,
    AllocStatus = 87,
    AllocRejCode = 88,
    EmailType = 94,
    StopPx = 99,
    ExDestination = 100,
    CxlRejReason = 102,
    OrdRejReason = 103,
    IOIQualifier = 104,
    Issuer = 106,
    SecurityDesc = 107,
    MinQty = 110,
    MaxFloor = 111,
    ReportToExch = 113,
    LocateReqd = 114,
    QuoteID = 117,
    NetMoney = 118,
    SettlCurrAmt = 119,
    SettlCurrency = 120,
    ForexReq = 121,
    NoExecs = 124,
    ExpireTime = 126,
    DKReason = 127,
    IOINaturalFlag = 130,
    QuoteReqID = 131,
    BidPx = 132,
    OfferPx = 133,
    BidSize = 134,
    OfferSize = 135,
    NoMiscFees = 136,
    MiscFeeAmt = 137,
    MiscFeeCurr = 138,
    MiscFeeType = 139,
    PrevClosePx = 140,
    NoRelatedSym = 146,
    Subject = 147,
    Headline = 148,
    URLLink = 149,
    ExecType = 150,
    LeavesQty = 151,
    CashOrderQty = 152,
    AllocAvgPx = 153,
    AllocNetMoney = 154,
    SettlCurrFxRate = 155,
    SettlCurrFxRateCalc = 156,
    NumDaysInterest = 157,
    AccruedInterestRate = 158,
    AccruedInterestAmt = 159,
    SettlInstMode = 160,
    AllocText = 161,
    SettlInstID = 162,
    SettlInstTransType = 163,
    EmailThreadID = 164,
    SettlInstSource = 165,
    SecurityType = 167,
    EffectiveTime = 168,
    StandInstDbType = 169,
    StandInstDbName = 170,
    StandInstDbID = 171,
    SettlDeliveryType = 172,
    BidSpotRate = 188,
    BidForwardPoints = 189,
    OfferSpotRate = 190,
    OfferForwardPoints = 191,
    OrderQty2 = 192,
    SettlDate2 = 193,
    LastSpotRate = 194,
    LastForwardPoints = 195,
    AllocLinkID = 196,
    AllocLinkType = 197,
    SecondaryOrderID = 198,
    NoIOIQualifiers = 199,
    MaturityMonthYear = 200,
    PutOrCall = 201,
    StrikePrice = 202,
    CoveredOrUncovered = 203,
    OptAttribute = 206,
    SecurityExchange = 207,
    NotifyBrokerOfCredit = 208,
    AllocHandlInst = 209,
    MaxShow = 210,
    PegOffsetValue = 211,
    SettlInstRefID = 214,
    NoRoutingIDs = 215,
    RoutingType = 216,
    RoutingID = 217,
    Spread = 218,
    BenchmarkCurveCurrency = 220,
    BenchmarkCurveName = 221,
    BenchmarkCurvePoint = 222,
    CouponRate = 223,
    CouponPaymentDate = 224,
    IssueDate = 225,
    RepurchaseTerm = 226,
    RepurchaseRate = 227,
    Factor = 228,
    TradeOriginationDate = 229,
    ExDate = 230,
    ContractMultiplier = 231,
    NoStipulations = 232,
    StipulationType = 233,
    StipulationValue = 234,
    YieldType = 235,
    Yield = 236,
    TotalTakedown = 237,
    Concession = 238,
    RepoCollateralSecurityType = 239,
    RedemptionDate = 240,
    UnderlyingCouponPaymentDate = 241,
    UnderlyingIssueDate = 242,
    UnderlyingRepoCollateralSecurityType = 243,
    UnderlyingRepurchaseTerm = 244,
    UnderlyingRepurchaseRate = 245,
    UnderlyingFactor = 246,
    UnderlyingRedemptionDate = 247,
    LegCouponPaymentDate = 248,
    LegIssueDate = 249,
    LegRepoCollateralSecurityType = 250,
    LegRepurchaseTerm = 251,
    LegRepurchaseRate = 252,
    LegFactor = 253,
    LegRedemptionDate = 254,
    CreditRating = 255,
    UnderlyingCreditRating = 256,
    LegCreditRating = 257,
    TradedFlatSwitch = 258,
    BasisFeatureDate = 259,
    BasisFeaturePrice = 260,
    MDReqID = 262,
    SubscriptionRequestType = 263,
    MarketDepth = 264,
    MDUpdateType = 265,
    AggregatedBook = 266,
    NoMDEntryTypes = 267,
    NoMDEntries = 268,
    MDEntryType = 269,
    MDEntryPx = 270,
    MDEntrySize = 271,
    MDEntryDate = 272,
    MDEntryTime = 273,
    TickDirection = 274,
    MDMkt = 275,
    QuoteCondition = 276,
    TradeCondition = 277,
    MDEntryID = 278,
    MDUpdateAction = 279,
    MDEntryRefID = 280,
    MDReqRejReason = 281,
    MDEntryOriginator = 282,
    LocationID = 283,
    DeskID = 284,
    DeleteReason = 285,
    OpenCloseSettlFlag = 286,
    SellerDays = 287,
    MDEntryBuyer = 288,
    MDEntrySeller = 289,
    MDEntryPositionNo = 290,
    FinancialStatus = 291,
    CorporateAction = 292,
    DefBidSize = 293,
    DefOfferSize = 294,
    NoQuoteEntries = 295,
    NoQuoteSets = 296,
    QuoteStatus = 297,
    QuoteCancelType = 298,
    QuoteEntryID = 299,
    QuoteRejectReason = 300,
    QuoteResponseLevel = 301,
    QuoteSetID = 302,
    QuoteRequestType = 303,
    TotNoQuoteEntries = 304,
    UnderlyingSecurityIDSource = 305,
    UnderlyingIssuer = 306,
    UnderlyingSecurityDesc = 307,
    UnderlyingSecurityExchange = 308,
    UnderlyingSecurityID = 309,
    UnderlyingSecurityType = 310,
    UnderlyingSymbol = 311,
    UnderlyingSymbolSfx = 312,
    UnderlyingMaturityMonthYear = 313,
    UnderlyingPutOrCall = 315,
    UnderlyingStrikePrice = 316,
    UnderlyingOptAttribute = 317,
    UnderlyingCurrency = 318,
    SecurityReqID = 320,
    SecurityRequestType = 321,
    SecurityResponseID = 322,
    SecurityResponseType = 323,
    SecurityStatusReqID = 324,
    UnsolicitedIndicator = 325,
    SecurityTradingStatus = 326,
    HaltReasonInt = 327,
    InViewOfCommon = 328,
    DueToRelated = 329,
    BuyVolume = 330,
    SellVolume = 331,
    HighPx = 332,
    LowPx = 333,
    Adjustment = 334,
    TradSesReqID = 335,
    TradingSessionID = 336,
    ContraTrader = 337,
    TradSesMethod = 338,
    TradSesMode = 339,
    TradSesStatus = 340,
    TradSesStartTime = 341,
    TradSesOpenTime = 342,
    TradSesPreCloseTime = 343,
    TradSesCloseTime = 344,
    TradSesEndTime = 345,
    NumberOfOrders = 346,
    EncodedIssuerLen = 348,
    EncodedIssuer = 349,
    EncodedSecurityDescLen = 350,
    EncodedSecurityDesc = 351,
    EncodedListExecInstLen = 352,
    EncodedListExecInst = 353,
    EncodedSubjectLen = 356,
    EncodedSubject = 357,
    EncodedHeadlineLen = 358,
    EncodedHeadline = 359,
    EncodedAllocTextLen = 360,
    EncodedAllocText = 361,
    EncodedUnderlyingIssuerLen = 362,
    EncodedUnderlyingIssuer = 363,
    EncodedUnderlyingSecurityDescLen = 364,
    EncodedUnderlyingSecurityDesc = 365,
    AllocPrice = 366,
    QuoteSetValidUntilTime = 367,
    QuoteEntryRejectReason = 368,
    BidRequestTransType = 374,
    ContraBroker = 375,
    ComplianceID = 376,
    SolicitedFlag = 377,
    ExecRestatementReason = 378,
    BusinessRejectRefID = 379,
    BusinessRejectReason = 380,
    GrossTradeAmt = 381,
    NoContraBrokers = 382,
    NoTradingSessions = 386,
    TotalVolumeTraded = 387,
    DiscretionInst = 388,
    DiscretionOffsetValue = 389,
    BidID = 390,
    ClientBidID = 391,
    ListName = 392,
    TotNoRelatedSym = 393,
    BidType = 394,
    NumTickets = 395,
    SideValue1 = 396,
    SideValue2 = 397,
    NoBidDescriptors = 398,
    BidDescriptorType = 399,
    BidDescriptor = 400,
    SideValueInd = 401,
    LiquidityPctLow = 402,
    LiquidityPctHigh = 403,
    LiquidityValue = 404,
    EFPTrackingError = 405,
    FairValue = 406,
    OutsideIndexPct = 407,
    ValueOfFutures = 408,
    LiquidityIndType = 409,
    WtAverageLiquidity = 410,
    ExchangeForPhysical = 411,
    OutMainCntryUIndex = 412,
    CrossPercent = 413,
    ProgRptReqs = 414,
    ProgPeriodInterval = 415,
    IncTaxInd = 416,
    NumBidders = 417,
    BidTradeType = 418,
    BasisPxType = 419,
    NoBidComponents = 420,
    Country = 421,
    TotNoStrikes = 422,
    PriceType = 423,
    DayOrderQty = 424,
    DayCumQty = 425,
    DayAvgPx = 426,
    GTBookingInst = 427,
    NoStrikes = 428,
    ListStatusType = 429,
    NetGrossInd = 430,
    ListOrderStatus = 431,
    ExpireDate = 432,
    ListExecInstType = 433,
    CxlRejResponseTo = 434,
    UnderlyingCouponRate = 435,
    UnderlyingContractMultiplier = 436,
    ContraTradeQty = 437,
    ContraTradeTime = 438,
    LiquidityNumSecurities = 441,
    MultiLegReportingType = 442,
    StrikeTime = 443,
    ListStatusText = 444,
    EncodedListStatusTextLen = 445,
    EncodedListStatusText = 446,
    PartyIDSource = 447,
    PartyID = 448,
    NetChgPrevDay = 451,
    PartyRole = 452,
    NoPartyIDs = 453,
    NoSecurityAltID = 454,
    SecurityAltID = 455,
    SecurityAltIDSource = 456,
    NoUnderlyingSecurityAltID = 457,
    UnderlyingSecurityAltID = 458,
    UnderlyingSecurityAltIDSource = 459,
    Product = 460,
    CFICode = 461,
    UnderlyingProduct = 462,
    UnderlyingCFICode = 463,
    BookingRefID = 466,
    IndividualAllocID = 467,
    RoundingDirection = 468,
    RoundingModulus = 469,
    CountryOfIssue = 470,
    StateOrProvinceOfIssue = 471,
    LocaleOfIssue = 472,
    NoRegistDtls = 473,
    MailingDtls = 474,
    InvestorCountryOfResidence = 475,
    PaymentRef = 476,
    DistribPaymentMethod = 477,
    CashDistribCurr = 478,
    CommCurrency = 479,
    CancellationRights = 480,
    MoneyLaunderingStatus = 481,
    MailingInst = 482,
    TransBkdTime = 483,
    ExecPriceType = 484,
    ExecPriceAdjustment = 485,
    DateOfBirth = 486,
    TradeReportTransType = 487,
    CardHolderName = 488,
    CardNumber = 489,
    CardExpDate = 490,
    CardIssNum = 491,
    PaymentMethod = 492,
    RegistAcctType = 493,
    Designation = 494,
    TaxAdvantageType = 495,
    RegistRejReasonText = 496,
    FundRenewWaiv = 497,
    CashDistribAgentName = 498,
    CashDistribAgentCode = 499,
    CashDistribAgentAcctNumber = 500,
    CashDistribPayRef = 501,
    CashDistribAgentAcctName = 502,
    CardStartDate = 503,
    PaymentDate = 504,
    PaymentRemitterID = 505,
    RegistStatus = 506,
    RegistRejReasonCode = 507,
    RegistRefID = 508,
    RegistDtls = 509,
    NoDistribInsts = 510,
    RegistEmail = 511,
    DistribPercentage = 512,
    RegistID = 513,
    RegistTransType = 514,
    ExecValuationPoint = 515,
    OrderPercent = 516,
    OwnershipType = 517,
    NoContAmts = 518,
    ContAmtType = 519,
    ContAmtValue = 520,
    ContAmtCurr = 521,
    OwnerType = 522,
    PartySubID = 523,
    NestedPartyID = 524,
    NestedPartyIDSource = 525,
    SecondaryClOrdID = 526,
    SecondaryExecID = 527,
    OrderCapacity = 528,
    OrderRestrictions = 529,
    MassCancelRequestType = 530,
    MassCancelResponse = 531,
    MassCancelRejectReason = 532,
    TotalAffectedOrders = 533,
    NoAffectedOrders = 534,
    AffectedOrderID = 535,
    AffectedSecondaryOrderID = 536,
    QuoteType = 537,
    NestedPartyRole = 538,
    NoNestedPartyIDs = 539,
    TotalAccruedInterestAmt = 540,
    MaturityDate = 541,
    UnderlyingMaturityDate = 542,
    InstrRegistry = 543,
    CashMargin = 544,
    NestedPartySubID = 545,
    Scope = 546,
    MDImplicitDelete = 547,
    CrossID = 548,
    CrossType = 549,
    CrossPrioritization = 550,
    OrigCrossID = 551,
    NoSides = 552,
    NoLegs = 555,
    LegCurrency = 556,
    TotNoSecurityTypes = 557,
    NoSecurityTypes = 558,
    SecurityListRequestType = 559,
    SecurityRequestResult = 560,
    RoundLot = 561,
    MinTradeVol = 562,
    MultiLegRptTypeReq = 563,
    LegPositionEffect = 564,
    LegCoveredOrUncovered = 565,
    LegPrice = 566,
    TradSesStatusRejReason = 567,
    TradeRequestID = 568,
    TradeRequestType = 569,
    PreviouslyReported = 570,
    TradeReportID = 571,
    TradeReportRefID = 572,
    MatchStatus = 573,
    MatchType = 574,
    OddLot = 575,
    NoClearingInstructions = 576,
    ClearingInstruction = 577,
    TradeInputSource = 578,
    TradeInputDevice = 579,
    NoDates = 580,
    AccountType = 581,
    CustOrderCapacity = 582,
    ClOrdLinkID = 583,
    MassStatusReqID = 584,
    MassStatusReqType = 585,
    OrigOrdModTime = 586,
    LegSettlType = 587,
    LegSettlDate = 588,
    DayBookingInst = 589,
    BookingUnit = 590,
    PreallocMethod = 591,
    UnderlyingCountryOfIssue = 592,
    UnderlyingStateOrProvinceOfIssue = 593,
    UnderlyingLocaleOfIssue = 594,
    UnderlyingInstrRegistry = 595,
    LegCountryOfIssue = 596,
    LegStateOrProvinceOfIssue = 597,
    LegLocaleOfIssue = 598,
    LegInstrRegistry = 599,
    LegSymbol = 600,
    LegSymbolSfx = 601,
    LegSecurityID = 602,
    LegSecurityIDSource = 603,
    NoLegSecurityAltID = 604,
    LegSecurityAltID = 605,
    LegSecurityAltIDSource = 606,
    LegProduct = 607,
    LegCFICode = 608,
    LegSecurityType = 609,
    LegMaturityMonthYear = 610,
    LegMaturityDate = 611,
    LegStrikePrice = 612,
    LegOptAttribute = 613,
    LegContractMultiplier = 614,
    LegCouponRate = 615,
    LegSecurityExchange = 616,
    LegIssuer = 617,
    EncodedLegIssuerLen = 618,
    EncodedLegIssuer = 619,
    LegSecurityDesc = 620,
    EncodedLegSecurityDescLen = 621,
    EncodedLegSecurityDesc = 622,
    LegRatioQty = 623,
    LegSide = 624,
    TradingSessionSubID = 625,
    AllocType = 626,
    MidPx = 631,
    BidYield = 632,
    MidYield = 633,
    OfferYield = 634,
    ClearingFeeIndicator = 635,
    WorkingIndicator = 636,
    LegLastPx = 637,
    PriorityIndicator = 638,
    PriceImprovement = 639,
    Price2 = 640,
    LastForwardPoints2 = 641,
    BidForwardPoints2 = 642,
    OfferForwardPoints2 = 643,
    RFQReqID = 644,
    MktBidPx = 645,
    MktOfferPx = 646,
    MinBidSize = 647,
    MinOfferSize = 648,
    QuoteStatusReqID = 649,
    LegalConfirm = 650,
    UnderlyingLastPx = 651,
    UnderlyingLastQty = 652,
    LegRefID = 654,
    ContraLegRefID = 655,
    SettlCurrBidFxRate = 656,
    SettlCurrOfferFxRate = 657,
    QuoteRequestRejectReason = 658,
    SideComplianceID = 659,
    AcctIDSource = 660,
    AllocAcctIDSource = 661,
    BenchmarkPrice = 662,
    BenchmarkPriceType = 663,
    ConfirmID = 664,
    ConfirmStatus = 665,
    ConfirmTransType = 666,
    ContractSettlMonth = 667,
    DeliveryForm = 668,
    LastParPx = 669,
    NoLegAllocs = 670,
    LegAllocAccount = 671,
    LegIndividualAllocID = 672,
    LegAllocQty = 673,
    LegAllocAcctIDSource = 674,
    LegSettlCurrency = 675,
    LegBenchmarkCurveCurrency = 676,
    LegBenchmarkCurveName = 677,
    LegBenchmarkCurvePoint = 678,
    LegBenchmarkPrice = 679,
    LegBenchmarkPriceType = 680,
    LegBidPx = 681,
    LegIOIQty = 682,
    NoLegStipulations = 683,
    LegOfferPx = 684,
    LegOrderQty = 685,
    LegPriceType = 686,
    LegQty = 687,
    LegStipulationType = 688,
    LegStipulationValue = 689,
    LegSwapType = 690,
    Pool = 691,
    QuotePriceType = 692,
    QuoteRespID = 693,
    QuoteRespType = 694,
    QuoteQualifier = 695,
    YieldRedemptionDate = 696,
    YieldRedemptionPrice = 697,
    YieldRedemptionPriceType = 698,
    BenchmarkSecurityID = 699,
    ReversalIndicator = 700,
    YieldCalcDate = 701,
    NoPositions = 702,
    PosType = 703,
    LongQty = 704,
    ShortQty = 705,
    PosQtyStatus = 706,
    PosAmtType = 707,
    PosAmt = 708,
    PosTransType = 709,
    PosReqID = 710,
    NoUnderlyings = 711,
    PosMaintAction = 712,
    OrigPosReqRefID = 713,
    PosMaintRptRefID = 714,
    ClearingBusinessDate = 715,
    SettlSessID = 716,
    SettlSessSubID = 717,
    AdjustmentType = 718,
    ContraryInstructionIndicator = 719,
    PriorSpreadIndicator = 720,
    PosMaintRptID = 721,
    PosMaintStatus = 722,
    PosMaintResult = 723,
    PosReqType = 724,
    ResponseTransportType = 725,
    ResponseDestination = 726,
    TotalNumPosReports = 727,
    PosReqResult = 728,
    PosReqStatus = 729,
    SettlPrice = 730,
    SettlPriceType = 731,
    UnderlyingSettlPrice = 732,
    UnderlyingSettlPriceType = 733,
    PriorSettlPrice = 734,
    NoQuoteQualifiers = 735,
    AllocSettlCurrency = 736,
    AllocSettlCurrAmt = 737,
    InterestAtMaturity = 738,
    LegDatedDate = 739,
    LegPool = 740,
    AllocInterestAtMaturity = 741,
    AllocAccruedInterestAmt = 742,
    DeliveryDate = 743,
    AssignmentMethod = 744,
    AssignmentUnit = 745,
    OpenInterest = 746,
    ExerciseMethod = 747,
    TotNumTradeReports = 748,
    TradeRequestResult = 749,
    TradeRequestStatus = 750,
    TradeReportRejectReason = 751,
    SideMultiLegReportingType = 752,
    NoPosAmt = 753,
    AutoAcceptIndicator = 754,
    AllocReportID = 755,
    NoNested2PartyIDs = 756,
    Nested2PartyID = 757,
    Nested2PartyIDSource = 758,
    Nested2PartyRole = 759,
    Nested2PartySubID = 760,
    BenchmarkSecurityIDSource = 761,
    SecuritySubType = 762,
    UnderlyingSecuritySubType = 763,
    LegSecuritySubType = 764,
    AllowableOneSidednessPct = 765,
    AllowableOneSidednessValue = 766,
    AllowableOneSidednessCurr = 767,
    NoTrdRegTimestamps = 768,
    TrdRegTimestamp = 769,
    TrdRegTimestampType = 770,
    TrdRegTimestampOrigin = 771,
    ConfirmRefID = 772,
    ConfirmType = 773,
    ConfirmRejReason = 774,
    BookingType = 775,
    IndividualAllocRejCode = 776,
    SettlInstMsgID = 777,
    NoSettlInst = 778,
    LastUpdateTime = 779,
    AllocSettlInstType = 780,
    NoSettlPartyIDs = 781,
    SettlPartyID = 782,
    SettlPartyIDSource = 783,
    SettlPartyRole = 784,
    SettlPartySubID = 785,
    SettlPartySubIDType = 786,
    DlvyInstType = 787,
    TerminationType = 788,
    OrdStatusReqID = 790,
    SettlInstReqID = 791,
    SettlInstReqRejCode = 792,
    SecondaryAllocID = 793,
    AllocReportType = 794,
    AllocReportRefID = 795,
    AllocCancReplaceReason = 796,
    CopyMsgIndicator = 797,
    AllocAccountType = 798,
    OrderAvgPx = 799,
    OrderBookingQty = 800,
    NoSettlPartySubIDs = 801,
    NoPartySubIDs = 802,
    PartySubIDType = 803,
    NoNestedPartySubIDs = 804,
    NestedPartySubIDType = 805,
    NoNested2PartySubIDs = 806,
    Nested2PartySubIDType = 807,
    AllocIntermedReqType = 808,
    UnderlyingPx = 810,
    PriceDelta = 811,
    ApplQueueMax = 812,
    ApplQueueDepth = 813,
    ApplQueueResolution = 814,
    ApplQueueAction = 815,
    NoAltMDSource = 816,
    AltMDSourceID = 817,
    SecondaryTradeReportID = 818,
    AvgPxIndicator = 819,
    TradeLinkID = 820,
    OrderInputDevice = 821,
    UnderlyingTradingSessionID = 822,
    UnderlyingTradingSessionSubID = 823,
    TradeLegRefID = 824,
    ExchangeRule = 825,
    TradeAllocIndicator = 826,
    ExpirationCycle = 827,
    TrdType = 828,
    TrdSubType = 829,
    TransferReason = 830,
    TotNumAssignmentReports = 832,
    AsgnRptID = 833,
    ThresholdAmount = 834,
    PegMoveType = 835,
    PegOffsetType = 836,
    PegLimitType = 837,
    PegRoundDirection = 838,
    PeggedPrice = 839,
    PegScope = 840,
    DiscretionMoveType = 841,
    DiscretionOffsetType = 842,
    DiscretionLimitType = 843,
    DiscretionRoundDirection = 844,
    DiscretionPrice = 845,
    DiscretionScope = 846,
    TargetStrategy = 847,
    TargetStrategyParameters = 848,
    ParticipationRate = 849,
    TargetStrategyPerformance = 850,
    LastLiquidityInd = 851,
    PublishTrdIndicator = 852,
    ShortSaleReason = 853,
    QtyType = 854,
    SecondaryTrdType = 855,
    TradeReportType = 856,
    AllocNoOrdersType = 857,
    SharedCommission = 858,
    ConfirmReqID = 859,
    AvgParPx = 860,
    ReportedPx = 861,
    NoCapacities = 862,
    OrderCapacityQty = 863,
    NoEvents = 864,
    EventType = 865,
    EventDate = 866,
    EventPx = 867,
    EventText = 868,
    PctAtRisk = 869,
    NoInstrAttrib = 870,
    InstrAttribType = 871,
    InstrAttribValue = 872,
    DatedDate = 873,
    InterestAccrualDate = 874,
    CPProgram = 875,
    CPRegType = 876,
    UnderlyingCPProgram = 877,
    UnderlyingCPRegType = 878,
    UnderlyingQty = 879,
    TrdMatchID = 880,
    SecondaryTradeReportRefID = 881,
    UnderlyingDirtyPrice = 882,
    UnderlyingEndPrice = 883,
    UnderlyingStartValue = 884,
    UnderlyingCurrentValue = 885,
    UnderlyingEndValue = 886,
    NoUnderlyingStips = 887,
    UnderlyingStipType = 888,
    UnderlyingStipValue = 889,
    MaturityNetMoney = 890,
    MiscFeeBasis = 891,
    TotNoAllocs = 892,
    LastFragment = 893,
    CollReqID = 894,
    CollAsgnReason = 895,
    CollInquiryQualifier = 896,
    NoTrades = 897,
    MarginRatio = 898,
    MarginExcess = 899,
    TotalNetValue = 900,
    CashOutstanding = 901,
    CollAsgnID = 902,
    CollAsgnTransType = 903,
    CollRespID = 904,
    CollAsgnRespType = 905,
    CollAsgnRejectReason = 906,
    CollAsgnRefID = 907,
    CollRptID = 908,
    CollInquiryID = 909,
    CollStatus = 910,
    TotNumReports = 911,
    LastRptRequested = 912,
    AgreementDesc = 913,
    AgreementID = 914,
    AgreementDate = 915,
    StartDate = 916,
    EndDate = 917,
    AgreementCurrency = 918,
    DeliveryType = 919,
    EndAccruedInterestAmt = 920,
    StartCash = 921,
    EndCash = 922,
    UserRequestID = 923,
    UserRequestType = 924,
    NewPassword = 925,
    UserStatus = 926,
    UserStatusText = 927,
    StatusValue = 928,
    StatusText = 929,
    RefCompID = 930,
    RefSubID = 931,
    NetworkResponseID = 932,
    NetworkRequestID = 933,
    LastNetworkResponseID = 934,
    NetworkRequestType = 935,
    NoCompIDs = 936,
    NetworkStatusResponseType = 937,
    NoCollInquiryQualifier = 938,
    TrdRptStatus = 939,
    AffirmStatus = 940,
    UnderlyingStrikeCurrency = 941,
    LegStrikeCurrency = 942,
    TimeBracket = 943,
    CollAction = 944,
    CollInquiryStatus = 945,
    CollInquiryResult = 946,
    StrikeCurrency = 947,
    NoNested3PartyIDs = 948,
    Nested3PartyID = 949,
    Nested3PartyIDSource = 950,
    Nested3PartyRole = 951,
    NoNested3PartySubIDs = 952,
    Nested3PartySubID = 953,
    Nested3PartySubIDType = 954,
    LegContractSettlMonth = 955,
    LegInterestAccrualDate = 956,
    NoStrategyParameters = 957,
    StrategyParameterName = 958,
    StrategyParameterType = 959,
    StrategyParameterValue = 960,
    HostCrossID = 961,
    SideTimeInForce = 962,
    MDReportID = 963,
    SecurityReportID = 964,
    SecurityStatus = 965,
    SettleOnOpenFlag = 966,
    StrikeMultiplier = 967,
    StrikeValue = 968,
    MinPriceIncrement = 969,
    PositionLimit = 970,
    NTPositionLimit = 971,
    UnderlyingAllocationPercent = 972,
    UnderlyingCashAmount = 973,
    UnderlyingCashType = 974,
    UnderlyingSettlementType = 975,
    QuantityDate = 976,
    ContIntRptID = 977,
    LateIndicator = 978,
    InputSource = 979,
    SecurityUpdateAction = 980,
    NoExpiration = 981,
    ExpirationQtyType = 982,
    ExpQty = 983,
    NoUnderlyingAmounts = 984,
    UnderlyingPayAmount = 985,
    UnderlyingCollectAmount = 986,
    UnderlyingSettlementDate = 987,
    UnderlyingSettlementStatus = 988,
    SecondaryIndividualAllocID = 989,
    LegReportID = 990,
    RndPx = 991,
    IndividualAllocType = 992,
    AllocCustomerCapacity = 993,
    TierCode = 994,
    UnitOfMeasure = 996,
    TimeUnit = 997,
    UnderlyingUnitOfMeasure = 998,
    LegUnitOfMeasure = 999,
    UnderlyingTimeUnit = 1000,
    LegTimeUnit = 1001,
    AllocMethod = 1002,
    TradeID = 1003,
    SideTradeReportID = 1005,
    SideFillStationCd = 1006,
    SideReasonCd = 1007,
    SideTrdSubTyp = 1008,
    SideLastQty = 1009,
    MessageEventSource = 1011,
    SideTrdRegTimestamp = 1012,
    SideTrdRegTimestampType = 1013,
    SideTrdRegTimestampSrc = 1014,
    AsOfIndicator = 1015,
    NoSideTrdRegTS = 1016,
    LegOptionRatio = 1017,
    NoInstrumentParties = 1018,
    InstrumentPartyID = 1019,
    TradeVolume = 1020,
    MDBookType = 1021,
    MDFeedType = 1022,
    MDPriceLevel = 1023,
    MDOriginType = 1024,
    FirstPx = 1025,
    MDEntrySpotRate = 1026,
    MDEntryForwardPoints = 1027,
    ManualOrderIndicator = 1028,
    CustDirectedOrder = 1029,
    ReceivedDeptID = 1030,
    CustOrderHandlingInst = 1031,
    OrderHandlingInstSource = 1032,
    DeskType = 1033,
    DeskTypeSource = 1034,
    DeskOrderHandlingInst = 1035,
    ExecAckStatus = 1036,
    UnderlyingDeliveryAmount = 1037,
    UnderlyingCapValue = 1038,
    UnderlyingSettlMethod = 1039,
    SecondaryTradeID = 1040,
    FirmTradeID = 1041,
    SecondaryFirmTradeID = 1042,
    CollApplType = 1043,
    UnderlyingAdjustedQuantity = 1044,
    UnderlyingFXRate = 1045,
    UnderlyingFXRateCalc = 1046,
    AllocPositionEffect = 1047,
    DealingCapacity = 1048,
    InstrmtAssignmentMethod = 1049,
    InstrumentPartyIDSource = 1050,
    InstrumentPartyRole = 1051,
    NoInstrumentPartySubIDs = 1052,
    InstrumentPartySubID = 1053,
    InstrumentPartySubIDType = 1054,
    PositionCurrency = 1055,
    CalculatedCcyLastQty = 1056,
    AggressorIndicator = 1057,
    NoUndlyInstrumentParties = 1058,
    UnderlyingInstrumentPartyID = 1059,
    UnderlyingInstrumentPartyIDSource = 1060,
    UnderlyingInstrumentPartyRole = 1061,
    NoUndlyInstrumentPartySubIDs = 1062,
    UnderlyingInstrumentPartySubID = 1063,
    UnderlyingInstrumentPartySubIDType = 1064,
    BidSwapPoints = 1065,
    OfferSwapPoints = 1066,
    LegBidForwardPoints = 1067,
    LegOfferForwardPoints = 1068,
    SwapPoints = 1069,
    MDQuoteType = 1070,
    LastSwapPoints = 1071,
    SideGrossTradeAmt = 1072,
    LegLastForwardPoints = 1073,
    LegCalculatedCcyLastQty = 1074,
    LegGrossTradeAmt = 1075,
    MaturityTime = 1079,
    RefOrderID = 1080,
    RefOrderIDSource = 1081,
    SecondaryDisplayQty = 1082,
    DisplayWhen = 1083,
    DisplayMethod = 1084,
    DisplayLowQty = 1085,
    DisplayHighQty = 1086,
    DisplayMinIncr = 1087,
    RefreshQty = 1088,
    MatchIncrement = 1089,
    MaxPriceLevels = 1090,
    PreTradeAnonymity = 1091,
    PriceProtectionScope = 1092,
    LotType = 1093,
    PegPriceType = 1094,
    PeggedRefPrice = 1095,
    PegSecurityIDSource = 1096,
    PegSecurityID = 1097,
    PegSymbol = 1098,
    PegSecurityDesc = 1099,
    TriggerType = 1100,
    TriggerAction = 1101,
    TriggerPrice = 1102,
    TriggerSymbol = 1103,
    TriggerSecurityID = 1104,
    TriggerSecurityIDSource = 1105,
    TriggerSecurityDesc = 1106,
    TriggerPriceType = 1107,
    TriggerPriceTypeScope = 1108,
    TriggerPriceDirection = 1109,
    TriggerNewPrice = 1110,
    TriggerOrderType = 1111,
    TriggerNewQty = 1112,
    TriggerTradingSessionID = 1113,
    TriggerTradingSessionSubID = 1114,
    OrderCategory = 1115,
    NoRootPartyIDs = 1116,
    RootPartyID = 1117,
    RootPartyIDSource = 1118,
    RootPartyRole = 1119,
    NoRootPartySubIDs = 1120,
    RootPartySubID = 1121,
    RootPartySubIDType = 1122,
    TradeHandlingInstr = 1123,
    OrigTradeHandlingInstr = 1124,
    OrigTradeDate = 1125,
    OrigTradeID = 1126,
    OrigSecondaryTradeID = 1127,
    TZTransactTime = 1132,
    ExDestinationIDSource = 1133,
    ReportedPxDiff = 1134,
    RptSys = 1135,
    AllocClearingFeeIndicator = 1136,
    DisplayQty = 1138,
    ExchangeSpecialInstructions = 1139,
    MaxTradeVol = 1140,
    NoMDFeedTypes = 1141,
    MatchAlgorithm = 1142,
    MaxPriceVariation = 1143,
    ImpliedMarketIndicator = 1144,
    EventTime = 1145,
    MinPriceIncrementAmount = 1146,
    UnitOfMeasureQty = 1147,
    LowLimitPrice = 1148,
    HighLimitPrice = 1149,
    TradingReferencePrice = 1150,
    SecurityGroup = 1151,
    LegNumber = 1152,
    SettlementCycleNo = 1153,
    SideCurrency = 1154,
    SideSettlCurrency = 1155,
    ApplExtID = 1156,
    CcyAmt = 1157,
    NoSettlDetails = 1158,
    SettlObligMode = 1159,
    SettlObligMsgID = 1160,
    SettlObligID = 1161,
    SettlObligTransType = 1162,
    SettlObligRefID = 1163,
    SettlObligSource = 1164,
    NoSettlOblig = 1165,
    QuoteMsgID = 1166,
    QuoteEntryStatus = 1167,
    TotNoCxldQuotes = 1168,
    TotNoAccQuotes = 1169,
    TotNoRejQuotes = 1170,
    PrivateQuote = 1171,
    RespondentType = 1172,
    MDSubBookType = 1173,
    SecurityTradingEvent = 1174,
    NoStatsIndicators = 1175,
    StatsType = 1176,
    NoOfSecSizes = 1177,
    MDSecSizeType = 1178,
    MDSecSize = 1179,
    ApplID = 1180,
    ApplSeqNum = 1181,
    ApplBegSeqNum = 1182,
    ApplEndSeqNum = 1183,
    SecurityXMLLen = 1184,
    SecurityXML = 1185,
    SecurityXMLSchema = 1186,
    RefreshIndicator = 1187,
    Volatility = 1188,
    TimeToExpiration = 1189,
    RiskFreeRate = 1190,
    PriceUnitOfMeasure = 1191,
    PriceUnitOfMeasureQty = 1192,
    SettlMethod = 1193,
    ExerciseStyle = 1194,
    OptPayoutAmount = 1195,
    PriceQuoteMethod = 1196,
    ValuationMethod = 1197,
    ListMethod = 1198,
    CapPrice = 1199,
    FloorPrice = 1200,
    NoStrikeRules = 1201,
    StartStrikePxRange = 1202,
    EndStrikePxRange = 1203,
    StrikeIncrement = 1204,
    NoTickRules = 1205,
    StartTickPriceRange = 1206,
    EndTickPriceRange = 1207,
    TickIncrement = 1208,
    TickRuleType = 1209,
    NestedInstrAttribType = 1210,
    NestedInstrAttribValue = 1211,
    LegMaturityTime = 1212,
    UnderlyingMaturityTime = 1213,
    DerivativeSymbol = 1214,
    DerivativeSymbolSfx = 1215,
    DerivativeSecurityID = 1216,
    DerivativeSecurityIDSource = 1217,
    NoDerivativeSecurityAltID = 1218,
    DerivativeSecurityAltID = 1219,
    DerivativeSecurityAltIDSource = 1220,
    SecondaryLowLimitPrice = 1221,
    MaturityRuleID = 1222,
    StrikeRuleID = 1223,
    LegUnitOfMeasureQty = 1224,
    DerivativeOptPayAmount = 1225,
    EndMaturityMonthYear = 1226,
    ProductComplex = 1227,
    DerivativeProductComplex = 1228,
    MaturityMonthYearIncrement = 1229,
    SecondaryHighLimitPrice = 1230,
    MinLotSize = 1231,
    NoExecInstRules = 1232,
    NoLotTypeRules = 1234,
    NoMatchRules = 1235,
    NoMaturityRules = 1236,
    NoOrdTypeRules = 1237,
    NoTimeInForceRules = 1239,
    SecondaryTradingReferencePrice = 1240,
    StartMaturityMonthYear = 1241,
    FlexProductEligibilityIndicator = 1242,
    DerivFlexProductEligibilityIndicator = 1243,
    FlexibleIndicator = 1244,
    TradingCurrency = 1245,
    DerivativeProduct = 1246,
    DerivativeSecurityGroup = 1247,
    DerivativeCFICode = 1248,
    DerivativeSecurityType = 1249,
    DerivativeSecuritySubType = 1250,
    DerivativeMaturityMonthYear = 1251,
    DerivativeMaturityDate = 1252,
    DerivativeMaturityTime = 1253,
    DerivativeSettleOnOpenFlag = 1254,
    DerivativeInstrmtAssignmentMethod = 1255,
    DerivativeSecurityStatus = 1256,
    DerivativeInstrRegistry = 1257,
    DerivativeCountryOfIssue = 1258,
    DerivativeStateOrProvinceOfIssue = 1259,
    DerivativeLocaleOfIssue = 1260,
    DerivativeStrikePrice = 1261,
    DerivativeStrikeCurrency = 1262,
    DerivativeStrikeMultiplier = 1263,
    DerivativeStrikeValue = 1264,
    DerivativeOptAttribute = 1265,
    DerivativeContractMultiplier = 1266,
    DerivativeMinPriceIncrement = 1267,
    DerivativeMinPriceIncrementAmount = 1268,
    DerivativeUnitOfMeasure = 1269,
    DerivativeUnitOfMeasureQty = 1270,
    DerivativeTimeUnit = 1271,
    DerivativeSecurityExchange = 1272,
    DerivativePositionLimit = 1273,
    DerivativeNTPositionLimit = 1274,
    DerivativeIssuer = 1275,
    DerivativeIssueDate = 1276,
    DerivativeEncodedIssuerLen = 1277,
    DerivativeEncodedIssuer = 1278,
    DerivativeSecurityDesc = 1279,
    DerivativeEncodedSecurityDescLen = 1280,
    DerivativeEncodedSecurityDesc = 1281,
    DerivativeSecurityXMLLen = 1282,
    DerivativeSecurityXML = 1283,
    DerivativeSecurityXMLSchema = 1284,
    DerivativeContractSettlMonth = 1285,
    NoDerivativeEvents = 1286,
    DerivativeEventType = 1287,
    DerivativeEventDate = 1288,
    DerivativeEventTime = 1289,
    DerivativeEventPx = 1290,
    DerivativeEventText = 1291,
    NoDerivativeInstrumentParties = 1292,
    DerivativeInstrumentPartyID = 1293,
    DerivativeInstrumentPartyIDSource = 1294,
    DerivativeInstrumentPartyRole = 1295,
    NoDerivativeInstrumentPartySubIDs = 1296,
    DerivativeInstrumentPartySubID = 1297,
    DerivativeInstrumentPartySubIDType = 1298,
    DerivativeExerciseStyle = 1299,
    MarketSegmentID = 1300,
    MarketID = 1301,
    MaturityMonthYearIncrementUnits = 1302,
    MaturityMonthYearFormat = 1303,
    StrikeExerciseStyle = 1304,
    SecondaryPriceLimitType = 1305,
    PriceLimitType = 1306,
    ExecInstValue = 1308,
    NoTradingSessionRules = 1309,
    NoMarketSegments = 1310,
    NoDerivativeInstrAttrib = 1311,
    NoNestedInstrAttrib = 1312,
    DerivativeInstrAttribType = 1313,
    DerivativeInstrAttribValue = 1314,
    DerivativePriceUnitOfMeasure = 1315,
    DerivativePriceUnitOfMeasureQty = 1316,
    DerivativeSettlMethod = 1317,
    DerivativePriceQuoteMethod = 1318,
    DerivativeValuationMethod = 1319,
    DerivativeListMethod = 1320,
    DerivativeCapPrice = 1321,
    DerivativeFloorPrice = 1322,
    DerivativePutOrCall = 1323,
    ListUpdateAction = 1324,
    ParentMktSegmID = 1325,
    TradingSessionDesc = 1326,
    TradSesUpdateAction = 1327,
    RejectText = 1328,
    FeeMultiplier = 1329,
    UnderlyingLegSymbol = 1330,
    UnderlyingLegSymbolSfx = 1331,
    UnderlyingLegSecurityID = 1332,
    UnderlyingLegSecurityIDSource = 1333,
    NoUnderlyingLegSecurityAltID = 1334,
    UnderlyingLegSecurityAltID = 1335,
    UnderlyingLegSecurityAltIDSource = 1336,
    UnderlyingLegSecurityType = 1337,
    UnderlyingLegSecuritySubType = 1338,
    UnderlyingLegMaturityMonthYear = 1339,
    UnderlyingLegStrikePrice = 1340,
    UnderlyingLegSecurityExchange = 1341,
    NoOfLegUnderlyings = 1342,
    UnderlyingLegPutOrCall = 1343,
    UnderlyingLegCFICode = 1344,
    UnderlyingLegMaturityDate = 1345,
    ApplReqID = 1346,
    ApplReqType = 1347,
    ApplResponseType = 1348,
    ApplTotalMessageCount = 1349,
    ApplLastSeqNum = 1350,
    NoApplIDs = 1351,
    ApplResendFlag = 1352,
    ApplResponseID = 1353,
    ApplResponseError = 1354,
    RefApplID = 1355,
    ApplReportID = 1356,
    RefApplLastSeqNum = 1357,
    LegPutOrCall = 1358,
    TotNoFills = 1361,
    NoFills = 1362,
    FillExecID = 1363,
    FillPx = 1364,
    FillQty = 1365,
    LegAllocID = 1366,
    LegAllocSettlCurrency = 1367,
    TradSesEvent = 1368,
    MassActionReportID = 1369,
    NoNotAffectedOrders = 1370,
    NotAffectedOrderID = 1371,
    NotAffOrigClOrdID = 1372,
    MassActionType = 1373,
    MassActionScope = 1374,
    MassActionResponse = 1375,
    MassActionRejectReason = 1376,
    MultilegModel = 1377,
    MultilegPriceMethod = 1378,
    LegVolatility = 1379,
    DividendYield = 1380,
    LegDividendYield = 1381,
    CurrencyRatio = 1382,
    LegCurrencyRatio = 1383,
    LegExecInst = 1384,
    ContingencyType = 1385,
    ListRejectReason = 1386,
    NoTrdRepIndicators = 1387,
    TrdRepPartyRole = 1388,
    TrdRepIndicator = 1389,
    TradePublishIndicator = 1390,
    UnderlyingLegOptAttribute = 1391,
    UnderlyingLegSecurityDesc = 1392,
    MarketReqID = 1393,
    MarketReportID = 1394,
    MarketUpdateAction = 1395,
    MarketSegmentDesc = 1396,
    EncodedMktSegmDescLen = 1397,
    EncodedMktSegmDesc = 1398,
    ApplNewSeqNum = 1399,
    EncryptedPasswordMethod = 1400,
    EncryptedPasswordLen = 1401,
    EncryptedPassword = 1402,
    EncryptedNewPasswordLen = 1403,
    EncryptedNewPassword = 1404,
    UnderlyingLegMaturityTime = 1405,
    RefApplExtID = 1406,
    DefaultApplExtID = 1407,
    DefaultCstmApplVerID = 1408,
    SessionStatus = 1409,
    DefaultVerIndicator = 1410,
    Nested4PartySubIDType = 1411,
    Nested4PartySubID = 1412,
    NoNested4PartySubIDs = 1413,
    NoNested4PartyIDs = 1414,
    Nested4PartyID = 1415,
    Nested4PartyIDSource = 1416,
    Nested4PartyRole = 1417,
    LegLastQty = 1418,
    UnderlyingExerciseStyle = 1419,
    LegExerciseStyle = 1420,
    LegPriceUnitOfMeasure = 1421,
    LegPriceUnitOfMeasureQty = 1422,
    UnderlyingUnitOfMeasureQty = 1423,
    UnderlyingPriceUnitOfMeasure = 1424,
    UnderlyingPriceUnitOfMeasureQty = 1425,
    ApplReportType = 1426,
    SideExecID = 1427,
    OrderDelay = 1428,
    OrderDelayUnit = 1429,
    VenueType = 1430,
    RefOrdIDReason = 1431,
    OrigCustOrderCapacity = 1432,
    RefApplReqID = 1433,
    ModelType = 1434,
    ContractMultiplierUnit = 1435,
    LegContractMultiplierUnit = 1436,
    UnderlyingContractMultiplierUnit = 1437,
    DerivativeContractMultiplierUnit = 1438,
    FlowScheduleType = 1439,
    LegFlowScheduleType = 1440,
    UnderlyingFlowScheduleType = 1441,
    DerivativeFlowScheduleType = 1442,
    FillLiquidityInd = 1443,
    SideLiquidityInd = 1444,
    NoRateSources = 1445,
    RateSource = 1446,
    RateSourceType = 1447,
    ReferencePage = 1448,
    RestructuringType = 1449,
    Seniority = 1450,
    NotionalPercentageOutstanding = 1451,
    OriginalNotionalPercentageOutstanding = 1452,
    UnderlyingRestructuringType = 1453,
    UnderlyingSeniority = 1454,
    UnderlyingNotionalPercentageOutstanding = 1455,
    UnderlyingOriginalNotionalPercentageOutstanding = 1456,
    AttachmentPoint = 1457,
    DetachmentPoint = 1458,
    UnderlyingAttachmentPoint = 1459,
    UnderlyingDetachmentPoint = 1460,
    NoTargetPartyIDs = 1461,
    TargetPartyID = 1462,
    TargetPartyIDSource = 1463,
    TargetPartyRole = 1464,
    SecurityListID = 1465,
    SecurityListRefID = 1466,
    SecurityListDesc = 1467,
    EncodedSecurityListDescLen = 1468,
    EncodedSecurityListDesc = 1469,
    SecurityListType = 1470,
    SecurityListTypeSource = 1471,
    NewsID = 1472,
    NewsCategory = 1473,
    LanguageCode = 1474,
    NoNewsRefIDs = 1475,
    NewsRefID = 1476,
    NewsRefType = 1477,
    StrikePriceDeterminationMethod = 1478,
    StrikePriceBoundaryMethod = 1479,
    StrikePriceBoundaryPrecision = 1480,
    UnderlyingPriceDeterminationMethod = 1481,
    OptPayoutType = 1482,
    NoComplexEvents = 1483,
    ComplexEventType = 1484,
    ComplexOptPayoutAmount = 1485,
    ComplexEventPrice = 1486,
    ComplexEventPriceBoundaryMethod = 1487,
    ComplexEventPriceBoundaryPrecision = 1488,
    ComplexEventPriceTimeType = 1489,
    ComplexEventCondition = 1490,
    NoComplexEventDates = 1491,
    ComplexEventStartDate = 1492,
    ComplexEventEndDate = 1493,
    NoComplexEventTimes = 1494,
    ComplexEventStartTime = 1495,
    ComplexEventEndTime = 1496,
    StreamAsgnReqID = 1497,
    StreamAsgnReqType = 1498,
    NoAsgnReqs = 1499,
    MDStreamID = 1500,
    StreamAsgnRptID = 1501,
    StreamAsgnRejReason = 1502,
    StreamAsgnAckType = 1503,
    RelSymTransactTime = 1504,
    StreamAsgnType = 1617,
    ShortSecurityDesc = 5381,
    PortfolioID = 5424,
    NasdaqSubMkt = 5815,
    PerformanceTracingIdentifier = 9900,
    SecurityGroupParentID = 9992,
    SecurityGroupName = 9993,
    NoPortfolioIDs = 9994,
    PortfolioRequestResult = 9995,
    PortfolioReqID = 9996,
    SecurityGroupID = 9997,
    NoVenueIdentifiers = 9998,
    VenueID = 9999,
    Max = 10000
}; // enum Field
};

namespace MessageType {
enum Type
{
    CustomMessage = 0,
    Heartbeat = 1,                                // 0
    TestRequest = 2,                              // 1
    ResendRequest = 3,                            // 2
    Reject = 4,                                   // 3
    SequenceReset = 5,                            // 4
    Logout = 6,                                   // 5
    Logon = 7,                                    // A
    IOI = 8,                                      // 6
    Advertisement = 9,                            // 7
    ExecutionReport = 10,                         // 8
    OrderCancelReject = 11,                       // 9
    News = 12,                                    // B
    Email = 13,                                   // C
    NewOrderSingle = 14,                          // D
    NewOrderList = 15,                            // E
    OrderCancelRequest = 16,                      // F
    OrderCancelReplaceRequest = 17,               // G
    OrderStatusRequest = 18,                      // H
    AllocationInstruction = 19,                   // J
    ListCancelRequest = 20,                       // K
    ListExecute = 21,                             // L
    ListStatusRequest = 22,                       // M
    ListStatus = 23,                              // N
    AllocationInstructionAck = 24,                // P
    DontKnowTrade = 25,                           // Q
    QuoteRequest = 26,                            // R
    Quote = 27,                                   // S
    SettlementInstructions = 28,                  // T
    MarketDataRequest = 29,                       // V
    MarketDataSnapshotFullRefresh = 30,           // W
    MarketDataIncrementalRefresh = 31,            // X
    MarketDataRequestReject = 32,                 // Y
    QuoteCancel = 33,                             // Z
    QuoteStatusRequest = 34,                      // a
    MassQuoteAcknowledgement = 35,                // b
    SecurityDefinitionRequest = 36,               // c
    SecurityDefinition = 37,                      // d
    SecurityStatusRequest = 38,                   // e
    SecurityStatus = 39,                          // f
    TradingSessionStatusRequest = 40,             // g
    TradingSessionStatus = 41,                    // h
    MassQuote = 42,                               // i
    BusinessMessageReject = 43,                   // j
    BidRequest = 44,                              // k
    BidResponse = 45,                             // l
    ListStrikePrice = 46,                         // m
    RegistrationInstructions = 47,                // o
    RegistrationInstructionsResponse = 48,        // p
    OrderMassCancelRequest = 49,                  // q
    OrderMassCancelReport = 50,                   // r
    NewOrderCross = 51,                           // s
    CrossOrderCancelReplaceRequest = 52,          // t
    CrossOrderCancelRequest = 53,                 // u
    SecurityTypeRequest = 54,                     // v
    SecurityTypes = 55,                           // w
    SecurityListRequest = 56,                     // x
    SecurityList = 57,                            // y
    DerivativeSecurityListRequest = 58,           // z
    DerivativeSecurityList = 59,                  // AA
    NewOrderMultileg = 60,                        // AB
    MultilegOrderCancelReplace = 61,              // AC
    TradeCaptureReportRequest = 62,               // AD
    TradeCaptureReport = 63,                      // AE
    OrderMassStatusRequest = 64,                  // AF
    QuoteRequestReject = 65,                      // AG
    RFQRequest = 66,                              // AH
    QuoteStatusReport = 67,                       // AI
    QuoteResponse = 68,                           // AJ
    Confirmation = 69,                            // AK
    PositionMaintenanceRequest = 70,              // AL
    PositionMaintenanceReport = 71,               // AM
    RequestForPositions = 72,                     // AN
    RequestForPositionsAck = 73,                  // AO
    PositionReport = 74,                          // AP
    TradeCaptureReportRequestAck = 75,            // AQ
    TradeCaptureReportAck = 76,                   // AR
    AllocationReport = 77,                        // AS
    AllocationReportAck = 78,                     // AT
    ConfirmationAck = 79,                         // AU
    SettlementInstructionRequest = 80,            // AV
    AssignmentReport = 81,                        // AW
    CollateralRequest = 82,                       // AX
    CollateralAssignment = 83,                    // AY
    CollateralResponse = 84,                      // AZ
    CollateralReport = 85,                        // BA
    CollateralInquiry = 86,                       // BB
    NetworkCounterpartySystemStatusRequest = 87,  // BC
    NetworkCounterpartySystemStatusResponse = 88, // BD
    UserRequest = 89,                             // BE
    UserResponse = 90,                            // BF
    CollateralInquiryAck = 91,                    // BG
    ConfirmationRequest = 92,                     // BH
    ContraryIntentionReport = 93,                 // BO
    SecurityDefinitionUpdateReport = 94,          // BP
    SecurityListUpdateReport = 95,                // BK
    AdjustedPositionReport = 96,                  // BL
    AllocationInstructionAlert = 97,              // BM
    ExecutionAcknowledgement = 98,                // BN
    TradingSessionList = 99,                      // BJ
    TradingSessionListRequest = 100,              // BI
    SettlementObligationReport = 101,             // BQ
    DerivativeSecurityListUpdateReport = 102,     // BR
    TradingSessionListUpdateReport = 103,         // BS
    MarketDefinitionRequest = 104,                // BT
    MarketDefinition = 105,                       // BU
    MarketDefinitionUpdateReport = 106,           // BV
    ApplicationMessageRequest = 107,              // BW
    ApplicationMessageRequestAck = 108,           // BX
    ApplicationMessageReport = 109,               // BY
    OrderMassActionReport = 110,                  // BZ
    OrderMassActionRequest = 111,                 // CA
    UserNotification = 112,                       // CB
    StreamAssignmentRequest = 113,                // CC
    StreamAssignmentReport = 114,                 // CD
    StreamAssignmentReportACK = 115,              // CE
    SecurityGroupParameterRequest = 116,          // TA
    SecurityGroupParameters = 117,                // TB
    PortfolioDefinitionRequest = 118,             // TC
    PortfolioDefinition = 119,                    // TD
    Max = 0xFF
}; // enum MessageType
};

namespace Enum {
struct STRATEGY_EXPORT EncryptMethod
{
    static const int NONE_OTHER;  // 0
    static const int PKCS;        // 1
    static const int DES;         // 2
    static const int PKCS_DES;    // 3
    static const int PGP_DES;     // 4
    static const int PGP_DES_MD5; // 5
    static const int PEM_DES_MD5; // 6
};
struct STRATEGY_EXPORT SessionRejectReason
{
    static const int INVALID_TAG_NUMBER;                             // 0
    static const int REQUIRED_TAG_MISSING;                           // 1
    static const int SENDINGTIME_ACCURACY_PROBLEM;                   // 10
    static const int INVALID_MSGTYPE;                                // 11
    static const int XML_VALIDATION_ERROR;                           // 12
    static const int TAG_APPEARS_MORE_THAN_ONCE;                     // 13
    static const int TAG_SPECIFIED_OUT_OF_REQUIRED_ORDER;            // 14
    static const int REPEATING_GROUP_FIELDS_OUT_OF_ORDER;            // 15
    static const int INCORRECT_NUMINGROUP_COUNT_FOR_REPEATING_GROUP; // 16
    static const int NON_DATA_VALUE_INCLUDES_FIELD_DELIMITER;        // 17
    static const int TAG_NOT_DEFINED_FOR_THIS_MESSAGE_TYPE;          // 2
    static const int UNDEFINED_TAG;                                  // 3
    static const int TAG_SPECIFIED_WITHOUT_A_VALUE;                  // 4
    static const int VALUE_IS_INCORRECT;                             // 5
    static const int INCORRECT_DATA_FORMAT_FOR_VALUE;                // 6
    static const int DECRYPTION_PROBLEM;                             // 7
    static const int SIGNATURE_PROBLEM;                              // 8
    static const int COMPID_PROBLEM;                                 // 9
    static const int OTHER;                                          // 99
};
struct STRATEGY_EXPORT MsgDirection
{
    static const char RECEIVE; // 'R'
    static const char SEND;    // 'S'
};
struct STRATEGY_EXPORT AdvSide
{
    static const char BUY;   // 'B'
    static const char SELL;  // 'S'
    static const char TRADE; // 'T'
    static const char CROSS; // 'X'
};
struct STRATEGY_EXPORT CommType
{
    static const char PER_UNIT;                    // '1'
    static const char PERCENT;                     // '2'
    static const char ABSOLUTE;                    // '3'
    static const char PERCENTAGE_WAIVED_4;         // '4'
    static const char PERCENTAGE_WAIVED_5;         // '5'
    static const char POINTS_PER_BOND_OR_CONTRACT; // '6'
};
struct STRATEGY_EXPORT HandlInst
{
    static const char AUTOMATED_EXECUTION_ORDER_PRIVATE_NO_BROKER_INTERVENTION; // '1'
    static const char AUTOMATED_EXECUTION_ORDER_PUBLIC_BROKER_INTERVENTION_OK;  // '2'
    static const char MANUAL_ORDER_BEST_EXECUTION;                              // '3'
};
struct STRATEGY_EXPORT IOIQltyInd
{
    static const char HIGH;   // 'H'
    static const char LOW;    // 'L'
    static const char MEDIUM; // 'M'
};
struct STRATEGY_EXPORT IOITransType
{
    static const char NEW;     // 'N'
    static const char CANCEL;  // 'C'
    static const char REPLACE; // 'R'
};
struct STRATEGY_EXPORT LastCapacity
{
    static const char AGENT;              // '1'
    static const char CROSS_AS_AGENT;     // '2'
    static const char CROSS_AS_PRINCIPAL; // '3'
    static const char PRINCIPAL;          // '4'
};
struct STRATEGY_EXPORT OrdStatus
{
    static const char NEW;                  // '0'
    static const char PARTIALLY_FILLED;     // '1'
    static const char FILLED;               // '2'
    static const char DONE_FOR_DAY;         // '3'
    static const char CANCELED;             // '4'
    static const char REPLACED;             // '5'
    static const char PENDING_CANCEL;       // '6'
    static const char STOPPED;              // '7'
    static const char REJECTED;             // '8'
    static const char SUSPENDED;            // '9'
    static const char PENDING_NEW;          // 'A'
    static const char CALCULATED;           // 'B'
    static const char EXPIRED;              // 'C'
    static const char ACCEPTED_FOR_BIDDING; // 'D'
    static const char PENDING_REPLACE;      // 'E'
};
struct STRATEGY_EXPORT OrdType
{
    static const char MARKET;                         // '1'
    static const char LIMIT;                          // '2'
    static const char STOP;                           // '3'
    static const char STOP_LIMIT;                     // '4'
    static const char MARKET_ON_CLOSE;                // '5'
    static const char WITH_OR_WITHOUT;                // '6'
    static const char LIMIT_OR_BETTER;                // '7'
    static const char LIMIT_WITH_OR_WITHOUT;          // '8'
    static const char ON_BASIS;                       // '9'
    static const char ON_CLOSE;                       // 'A'
    static const char LIMIT_ON_CLOSE;                 // 'B'
    static const char FOREX_MARKET;                   // 'C'
    static const char PREVIOUSLY_QUOTED;              // 'D'
    static const char PREVIOUSLY_INDICATED;           // 'E'
    static const char FOREX_LIMIT;                    // 'F'
    static const char FOREX_SWAP;                     // 'G'
    static const char FOREX_PREVIOUSLY_QUOTED;        // 'H'
    static const char FUNARI;                         // 'I'
    static const char MARKET_IF_TOUCHED;              // 'J'
    static const char MARKET_WITH_LEFT_OVER_AS_LIMIT; // 'K'
    static const char PREVIOUS_FUND_VALUATION_POINT;  // 'L'
    static const char NEXT_FUND_VALUATION_POINT;      // 'M'
    static const char PEGGED;                         // 'P'
    static const char COUNTER_ORDER_SELECTION;        // 'Q'
};
struct STRATEGY_EXPORT Side
{
    static const char BUY;                // '1'
    static const char SELL;               // '2'
    static const char BUY_MINUS;          // '3'
    static const char SELL_PLUS;          // '4'
    static const char SELL_SHORT;         // '5'
    static const char SELL_SHORT_EXEMPT;  // '6'
    static const char UNDISCLOSED;        // '7'
    static const char CROSS;              // '8'
    static const char CROSS_SHORT;        // '9'
    static const char CROSS_SHORT_EXEMPT; // 'A'
    static const char AS_DEFINED;         // 'B'
    static const char OPPOSITE;           // 'C'
    static const char SUBSCRIBE;          // 'D'
    static const char REDEEM;             // 'E'
    static const char LEND;               // 'F'
    static const char BORROW;             // 'G'
};
struct STRATEGY_EXPORT TimeInForce
{
    static const char DAY;                   // '0'
    static const char GOOD_TILL_CANCEL;      // '1'
    static const char AT_THE_OPENING;        // '2'
    static const char IMMEDIATE_OR_CANCEL;   // '3'
    static const char FILL_OR_KILL;          // '4'
    static const char GOOD_TILL_CROSSING;    // '5'
    static const char GOOD_TILL_DATE;        // '6'
    static const char AT_THE_CLOSE;          // '7'
    static const char GOOD_THROUGH_CROSSING; // '8'
    static const char AT_CROSSING;           // '9'
};
struct STRATEGY_EXPORT Urgency
{
    static const char NORMAL;     // '0'
    static const char FLASH;      // '1'
    static const char BACKGROUND; // '2'
};
struct STRATEGY_EXPORT AllocTransType
{
    static const char NEW;                            // '0'
    static const char REPLACE;                        // '1'
    static const char CANCEL;                         // '2'
    static const char PRELIMINARY;                    // '3'
    static const char CALCULATED;                     // '4'
    static const char CALCULATED_WITHOUT_PRELIMINARY; // '5'
    static const char REVERSAL;                       // '6'
};
struct STRATEGY_EXPORT PositionEffect
{
    static const char CLOSE;                    // 'C'
    static const char FIFO;                     // 'F'
    static const char OPEN;                     // 'O'
    static const char ROLLED;                   // 'R'
    static const char CLOSE_BUT_NOTIFY_ON_OPEN; // 'N'
    static const char DEFAULT;                  // 'D'
};
struct STRATEGY_EXPORT ProcessCode
{
    static const char REGULAR;              // '0'
    static const char SOFT_DOLLAR;          // '1'
    static const char STEP_IN;              // '2'
    static const char STEP_OUT;             // '3'
    static const char SOFT_DOLLAR_STEP_IN;  // '4'
    static const char SOFT_DOLLAR_STEP_OUT; // '5'
    static const char PLAN_SPONSOR;         // '6'
};
struct STRATEGY_EXPORT AllocStatus
{
    static const int ACCEPTED;                 // 0
    static const int BLOCK_LEVEL_REJECT;       // 1
    static const int ACCOUNT_LEVEL_REJECT;     // 2
    static const int RECEIVED;                 // 3
    static const int INCOMPLETE;               // 4
    static const int REJECTED_BY_INTERMEDIARY; // 5
    static const int ALLOCATION_PENDING;       // 6
    static const int REVERSED;                 // 7
};
struct STRATEGY_EXPORT AllocRejCode
{
    static const int UNKNOWN_ACCOUNT;                   // 0
    static const int INCORRECT_QUANTITY;                // 1
    static const int INCORRECT_AVERAGEG_PRICE;          // 2
    static const int UNKNOWN_EXECUTING_BROKER_MNEMONIC; // 3
    static const int COMMISSION_DIFFERENCE;             // 4
    static const int UNKNOWN_ORDERID;                   // 5
    static const int UNKNOWN_LISTID;                    // 6
    static const int OTHER_7;                           // 7
    static const int INCORRECT_ALLOCATED_QUANTITY;      // 8
    static const int CALCULATION_DIFFERENCE;            // 9
    static const int UNKNOWN_OR_STALE_EXECID;           // 10
    static const int MISMATCHED_DATA;                   // 11
    static const int UNKNOWN_CLORDID;                   // 12
    static const int WAREHOUSE_REQUEST_REJECTED;        // 13
    static const int OTHER_99;                          // 99
};
struct STRATEGY_EXPORT EmailType
{
    static const char NEW;         // '0'
    static const char REPLY;       // '1'
    static const char ADMIN_REPLY; // '2'
};
struct STRATEGY_EXPORT CxlRejReason
{
    static const int TOO_LATE_TO_CANCEL;                                        // 0
    static const int UNKNOWN_ORDER;                                             // 1
    static const int BROKER;                                                    // 2
    static const int ORDER_ALREADY_IN_PENDING_CANCEL_OR_PENDING_REPLACE_STATUS; // 3
    static const int UNABLE_TO_PROCESS_ORDER_MASS_CANCEL_REQUEST;               // 4
    static const int ORIGORDMODTIME;                                            // 5
    static const int DUPLICATE_CLORDID;                                         // 6
    static const int PRICE_EXCEEDS_CURRENT_PRICE;                               // 7
    static const int PRICE_EXCEEDS_CURRENT_PRICE_BAND;                          // 8
    static const int INVALID_PRICE_INCREMENT;                                   // 18
    static const int OTHER;                                                     // 99
};
struct STRATEGY_EXPORT OrdRejReason
{
    static const int BROKER;                                     // 0
    static const int UNKNOWN_SYMBOL;                             // 1
    static const int EXCHANGE_CLOSED;                            // 2
    static const int ORDER_EXCEEDS_LIMIT;                        // 3
    static const int TOO_LATE_TO_ENTER;                          // 4
    static const int UNKNOWN_ORDER;                              // 5
    static const int DUPLICATE_ORDER;                            // 6
    static const int DUPLICATE_OF_A_VERBALLY_COMMUNICATED_ORDER; // 7
    static const int STALE_ORDER;                                // 8
    static const int TRADE_ALONG_REQUIRED;                       // 9
    static const int INVALID_INVESTOR_ID;                        // 10
    static const int UNSUPPORTED_ORDER_CHARACTERISTIC;           // 11
    static const int SURVEILLENCE_OPTION;                        // 12
    static const int INCORRECT_QUANTITY;                         // 13
    static const int INCORRECT_ALLOCATED_QUANTITY;               // 14
    static const int UNKNOWN_ACCOUNT;                            // 15
    static const int PRICE_EXCEEDS_CURRENT_PRICE_BAND;           // 16
    static const int INVALID_PRICE_INCREMENT;                    // 18
    static const int OTHER;                                      // 99
};
struct STRATEGY_EXPORT IOIQualifier
{
    static const char ALL_OR_NONE;          // 'A'
    static const char MARKET_ON_CLOSE;      // 'B'
    static const char AT_THE_CLOSE;         // 'C'
    static const char VWAP;                 // 'D'
    static const char IN_TOUCH_WITH;        // 'I'
    static const char LIMIT;                // 'L'
    static const char MORE_BEHIND;          // 'M'
    static const char AT_THE_OPEN;          // 'O'
    static const char TAKING_A_POSITION;    // 'P'
    static const char AT_THE_MARKET;        // 'Q'
    static const char READY_TO_TRADE;       // 'R'
    static const char PORTFOLIO_SHOWN;      // 'S'
    static const char THROUGH_THE_DAY;      // 'T'
    static const char VERSUS;               // 'V'
    static const char INDICATION;           // 'W'
    static const char CROSSING_OPPORTUNITY; // 'X'
    static const char AT_THE_MIDPOINT;      // 'Y'
    static const char PRE_OPEN;             // 'Z'
};
struct STRATEGY_EXPORT DKReason
{
    static const char UNKNOWN_SYMBOL;         // 'A'
    static const char WRONG_SIDE;             // 'B'
    static const char QUANTITY_EXCEEDS_ORDER; // 'C'
    static const char NO_MATCHING_ORDER;      // 'D'
    static const char PRICE_EXCEEDS_LIMIT;    // 'E'
    static const char CALCULATION_DIFFERENCE; // 'F'
    static const char OTHER;                  // 'Z'
};
struct STRATEGY_EXPORT MiscFeeType
{
    static const char REGULATORY;       // '1'
    static const char TAX;              // '2'
    static const char LOCAL_COMMISSION; // '3'
    static const char EXCHANGE_FEES;    // '4'
    static const char STAMP;            // '5'
    static const char LEVY;             // '6'
    static const char OTHER;            // '7'
    static const char MARKUP;           // '8'
    static const char CONSUMPTION_TAX;  // '9'
};
struct STRATEGY_EXPORT ExecType
{
    static const char NEW;                                 // '0'
    static const char DONE_FOR_DAY;                        // '3'
    static const char CANCELED;                            // '4'
    static const char REPLACED;                            // '5'
    static const char PENDING_CANCEL;                      // '6'
    static const char STOPPED;                             // '7'
    static const char REJECTED;                            // '8'
    static const char SUSPENDED;                           // '9'
    static const char PENDING_NEW;                         // 'A'
    static const char CALCULATED;                          // 'B'
    static const char EXPIRED;                             // 'C'
    static const char RESTATED;                            // 'D'
    static const char PENDING_REPLACE;                     // 'E'
    static const char TRADE;                               // 'F'
    static const char TRADE_CORRECT;                       // 'G'
    static const char TRADE_CANCEL;                        // 'H'
    static const char ORDER_STATUS;                        // 'I'
    static const char TRADE_IN_A_CLEARING_HOLD;            // 'J'
    static const char TRADE_HAS_BEEN_RELEASED_TO_CLEARING; // 'K'
    static const char TRIGGERED_OR_ACTIVATED_BY_SYSTEM;    // 'L'
};
struct STRATEGY_EXPORT SettlCurrFxRateCalc
{
    static const char MULTIPLY; // 'M'
    static const char DIVIDE;   // 'D'
};
struct STRATEGY_EXPORT SettlInstMode
{
    static const char DEFAULT;                                // '0'
    static const char STANDING_INSTRUCTIONS_PROVIDED;         // '1'
    static const char SPECIFIC_ALLOCATION_ACCOUNT_OVERRIDING; // '2'
    static const char SPECIFIC_ALLOCATION_ACCOUNT_STANDING;   // '3'
    static const char SPECIFIC_ORDER_FOR_A_SINGLE_ACCOUNT;    // '4'
    static const char REQUEST_REJECT;                         // '5'
};
struct STRATEGY_EXPORT SettlInstTransType
{
    static const char NEW;     // 'N'
    static const char CANCEL;  // 'C'
    static const char REPLACE; // 'R'
    static const char RESTATE; // 'T'
};
struct STRATEGY_EXPORT SettlInstSource
{
    static const char BROKERS_INSTRUCTIONS;      // '1'
    static const char INSTITUTIONS_INSTRUCTIONS; // '2'
    static const char INVESTOR;                  // '3'
};
struct STRATEGY_EXPORT StandInstDbType
{
    static const int OTHER;              // 0
    static const int DTC_SID;            // 1
    static const int THOMSON_ALERT;      // 2
    static const int A_GLOBAL_CUSTODIAN; // 3
    static const int ACCOUNTNET;         // 4
};
struct STRATEGY_EXPORT SettlDeliveryType
{
    static const int VERSUS_PAYMENT_DELIVER; // 0
    static const int FREE_DELIVER;           // 1
    static const int TRI_PARTY;              // 2
    static const int HOLD_IN_CUSTODY;        // 3
};
struct STRATEGY_EXPORT AllocLinkType
{
    static const int FX_NETTING; // 0
    static const int FX_SWAP;    // 1
};
struct STRATEGY_EXPORT PutOrCall
{
    static const int PUT;  // 0
    static const int CALL; // 1
};
struct STRATEGY_EXPORT CoveredOrUncovered
{
    static const int COVERED;   // 0
    static const int UNCOVERED; // 1
};
struct STRATEGY_EXPORT AllocHandlInst
{
    static const int MATCH;             // 1
    static const int FORWARD;           // 2
    static const int FORWARD_AND_MATCH; // 3
};
struct STRATEGY_EXPORT RoutingType
{
    static const int TARGET_FIRM; // 1
    static const int TARGET_LIST; // 2
    static const int BLOCK_FIRM;  // 3
    static const int BLOCK_LIST;  // 4
};
struct STRATEGY_EXPORT SubscriptionRequestType
{
    static const char SNAPSHOT;                                      // '0'
    static const char SNAPSHOT_PLUS_UPDATES;                         // '1'
    static const char DISABLE_PREVIOUS_SNAPSHOT_PLUS_UPDATE_REQUEST; // '2'
};
struct STRATEGY_EXPORT MDUpdateType
{
    static const int FULL_REFRESH;        // 0
    static const int INCREMENTAL_REFRESH; // 1
};
struct STRATEGY_EXPORT MDEntryType
{
    static const char BID;                                             // '0'
    static const char OFFER;                                           // '1'
    static const char TRADE;                                           // '2'
    static const char INDEX_VALUE;                                     // '3'
    static const char OPENING_PRICE;                                   // '4'
    static const char CLOSING_PRICE;                                   // '5'
    static const char SETTLEMENT_PRICE;                                // '6'
    static const char TRADING_SESSION_HIGH_PRICE;                      // '7'
    static const char TRADING_SESSION_LOW_PRICE;                       // '8'
    static const char TRADING_SESSION_VWAP_PRICE;                      // '9'
    static const char IMBALANCE;                                       // 'A'
    static const char TRADE_VOLUME;                                    // 'B'
    static const char OPEN_INTEREST;                                   // 'C'
    static const char COMPOSITE_UNDERLYING_PRICE;                      // 'D'
    static const char SIMULATED_SELL_PRICE;                            // 'E'
    static const char SIMULATED_BUY_PRICE;                             // 'F'
    static const char MARGIN_RATE;                                     // 'G'
    static const char MID_PRICE;                                       // 'H'
    static const char EMPTY_BOOK;                                      // 'J'
    static const char SETTLE_HIGH_PRICE;                               // 'K'
    static const char SETTLE_LOW_PRICE;                                // 'L'
    static const char PRIOR_SETTLE_PRICE;                              // 'M'
    static const char SESSION_HIGH_BID;                                // 'N'
    static const char SESSION_LOW_OFFER;                               // 'O'
    static const char EARLY_PRICES;                                    // 'P'
    static const char AUCTION_CLEARING_PRICE;                          // 'Q'
    static const char SWAP_VALUE_FACTOR;                               // 'S'
    static const char DAILY_VALUE_ADJUSTMENT_FOR_LONG_POSITIONS;       // 'R'
    static const char CUMULATIVE_VALUE_ADJUSTMENT_FOR_LONG_POSITIONS;  // 'T'
    static const char DAILY_VALUE_ADJUSTMENT_FOR_SHORT_POSITIONS;      // 'U'
    static const char CUMULATIVE_VALUE_ADJUSTMENT_FOR_SHORT_POSITIONS; // 'V'
    static const char RECOVERY_RATE;                                   // 'Y'
    static const char RECOVERY_RATE_FOR_LONG;                          // 'Z'
    static const char RECOVERY_RATE_FOR_SHORT;                         // 'a'
    static const char FIXING_PRICE;                                    // 'W'
    static const char CASH_RATE;                                       // 'X'
};
struct STRATEGY_EXPORT TickDirection
{
    static const char PLUS_TICK;       // '0'
    static const char ZERO_PLUS_TICK;  // '1'
    static const char MINUS_TICK;      // '2'
    static const char ZERO_MINUS_TICK; // '3'
};
struct STRATEGY_EXPORT MDUpdateAction
{
    static const char NEW;         // '0'
    static const char CHANGE;      // '1'
    static const char DELETE;      // '2'
    static const char DELETE_THRU; // '3'
    static const char DELETE_FROM; // '4'
    static const char OVERLAY;     // '5'
};
struct STRATEGY_EXPORT MDReqRejReason
{
    static const char UNKNOWN_SYMBOL;                      // '0'
    static const char DUPLICATE_MDREQID;                   // '1'
    static const char INSUFFICIENT_BANDWIDTH;              // '2'
    static const char INSUFFICIENT_PERMISSIONS;            // '3'
    static const char UNSUPPORTED_SUBSCRIPTIONREQUESTTYPE; // '4'
    static const char UNSUPPORTED_MARKETDEPTH;             // '5'
    static const char UNSUPPORTED_MDUPDATETYPE;            // '6'
    static const char UNSUPPORTED_AGGREGATEDBOOK;          // '7'
    static const char UNSUPPORTED_MDENTRYTYPE;             // '8'
    static const char UNSUPPORTED_TRADINGSESSIONID;        // '9'
    static const char UNSUPPORTED_SCOPE;                   // 'A'
    static const char UNSUPPORTED_OPENCLOSESETTLEFLAG;     // 'B'
    static const char UNSUPPORTED_MDIMPLICITDELETE;        // 'C'
    static const char INSUFFICIENT_CREDIT;                 // 'D'
};
struct STRATEGY_EXPORT DeleteReason
{
    static const char CANCELLATION; // '0'
    static const char ERROR;        // '1'
};
struct STRATEGY_EXPORT QuoteStatus
{
    static const int ACCEPTED;                        // 0
    static const int CANCEL_FOR_SYMBOL;               // 1
    static const int CANCELED_FOR_SECURITY_TYPE;      // 2
    static const int CANCELED_FOR_UNDERLYING;         // 3
    static const int CANCELED_ALL;                    // 4
    static const int REJECTED;                        // 5
    static const int REMOVED_FROM_MARKET;             // 6
    static const int EXPIRED;                         // 7
    static const int QUERY;                           // 8
    static const int QUOTE_NOT_FOUND;                 // 9
    static const int PENDING;                         // 10
    static const int PASS;                            // 11
    static const int LOCKED_MARKET_WARNING;           // 12
    static const int CROSS_MARKET_WARNING;            // 13
    static const int CANCELED_DUE_TO_LOCK_MARKET;     // 14
    static const int CANCELED_DUE_TO_CROSS_MARKET;    // 15
    static const int ACTIVE;                          // 16
    static const int CANCELED;                        // 17
    static const int UNSOLICITED_QUOTE_REPLENISHMENT; // 18
    static const int PENDING_END_TRADE;               // 19
    static const int TOO_LATE_TO_END;                 // 20
};
struct STRATEGY_EXPORT QuoteCancelType
{
    static const int CANCEL_FOR_ONE_OR_MORE_SECURITIES;        // 1
    static const int CANCEL_FOR_SECURITY_TYPE;                 // 2
    static const int CANCEL_FOR_UNDERLYING_SECURITY;           // 3
    static const int CANCEL_ALL_QUOTES;                        // 4
    static const int CANCEL_QUOTE_SPECIFIED_IN_QUOTEID;        // 5
    static const int CANCEL_BY_QUOTETYPE;                      // 6
    static const int CANCEL_FOR_SECURITY_ISSUER;               // 7
    static const int CANCEL_FOR_ISSUER_OF_UNDERLYING_SECURITY; // 8
};
struct STRATEGY_EXPORT QuoteRejectReason
{
    static const int UNKNOWN_SYMBOL;                                   // 1
    static const int EXCHANGE;                                         // 2
    static const int QUOTE_REQUEST_EXCEEDS_LIMIT;                      // 3
    static const int TOO_LATE_TO_ENTER;                                // 4
    static const int UNKNOWN_QUOTE;                                    // 5
    static const int DUPLICATE_QUOTE;                                  // 6
    static const int INVALID_BID_ASK_SPREAD;                           // 7
    static const int INVALID_PRICE;                                    // 8
    static const int NOT_AUTHORIZED_TO_QUOTE_SECURITY;                 // 9
    static const int PRICE_EXCEEDS_CURRENT_PRICE_BAND;                 // 10
    static const int QUOTE_LOCKED;                                     // 11
    static const int OTHER;                                            // 99
    static const int INVALID_OR_UNKNOWN_SECURITY_ISSUER;               // 12
    static const int INVALID_OR_UNKNOWN_ISSUER_OF_UNDERLYING_SECURITY; // 13
};
struct STRATEGY_EXPORT QuoteResponseLevel
{
    static const int NO_ACKNOWLEDGEMENT;                            // 0
    static const int ACKNOWLEDGE_ONLY_NEGATIVE_OR_ERRONEOUS_QUOTES; // 1
    static const int ACKNOWLEDGE_EACH_QUOTE_MESSAGE;                // 2
    static const int SUMMARY_ACKNOWLEDGEMENT;                       // 3
};
struct STRATEGY_EXPORT QuoteRequestType
{
    static const int MANUAL;    // 1
    static const int AUTOMATIC; // 2
};
struct STRATEGY_EXPORT SecurityRequestType
{
    static const int REQUEST_SECURITY_IDENTITY_AND_SPECIFICATIONS;              // 0
    static const int REQUEST_SECURITY_IDENTITY_FOR_THE_SPECIFICATIONS_PROVIDED; // 1
    static const int REQUEST_LIST_SECURITY_TYPES;                               // 2
    static const int REQUEST_LIST_SECURITIES;                                   // 3
    static const int SYMBOL;                                                    // 4
    static const int SECURITYTYPE_AND_OR_CFICODE;                               // 5
    static const int PRODUCT;                                                   // 6
    static const int TRADINGSESSIONID;                                          // 7
    static const int ALL_SECURITIES;                                            // 8
    static const int MARKETID_OR_MARKETID_PLUS_MARKETSEGMENTID;                 // 9
};
struct STRATEGY_EXPORT SecurityResponseType
{
    static const int ACCEPT_SECURITY_PROPOSAL_AS_IS;                                      // 1
    static const int ACCEPT_SECURITY_PROPOSAL_WITH_REVISIONS_AS_INDICATED_IN_THE_MESSAGE; // 2
    static const int LIST_OF_SECURITY_TYPES_RETURNED_PER_REQUEST;                         // 3
    static const int LIST_OF_SECURITIES_RETURNED_PER_REQUEST;                             // 4
    static const int REJECT_SECURITY_PROPOSAL;                                            // 5
    static const int CANNOT_MATCH_SELECTION_CRITERIA;                                     // 6
};
struct STRATEGY_EXPORT SecurityTradingStatus
{
    static const int OPENING_DELAY;                  // 1
    static const int TRADING_HALT;                   // 2
    static const int RESUME;                         // 3
    static const int NO_OPEN;                        // 4
    static const int PRICE_INDICATION;               // 5
    static const int TRADING_RANGE_INDICATION;       // 6
    static const int MARKET_IMBALANCE_BUY;           // 7
    static const int MARKET_IMBALANCE_SELL;          // 8
    static const int MARKET_ON_CLOSE_IMBALANCE_BUY;  // 9
    static const int MARKET_ON_CLOSE_IMBALANCE_SELL; // 10
    static const int NO_MARKET_IMBALANCE;            // 12
    static const int NO_MARKET_ON_CLOSE_IMBALANCE;   // 13
    static const int ITS_PRE_OPENING;                // 14
    static const int NEW_PRICE_INDICATION;           // 15
    static const int TRADE_DISSEMINATION_TIME;       // 16
    static const int READY_TO_TRADE;                 // 17
    static const int NOT_AVAILABLE_FOR_TRADING;      // 18
    static const int NOT_TRADED_ON_THIS_MARKET;      // 19
    static const int UNKNOWN_OR_INVALID;             // 20
    static const int PRE_OPEN;                       // 21
    static const int OPENING_ROTATION;               // 22
    static const int FAST_MARKET;                    // 23
    static const int PRE_CROSS;                      // 24
    static const int CROSS;                          // 25
    static const int POST_CLOSE;                     // 26
};
struct STRATEGY_EXPORT HaltReasonInt
{
    static const int NEWS_DISSEMINATION;     // 0
    static const int ORDER_INFLUX;           // 1
    static const int ORDER_IMBALANCE;        // 2
    static const int ADDITIONAL_INFORMATION; // 3
    static const int NEWS_PENDING;           // 4
    static const int EQUIPMENT_CHANGEOVER;   // 5
};
struct STRATEGY_EXPORT Adjustment
{
    static const int CANCEL;     // 1
    static const int ERROR;      // 2
    static const int CORRECTION; // 3
};
struct STRATEGY_EXPORT TradSesMethod
{
    static const int ELECTRONIC;  // 1
    static const int OPEN_OUTCRY; // 2
    static const int TWO_PARTY;   // 3
};
struct STRATEGY_EXPORT TradSesMode
{
    static const int TESTING;    // 1
    static const int SIMULATED;  // 2
    static const int PRODUCTION; // 3
};
struct STRATEGY_EXPORT TradSesStatus
{
    static const int UNKNOWN;          // 0
    static const int HALTED;           // 1
    static const int OPEN;             // 2
    static const int CLOSED;           // 3
    static const int PRE_OPEN;         // 4
    static const int PRE_CLOSE;        // 5
    static const int REQUEST_REJECTED; // 6
};
struct STRATEGY_EXPORT BidRequestTransType
{
    static const char CANCEL; // 'C'
    static const char NO;     // 'N'
};
struct STRATEGY_EXPORT ExecRestatementReason
{
    static const int GT_CORPORATE_ACTION;         // 0
    static const int GT_RENEWAL;                  // 1
    static const int VERBAL_CHANGE;               // 2
    static const int REPRICING_OF_ORDER;          // 3
    static const int BROKER_OPTION;               // 4
    static const int PARTIAL_DECLINE_OF_ORDERQTY; // 5
    static const int CANCEL_ON_TRADING_HALT;      // 6
    static const int CANCEL_ON_SYSTEM_FAILURE;    // 7
    static const int MARKET;                      // 8
    static const int CANCELED_NOT_BEST;           // 9
    static const int WAREHOUSE_RECAP;             // 10
    static const int PEG_REFRESH;                 // 11
    static const int OTHER;                       // 99
};
struct STRATEGY_EXPORT BusinessRejectReason
{
    static const int OTHER;                                     // 0
    static const int UNKNOWN_ID;                                // 1
    static const int UNKNOWN_SECURITY;                          // 2
    static const int UNSUPPORTED_MESSAGE_TYPE;                  // 3
    static const int APPLICATION_NOT_AVAILABLE;                 // 4
    static const int CONDITIONALLY_REQUIRED_FIELD_MISSING;      // 5
    static const int NOT_AUTHORIZED;                            // 6
    static const int DELIVERTO_FIRM_NOT_AVAILABLE_AT_THIS_TIME; // 7
    static const int INVALID_PRICE_INCREMENT;                   // 18
};
struct STRATEGY_EXPORT DiscretionInst
{
    static const char RELATED_TO_DISPLAYED_PRICE;     // '0'
    static const char RELATED_TO_MARKET_PRICE;        // '1'
    static const char RELATED_TO_PRIMARY_PRICE;       // '2'
    static const char RELATED_TO_LOCAL_PRIMARY_PRICE; // '3'
    static const char RELATED_TO_MIDPOINT_PRICE;      // '4'
    static const char RELATED_TO_LAST_TRADE_PRICE;    // '5'
    static const char RELATED_TO_VWAP;                // '6'
    static const char AVERAGE_PRICE_GUARANTEE;        // '7'
};
struct STRATEGY_EXPORT BidType
{
    static const int NON_DISCLOSED_STYLE; // 1
    static const int DISCLOSED_SYTLE;     // 2
    static const int NO_BIDDING_PROCESS;  // 3
};
struct STRATEGY_EXPORT BidDescriptorType
{
    static const int SECTOR;  // 1
    static const int COUNTRY; // 2
    static const int INDEX;   // 3
};
struct STRATEGY_EXPORT SideValueInd
{
    static const int SIDE_VALUE_1; // 1
    static const int SIDE_VALUE_2; // 2
};
struct STRATEGY_EXPORT LiquidityIndType
{
    static const int FIVEDAY_DAY_MOVING_AVERAGE;   // 1
    static const int TWENTYDAY_DAY_MOVING_AVERAGE; // 2
    static const int NORMAL_MARKET_SIZE;           // 3
    static const int OTHER;                        // 4
};
struct STRATEGY_EXPORT ProgRptReqs
{
    static const int BUY_SIDE_EXPLICITLY_REQUESTS_STATUS_USING_STATUE_REQUEST;                                            // 1
    static const int SELL_SIDE_PERIODICALLY_SENDS_STATUS_USING_LIST_STATUS_PERIOD_OPTIONALLY_SPECIFIED_IN_PROGRESSPERIOD; // 2
    static const int REAL_TIME_EXECUTION_REPORTS;                                                                         // 3
};
struct STRATEGY_EXPORT IncTaxInd
{
    static const int NET;   // 1
    static const int GROSS; // 2
};
struct STRATEGY_EXPORT BidTradeType
{
    static const char AGENCY;           // 'A'
    static const char VWAP_GUARANTEE;   // 'G'
    static const char GUARANTEED_CLOSE; // 'J'
    static const char RISK_TRADE;       // 'R'
};
struct STRATEGY_EXPORT BasisPxType
{
    static const char CLOSING_PRICE_AT_MORNING_SESSION;              // '2'
    static const char CLOSING_PRICE;                                 // '3'
    static const char CURRENT_PRICE;                                 // '4'
    static const char SQ;                                            // '5'
    static const char VWAP_THROUGH_A_DAY;                            // '6'
    static const char VWAP_THROUGH_A_MORNING_SESSION;                // '7'
    static const char VWAP_THROUGH_AN_AFTERNOON_SESSION;             // '8'
    static const char VWAP_THROUGH_A_DAY_EXCEPT_YORI;                // '9'
    static const char VWAP_THROUGH_A_MORNING_SESSION_EXCEPT_YORI;    // 'A'
    static const char VWAP_THROUGH_AN_AFTERNOON_SESSION_EXCEPT_YORI; // 'B'
    static const char STRIKE;                                        // 'C'
    static const char OPEN;                                          // 'D'
    static const char OTHERS;                                        // 'Z'
};
struct STRATEGY_EXPORT PriceType
{
    static const int PERCENTAGE;                         // 1
    static const int PER_UNIT;                           // 2
    static const int FIXED_AMOUNT;                       // 3
    static const int DISCOUNT;                           // 4
    static const int PREMIUM;                            // 5
    static const int SPREAD;                             // 6
    static const int TED_PRICE;                          // 7
    static const int TED_YIELD;                          // 8
    static const int YIELD;                              // 9
    static const int FIXED_CABINET_TRADE_PRICE;          // 10
    static const int VARIABLE_CABINET_TRADE_PRICE;       // 11
    static const int PRODUCT_TICKS_IN_HALFS;             // 13
    static const int PRODUCT_TICKS_IN_FOURTHS;           // 14
    static const int PRODUCT_TICKS_IN_EIGHTS;            // 15
    static const int PRODUCT_TICKS_IN_SIXTEENTHS;        // 16
    static const int PRODUCT_TICKS_IN_THIRTY_SECONDS;    // 17
    static const int PRODUCT_TICKS_IN_SIXTY_FORTHS;      // 18
    static const int PRODUCT_TICKS_IN_ONE_TWENTY_EIGHTS; // 19
};
struct STRATEGY_EXPORT GTBookingInst
{
    static const int BOOK_OUT_ALL_TRADES_ON_DAY_OF_EXECUTION;                 // 0
    static const int ACCUMULATE_EXECTUIONS_UNTIL_FORDER_IS_FILLED_OR_EXPIRES; // 1
    static const int ACCUMULATE_UNTIL_VERBALLLY_NOTIFIED_OTHERWISE;           // 2
};
struct STRATEGY_EXPORT ListStatusType
{
    static const int ACK;          // 1
    static const int RESPONSE;     // 2
    static const int TIMED;        // 3
    static const int EXEC_STARTED; // 4
    static const int ALL_DONE;     // 5
    static const int ALERT;        // 6
};
struct STRATEGY_EXPORT NetGrossInd
{
    static const int NET;   // 1
    static const int GROSS; // 2
};
struct STRATEGY_EXPORT ListOrderStatus
{
    static const int IN_BIDDING_PROCESS;     // 1
    static const int RECEIVED_FOR_EXECUTION; // 2
    static const int EXECUTING;              // 3
    static const int CANCELLING;             // 4
    static const int ALERT;                  // 5
    static const int ALL_DONE;               // 6
    static const int REJECT;                 // 7
};
struct STRATEGY_EXPORT ListExecInstType
{
    static const char IMMEDIATE;                   // '1'
    static const char WAIT_FOR_EXECUT_INSTRUCTION; // '2'
    static const char EXCHANGE_SWITCH_CIV_ORDER_3; // '3'
    static const char EXCHANGE_SWITCH_CIV_ORDER_4; // '4'
    static const char EXCHANGE_SWITCH_CIV_ORDER_5; // '5'
};
struct STRATEGY_EXPORT CxlRejResponseTo
{
    static const char ORDER_CANCEL_REQUEST;         // '1'
    static const char ORDER_CANCEL_REPLACE_REQUEST; // '2'
};
struct STRATEGY_EXPORT MultiLegReportingType
{
    static const char SINGLE_SECURITY;                        // '1'
    static const char INDIVIDUAL_LEG_OF_A_MULTI_LEG_SECURITY; // '2'
    static const char MULTI_LEG_SECURITY;                     // '3'
};
struct STRATEGY_EXPORT PartyIDSource
{
    static const char UK_NATIONAL_INSURANCE_OR_PENSION_NUMBER;                                                           // '6'
    static const char US_SOCIAL_SECURITY_NUMBER;                                                                         // '7'
    static const char US_EMPLOYER_OR_TAX_ID_NUMBER;                                                                      // '8'
    static const char AUSTRALIAN_BUSINESS_NUMBER;                                                                        // '9'
    static const char AUSTRALIAN_TAX_FILE_NUMBER;                                                                        // 'A'
    static const char KOREAN_INVESTOR_ID;                                                                                // '1'
    static const char TAIWANESE_QUALIFIED_FOREIGN_INVESTOR_ID_QFII_FID;                                                  // '2'
    static const char TAIWANESE_TRADING_ACCT;                                                                            // '3'
    static const char MALAYSIAN_CENTRAL_DEPOSITORY;                                                                      // '4'
    static const char CHINESE_INVESTOR_ID;                                                                               // '5'
    static const char DIRECTED_BROKER_THREE_CHARACTER_ACRONYM_AS_DEFINED_IN_ISITC_ETC_BEST_PRACTICE_GUIDELINES_DOCUMENT; // 'I'
    static const char BIC;                                                                                               // 'B'
    static const char GENERALLY_ACCEPTED_MARKET_PARTICIPANT_IDENTIFIER;                                                  // 'C'
    static const char PROPRIETARY;                                                                                       // 'D'
    static const char ISO_COUNTRY_CODE;                                                                                  // 'E'
    static const char SETTLEMENT_ENTITY_LOCATION;                                                                        // 'F'
    static const char MIC;                                                                                               // 'G'
    static const char CSD_PARTICIPANT_MEMBER_CODE;                                                                       // 'H'
};
struct STRATEGY_EXPORT PartyRole
{
    static const int EXECUTING_FIRM;                                                        // 1
    static const int BROKER_OF_CREDIT;                                                      // 2
    static const int CLIENT_ID;                                                             // 3
    static const int CLEARING_FIRM;                                                         // 4
    static const int INVESTOR_ID;                                                           // 5
    static const int INTRODUCING_FIRM;                                                      // 6
    static const int ENTERING_FIRM;                                                         // 7
    static const int LOCATE;                                                                // 8
    static const int FUND_MANAGER_CLIENT_ID;                                                // 9
    static const int SETTLEMENT_LOCATION;                                                   // 10
    static const int ORDER_ORIGINATION_TRADER;                                              // 11
    static const int EXECUTING_TRADER;                                                      // 12
    static const int ORDER_ORIGINATION_FIRM;                                                // 13
    static const int GIVEUP_CLEARING_FIRM;                                                  // 14
    static const int CORRESPONDANT_CLEARING_FIRM;                                           // 15
    static const int EXECUTING_SYSTEM;                                                      // 16
    static const int CONTRA_FIRM;                                                           // 17
    static const int CONTRA_CLEARING_FIRM;                                                  // 18
    static const int SPONSORING_FIRM;                                                       // 19
    static const int UNDERLYING_CONTRA_FIRM;                                                // 20
    static const int CLEARING_ORGANIZATION;                                                 // 21
    static const int EXCHANGE;                                                              // 22
    static const int CUSTOMER_ACCOUNT;                                                      // 24
    static const int CORRESPONDENT_CLEARING_ORGANIZATION;                                   // 25
    static const int CORRESPONDENT_BROKER;                                                  // 26
    static const int BUYER_SELLER;                                                          // 27
    static const int CUSTODIAN;                                                             // 28
    static const int INTERMEDIARY;                                                          // 29
    static const int AGENT;                                                                 // 30
    static const int SUB_CUSTODIAN;                                                         // 31
    static const int BENEFICIARY;                                                           // 32
    static const int INTERESTED_PARTY;                                                      // 33
    static const int REGULATORY_BODY;                                                       // 34
    static const int LIQUIDITY_PROVIDER;                                                    // 35
    static const int ENTERING_TRADER;                                                       // 36
    static const int CONTRA_TRADER;                                                         // 37
    static const int POSITION_ACCOUNT;                                                      // 38
    static const int CONTRA_INVESTOR_ID;                                                    // 39
    static const int TRANSFER_TO_FIRM;                                                      // 40
    static const int CONTRA_POSITION_ACCOUNT;                                               // 41
    static const int CONTRA_EXCHANGE;                                                       // 42
    static const int INTERNAL_CARRY_ACCOUNT;                                                // 43
    static const int ORDER_ENTRY_OPERATOR_ID;                                               // 44
    static const int SECONDARY_ACCOUNT_NUMBER;                                              // 45
    static const int FOREIGN_FIRM;                                                          // 46
    static const int THIRD_PARTY_ALLOCATION_FIRM;                                           // 47
    static const int CLAIMING_ACCOUNT;                                                      // 48
    static const int ASSET_MANAGER;                                                         // 49
    static const int PLEDGOR_ACCOUNT;                                                       // 50
    static const int PLEDGEE_ACCOUNT;                                                       // 51
    static const int LARGE_TRADER_REPORTABLE_ACCOUNT;                                       // 52
    static const int TRADER_MNEMONIC;                                                       // 53
    static const int SENDER_LOCATION;                                                       // 54
    static const int SESSION_ID;                                                            // 55
    static const int ACCEPTABLE_COUNTERPARTY;                                               // 56
    static const int UNACCEPTABLE_COUNTERPARTY;                                             // 57
    static const int ENTERING_UNIT;                                                         // 58
    static const int EXECUTING_UNIT;                                                        // 59
    static const int INTRODUCING_BROKER;                                                    // 60
    static const int QUOTE_ORIGINATOR;                                                      // 61
    static const int REPORT_ORIGINATOR;                                                     // 62
    static const int SYSTEMATIC_INTERNALISER;                                               // 63
    static const int MULTILATERAL_TRADING_FACILITY;                                         // 64
    static const int REGULATED_MARKET;                                                      // 65
    static const int MARKET_MAKER;                                                          // 66
    static const int INVESTMENT_FIRM;                                                       // 67
    static const int HOST_COMPETENT_AUTHORITY;                                              // 68
    static const int HOME_COMPETENT_AUTHORITY;                                              // 69
    static const int COMPETENT_AUTHORITY_OF_THE_MOST_RELEVANT_MARKET_IN_TERMS_OF_LIQUIDITY; // 70
    static const int COMPETENT_AUTHORITY_OF_THE_TRANSACTION;                                // 71
    static const int REPORTING_INTERMEDIARY;                                                // 72
    static const int EXECUTION_VENUE;                                                       // 73
    static const int MARKET_DATA_ENTRY_ORIGINATOR;                                          // 74
    static const int LOCATION_ID;                                                           // 75
    static const int DESK_ID;                                                               // 76
    static const int MARKET_DATA_MARKET;                                                    // 77
    static const int ALLOCATION_ENTITY;                                                     // 78
    static const int PRIME_BROKER_PROVIDING_GENERAL_TRADE_SERVICES;                         // 79
    static const int STEP_OUT_FIRM;                                                         // 80
    static const int BROKERCLEARINGID;                                                      // 81
    static const int CENTRAL_REGISTRATION_DEPOSITORY;                                       // 82
    static const int CLEARING_ACCOUNT;                                                      // 83
    static const int ACCEPTABLE_SETTLING_COUNTERPARTY;                                      // 84
    static const int UNACCEPTABLE_SETTLING_COUNTERPARTY;                                    // 85
};
struct STRATEGY_EXPORT Product
{
    static const int AGENCY;      // 1
    static const int COMMODITY;   // 2
    static const int CORPORATE;   // 3
    static const int CURRENCY;    // 4
    static const int EQUITY;      // 5
    static const int GOVERNMENT;  // 6
    static const int INDEX;       // 7
    static const int LOAN;        // 8
    static const int MONEYMARKET; // 9
    static const int MORTGAGE;    // 10
    static const int MUNICIPAL;   // 11
    static const int OTHER;       // 12
    static const int FINANCING;   // 13
};
struct STRATEGY_EXPORT RoundingDirection
{
    static const char ROUND_TO_NEAREST; // '0'
    static const char ROUND_DOWN;       // '1'
    static const char ROUND_UP;         // '2'
};
struct STRATEGY_EXPORT DistribPaymentMethod
{
    static const int CREST;                            // 1
    static const int NSCC;                             // 2
    static const int EUROCLEAR;                        // 3
    static const int CLEARSTREAM;                      // 4
    static const int CHEQUE;                           // 5
    static const int TELEGRAPHIC_TRANSFER;             // 6
    static const int FED_WIRE;                         // 7
    static const int DIRECT_CREDIT;                    // 8
    static const int ACH_CREDIT;                       // 9
    static const int BPAY;                             // 10
    static const int HIGH_VALUE_CLEARING_SYSTEM_HVACS; // 11
    static const int REINVEST_IN_FUND;                 // 12
};
struct STRATEGY_EXPORT CancellationRights
{
    static const char YES;  // 'Y'
    static const char NO_N; // 'N'
    static const char NO_M; // 'M'
    static const char NO_O; // 'O'
};
struct STRATEGY_EXPORT MoneyLaunderingStatus
{
    static const char PASSED;      // 'Y'
    static const char NOT_CHECKED; // 'N'
    static const char EXEMPT_1;    // '1'
    static const char EXEMPT_2;    // '2'
    static const char EXEMPT_3;    // '3'
};
struct STRATEGY_EXPORT ExecPriceType
{
    static const char BID_PRICE;                              // 'B'
    static const char CREATION_PRICE;                         // 'C'
    static const char CREATION_PRICE_PLUS_ADJUSTMENT_PERCENT; // 'D'
    static const char CREATION_PRICE_PLUS_ADJUSTMENT_AMOUNT;  // 'E'
    static const char OFFER_PRICE;                            // 'O'
    static const char OFFER_PRICE_MINUS_ADJUSTMENT_PERCENT;   // 'P'
    static const char OFFER_PRICE_MINUS_ADJUSTMENT_AMOUNT;    // 'Q'
    static const char SINGLE_PRICE;                           // 'S'
};
struct STRATEGY_EXPORT TradeReportTransType
{
    static const int NEW;                             // 0
    static const int CANCEL;                          // 1
    static const int REPLACE;                         // 2
    static const int RELEASE;                         // 3
    static const int REVERSE;                         // 4
    static const int CANCEL_DUE_TO_BACK_OUT_OF_TRADE; // 5
};
struct STRATEGY_EXPORT PaymentMethod
{
    static const int CREST;                      // 1
    static const int NSCC;                       // 2
    static const int EUROCLEAR;                  // 3
    static const int CLEARSTREAM;                // 4
    static const int CHEQUE;                     // 5
    static const int TELEGRAPHIC_TRANSFER;       // 6
    static const int FED_WIRE;                   // 7
    static const int DEBIT_CARD;                 // 8
    static const int DIRECT_DEBIT;               // 9
    static const int DIRECT_CREDIT;              // 10
    static const int CREDIT_CARD;                // 11
    static const int ACH_DEBIT;                  // 12
    static const int ACH_CREDIT;                 // 13
    static const int BPAY;                       // 14
    static const int HIGH_VALUE_CLEARING_SYSTEM; // 15
};
struct STRATEGY_EXPORT TaxAdvantageType
{
    static const int NONE_NOT_APPLICABLE;              // 0
    static const int MAXI_ISA;                         // 1
    static const int TESSA;                            // 2
    static const int MINI_CASH_ISA;                    // 3
    static const int MINI_STOCKS_AND_SHARES_ISA;       // 4
    static const int MINI_INSURANCE_ISA;               // 5
    static const int CURRENT_YEAR_PAYMENT;             // 6
    static const int PRIOR_YEAR_PAYMENT;               // 7
    static const int ASSET_TRANSFER;                   // 8
    static const int EMPLOYEE_9;                       // 9
    static const int EMPLOYEE_10;                      // 10
    static const int EMPLOYER_11;                      // 11
    static const int EMPLOYER_12;                      // 12
    static const int NON_FUND_PROTOTYPE_IRA;           // 13
    static const int NON_FUND_QUALIFIED_PLAN;          // 14
    static const int DEFINED_CONTRIBUTION_PLAN;        // 15
    static const int INDIVIDUAL_RETIREMENT_ACCOUNT_16; // 16
    static const int INDIVIDUAL_RETIREMENT_ACCOUNT_17; // 17
    static const int KEOGH;                            // 18
    static const int PROFIT_SHARING_PLAN;              // 19
    static const int TAX_401;                          // 20
    static const int SELF_DIRECTED_IRA;                // 21
    static const int TAX_403;                          // 22
    static const int TAX_457;                          // 23
    static const int ROTH_IRA_24;                      // 24
    static const int ROTH_IRA_25;                      // 25
    static const int ROTH_CONVERSION_IRA_26;           // 26
    static const int ROTH_CONVERSION_IRA_27;           // 27
    static const int EDUCATION_IRA_28;                 // 28
    static const int EDUCATION_IRA_29;                 // 29
    static const int OTHER;                            // 999
};
struct STRATEGY_EXPORT FundRenewWaiv
{
    static const char NO;  // 'N'
    static const char YES; // 'Y'
};
struct STRATEGY_EXPORT RegistStatus
{
    static const char ACCEPTED; // 'A'
    static const char REJECTED; // 'R'
    static const char HELD;     // 'H'
    static const char REMINDER; // 'N'
};
struct STRATEGY_EXPORT RegistRejReasonCode
{
    static const int INVALID_UNACCEPTABLE_ACCOUNT_TYPE;                  // 1
    static const int INVALID_UNACCEPTABLE_TAX_EXEMPT_TYPE;               // 2
    static const int INVALID_UNACCEPTABLE_OWNERSHIP_TYPE;                // 3
    static const int INVALID_UNACCEPTABLE_NO_REG_DETAILS;                // 4
    static const int INVALID_UNACCEPTABLE_REG_SEQ_NO;                    // 5
    static const int INVALID_UNACCEPTABLE_REG_DETAILS;                   // 6
    static const int INVALID_UNACCEPTABLE_MAILING_DETAILS;               // 7
    static const int INVALID_UNACCEPTABLE_MAILING_INSTRUCTIONS;          // 8
    static const int INVALID_UNACCEPTABLE_INVESTOR_ID;                   // 9
    static const int INVALID_UNACEEPTABLE_INVESTOR_ID_SOURCE;            // 10
    static const int INVALID_UNACCEPTABLE_DATE_OF_BIRTH;                 // 11
    static const int INVALID_UNACCEPTABLE_INVESTOR_COUNTRY_OF_RESIDENCE; // 12
    static const int INVALID_UNACCEPTABLE_NO_DISTRIB_INSTNS;             // 13
    static const int INVALID_UNACCEPTABLE_DISTRIB_PERCENTAGE;            // 14
    static const int INVALID_UNACCEPTABLE_DISTRIB_PAYMENT_METHOD;        // 15
    static const int INVALID_UNACCEPTABLE_CASH_DISTRIB_AGENT_ACCT_NAME;  // 16
    static const int INVALID_UNACCEPTABLE_CASH_DISTRIB_AGENT_CODE;       // 17
    static const int INVALID_UNACCEPTABLE_CASH_DISTRIB_AGENT_ACCT_NUM;   // 18
    static const int OTHER;                                              // 99
};
struct STRATEGY_EXPORT RegistTransType
{
    static const char NEW;     // '0'
    static const char CANCEL;  // '2'
    static const char REPLACE; // '1'
};
struct STRATEGY_EXPORT OwnershipType
{
    static const char JOINT_INVESTORS;   // 'J'
    static const char TENANTS_IN_COMMON; // 'T'
    static const char JOINT_TRUSTEES;    // '2'
};
struct STRATEGY_EXPORT ContAmtType
{
    static const int COMMISSION_AMOUNT;                       // 1
    static const int COMMISSION_PERCENT;                      // 2
    static const int INITIAL_CHARGE_AMOUNT;                   // 3
    static const int INITIAL_CHARGE_PERCENT;                  // 4
    static const int DISCOUNT_AMOUNT;                         // 5
    static const int DISCOUNT_PERCENT;                        // 6
    static const int DILUTION_LEVY_AMOUNT;                    // 7
    static const int DILUTION_LEVY_PERCENT;                   // 8
    static const int EXIT_CHARGE_AMOUNT;                      // 9
    static const int EXIT_CHARGE_PERCENT;                     // 10
    static const int FUND_BASED_RENEWAL_COMMISSION_PERCENT;   // 11
    static const int PROJECTED_FUND_VALUE;                    // 12
    static const int FUND_BASED_RENEWAL_COMMISSION_AMOUNT_13; // 13
    static const int FUND_BASED_RENEWAL_COMMISSION_AMOUNT_14; // 14
    static const int NET_SETTLEMENT_AMOUNT;                   // 15
};
struct STRATEGY_EXPORT OwnerType
{
    static const int INDIVIDUAL_INVESTOR;                 // 1
    static const int PUBLIC_COMPANY;                      // 2
    static const int PRIVATE_COMPANY;                     // 3
    static const int INDIVIDUAL_TRUSTEE;                  // 4
    static const int COMPANY_TRUSTEE;                     // 5
    static const int PENSION_PLAN;                        // 6
    static const int CUSTODIAN_UNDER_GIFTS_TO_MINORS_ACT; // 7
    static const int TRUSTS;                              // 8
    static const int FIDUCIARIES;                         // 9
    static const int NETWORKING_SUB_ACCOUNT;              // 10
    static const int NON_PROFIT_ORGANIZATION;             // 11
    static const int CORPORATE_BODY;                      // 12
    static const int NOMINEE;                             // 13
};
struct STRATEGY_EXPORT OrderCapacity
{
    static const char AGENCY;                 // 'A'
    static const char PROPRIETARY;            // 'G'
    static const char INDIVIDUAL;             // 'I'
    static const char PRINCIPAL;              // 'P'
    static const char RISKLESS_PRINCIPAL;     // 'R'
    static const char AGENT_FOR_OTHER_MEMBER; // 'W'
};
struct STRATEGY_EXPORT MassCancelRequestType
{
    static const char CANCEL_ORDERS_FOR_A_SECURITY;             // '1'
    static const char CANCEL_ORDERS_FOR_AN_UNDERLYING_SECURITY; // '2'
    static const char CANCEL_ORDERS_FOR_A_PRODUCT;              // '3'
    static const char CANCEL_ORDERS_FOR_A_CFICODE;              // '4'
    static const char CANCEL_ORDERS_FOR_A_SECURITYTYPE;         // '5'
    static const char CANCEL_ORDERS_FOR_A_TRADING_SESSION;      // '6'
    static const char CANCEL_ALL_ORDERS;                        // '7'
    static const char CANCEL_ORDERS_FOR_A_MARKET;               // '8'
    static const char CANCEL_ORDERS_FOR_A_MARKET_SEGMENT;       // '9'
    static const char CANCEL_ORDERS_FOR_A_SECURITY_GROUP;       // 'A'
    static const char CANCEL_FOR_SECURITY_ISSUER;               // 'B'
    static const char CANCEL_FOR_ISSUER_OF_UNDERLYING_SECURITY; // 'C'
};
struct STRATEGY_EXPORT MassCancelResponse
{
    static const char CANCEL_REQUEST_REJECTED;                         // '0'
    static const char CANCEL_ORDERS_FOR_A_SECURITY;                    // '1'
    static const char CANCEL_ORDERS_FOR_AN_UNDERLYING_SECURITY;        // '2'
    static const char CANCEL_ORDERS_FOR_A_PRODUCT;                     // '3'
    static const char CANCEL_ORDERS_FOR_A_CFICODE;                     // '4'
    static const char CANCEL_ORDERS_FOR_A_SECURITYTYPE;                // '5'
    static const char CANCEL_ORDERS_FOR_A_TRADING_SESSION;             // '6'
    static const char CANCEL_ALL_ORDERS;                               // '7'
    static const char CANCEL_ORDERS_FOR_A_MARKET;                      // '8'
    static const char CANCEL_ORDERS_FOR_A_MARKET_SEGMENT;              // '9'
    static const char CANCEL_ORDERS_FOR_A_SECURITY_GROUP;              // 'A'
    static const char CANCEL_ORDERS_FOR_A_SECURITIES_ISSUER;           // 'B'
    static const char CANCEL_ORDERS_FOR_ISSUER_OF_UNDERLYING_SECURITY; // 'C'
};
struct STRATEGY_EXPORT MassCancelRejectReason
{
    static const int MASS_CANCEL_NOT_SUPPORTED;                        // 0
    static const int INVALID_OR_UNKNOWN_SECURITY;                      // 1
    static const int INVALID_OR_UNKOWN_UNDERLYING_SECURITY;            // 2
    static const int INVALID_OR_UNKNOWN_PRODUCT;                       // 3
    static const int INVALID_OR_UNKNOWN_CFICODE;                       // 4
    static const int INVALID_OR_UNKNOWN_SECURITYTYPE;                  // 5
    static const int INVALID_OR_UNKNOWN_TRADING_SESSION;               // 6
    static const int INVALID_OR_UNKNOWN_MARKET;                        // 7
    static const int INVALID_OR_UNKOWN_MARKET_SEGMENT;                 // 8
    static const int INVALID_OR_UNKNOWN_SECURITY_GROUP;                // 9
    static const int OTHER;                                            // 99
    static const int INVALID_OR_UNKNOWN_SECURITY_ISSUER;               // 10
    static const int INVALID_OR_UNKNOWN_ISSUER_OF_UNDERLYING_SECURITY; // 11
};
struct STRATEGY_EXPORT QuoteType
{
    static const int INDICATIVE;           // 0
    static const int TRADEABLE;            // 1
    static const int RESTRICTED_TRADEABLE; // 2
    static const int COUNTER;              // 3
};
struct STRATEGY_EXPORT CashMargin
{
    static const char CASH;         // '1'
    static const char MARGIN_OPEN;  // '2'
    static const char MARGIN_CLOSE; // '3'
};
struct STRATEGY_EXPORT CrossType
{
    static const int CROSS_AON;        // 1
    static const int CROSS_IOC;        // 2
    static const int CROSS_ONE_SIDE;   // 3
    static const int CROSS_SAME_PRICE; // 4
};
struct STRATEGY_EXPORT CrossPrioritization
{
    static const int NONE;                     // 0
    static const int BUY_SIDE_IS_PRIORITIZED;  // 1
    static const int SELL_SIDE_IS_PRIORITIZED; // 2
};
struct STRATEGY_EXPORT SecurityListRequestType
{
    static const int SYMBOL;                                    // 0
    static const int SECURITYTYPE_AND_OR_CFICODE;               // 1
    static const int PRODUCT;                                   // 2
    static const int TRADINGSESSIONID;                          // 3
    static const int ALL_SECURITIES;                            // 4
    static const int MARKETID_OR_MARKETID_PLUS_MARKETSEGMENTID; // 5
    static const int SHORT_NAME;                                // 10
    static const int GROUP_ID;                                  // 11
    static const int GROUP_NAME;                                // 111
};
struct STRATEGY_EXPORT SecurityRequestResult
{
    static const int VALID_REQUEST;                                      // 0
    static const int INVALID_OR_UNSUPPORTED_REQUEST;                     // 1
    static const int NO_INSTRUMENTS_FOUND_THAT_MATCH_SELECTION_CRITERIA; // 2
    static const int NOT_AUTHORIZED_TO_RETRIEVE_INSTRUMENT_DATA;         // 3
    static const int INSTRUMENT_DATA_TEMPORARILY_UNAVAILABLE;            // 4
    static const int REQUEST_FOR_INSTRUMENT_DATA_NOT_SUPPORTED;          // 5
};
struct STRATEGY_EXPORT MultiLegRptTypeReq
{
    static const int REPORT_BY_MULITLEG_SECURITY_ONLY;                                                      // 0
    static const int REPORT_BY_MULTILEG_SECURITY_AND_BY_INSTRUMENT_LEGS_BELONGING_TO_THE_MULTILEG_SECURITY; // 1
    static const int REPORT_BY_INSTRUMENT_LEGS_BELONGING_TO_THE_MULTILEG_SECURITY_ONLY;                     // 2
};
struct STRATEGY_EXPORT TradSesStatusRejReason
{
    static const int UNKNOWN_OR_INVALID_TRADINGSESSIONID; // 1
    static const int OTHER;                               // 99
};
struct STRATEGY_EXPORT TradeRequestType
{
    static const int ALL_TRADES;                                           // 0
    static const int MATCHED_TRADES_MATCHING_CRITERIA_PROVIDED_ON_REQUEST; // 1
    static const int UNMATCHED_TRADES_THAT_MATCH_CRITERIA;                 // 2
    static const int UNREPORTED_TRADES_THAT_MATCH_CRITERIA;                // 3
    static const int ADVISORIES_THAT_MATCH_CRITERIA;                       // 4
};
struct STRATEGY_EXPORT MatchStatus
{
    static const char COMPARED_MATCHED_OR_AFFIRMED;       // '0'
    static const char UNCOMPARED_UNMATCHED_OR_UNAFFIRMED; // '1'
    static const char ADVISORY_OR_ALERT;                  // '2'
};
struct STRATEGY_EXPORT ClearingInstruction
{
    static const int PROCESS_NORMALLY;                     // 0
    static const int EXCLUDE_FROM_ALL_NETTING;             // 1
    static const int BILATERAL_NETTING_ONLY;               // 2
    static const int EX_CLEARING;                          // 3
    static const int SPECIAL_TRADE;                        // 4
    static const int MULTILATERAL_NETTING;                 // 5
    static const int CLEAR_AGAINST_CENTRAL_COUNTERPARTY;   // 6
    static const int EXCLUDE_FROM_CENTRAL_COUNTERPARTY;    // 7
    static const int MANUAL_MODE;                          // 8
    static const int AUTOMATIC_POSTING_MODE;               // 9
    static const int AUTOMATIC_GIVE_UP_MODE;               // 10
    static const int QUALIFIED_SERVICE_REPRESENTATIVE_QSR; // 11
    static const int CUSTOMER_TRADE;                       // 12
    static const int SELF_CLEARING;                        // 13
};
struct STRATEGY_EXPORT AccountType
{
    static const int ACCOUNT_IS_CARRIED_ON_CUSTOMER_SIDE_OF_THE_BOOKS;                       // 1
    static const int ACCOUNT_IS_CARRIED_ON_NON_CUSTOMER_SIDE_OF_BOOKS;                       // 2
    static const int HOUSE_TRADER;                                                           // 3
    static const int FLOOR_TRADER;                                                           // 4
    static const int ACCOUNT_IS_CARRIED_ON_NON_CUSTOMER_SIDE_OF_BOOKS_AND_IS_CROSS_MARGINED; // 6
    static const int ACCOUNT_IS_HOUSE_TRADER_AND_IS_CROSS_MARGINED;                          // 7
    static const int JOINT_BACK_OFFICE_ACCOUNT;                                              // 8
};
struct STRATEGY_EXPORT CustOrderCapacity
{
    static const int MEMBER_TRADING_FOR_THEIR_OWN_ACCOUNT;              // 1
    static const int CLEARING_FIRM_TRADING_FOR_ITS_PROPRIETARY_ACCOUNT; // 2
    static const int MEMBER_TRADING_FOR_ANOTHER_MEMBER;                 // 3
    static const int ALL_OTHER;                                         // 4
};
struct STRATEGY_EXPORT MassStatusReqType
{
    static const int STATUS_FOR_ORDERS_FOR_A_SECURITY;             // 1
    static const int STATUS_FOR_ORDERS_FOR_AN_UNDERLYING_SECURITY; // 2
    static const int STATUS_FOR_ORDERS_FOR_A_PRODUCT;              // 3
    static const int STATUS_FOR_ORDERS_FOR_A_CFICODE;              // 4
    static const int STATUS_FOR_ORDERS_FOR_A_SECURITYTYPE;         // 5
    static const int STATUS_FOR_ORDERS_FOR_A_TRADING_SESSION;      // 6
    static const int STATUS_FOR_ALL_ORDERS;                        // 7
    static const int STATUS_FOR_ORDERS_FOR_A_PARTYID;              // 8
    static const int STATUS_FOR_SECURITY_ISSUER;                   // 9
    static const int STATUS_FOR_ISSUER_OF_UNDERLYING_SECURITY;     // 10
};
struct STRATEGY_EXPORT DayBookingInst
{
    static const char CAN_TRIGGER_BOOKING_WITHOUT_REFERENCE_TO_THE_ORDER_INITIATOR; // '0'
    static const char SPEAK_WITH_ORDER_INITIATOR_BEFORE_BOOKING;                    // '1'
    static const char ACCUMULATE;                                                   // '2'
};
struct STRATEGY_EXPORT BookingUnit
{
    static const char EACH_PARTIAL_EXECUTION_IS_A_BOOKABLE_UNIT;                               // '0'
    static const char AGGREGATE_PARTIAL_EXECUTIONS_ON_THIS_ORDER_AND_BOOK_ONE_TRADE_PER_ORDER; // '1'
    static const char AGGREGATE_EXECUTIONS_FOR_THIS_SYMBOL_SIDE_AND_SETTLEMENT_DATE;           // '2'
};
struct STRATEGY_EXPORT PreallocMethod
{
    static const char PRO_RATA;        // '0'
    static const char DO_NOT_PRO_RATA; // '1'
};
struct STRATEGY_EXPORT AllocType
{
    static const int CALCULATED;                              // 1
    static const int PRELIMINARY;                             // 2
    static const int SELLSIDE_CALCULATED_USING_PRELIMINARY;   // 3
    static const int SELLSIDE_CALCULATED_WITHOUT_PRELIMINARY; // 4
    static const int READY_TO_BOOK;                           // 5
    static const int BUYSIDE_READY_TO_BOOK;                   // 6
    static const int WAREHOUSE_INSTRUCTION;                   // 7
    static const int REQUEST_TO_INTERMEDIARY;                 // 8
    static const int ACCEPT;                                  // 9
    static const int REJECT;                                  // 10
    static const int ACCEPT_PENDING;                          // 11
    static const int INCOMPLETE_GROUP;                        // 12
    static const int COMPLETE_GROUP;                          // 13
    static const int REVERSAL_PENDING;                        // 14
};
struct STRATEGY_EXPORT PriorityIndicator
{
    static const int PRIORITY_UNCHANGED;                      // 0
    static const int LOST_PRIORITY_AS_RESULT_OF_ORDER_CHANGE; // 1
};
struct STRATEGY_EXPORT QuoteRequestRejectReason
{
    static const int UNKNOWN_SYMBOL;                  // 1
    static const int EXCHANGE;                        // 2
    static const int QUOTE_REQUEST_EXCEEDS_LIMIT;     // 3
    static const int TOO_LATE_TO_ENTER;               // 4
    static const int INVALID_PRICE;                   // 5
    static const int NOT_AUTHORIZED_TO_REQUEST_QUOTE; // 6
    static const int NO_MATCH_FOR_INQUIRY;            // 7
    static const int NO_MARKET_FOR_INSTRUMENT;        // 8
    static const int NO_INVENTORY;                    // 9
    static const int PASS;                            // 10
    static const int INSUFFICIENT_CREDIT;             // 11
    static const int OTHER;                           // 99
};
struct STRATEGY_EXPORT AcctIDSource
{
    static const int BIC;       // 1
    static const int SID_CODE;  // 2
    static const int TFM;       // 3
    static const int OMGEO;     // 4
    static const int DTCC_CODE; // 5
    static const int OTHER;     // 99
};
struct STRATEGY_EXPORT ConfirmStatus
{
    static const int RECEIVED;                        // 1
    static const int MISMATCHED_ACCOUNT;              // 2
    static const int MISSING_SETTLEMENT_INSTRUCTIONS; // 3
    static const int CONFIRMED;                       // 4
    static const int REQUEST_REJECTED;                // 5
};
struct STRATEGY_EXPORT ConfirmTransType
{
    static const int NEW;     // 0
    static const int REPLACE; // 1
    static const int CANCEL;  // 2
};
struct STRATEGY_EXPORT DeliveryForm
{
    static const int BOOK_ENTRY; // 1
    static const int BEARER;     // 2
};
struct STRATEGY_EXPORT LegSwapType
{
    static const int PAR_FOR_PAR;       // 1
    static const int MODIFIED_DURATION; // 2
    static const int RISK;              // 4
    static const int PROCEEDS;          // 5
};
struct STRATEGY_EXPORT QuotePriceType
{
    static const int PERCENT;      // 1
    static const int PER_SHARE;    // 2
    static const int FIXED_AMOUNT; // 3
    static const int DISCOUNT;     // 4
    static const int PREMIUM;      // 5
    static const int SPREAD;       // 6
    static const int TED_PRICE;    // 7
    static const int TED_YIELD;    // 8
    static const int YIELD_SPREAD; // 9
    static const int YIELD;        // 10
};
struct STRATEGY_EXPORT QuoteRespType
{
    static const int HIT_LIFT;  // 1
    static const int COUNTER;   // 2
    static const int EXPIRED;   // 3
    static const int COVER;     // 4
    static const int DONE_AWAY; // 5
    static const int PASS;      // 6
    static const int END_TRADE; // 7
    static const int TIMED_OUT; // 8
};
struct STRATEGY_EXPORT PosQtyStatus
{
    static const int SUBMITTED; // 0
    static const int ACCEPTED;  // 1
    static const int REJECTED;  // 2
};
struct STRATEGY_EXPORT PosTransType
{
    static const int EXERCISE;                                      // 1
    static const int DO_NOT_EXERCISE;                               // 2
    static const int POSITION_ADJUSTMENT;                           // 3
    static const int POSITION_CHANGE_SUBMISSION_MARGIN_DISPOSITION; // 4
    static const int PLEDGE;                                        // 5
    static const int LARGE_TRADER_SUBMISSION;                       // 6
};
struct STRATEGY_EXPORT PosMaintAction
{
    static const int NEW;     // 1
    static const int REPLACE; // 2
    static const int CANCEL;  // 3
    static const int REVERSE; // 4
};
struct STRATEGY_EXPORT AdjustmentType
{
    static const int PROCESS_REQUEST_AS_MARGIN_DISPOSITION; // 0
    static const int DELTA_PLUS;                            // 1
    static const int DELTA_MINUS;                           // 2
    static const int FINAL;                                 // 3
};
struct STRATEGY_EXPORT PosMaintStatus
{
    static const int ACCEPTED;                // 0
    static const int ACCEPTED_WITH_WARNINGS;  // 1
    static const int REJECTED;                // 2
    static const int COMPLETED;               // 3
    static const int COMPLETED_WITH_WARNINGS; // 4
};
struct STRATEGY_EXPORT PosMaintResult
{
    static const int SUCCESSFUL_COMPLETION; // 0
    static const int REJECTED;              // 1
    static const int OTHER;                 // 99
};
struct STRATEGY_EXPORT PosReqType
{
    static const int POSITIONS;           // 0
    static const int TRADES;              // 1
    static const int EXERCISES;           // 2
    static const int ASSIGNMENTS;         // 3
    static const int SETTLEMENT_ACTIVITY; // 4
    static const int BACKOUT_MESSAGE;     // 5
    static const int DELTA_POSITIONS;     // 6
};
struct STRATEGY_EXPORT ResponseTransportType
{
    static const int INBAND;      // 0
    static const int OUT_OF_BAND; // 1
};
struct STRATEGY_EXPORT PosReqResult
{
    static const int VALID_REQUEST;                          // 0
    static const int INVALID_OR_UNSUPPORTED_REQUEST;         // 1
    static const int NO_POSITIONS_FOUND_THAT_MATCH_CRITERIA; // 2
    static const int NOT_AUTHORIZED_TO_REQUEST_POSITIONS;    // 3
    static const int REQUEST_FOR_POSITION_NOT_SUPPORTED;     // 4
    static const int OTHER;                                  // 99
};
struct STRATEGY_EXPORT PosReqStatus
{
    static const int COMPLETED;               // 0
    static const int COMPLETED_WITH_WARNINGS; // 1
    static const int REJECTED;                // 2
};
struct STRATEGY_EXPORT SettlPriceType
{
    static const int FINAL;       // 1
    static const int THEORETICAL; // 2
};
struct STRATEGY_EXPORT AssignmentMethod
{
    static const char PRO_RATA; // 'P'
    static const char RANDOM;   // 'R'
};
struct STRATEGY_EXPORT ExerciseMethod
{
    static const char AUTOMATIC; // 'A'
    static const char MANUAL;    // 'M'
};
struct STRATEGY_EXPORT TradeRequestResult
{
    static const int SUCCESSFUL;                       // 0
    static const int INVALID_OR_UNKNOWN_INSTRUMENT;    // 1
    static const int INVALID_TYPE_OF_TRADE_REQUESTED;  // 2
    static const int INVALID_PARTIES;                  // 3
    static const int INVALID_TRANSPORT_TYPE_REQUESTED; // 4
    static const int INVALID_DESTINATION_REQUESTED;    // 5
    static const int TRADEREQUESTTYPE_NOT_SUPPORTED;   // 8
    static const int NOT_AUTHORIZED;                   // 9
    static const int OTHER;                            // 99
};
struct STRATEGY_EXPORT TradeRequestStatus
{
    static const int ACCEPTED;  // 0
    static const int COMPLETED; // 1
    static const int REJECTED;  // 2
};
struct STRATEGY_EXPORT TradeReportRejectReason
{
    static const int SUCCESSFUL;                    // 0
    static const int INVALID_PARTY_ONFORMATION;     // 1
    static const int UNKNOWN_INSTRUMENT;            // 2
    static const int UNAUTHORIZED_TO_REPORT_TRADES; // 3
    static const int INVALID_TRADE_TYPE;            // 4
    static const int OTHER;                         // 99
};
struct STRATEGY_EXPORT SideMultiLegReportingType
{
    static const int SINGLE_SECURITY;                       // 1
    static const int INDIVIDUAL_LEG_OF_A_MULTILEG_SECURITY; // 2
    static const int MULTILEG_SECURITY;                     // 3
};
struct STRATEGY_EXPORT TrdRegTimestampType
{
    static const int EXECUTION_TIME;         // 1
    static const int TIME_IN;                // 2
    static const int TIME_OUT;               // 3
    static const int BROKER_RECEIPT;         // 4
    static const int BROKER_EXECUTION;       // 5
    static const int DESK_RECEIPT;           // 6
    static const int SUBMISSION_TO_CLEARING; // 7
};
struct STRATEGY_EXPORT ConfirmType
{
    static const int STATUS;                        // 1
    static const int CONFIRMATION;                  // 2
    static const int CONFIRMATION_REQUEST_REJECTED; // 3
};
struct STRATEGY_EXPORT ConfirmRejReason
{
    static const int MISMATCHED_ACCOUNT;              // 1
    static const int MISSING_SETTLEMENT_INSTRUCTIONS; // 2
    static const int OTHER;                           // 99
};
struct STRATEGY_EXPORT BookingType
{
    static const int REGULAR_BOOKING;   // 0
    static const int CFD;               // 1
    static const int TOTAL_RETURN_SWAP; // 2
};
struct STRATEGY_EXPORT AllocSettlInstType
{
    static const int USE_DEFAULT_INSTRUCTIONS;        // 0
    static const int DERIVE_FROM_PARAMETERS_PROVIDED; // 1
    static const int FULL_DETAILS_PROVIDED;           // 2
    static const int SSI_DB_IDS_PROVIDED;             // 3
    static const int PHONE_FOR_INSTRUCTIONS;          // 4
};
struct STRATEGY_EXPORT DlvyInstType
{
    static const char CASH;       // 'C'
    static const char SECURITIES; // 'S'
};
struct STRATEGY_EXPORT TerminationType
{
    static const int OVERNIGHT; // 1
    static const int TERM;      // 2
    static const int FLEXIBLE;  // 3
    static const int OPEN;      // 4
};
struct STRATEGY_EXPORT SettlInstReqRejCode
{
    static const int UNABLE_TO_PROCESS_REQUEST;                 // 0
    static const int UNKNOWN_ACCOUNT;                           // 1
    static const int NO_MATCHING_SETTLEMENT_INSTRUCTIONS_FOUND; // 2
    static const int OTHER;                                     // 99
};
struct STRATEGY_EXPORT AllocReportType
{
    static const int PRELIMINARY_REQUEST_TO_INTERMEDIARY;     // 2
    static const int SELLSIDE_CALCULATED_USING_PRELIMINARY;   // 3
    static const int SELLSIDE_CALCULATED_WITHOUT_PRELIMINARY; // 4
    static const int WAREHOUSE_RECAP;                         // 5
    static const int REQUEST_TO_INTERMEDIARY;                 // 8
    static const int ACCEPT;                                  // 9
    static const int REJECT;                                  // 10
    static const int ACCEPT_PENDING;                          // 11
    static const int COMPLETE;                                // 12
    static const int REVERSE_PENDING;                         // 14
};
struct STRATEGY_EXPORT AllocCancReplaceReason
{
    static const int ORIGINAL_DETAILS_INCOMPLETE_INCORRECT; // 1
    static const int CHANGE_IN_UNDERLYING_ORDER_DETAILS;    // 2
    static const int OTHER;                                 // 99
};
struct STRATEGY_EXPORT AllocAccountType
{
    static const int ACCOUNT_IS_CARRIED_PN_CUSTOMER_SIDE_OF_BOOKS;                           // 1
    static const int ACCOUNT_IS_CARRIED_ON_NON_CUSTOMER_SIDE_OF_BOOKS;                       // 2
    static const int HOUSE_TRADER;                                                           // 3
    static const int FLOOR_TRADER;                                                           // 4
    static const int ACCOUNT_IS_CARRIED_ON_NON_CUSTOMER_SIDE_OF_BOOKS_AND_IS_CROSS_MARGINED; // 6
    static const int ACCOUNT_IS_HOUSE_TRADER_AND_IS_CROSS_MARGINED;                          // 7
    static const int JOINT_BACK_OFFICE_ACCOUNT;                                              // 8
};
struct STRATEGY_EXPORT PartySubIDType
{
    static const int FIRM;                         // 1
    static const int PERSON;                       // 2
    static const int SYSTEM;                       // 3
    static const int APPLICATION;                  // 4
    static const int FULL_LEGAL_NAME_OF_FIRM;      // 5
    static const int POSTAL_ADDRESS;               // 6
    static const int PHONE_NUMBER;                 // 7
    static const int EMAIL_ADDRESS;                // 8
    static const int CONTACT_NAME;                 // 9
    static const int SECURITIES_ACCOUNT_NUMBER;    // 10
    static const int REGISTRATION_NUMBER;          // 11
    static const int REGISTERED_ADDRESS_12;        // 12
    static const int REGULATORY_STATUS;            // 13
    static const int REGISTRATION_NAME;            // 14
    static const int CASH_ACCOUNT_NUMBER;          // 15
    static const int BIC;                          // 16
    static const int CSD_PARTICIPANT_MEMBER_CODE;  // 17
    static const int REGISTERED_ADDRESS_18;        // 18
    static const int FUND_ACCOUNT_NAME;            // 19
    static const int TELEX_NUMBER;                 // 20
    static const int FAX_NUMBER;                   // 21
    static const int SECURITIES_ACCOUNT_NAME;      // 22
    static const int CASH_ACCOUNT_NAME;            // 23
    static const int DEPARTMENT;                   // 24
    static const int LOCATION_DESK;                // 25
    static const int POSITION_ACCOUNT_TYPE;        // 26
    static const int SECURITY_LOCATE_ID;           // 27
    static const int MARKET_MAKER;                 // 28
    static const int ELIGIBLE_COUNTERPARTY;        // 29
    static const int PROFESSIONAL_CLIENT;          // 30
    static const int LOCATION;                     // 31
    static const int EXECUTION_VENUE;              // 32
    static const int CURRENCY_DELIVERY_IDENTIFIER; // 33
};
struct STRATEGY_EXPORT AllocIntermedReqType
{
    static const int PENDING_ACCEPT;       // 1
    static const int PENDING_RELEASE;      // 2
    static const int PENDING_REVERSAL;     // 3
    static const int ACCEPT;               // 4
    static const int BLOCK_LEVEL_REJECT;   // 5
    static const int ACCOUNT_LEVEL_REJECT; // 6
};
struct STRATEGY_EXPORT ApplQueueResolution
{
    static const int NO_ACTION_TAKEN; // 0
    static const int QUEUE_FLUSHED;   // 1
    static const int OVERLAY_LAST;    // 2
    static const int END_SESSION;     // 3
};
struct STRATEGY_EXPORT ApplQueueAction
{
    static const int NO_ACTION_TAKEN; // 0
    static const int QUEUE_FLUSHED;   // 1
    static const int OVERLAY_LAST;    // 2
    static const int END_SESSION;     // 3
};
struct STRATEGY_EXPORT AvgPxIndicator
{
    static const int NO_AVERAGE_PRICING;                                                    // 0
    static const int TRADE_IS_PART_OF_AN_AVERAGE_PRICE_GROUP_IDENTIFIED_BY_THE_TRADELINKID; // 1
    static const int LAST_TRADE_IS_THE_AVERAGE_PRICE_GROUP_IDENTIFIED_BY_THE_TRADELINKID;   // 2
};
struct STRATEGY_EXPORT TradeAllocIndicator
{
    static const int ALLOCATION_NOT_REQUIRED;                // 0
    static const int ALLOCATION_REQUIRED;                    // 1
    static const int USE_ALLOCATION_PROVIDED_WITH_THE_TRADE; // 2
    static const int ALLOCATION_GIVE_UP_EXECUTOR;            // 3
    static const int ALLOCATION_FROM_EXECUTOR;               // 4
    static const int ALLOCATION_TO_CLAIM_ACCOUNT;            // 5
};
struct STRATEGY_EXPORT ExpirationCycle
{
    static const int EXPIRE_ON_TRADING_SESSION_CLOSE;                                                // 0
    static const int EXPIRE_ON_TRADING_SESSION_OPEN;                                                 // 1
    static const int TRADING_ELIGIBILITY_EXPIRATION_SPECIFIED_IN_THE_DATE_AND_TIME_FIELDS_EVENTDATE; // 2
};
struct STRATEGY_EXPORT TrdType
{
    static const int REGULAR_TRADE;                        // 0
    static const int BLOCK_TRADE_1;                        // 1
    static const int EFP;                                  // 2
    static const int TRANSFER;                             // 3
    static const int LATE_TRADE;                           // 4
    static const int T_TRADE;                              // 5
    static const int WEIGHTED_AVERAGE_PRICE_TRADE;         // 6
    static const int BUNCHED_TRADE;                        // 7
    static const int LATE_BUNCHED_TRADE;                   // 8
    static const int PRIOR_REFERENCE_PRICE_TRADE;          // 9
    static const int AFTER_HOURS_TRADE;                    // 10
    static const int EXCHANGE_FOR_RISK;                    // 11
    static const int EXCHANGE_FOR_SWAP;                    // 12
    static const int EXCHANGE_OF_FUTURES_FOR;              // 13
    static const int EXCHANGE_OF_OPTIONS_FOR_OPTIONS;      // 14
    static const int TRADING_AT_SETTLEMENT;                // 15
    static const int ALL_OR_NONE;                          // 16
    static const int FUTURES_LARGE_ORDER_EXECUTION;        // 17
    static const int EXCHANGE_OF_FUTURES_FOR_FUTURES;      // 18
    static const int OPTION_INTERIM_TRADE;                 // 19
    static const int OPTION_CABINET_TRADE;                 // 20
    static const int PRIVATELY_NEGOTIATED_TRADES;          // 22
    static const int SUBSTITUTION_OF_FUTURES_FOR_FORWARDS; // 23
    static const int NON_STANDARD_SETTLEMENT;              // 48
    static const int DERIVATIVE_RELATED_TRANSACTION;       // 49
    static const int PORTFOLIO_TRADE;                      // 50
    static const int VOLUME_WEIGHTED_AVERAGE_TRADE;        // 51
    static const int EXCHANGE_GRANTED_TRADE;               // 52
    static const int REPURCHASE_AGREEMENT;                 // 53
    static const int OTC;                                  // 54
    static const int EXCHANGE_BASIS_FACILITY;              // 55
    static const int ERROR_TRADE;                          // 24
    static const int SPECIAL_CUM_DIVIDEND;                 // 25
    static const int SPECIAL_EX_DIVIDEND;                  // 26
    static const int SPECIAL_CUM_COUPON;                   // 27
    static const int SPECIAL_EX_COUPON;                    // 28
    static const int CASH_SETTLEMENT;                      // 29
    static const int SPECIAL_PRICE;                        // 30
    static const int GUARANTEED_DELIVERY;                  // 31
    static const int SPECIAL_CUM_RIGHTS;                   // 32
    static const int SPECIAL_EX_RIGHTS;                    // 33
    static const int SPECIAL_CUM_CAPITAL_REPAYMENTS;       // 34
    static const int SPECIAL_EX_CAPITAL_REPAYMENTS;        // 35
    static const int SPECIAL_CUM_BONUS;                    // 36
    static const int SPECIAL_EX_BONUS;                     // 37
    static const int BLOCK_TRADE_38;                       // 38
    static const int WORKED_PRINCIPAL_TRADE;               // 39
    static const int BLOCK_TRADES;                         // 40
    static const int NAME_CHANGE;                          // 41
    static const int PORTFOLIO_TRANSFER;                   // 42
    static const int PROROGATION_BUY;                      // 43
    static const int PROROGATION_SELL;                     // 44
    static const int OPTION_EXERCISE;                      // 45
    static const int DELTA_NEUTRAL_TRANSACTION;            // 46
    static const int FINANCING_TRANSACTION;                // 47
};
struct STRATEGY_EXPORT TrdSubType
{
    static const int CMTA;                                            // 0
    static const int INTERNAL_TRANSFER_OR_ADJUSTMENT;                 // 1
    static const int EXTERNAL_TRANSFER_OR_TRANSFER_OF_ACCOUNT;        // 2
    static const int REJECT_FOR_SUBMITTING_SIDE;                      // 3
    static const int ADVISORY_FOR_CONTRA_SIDE;                        // 4
    static const int OFFSET_DUE_TO_AN_ALLOCATION;                     // 5
    static const int ONSET_DUE_TO_AN_ALLOCATION;                      // 6
    static const int DIFFERENTIAL_SPREAD;                             // 7
    static const int IMPLIED_SPREAD_LEG_EXECUTED_AGAINST_AN_OUTRIGHT; // 8
    static const int TRANSACTION_FROM_EXERCISE;                       // 9
    static const int TRANSACTION_FROM_ASSIGNMENT;                     // 10
    static const int ACATS;                                           // 11
    static const int OFF_HOURS_TRADE;                                 // 33
    static const int ON_HOURS_TRADE;                                  // 34
    static const int OTC_QUOTE;                                       // 35
    static const int CONVERTED_SWAP;                                  // 36
    static const int AI;                                              // 14
    static const int B;                                               // 15
    static const int K;                                               // 16
    static const int LC;                                              // 17
    static const int M;                                               // 18
    static const int N;                                               // 19
    static const int NM;                                              // 20
    static const int NR;                                              // 21
    static const int P;                                               // 22
    static const int PA;                                              // 23
    static const int PC;                                              // 24
    static const int PN;                                              // 25
    static const int R;                                               // 26
    static const int RO;                                              // 27
    static const int RT;                                              // 28
    static const int SW;                                              // 29
    static const int T;                                               // 30
    static const int WN;                                              // 31
    static const int WT;                                              // 32
    static const int CROSSED_TRADE;                                   // 37
    static const int INTERIM_PROTECTED_TRADE;                         // 38
    static const int LARGE_IN_SCALE;                                  // 39
};
struct STRATEGY_EXPORT PegMoveType
{
    static const int FLOATING; // 0
    static const int FIXED;    // 1
};
struct STRATEGY_EXPORT PegOffsetType
{
    static const int PRICE;        // 0
    static const int BASIS_POINTS; // 1
    static const int TICKS;        // 2
    static const int PRICE_TIER;   // 3
};
struct STRATEGY_EXPORT PegLimitType
{
    static const int OR_BETTER; // 0
    static const int STRICT;    // 1
    static const int OR_WORSE;  // 2
};
struct STRATEGY_EXPORT PegRoundDirection
{
    static const int MORE_AGGRESSIVE; // 1
    static const int MORE_PASSIVE;    // 2
};
struct STRATEGY_EXPORT PegScope
{
    static const int LOCAL;                    // 1
    static const int NATIONAL;                 // 2
    static const int GLOBAL;                   // 3
    static const int NATIONAL_EXCLUDING_LOCAL; // 4
};
struct STRATEGY_EXPORT DiscretionMoveType
{
    static const int FLOATING; // 0
    static const int FIXED;    // 1
};
struct STRATEGY_EXPORT DiscretionOffsetType
{
    static const int PRICE;        // 0
    static const int BASIS_POINTS; // 1
    static const int TICKS;        // 2
    static const int PRICE_TIER;   // 3
};
struct STRATEGY_EXPORT DiscretionLimitType
{
    static const int OR_BETTER; // 0
    static const int STRICT;    // 1
    static const int OR_WORSE;  // 2
};
struct STRATEGY_EXPORT DiscretionRoundDirection
{
    static const int MORE_AGGRESSIVE; // 1
    static const int MORE_PASSIVE;    // 2
};
struct STRATEGY_EXPORT DiscretionScope
{
    static const int LOCAL;                    // 1
    static const int NATIONAL;                 // 2
    static const int GLOBAL;                   // 3
    static const int NATIONAL_EXCLUDING_LOCAL; // 4
};
struct STRATEGY_EXPORT TargetStrategy
{
    static const int VWAP;                   // 1
    static const int PARTICIPATE;            // 2
    static const int MININIZE_MARKET_IMPACT; // 3
};
struct STRATEGY_EXPORT LastLiquidityInd
{
    static const int ADDED_LIQUIDITY;      // 1
    static const int REMOVED_LIQUIDITY;    // 2
    static const int LIQUIDITY_ROUTED_OUT; // 3
    static const int AUCTION;              // 4
};
struct STRATEGY_EXPORT ShortSaleReason
{
    static const int DEALER_SOLD_SHORT;                        // 0
    static const int DEALER_SOLD_SHORT_EXEMPT;                 // 1
    static const int SELLING_CUSTOMER_SOLD_SHORT;              // 2
    static const int SELLING_CUSTOMER_SOLD_SHORT_EXEMPT;       // 3
    static const int QUALIFIED_SERVICE_REPRESENTATIVE;         // 4
    static const int QSR_OR_AGU_CONTRA_SIDE_SOLD_SHORT_EXEMPT; // 5
};
struct STRATEGY_EXPORT QtyType
{
    static const int UNITS;                          // 0
    static const int CONTRACTS;                      // 1
    static const int UNITS_OF_MEASURE_PER_TIME_UNIT; // 2
};
struct STRATEGY_EXPORT TradeReportType
{
    static const int SUBMIT;                      // 0
    static const int ALLEGED_1;                   // 1
    static const int ACCEPT;                      // 2
    static const int DECLINE;                     // 3
    static const int ADDENDUM;                    // 4
    static const int NO_WAS;                      // 5
    static const int TRADE_REPORT_CANCEL;         // 6
    static const int TRADE_BREAK;                 // 7
    static const int DEFAULTED;                   // 8
    static const int INVALID_CMTA;                // 9
    static const int PENDED;                      // 10
    static const int ALLEGED_NEW;                 // 11
    static const int ALLEGED_ADDENDUM;            // 12
    static const int ALLEGED_NO_WAS;              // 13
    static const int ALLEGED_TRADE_REPORT_CANCEL; // 14
    static const int ALLEGED_15;                  // 15
};
struct STRATEGY_EXPORT AllocNoOrdersType
{
    static const int NOT_SPECIFIED;          // 0
    static const int EXPLICIT_LIST_PROVIDED; // 1
};
struct STRATEGY_EXPORT EventType
{
    static const int PUT;                        // 1
    static const int CALL;                       // 2
    static const int TENDER;                     // 3
    static const int SINKING_FUND_CALL;          // 4
    static const int ACTIVATION;                 // 5
    static const int INACTIVIATION;              // 6
    static const int LAST_ELIGIBLE_TRADE_DATE;   // 7
    static const int SWAP_START_DATE;            // 8
    static const int SWAP_END_DATE;              // 9
    static const int SWAP_ROLL_DATE;             // 10
    static const int SWAP_NEXT_START_DATE;       // 11
    static const int SWAP_NEXT_ROLL_DATE;        // 12
    static const int FIRST_DELIVERY_DATE;        // 13
    static const int LAST_DELIVERY_DATE;         // 14
    static const int INITIAL_INVENTORY_DUE_DATE; // 15
    static const int FINAL_INVENTORY_DUE_DATE;   // 16
    static const int FIRST_INTENT_DATE;          // 17
    static const int LAST_INTENT_DATE;           // 18
    static const int POSITION_REMOVAL_DATE;      // 19
    static const int OTHER;                      // 99
};
struct STRATEGY_EXPORT InstrAttribType
{
    static const int FLAT;                                                                        // 1
    static const int ZERO_COUPON;                                                                 // 2
    static const int INTEREST_BEARING;                                                            // 3
    static const int NO_PERIODIC_PAYMENTS;                                                        // 4
    static const int VARIABLE_RATE;                                                               // 5
    static const int LESS_FEE_FOR_PUT;                                                            // 6
    static const int STEPPED_COUPON;                                                              // 7
    static const int COUPON_PERIOD;                                                               // 8
    static const int WHEN_AND_IF_ISSUED;                                                          // 9
    static const int ORIGINAL_ISSUE_DISCOUNT;                                                     // 10
    static const int CALLABLE_PUTTABLE;                                                           // 11
    static const int ESCROWED_TO_MATURITY;                                                        // 12
    static const int ESCROWED_TO_REDEMPTION_DATE;                                                 // 13
    static const int PRE_REFUNDED;                                                                // 14
    static const int IN_DEFAULT;                                                                  // 15
    static const int UNRATED;                                                                     // 16
    static const int TAXABLE;                                                                     // 17
    static const int INDEXED;                                                                     // 18
    static const int SUBJECT_TO_ALTERNATIVE_MINIMUM_TAX;                                          // 19
    static const int ORIGINAL_ISSUE_DISCOUNT_PRICE_SUPPLY_PRICE_IN_THE_INSTRATTRIBVALUE;          // 20
    static const int CALLABLE_BELOW_MATURITY_VALUE;                                               // 21
    static const int CALLABLE_WITHOUT_NOTICE_BY_MAIL_TO_HOLDER_UNLESS_REGISTERED;                 // 22
    static const int PRICE_TICK_RULES_FOR_SECURITY;                                               // 23
    static const int TRADE_TYPE_ELIGIBILITY_DETAILS_FOR_SECURITY;                                 // 24
    static const int INSTRUMENT_DENOMINATOR;                                                      // 25
    static const int INSTRUMENT_NUMERATOR;                                                        // 26
    static const int INSTRUMENT_PRICE_PRECISION;                                                  // 27
    static const int INSTRUMENT_STRIKE_PRICE;                                                     // 28
    static const int TRADEABLE_INDICATOR;                                                         // 29
    static const int TEXT_SUPPLY_THE_TEXT_OF_THE_ATTRIBUTE_OR_DISCLAIMER_IN_THE_INSTRATTRIBVALUE; // 99
};
struct STRATEGY_EXPORT MiscFeeBasis
{
    static const int ABSOLUTE;   // 0
    static const int PER_UNIT;   // 1
    static const int PERCENTAGE; // 2
};
struct STRATEGY_EXPORT CollAsgnReason
{
    static const int INITIAL;                   // 0
    static const int SCHEDULED;                 // 1
    static const int TIME_WARNING;              // 2
    static const int MARGIN_DEFICIENCY;         // 3
    static const int MARGIN_EXCESS;             // 4
    static const int FORWARD_COLLATERAL_DEMAND; // 5
    static const int EVENT_OF_DEFAULT;          // 6
    static const int ADVERSE_TAX_EVENT;         // 7
};
struct STRATEGY_EXPORT CollInquiryQualifier
{
    static const int TRADE_DATE;            // 0
    static const int GC_INSTRUMENT;         // 1
    static const int COLLATERAL_INSTRUMENT; // 2
    static const int SUBSTITUTION_ELIGIBLE; // 3
    static const int NOT_ASSIGNED;          // 4
    static const int PARTIALLY_ASSIGNED;    // 5
    static const int FULLY_ASSIGNED;        // 6
    static const int OUTSTANDING_TRADES;    // 7
};
struct STRATEGY_EXPORT CollAsgnTransType
{
    static const int NEW;     // 0
    static const int REPLACE; // 1
    static const int CANCEL;  // 2
    static const int RELEASE; // 3
    static const int REVERSE; // 4
};
struct STRATEGY_EXPORT CollAsgnRespType
{
    static const int RECEIVED; // 0
    static const int ACCEPTED; // 1
    static const int DECLINED; // 2
    static const int REJECTED; // 3
};
struct STRATEGY_EXPORT CollAsgnRejectReason
{
    static const int UNKNOWN_DEAL;                  // 0
    static const int UNKNOWN_OR_INVALID_INSTRUMENT; // 1
    static const int UNAUTHORIZED_TRANSACTION;      // 2
    static const int INSUFFICIENT_COLLATERAL;       // 3
    static const int INVALID_TYPE_OF_COLLATERAL;    // 4
    static const int EXCESSIVE_SUBSTITUTION;        // 5
    static const int OTHER;                         // 99
};
struct STRATEGY_EXPORT CollStatus
{
    static const int UNASSIGNED;          // 0
    static const int PARTIALLY_ASSIGNED;  // 1
    static const int ASSIGNMENT_PROPOSED; // 2
    static const int ASSIGNED;            // 3
    static const int CHALLENGED;          // 4
};
struct STRATEGY_EXPORT DeliveryType
{
    static const int VERSUS_PAYMENT_DELIVER; // 0
    static const int FREE_DELIVER;           // 1
    static const int TRI_PARTY;              // 2
    static const int HOLD_IN_CUSTODY;        // 3
};
struct STRATEGY_EXPORT UserRequestType
{
    static const int LOG_ON_USER;                    // 1
    static const int LOG_OFF_USER;                   // 2
    static const int CHANGE_PASSWORD_FOR_USER;       // 3
    static const int REQUEST_INDIVIDUAL_USER_STATUS; // 4
};
struct STRATEGY_EXPORT UserStatus
{
    static const int LOGGED_IN;                      // 1
    static const int NOT_LOGGED_IN;                  // 2
    static const int USER_NOT_RECOGNISED;            // 3
    static const int PASSWORD_INCORRECT;             // 4
    static const int PASSWORD_CHANGED;               // 5
    static const int OTHER;                          // 6
    static const int FORCED_USER_LOGOUT_BY_EXCHANGE; // 7
    static const int SESSION_SHUTDOWN_WARNING;       // 8
};
struct STRATEGY_EXPORT StatusValue
{
    static const int CONNECTED;       // 1
    static const int NOT_CONNECTED_2; // 2
    static const int NOT_CONNECTED_3; // 3
    static const int IN_PROCESS;      // 4
};
struct STRATEGY_EXPORT NetworkRequestType
{
    static const int SNAPSHOT;                                        // 1
    static const int SUBSCRIBE;                                       // 2
    static const int STOP_SUBSCRIBING;                                // 4
    static const int LEVEL_OF_DETAIL_THEN_NOCOMPIDS_BECOMES_REQUIRED; // 8
};
struct STRATEGY_EXPORT NetworkStatusResponseType
{
    static const int FULL;               // 1
    static const int INCREMENTAL_UPDATE; // 2
};
struct STRATEGY_EXPORT TrdRptStatus
{
    static const int ACCEPTED;             // 0
    static const int REJECTED;             // 1
    static const int ACCEPTED_WITH_ERRORS; // 3
};
struct STRATEGY_EXPORT AffirmStatus
{
    static const int RECEIVED;                         // 1
    static const int CONFIRM_REJECTED_IE_NOT_AFFIRMED; // 2
    static const int AFFIRMED;                         // 3
};
struct STRATEGY_EXPORT CollAction
{
    static const int RETAIN; // 0
    static const int ADD;    // 1
    static const int REMOVE; // 2
};
struct STRATEGY_EXPORT CollInquiryStatus
{
    static const int ACCEPTED;                // 0
    static const int ACCEPTED_WITH_WARNINGS;  // 1
    static const int COMPLETED;               // 2
    static const int COMPLETED_WITH_WARNINGS; // 3
    static const int REJECTED;                // 4
};
struct STRATEGY_EXPORT CollInquiryResult
{
    static const int SUCCESSFUL;                                  // 0
    static const int INVALID_OR_UNKNOWN_INSTRUMENT;               // 1
    static const int INVALID_OR_UNKNOWN_COLLATERAL_TYPE;          // 2
    static const int INVALID_PARTIES;                             // 3
    static const int INVALID_TRANSPORT_TYPE_REQUESTED;            // 4
    static const int INVALID_DESTINATION_REQUESTED;               // 5
    static const int NO_COLLATERAL_FOUND_FOR_THE_TRADE_SPECIFIED; // 6
    static const int NO_COLLATERAL_FOUND_FOR_THE_ORDER_SPECIFIED; // 7
    static const int COLLATERAL_INQUIRY_TYPE_NOT_SUPPORTED;       // 8
    static const int UNAUTHORIZED_FOR_COLLATERAL_INQUIRY;         // 9
    static const int OTHER;                                       // 99
};
struct STRATEGY_EXPORT StrategyParameterType
{
    static const int INT;                 // 1
    static const int LENGTH;              // 2
    static const int NUMINGROUP;          // 3
    static const int SEQNUM;              // 4
    static const int TAGNUM;              // 5
    static const int FLOAT;               // 6
    static const int QTY;                 // 7
    static const int PRICE;               // 8
    static const int PRICEOFFSET;         // 9
    static const int AMT;                 // 10
    static const int PERCENTAGE;          // 11
    static const int CHAR;                // 12
    static const int BOOLEAN;             // 13
    static const int STRING;              // 14
    static const int MULTIPLECHARVALUE;   // 15
    static const int CURRENCY;            // 16
    static const int EXCHANGE;            // 17
    static const int MONTHYEAR;           // 18
    static const int UTCTIMESTAMP;        // 19
    static const int UTCTIMEONLY;         // 20
    static const int LOCALMKTDATE;        // 21
    static const int UTCDATEONLY;         // 22
    static const int DATA;                // 23
    static const int MULTIPLESTRINGVALUE; // 24
    static const int COUNTRY;             // 25
    static const int LANGUAGE;            // 26
    static const int TZTIMEONLY;          // 27
    static const int TZTIMESTAMP;         // 28
    static const int TENOR;               // 29
};
struct STRATEGY_EXPORT UnderlyingSettlementType
{
    static const int T_PLUS_1; // 2
    static const int T_PLUS_3; // 4
    static const int T_PLUS_4; // 5
};
struct STRATEGY_EXPORT SecurityUpdateAction
{
    static const char ADD;    // 'A'
    static const char DELETE; // 'D'
    static const char MODIFY; // 'M'
};
struct STRATEGY_EXPORT ExpirationQtyType
{
    static const int AUTO_EXERCISE;           // 1
    static const int NON_AUTO_EXERCISE;       // 2
    static const int FINAL_WILL_BE_EXERCISED; // 3
    static const int CONTRARY_INTENTION;      // 4
    static const int DIFFERENCE;              // 5
};
struct STRATEGY_EXPORT IndividualAllocType
{
    static const int SUB_ALLOCATE;           // 1
    static const int THIRD_PARTY_ALLOCATION; // 2
};
struct STRATEGY_EXPORT AllocMethod
{
    static const int AUTOMATIC; // 1
    static const int GUARANTOR; // 2
    static const int MANUAL;    // 3
};
struct STRATEGY_EXPORT AsOfIndicator
{
    static const char AS_OF_FALSE; // '0'
    static const char AS_OF_TRUE;  // '1'
};
struct STRATEGY_EXPORT MDBookType
{
    static const int TOP_OF_BOOK; // 1
    static const int PRICE_DEPTH; // 2
    static const int ORDER_DEPTH; // 3
};
struct STRATEGY_EXPORT MDOriginType
{
    static const int BOOK;     // 0
    static const int OFF_BOOK; // 1
    static const int CROSS;    // 2
};
struct STRATEGY_EXPORT ExecAckStatus
{
    static const char RECEIVED_NOT_YET_PROCESSED; // '0'
    static const char ACCEPTED;                   // '1'
    static const char DONT_KNOW;                  // '2'
};
struct STRATEGY_EXPORT CollApplType
{
    static const int SPECIFIC_DEPOSIT; // 0
    static const int GENERAL;          // 1
};
struct STRATEGY_EXPORT UnderlyingFXRateCalc
{
    static const char DIVIDE;   // 'D'
    static const char MULTIPLY; // 'M'
};
struct STRATEGY_EXPORT AllocPositionEffect
{
    static const char OPEN;   // 'O'
    static const char CLOSE;  // 'C'
    static const char ROLLED; // 'R'
    static const char FIFO;   // 'F'
};
struct STRATEGY_EXPORT DealingCapacity
{
    static const char AGENT;              // 'A'
    static const char PRINCIPAL;          // 'P'
    static const char RISKLESS_PRINCIPAL; // 'R'
};
struct STRATEGY_EXPORT MDQuoteType
{
    static const int INDICATIVE;               // 0
    static const int TRADEABLE;                // 1
    static const int RESTRICTED_TRADEABLE;     // 2
    static const int COUNTER;                  // 3
    static const int INDICATIVE_AND_TRADEABLE; // 4
};
struct STRATEGY_EXPORT RefOrderIDSource
{
    static const char SECONDARYORDERID;  // '0'
    static const char ORDERID;           // '1'
    static const char MDENTRYID;         // '2'
    static const char QUOTEENTRYID;      // '3'
    static const char ORIGINAL_ORDER_ID; // '4'
};
struct STRATEGY_EXPORT DisplayWhen
{
    static const char IMMEDIATE; // '1'
    static const char EXHAUST;   // '2'
};
struct STRATEGY_EXPORT DisplayMethod
{
    static const char INITIAL;     // '1'
    static const char NEW;         // '2'
    static const char RANDOM;      // '3'
    static const char UNDISCLOSED; // '4'
};
struct STRATEGY_EXPORT PriceProtectionScope
{
    static const char NONE;     // '0'
    static const char LOCAL;    // '1'
    static const char NATIONAL; // '2'
    static const char GLOBAL;   // '3'
};
struct STRATEGY_EXPORT LotType
{
    static const char ODD_LOT;                            // '1'
    static const char ROUND_LOT;                          // '2'
    static const char BLOCK_LOT;                          // '3'
    static const char ROUND_LOT_BASED_UPON_UNITOFMEASURE; // '4'
};
struct STRATEGY_EXPORT PegPriceType
{
    static const int LAST_PEG;           // 1
    static const int MID_PRICE_PEG;      // 2
    static const int OPENING_PEG;        // 3
    static const int MARKET_PEG;         // 4
    static const int PRIMARY_PEG;        // 5
    static const int PEG_TO_VWAP;        // 7
    static const int TRAILING_STOP_PEG;  // 8
    static const int PEG_TO_LIMIT_PRICE; // 9
};
struct STRATEGY_EXPORT TriggerType
{
    static const char PARTIAL_EXECUTION;         // '1'
    static const char SPECIFIED_TRADING_SESSION; // '2'
    static const char NEXT_AUCTION;              // '3'
    static const char PRICE_MOVEMENT;            // '4'
};
struct STRATEGY_EXPORT TriggerAction
{
    static const char ACTIVATE; // '1'
    static const char MODIFY;   // '2'
    static const char CANCEL;   // '3'
};
struct STRATEGY_EXPORT TriggerPriceType
{
    static const char BEST_OFFER;               // '1'
    static const char LAST_TRADE;               // '2'
    static const char BEST_BID;                 // '3'
    static const char BEST_BID_OR_LAST_TRADE;   // '4'
    static const char BEST_OFFER_OR_LAST_TRADE; // '5'
    static const char BEST_MID;                 // '6'
};
struct STRATEGY_EXPORT TriggerPriceTypeScope
{
    static const char NONE;     // '0'
    static const char LOCAL;    // '1'
    static const char NATIONAL; // '2'
    static const char GLOBAL;   // '3'
};
struct STRATEGY_EXPORT TriggerPriceDirection
{
    static const char TRIGGER_IF_THE_PRICE_OF_THE_SPECIFIED_TYPE_GOES_UP_TO_OR_THROUGH_THE_SPECIFIED_TRIGGER_PRICE;   // 'U'
    static const char TRIGGER_IF_THE_PRICE_OF_THE_SPECIFIED_TYPE_GOES_DOWN_TO_OR_THROUGH_THE_SPECIFIED_TRIGGER_PRICE; // 'D'
};
struct STRATEGY_EXPORT TriggerOrderType
{
    static const char MARKET; // '1'
    static const char LIMIT;  // '2'
};
struct STRATEGY_EXPORT OrderCategory
{
    static const char ORDER;                      // '1'
    static const char QUOTE;                      // '2'
    static const char PRIVATELY_NEGOTIATED_TRADE; // '3'
    static const char MULTILEG_ORDER;             // '4'
    static const char LINKED_ORDER;               // '5'
    static const char QUOTE_REQUEST;              // '6'
    static const char IMPLIED_ORDER;              // '7'
    static const char CROSS_ORDER;                // '8'
    static const char STREAMING_PRICE;            // '9'
};
struct STRATEGY_EXPORT TradeHandlingInstr
{
    static const char TRADE_CONFIRMATION;                // '0'
    static const char TWO_PARTY_REPORT;                  // '1'
    static const char ONE_PARTY_REPORT_FOR_MATCHING;     // '2'
    static const char ONE_PARTY_REPORT_FOR_PASS_THROUGH; // '3'
    static const char AUTOMATED_FLOOR_ORDER_ROUTING;     // '4'
    static const char TWO_PARTY_REPORT_FOR_CLAIM;        // '5'
};
struct STRATEGY_EXPORT ExDestinationIDSource
{
    static const char BIC;                                              // 'B'
    static const char GENERALLY_ACCEPTED_MARKET_PARTICIPANT_IDENTIFIER; // 'C'
    static const char PROPRIETARY;                                      // 'D'
    static const char ISO_COUNTRY_CODE;                                 // 'E'
    static const char MIC;                                              // 'G'
};
struct STRATEGY_EXPORT ImpliedMarketIndicator
{
    static const int NOT_IMPLIED;                     // 0
    static const int IMPLIED_IN;                      // 1
    static const int IMPLIED_OUT;                     // 2
    static const int BOTH_IMPLIED_IN_AND_IMPLIED_OUT; // 3
};
struct STRATEGY_EXPORT SettlObligMode
{
    static const int PRELIMINARY; // 1
    static const int FINAL;       // 2
};
struct STRATEGY_EXPORT SettlObligTransType
{
    static const char CANCEL;  // 'C'
    static const char NEW;     // 'N'
    static const char REPLACE; // 'R'
    static const char RESTATE; // 'T'
};
struct STRATEGY_EXPORT SettlObligSource
{
    static const char INSTRUCTIONS_OF_BROKER;       // '1'
    static const char INSTRUCTIONS_FOR_INSTITUTION; // '2'
    static const char INVESTOR;                     // '3'
};
struct STRATEGY_EXPORT QuoteEntryStatus
{
    static const int ACCEPTED;                     // 0
    static const int REJECTED;                     // 5
    static const int REMOVED_FROM_MARKET;          // 6
    static const int EXPIRED;                      // 7
    static const int LOCKED_MARKET_WARNING;        // 12
    static const int CROSS_MARKET_WARNING;         // 13
    static const int CANCELED_DUE_TO_LOCK_MARKET;  // 14
    static const int CANCELED_DUE_TO_CROSS_MARKET; // 15
    static const int ACTIVE;                       // 16
};
struct STRATEGY_EXPORT RespondentType
{
    static const int ALL_MARKET_PARTICIPANTS;       // 1
    static const int SPECIFIED_MARKET_PARTICIPANTS; // 2
    static const int ALL_MARKET_MAKERS;             // 3
    static const int PRIMARY_MARKET_MAKER;          // 4
};
struct STRATEGY_EXPORT SecurityTradingEvent
{
    static const int ORDER_IMBALANCE_AUCTION_IS_EXTENDED; // 1
    static const int TRADING_RESUMES;                     // 2
    static const int PRICE_VOLATILITY_INTERRUPTION;       // 3
    static const int CHANGE_OF_TRADING_SESSION;           // 4
    static const int CHANGE_OF_TRADING_SUBSESSION;        // 5
    static const int CHANGE_OF_SECURITY_TRADING_STATUS;   // 6
    static const int CHANGE_OF_BOOK_TYPE;                 // 7
    static const int CHANGE_OF_MARKET_DEPTH;              // 8
};
struct STRATEGY_EXPORT StatsType
{
    static const int EXCHANGE_LAST; // 1
    static const int HIGH;          // 2
    static const int AVERAGE_PRICE; // 3
    static const int TURNOVER;      // 4
};
struct STRATEGY_EXPORT SettlMethod
{
    static const char CASH_SETTLEMENT_REQUIRED;     // 'C'
    static const char PHYSICAL_SETTLEMENT_REQUIRED; // 'P'
};
struct STRATEGY_EXPORT ExerciseStyle
{
    static const int EUROPEAN; // 0
    static const int AMERICAN; // 1
    static const int BERMUDA;  // 2
};
struct STRATEGY_EXPORT ListMethod
{
    static const int PRE_LISTED_ONLY; // 0
    static const int USER_REQUESTED;  // 1
};
struct STRATEGY_EXPORT TickRuleType
{
    static const int REGULAR;                 // 0
    static const int VARIABLE;                // 1
    static const int FIXED;                   // 2
    static const int TRADED_AS_A_SPREAD_LEG;  // 3
    static const int SETTLED_AS_A_SPREAD_LEG; // 4
};
struct STRATEGY_EXPORT MaturityMonthYearIncrementUnits
{
    static const int MONTHS; // 0
    static const int DAYS;   // 1
    static const int WEEKS;  // 2
    static const int YEARS;  // 3
};
struct STRATEGY_EXPORT MaturityMonthYearFormat
{
    static const int YEARMONTH_ONLY; // 0
    static const int YEARMONTHDAY;   // 1
    static const int YEARMONTHWEEK;  // 2
};
struct STRATEGY_EXPORT PriceLimitType
{
    static const int PRICE;      // 0
    static const int TICKS;      // 1
    static const int PERCENTAGE; // 2
};
struct STRATEGY_EXPORT ApplReqType
{
    static const int RETRANSMISSION_OF_APPLICATION_MESSAGES_FOR_THE_SPECIFIED_APPLICATIONS;        // 0
    static const int SUBSCRIPTION_TO_THE_SPECIFIED_APPLICATIONS;                                   // 1
    static const int REQUEST_FOR_THE_LAST_APPLLASTSEQNUM_PUBLISHED_FOR_THE_SPECIFIED_APPLICATIONS; // 2
    static const int REQUEST_VALID_SET_OF_APPLICATIONS;                                            // 3
    static const int UNSUBSCRIBE_TO_THE_SPECIFIED_APPLICATIONS;                                    // 4
    static const int CANCEL_RETRANSMISSION;                                                        // 5
    static const int CANCEL_RETRANSMISSION_AND_UNSUBSCRIBE_TO_THE_SPECIFIED_APPLICATIONS;          // 6
};
struct STRATEGY_EXPORT ApplResponseType
{
    static const int REQUEST_SUCCESSFULLY_PROCESSED; // 0
    static const int APPLICATION_DOES_NOT_EXIST;     // 1
    static const int MESSAGES_NOT_AVAILABLE;         // 2
};
struct STRATEGY_EXPORT ApplResponseError
{
    static const int APPLICATION_DOES_NOT_EXIST;           // 0
    static const int MESSAGES_REQUESTED_ARE_NOT_AVAILABLE; // 1
    static const int USER_NOT_AUTHORIZED_FOR_APPLICATION;  // 2
};
struct STRATEGY_EXPORT TradSesEvent
{
    static const int TRADING_RESUMES;              // 0
    static const int CHANGE_OF_TRADING_SESSION;    // 1
    static const int CHANGE_OF_TRADING_SUBSESSION; // 2
    static const int CHANGE_OF_TRADING_STATUS;     // 3
};
struct STRATEGY_EXPORT MassActionType
{
    static const int SUSPEND_ORDERS;                 // 1
    static const int RELEASE_ORDERS_FROM_SUSPENSION; // 2
    static const int CANCEL_ORDERS;                  // 3
};
struct STRATEGY_EXPORT MassActionScope
{
    static const int ALL_ORDERS_FOR_A_SECURITY;                // 1
    static const int ALL_ORDERS_FOR_AN_UNDERLYING_SECURITY;    // 2
    static const int ALL_ORDERS_FOR_A_PRODUCT;                 // 3
    static const int ALL_ORDERS_FOR_A_CFICODE;                 // 4
    static const int ALL_ORDERS_FOR_A_SECURITYTYPE;            // 5
    static const int ALL_ORDERS_FOR_A_TRADING_SESSION;         // 6
    static const int ALL_ORDERS;                               // 7
    static const int ALL_ORDERS_FOR_A_MARKET;                  // 8
    static const int ALL_ORDERS_FOR_A_MARKET_SEGMENT;          // 9
    static const int ALL_ORDERS_FOR_A_SECURITY_GROUP;          // 10
    static const int CANCEL_FOR_SECURITY_ISSUER;               // 11
    static const int CANCEL_FOR_ISSUER_OF_UNDERLYING_SECURITY; // 12
};
struct STRATEGY_EXPORT MassActionResponse
{
    static const int REJECTED; // 0
    static const int ACCEPTED; // 1
};
struct STRATEGY_EXPORT MassActionRejectReason
{
    static const int MASS_ACTION_NOT_SUPPORTED;                        // 0
    static const int INVALID_OR_UNKNOWN_SECURITY;                      // 1
    static const int INVALID_OR_UNKNOWN_UNDERLYING_SECURITY;           // 2
    static const int INVALID_OR_UNKNOWN_PRODUCT;                       // 3
    static const int INVALID_OR_UNKNOWN_CFICODE;                       // 4
    static const int INVALID_OR_UNKNOWN_SECURITYTYPE;                  // 5
    static const int INVALID_OR_UNKNOWN_TRADING_SESSION;               // 6
    static const int INVALID_OR_UNKNOWN_MARKET;                        // 7
    static const int INVALID_OR_UNKNOWN_MARKET_SEGMENT;                // 8
    static const int INVALID_OR_UNKNOWN_SECURITY_GROUP;                // 9
    static const int OTHER;                                            // 99
    static const int INVALID_OR_UNKNOWN_SECURITY_ISSUER;               // 10
    static const int INVALID_OR_UNKNOWN_ISSUER_OF_UNDERLYING_SECURITY; // 11
};
struct STRATEGY_EXPORT MultilegModel
{
    static const int PREDEFINED_MULTILEG_SECURITY;          // 0
    static const int USER_DEFINED_MULTLEG_SECURITY;         // 1
    static const int USER_DEFINED_NON_SECURITIZED_MULTILEG; // 2
};
struct STRATEGY_EXPORT MultilegPriceMethod
{
    static const int NET_PRICE;                       // 0
    static const int REVERSED_NET_PRICE;              // 1
    static const int YIELD_DIFFERENCE;                // 2
    static const int INDIVIDUAL;                      // 3
    static const int CONTRACT_WEIGHTED_AVERAGE_PRICE; // 4
    static const int MULTIPLIED_PRICE;                // 5
};
struct STRATEGY_EXPORT ContingencyType
{
    static const int ONE_CANCELS_THE_OTHER;   // 1
    static const int ONE_TRIGGERS_THE_OTHER;  // 2
    static const int ONE_UPDATES_THE_OTHER_3; // 3
    static const int ONE_UPDATES_THE_OTHER_4; // 4
};
struct STRATEGY_EXPORT ListRejectReason
{
    static const int BROKER;                           // 0
    static const int EXCHANGE_CLOSED;                  // 2
    static const int TOO_LATE_TO_ENTER;                // 4
    static const int UNKNOWN_ORDER;                    // 5
    static const int DUPLICATE_ORDER;                  // 6
    static const int UNSUPPORTED_ORDER_CHARACTERISTIC; // 11
    static const int OTHER;                            // 99
};
struct STRATEGY_EXPORT TradePublishIndicator
{
    static const int DO_NOT_PUBLISH_TRADE; // 0
    static const int PUBLISH_TRADE;        // 1
    static const int DEFERRED_PUBLICATION; // 2
};
struct STRATEGY_EXPORT MarketUpdateAction
{
    static const char ADD;    // 'A'
    static const char DELETE; // 'D'
    static const char MODIFY; // 'M'
};
struct STRATEGY_EXPORT SessionStatus
{
    static const int SESSION_ACTIVE;                                   // 0
    static const int SESSION_PASSWORD_CHANGED;                         // 1
    static const int SESSION_PASSWORD_DUE_TO_EXPIRE;                   // 2
    static const int NEW_SESSION_PASSWORD_DOES_NOT_COMPLY_WITH_POLICY; // 3
    static const int SESSION_LOGOUT_COMPLETE;                          // 4
    static const int INVALID_USERNAME_OR_PASSWORD;                     // 5
    static const int ACCOUNT_LOCKED;                                   // 6
    static const int LOGONS_ARE_NOT_ALLOWED_AT_THIS_TIME;              // 7
    static const int PASSWORD_EXPIRED;                                 // 8
};
struct STRATEGY_EXPORT ApplReportType
{
    static const int RESET_APPLSEQNUM_TO_NEW_VALUE_SPECIFIED_IN_APPLNEWSEQNUM;                               // 0
    static const int REPORTS_THAT_THE_LAST_MESSAGE_HAS_BEEN_SENT_FOR_THE_APPLIDS_REFER_TO_REFAPPLLASTSEQNUM; // 1
    static const int HEARTBEAT_MESSAGE_INDICATING_THAT_APPLICATION_IDENTIFIED_BY_REFAPPLID;                  // 2
    static const int APPLICATION_MESSAGE_RE_SEND_COMPLETED;                                                  // 3
};
struct STRATEGY_EXPORT OrderDelayUnit
{
    static const int SECONDS;                // 0
    static const int TENTHS_OF_A_SECOND;     // 1
    static const int HUNDREDTHS_OF_A_SECOND; // 2
    static const int MILLISECONDS;           // 3
    static const int MICROSECONDS;           // 4
    static const int NANOSECONDS;            // 5
    static const int MINUTES;                // 10
    static const int HOURS;                  // 11
    static const int DAYS;                   // 12
    static const int WEEKS;                  // 13
    static const int MONTHS;                 // 14
    static const int YEARS;                  // 15
};
struct STRATEGY_EXPORT VenueType
{
    static const char ELECTRONIC; // 'E'
    static const char PIT;        // 'P'
    static const char EX_PIT;     // 'X'
};
struct STRATEGY_EXPORT RefOrdIDReason
{
    static const int GTC_FROM_PREVIOUS_DAY;  // 0
    static const int PARTIAL_FILL_REMAINING; // 1
    static const int ORDER_CHANGED;          // 2
};
struct STRATEGY_EXPORT OrigCustOrderCapacity
{
    static const int MEMBER_TRADING_FOR_THEIR_OWN_ACCOUNT;              // 1
    static const int CLEARING_FIRM_TRADING_FOR_ITS_PROPRIETARY_ACCOUNT; // 2
    static const int MEMBER_TRADING_FOR_ANOTHER_MEMBER;                 // 3
    static const int ALL_OTHER;                                         // 4
};
struct STRATEGY_EXPORT ModelType
{
    static const int UTILITY_PROVIDED_STANDARD_MODEL; // 0
    static const int PROPRIETARY;                     // 1
};
struct STRATEGY_EXPORT ContractMultiplierUnit
{
    static const int SHARES; // 0
    static const int HOURS;  // 1
    static const int DAYS;   // 2
};
struct STRATEGY_EXPORT FlowScheduleType
{
    static const int NERC_EASTERN_OFF_PEAK;           // 0
    static const int NERC_WESTERN_OFF_PEAK;           // 1
    static const int NERC_CALENDAR_ALL_DAYS_IN_MONTH; // 2
    static const int NERC_EASTERN_PEAK;               // 3
    static const int NERC_WESTERN_PEAK;               // 4
};
struct STRATEGY_EXPORT RateSource
{
    static const int BLOOMBERG; // 0
    static const int REUTERS;   // 1
    static const int TELERATE;  // 2
    static const int OTHER;     // 99
};
struct STRATEGY_EXPORT RateSourceType
{
    static const int PRIMARY;   // 0
    static const int SECONDARY; // 1
};
struct STRATEGY_EXPORT SecurityListType
{
    static const int INDUSTRY_CLASSIFICATION; // 1
    static const int TRADING_LIST;            // 2
    static const int MARKET;                  // 3
    static const int NEWSPAPER_LIST;          // 4
};
struct STRATEGY_EXPORT SecurityListTypeSource
{
    static const int ICB;   // 1
    static const int NAICS; // 2
    static const int GICS;  // 3
};
struct STRATEGY_EXPORT NewsCategory
{
    static const int COMPANY_NEWS;          // 0
    static const int MARKETPLACE_NEWS;      // 1
    static const int FINANCIAL_MARKET_NEWS; // 2
    static const int TECHNICAL_NEWS;        // 3
    static const int OTHER_NEWS;            // 99
};
struct STRATEGY_EXPORT NewsRefType
{
    static const int REPLACEMENT;    // 0
    static const int OTHER_LANGUAGE; // 1
    static const int COMPLIMENTARY;  // 2
};
struct STRATEGY_EXPORT StrikePriceDeterminationMethod
{
    static const int FIXED_STRIKE;                                                                       // 1
    static const int STRIKE_SET_AT_EXPIRATION_TO_UNDERLYING_OR_OTHER_VALUE;                              // 2
    static const int STRIKE_SET_TO_AVERAGE_OF_UNDERLYING_SETTLEMENT_PRICE_ACROSS_THE_LIFE_OF_THE_OPTION; // 3
    static const int STRIKE_SET_TO_OPTIMAL_VALUE;                                                        // 4
};
struct STRATEGY_EXPORT StrikePriceBoundaryMethod
{
    static const int LESS_THAN_UNDERLYING_PRICE_IS_IN_THE_MONEY;                 // 1
    static const int LESS_THAN_OR_EQUAL_TO_THE_UNDERLYING_PRICE_IS_IN_THE_MONEY; // 2
    static const int EQUAL_TO_THE_UNDERLYING_PRICE_IS_IN_THE_MONEY;              // 3
    static const int GREATER_THAN_OR_EQUAL_TO_UNDERLYING_PRICE_IS_IN_THE_MONEY;  // 4
    static const int GREATER_THAN_UNDERLYING_IS_IN_THE_MONEY;                    // 5
};
struct STRATEGY_EXPORT UnderlyingPriceDeterminationMethod
{
    static const int REGULAR;           // 1
    static const int SPECIAL_REFERENCE; // 2
    static const int OPTIMAL_VALUE;     // 3
    static const int AVERAGE_VALUE;     // 4
};
struct STRATEGY_EXPORT OptPayoutType
{
    static const int VANILLA; // 1
    static const int CAPPED;  // 2
    static const int BINARY;  // 3
};
struct STRATEGY_EXPORT ComplexEventType
{
    static const int CAPPED;          // 1
    static const int TRIGGER;         // 2
    static const int KNOCK_IN_UP;     // 3
    static const int KOCK_IN_DOWN;    // 4
    static const int KNOCK_OUT_UP;    // 5
    static const int KNOCK_OUT_DOWN;  // 6
    static const int UNDERLYING;      // 7
    static const int RESET_BARRIER;   // 8
    static const int ROLLING_BARRIER; // 9
};
struct STRATEGY_EXPORT ComplexEventPriceBoundaryMethod
{
    static const int LESS_THAN_COMPLEXEVENTPRICE;                // 1
    static const int LESS_THAN_OR_EQUAL_TO_COMPLEXEVENTPRICE;    // 2
    static const int EQUAL_TO_COMPLEXEVENTPRICE;                 // 3
    static const int GREATER_THAN_OR_EQUAL_TO_COMPLEXEVENTPRICE; // 4
    static const int GREATER_THAN_COMPLEXEVENTPRICE;             // 5
};
struct STRATEGY_EXPORT ComplexEventPriceTimeType
{
    static const int EXPIRATION;          // 1
    static const int IMMEDIATE;           // 2
    static const int SPECIFIED_DATE_TIME; // 3
};
struct STRATEGY_EXPORT ComplexEventCondition
{
    static const int AND; // 1
    static const int OR;  // 2
};
struct STRATEGY_EXPORT StreamAsgnReqType
{
    static const int STREAM_ASSIGNMENT_FOR_NEW_CUSTOMER;      // 1
    static const int STREAM_ASSIGNMENT_FOR_EXISTING_CUSTOMER; // 2
};
struct STRATEGY_EXPORT StreamAsgnRejReason
{
    static const int UNKNOWN_CLIENT;                   // 0
    static const int EXCEEDS_MAXIMUM_SIZE;             // 1
    static const int UNKNOWN_OR_INVALID_CURRENCY_PAIR; // 2
    static const int NO_AVAILABLE_STREAM;              // 3
    static const int OTHER;                            // 99
};
struct STRATEGY_EXPORT StreamAsgnAckType
{
    static const int ASSIGNMENT_ACCEPTED; // 0
    static const int ASSIGNMENT_REJECTED; // 1
};
struct STRATEGY_EXPORT StreamAsgnType
{
    static const int ASSIGNMENT;         // 1
    static const int REJECTED;           // 2
    static const int TERMINATE_UNASSIGN; // 3
};
};

} // namespace FIX

} // namespace tbricks

STRATEGY_EXPORT std::ostream & print(std::ostream & strm, tbricks::FIX::Field::ID id);

inline std::ostream & operator<<(std::ostream & strm, tbricks::FIX::Field::ID id)
{
    return print(strm, id);
}

STRATEGY_EXPORT std::ostream & print(std::ostream & strm, tbricks::FIX::MessageType::Type type);

inline std::ostream & operator<<(std::ostream & strm, tbricks::FIX::MessageType::Type type)
{
    return print(strm, type);
}
