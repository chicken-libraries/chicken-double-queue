//
// file: package.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef CHICKEN_PACKAGE_H
#define CHICKEN_PACKAGE_H

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_CHICKEN_PACKAGE
#define CHICKEN_PUBLIC __attribute__((visibility("default")))
#else
#define CHICKEN_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard.
//

CHICKEN_PUBLIC const char *greet(void);

#endif // end of CHICKEN_PACKAGE_H
