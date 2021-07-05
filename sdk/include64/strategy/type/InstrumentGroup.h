#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// InstrumentGroup.
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/type/Boolean.h"
#include "strategy/type/String.h"
#include "strategy/type/Identifier.h"
#include "strategy/type/InstrumentGroupIdentifier.h"
#include <memory>

// \namespace tbricks
namespace tbricks {

namespace protocol {
class InstrumentGroup;
}

namespace visualization {
class InstrumentGroupRowEntityImpl;
}

class IRequestReplyHandler;

class STRATEGY_EXPORT InstrumentGroup : public AnyType
{
public:
    enum Type
    {
        NONE,
        CUSTOM,       /*< Any custom group for an instrument */
        SECTOR,       /*< A sector like, agriculture, pharmaceuticals etc. */
        CURRENCY,     /*< Currency. */
        EXCHANGE,     /*< Exchange. */
        COMBINATION,  /*< Combination. */
        SPREAD_TABLE, /*< Venue-provided spread tables. */
        DERIVATIVE    /*< Derivative. */
    };

public:
    class RequestResult;

public:
    class Options;
    class Modifier;

public:
    /**
     * Constructor.
     *
     * Constructs an empty object.
     */
    InstrumentGroup();

    /**
     * Copy constructor.
     */
    InstrumentGroup(const InstrumentGroup & v);

    /**
     * Constructor.
     *
     * Constructs an object and immediately resolves it. If resolution
     * fails, object is left in empty state.
     */
    InstrumentGroup(const InstrumentGroupIdentifier & id);
    ~InstrumentGroup() override;

    InstrumentGroup & operator=(const InstrumentGroup & v);

    /**
     * Assignment operator.
     *
     * Assigns an identifier and immediately resolves it. If resolution fails,
     * object will be left in empty state.
     */
    InstrumentGroup & operator=(const InstrumentGroupIdentifier & id);

    bool operator==(const InstrumentGroup & group) const;
    bool operator!=(const InstrumentGroup & group) const;

    /**
     * Resolve instrument group.
     *
     * %Set instrument group identifier and retrieve available group data.
     * Already resolved objects are cleared first.
     *
     * @param id                        Instrument group identifier
     *
     * @return                          'true' if the data is available,
     *                                  'false' otherwise
     */
    bool Resolve(const InstrumentGroupIdentifier & id);

    /**
     * Get instrument group identifier.
     *
     * Returns instrument group identifier the object is associated with.
     *
     * @return                          Instrument group identifier
     */
    const InstrumentGroupIdentifier & GetIdentifier() const;

    /**
     * Merge data from extern source.
     *
     * Object fields are updated from the argument, old values (if any) are
     * replaced.
     *
     * Method only fails when both source and target objects have their
     * identifier set, and identifiers are not equal. If this is the case, the
     * method throws an exception.
     *
     * @param group                     Data source
     */
    void Merge(const InstrumentGroup & group);

public:
    /**
     * Check object for emptiness.
     *
     * Object is considered empty if its data is not resolved.
     *
     * @return                          "true" if object is empty, "false"
     *                                  otherwise
     */
    bool Empty() const override;

    /**
     * Clear object.
     *
     * Object is considered empty after this call.
     */
    void Clear();

    size_t GetHash() const override;

public:
    /**
     * Get name.
     *
     * A short name of an instrument group.
     *
     * @return                          Short group name if available,
     *                                  empty object otherwise
     */
    String GetName() const;

    /**
     * Get long name.
     *
     * A long, explanatory name of an instrument group.
     *
     * @return                          Long group name if available,
     *                                  empty object otherwise
     */
    String GetLongName() const;

    /**
     * Get group category.
     *
     * The category of the instrument group (used for grouping in the
     * instrument library pane in the front-end).  The category is a sort of a
     * group-group, an order of groups if the same type that is associated but
     * not hierarchically related.
     *
     * @return                          Group category if available,
     *                                  empty object otherwise
     */
    String GetCategory() const;

    /**
     * Get parent group identifier.
     *
     * @return                          Parent group identifier if available,
     *                                  empty identifier otherwise
     */
    InstrumentGroupIdentifier GetParentIdentifier() const;

    /**
     * Get group description.
     *
     * Describing what the group in reality is, its fine grained type, it may
     * be a product or a class of instruments, or even an assettype.
     *
     * @return                          Group description if available,
     *                                  empty object otherwise
     */
    String GetDescription() const;

    /**
     * Get group description.
     *
     * Describing what the group in reality is, its fine grained type, it may
     * be a product or a class of instruments, or even an assettype.
     *
     * @return                          Group description if available,
     *                                  empty object otherwise
     */

    /**
     * Get value of "deleted" field.
     *
     * If "deleted" field is not set, the method returns empty object.
     *
     * @return                          Value of "deleted" field
     */
    Boolean GetDeleted() const;

    /**
     * Get group type.
     *
     * Type classification of an instrument group.
     *
     * @return                          Group type
     */
    Type GetType() const;

    /**
     * Get datetime of last modification.
     *
     * Returns datetime of last modification.
     *
     * @return                          Modified datetime
     */
    DateTime GetHostModifiedDatetime() const;

    constexpr static TypeInfo GetTypeInfo() { return TypeInfo::SFT_INSTRUMENT_GROUP; }

public:
    /**
     * Send instrument group create request.
     *
     * Method sends a request for creation instrument group.
     *
     * Instrument group create request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param options                   Creation request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          InstrumentGroup::RequestResult object
     */
    static RequestResult SendCreateRequest(const InstrumentGroup::Options & options, IRequestReplyHandler & handler);

    /**
     * Send instrument group modify request.
     *
     * Method sends a request for modify instrument group.
     *
     * Instrument group modify request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param modifier                  Modifiy request
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          InstrumentGroup::RequestResult object
     */
    static RequestResult SendModifyRequest(const InstrumentGroup::Modifier & modifier, IRequestReplyHandler & handler);

    /**
     * Send instrument group delete request.
     *
     * Method sends a request for delete instrument group.
     *
     * Instrument group delete request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * @param id                        instrument group identifier
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          InstrumentGroup::RequestResult object
     */
    static RequestResult SendDeleteRequest(const InstrumentGroupIdentifier & id, IRequestReplyHandler & handler);

    /**
     * Send maturity instrument group create request.
     *
     * Method sends a request for creation maturity instrument group.
     *
     * Instrument group create request is a remote operation and its status is
     * delievered to HandleRequestReply() as soon as the operation result is
     * available.
     *
     * Created instrument group will have same type as parent group.
     *
     * @param parent_group              Parent group identifier (mandatory)
     * @param maturity_date             Group maturity date (mandatory)
     *
     * @param handler                   Request reply handle instance, must
     *                                  remain alive until [N]ACK is received
     *
     * @return                          InstrumentGroup::RequestResult object
     */
    static RequestResult
    SendMaturityGroupCreateRequest(const InstrumentGroup & parent_group, const Date & maturity_date, IRequestReplyHandler & handler);

public:
    InstrumentGroup(std::shared_ptr<protocol::InstrumentGroup> && msg);
    InstrumentGroup & operator=(const protocol::InstrumentGroup & msg);

private:
    std::ostream & Print(std::ostream & strm) const override;
    TypeInfo get_type_info() const override;

    /// Codec
    size_t get_size() const override;
    int decode(const void * data, size_t size) override;
    int encode(void * data, size_t size) const override;

private:
    friend STRATEGY_EXPORT class IrdXmlPrinter;

    friend STRATEGY_EXPORT class visualization::InstrumentGroupRowEntityImpl;
    const protocol::InstrumentGroup * get_instrument_group() const { return m_msg.get(); }

private:
    InstrumentGroupIdentifier m_id;
    std::shared_ptr<protocol::InstrumentGroup> m_msg;
};

/**
 * InstrumentGroup::RequestResult object.
 *
 * Defines feedback information after the creation of a instrument group.
 * Consists of InstrumentGroupIdentifier and request Identifier.
 *
 */
class STRATEGY_EXPORT InstrumentGroup::RequestResult : public Printable
{
public:
    RequestResult();
    RequestResult(const Identifier & request_identifier, const InstrumentGroupIdentifier & instrument_group_identifier);

    const Identifier & GetRequestIdentifier() const;
    const InstrumentGroupIdentifier & GetInstrumentGroupIdentifier() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    Identifier m_request_identifier;
    InstrumentGroupIdentifier m_instrument_group_identifier;
};

/**
 * InstrumentGroup::Options object.
 *
 * Defined options for the creation of instrument groups from strategies.
 *
 * Fill members Options class and call:
 *
 *     InstrumentGroup::SendCreateRequest(options, request_handler);
 *
 * for creation instrument group.
 *
 */
class STRATEGY_EXPORT InstrumentGroup::Options : public Printable
{
public:
    Options();
    Options(const Options & options);
    Options & operator=(const Options & options);
    ~Options() override;

public:
    const String & GetName() const;
    void SetName(const String & name);

    const String & GetLongName() const;
    void SetLongName(const String & long_name);

    const String & GetDescription() const;
    void SetDescription(const String & description);

    const String & GetCategory() const;
    void SetCategory(const String & category);

    InstrumentGroup::Type GetType() const;
    void SetType(InstrumentGroup::Type type);

    const InstrumentGroup & GetParentGroup() const;
    void SetParentGroup(const InstrumentGroup & group);

public:
    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    String m_name;
    String m_long_name;
    String m_description;
    String m_category;
    InstrumentGroup::Type m_type;
    InstrumentGroup m_group;
};

/**
 * InstrumentGroup::Modifier object.
 *
 * Defined modify options for the creation of instrument groups from strategies.
 *
 * Fill members Modifier class and call:
 *
 *     InstrumentGroup::SendModifyRequest(modifier, request_handler);
 *
 * for modify instrument group.
 *
 */
class STRATEGY_EXPORT InstrumentGroup::Modifier : public Printable
{
public:
    Modifier(const InstrumentGroupIdentifier & identifier);
    Modifier(const Modifier & modifier);
    Modifier & operator=(const Modifier & modifier);
    ~Modifier() override;

public:
    const InstrumentGroupIdentifier & GetIdentifier() const;

    bool HasName() const;
    void SetName(const String & name);
    const String & GetName() const;

    bool HasLongName() const;
    void SetLongName(const String & long_name);
    const String & GetLongName() const;

    bool HasDescription() const;
    void SetDescription(const String & description);
    const String & GetDescription() const;

    bool HasCategory() const;
    void SetCategory(const String & category);
    const String & GetCategory() const;

    bool HasDeleted() const;
    void SetDeleted(const Boolean & is_deleted);
    const Boolean & GetDeleted() const;

public:
    void Clear();
    bool Empty() const;

public:
    std::ostream & Print(std::ostream & strm) const override;

private:
    InstrumentGroupIdentifier m_identifier;
    String m_name;
    String m_long_name;
    String m_description;
    String m_category;
    Boolean m_deleted;
};

} // \namespace tbricks
