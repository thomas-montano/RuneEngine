/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "Rune Engine", "index.html", [
    [ "Welcome to the RuneEngine!", "index.html#Welcome", [
      [ "Getting Started", "index.html#startup", null ],
      [ "Setting up a New Rune Project", "index.html#setup", null ],
      [ "Engine Features", "index.html#features", null ],
      [ "Engine Issues", "index.html#bugs", null ]
    ] ],
    [ "Game Objects", "game_objects.html", [
      [ "Creating an Object", "game_objects.html#objects", null ],
      [ "Scripting", "game_objects.html#Scripts", null ]
    ] ],
    [ "Entry Point", "entry_point.html", null ],
    [ "Physics", "physics.html", [
      [ "Adding a static (non-moving) RigidBody to your GameObject.", "physics.html#Initialization", null ],
      [ "Giving your RigidBody movement.", "physics.html#massChange", null ]
    ] ],
    [ "Shaders", "shaders.html", [
      [ "Vertex Shader", "shaders.html#vertex", null ],
      [ "Fragment Shader", "shaders.html#fragment", null ]
    ] ],
    [ "Game Scenes", "scenes.html", null ],
    [ "DoubleRect", "namespacerune.html#ab3b5b79043b5ba92b9e3828860594d80", null ],
    [ "FloatRect", "namespacerune.html#a691b34e0ab0fa7d997e3b113220df13f", null ],
    [ "IntRect", "namespacerune.html#a85f6fe1f75debf6d9fc8c78f58591175", null ],
    [ "broadPhaseCollisions", "namespacerune.html#a3c171aae49eceeeeba7a7755f87f20e3", null ],
    [ "crossProduct", "namespacerune.html#a406e83229b1b6c93214d89678a097d54", null ],
    [ "crossProduct", "namespacerune.html#adb17702f6bd94ef462be77b292be9cf3", null ],
    [ "crossProduct", "classrune_1_1_vec2.html#a1c55d9f7dfe9ba1b9836e6cc61fb144a", null ],
    [ "crossProduct", "classrune_1_1_vec3.html#ab93f36a4aa82d1bf3ca64c3fb41395ac", null ],
    [ "dotProduct", "namespacerune.html#ad9daf717da1fe95479dac74c359f5aac", null ],
    [ "dotProduct", "namespacerune.html#a59467d90e7e50e40a73c75731bf5137b", null ],
    [ "dotProduct", "classrune_1_1_vec2.html#ad6b587c19443420953ff219f4e5a473b", null ],
    [ "dotProduct", "classrune_1_1_vec3.html#ac04a52a948db3770f672e622dfb179a1", null ],
    [ "findNormal", "namespacerune.html#adcbe8ca970cd23adf592678466137317", null ],
    [ "findNormal", "classrune_1_1_vec2.html#aad1c80af83832823e4fa7953a27c218f", null ],
    [ "narrowPhaseCollisions", "namespacerune.html#a5fef3077b3a7831bfa17acfccb65918e", null ],
    [ "normalize", "namespacerune.html#aec151d5c17103d6293c270cca8bc8447", null ],
    [ "normalize", "namespacerune.html#a6856396c967e2821bb62160fcea2a941", null ],
    [ "normalize", "classrune_1_1_vec2.html#a0edfd4125a2b36a0f15b682bf23a0824", null ],
    [ "normalize", "classrune_1_1_vec3.html#abf37aa8efc34acc18169320eb03a0cdc", null ],
    [ "operator*", "classrune_1_1_mat2.html#a6702db0d91a42b817a26719c3cc83d81", null ],
    [ "operator*", "classrune_1_1_mat2.html#a4f2ca339f4920493702c960940dae047", null ],
    [ "operator*", "namespacerune.html#a0dcc2a1a019db8f6ebf5cb48fbdc368d", null ],
    [ "operator*", "namespacerune.html#a89ef20cf3b1ac021b02345d0d2c0efd7", null ],
    [ "operator*", "namespacerune.html#a8fc50b0f0f9dd6e30dec084fadeb25fd", null ],
    [ "operator*", "namespacerune.html#ad9cd349d6b97e8b6db545b56c35e4315", null ],
    [ "operator*", "namespacerune.html#a761b2a58c08e8d9cf7c8fbe0cce9a839", null ],
    [ "operator*", "classrune_1_1_vec2.html#a5d83b495f4db527989049d746e60da99", null ],
    [ "operator*", "classrune_1_1_vec3.html#ace0e90c0eb4ab96c176711b7c4b62daf", null ],
    [ "operator/", "namespacerune.html#a4e159aa0311b23ad3931669c30fb5d8c", null ],
    [ "operator/", "classrune_1_1_vec2.html#a66db98c6441689676e4767db660c012a", null ],
    [ "operator/", "classrune_1_1_vec2.html#a418c8098cbdac5a10ff014867a42848f", null ],
    [ "operator<<", "classrune_1_1_mat2.html#a282964f6219a5a041f69e6b3c7b12eec", null ],
    [ "operator<<", "classrune_1_1_mat3.html#a18d97345fcf7ed0466185e07c0622869", null ],
    [ "operator<<", "namespacerune.html#adea760761c002a69263959a4df3af578", null ],
    [ "operator<<", "namespacerune.html#a220260a80ae54a240b4fd015d1bf80cf", null ],
    [ "operator<<", "classrune_1_1_vec2.html#a488d402d4499bdb150d472cd35067cdc", null ],
    [ "operator<<", "classrune_1_1_vec3.html#aa8e4d33ec38b12c67e71d753cf33b8a8", null ],
    [ "positionalCorrection", "namespacerune.html#a9e1730d90e829952a3d1a71324587197", null ],
    [ "pythagoreanSolve", "namespacerune.html#aad04dc4af33c94d6d833532f613d010d", null ],
    [ "resolveCollisions", "namespacerune.html#a5845297089fab6833a3951f904efaa7e", null ],
    [ "updatePhysics", "namespacerune.html#a9d5b071fda26b92b7e8f3aebd5b0450a", null ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", "functions_dup" ],
        [ "Functions", "functions_func.html", "functions_func" ],
        [ "Variables", "functions_vars.html", null ],
        [ "Enumerations", "functions_enum.html", null ],
        [ "Enumerator", "functions_eval.html", null ],
        [ "Related Symbols", "functions_rela.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"_rune_engine_8h_source.html",
"classrune_1_1_mat3.html#a5b34738cb444cb2d458dfade9b0d9f70",
"classrune_1_1_vec3.html#ace0e90c0eb4ab96c176711b7c4b62daf"
];

const SYNCONMSG = 'click to disable panel synchronization';
const SYNCOFFMSG = 'click to enable panel synchronization';
const LISTOFALLMEMBERS = 'List of all members';