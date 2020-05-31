/* Copyright 2020 nabe
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    l00, l01,                                         R04, R05, \
    l10, l11, l02, l03, l04, l05, R00, R01, R02, R03, R14, R15, \
    l20, l21, l12, l13, l14, l15, R10, R11, R12, R13, R24, R25, \
    l30, l31, l22, l23, l24, l25, R20, R21, R22, R23, R34, R35, \
              l32, l33, l34, l35, R30, R31, R32, R33            \
) \
{ \
    {l05, l04, l03, l02, l01, l00}, \
    {l15, l14, l13, l12, l11, l10}, \
    {l25, l24, l23, l22, l21, l20}, \
    {l35, l34, l33, l32, l31, l30}, \
    {R00, R01, R02, R03, R04, R05}, \
    {R10, R11, R12, R13, R14, R15}, \
    {R20, R21, R22, R23, R24, R25}, \
    {R30, R31, R32, R33, R34, R35}  \
}
