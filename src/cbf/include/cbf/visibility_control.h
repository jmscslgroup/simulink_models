#ifndef CBF__VISIBILITY_CONTROL_H_
#define CBF__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CBF_EXPORT __attribute__ ((dllexport))
    #define CBF_IMPORT __attribute__ ((dllimport))
  #else
    #define CBF_EXPORT __declspec(dllexport)
    #define CBF_IMPORT __declspec(dllimport)
  #endif
  #ifdef CBF_BUILDING_LIBRARY
    #define CBF_PUBLIC CBF_EXPORT
  #else
    #define CBF_PUBLIC CBF_IMPORT
  #endif
  #define CBF_PUBLIC_TYPE CBF_PUBLIC
  #define CBF_LOCAL
#else
  #define CBF_EXPORT __attribute__ ((visibility("default")))
  #define CBF_IMPORT
  #if __GNUC__ >= 4
    #define CBF_PUBLIC __attribute__ ((visibility("default")))
    #define CBF_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CBF_PUBLIC
    #define CBF_LOCAL
  #endif
  #define CBF_PUBLIC_TYPE
#endif
#endif  // CBF__VISIBILITY_CONTROL_H_
// Generated 12-Oct-2023 14:21:42
// Copyright 2019-2020 The MathWorks, Inc.
