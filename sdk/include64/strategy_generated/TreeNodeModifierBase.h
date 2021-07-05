#pragma once

//****************************************************************************
// Tbricks App API
//
// Copyright (C) 2020 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// TreeNodeModifierBase object
//
//****************************************************************************

#include <memory>

#include "strategy/Linkage.h"
#include "strategy/Printable.h"



#include <optional>
#include <vector>

namespace tbricks {

class Boolean;
class String;


namespace protocol { class TreeNodeRequest; }

class STRATEGY_EXPORT TreeNodeModifierBase : public Printable
{
protected:
    TreeNodeModifierBase();
    TreeNodeModifierBase(const TreeNodeModifierBase & value);
    TreeNodeModifierBase(TreeNodeModifierBase && value) noexcept;
    TreeNodeModifierBase & operator=(const TreeNodeModifierBase & value);
    TreeNodeModifierBase & operator=(TreeNodeModifierBase && value) noexcept;
    virtual ~TreeNodeModifierBase();

public:
    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasName() const;

    /**
     * Get tree node name.
     *
     *
     * @return                          tree node name
     */
    String GetName() const;

    /**
     * %Set tree node name.
     *
     *    
     *  
     * @param value                     tree node name
     */
    void SetName(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDescription() const;

    /**
     * Get tree node description.
     *
     *
     * @return                          tree node description
     */
    String GetDescription() const;

    /**
     * %Set tree node description.
     *
     *    
     *  
     * @param value                     tree node description
     */
    void SetDescription(const String & value);

    /**
     * Check if field is set.
     *
     *
     * @return                          True if field is set, false otherwise
     */
    bool HasDeleted() const;

    /**
     * Get deleted.
     *
     *
     * @return                          deleted
     */
    Boolean GetDeleted() const;

    /**
     * %Set deleted.
     *
     *    
     * @throw Exception if passed value is empty
     *  
     * @param value                     deleted
     */
    void SetDeleted(const Boolean & value);


public:
    bool Empty() const;

    void Clear();

    std::ostream & Print(std::ostream & strm) const override;


/** @cond PRIVATE */
public:
    TreeNodeModifierBase(const protocol::TreeNodeRequest & value);
    TreeNodeModifierBase(std::unique_ptr<protocol::TreeNodeRequest> && value);

    std::unique_ptr<protocol::TreeNodeRequest> & get_impl_wr() const;
    const std::unique_ptr<protocol::TreeNodeRequest> & get_impl_rd() const
    { return m_impl; }
/** @endcond */

private:
    std::unique_ptr<protocol::TreeNodeRequest> m_impl;
};

}
