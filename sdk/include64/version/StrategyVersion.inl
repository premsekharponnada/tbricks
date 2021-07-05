/******************************************************************************
** Tbricks Product Version.
**
** Copyright (c) 2006-2020 Tbricks AB.
**
** This file was automatically generated. DO NOT CHANGE IT.
**
******************************************************************************/

#include "strategy/API.h"


//****************************************************************************
// Get module build date/time and API version in a human readable form.
//****************************************************************************

extern "C" USER_STRATEGY_EXPORT
void GetStrategyDllVersion(std::string & version)
{
    version = "Tbricks-2.14.6 (3371669abcb74c4c22a26bd56414a4787ad1d468)";
}


//****************************************************************************
// Get module build profile. Requires STRATEGY_BUILD_PROFILE cmd define.
//****************************************************************************

extern "C" USER_STRATEGY_EXPORT
const char * GetStrategyDllBuildProfile()
{
    return STRATEGY_BUILD_PROFILE;
}

/*****************************************************************************/
