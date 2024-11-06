#ifndef VELOCITY_CONTROLLER__VISIBILITY_CONTROL_H_
#define VELOCITY_CONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define VELOCITY_CONTROLLER_EXPORT __attribute__ ((dllexport))
    #define VELOCITY_CONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define VELOCITY_CONTROLLER_EXPORT __declspec(dllexport)
    #define VELOCITY_CONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef VELOCITY_CONTROLLER_BUILDING_LIBRARY
    #define VELOCITY_CONTROLLER_PUBLIC VELOCITY_CONTROLLER_EXPORT
  #else
    #define VELOCITY_CONTROLLER_PUBLIC VELOCITY_CONTROLLER_IMPORT
  #endif
  #define VELOCITY_CONTROLLER_PUBLIC_TYPE VELOCITY_CONTROLLER_PUBLIC
  #define VELOCITY_CONTROLLER_LOCAL
#else
  #define VELOCITY_CONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define VELOCITY_CONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define VELOCITY_CONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define VELOCITY_CONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define VELOCITY_CONTROLLER_PUBLIC
    #define VELOCITY_CONTROLLER_LOCAL
  #endif
  #define VELOCITY_CONTROLLER_PUBLIC_TYPE
#endif
#endif  // VELOCITY_CONTROLLER__VISIBILITY_CONTROL_H_
// Generated 18-Oct-2023 15:57:52
// Copyright 2019-2020 The MathWorks, Inc.
