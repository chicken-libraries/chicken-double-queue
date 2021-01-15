//
// file: double-queue.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef CHICKEN_DEQUEUE_PACKAGE_H
#define CHICKEN_DEQUEUE_PACKAGE_H

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_CHICKEN_DEQUEUE_PACKAGE
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

typedef struct DeQueueOf DeQueueOf;

//
// Constructor and destructor functions
//

CHICKEN_PUBLIC DeQueueOf *chickenDeQueueCreate(void);
CHICKEN_PUBLIC void chickenDeQueueErase(DeQueueOf **structureRef);

//
// Operations provided
//

CHICKEN_PUBLIC void chickenDeQueuePush(DeQueueOf *structurePtr, char *data);
CHICKEN_PUBLIC void chickenDeQueuePushStart(DeQueueOf *structurePtr, char *data);
CHICKEN_PUBLIC void chickenDeQueuePushEnd(DeQueueOf *structurePtr, char *data);
CHICKEN_PUBLIC char *chickenDeQueuePop(DeQueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenDeQueuePopStart(DeQueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenDeQueuePopEnd(DeQueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenDeQueuePeek(DeQueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenDeQueuePeekStart(DeQueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenDeQueuePeekEnd(DeQueueOf *structurePtr);
CHICKEN_PUBLIC unsigned int chickenDeQueueItsEmpty(DeQueueOf *structurePtr);
CHICKEN_PUBLIC unsigned int chickenDeQueueNotEmpty(DeQueueOf *structurePtr);
CHICKEN_PUBLIC unsigned int chickenDeQueueGetSize(DeQueueOf *structurePtr);

#endif // end of CHICKEN_PACKAGE_H
