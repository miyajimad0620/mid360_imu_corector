// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MID360_IMU_CORECTOR__VISIBILITY_HPP_
#define MID360_IMU_CORECTOR__VISIBILITY_HPP_

#ifdef __cplusplus
extern "C" {
#endif

// This logic was borroexampled (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__

#ifdef __GNUC__
#define MID360_IMU_CORECTOR_EXPORT __attribute__((dllexport))
#define MID360_IMU_CORECTOR_IMPORT __attribute__((dllimport))
#else
#define MID360_IMU_CORECTOR_EXPORT __declspec(dllexport)
#define MID360_IMU_CORECTOR_IMPORT __declspec(dllimport)
#endif

#ifdef MID360_IMU_CORECTOR_DLL
#define MID360_IMU_CORECTOR_PUBLIC MID360_IMU_CORECTOR_EXPORT
#else
#define MID360_IMU_CORECTOR_PUBLIC MID360_IMU_CORECTOR_IMPORT
#endif

#define MID360_IMU_CORECTOR_PUBLIC_TYPE MID360_IMU_CORECTOR_PUBLIC

#define MID360_IMU_CORECTOR_LOCAL

#else

#define MID360_IMU_CORECTOR_EXPORT __attribute__((visibility("default")))
#define MID360_IMU_CORECTOR_IMPORT

#if __GNUC__ >= 4
#define MID360_IMU_CORECTOR_PUBLIC __attribute__((visibility("default")))
#define MID360_IMU_CORECTOR_LOCAL __attribute__((visibility("hidden")))
#else
#define MID360_IMU_CORECTOR_PUBLIC
#define MID360_IMU_CORECTOR_LOCAL
#endif

#define MID360_IMU_CORECTOR_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // MID360_IMU_CORECTOR__VISIBILITY_HPP_
