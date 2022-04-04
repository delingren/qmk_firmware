/* Copyright 2021 SawnsProjects
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

#define XXX KC_NO

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │00 │10 │01 │11 │02 │12 │03 │13 │04 │14 │05 │15 │06 │26 │17 │07 │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
 * │20   │30 │21 │31 │22 │32 │23 │33 │24 │34 │25 │35 │36 │46   │37 │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │40    │50 │41 │51 │42 │52 │43 │53 │44 │54 │45 │55 │47      │57 │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │60      │70 │61 │71 │62 │72 │63 │73 │64 │74 │65 │75    │77 │67 │
 * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │80  │90  │81  │82      │92  │93        │94  │85  │ │95 │97 │87 │
 * └────┴────┴────┴────────┴────┴──────────┴────┴────┘ └───┴───┴───┘
 */

#define LAYOUT_65_ansi_blocker_split_sp( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,      K0F, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1F, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D,      K2F, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, K3F, \
    K40,      K42, K43,      K45, K46, K47, K48,           K4B,      K4D, K4E, K4F \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, XXX, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, XXX, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, XXX, K2D, XXX, K2F }, \
    { K30, XXX, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, XXX, K3D, K3E, K3F }, \
    { K40, XXX, K42, K43, XXX, K45, K46, K47, K48, XXX, XXX, K4B, XXX, K4D, K4E, K4F }, \
}
