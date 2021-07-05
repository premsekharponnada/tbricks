#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Tree node parameters container
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/AnyType.h"
#include "strategy/type/Variant.h"
#include "strategy/type/Uuid.h"

#include "strategy/TreeNodeParameterDefinition.h"

namespace tbricks {

namespace protocol {
class TreeNode;
}

/**
 * TreeNodeParameters parameters class
 */
class STRATEGY_EXPORT TreeNodeParameters : public Printable
{
public:
    TreeNodeParameters();
    TreeNodeParameters(const TreeNodeParameters & parameters);
    TreeNodeParameters(TreeNodeParameters && parameters) noexcept;
    ~TreeNodeParameters();

    TreeNodeParameters & operator=(const TreeNodeParameters & parameters);
    TreeNodeParameters & operator=(TreeNodeParameters && parameters) noexcept;

    bool operator==(const TreeNodeParameters & parameters) const;
    bool operator!=(const TreeNodeParameters & parameters) const { return !operator==(parameters); }

    /** Fetch parameter value from the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     *
     * @return                          True if container has parameter value
     *                                  tagged with given name, false otherwise
     */
    bool GetParameter(const TreeNodeParameterDefinition & definition, AnyType & value) const;

    bool GetParameter(const Uuid & identifier, AnyType & value) const;

    /**
     * Store parameter value in the parameter container.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     * @param value                     Variable to store parameter value
     */
    void SetParameter(const TreeNodeParameterDefinition & definition, const AnyType & value);

    /**
     * Check if container has a value for the key.
     *
     * Method returns 'true' if only if container has a value for the
     * provided parameter definition.
     *
     * @param definition                Parameter definition, used as a key to
     *                                  the container
     *
     * @return                          True if value is found, false otherwise.
     */
    bool HasParameter(const TreeNodeParameterDefinition & definition) const;

    /**
     * Check container for emptiness.
     *
     * @return                          True if there are no records in the
     *                                  container, false otherwise.
     */
    bool Empty() const;
    void Clear();

    /**
     * Merge parameters.
     *
     * Updates container data with values from the argument.
     *
     * @param parameters                Parameter container
     */
    void Merge(const TreeNodeParameters & parameters);

    std::ostream & Print(std::ostream & strm) const override;

public:
    class STRATEGY_EXPORT const_iterator : public Printable
    {
    public:
        const_iterator();
        const_iterator(const const_iterator & it);
        ~const_iterator();
        const_iterator & operator=(const const_iterator & it);

        bool operator==(const const_iterator & it) const;
        bool operator!=(const const_iterator & it) const;

        const_iterator & operator++();
        const_iterator operator++(int);

        const_iterator & operator*();

        void Clear();
        bool Empty() const;

    public:
        Uuid GetIdentifier() const;
        // returns Empty definition if cannot resolve
        TreeNodeParameterDefinition GetDefinition() const;

        bool Get(AnyType & value) const;
        bool Get(Variant & value) const;

        std::ostream & Print(std::ostream & strm) const override;

    private:
        friend class TreeNodeParameters;
        void init(const void * data, size_t size, size_t pos = 0);

    private:
        const void * m_data;
        size_t m_size;
        size_t m_pos;
    };

    const_iterator begin() const;
    const_iterator end() const;

public:
    class Impl;
    const Impl & impl() const { return *m_parameters; }
    Impl & impl() { return *m_parameters; }
    void get_reference(strategy::DataRef & ref) const;

    void init_parameters(const std::shared_ptr<protocol::TreeNode> & tree_node);

private:
    std::unique_ptr<Impl> m_parameters;
};

} // \namespace tbricks
