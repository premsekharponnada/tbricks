#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Trading block
//
//****************************************************************************

#include "strategy_generated/TradingBlockBase.h"
#include "strategy_generated/TradingBlockOptionsBase.h"
#include "strategy_generated/TradingBlockModifierBase.h"
#include "strategy/Strategy.h"

#include <optional>

namespace tbricks {

enum class TradingBlockType;

/**
 * Representing a trading block. It allows blocking of trading requests
 * which matched trading block condition.
 */
class STRATEGY_EXPORT TradingBlock : public TradingBlockBase
{
public:
    class Update;
    class Options;
    class Modifier;
    class Stream;
    class RequestResult;

public:
    TradingBlock();
    TradingBlock(const TradingBlock & strategyType);
    TradingBlock(TradingBlock && strategyType) noexcept;
    TradingBlock & operator=(const TradingBlock & strategyType);
    TradingBlock & operator=(TradingBlock && strategyType) noexcept;
    ~TradingBlock() override;

public:
    /**
     * Send trading block create request.
     *
     * Sends trading block create request to metadata service.
     *
     * @param options                   Trading block options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          RequestResult::RequestResult object
     */
    static RequestResult SendCreateRequest(const Options & options, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send trading block modify request.
     *
     * Sends trading block modify request to metadata service.
     *
     * @param modifier                  Trading block modifier
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          RequestResult::RequestResult object
     */
    static RequestResult SendModifyRequest(const Modifier & modifier, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

    /**
     * Send trading block delete request.
     *
     * Sends trading block delete request to metadata service.
     *
     * @param options                   Trading block options
     * @param handler                   Request reply handler instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          RequestResult::RequestResult object
     */
    static RequestResult SendDeleteRequest(const Identifier & id, IRequestReplyHandler & handler = IRequestReplyHandler::Default());

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingBlockType() const;

    /**
     * Get trading block type.
     *
     * @return                          trading block type
     */
    std::optional<TradingBlockType> GetTradingBlockType() const;

public:
    /**
     * Merge tbrading block update.
     *
     * @param update                Trading block update
     */
    void Merge(const Update & update);
};

class STRATEGY_EXPORT TradingBlock::Update : public TradingBlockUpdateBase
{
public:
    Update();
    ~Update() override;
    Update(const Update & strategyType);
    Update(Update && strategyType) noexcept;
    Update & operator=(const Update & strategyType);
    Update & operator=(Update && strategyType) noexcept;

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingBlockType() const;

    /**
     * Get trading block type.
     *
     * @return                          trading block type
     */
    std::optional<TradingBlockType> GetTradingBlockType() const;

private:
    Update(std::shared_ptr<protocol::TradingBlock> update);
    friend class Converter;
    friend class TradingBlock;
};

class STRATEGY_EXPORT TradingBlock::Options : public TradingBlockOptionsBase
{
public:
    Options();
    Options(const Options & option);
    Options(Options && option) noexcept;
    Options & operator=(const Options & option);
    Options & operator=(Options && option) noexcept;
    ~Options() override;

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingBlockType() const;

    /**
     * Get trading block type.
     *
     * @return                          trading block type
     */
    std::optional<TradingBlockType> GetTradingBlockType() const;

    /**
     * %Set trading block type.
     * If the value is empty field will delete from options.
     *
     * @param value                     trading block type
     */
    void SetTradingBlockType(std::optional<TradingBlockType> value);

protected:
    friend class TradingBlock;
};

class STRATEGY_EXPORT TradingBlock::Modifier : public TradingBlockModifierBase
{
public:
    Modifier(const Identifier & identifier);

public:
    /**
     * Check if field is set.
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasTradingBlockType() const;

    /**
     * Get trading block type.
     *
     * @return                          trading block type
     */
    std::optional<TradingBlockType> GetTradingBlockType() const;

    /**
     * %Set trading block type.
     * If the value is empty field will delete from options.
     *
     * @param value                     trading block type
     */
    void SetTradingBlockType(std::optional<TradingBlockType> value);

protected:
    friend class TradingBlock;
    Identifier m_trading_block_identifier;
};

class STRATEGY_EXPORT TradingBlock::RequestResult : public Printable
{
public:
    RequestResult() = default;
    RequestResult(const Identifier & request_identifier, const Identifier & identifier) :
        m_request_identifier(request_identifier),
        m_identifier(identifier)
    {}

    const Identifier & GetRequestIdentifier() const { return m_request_identifier; }
    const Identifier & GetTradingBlockIdentifier() const { return m_identifier; }

public:
    virtual std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_request_identifier;
    Identifier m_identifier;
};
}
