/*
 *      Copyright (C) 2015 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#define BOOL XBMC_BOOL 
#include "UpdaterOsx.h"
#include "Application.h"
#undef BOOL

#import "osx/HotKeyController.h"
#import <Sparkle/Sparkle.h>
 
void CUpdaterOsx::Init()
{
  // init sparkle inapp updater
  [SUUpdater updaterForBundle:[NSBundle bundleForClass:[[HotKeyController sharedController] class]]];
}

void CUpdaterOsx::Deinit()
{
  // nothing to be done
}

void CUpdaterOsx::SetAutoUpdateEnabled(bool enabled)
{
  [[SUUpdater sharedUpdater] setAutomaticallyChecksForUpdates:enabled];
}

bool CUpdaterOsx::GetAutoUpdateEnabled()
{
  return [[SUUpdater sharedUpdater] automaticallyChecksForUpdates];
}

void CUpdaterOsx::CheckForUpdate()
{
  [[SUUpdater sharedUpdater] checkForUpdates:nil];
}
