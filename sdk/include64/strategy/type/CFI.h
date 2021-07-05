#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Classification of Financial Instruments.
//****************************************************************************************

#include "strategy/type/String.h"
#include "strategy/type/cfi/CFIAttribute.h"
#include "strategy/type/cfi/CFICategory.h"
#include "strategy/type/cfi/CFIGroup.h"

#include <optional>

namespace tbricks {

namespace types {
class CFI;
}

/**
 * ISO-10962
 *
 * The Classification of Financial Instruments (CFI) is used to describe
 * financial instruments.
 *
 * The CFI consists of 6 alphabetical characters.
 *
 * 1 character       - the highest level of category,
 * 2 character       - specific groups,
 * 3 - 6 characters  - the most important attributes of each group.
 *
 * Character 'X' used if information is unknown.
 *
 * Support 2 standards : ISO_10962_2001, ISO_10962_2015
 * If standard is not specified, 2001 standard is used.
 */
class STRATEGY_EXPORT CFI : public AnyType
{
public:
    class Delivery;

public:
    /** Standard of CFI */
    enum Standard
    {
        V2001 = 0, /**< ISO_10962_2001 */
        V2015 = 1  /**< ISO_10962_2015 */
    };

public:
    /**
     * Create empty CFI
     */
    CFI() = default;

    /**
     * Create CFI from string.
     * If the string has less then 6 characters,
     * the missed characters changed by 'X'.
     * If the string has more then 6 characters,
     * the created CFI will be empty.
     *
     * @param str  CFI code
     * @param s    CFI standard
     */
    CFI(const char * str, Standard s) { set(str, s); }

    /**
     * Create CFI from string.
     * If the string has less then 6 characters,
     * the missed characters changed by 'X'.
     * If the string has more then 6 characters,
     * the created CFI will be empty.
     *
     * @param str  CFI code
     * @param s    CFI standard
     */
    CFI(const String & str, Standard s) { set(str.GetCString(), str.GetSize(), s); }

    /**
     * Create the CFI from string according to the 2001 standard.
     * If the string has less then 6 characters,
     * the missed characters changed by 'X'.
     * If the string has more then 6 characters,
     * the created CFI will be empty.
     *
     * @deprecated Deprecated in 2.14.0, please specify standard
     */
    [[deprecated(DEPRECATE_LINK)]] CFI(const char * str) { set(str, V2001); }

        /**
         * Create the CFI from string according to the 2001 standard.
         * If the string has less then 6 characters,
         * the missed characters changed by 'X'.
         * If the string has more then 6 characters,
         * the created CFI will be empty.
         *
         * @deprecated Deprecated in 2.14.0, please specify standard
         */
        [[deprecated(DEPRECATE_LINK)]] CFI(const String & str)
    {
        set(str.GetCString(), str.GetSize(), V2001);
    }

    /**
     * If the string has less then 6 characters,
     * the missed characters changed by 'X'.
     * If the string has more then 6 characters,
     * the created CFI will be empty.
     *
     * @deprecated Deprecated in 2.14.0, please specify standard
     */
    [[deprecated(DEPRECATE_LINK)]] CFI & operator=(const String & str)
    {
        set(str.GetCString(), str.GetSize(), V2001);
        return *this;
    }

    /**
     * If the string has less then 6 characters,
     * the missed characters changed by 'X'.
     * If the string has more then 6 characters,
     * the created CFI will be empty.
     *
     * @deprecated Deprecated in 2.14.0, please specify standard
     */
    [[deprecated(DEPRECATE_LINK)]] CFI & operator=(const char * str)
    {
        set(str, V2001);
        return *this;
    }

    /**
     * Create the CFI according to the 2015 standard.
     */
    CFI(CFICategory cat);

    /**
     * Create the CFI according to the 2015 standard.
     */
    CFI(CFIGroup group);

    CFI & operator=(const CFI &) = default;
    CFI(const CFI &) = default;

public:
    /**
     * @return CFI standard
     */
    Standard GetStandard() const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] operator String() const;

    /**
     * @return current 6-character string representation of CFI code without standard.
     */
    String GetCFICode() const;

    /**
     * Check only specified attributes in mask.
     *
     * @param        CFI mask (X is anyone character)
     * @return       'True' if CFI matches the mask, otherwise 'False'.
     *
     * @deprecated Deprecated in 2.14.0, use CFIMask::Match()
     *
     * With backward compatibility, if you use CFIs with different versions,
     * the new CFI is converted to the old format.
     */
    [[deprecated(DEPRECATE_LINK)]] bool Match(const CFI & cfi_mask) const;

    /**
     * @deprecated Deprecated in 2.14.0, use IsCashSettled() and IsPhysicallySettled()
     */
    [[deprecated(DEPRECATE_LINK)]] Delivery GetDelivery() const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] char operator[](size_t pos) const;

    /**
     * @deprecated Deprecated in 2.14.0, use GetCFICode() instead
     */
    [[deprecated(DEPRECATE_LINK)]] const char * GetCFI() const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator==(const String & value) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator!=(const String & value) const { return !operator==(value); }

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator<(const String & value) const;
    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator>(const String & value) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator<=(const String & value) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator>=(const String & value) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator==(const char * cfi) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator!=(const char * cfi) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator<(const char * cfi) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator>(const char * cfi) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator<=(const char * cfi) const;

    /**
     * @deprecated Deprecated in 2.14.0
     */
    [[deprecated(DEPRECATE_LINK)]] bool operator>=(const char * cfi) const;

public:
    /**
     * @return cfi category
     */
    std::optional<CFICategory> GetCategory() const;

    /**
     * @return true if cfi has passed category
     */
    bool HasCategory(CFICategory value) const;

    /**
     * @return cfi group
     */
    std::optional<CFIGroup> GetGroup() const;

    /**
     * @return true if cfi has passed group
     */
    bool HasGroup(CFIGroup value) const;

    /**
     * %Set attribute if category allows
     * @return true if possible set attribute, false if it is impossible or attribute empty
     */
    bool SetAttribute(CFIAttribute value);

    /**
     * @return true if cfi has passed attribute
     */
    bool HasAttribute(CFIAttribute value) const;

public:
    /// Instrument is equity instrument, including collective vehicles (e.g. ETFs)
    /// EXXXXX, CXXXXX
    bool IsEquity() const;

    /// Instrument is an option, listed or not
    /// OXXXXX, HXXXXX
    bool IsOption() const;

    /// Instrument is a future or forward
    /// FXXXXX, JXXXXX, MMFXXX
    /// @deprecated Depreacated in 2.14.0 use FutureOrForward()
    [[deprecated(DEPRECATE_LINK)]] bool IsFuture() const;

    /// Instrument is a future or forward
    /// FXXXXX, JXXXXX, MMFXXX
    bool IsFutureOrForward() const;

    /// Instrument is a forward
    /// JXXXXX, MMFXXX
    bool IsForward() const;

    /// Instrument is a warrant, mini future or similar certificate
    /// RWXXXX, RFXXXX
    bool IsWarrant() const;

    /// Instrument is any of rights, including warrant
    /// RXXXXX
    bool IsRight() const;

    /// Instrument is a subscription right
    /// RSXXXX
    bool IsSubscriptionRight() const;

    /// Instrument is a purchase right
    /// RPXXXX
    bool IsPurchaseRight() const;

    /// Instrument is a miscellaneous right, e.g. EUSIPA certificate or capped call/put
    /// RMXXXX
    bool IsRedemptionRight() const;

    /// Indicates that an instrument is any debt instrument
    /// DXXXXX
    bool IsDebtInstrument() const;

    /// 2001: EXXXXA, RXXXXA, DXXXXA
    /// 2015: EDXXXX, RDXXXX, DDXXXX
    bool IsDepositaryReceipt() const;

    /// Indicates that instrument is bond
    /// DBXXXX
    bool IsBond() const;

    /// Indicates that instrument is a convertible bond
    /// DCXXXX
    bool IsConvertibleBond() const;

    /// Indicates that instrument is a bond with warrant attached
    /// DWXXXX
    bool IsBondWithWarrant() const;

    /// Indicates that an instrument is a medium-term note
    /// DTXXXX
    bool IsMediumTermNote() const;

    /// Indicates that an instrument is a money-market instrument
    /// DYXXXX
    bool IsMoneyMarketInstrument() const;

    /// Indicates that an instrument is a miscellaneous debt instrument
    /// DMXXXX
    bool IsDebtMisc() const;

    /// Indicates that instrument is call option or call warrant
    /// OCXXXX, HXXAXX, HXXBXX, HXXCXX, RWXXCX
    bool IsCall() const;

    /// Indicates that instrument is put option or put warrant
    /// OPXXXX, HXXDXX, HXXEXX, HXXFXX, RWXXPX
    bool IsPut() const;

    /// An instrument is an American option or warrant
    /// 2001: OXAXXX
    /// 2015: OXAXXX, RWXXXA, RFXXXA, HXBXXX, HXEXXX, HXHXXX
    bool IsAmerican() const;

    /// An instrument is an European option or warrant
    /// 2001: OXEXXX
    /// 2015: OXEXXX, RWXXXE, RFXXXE, HXAXXX, HXDXXX, HXGXXX
    bool IsEuropean() const;

    /// Instrument is a currency spot or currency referential instrument
    /// MRCXXX, TCXXXX, IFXXXX
    bool IsCurrency() const;

    /// An instrument is a common, preferred or preference share. OR it's a miscellaneous equity instrument.
    /// ESXXXX, EPXXXX, EMXXXX, ERXXXX
    bool IsShare() const;

    /// Instrument is an option, warrant, future, forward based on debt instrument.
    /// Or it's a fixed-fixed swap. Or it's bond-based ETF
    /// 2001: OXXDXX, FFDXXX, RWDXXX, EUXXBX, SXDXXX, HRXXXX, JRXXXX, CIXXBX, CEXXBX, CPXXBX
    /// 2015: OXXDXX, FFDXXX, RWDXXX, EUXXBX, SRDXXX, HRXXXX, JRXXXX, CIXXBX, CEXXBX, CPXXBX
    bool UnderlyingAssetIsDebt() const;

    /// Instrument is a combination or a composite
    /// MCXXXX, KXXXXX
    /// @deprecated Deprecated in 2.14.0 use IsCombination and IsCombinedInstrument
    [[deprecated(DEPRECATE_LINK)]] bool IsComposite() const;

    /// Instrument is a combination
    /// MC[X]XXX, KXXXXX
    bool IsCombination() const;

    /// Instrument is a composite
    /// 2001: MCMXXX
    /// 2015: MC[^X]XXX
    bool IsCombinedInstrument() const;

    /// Instrument is a cash-settled option, future or forward
    /// OXXXCX, FXXCXX, HXXXXC, JXXXXC, RWXXXX, RFXXXX
    bool IsCashSettled() const;

    /// Indicates that instrument is physically-settled option, futures or warrant.
    /// OXXXPX, FXXPXX, HXXXXP, JXXXXP, RSXXXX, RAXXXX, RPXXXX
    bool IsPhysicallySettled() const;

    /// Indicates that an instrument is a unit in asset pool
    /// (e.g. ETF,  mutual fund or any other collective investment vehicle) or it's unclassified equity instrument
    /// 2001: EUXXXX
    /// 2015: CEXXXX
    bool IsETF() const;

public:
    bool Empty() const override { return (0 == m_value); }

    void Clear() { m_value = 0; }

    void ClearAttributes();

    void ClearAttribute(unsigned int i);

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_CFI; }

public:
    /**
     * Be careful with CFI-s in different standards, they are different!
     * for example: ECXXFX V2001 and ECXXFX V2015 are not the same.
     */
    bool operator==(const CFI & value) const;
    bool operator!=(const CFI & value) const;

    bool operator<(const CFI & value) const;
    bool operator>(const CFI & value) const;

    bool operator<=(const CFI & value) const;
    bool operator>=(const CFI & value) const;

public:
    CFI(const types::CFI & value);
    types::CFI get_impl() const;

private:
    bool CheckAttribute(char cat, char grp, uint8_t ind) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    void set(const char * str, Standard s);
    void set(const char * str, size_t size, Standard s);

    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    uint64_t m_value = 0;
};

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator==(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator!=(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator<(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator>(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator<=(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator>=(const String & v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator==(const char * v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator!=(const char * v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator<(const char * v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator>(const char * v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator<=(const char * v1, const CFI & v2);

/**
 * @deprecated Deprecated in 2.14.0
 */
[[deprecated(DEPRECATE_LINK)]] STRATEGY_EXPORT bool operator>=(const char * v1, const CFI & v2);
}
