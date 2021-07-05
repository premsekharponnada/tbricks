#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in alert streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/stream/AlertStream.h"
#include "strategy/type/Uuid.h"
#include "strategy/type/AlertType.h"
#include "strategy/parameter/Parameter.h"
#include "strategy/Alert.h"
#include "strategy/AlertParameterDefinition.h"
#include "strategy/stream_filter/conditions/DateTimeFilterCondition.h"

namespace tbricks {

namespace filter {
class ICondition;
}

/**
 * Default filter, matches all data.
 */
class STRATEGY_EXPORT Alert::Stream::Filters::Filter : public tbricks::Filter
{
public:
    Filter();
    Filter(const Filter & filter);
    ~Filter();

    Filter & operator=(const Filter & filter);
    Filter & operator|=(const Filter & filter);
    Filter & operator&=(const Filter & filter);
    Filter operator||(const Filter & filter);
    Filter operator&&(const Filter & filter);
    Filter operator!();
    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

class STRATEGY_EXPORT Alert::Stream::Filters::FilterCondition : public tbricks::FilterCondition
{
public:
    Filter operator||(const FilterCondition & cond) const;
    Filter operator&&(const FilterCondition & cond) const;
    Filter operator||(const Filter & cond) const;
    Filter operator&&(const Filter & cond) const;
    Filter operator!() const;
    operator Filter() const;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::BySeverity matches alerts with the specified severity.
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::BySeverity : public Alert::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match alerts having severity as specified
     * in the input parameter.
     *
     * @param  severity                     Alert::Severity enumeration.
                                            Possible values of alert severity:
                                            1) Normal
                                            2) Critical
      */
    BySeverity(const Alert::Severity & severity);
    BySeverity(const Alert::Stream::Filters::BySeverity & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Alert::Severity m_severity;
    bool m_empty;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByStrategyType matches alerts generated by plugins of the specified type
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByStrategyType : public Alert::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match alters generated by the plugin of the
     * type as specified in the input parameter.
     *
     * @param type                          Instance of StrategyIdentifier.
                                            Here, the type of plugin is specified
                                            by strategy identifier.
     */
    ByStrategyType(const StrategyIdentifier & type);

    /**
     * Constructor.
     *
     * Makes a filter to match alters generated by the plugin of
     * the type as specified in the input parameter.
     *
     * @param type                         Instance of Identifier.
                                           Here, the type of plugin is specified
                                           by identifier.
     */
    ByStrategyType(const Identifier & type);

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    StrategyIdentifier m_type;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByChecked matches all (not)checked alerts.
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByChecked : public Alert::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all the checked or non-checked  alters
     * as specified in the input parameter.
     *
     * @param isChecked                    bool value.
                                           Set to true for checked alters.
                                           Set to false for non-checked alters.
      */
    ByChecked(bool isChecked);
    ByChecked(const ByChecked & filter);

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    bool m_IsChecked;
    bool m_empty;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByParameter matches alerts with the specified parameter.
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByParameter : public Alert::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByParameter();
    ByParameter(const ByParameter & filter);

    /**
     * Constructor.
     *
     * Makes a filter to match all the alters having parameter and its value
     * as specified in the input parameters.
     *
     * @param definition                  Parameter "definitions" allows to select what
                                          specific alert parameters updates the
                                          caller is interested in.
     * @param value                       alert parameter's value.
     */
    ByParameter(const AlertParameterDefinition & definition, const AnyType & value);
    ~ByParameter();
    ByParameter & operator=(const ByParameter & filter);
    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    void init(const Uuid & parameter_id, const AnyType & value);

private:
    filter::ICondition * m_condition;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByCreatedDateTime matches alerts created in the specified time frame, including the
 * boundaries.
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByCreatedDateTime : public Alert::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments created in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByCreatedDateTime(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<alert by host created date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByModifiedDateTime matches alerts modified in the specified time frame, including the
 * boundaries.
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByModifiedDateTime : public Alert::Stream::Filters::FilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all instruments modified in the specified time frame,
     * including the boundaries.
     *
     * Setting one of the parameters empty creates an interval filter with
     * one end open.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    ByModifiedDateTime(const DateTime & from, const DateTime & until) : m_impl(from, until) {}

    /**
     * %Set initial point for the search.
     *
     * Final point value remains unchanged.
     *
     * @param from                      Date/time to start the search from
     */
    void SetFromDate(const DateTime & from) { m_impl.SetFromDate(from); }

    /**
     * Get current initial search point.
     *
     * @return                          Current settings for the starting point,
     *                                  which could be empty
     */
    const DateTime & GetFromDate() const { return m_impl.GetFromDate(); }

    /**
     * %Set final position for the search.
     *
     * Initial point value remains unchanged.
     *
     * @param until                     Date/time to end the search with
     */
    void SetUntilDate(const DateTime & until) { m_impl.SetUntilDate(until); }

    /**
     * Get current final search point.
     *
     * @return                          Current settings for the final point,
     *                                  which could be empty
     */
    const DateTime & GetUntilDate() const { return m_impl.GetUntilDate(); }

    /**
     * %Set a search range.
     *
     * @param from                      Date/time to start the search from
     * @param until                     Date/time to end the search with
     */
    void SetFromUntilDate(const DateTime & from, const DateTime & until)
    {
        m_impl.SetFromDate(from);
        m_impl.SetUntilDate(until);
    }

    virtual void Clear() { m_impl.Clear(); }
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const { return m_impl.Empty(); }

protected:
    virtual std::ostream & Print(std::ostream & strm) const
    {
        strm << "<alert by host modified date time filter>\n";
        return m_impl.Print(strm);
    }

private:
    DateTimeConditionImpl m_impl;
};

//------------------------------------------------------------------------------------

/**
 * Alert::Stream::Filters::ByAlertType matches alerts of the specified type.
 *
 */
class STRATEGY_EXPORT Alert::Stream::Filters::ByAlertType : public Alert::Stream::Filters::FilterCondition
{
public:
    /// Default constructor.
    ByAlertType();
    ByAlertType(const ByAlertType & filter);

    /**
     * Constructor.
     *
     * Makes a filter to match all the alters having
     * alert type as specified in the input parameter.
     *
     * @param alert_type			Instance of AlertType
     */
    ByAlertType(const AlertType & alert_type);

    virtual void Clear();
    virtual bool Empty() const;
    virtual tbricks::filter::FieldFilter GetValue() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    AlertType m_alert_type;
};
}