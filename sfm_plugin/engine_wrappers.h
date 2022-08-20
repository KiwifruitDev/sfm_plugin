/*
 * sfm_plugin
 * ----------
 * 
 * MIT License
 * 
 * Copyright (c) 2022 KiwifruitDev
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _INCLUDE_SOURCE_ENGINE_WRAPPERS_
#define _INCLUDE_SOURCE_ENGINE_WRAPPERS_

#include <eiface.h>

extern IVEngineServer *engine;
extern CGlobalVars *gpGlobals;

#if SOURCE_ENGINE == SE_EPISODEONE && defined METAMOD_PLAPI_VERSION
#error "Metamod:Source 1.6 API is not supported on the old engine."
#endif

#define ENGINE_CALL(func) SH_CALL(engine, &IVEngineServer::func)

/**
 * Wrap some API calls for legacy MM:S.
 */
#if !defined METAMOD_PLAPI_VERSION
#define GetEngineFactory engineFactory
#define GetServerFactory serverFactory
#define MM_Format snprintf
#define	GetCGlobals	pGlobals
#else
#define MM_Format g_SMAPI->Format
#endif

#if SOURCE_ENGINE <= SE_DARKMESSIAH
/**
 * Wrap the CCommand class so our code looks the same on all engines.
 */
class CCommand
{
public:
	const char *ArgS()
	{
		return engine->Cmd_Args();
	}
	int ArgC()
	{
		return engine->Cmd_Argc();
	}

	const char *Arg(int index)
	{
		return engine->Cmd_Argv(index);
	}
};

#define CVAR_INTERFACE_VERSION VENGINE_CVAR_INTERFACE_VERSION
#endif

/**
 * Left 4 Dead engine removed these from IVEngineServer.
 */
#if SOURCE_ENGINE >= SE_LEFT4DEAD

inline int IndexOfEdict(const edict_t *pEdict)
{
	return (int)(pEdict - gpGlobals->pEdicts);
}
inline edict_t *PEntityOfEntIndex(int iEntIndex)
{
	if (iEntIndex >= 0 && iEntIndex < gpGlobals->maxEntities)
	{
		return (edict_t *)(gpGlobals->pEdicts + iEntIndex);
	}
	return NULL;
}

#else

inline int IndexOfEdict(const edict_t *pEdict)
{
	return engine->IndexOfEdict(pEdict);
}
inline edict_t *PEntityOfEntIndex(int iEntIndex)
{
	return engine->PEntityOfEntIndex(iEntIndex);
}

#endif

#endif //_INCLUDE_SOURCE_ENGINE_WRAPPERS_

