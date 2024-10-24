/**
*   @file    RingBuffer.c
*   @version 1.0.0
*
*   @brief   RingBuffer - API source
*   @details This file implements RingBuffer API
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "RingBuffer.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Intialize a queue
* @details    This function intialize a queue.
*
* @param[in]  MyBuffer A pointer to the ring buffer.
* @param[in]  pQueue Pointer to memory region for a queue
*
* @return     void
*/
void RingBuff_Init(RingBufferType * MyBuffer, NoteType * pQueue)
{
    for (uint8_t i = 0; i <= QUEUE_LEN; i++)
    {
        MyBuffer->Queue[i] = pQueue + i;
    }
    MyBuffer->Head    = 0;
    MyBuffer->Tail    = 0;
    MyBuffer->Index   = 0;
    MyBuffer->isFull  = 0;
    MyBuffer->isEmpty = 1;
}

/**
* @brief      Push data to queue.
* @details    This function push 1 byte data to queue.
*
* @param[in]  MyBuffer A pointer to the ring buffer.
*
* @return     void
* @note       Will overwrite data to queue when queue is full
*/
void RingBuff_Push (RingBufferType * MyBuffer , uint8_t Data)
{
    /* Get pointer of current head note */
    NoteType * pHeadNote = MyBuffer->Queue[MyBuffer->Head];

    /* Get current position for push data */
    uint8_t * pPosition = pHeadNote->Note + MyBuffer->Index;

    /* Load data to queue */
    *pPosition = Data;

    /* If data = '\n' next new line , increase head */
    if (Data == '\n')
    {
        /* clear empty flag */
        MyBuffer->isEmpty = 0;

        /* new line */
        MyBuffer->Head++;
        MyBuffer->Index = 0;
        if (MyBuffer->Head >= QUEUE_LEN)
        {
            MyBuffer->Head = 0;
        }

        /* check buffer is full and raise full flag*/
        if (MyBuffer->Head == MyBuffer->Tail)
        {
            MyBuffer->isFull = 1;
        }
    }
    else
    {
        MyBuffer->Index++;
    }

}

/**
* @brief      Pop data from queue.
* @details    This function pop a note from queue.
*
* @param[in]  MyBuffer A pointer to the ring buffer.
* @param[in]  MyBuffer A pointer to the frame store data.
*
* @return     void
*/
void RingBuff_Pop (RingBufferType * MyBuffer, FrameType * MyFrame)
{
    /* Get data */
    *MyFrame = *(FrameType *)(MyBuffer->Queue[MyBuffer->Tail]);

    /* Increase tail */
    MyBuffer->Tail++;
    if (MyBuffer->Tail >= QUEUE_LEN)
        {
            MyBuffer->Tail = 0;
        }

    /* Check buffer is empty and raise empty flag */
    if (MyBuffer->Head == MyBuffer->Tail)
        {
            MyBuffer->isEmpty = 1;
        }
}
#ifdef __cplusplus
}
#endif

/** @} */
