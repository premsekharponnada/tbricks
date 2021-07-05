#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Binary type.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include <iostream>

namespace tbricks {

/**
 * Contains copy of data if size is not equal zero
 * or pointer on data, otherwise.
 *
 * If size equal zero, the object is not responsible for data deallocation.
 */
class STRATEGY_EXPORT Binary : public AnyType
{
public:
    using AnyType::Decode;

    /** Creates empty Binary */
    Binary();

    /**
     * If the size of the passed value is zero, shallow copy will be
     * called, otherwise it will call deep copy.
     *
     * @param value          Binary object
     */
    Binary(const Binary & value);

    /**
     * Move Binary object, the passed object will
     * be empty after move.
     *
     * @param                Binary object
     */
    Binary(Binary && other) noexcept;

    /**
     * Creates Binary from data.
     * If size is zero, it will call shallow copy,
     * otherwise deep copy.
     *
     * @param data         pointer on data
     * @param size         size od data
     */
    Binary(const void * data, size_t size = 0);

    /**
     * Free data if size is not equals zero.
     */
    ~Binary() override;

    /**
     * @see copy ctor.
     */
    Binary & operator=(const Binary & value);

    /**
     * @see move ctor.
     */
    Binary & operator=(Binary && other) noexcept;

    /**
     * @return true if size equal zero, otherwise false.
     */
    bool Empty() const override { return (m_size == 0); }

    /**
     * Free data if size is not equals zero.
     */
    void Clear();

    /**
     * @return size of data
     */
    size_t GetSize() const { return m_size; }

    /**
     * @return pointer to data
     */
    const void * GetData() const { return m_data; }

    /**
     * @return pointer to data
     */
    void * GetData() { return m_data; }

    /**
     * Exchanges the values of object and data.
     *
     * @param data         reference to the pointer to data.
     * @param size         reference to the size of data.
     */
    void Swap(void *& data, size_t & size);

    /**
     * Reallocate memory, the new pointer to data will be saved in the object.
     *
     * @param size         new size of object.
     * @return             new pointer to the data.
     */
    void * Resize(size_t size);

    /**
     * %Set the new data into the object.
     * If size is zero, it will call shallow copy,
     * otherwise deep copy.
     * Old data will be freed if old size is not equal zero.
     *
     * @param data         pointer on data
     * @param size         size od data
     */
    void Set(const void * data, size_t size);

    /**
     * Append passed data to the end of the current data.
     * If the passed size is zero, nothing to do.
     * If the old size of the object was zero, old data will be lost.
     *
     * @param              data for append
     * @size               the size of the passed data
     */
    void Append(const void * data, size_t size);

    /**
     * @see Append(const void * data, size_t size)
     */
    void Append(const Binary & value);

    /**
     * Append value to the end of the current data.
     * If the old size of the object was zero, old data will be lost.
     *
     * @param               value for append
     */
    void Append(const AnyType & value);

    /**
     * Decode the data from the specified position to the passed value.
     *
     * @param value         data will be decoded in this value
     * @param offset        the start point for decoding
     */
    bool Decode(AnyType & value, size_t & offset) const;

    /**
     * @return hash value of the object
     */
    size_t GetHash() const override;

    /**
     * @return TypeInfo of the object
     */
    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_BINARY; }

    /**
     * @see Append(const AnyType & value)
     */
    Binary & operator<<(const AnyType & value)
    {
        Append(value);
        return *this;
    }

    template <typename CodecType>
    void Append(const CodecType & value)
    {
        value.Encode(*this);
    }

    template <typename CodecType>
    Binary & operator<<(const CodecType & value)
    {
        Append(value);
        return *this;
    }

public:
    class iterator
    {
    public:
        iterator(const Binary & data, size_t offset = 0) : m_data(data), m_offset(offset) {}

        template <typename CodecType>
        iterator & operator>>(CodecType & value)
        {
            value.Decode(m_data, m_offset);
            return *this;
        }

    private:
        const Binary & m_data;
        size_t m_offset;
    };

    iterator operator>>(size_t offset) const { return iterator(*this, offset); }

    template <typename CodecType>
    iterator operator>>(CodecType & value) const
    {
        size_t offset = 0;
        value.Decode(*this, offset);
        return iterator(*this, offset);
    }

    iterator begin() const { return iterator(*this); }

public:
    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * If size of left and right operands equals zero, return true.
     */
    bool operator==(const Binary & value) const;

    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * If size of left and right operands equals zero, return false.
     */
    bool operator!=(const Binary & value) const;

    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * The object with the least size will be less.
     */
    bool operator<(const Binary & value) const;

    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * The object with the greatest size will be great.
     */
    bool operator>(const Binary & value) const;

    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * The object with the least size will be less.
     */
    bool operator<=(const Binary & value) const;

    /**
     * Compares bytes of the block of memory pointed by left operand to
     * bytes pointed by right operand.
     * The object with the greatest size will be great.
     */

    bool operator>=(const Binary & value) const;

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    void * m_data;
    size_t m_size;
};

typedef Binary UserData;
}
