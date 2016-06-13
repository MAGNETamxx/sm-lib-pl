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

#if defined _geoip_included
  #endinput
#endif
#define _geoip_included

#include <core>

/**
 * @section Adress IP może zawierać port, będzie on wycięty.
 */

/**
 * Pobiera 2-wu znakowy kod kraju z adressu IP. (np. US, CA, PL, itp.)
 *
 * @param ip			Adress IP.
 * @param ccode			Buffor do przechowania kodu.
 * @return				True jeśli zakończy się sukcessem, false jeśli nie może znależć kraju.
 */
native bool GeoipCode2(const char[] ip, char ccode[3]);

/**
 * Pobiera 3-rj znakowy kod kraju z adressu IP. (np. USA, CAN, POL, itp.)
 *
 * @param ip			Adress IP.
 * @param ccode			Buffor do przechowania kodu.
 * @return				True jeśli zakończy się sukcessem, false jeśli nie może znależć kraju.
 */
native bool GeoipCode3(const char[] ip, char ccode[4]);

/**
 * Pobiera pełną nazwę kraju z adressu IP (Maksymalna długość nazwy kraju wynosi 45).
 *
 * @param ip			Adress IP.
 * @param name			Buffor do przechowania kodu.
 * @param maxlength			Rozmiar buffora.
 * @return				True jeśli zakończy się sukcessem, false jeśli nie może znależć kraju.
 */
native bool GeoipCountry(const char[] ip, char[] name, int maxlength);

/**
 * @endsection
 */

/**
 * Do not edit below this line!
 */
public Extension __ext_geoip =
{
	name = "GeoIP",
	file = "geoip.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public void __ext_geoip_SetNTVOptional()
{
	MarkNativeAsOptional("GeoipCode2");
	MarkNativeAsOptional("GeoipCode3");
	MarkNativeAsOptional("GeoipCountry");
}
#endif
