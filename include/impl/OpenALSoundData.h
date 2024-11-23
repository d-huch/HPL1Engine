/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HPL_OPENAL_SOUND_DATA_H
#define HPL_OPENAL_SOUND_DATA_H

#include "sound/SoundData.h"
//#include "OAL_Funcs.h"

namespace hpl {

class cOAL_Sample; // Forward declaration
class cOAL_Stream; // Forward declaration

class cOpenALSoundData : public iSoundData
{
public:
  cOpenALSoundData(tString asName, bool abStream);
  ~cOpenALSoundData();

  bool CreateFromFile(const tString &asFile);

  iSoundChannel* CreateChannel(int alPriority);

  bool IsStream(){ return mbStream;}

  bool IsStereo();

  cOAL_Sample*	GetSample(){ return ( mpSample ); }
  cOAL_Stream*	GetStream(){ return ( mpStream ); }

private:
  cOAL_Sample*	mpSample;
  cOAL_Stream*	mpStream;
};
};
#endif // HPL_OPENAL_SOUND_DATA_H