#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Safe Pointer Implementation.
//****************************************************************************************

#include <cstdlib>
#include "Linkage.h"

// \namespace tbricks
namespace tbricks {

/**
 * SafePointer<> smart pointer, relies on RetainCounting interface.
 */
class SafePointerBase
{
private:
    SafePointerBase(const SafePointerBase & /* safePtr */) {}

protected:
    SafePointerBase() {}

    template <typename pointer_t>
    static long retain(pointer_t * obj)
    {
        return static_cast<typename pointer_t::RetainableType *>(obj)->retain();
    }

    template <typename pointer_t>
    static long release(pointer_t * obj)
    {
        return static_cast<typename pointer_t::RetainableType *>(obj)->release();
    }
};

/**
 *  Safe Pointer Implementation. This template implements thread-safe
 *  object reference counting much in the same spirit as SafePointer does but
 *  unlike the latter it relies on retain()/release() methods that MUST be
 *  provided by the object SafePointer holds.
 *
 *  Such implementation is quite handy for objects created outside of the
 *  user code which can be disposed asynchronously by the underlying logic.
 *  The most obvious example of such is Instrument, retained deeply
 *  in Strategy Engine machinery, and asynchronously disposed on e.g. connection
 *  loss. For objects like this, if user-level code plans to use them safely
 *  and not from object's callbacks, the code has to make sure the object is
 *  still alive when the code calls its methods, and this is exactly where
 *  SafePointer fills the bill.
 *
 *  SafePointer<> smart pointer, relies on RetainCounting interface.
 */
template <typename pointer_t>
class SafePointer : public SafePointerBase
{
public:
    typedef pointer_t value_type;

public:
    /**
     * Constructor.
     *
     * Retains pointer.
     */
    SafePointer(pointer_t * ptr = NULL) : m_pointer(ptr)
    {
        if (m_pointer != NULL)
            this->retain(m_pointer);
    }

    /**
     * Copy constructor.
     *
     * Retains pointer.
     */
    SafePointer(const SafePointer<pointer_t> & ref) : m_pointer(ref.m_pointer)
    {
        if (m_pointer != NULL)
            this->retain(m_pointer);
    }

    /**
     * Move constructor.
     *
     * Move pointer.
     */
    SafePointer(SafePointer<pointer_t> && ref) noexcept : m_pointer(std::exchange(ref.m_pointer, nullptr)) {}

    /**
     * Constructor.
     *
     * Retains pointer.
     */
    template <typename base_pointer_t>
    SafePointer(const SafePointer<base_pointer_t> & ref) : m_pointer(ref.get())
    {
        if (m_pointer != NULL)
            this->retain(m_pointer);
    }

    /**
     * Destructor.
     *
     * Releases pointer.
     */
    ~SafePointer(void)
    {
        if (m_pointer != NULL)
            this->release(m_pointer);
    }

    /**
     * Copy-on-write logic. Allocates a new object unless it is exclusively
     * (read: retain count == 1) owned by the callee.
     */
    SafePointer<pointer_t> COW(void)
    {
        if (m_pointer->get_retain_count() > 1)
            return SafePointer<pointer_t>(new pointer_t(*m_pointer));

        return *this;
    }

    /**
     * Copy operator.
     *
     * Retains new pointer, releases and replaces current pointer.
     */
    SafePointer<pointer_t> & operator=(const SafePointer<pointer_t> & ref)
    {
        /**
         * Acquire new reference
         */
        if (ref.m_pointer != NULL)
            this->retain(ref.m_pointer);

        /* Release current reference */
        if (m_pointer != NULL)
            this->release(m_pointer);

        /* Copy over new data */
        m_pointer = ref.m_pointer;

        return *this;
    }

    /**
     * Assigment operator.
     *
     * Retains new pointer, releases and replaces current pointer.
     */
    SafePointer<pointer_t> & operator=(pointer_t * ptr)
    {
        /* Retain a pointer */
        if (ptr != NULL)
            this->retain(ptr);

        /* Release current reference */
        if (m_pointer != NULL)
            this->release(m_pointer);

        /* Copy over new data */
        m_pointer = ptr;

        return *this;
    }

    /**
     * Equals operator.
     *
     * @param ref                   SafePointer<pointer_t>
     *
     * @return                      'true' if pointers are equals
     *                              'false' otherwise
     */
    bool operator==(const SafePointer<pointer_t> & ref) const { return m_pointer == ref.m_pointer; }

    /**
     * Equals operator.
     *
     * @param ptr                   pointer_t *
     *
     * @return                      'true' if pointers are equals
     *                              'false' otherwise
     */
    bool operator==(pointer_t * ptr) const { return m_pointer == ptr; }

    /**
     * Checks SafePointer emptiness.
     * SafePointer is empty, if pointer equals nullptr
     *
     * @return                      'true' if SafePointer is empty,
     *                              'false' otherwise
     */
    bool Empty() const { return (m_pointer == NULL); }

    /**
     * Clear SafePointer.
     *
     * SafePointer becomes empty after this call.
     */
    void Clear() { this->operator=(NULL); }

    /**
     * Dereference operator
     */
    pointer_t * operator->(void)const { return m_pointer; }

    /**
     * Indirection operator
     */
    pointer_t & operator*(void)const { return *m_pointer; }

    /**
     * static_cast conversion operator
     */
    operator pointer_t *(void)const { return m_pointer; }

    /**
     * Get pointer.
     *
     * Returns pointer.
     */
    pointer_t * Get(void) const { return m_pointer; }

    /**
     * Reset pointer.
     *
     * @param ptr                   New pointer
     */
    void Reset(pointer_t * ptr = NULL) { this->operator=(ptr); }

private:
    pointer_t * m_pointer;
};

} // \namespace tbricks
