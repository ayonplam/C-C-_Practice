/**
*   @file    LinkedList.h
*   @version 1.0.0
*
*   @brief   LinkedList API header
*   @details Contains declarations of the LinkedList API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>

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
#define E_OK      0x00U
#define E_NOT_OK  0x01U

#define NOT_EXIST NULL
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief This type can be used as standard API return type which is shared between the RTE and the
*        BSW modules.
*/
/* @implements Std_ReturnType_type */
typedef uint8_t Std_ReturnType;

/**
 * @brief This structure describes a note of linked list
 */
typedef struct Node {
    uint64_t Data;
    struct Node * pNext;
} NodeType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

void PrintList( const NodeType * pNodeHead );

NodeType* Search( NodeType * pNodeHead, uint64_t u64Value );

Std_ReturnType AddNode_ToTail( NodeType * pNodeHead, NodeType * pNewNode);

Std_ReturnType AddNode_ToHead( NodeType * pNodeHead, NodeType * pNewNode);

Std_ReturnType DeleteNode( uint64_t u64Value, NodeType * pNodeHead );

void SortList( NodeType * pNodeHead );

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */

/** @} */
