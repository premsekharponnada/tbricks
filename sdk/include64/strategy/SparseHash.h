#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// SparseHash.
//****************************************************************************************

#include <ostream>
#include <sstream>

#include "strategy/Linkage.h"
#include "strategy/type/String.h"
#include "strategy/type/StdInt.h"

#include "sparsehash/sparse_hash_map"

// \namespace tbricks
namespace tbricks {

/**
 * SparseHash template.
 *
 * SparseHash is very memory efficient and have reasonably good execution time
 * for all operations. If table is not on a super critical path, SparseHash
 * should be always preferred to Hash table (i.e. dense hash table).
 */
template <typename KeyT, typename ValueT>
class SparseHash
{
public:
    class Key
    {
    public:
        enum KeyType
        {
            KT_Empty,
            KT_Deleted,
            KT_Value,
            KT_Pointer
        };

    public:
        Key() : m_type(KT_Empty), m_pointer(NULL) {}
        Key(bool /* deleted */) : m_type(KT_Deleted), m_pointer(NULL) {}
        Key(const KeyT & value) : m_type(KT_Value), m_value(value), m_pointer(NULL) {}
        Key(const KeyT * value) : m_type(KT_Pointer), m_pointer(value) {}

        Key(const Key & key) : m_type(key.m_type), m_pointer(NULL)
        {
            switch (m_type) {
            case KT_Value:
                m_value = key.m_value;
                break;
            case KT_Pointer:
                m_pointer = NULL;
                m_type = KT_Value;
                m_value = *key.m_pointer;
                break;
            default:
                break;
            }
        }

        Key & operator=(const Key & key)
        {
            m_type = key.m_type;
            switch (m_type) {
            case KT_Value:
                m_value = key.m_value;
                break;
            case KT_Pointer:
                m_pointer = NULL;
                m_type = KT_Value;
                m_value = *key.m_pointer;
                break;
            default:
                break;
            }
            return *this;
        }

        bool operator==(const Key & key) const
        {
            switch (m_type) {
            case KT_Empty:
            case KT_Deleted:
                return (m_type == key.m_type);
            case KT_Value:
                switch (key.m_type) {
                case KT_Value:
                    return (m_value == key.m_value);
                case KT_Pointer:
                    return (m_value == *key.m_pointer);
                default:
                    return false;
                }
            case KT_Pointer:
                switch (key.m_type) {
                case KT_Value:
                    return (*m_pointer == key.m_value);
                case KT_Pointer:
                    return (*m_pointer == *key.m_pointer);
                default:
                    return false;
                }
            default:
                return false;
            }
        }

        bool operator!=(const Key & key) const { return !operator==(key); }

        size_t get_hash() const
        {
            switch (m_type) {
            case KT_Empty:
                return 0xeeeeeeee;
            case KT_Deleted:
                return 0xdeadbeef;
            case KT_Value:
                return hash_value(m_value);
            case KT_Pointer:
                return hash_value(*m_pointer);
            default:
                return 0;
            }
        }

        operator const KeyT &() const { return get_value(); }

        const KeyT * operator->() const { return &get_value(); }

        KeyT * operator->() { return &get_value(); }

        const KeyT & operator*() const { return get_value(); }

        const KeyT & get_value() const
        {
            if (m_type == KT_Pointer) {
                return *m_pointer;
            }
            return m_value;
        }

        std::ostream & print(std::ostream & strm) const
        {
            switch (m_type) {
            case KT_Empty:
                strm << "<empty>";
                break;
            case KT_Deleted:
                strm << "<deleted>";
                break;
            case KT_Value:
                strm << m_value;
                break;
            case KT_Pointer:
                strm << "<pointer> " << *m_pointer;
                break;
            default:
                break;
            }
            return strm;
        }

        friend std::ostream & operator<<(std::ostream & strm, const Key & key) { return key.print(strm); }

    private:
        KeyType m_type;
        KeyT m_value;
        const KeyT * m_pointer;
    };

    struct KeyHash
    {
        size_t operator()(const Key & key) const { return key.get_hash(); }
    };

private:
    typedef google::sparse_hash_map<Key, ValueT, KeyHash> hash_type;

public:
    SparseHash() { init_keys(); }
    SparseHash(const SparseHash & hash) = default;
    SparseHash(SparseHash && hash) = default;
    SparseHash(size_t size) : m_hash(size) { init_keys(); }

    SparseHash & operator=(const SparseHash & hash) = default;
    SparseHash & operator=(SparseHash && hash) = default;

    typedef typename hash_type::iterator iterator;
    typedef typename hash_type::const_iterator const_iterator;
    typedef typename hash_type::key_type key_type;
    typedef typename hash_type::value_type value_type;
    typedef typename hash_type::reference reference;
    typedef typename hash_type::const_reference const_reference;

    void init_keys() { m_hash.set_deleted_key(Key(true)); }

    bool operator==(const SparseHash & hash) const { return m_hash == hash.m_hash; }
    bool operator!=(const SparseHash & hash) const { return !operator==(hash); }

    void clear() { m_hash.clear(); }
    void erase(iterator pos) { m_hash.erase(pos); }
    size_t erase(const KeyT & key) { return m_hash.erase(key); }

    void swap(SparseHash & hash) { m_hash.swap(hash.m_hash); }

    bool empty() const { return m_hash.empty(); }
    size_t size() const { return m_hash.size(); }
    void resize(size_t size) { m_hash.resize(size); }

    iterator begin() { return m_hash.begin(); }
    const_iterator begin() const { return m_hash.begin(); }

    iterator end() { return m_hash.end(); }
    const_iterator end() const { return m_hash.end(); }

    iterator find(const KeyT & key)
    {
        Key hkey(&key);
        return m_hash.find(hkey);
    }
    const_iterator find(const KeyT & key) const
    {
        Key hkey(&key);
        return m_hash.find(hkey);
    }
    ValueT & operator[](const KeyT & key)
    {
        Key hkey(&key);
        return m_hash[hkey];
    }

    std::pair<iterator, bool> insert(const typename hash_type::value_type & pair) { return m_hash.insert(pair); }
    iterator insert(iterator position, const value_type & x) { return m_hash.insert(position, x); }

public:
    size_t GetHash() const
    {
        size_t hash = 0;
        for (const auto & i : *this) {
            hash += hash_value(i.first) + hash_value(i.second);
        }
        return hash;
    }

public:
    std::ostream & Print(std::ostream & strm) const
    {
        if (empty()) {
            return strm << "<empty>";
        }
        strm << '[' << size() << ']';
        long & nindent = strm.iword(0);
        nindent += 2;
        std::string indent(nindent, ' ');
        const_iterator it = begin();
        const_iterator it_end = end();
        for (; it != it_end; ++it) {
            strm << std::endl << indent << it->first << " = " << it->second;
        }
        nindent -= 2;
        return strm;
    }

    String ToString() const
    {
        std::ostringstream strm;
        Print(strm);
        return std::move(strm).str();
    }
    friend std::ostream & operator<<(std::ostream & strm, const SparseHash & hash) { return hash.Print(strm); }

private:
    hash_type m_hash;
};

template <typename KeyT, typename ValueT>
inline size_t hash_value(const SparseHash<KeyT, ValueT> & value)
{
    return value.GetHash();
}

} // \namespace tbricks
