/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod (C)2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This file is part of the SourceMod/SourcePawn SDK.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#if defined _adminmenu_included
 #endinput
#endif
#define _adminmenu_included

/* Decide whether topmenus should be required */
#if !defined REQUIRE_PLUGIN
 #if defined REQUIRE_EXTENSIONS
  #define TEMP_REQUIRE_EXTENSIONS
  #undef REQUIRE_EXTENSIONS
 #endif
#endif

#include <topmenus>

/* Restore old REQUIRE_EXTENSIONS value if necessary */
#if defined TEMP_REQUIRE_EXTENSIONS
 #define REQUIRE_EXTENSIONS
 #undef TEMP_REQUIRE_EXTENSIONS
#endif

/** Kategoria dla komend gracza. */
#define ADMINMENU_PLAYERCOMMANDS		"PlayerCommands"
/** Kategoria dla komend server'a. */
#define ADMINMENU_SERVERCOMMANDS		"ServerCommands"
/** Kategoria na komendy głosowania. */
#define ADMINMENU_VOTINGCOMMANDS		"VotingCommands"

/**
 * Wywoływane kiedy menu admina jest tworzone, pluginy 3-cie mogą przechwycić Handle lub dodać kategorie.
 *
 * @param topmenu		Handle do TopMenu menu admina.
 */
forward void OnAdminMenuCreated(Handle topmenu);

/**
 * Wywoływane kiedy menu admina jest gotowe dodania itemów.
 *
 * @param topmenu		Handle do TopMenu menu admina.
 */
forward void OnAdminMenuReady(Handle topmenu);

/**
 * Pobiera Handle do TopMenu menu admina.
 *
 * @return				Handle do TopMenu menu admina lub INVALID_HANDLE jeśli jeszcze nie jest stworzone.
 */
native TopMenu GetAdminTopMenu();

/**
 * Dodaje cel do menu admina.
 *
 * Każdy klient jest wyświetlany jako: nick (UserID). Każdy item przechowuje UserID jako ciąg znaków w info.
 *
 * @param menu			Menu Handle.
 * @param source_client	Source client, or 0 to ignore immunity. (To do przetłumaczenia póżniej, moje tłumaczenie się nie klej)
 * @param in_game_only	True aby można było wybrać tylko klientów w grze.
 * @param alive_only 	True aby można było wybrać tylko żywych klientów.
 * @return				Ilość dodanych klientów.
 */
native int AddTargetsToMenu(Handle menu,
						int source_client,
						bool in_game_only=true,
						bool alive_only=false);

/**
 * Dodaje cel do menu admina.
 *
 * Każdy klient jest wyświetlany jako: nick (UserID). Każdy item przechowuje UserID jako ciąg znaków w info.
 *
 * @param menu			Menu Handle.
 * @param source_client	Source client, or 0 to ignore immunity. (To do przetłumaczenia póżniej, moje tłumaczenie się nie klej)
 * @param flags			Flagi COMMAND_FILTER z commandfilters.inc.
 * @return				Ilość dodanych klientów.
 */
native int AddTargetsToMenu2(Handle menu, int source_client, int flags);

/**
 * Otwiera ponownie menu admina klientowi po wybraniu itemu pod warunkiem że Handle jest prawidłowy.
 * Auto-aborts if the Handle is invalid.
 *
 * @param topmenu		TopMenu Handle.
 * @param client		ID klienta.
 * @return				True jeśli powiodło się, false w przeciwnym wypadku.
 */
stock bool RedisplayAdminMenu(Handle topmenu, int client)
{
	if (topmenu == INVALID_HANDLE)
	{
		return false;
	}

	return DisplayTopMenu(topmenu, client, TopMenuPosition_LastCategory);
}

/* DO NOT EDIT BELOW THIS LINE */

public SharedPlugin __pl_adminmenu =
{
	name = "adminmenu",
	file = "adminmenu.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_adminmenu_SetNTVOptional()
{
	MarkNativeAsOptional("GetAdminTopMenu");
	MarkNativeAsOptional("AddTargetsToMenu");
	MarkNativeAsOptional("AddTargetsToMenu2");
}
#endif
