#ifndef SET_POINT_ADAPTER__VISIBILITY_CONTROL_H_
#define SET_POINT_ADAPTER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define SET_POINT_ADAPTER_EXPORT __attribute__ ((dllexport))
    #define SET_POINT_ADAPTER_IMPORT __attribute__ ((dllimport))
  #else
    #define SET_POINT_ADAPTER_EXPORT __declspec(dllexport)
    #define SET_POINT_ADAPTER_IMPORT __declspec(dllimport)
  #endif
  #ifdef SET_POINT_ADAPTER_BUILDING_LIBRARY
    #define SET_POINT_ADAPTER_PUBLIC SET_POINT_ADAPTER_EXPORT
  #else
    #define SET_POINT_ADAPTER_PUBLIC SET_POINT_ADAPTER_IMPORT
  #endif
  #define SET_POINT_ADAPTER_PUBLIC_TYPE SET_POINT_ADAPTER_PUBLIC
  #define SET_POINT_ADAPTER_LOCAL
#else
  #define SET_POINT_ADAPTER_EXPORT __attribute__ ((visibility("default")))
  #define SET_POINT_ADAPTER_IMPORT
  #if __GNUC__ >= 4
    #define SET_POINT_ADAPTER_PUBLIC __attribute__ ((visibility("default")))
    #define SET_POINT_ADAPTER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define SET_POINT_ADAPTER_PUBLIC
    #define SET_POINT_ADAPTER_LOCAL
  #endif
  #define SET_POINT_ADAPTER_PUBLIC_TYPE
#endif
#endif  // SET_POINT_ADAPTER__VISIBILITY_CONTROL_H_
// Generated 28-Jan-2025 17:35:22
// Copyright 2019-2020 The MathWorks, Inc.
