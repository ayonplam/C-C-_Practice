/**
*   @file    RingBuffer.h
*   @version 1.0.0
*
*   @brief   RingBuffer - API header
*   @details Contains declarations of the RingBuffer API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define QUEUE_LEN 4U   /* Queue has 4 note */
#define NOTE_SIZE 256U /* 256 bytes */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This structure describes a note of ring buffer
 */
typedef struct {
    uint8_t Note[NOTE_SIZE];
} NoteType;

/**
 * @brief This structure describes a example frame to save a note (pop)
 */
typedef struct {
    uint8_t Frame[NOTE_SIZE];
} FrameType;

/**
 * @brief This structure describes a ring buffer structure
 */

typedef struct {
    NoteType * Queue[QUEUE_LEN];
    uint16_t Head;  /* increase head when push a new line */
    uint16_t Tail;  /* increse tail when pop a new line */
    uint16_t Index; /* current index in a elemnent */
    bool isFull;    /* flag check queue is full, = 1 */
    bool isEmpty;   /* flag check queue is empty, = 1 */
} RingBufferType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

void RingBuff_Init(RingBufferType * MyBuffer, NoteType * pQueue);

void RingBuff_Push (RingBufferType * MyBuffer , uint8_t Data);

void RingBuff_Pop (RingBufferType * MyBuffer, FrameType * MyFrame);

#ifdef __cplusplus
}
#endif

#endif /* RING_BUFFER_H */

/** @} */
