//----------------------------------------------------------------------------
//  EDGE Platform Interface Header
//----------------------------------------------------------------------------
//
//  Copyright (c) 1999-2008  The EDGE Team.
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//----------------------------------------------------------------------------

#ifndef __EDGE_PLATFORM_INTERFACE__
#define __EDGE_PLATFORM_INTERFACE__

#include "headers.h"
#include "types.h"
#include "macros.h"
#include "asserts.h"

#ifdef __linux__
#include "epi_linux.h"
#endif

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#include "epi_win32.h"
#endif

#ifdef __APPLE__
#include "epi_macosx.h"
#endif

// Clang wasn't happy when I tried to put these in a single ifdef statement :()
#ifndef __linux__
// The macos header should suffice for BSD as well in this particular case - Dasho
#ifdef __unix__
// I think APPLE would pass the __unix__ check too, so avoid duplicate includes
#ifndef __APPLE__
#include "epi_macosx.h"
#endif
#endif
#endif

namespace epi
{
	// Base Functions
	bool Init(void);
	void Shutdown(void);
};

/* Important functions provided by Engine code */

void I_Error(const char *error,...) GCCATTR((format(printf, 1, 2)));
void I_Warning(const char *warning,...) GCCATTR((format(printf, 1, 2)));
void I_Printf(const char *message,...) GCCATTR((format(printf, 1, 2)));
void I_Debugf(const char *message,...) GCCATTR((format(printf, 1, 2)));

#endif /* __EDGE_PLATFORM_INTERFACE__ */

//--- editor settings ---
// vi:ts=4:sw=4:noexpandtab
