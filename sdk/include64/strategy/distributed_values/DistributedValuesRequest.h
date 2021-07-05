#pragma once
//****************************************************************************
// Tbricks Strategy Framework.
//
// Copyright (c) 2006-2017 Tbricks AB.
//
// Distributed values request.
//
//****************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Pair.h"
#include "strategy/type/Identifier.h"
#include "strategy/parameter/StrategyParameters.h"

#include "strategy/distributed_values/DistributedValueDefinition.h"
#include "strategy/distributed_values/DistributedValueIdentification.h"

namespace tbricks {

typedef Identifier DistributedValuesRequestIdentifier;

/**
 *  DistributedValuesRequest class
 */
class STRATEGY_EXPORT DistributedValuesRequest : public Printable
{
public:
    DistributedValuesRequest();
    DistributedValuesRequest(const DistributedValuesRequest & request);
    DistributedValuesRequest & operator=(const DistributedValuesRequest & request);
    virtual ~DistributedValuesRequest();

public:
    DistributedValuesRequestIdentifier GetIdentifier() const;

public:
    class STRATEGY_EXPORT Object;

    class STRATEGY_EXPORT Objects
    {
    public:
        class STRATEGY_EXPORT const_iterator
        {
        public:
            const_iterator();
            const_iterator(const const_iterator & it);
            const_iterator & operator=(const const_iterator & it);
            virtual ~const_iterator();

        public:
            bool operator==(const const_iterator & it) const;
            bool operator!=(const const_iterator & it) const;

            const_iterator & operator++();
            const_iterator operator++(int);

            const Object & operator*() const;
            Object const * operator->() const;

        private:
            class Impl;
            std::unique_ptr<Impl> m_impl;

        private:
            friend STRATEGY_EXPORT class Objects;

            const_iterator(std::unique_ptr<Impl> & ptr);
        };

    public:
        const_iterator begin() const;
        const_iterator end() const;

    public:
        /**
         * Returns vector of requested objects with parameters.
         *
         * CAUTION! ADDITIONAL ALLOCATION & COPYING:
         * Method may lead to allocations and copying data to vector structure.
         * Please use Objects::const_iterator to avoid unneccessary allocation and copying.
         */
        void Get(std::vector<Object> & objects) const;

    private:
        friend STRATEGY_EXPORT class DistributedValuesRequest;

        Objects(const DistributedValuesRequest & request);

    private:
        const DistributedValuesRequest & m_request;
    };

    /**
     * Class for accessing DistributedValuesRequest::Object information
     */
    class STRATEGY_EXPORT Object : public Printable
    {
    public:
        Object() = default;
        Object(const Object & object) = default;
        Object & operator=(const Object & object) = default;
        virtual ~Object() = default;

    public:
        const Identifier & GetIdentifier() const { return m_identifier; }

        const StrategyParameters & GetParameters() const { return m_parameters; }

    protected:
        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        friend STRATEGY_EXPORT class Objects;
        friend STRATEGY_EXPORT class Objects::const_iterator;

    private:
        Identifier m_identifier;
        StrategyParameters m_parameters;
    };

public:
    class STRATEGY_EXPORT Value;

    class STRATEGY_EXPORT Values
    {
    public:
        class STRATEGY_EXPORT const_iterator
        {
        public:
            const_iterator();
            const_iterator(const const_iterator & it);
            const_iterator & operator=(const const_iterator & it);
            virtual ~const_iterator();

        public:
            bool operator==(const const_iterator & it) const;
            bool operator!=(const const_iterator & it) const;

            const_iterator & operator++();
            const_iterator operator++(int);

            const Value & operator*() const;
            Value const * operator->() const;

        private:
            class Impl;
            std::unique_ptr<Impl> m_impl;

        private:
            friend STRATEGY_EXPORT class Values;

            const_iterator(std::unique_ptr<Impl> & ptr);
        };

    public:
        const_iterator begin() const;
        const_iterator end() const;

    public:
        /**
         * Returns vector of requested objects with parameters.
         *
         * CAUTION! ADDITIONAL ALLOCATION & COPYING:
         * Method may lead to allocations and copying data to vector structure.
         * Please use Values::const_iterator to avoid unneccessary allocation and copying.
         */
        void Get(std::vector<Value> & values) const;

    private:
        friend STRATEGY_EXPORT class DistributedValuesRequest;

        Values(const DistributedValuesRequest & request);

    private:
        const DistributedValuesRequest & m_request;
    };

    /**
     * Class for accessing DistributedValuesRequest::Value information
     */
    class STRATEGY_EXPORT Value : public Printable
    {
    public:
        Value() = default;
        Value(const Value & value) = default;
        Value & operator=(const Value & value) = default;
        virtual ~Value() = default;

    public:
        const Identifier & GetIdentifier() const { return m_identifier; }

        const DistributedValueDefinition & GetDefinition() const { return m_definition; }

        const StrategyParameters & GetParameters() const { return m_parameters; }

    protected:
        virtual std::ostream & Print(std::ostream & strm) const;

    private:
        friend STRATEGY_EXPORT class DistributedValuesRequest;

    private:
        Identifier m_identifier;
        DistributedValueDefinition m_definition;
        StrategyParameters m_parameters;
    };

    void GetValues(std::vector<Value> & values) const;

public:
    Objects GetObjects() const;
    Values GetValues() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    friend STRATEGY_EXPORT class Converter;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

/**
 *  DistributedValuesReply class
 */
class STRATEGY_EXPORT DistributedValuesReply : public Printable
{
public:
    DistributedValuesReply(const DistributedValuesRequestIdentifier & identifier, bool supported);
    DistributedValuesReply(const DistributedValuesReply & reply);
    DistributedValuesReply & operator=(const DistributedValuesReply & reply);
    virtual ~DistributedValuesReply();

public:
    const DistributedValuesRequestIdentifier & GetIdentifier() const;

public:
    void SetSupported(bool supported);
    bool Supported() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    DistributedValuesReply();

    friend STRATEGY_EXPORT class Converter;

private:
    DistributedValuesRequestIdentifier m_identifier;
    bool m_supported;
};
}
