#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TradeStreamOptions
//****************************************************************************************

#include "strategy/stream/TCPStream.h"

namespace tbricks {

class STRATEGY_EXPORT TCPStream::Options : public Printable
{
public:
    /**
     * %Set output size.
     *
     * @param size      output size
     */
    void SetOutputSize(size_t size) { m_output_size = size; }

    /**
     * Get output size.
     *
     * @return          output size
     */
    size_t GetOutputSize() const { return m_output_size; }

    /**
     * %Set output prompt.
     *
     * @param prompt    output prompt
     */
    void SetOutputPrompt(const Binary & prompt) { m_output_prompt = prompt; }

    /**
     * Get output prompt.
     *
     * @return          output prompt
     */
    const Binary & GetOutputPrompt() const { return m_output_prompt; }

    /**
     * %Set data type.
     *
     * @param type      data type
     */
    void SetDataType(TCPDataType type) { m_data_type = type; }

    /**
     * Get data type.
     *
     * @return          data type
     */
    TCPDataType GetDataType() const { return m_data_type; }

protected:
    std::ostream & Print(std::ostream & strm) const override;

private:
    size_t m_output_size = 0;
    Binary m_output_prompt;
    TCPDataType m_data_type = TCPDataType::RAW;
};
}
