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
 
#include "UpdaterWindows.h"
#include "Application.h"
#include <winsparkle.h>
 
// callback for the sparkle updater
void win_sparkle_shutdown_request_callback()
{
  // shutdown kodi...
  g_application.Stop(EXITCODE_QUIT);
}

void CUpdaterWindows::Init()
{
  // init win_sparkle inapp updater
  win_sparkle_set_shutdown_request_callback(win_sparkle_shutdown_request_callback);
  win_sparkle_init();
}

void CUpdaterWindows::Deinit()
{
  // shutdown the updater
  win_sparkle_cleanup();
}

void CUpdaterWindows::SetAutoUpdateEnabled(bool enabled)
{
  win_sparkle_set_automatic_check_for_updates(enabled ? 1 : 0);
}

bool CUpdaterWindows::GetAutoUpdateEnabled()
{
  return win_sparkle_get_automatic_check_for_updates() == 1 ? true : false;
}

void CUpdaterWindows::CheckForUpdate()
{
  win_sparkle_check_update_with_ui();
}