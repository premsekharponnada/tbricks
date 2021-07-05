#pragma once

//****************************************************************************************
// Tbricks App API
//
// Copyright (c) 2019 Itiviti Group AB.
// Itiviti (R) is a registered trademark of Itiviti Group AB, Sweden. All rights reserved.
//
// Parameter of Volume type.
//****************************************************************************************

#include "strategy/type/Volume.h"
#include "strategy/parameter/Parameter.h"

namespace tbricks {

/**
 * Parameter of an app instance. It contents the volume value.
 * By default the value is empty.
 */
class STRATEGY_EXPORT VolumeParameter : public Parameter
{
public:
    using ValueType = Volume;

public:
    /**
     * Create empty parameter and associate it with app instance
     * @param definition   parameter definition
     */
    VolumeParameter(const ParameterDefinition & definition);
    VolumeParameter(const VolumeParameter & parameter);

    VolumeParameter & operator=(const Volume & volume);
    VolumeParameter & operator=(const VolumeParameter & parameter);

    /**
     * Get current value of parameter
     * @return            value of parameter
     */
    const Volume & GetVolume() const;
    operator const Volume &() const;

    VolumeParameter & operator+=(const Volume & volume);
    VolumeParameter & operator+=(const VolumeParameter & parameter);

    VolumeParameter & operator-=(const Volume & volume);
    VolumeParameter & operator-=(const VolumeParameter & parameter);

    /**
     * Merge passed volume into parameter value
     * @see Volume::Merge()
     *
     * @param volume      volume to merge
     */
    void Merge(const Volume & volume);

    /**
     * %Set or merge value from passed parameters
     *
     * @code
     * TBDEBUG(m_volume_param);                 // Volume = <volume> 0 [<empty>]
     * TBDEBUG(parameters);                     // { Volume = <smart double> +12 }
     *
     * m_volume_param.GetParameter(parameters);
     * TBDEBUG(m_volume_param);                 // Volume = <volume> 12 [<empty>]
     * @endcode
     *
     * @code
     * TBDEBUG(m_volume_param);                 // Volume = <volume> <empty> [<empty>]
     * TBDEBUG(parameters);                     // { Volume = <smart double> +12 }
     *
     * m_volume_param.GetParameter(parameters);
     * TBDEBUG(m_volume_param);                 // Volume = <volume> +=12 [<empty>]
     * @endcode
     */
    bool GetParameter(const StrategyParameters::const_iterator & it);

    /**
     * %Set or merge value from passed parameters
     *
     * @code
     * TBDEBUG(m_volume_param);                 // Volume = <volume> 0 [<empty>]
     * TBDEBUG(it);                             // Volume = <smart double> +12
     *
     * m_volume_param.GetParameter(it);
     * TBDEBUG(m_volume_param);                 // Volume = <volume> 12 [<empty>]
     * @endcode
     *
     * @code
     * TBDEBUG(m_volume_param);                 // Volume = <volume> <empty> [<empty>]
     * TBDEBUG(it);                             // Volume = <smart double> +12
     *
     * m_volume_param.GetParameter(it);
     * TBDEBUG(m_volume_param);                 // Volume = <volume> +=12 [<empty>]
     * @endcode
     */
    bool GetParameter(const StrategyParameters & parameters);

    void SetDefaultIncrement(double increment);

    /// 1.0 by default
    double GetDefaultIncrement() const;

    class Impl;

private:
    Impl * m_impl;
};
}
