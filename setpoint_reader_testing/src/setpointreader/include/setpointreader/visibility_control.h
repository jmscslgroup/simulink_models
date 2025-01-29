#ifndef SETPOINTREADER__VISIBILITY_CONTROL_H_
#define SETPOINTREADER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SETPOINTREADER_EXPORT __attribute__ ((dllexport))
    #define SETPOINTREADER_IMPORT __attribute__ ((dllimport))
  #else
    #define SETPOINTREADER_EXPORT __declspec(dllexport)
    #define SETPOINTREADER_IMPORT __declspec(dllimport)
  #endif
  #ifdef SETPOINTREADER_BUILDING_LIBRARY
    #define SETPOINTREADER_PUBLIC SETPOINTREADER_EXPORT
  #else
    #define SETPOINTREADER_PUBLIC SETPOINTREADER_IMPORT
  #endif
  #define SETPOINTREADER_PUBLIC_TYPE SETPOINTREADER_PUBLIC
  #define SETPOINTREADER_LOCAL
#else
  #define SETPOINTREADER_EXPORT __attribute__ ((visibility("default")))
  #define SETPOINTREADER_IMPORT
  #if __GNUC__ >= 4
    #define SETPOINTREADER_PUBLIC __attribute__ ((visibility("default")))
    #define SETPOINTREADER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SETPOINTREADER_PUBLIC
    #define SETPOINTREADER_LOCAL
  #endif
  #define SETPOINTREADER_PUBLIC_TYPE
#endif
#endif  // SETPOINTREADER__VISIBILITY_CONTROL_H_
// Generated 28-Jan-2025 11:52:42
// Copyright 2019-2020 The MathWorks, Inc.
