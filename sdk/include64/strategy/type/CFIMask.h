#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// CFI Mask
//****************************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/CFI.h"

namespace tbricks {

namespace types {
class CFIMask;
class CFI;
}

/**
 * CFIMask is a set of CFIs.
 * It may be useful when you want to match some set of CFIs,
 * for example, all options (OXXXXX, HXXXXX) or warrants (RWXXXX, RFXXXX).
 * It is possible to create custom mask from vector of CFIs.
 * Character 'X' in passed CFI used if information may be any.
 */
class STRATEGY_EXPORT CFIMask : public AnyType
{
public:
    CFIMask();
    CFIMask(const CFI & value);
    CFIMask(const std::vector<CFI> & value);
    CFIMask(std::vector<CFI> && value);

    CFIMask(const CFIMask & mask);
    CFIMask(CFIMask && mask) = default;

    CFIMask & operator=(const CFIMask & mask);
    CFIMask & operator=(CFIMask && mask) = default;

public:
    bool operator==(const CFIMask & value) const;
    bool operator!=(const CFIMask & value) const;

    /**
     * As CFIMask consists of a set of CFIs.
     * The Match() method sequentially matches each CFI from the mask with passed.
     * It checks only specified attributes in mask.
     * Character 'X' in the mask used if information may be any.
     *
     * With backward compatibility, if you use CFIs with different versions,
     * the new CFI is converted to the old format.
     *
     * CFI matches the mask when it matches one from the set.
     *
     * @param        CFI.
     * @return       'True' if CFI matches the mask, otherwise 'False'.
     */
    bool Match(const CFI & value) const;

    /**
     * Get the vector of CFI contained in this mask
     *
     * @return       Vector of CFI.
     */
    std::vector<CFI> GetCFIs() const;

    bool Empty() const override;
    void Clear();

    CFIMask operator|(const CFIMask & value);
    CFIMask & operator|=(const CFIMask & value);

    CFIMask operator|(const CFI & value);
    CFIMask & operator|=(const CFI & value);

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_CFI_MASK; }

public:
    /// Instrument is an option, listed or not
    /// OXXXXX, HXXXXX
    static CFIMask Options();

    /// Instrument is a future or forward
    /// FXXXXX, JXXXXX, MMFXXX
    static CFIMask FuturesOrForwards();

    /// Instrument is equity instrument, including collective vehicles (e.g. ETFs)
    /// EXXXXX, CXXXXX
    static CFIMask Equities();

    /// Instrument is a future or forward
    /// FXXXXX, MMFXXX
    static CFIMask Forwards();

    /// Instrument is a warrant, mini future or similar certificate
    /// RWXXXX, RFXXXX
    static CFIMask Warrants();

    /// Instrument is any of rights, including warrant
    /// RXXXXX
    static CFIMask Rights();

    /// An instrument is an European option or warrant
    /// 2001: OXEXXX
    /// 2015: OXEXXX, RWXXXE, RFXXXE, HXAXXX, HXDXXX, HXGXXX
    static CFIMask EuropeanExerciseStyle();

    /// An instrument is an American option or warrant
    /// 2001: OXAXXX
    /// 2015: OXAXXX, RWXXXA, RFXXXA, HXBXXX, HXEXXX, HXHXXX
    static CFIMask AmericanExerciseStyle();

    /// Instrument is a combination or a composite
    /// MCXXXX, KXXXXX
    static CFIMask CombinationsOrComposites();

public:
    CFIMask(types::CFIMask && value);
    types::CFIMask get_impl() const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    std::shared_ptr<types::CFIMask> m_mask;
};
}
