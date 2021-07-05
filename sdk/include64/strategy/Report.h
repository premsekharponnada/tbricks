#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Report object
//****************************************************************************************

#include "strategy/Linkage.h"
#include "strategy/Printable.h"

#include "strategy/Types.h"
#include "strategy/Matrix.h"

namespace tbricks {

/**
 * Report.
 *
 * Used to create a Dynamic Reports which displays data in the form
 * of table, chart, summary, bullet, etc.
 */
class STRATEGY_EXPORT Report : public Printable
{
public:
    class Item;

public:
    /**
     * Constructor.
     *
     * Constructs new, empty Report instance.
     */
    Report();
    Report(const Report & report);
    Report & operator=(const Report & report);

    /**
     * Destructor.
     */
    virtual ~Report();

public:
    /**
     * Creates a new blank report with default settings.
     */
    static Report Create();

public:
    /**
     * This method adds a new Item on the report
     * or update/modify the existing Item on the report.
     *
     * for e.g add a new Item:
     * report.UpdateItem(Report::Item("data", m, "table"));
     *
     * for e.g. update an existing Item:
     * report.UpdateItem(item);
     *
     * @param item                   An Item to be updated.
     */
    void UpdateItem(const Item & item);

    /**
     * This method delete the Item from the Report.
     *
     * @param item                   An Item to be deleted.
     */
    void DeleteItem(const Item & item);

public:
    std::ostream & Print(std::ostream & strm) const;

public:
    bool Empty() const;

private:
    bool m_empty;
};

/**
 * Report::Item allows to add the information on the report
 * in the form of items.
 *
 * An Item defines the structure and style of the information
 * to be added on the report.
 */
class STRATEGY_EXPORT Report::Item : public Printable
{
public:
    /// Default constructor.
    Item();

    /**
     * Constructor.
     *
     * Creates an Item with the specified parameters.
     *
     * @param key                    key is a user-defined string and
     *                               need not be unique for all the Item.
     *
     * @param value                  AnyType value can be any Variant.
     *
     * @param style                  style specifies the representation of
     *                               the data like summary, table, bullets etc.
     */
    Item(const String & key, const AnyType & value, const String & style = String());

    /**
     * Constructor.
     *
     * Creates an Item with the specified key, value and style to represent the matrix.
     *
     * @param key                    key can be any string and
     *                               need not be unique for all the Item.
     *
     * @param value                  Matrix is a two dimensional input
     *                               data with AnyType value.
     *
     * @param style                  style specifies the representation of
     *                               the data like chart, table, bullets etc.
     */
    Item(const String & key, const Matrix & value, const String & style = String());
    Item & operator=(const Item & item);
    virtual ~Item();

public:
    /**
     * Get key of the item.
     *
     * @return                       key of an Item.
     */
    const String & GetKey() const;

    /**
     * Get style of the item.
     *
     * @return                       style of an Item.
     *                               for e.g. chart, summary etc.
     */
    const String & GetStyle() const;

    /**
     * Get value of the item.
     *
     * @return                      an Item value variant type
     */
    const Variant & GetValue() const;

    /**
     * Get matrix of the item.
     *
     * @return                       data in a matrix structure which
     *                               consists of rows and columns.
     *
     * for e.g : <Matrix> height = 2 width = 3
     *           {
     *                  ABC   PQR   XYZ
     *                  abc   pqr   xyz
     *           }
     */
    const Matrix & GetMatrix() const;

    /**
     * %Set value of the item.
     *
     * Value should be of Variant type.
     *
     * @param value                  data or information to be added on the report.
     */
    void SetValue(const AnyType & value);

    /**
     * %Set the matrix of an Item.
     * This method allows to present the information in a matrix
     * structure format.
     *
     * Matrix is two dimensional structure with row, column and
     * Anytype value as the inputs.
     *
     * @param matrix                 instance of matrix.
     */
    void SetMatrix(const Matrix & matrix);

    /**
     *  Get Report Data Identifier.
     *
     *  @return                      Item or report data identifier.
     */
    const Identifier & GetIdentifier() const;

public:
    /**
     * Returns true if Report is empty else returns false.
     */
    bool Empty() const;
    void Clear();

public:
    std::ostream & Print(std::ostream & strm) const;

private:
    Identifier m_identifier;
    String m_key;
    String m_style;
    Variant m_value;
    Matrix m_matrix;
};

} // namespace tbricks
