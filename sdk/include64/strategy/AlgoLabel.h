#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// AlgoLabel
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include "strategy/Types.h"
#include "strategy/Strategy.h"

namespace tbricks {

namespace protocol {
class AlgoLabel;
class AlgoLabelRequest;
}

class STRATEGY_EXPORT AlgoLabel : public Printable
{
public:
    class Stream;
    class Options;
    class Modifier;
    class RequestResult;

public:
    AlgoLabel();
    ~AlgoLabel() override;

    AlgoLabel(const AlgoLabel & algo_label);
    AlgoLabel(AlgoLabel && algo_label) noexcept;

    AlgoLabel & operator=(const AlgoLabel & algo_label);
    AlgoLabel & operator=(AlgoLabel && algo_label) noexcept;

public:
    Identifier GetIdentifier() const;
    bool HasIdentifier() const;

    String GetName() const;
    bool HasName() const;

    uint32_t GetShortCode() const;
    bool HasShortCode() const;

    StrategyIdentifier GetAppType() const;
    bool HasAppType() const;

    StrategyParameters GetAppParameters() const;
    bool HasAppParameters() const;

    StrategyParameters GetAlgoLabelParameters() const;
    bool HasAlgoLabelParameters() const;

    Boolean GetDeleted() const;
    bool HasDeleted() const;

    Boolean GetManual() const;
    bool HasManual() const;

    DateTime GetHostCreatedDatetime() const;
    bool HasHostCreatedDatetime() const;

    DateTime GetHostModifiedDatetime() const;
    bool HasHostModifiedDatetime() const;

    Integer GetAppAlgoVersion() const;
    bool HasAppAlgoVersion() const;

    AlgoLabelType GetAlgoLabelType() const;
    bool HasAlgoLabelType() const;

public:
    bool IsSystemProvided() const;
    bool Empty() const;
    void Clear();

public:
    static RequestResult SendCreateRequest(const Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());
    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());
    static RequestResult SendDeleteRequest(const Identifier & id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

private:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    friend STRATEGY_EXPORT class Converter;
    AlgoLabel(std::shared_ptr<protocol::AlgoLabel> msg);

private:
    std::shared_ptr<protocol::AlgoLabel> m_msg;
};

/**
 * AlgoLabel::RequestResult
 */
class STRATEGY_EXPORT AlgoLabel::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_identifier, const Identifier & identifier) :
        m_request_identifier(request_identifier),
        m_identifier(identifier)
    {}

    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }

    const Identifier & GetIdentifier() const { return m_identifier; }

protected:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_identifier;
    Identifier m_identifier;
};

/**
 * AlgoLabel::Options
 */
class STRATEGY_EXPORT AlgoLabel::Options : public Printable
{
public:
    Options();
    ~Options() override;

    Options(const Options & option);
    Options(Options && options) noexcept;

    Options & operator=(const Options & options);
    Options & operator=(Options && options) noexcept;

public:
    void SetName(const String & name);
    String GetName() const;

    void SetShortCode(uint32_t short_code);
    uint32_t GetShortCode() const;

    void SetAppType(const StrategyIdentifier & identifier);
    StrategyIdentifier GetAppType() const;

    void SetAppParameters(const StrategyParameters & paramters);
    StrategyParameters GetAppParameters() const;

    void SetManual(const Boolean & manual) const;
    Boolean GetManual() const;

public:
    bool Empty() const;
    void Clear();

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    friend STRATEGY_EXPORT class AlgoLabel;

    std::unique_ptr<protocol::AlgoLabelRequest> m_msg;
};

class STRATEGY_EXPORT AlgoLabel::Modifier : public AlgoLabel::Options
{
public:
    Modifier(const Identifier & identifier);

public:
    Identifier GetIdentifier() const;
};

} // namespace tbricks
