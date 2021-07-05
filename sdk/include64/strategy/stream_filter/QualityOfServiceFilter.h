#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Filter for use in service status streams.
//****************************************************************************************

#include "strategy/stream_filter/Filter.h"
#include "strategy/type/ServiceIdentifier.h"

namespace tbricks {

/**
 * Default QualityOfService filter, matches all services.
 */
class STRATEGY_EXPORT QualityOfServiceFilter : public Filter
{
public:
    QualityOfServiceFilter();
    QualityOfServiceFilter(const QualityOfServiceFilter & filter);
    ~QualityOfServiceFilter();

    QualityOfServiceFilter & operator=(const QualityOfServiceFilter & filter);

    QualityOfServiceFilter & operator|=(const QualityOfServiceFilter & filter);
    QualityOfServiceFilter & operator&=(const QualityOfServiceFilter & filter);

    QualityOfServiceFilter operator||(const QualityOfServiceFilter & filter);
    QualityOfServiceFilter operator&&(const QualityOfServiceFilter & filter);

    QualityOfServiceFilter operator!();

    void Clear() override;
    bool Empty() const override;
    tbricks::filter::FieldFilter GetValue() const override;

protected:
    std::ostream & Print(std::ostream & strm) const override;
    uint64_t get_stream_message_id() const override;
};

/**
 * Convenience alias.
 */
typedef QualityOfServiceFilter AnyQualityOfServiceFilter;

class STRATEGY_EXPORT QualityOfServiceFilterCondition : public FilterCondition
{
public:
    QualityOfServiceFilter operator||(const QualityOfServiceFilterCondition & cond) const;
    QualityOfServiceFilter operator&&(const QualityOfServiceFilterCondition & cond) const;
    QualityOfServiceFilter operator||(const QualityOfServiceFilter & cond) const;
    QualityOfServiceFilter operator&&(const QualityOfServiceFilter & cond) const;
    QualityOfServiceFilter operator!() const;
    operator QualityOfServiceFilter() const;
};

/**
 * QualityOfServiceByIdentifierFilter matches concrete service instance updates,
 * selected by service identifier.
 */
class STRATEGY_EXPORT QualityOfServiceByIdentifierFilter : public QualityOfServiceFilterCondition
{
public:
    /**
     * Constructor.
     *
     * Makes a filter to match all QualityOfService having service identifier
     * as specified in the input parameter.
     *
     * @param service_id            Instance of ServiceIdentifier
     */
    QualityOfServiceByIdentifierFilter(const ServiceIdentifier & service_id);
    QualityOfServiceByIdentifierFilter(const QualityOfServiceByIdentifierFilter & filter);

    QualityOfServiceByIdentifierFilter & operator=(const QualityOfServiceByIdentifierFilter & filter);

    virtual void Clear();
    virtual tbricks::filter::FieldFilter GetValue() const;
    virtual bool Empty() const;

protected:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    ServiceIdentifier m_service_id;
};
}
