/**
*   @file    LinkedList.c
*   @version 1.0.0
*
*   @brief   LinkedList - API source
*   @details This file implements LinkedList API
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
#include "LinkedList.h"
#include <stdio.h>
/*==================================================================================================
*                          LOCAL TYPEDEFS ( STRUCTURES, UNIONS, ENUMS )
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
* @brief      Print Linked List
* @details    This function print Linked List
*
* @param[in]  pNodeHead A pointer to the Linked List
*
* @return     void
*/
void PrintList( const NodeType * pNodeHead )
{
    const NodeType * pNodeCurrent = pNodeHead;

    while ( pNodeCurrent ) {
        printf( "%lld -> ", pNodeCurrent->Data );
        pNodeCurrent = pNodeCurrent->pNext;
    }
    printf( "NULL\n" );
}

/**
* @brief      Search value is in Linked List
* @details    This function search value is in Linked List or not
*
* @param[in]  pNodeHead A pointer to the Linked List
* @param[in]  u64Value  Value need to be find
*
* @return     NodeType*
* @retval     NULL   The value not exist in Linked List
* @retval     others Pointer to the node of the value in Linked List
*/
NodeType* Search( NodeType * pNodeHead, uint64_t u64Value )
{
    NodeType * pNodeCurrent = pNodeHead;

    /* Run pointer current to each node of list until last node */
    while ( pNodeCurrent != NULL ) {
        if ( pNodeCurrent->Data == u64Value ) {
            break;
        }
        pNodeCurrent = pNodeCurrent->pNext; /* Pointer current to next node */
    }

    return pNodeCurrent;
}

/**
* @brief      Add a node to head of Linked List
* @details    This function add a node to head of Linked List
*
* @param[in]  pNodeHead   A pointer to the Linked List
* @param[in]  pNewNode    A pointer to the new node
*
* @return     Std_ReturnType
* @retval     E_OK     Add OK
* @retval     E_NOT_OK Add Failed
*/
Std_ReturnType AddNode_ToHead( NodeType * pNodeHead, NodeType * pNewNode)
{
    Std_ReturnType nReturnValue = E_OK;

    pNewNode->pNext = pNodeHead;
    pNodeHead = pNewNode;

    return nReturnValue;
}

/**
* @brief      Add a node to tail of Linked List
* @details    This function add a node to tail of Linked List
*
* @param[in]  pNodeHead   A pointer to the Linked List
* @param[in]  pNewNode    A pointer to the new node
*
* @return     Std_ReturnType
* @retval     E_OK     Add OK
* @retval     E_NOT_OK Add Failed
*/
Std_ReturnType AddNode_ToTail( NodeType * pNodeHead, NodeType * pNewNode)
{
    Std_ReturnType nReturnValue = E_OK;

    NodeType * pNodeCurrent = pNodeHead;

    /* Run pointer current to each node of list until last node */
    while ( pNodeCurrent != NULL )
    {
        pNodeCurrent = pNodeCurrent->pNext;
    }
    pNodeCurrent->pNext = pNewNode;
    pNewNode->pNext = NULL;

    return nReturnValue;
}

/**
* @brief      Delete a node of Linked List
* @details    This function delete a node of Linked List
*
* @param[in]  pNodeHead   A pointer to the Linked List
* @param[in]  u64Value    Value of node will be delete
*
* @return     Std_ReturnType
* @retval     E_OK     Delete OK
* @retval     E_NOT_OK Delete Failed
*/
Std_ReturnType DeleteNode( uint64_t u64Value, NodeType * pNodeHead )
{
    Std_ReturnType nReturnValue = E_NOT_OK;
    NodeType * pNodeCurrent  = pNodeHead;
    NodeType * pNodePrevious = NULL;

    while ( pNodeCurrent != NULL ) {
        if ( pNodeCurrent->Data == u64Value ) {
            break;
        }
        pNodePrevious = pNodeCurrent;
        pNodeCurrent  = pNodeCurrent->pNext; /* Pointer current to next node */
    }
    if ( pNodeCurrent != NULL )
    {
        pNodePrevious->pNext = pNodeCurrent->pNext;
        nReturnValue = E_OK;
    }

    return nReturnValue;
}

/**
* @brief      Sort Linked List
* @details    This function sort Linked List
*
* @param[in]  pNodeHead   A pointer to the Linked List
*
* @return     void
*/
void SortList( NodeType * pNodeHead )
{
    NodeType * pNodeCurrent  = pNodeHead;
    NodeType * pIndex = NULL;
    uint64_t temp;

    while ( pNodeCurrent != NULL ) {
        /* Node index will point to node next to current */
        pIndex = pNodeCurrent->pNext;

        while ( pIndex != NULL ) {
            /* If current node's data is greater than index's node data, swap the data between them */
            if ( pNodeCurrent->Data > pIndex->Data ) {
                temp = pNodeCurrent->Data;
                pNodeCurrent->Data = pIndex->Data;
                pIndex->Data = temp;
            }
            pIndex = pIndex->pNext;
        }
        pNodeCurrent = pNodeCurrent->pNext;
    }
}

#ifdef __cplusplus
}
#endif

/** @} */
