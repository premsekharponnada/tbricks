#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Limit settings
//
//****************************************************************************

#include "strategy/LimitSettingsParameters.h"
#include "strategy/Linkage.h"
#include "strategy/Printable.h"
#include "strategy/Strategy.h"
#include "strategy/type/Integer.h"
#include "strategy_generated/LimitSettingsBase.h"
#include "strategy_generated/LimitSettingsModifierBase.h"
#include "strategy_generated/LimitSettingsOptionsBase.h"
#include "strategy_generated/LimitSettingsUpdateBase.h"

#include <memory>

namespace tbricks {

namespace types {
class Parameters;
}

namespace protocol {
class LimitSettings;
class LimitFilterCondition;
class LimitSettingsAddRequest;
class LimitSettingsUpdateRequest;
}

/**
 * LimitSettings object stores a collection of limit
 * settings and, through nested auxiliary classes,
 * provides for distant manipulations.
 */
class STRATEGY_EXPORT LimitSettings : public LimitSettingsBase
{
public:
    class FilterConditions;
    class Values;
    class Update;
    class RequestResult;
    class Options;
    class Modifier;
    class Stream;

public:
    using LimitSettingsBase::LimitSettingsBase;

public:
    /**
     * Send limit settings create request.
     *
     * Limit settings create request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Limit settings creation options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier, for later use
     *                                  in HandleRequestReply() method
     */
    static RequestResult SendCreateRequest(const LimitSettings::Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send limit settings modify request.
     *
     * Limit settings modify request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param modifier                  Limit settings modification request
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier, for later use
     *                                  in HandleRequestReply() method
     */
    static RequestResult SendModifyRequest(const Identifier & id,
                                           const LimitSettings::Modifier & modifier,
                                           IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send limit settings delete request.
     *
     * Limit settings delete request is a remote operation and its status is
     * delivered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param id                        Limit identifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          Request identifier, for later use
     *                                  in HandleRequestReply() method
     */
    static RequestResult SendDeleteRequest(const Identifier & id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    /**
     * Check if limit settings contain limit definition
     *
     * @return                          True if limit settings contain limit definition, false otherwise
     */
    bool HasDefinition() const;

    /**
     * Get limit definition
     *
     * @return                          Limit definition or empty definition
     */
    ParameterDefinition GetDefinition() const;

    /**
     * Check if limit settings contain filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @return                          True if limit settings contain filter conditions, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasFilterConditions() const;

    /**
     * Get limit filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit filter conditions or empty filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] FilterConditions GetFilterConditions() const;

    /**
     * Check if limit settings contain values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @return                          True if limit settings contain values, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasValues() const;

    /**
     * Get limit values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit values or empty values
     */
    [[deprecated(DEPRECATE_LINK)]] Values GetValues() const;

    /**
     * Check if limit settings contain a particular filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @return                          True if limit settings contain given filter condition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasFilterCondition(const ParameterDefinition & definition) const;

    /**
     * Get particular limit filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @param value                     Result
     * @return                          True if limit settings contain given filter condition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilterCondition(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Check if limit settings contain a particular value
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @return                          True if limit settings contain given value, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasValue(const ParameterDefinition & definition) const;

    /**
     * Get particular limit value
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @param value                     Result
     * @return                          True if limit settings contain given value, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetValue(const ParameterDefinition & definition, AnyType & value) const;

public:
    /**
     * Merge the update of limit settings
     *
     * @param update                    Update of limit settings
     */
    void Merge(const LimitSettings::Update & update);
};

/**
 * LimitSettings::Update, collection of updated limit settings.
 */
class STRATEGY_EXPORT LimitSettings::Update : public LimitSettingsUpdateBase
{
public:
    using LimitSettingsUpdateBase::LimitSettingsUpdateBase;

public:
    /**
     * Check if limit settings update contains limit definition
     *
     * @return                          True if limit settings update contains limit definition, false otherwise
     */
    bool HasDefinition() const;

    /**
     * Get limit definition
     *
     * @return                          Limit definition or empty definition
     */
    ParameterDefinition GetDefinition() const;

    /**
     * Check if limit settings update contains filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @return                          True if limit settings update contains filter conditions, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasFilterConditions() const;

    /**
     * Get limit filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit filter conditions or empty filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] FilterConditions GetFilterConditions() const;

    /**
     * Check if limit settings update contains values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use HasParameters instead.
     *
     * @return                          True if limit settings update contains values, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasValues() const;

    /**
     * Get limit values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit values or empty values
     */
    [[deprecated(DEPRECATE_LINK)]] Values GetValues() const;

    /**
     * Check if limit settings update contains a particular filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @return                          True if limit settings update contains given filter condition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasFilterCondition(const ParameterDefinition & definition) const;

    /**
     * Get particular limit filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @param value                     Result
     * @return                          True if limit settings update contains given filter condition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilterCondition(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Check if limit settings update contains a particular value
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @return                          True if limit settings update contains given value, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool HasValue(const ParameterDefinition & definition) const;

    /**
     * Get particular limit value
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container
     * @param value                     Result
     * @return                          True if limit settings update contains given value, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetValue(const ParameterDefinition & definition, AnyType & value) const;

private:
    friend class LimitSettings;
};

/**
 * LimitSettings::RequestResult object.
 *
 * Defines feedback information after the creation, modification or deletion of limit settings.
 * Consists of limit identifier and request identifier.
 */
class STRATEGY_EXPORT LimitSettings::RequestResult : public Printable
{
public:
    /**
     * Default constructor, creates an empty object
     */
    RequestResult() = default;

    /**
     * Constructor accepting request identifier and limit identifier
     *
     * @param request_identifier        Request identifier
     * @param identifier                Limit identifier
     */
    RequestResult(const Identifier & request_identifier, const Identifier & identifier) :
        m_request_identifier(request_identifier),
        m_identifier(identifier)
    {}

    /**
     * Get request identifier
     *
     * @return                          Request identifier
     */
    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }

    /**
     * Get limit identifier
     *
     * @return                          Limit identifier
     */
    const Identifier & GetLimitIdentifier() const { return m_identifier; }

public:
    /**
     * Print request result contents to the output stream
     *
     * @param                           Output stream
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_identifier;
    Identifier m_identifier;
};

/**
 * LimitSettings::FilterCondition, helper class representing a collection
 * of limit filter conditions.
 */
class STRATEGY_EXPORT LimitSettings::FilterConditions : public Printable
{
public:
    /**
     * Default constructor, creates an empty object
     */
    FilterConditions();

    /**
     * Copy constructor
     */
    FilterConditions(const FilterConditions & conditions);

    /**
     * Move constructor
     */
    FilterConditions(FilterConditions && conditions) noexcept;

    /**
     * Copy assignment
     */
    FilterConditions & operator=(const FilterConditions & conditions);

    /**
     * Move assignment
     */
    FilterConditions & operator=(FilterConditions && conditions) noexcept;

    /**
     * Destructor
     */
    ~FilterConditions() override;

    /**
     * Equality operator
     *
     * @param filter_conditions         Filter conditions checked for equality with the current ones
     * @return                          True if compared filter conditions are equal, false otherwise
     */
    bool operator==(const FilterConditions & filter_conditions) const;

    /**
     * Inequality operator
     *
     * @param filter_conditions         Filter conditions checked for inequality with the current ones
     * @return                          True if compared filter conditions are not equal, false otherwise
     */
    bool operator!=(const FilterConditions & filter_conditions) const;

    /**
     * Get limit filter conditions hash
     *
     * @return                          Hash for limit filter conditions
     */
    size_t GetHash() const;

public:
    /**
     * Check if a particular filter condition exists
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    bool HasCondition(const ParameterDefinition & definition) const;

    /**
     * Fetch a particular limit filter condition
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Result
     *
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    bool GetCondition(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Set particular limit filter condition
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Limit filter condition value
     */
    void SetCondition(const ParameterDefinition & definition, const AnyType & value);

public:
    /**
     * LimitSettings::FilterConditions::const_iterator, helper class
     * providing the ability to iterate over the filter conditions.
     */
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        /**
         * Default constructor, creates an empty object
         */
        const_iterator();

        /**
         * Copy constructor
         */
        const_iterator(const const_iterator & it);

        /**
         * Copy assignment
         */
        const_iterator & operator=(const const_iterator & it);

        /**
         * Destructor
         */
        ~const_iterator() override;

        /**
         * Equality operator
         *
         * @param it                    Iterator checked for equality with the current one
         * @return                      True if compared iterators are equal, false otherwise
         */
        bool operator==(const const_iterator & it) const;

        /**
         * Inequality operator
         *
         * @param it                    Iterator checked for inequality with the current one
         * @return                      True if compared iterators are not equal, false otherwise
         */
        bool operator!=(const const_iterator & it) const;

        /**
         * Prefix increment operator
         */
        const_iterator & operator++();

        /**
         * Postfix increment operator
         */
        const_iterator operator++(int);

        /**
         * Dereferencing operator - returns the iterator itself, is required for range based for
         */
        const_iterator & operator*();

        /**
         * Clear the iterator i.e. reset it to empty state
         */
        void Clear();

        /**
         * Check the iterator for emptiness
         *
         * @return                      True if iterator is empty i.e. doesn't point anywhere, false otherwise
         */
        bool Empty() const;

    public:
        /**
         * Get limit filter condition definition
         *
         * @return                      Limit filter condition definition, empty if the definition cannot be resolved
         */
        ParameterDefinition GetDefinition() const;

        /**
         * Get limit filter condition value
         *
         * @param value                 Result
         * @return                      True if limit filter condition value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(AnyType & value) const;

        /**
         * Get limit filter condition value
         *
         * @param value                 Result
         * @return                      True if limit filter condition value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(Variant & value) const;

        /**
         * Print limit filter conditions iterator to the output stream
         *
         * @param                           Output stream
         */
        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class LimitSettings;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    /**
     * Get begin iterator for limit filter conditions
     *
     * @return                          Begin iterator for limit filter conditions
     */
    const_iterator begin() const;

    /**
     * Get end iterator for limit filter conditions
     *
     * @return                          End iterator for limit filter conditions
     */
    const_iterator end() const;

public:
    /**
     * Check limit filter conditions for emptiness
     *
     * @return                          True if limit filter conditions are empty, false otherwise
     */
    bool Empty() const;

    /**
     * Clear all contents from limit filter conditions i.e. reset them to the same state as the one right after calling
     * the default constructor
     */
    void Clear();

    /**
     * Get the number of limit filter conditions
     *
     * @return                          The number of limit filter conditions
     */
    size_t GetSize() const;

public:
    /**
     * Print limit filter conditions to the output stream
     *
     * @param                           Output stream
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    friend class LimitSettings;
    friend class LimitSettings::Update;
    friend class LimitSettings::Options;

private:
    std::unique_ptr<types::Parameters> m_parameters;
};

inline size_t hash_value(const LimitSettings::FilterConditions & value)
{
    return value.GetHash();
}

/**
 * LimitSettings::Values, helper class representing a collection
 * of limit values.
 */
class STRATEGY_EXPORT LimitSettings::Values : public Printable
{
public:
    /**
     * Default constructor, creates an empty object
     */
    Values();

    /**
     * Copy constructor
     */
    Values(const Values & values);

    /**
     * Move constructor
     */
    Values(Values && values) noexcept;

    /**
     * Copy assignment
     */
    Values & operator=(const Values & values);

    /**
     * Move assignment
     */
    Values & operator=(Values && values) noexcept;

    /**
     * Destructor
     */
    ~Values() override;

    /**
     * Equality operator
     *
     * @param values                    Values checked for equality with the current ones
     * @return                          True if compared values are equal, false otherwise
     */
    bool operator==(const Values & values) const;

    /**
     * Inequality operator
     *
     * @param values                    Values checked for inequality with the current ones
     * @return                          True if compared values are not equal, false otherwise
     */
    bool operator!=(const Values & values) const;

    /**
     * Get limit values hash
     *
     * @return                          Hash for limit values
     */
    size_t GetHash() const;

public:
    /**
     * Check if a particular limit value exists
     *
     * @param definition                Parameter definition, used as a key to the container of limit values
     * @return                          True if limit value exists for given definition, false otherwise
     */
    bool HasValue(const ParameterDefinition & definition) const;

    /**
     * Fetch a particular limit value
     *
     * @param definition                Parameter definition, used as a key to the container of limit values
     * @param value                     Result
     *
     * @return                          True if limit value exists for given definition, false otherwise
     */
    bool GetValue(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Set particular limit value
     *
     * @param definition                Parameter definition, used as a key to the container of limit values
     * @param value                     Limit value
     */
    void SetValue(const ParameterDefinition & definition, const AnyType & value);

public:
    /**
     * LimitSettings::Values::const_iterator, helper class
     * providing the ability to iterate over the limit values.
     */
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        /**
         * Default constructor, creates an empty object
         */
        const_iterator();

        /**
         * Copy constructor
         */
        const_iterator(const const_iterator & it);

        /**
         * Copy assignment
         */
        const_iterator & operator=(const const_iterator & it);

        /**
         * Destructor
         */
        ~const_iterator() override;

        /**
         * Equality operator
         *
         * @param it                    Iterator checked for equality with the current one
         * @return                      True if compared iterators are equal, false otherwise
         */
        bool operator==(const const_iterator & it) const;

        /**
         * Inequality operator
         *
         * @param it                    Iterator checked for inequality with the current one
         * @return                      True if compared iterators are not equal, false otherwise
         */
        bool operator!=(const const_iterator & it) const;

        /**
         * Prefix increment operator
         */
        const_iterator & operator++();

        /**
         * Postfix increment operator
         */
        const_iterator operator++(int);

        /**
         * Dereferencing operator - returns the iterator itself, is required for range based for
         */
        const_iterator & operator*();

        /**
         * Clear the iterator i.e. reset it to empty state
         */
        void Clear();

        /**
         * Check the iterator for emptiness
         *
         * @return                      True if iterator is empty i.e. doesn't point anywhere, false otherwise
         */
        bool Empty() const;

    public:
        /**
         * Get limit value definition
         *
         * @return                      Limit value definition, empty if the definition cannot be resolved
         */
        ParameterDefinition GetDefinition() const;

        /**
         * Get limit value
         *
         * @param value                 Result
         * @return                      True if limit value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(AnyType & value) const;

        /**
         * Get limit value
         *
         * @param value                 Result
         * @return                      True if limit value was found for current iterator state,
         *                              false otherwise
         */
        bool Get(Variant & value) const;

        /**
         * Print limit values iterator to the output stream
         *
         * @param                           Output stream
         */
        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class LimitSettings;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    /**
     * Get begin iterator for limit values
     *
     * @return                          Begin iterator for limit values
     */
    const_iterator begin() const;

    /**
     * Get end iterator for limit values
     *
     * @return                          End iterator for limit values
     */
    const_iterator end() const;

public:
    /**
     * Check limit values for emptiness
     *
     * @return                          True if limit filter conditions are empty, false otherwise
     */
    bool Empty() const;

    /**
     * Clear all contents from limit values i.e. reset them to the same state as the one right after calling
     * the default constructor
     */
    void Clear();

    /**
     * Get the number of limit values
     *
     * @return                          The number of limit values
     */
    size_t GetSize() const;

public:
    /**
     * Print limit values to the output stream
     *
     * @param                           Output stream
     */
    std::ostream & Print(std::ostream & strm) const override;

private:
    friend class LimitSettings;
    friend class LimitSettings::Update;
    friend class LimitSettings::Options;

private:
    std::unique_ptr<types::Parameters> m_parameters;
};

inline size_t hash_value(const LimitSettings::Values & value)
{
    return value.GetHash();
}

/**
 * LimitSettings::Options, helper class for remote limit settings creation.
 *
 * @see LimitSettings::SendCreateRequest
 */
class STRATEGY_EXPORT LimitSettings::Options : public LimitSettingsOptionsBase
{
public:
    using LimitSettingsOptionsBase::LimitSettingsOptionsBase;

public:
    /**
     * Set limit definition
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendCreateRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @param definition                Limit definition
     */
    void SetDefinition(const ParameterDefinition & definition);

    /**
     * Set limit filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use SetParameters instead.
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendCreateRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @param conditions                Limit filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] void SetFilterConditions(const LimitSettings::FilterConditions & conditions);

    /**
     * Set limit values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use SetParameters instead.
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendCreateRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @param values                    Limit values
     */
    [[deprecated(DEPRECATE_LINK)]] void SetValues(const LimitSettings::Values & values);

    /**
     * Fetch limit definition
     *
     * @return                          Limit definition, empty if it was not set or was set to empty definition
     */
    ParameterDefinition GetDefinition() const;

    /**
     * Fetch limit filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit filter conditions, empty if they were not set or were set to empty
     *                                  filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] LimitSettings::FilterConditions GetFilterConditions() const;

    /**
     * Fetch limit values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit values, empty if they were not set or were set to empty values
     */
    [[deprecated(DEPRECATE_LINK)]] LimitSettings::Values GetValues() const;

    /**
     * Fetch a particular limit filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Result
     *
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilterCondition(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Fetch a particular limit value
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container of limit values
     * @param value                     Result
     *
     * @return                          True if value exists for given definition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetValue(const ParameterDefinition & definition, AnyType & value) const;

public:
    bool Empty() const;

    void Clear();

private:
    friend class LimitSettings;
    LimitSettings::FilterConditions m_conditions;
    LimitSettings::Values m_values;
};

/**
 * LimitSettings::Modifier, helper class for remote limit settings modifications.
 *
 * @see LimitSettings::SendModifyRequest
 */
class STRATEGY_EXPORT LimitSettings::Modifier : public LimitSettingsModifierBase
{
public:
    using LimitSettingsModifierBase::LimitSettingsModifierBase;

public:
    /**
     * Set limit filter conditions
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendModifyRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use SetParameters instead.
     *
     * @param conditions                Limit filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] void SetFilterConditions(const LimitSettings::FilterConditions & conditions);

    /**
     * Set limit values
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendModifyRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use SetParameters instead.
     *
     * @param values                    Limit values
     */
    [[deprecated(DEPRECATE_LINK)]] void SetValues(const LimitSettings::Values & values);

    /**
     * Fetch limit definition
     *
     * @return                          Limit definition, empty if it was not set or was set to empty definition
     */
    ParameterDefinition GetDefinition() const;

    /**
     * Set limit definition
     *
     * Parameter value does not take effect until appropriate
     * LimitSettings::SendCreateRequest() is called and it is acknowledged by remote
     * side with IRequestReplyHandler::HandleRequestReply().
     *
     * @param definition                Limit definition
     */
    void SetDefinition(const ParameterDefinition & definition);

    /**
     * Fetch limit filter conditions
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit filter conditions, empty if they were not set or were set to empty
     *                                  filter conditions
     */
    [[deprecated(DEPRECATE_LINK)]] LimitSettings::FilterConditions GetFilterConditions() const;

    /**
     * Fetch limit values
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @return                          Limit values, empty if they were not set or were set to empty values
     */
    [[deprecated(DEPRECATE_LINK)]] LimitSettings::Values GetValues() const;

    /**
     * Fetch a particular limit filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Result
     *
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetFilterCondition(const ParameterDefinition & definition, AnyType & value) const;

    /**
     * Fetch a particular limit filter condition
     *
     * @deprecated Deprecated in 2.14.0, will be removed in 2.16.0. Use GetParameters instead.
     *
     * @param definition                Parameter definition, used as a key to the container of limit filter conditions
     * @param value                     Result
     *
     * @return                          True if filter condition exists for given definition, false otherwise
     */
    [[deprecated(DEPRECATE_LINK)]] bool GetValue(const ParameterDefinition & definition, AnyType & value) const;

public:
    bool Empty() const;

    void Clear();

private:
    friend class LimitSettings;
    LimitSettings::FilterConditions m_conditions;
    LimitSettings::Values m_values;
};
}
