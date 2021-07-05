#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Variant type
//
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Exception.h"

#include "strategy/type/Identifier.h"
#include "strategy/type/Boolean.h"
#include "strategy/type/Integer.h"
#include "strategy/type/Enumeration.h"
#include "strategy/type/Double.h"
#include "strategy/type/String.h"
#include "strategy/type/DateTime.h"
#include "strategy/type/Date.h"
#include "strategy/type/Time.h"
#include "strategy/type/Price.h"
#include "strategy/type/Volume.h"
#include "strategy/type/InstrumentIdentifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include "strategy/type/Venue.h"
#include "strategy/type/SmartDouble.h"
#include "strategy/type/PortfolioIdentifier.h"
#include "strategy/type/Side.h"
#include "strategy/type/TradeIdentifier.h"
#include "strategy/type/RankingIdentifier.h"
#include "strategy/type/MIC.h"
#include "strategy/type/CFI.h"
#include "strategy/type/Currency.h"
#include "strategy/type/Table.h"
#include "strategy/type/Binary.h"
#include "strategy/calculated_property/GridSelection.h"
#include "strategy/calculated_property/CalculatedProperty.h"
#include "strategy/calculated_property/CalculatedPropertyFilter.h"
#include "strategy/type/LiquidityPoolIdentifier.h"
#include "strategy/type/TreeNodeIdentifier.h"
#include "strategy/type/SubsystemIdentifier.h"
#include "strategy/type/LegalEntityIdentifier.h"
#include "strategy/type/TreeTypeIdentifier.h"
#include "strategy/type/MMTFlags.h"
#include "strategy/type/BinaryTable.h"

/// @cond PRIVATE
// clang-format off
#define DEFINE_VARIANT_TYPES(OpName)              \
DEFINE_VARIANT_##OpName(PortfolioIdentifier)      \
DEFINE_VARIANT_##OpName(InstrumentIdentifier)     \
DEFINE_VARIANT_##OpName(Price)                    \
DEFINE_VARIANT_##OpName(Volume)                   \
DEFINE_VARIANT_##OpName(String)                   \
DEFINE_VARIANT_##OpName(Double)                   \
DEFINE_VARIANT_##OpName(SmartDouble)              \
DEFINE_VARIANT_##OpName(Boolean)                  \
DEFINE_VARIANT_##OpName(Side)                     \
DEFINE_VARIANT_##OpName(Venue)                    \
DEFINE_VARIANT_##OpName(Integer)                  \
DEFINE_VARIANT_##OpName(Enumeration)              \
DEFINE_VARIANT_##OpName(DateTime)                 \
DEFINE_VARIANT_##OpName(Date)                     \
DEFINE_VARIANT_##OpName(Time)                     \
DEFINE_VARIANT_##OpName(TradeIdentifier)          \
DEFINE_VARIANT_##OpName(MIC)                      \
DEFINE_VARIANT_##OpName(CFI)                      \
DEFINE_VARIANT_##OpName(Currency)                 \
DEFINE_VARIANT_##OpName(Duration)                 \
DEFINE_VARIANT_##OpName(Identifier)               \
DEFINE_VARIANT_##OpName(InstrumentGroupIdentifier)\
DEFINE_VARIANT_##OpName(Table)                    \
DEFINE_VARIANT_##OpName(Binary)                   \
DEFINE_VARIANT_##OpName(GridSelection)            \
DEFINE_VARIANT_##OpName(CalculatedProperty)       \
DEFINE_VARIANT_##OpName(CalculatedPropertyFilter) \
DEFINE_VARIANT_##OpName(TreeNodeIdentifier)       \
DEFINE_VARIANT_##OpName(LiquidityPoolIdentifier)  \
DEFINE_VARIANT_##OpName(SubsystemIdentifier)      \
DEFINE_VARIANT_##OpName(LegalEntityIdentifier)    \
DEFINE_VARIANT_##OpName(TreeTypeIdentifier)       \
DEFINE_VARIANT_##OpName(MMTFlags)                 \
DEFINE_VARIANT_##OpName(BinaryTable)              \
DEFINE_VARIANT_##OpName(RankingIdentifier)
// clang-format on

namespace tbricks::types {
class Any;
}
/// @endcond

// \namespace tbricks
namespace tbricks {

/**
 * The class Variant represents a type-safe union of AnyType classes. An instance
 * of Variant at any given time either holds a value of one of its alternative
 * types, or be in empty, or remove state.
 *
 * Supported types: PortfolioIdentifier, InstrumentIdentifier, Price, Volume, String,
 * Double, SmartDouble, Boolean, Side, Venue, Integer, Enumeration, DateTime, Date,
 * Time, TradeIdentifier, Mic, CFI, Currency, Duration, Identifier, InstrumentGroupIdentifier
 * Table, Binary, GridSelection, CalculatedProperty, CalculatedPropertyFilter, TreeNodeIdentifier
 * LiquidityPoolIdentifier, SubsystemIdentifier, LegalEntityIdentifier, TreeTypeIdentifier
 * MMTFlags, BinaryTable, RankingIdentifier
 */
class STRATEGY_EXPORT Variant : public AnyType
{
private:
    template <class T>
    using is_supported_type = std::disjunction<
#define DEFINE_VARIANT_IS_SAME(Type) std::is_same<T, Type>,
        DEFINE_VARIANT_TYPES(IS_SAME) std::is_same<T, void>>;
#undef DEFINE_VARIANT_IS_SAME

public:
    Variant() {}
    Variant(const Variant & value);
    Variant(Variant && value) noexcept;
    Variant & operator=(const Variant & value);
    Variant & operator=(Variant && value) noexcept;

#define DEFINE_VARIANT_DEF_CONSTRUCTOR(Type)    \
    Variant(const Type & value) { Set(value); } \
    Variant(Type && value) { Set(std::move(value)); }
    DEFINE_VARIANT_TYPES(DEF_CONSTRUCTOR);
#undef DEFINE_VARIANT_DEF_CONSTRUCTOR

    /// Construct a new Variant object held String object constructed from \p value.
    Variant(const char * str) { Set(str); }
    /// Construct a new Variant object held Integer object constructed from \p value.
    Variant(int value) { Set(value); }
    /// Construct a new Variant object held Double object constructed from \p value.
    Variant(double value) { Set(value); }
    /// Construct a new Variant object held Identifier object constructed from \p value.
    Variant(const Uuid & value) { Set(value); }
    // Destroys the variant, along with its contained value
    ~Variant() override;

    /**
     * Creates a Variant object for AnyType.
     *
     * @exception Exception if object \p value object type is not supported
     *
     * @return                          variant object
     */
    static Variant Create(const AnyType & value);

    /**
     * Creates a Variant object from another variant object.
     *
     * @return                          variant object
     */
    static Variant Create(const Variant & value);

    /**
     * Creates a Variant object held Identifier object constructed from \p value.
     *
     * @return                          variant object
     */
    static Variant Create(const Uuid & value);

    /**
     * Returns the TypeInfo of the alternative that is currently held by the variant.
     * If the variant is empty or in remove state return Variant's TypeInfo.
     *
     * @return                          TypeInfo object
     */
    TypeInfo GetValueTypeInfo() const;

    /**
     * Checks if the variant holds the alternative which is
     * compatible with \p type.
     *
     * @param type                      TypeInfo type
     *
     * @return                          "true" if variant holds the alternative
     *                                  which is compatible with \p type,
     *                                  "false" otherwise.
     */
    bool IsCompatibleType(TypeInfo::Type type) const;

    PortfolioIdentifier GetPortfolioIdentifier() const;
    InstrumentIdentifier GetInstrumentIdentifier() const;
    Price GetPrice() const;
    Volume GetVolume() const;
    String GetString() const;
    Double GetDouble() const;
    SmartDouble GetSmartDouble() const;
    Boolean GetBoolean() const;
    Side GetSide() const;
    Venue GetVenue() const;
    Integer GetInteger() const;
    Enumeration GetEnumeration() const;
    DateTime GetDateTime() const;
    Date GetDate() const;
    Time GetTime() const;
    TradeIdentifier GetTradeIdentifier() const;
    MIC GetMIC() const;
    CFI GetCFI() const;
    Currency GetCurrency() const;
    Duration GetDuration() const;
    Identifier GetIdentifier() const;
    InstrumentGroupIdentifier GetInstrumentGroupIdentifier() const;
    TreeNodeIdentifier GetTreeNodeIdentifier() const;
    RankingIdentifier GetRankingIdentifier() const;
    const Table & GetTable() const;
    const Binary & GetBinary() const;
    const GridSelection & GetGridSelection() const;
    const CalculatedProperty & GetCalculatedProperty() const;
    bool Get(AnyType & any) const;
    LiquidityPoolIdentifier GetLiquidityPoolIdentifier() const;
    SubsystemIdentifier GetSubsystemIdentifier() const;
    LegalEntityIdentifier GetLegalEntityIdentifier() const;
    TreeTypeIdentifier GetTreeTypeIdentifier() const;
    MMTFlags GetMMTFlags() const;
    BinaryTable GetBinaryTable() const;
    CalculatedPropertyFilter GetCalculatedPropertyFilter() const;

    /**
     * Applies the visitor \p vis to the variant
     *
     * @param vis                       visitor
     *
     * The return type is deduced from the returned expression as if by decltype.
     *
     * The call is ill-formed if the invocation of visitor is not a valid expression
     * of the same type and value category, for all alternative types of the variant.
     *
     * @return                          result form the visitor
     */
    template <typename Visitor>
    decltype(auto) Visit(Visitor && vis) const
    {
        return visit_value(*this, std::forward<Visitor>(vis));
    }

    /**
     * Applies the visitor \p vis to the variant
     *
     * @param vis                       visitor
     *
     * The return type is deduced from the returned expression as if by decltype.
     *
     * The call is ill-formed if the invocation of visitor is not a valid expression
     * of the same type and value category, for all alternative types of the variant.
     *
     * @return                          result form the visitor
     */
    template <typename Visitor>
    decltype(auto) Visit(Visitor && vis)
    {
        return visit_value(*this, std::forward<Visitor>(vis));
    }

    /**
     * Assigne a new value to the variant object
     *
     * @param value                     new value
     */
    template <typename T, typename = std::enable_if_t<is_supported_type<T>::value>>
    void Set(const T & value)
    {
        Emplace<T>(value);
    }

    /**
     * Assigne a new value to the variant object
     *
     * @param value                     new value
     */
    template <typename T, typename = std::enable_if_t<is_supported_type<std::decay_t<T>>::value>>
    void Set(T && value)
    {
        Emplace<std::decay_t<T>>(std::forward<T>(value));
    }

    void Set(const Variant & value);
    void Set(Variant && value);
    void Set(const char * str) { Emplace<String>(str); }
    void Set(int value) { Emplace<Integer>(value); }
    void Set(double value) { Emplace<Double>(value); }
    void Set(const Uuid & value) { Emplace<Identifier>(value); }

    void Clear();

    /**
     * Check if variant does holds a value and value is not empty
     *
     * @return                          "true" if variant holds a value,
     *                                  "false" otherwise
     */
    bool Empty() const override;

    /**
     * Check if variant holds a value.
     *
     * @return                          "true" if variant holds a value,
     *                                  "false" otherwise
     */
    bool IsValueAssigned() const noexcept;

    /**
     * Checks if the variant holds the alternative object with
     * error.
     *
     * @see TypeWithError
     *
     * @return                          "true" if variant holds a value,
     *                                  "false" otherwise
     */
    bool HasError() const;

    /**
     * Returns an error text if the variant holds the alternative object with
     * error.
     *
     * @see TypeWithError
     *
     * @return                          Error text if variant holds the alternative
     *                                  object with error, empty String otherwise
     */
    String GetError() const;

    /**
     * Sets remove state to the variant.
     */
    void SetRemove();

    /**
     * Check if the variant in remove state.
     *
     * @return                          "true" if variant in remove state,
     *                                  "false" otherwise
     */
    bool IsRemove() const;

    /**
     * Assigne a new value to the variant object
     *
     * @param value                     new value
     */
    template <typename T>
    Variant & operator=(T && value)
    {
        Set(std::forward<T>(value));
        return *this;
    }

    /**
     * Checks equality for variants
     * - if both variant does not hold value, return true
     * - if variant hold different alternatives, returns false
     * - otherwise returns result of operator== of the alternative
     *
     * @return                          the boolean result of the comparison as
     *                                  described above.
     */
    bool TypeEqual(const Variant & value) const;

    int Compare(const Variant & value) const;

    bool operator==(const Variant & value) const;
    bool operator!=(const Variant & value) const;

    bool operator>(const Variant & value) const;
    bool operator<(const Variant & value) const;

    bool operator>=(const Variant & value) const;
    bool operator<=(const Variant & value) const;

public:
    std::ostream & Print(std::ostream & strm) const override;
    std::ostream & PrintWithType(std::ostream & strm) const;

    /**
     * Get limit filter conditions hash
     *
     * @return                          Hash for limit filter conditions
     */
    size_t GetHash() const override;

public:
    /// @cond PRIVATE
    Variant(const void * data, size_t size);

    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    int decode_keep_typed_empty(const types::Any & v, const CalculatedPropertyDefinition & def);
    int decode_keep_typed_empty(const void * data, size_t size, const CalculatedPropertyDefinition & def);
    int decode_sf_type(TypeInfo::Type type, const void * data, size_t size);
    /// @endcond

    /// Internal usage only (use GetValueTypeInfo)
    static TypeInfo GetTypeInfo();
    static TypeInfo GetTypeInfo(int any_type);

private:
    void import_type(const CalculatedPropertyDefinition & def, const void * data, size_t size);

    template <typename Type>
    const Type & get() const
    {
        check_type(Type::GetTypeInfo().GetType());
        return get_impl<Type>(*this);
    }

    template <typename Type>
    Type & get()
    {
        check_type(Type::GetTypeInfo().GetType());
        return get_impl<Type>(*this);
    }

    void check_type(TypeInfo::Type type) const
    {
        if (type != m_type) {
            throw_type_mismatch(type);
        }
    }
    void throw_type_mismatch(TypeInfo::Type type) const;

    template <typename Variant_T, typename Func_T>
    static decltype(auto) visit_value(Variant_T & value, Func_T && func)
    {
        switch (value.m_type) {
#define DEFINE_VARIANT_SWITCH(Type)     \
    case Type::GetTypeInfo().GetType(): \
        return func(get_impl<Type>(value));
            DEFINE_VARIANT_TYPES(SWITCH)
#undef DEFINE_VARIANT_SWITCH
        case TypeInfo::SFT_REMOVE:
            return func(Remove::REMOVE);
        default:
            assert(false);
        case TypeInfo::SFT_NONE:
            return func();
        }
    }

    template <typename T>
    int set_any_impl(const void * data, size_t size);
    int set_any(const void * data, size_t size, bool keep_typed_empty);

    Double cast_numeric() const;

private:
    template <typename T>
    static constexpr bool is_requires_allocation()
    {
        return sizeof(T) > sizeof(m_stack);
    }

    template <typename T, typename = std::enable_if_t<is_supported_type<T>::value>>
    void destroy()
    {
        m_type = TypeInfo::SFT_NONE;
        if constexpr (!is_requires_allocation<T>())
            (reinterpret_cast<T *>(&m_stack))->T::~T();
        else {
            delete reinterpret_cast<T *>(m_dynamic);
        }
    }

    template <typename T, typename... Args, typename = std::enable_if_t<is_supported_type<T>::value>>
    T & Emplace(Args &&... args)
    {
        if (m_type != TypeInfo::SFT_NONE) {
            Clear();
        }
        m_type = T::GetTypeInfo().GetType();
        if constexpr (!is_requires_allocation<T>())
            return *(new (&m_stack) T(std::forward<Args>(args)...));
        else {
            return *static_cast<T *>(m_dynamic = new T(std::forward<Args>(args)...));
        }
    }

    template <typename T, typename VariantT, typename = std::enable_if_t<is_supported_type<T>::value>>
    static decltype(auto) get_impl(VariantT & value)
    {
        assert(value.m_type == T::GetTypeInfo().GetType());
        using U = std::conditional_t<std::is_const_v<VariantT>, std::add_const_t<T>, T>;
        if constexpr (!is_requires_allocation<T>())
            return *reinterpret_cast<U *>(&value.m_stack);
        else
            return *reinterpret_cast<U *>(value.m_dynamic);
    }

private:
    enum class Remove
    {
        REMOVE
    };

private:
    static constexpr size_t c_buffer_size = 48;
    using stack_storage_t = typename std::aligned_storage_t<c_buffer_size, std::alignment_of_v<void *>>;

private:
    TypeInfo::Type m_type = TypeInfo::SFT_NONE;
    union
    {
        AnyType * m_dynamic;
        stack_storage_t m_stack;
    };
};

} // namespace tbricks
