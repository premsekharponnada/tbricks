#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (C) 2018 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// GermanHFTAlgoLabel
//****************************************************************************************

#include "strategy/Printable.h"
#include "strategy/Linkage.h"

#include <vector>
#include <memory>

namespace tbricks {

class DateTime;

namespace protocol {
class GermanHftAlgoLabel;
}

class STRATEGY_EXPORT GermanHFTAlgoLabel : public Printable
{
public:
    class Stream;

public:
    GermanHFTAlgoLabel();
    ~GermanHFTAlgoLabel() override;

    GermanHFTAlgoLabel(const GermanHFTAlgoLabel & label);
    GermanHFTAlgoLabel(GermanHFTAlgoLabel && label) noexcept;

    GermanHFTAlgoLabel & operator=(const GermanHFTAlgoLabel & label);
    GermanHFTAlgoLabel & operator=(GermanHFTAlgoLabel && label) noexcept;

public:
    std::vector<uint32_t> GetComponents() const;

    uint32_t GetAlgoLabel() const;

    DateTime GetHostCreatedDatetime() const;

    bool IsSystemProvided() const;

private:
    friend STRATEGY_EXPORT class Converter;
    GermanHFTAlgoLabel(std::shared_ptr<protocol::GermanHftAlgoLabel> msg);

private:
    virtual std::ostream & Print(std::ostream & strm) const override;

private:
    std::shared_ptr<protocol::GermanHftAlgoLabel> m_msg;
};
}
