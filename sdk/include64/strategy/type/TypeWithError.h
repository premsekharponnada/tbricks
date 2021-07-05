#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Basic class for all types that supported errors.
//****************************************************************************************

#include "strategy/type/AnyType.h"
#include <stdlib.h>
#include <cstring>

namespace tbricks {

class STRATEGY_EXPORT TypeWithError : public AnyType
{
public:
    ~TypeWithError() override
    {
        if (m_error_text != nullptr) {
            ClearError();
        }
    }

public:
    void SetError(const String & error);
    virtual void SetError(const char * error);
    bool CheckError(const String & error_text);
    String GetError() const;
    void ClearError()
    {
        if (m_error_text != nullptr) {
            free(m_error_text);
            m_error_text = nullptr;
        }
    }

    bool HasError() const { return (m_error_text != nullptr); }

protected:
    TypeWithError() : m_error_text(nullptr) {}

    TypeWithError(const TypeWithError & src) : m_error_text(nullptr)
    {
        if (src.m_error_text != nullptr) {
            operator=(src);
        }
    }

    TypeWithError(TypeWithError && src) noexcept
    {
        m_error_text = src.m_error_text;
        src.m_error_text = nullptr;
    }

    TypeWithError & operator=(const TypeWithError & src)
    {
        if ((m_error_text == nullptr) && (src.m_error_text == nullptr)) {
            return *this;
        }
        if (this != &src) {
            CopyError(src);
        }
        return *this;
    }

    TypeWithError & operator=(TypeWithError && src) noexcept
    {
        if (this != &src) {
            ClearError();
            m_error_text = src.m_error_text;
            src.m_error_text = nullptr;
        }
        return *this;
    }

    bool equal(const TypeWithError & value) const
    {
        if (m_error_text == nullptr) {
            return (value.m_error_text == nullptr);
        }

        return (value.m_error_text != nullptr) && (std::strcmp(m_error_text, value.m_error_text) == 0);
    }

    virtual void Clear() { ClearError(); }

    size_t get_size_no_value() const;
    int encode_no_value(void * data, size_t size) const;

    size_t get_size_error() const;
    int decode_error(const void * data, size_t size);
    int encode_error(void * data, size_t size) const;

    std::ostream & PrintError(std::ostream & strm) const;

private:
    void CopyError(const TypeWithError & src);

private:
    char * m_error_text;
};
}
