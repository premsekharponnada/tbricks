#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// GridSelection type.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/type/AnyType.h"
#include "strategy/type/Uuid.h"

namespace tbricks {

namespace types {
class GridSelection;
}

class STRATEGY_EXPORT GridSelection : public AnyType
{
public:
    GridSelection();
    GridSelection(const types::GridSelection & src);
    GridSelection(const GridSelection & src);
    ~GridSelection() override;

    GridSelection & operator=(const GridSelection & src);

    bool operator>(const GridSelection & other) const;
    bool operator>=(const GridSelection & other) const;
    bool operator<(const GridSelection & other) const;
    bool operator<=(const GridSelection & other) const;
    bool operator==(const GridSelection & other) const;
    bool operator!=(const GridSelection & other) const;

    bool Empty() const override;
    void Clear();

    size_t GetHash() const override;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_GRID_SELECTION; }

    operator types::GridSelection() const;

private:
    int compare(const GridSelection & other) const;

    void GetGridSelection(types::GridSelection & value) const;

    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

    Uuid m_service_id;
    Uuid m_view_id;
};
}
