//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "chicken/double-queue.h"

#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Chicken Libraries
// 'DeQueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_nextPtr] is the pointer to the next node
// > [_prevPtr] is the pointer to the prev node
//
struct DeQueueNode
{
    char *_data;
    struct DeQueueNode *_prevPtr;
    struct DeQueueNode *_nextPtr;
}; // end of struct

//
// This is the official definition for the Chicken Libraries
// 'DeQueueOf' type.
//
// Members:
// > _beginPtr is the pointer to queue begin
// > _endPtr is the pointer to queue end
//
struct DeQueueOf
{
    size_t _size;
    struct DeQueueNode *_endPtr;
    struct DeQueueNode *_beginPtr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
DeQueueOf *chickenDeQueueCreate(void)
{
    DeQueueOf *newStructure = malloc(sizeof(*newStructure));
    if (!newStructure)
    {
        return NULL;
    } // end if
    newStructure->_beginPtr = NULL;
    newStructure->_endPtr = NULL;
    newStructure->_size = 0;
    return newStructure;    
} // end of function chickenDeQueueCreate

//
// Should erase the queue structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structureRef]: Reference pointer to your structure
//
void chickenDeQueueErase(DeQueueOf **structureRef)
{
    if (!structureRef || !*structureRef)
    {
        return;
    } // end if

    while (chickenDeQueueNotEmpty(*structureRef))
    {
        chickenDeQueuePopEnd(*structureRef);
    } // end while

    free(*structureRef);
    *structureRef = NULL;
} // end of function chickenDeQueueErase

//
// Should push a new recored into start of the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void chickenDeQueuePushStart(DeQueueOf *structurePtr, char *data)
{
    if (!structurePtr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_nextPtr = structurePtr->_beginPtr;
    temp->_prevPtr = NULL;
    temp->_data = data;

    if (chickenDeQueueItsEmpty(structurePtr))
    {
        structurePtr->_endPtr = temp;
    } // end if
    else
    {
        structurePtr->_beginPtr->_prevPtr = temp;
    } // end else
    
    structurePtr->_beginPtr = temp;
    ++structurePtr->_size;
} // end of function chickenDeQueuePushStart

//
// Should push a new recored into end of the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void chickenDeQueuePushEnd(DeQueueOf *structurePtr, char *data)
{
    if (!structurePtr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_nextPtr = NULL;
    temp->_prevPtr = structurePtr->_endPtr;
    temp->_data = data;

    if (chickenDeQueueItsEmpty(structurePtr))
    {
        structurePtr->_beginPtr = temp;
    } // end if
    else
    {
        structurePtr->_endPtr->_nextPtr = temp;
    } // end else
    
    structurePtr->_endPtr = temp;
    ++structurePtr->_size;
} // end of function chickenDeQueuePushEnd

//
// Should return the value stored in the removed node from
// start of structure if the structure is both not nullptr
// and or empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
char *chickenDeQueuePopStart(DeQueueOf *structurePtr)
{
    if (!structurePtr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structurePtr->_beginPtr;
    char *value;
    structurePtr->_beginPtr = temp->_nextPtr;

    if (!structurePtr->_beginPtr)
    {
        structurePtr->_endPtr = NULL;
    } // end if
    else
    {
        structurePtr->_beginPtr->_prevPtr = NULL;
    } // end else
    --structurePtr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of function chickenDeQueuePopStart

//
// Should return the value stored in the removed node from
// end structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
char *chickenDeQueuePopEnd(DeQueueOf *structurePtr)
{
    if (!structurePtr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structurePtr->_endPtr;
    char *value;
    structurePtr->_endPtr = temp->_prevPtr;

    if (!structurePtr->_endPtr)
    {
        structurePtr->_beginPtr = NULL;
    } // end if
    else
    {
        structurePtr->_endPtr->_nextPtr = NULL;
    } // end else
    --structurePtr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of function chickenDeQueuePopEnd

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
char *chickenDeQueuePeekStart(DeQueueOf *structurePtr)
{
    return (chickenDeQueueNotEmpty(structurePtr)) ? structurePtr->_beginPtr->_data : NULL;
} // end of function chickenDeQueuePeekStart

//
// Should return the value stored in end pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
char *chickenDeQueuePeekEnd(DeQueueOf *structurePtr)
{
    return (chickenDeQueueNotEmpty(structurePtr)) ? structurePtr->_endPtr->_data : NULL;
} // end of function chickenDeQueuePeekEnd

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
unsigned int chickenDeQueueItsEmpty(DeQueueOf *structurePtr)
{
    return (!structurePtr->_beginPtr || !structurePtr->_endPtr) ? success : failed;
} // end of functions chickenDeQueueItsEmpty

//
// Should return a success value if the structure is not
// empty in anyway.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
unsigned int chickenDeQueueNotEmpty(DeQueueOf *structurePtr)
{
    return (structurePtr->_beginPtr || structurePtr->_endPtr) ? success : failed;
} // end of functions chickenDeQueueNotEmpty
