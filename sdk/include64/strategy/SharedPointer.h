#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Shared Pointer Implementation. It does not use mutexes and
// therefore more performant at the expense of thread-unsafeness.
//****************************************************************************************

#include "strategy/Printable.h"
#include <utility>

namespace tbricks {

/**
 * Shared Pointer Implementation. It does not use mutexes and
 * therefore more performant at the expense of thread-unsafeness.
 *
 * If operator << is implemented for PointerType, non-null pointer would be printed using it
 */
template <typename PointerType>
class SharedPointer : public Printable
{
public:
    SharedPointer() : m_pointer(NULL), m_retain_count(nullptr) {}
    SharedPointer(PointerType * ptr) : m_pointer(ptr), m_retain_count(nullptr)
    {
        if (m_pointer != NULL) {
            m_retain_count = new long(1);
        }
    }

    SharedPointer(const SharedPointer<PointerType> & src) : m_pointer(src.m_pointer), m_retain_count(src.m_retain_count)
    {
        if (!Empty()) {
            ++*m_retain_count;
        }
    }

    ~SharedPointer(void) override { this->drop_reference(); }

    SharedPointer<PointerType> & operator=(const SharedPointer<PointerType> & src)
    {
        /* Acquire new reference */
        if (!src.Empty()) {
            ++*src.m_retain_count;
        }

        /* Release current reference */
        this->drop_reference();

        /* Copy over new data */
        m_pointer = src.m_pointer;
        m_retain_count = src.m_retain_count;

        return *this;
    }

    PointerType * operator->() const { return m_pointer; }

    PointerType & operator*() const { return *m_pointer; }

    operator PointerType *() const { return m_pointer; }

    bool Empty() const { return m_pointer == NULL; }

public:
    std::ostream & Print(std::ostream & strm) const override
    {
        if (m_pointer == NULL) {
            strm << "<nil>";
            return strm;
        }

        strm << "<SharedPointer> [" << *m_retain_count << "]: address: " << m_pointer;
        print_impl(strm, *m_pointer);
        return strm;
    }

protected:
    void drop_reference()
    {
        if (!Empty() && !--*m_retain_count) {
            delete m_retain_count;
            m_retain_count = NULL;
            delete m_pointer;
            m_pointer = NULL;
        }
    }

private:
    // More prioritized template overload working only when operator<< returning std::ostream& is defined for the type
    template <class Type, class = decltype(std::declval<std::ostream &>() << std::declval<Type>())>
    void print_impl(std::ostream & strm, const Type & value) const
    {
        strm << ", value: " << value;
    }

    // Less prioritized variadic template overload
    template <class... Type>
    void print_impl(std::ostream & strm, const Type &... value) const
    {
        // skip printing value, if we cannot print.
    }

private:
    PointerType * m_pointer;
    long * m_retain_count;
};
}
