/**
*   @file    SrecFormat.h
*   @version 1.0.0
*
*   @brief   SrecFormat - API header
*   @details Contains declarations of the SrecFormat API functions.
*
*   @author  Lam Nguyen Phu
*
*   @{
*/
/*==================================================================================================
*
==================================================================================================*/

#ifndef SREC_FORMAT_H
#define SREC_FORMAT_H

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define E_OK      0x00U
#define E_NOT_OK  0x01U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Record type Enum.
* @details        Record type - single numeric digit "0" to "9" character (ASCII 0x30 to 0x39),
*                 defining the type of record.
*/
typedef enum {
    S0 = 0, /* Header */
    S1,     /* Data 16-bit Address */
    S2,     /* Data 24-bit Address */
    S3,     /* Data 32-bit Address */
    S4,     /* Reserved*/
    S5,     /* Count 16-bit Count */
    S6,     /* Count 24-bit Count */
    S7,     /* Start Address 32-bit Address */
    S8,     /* Start Address 24-bit Address */
    S9      /* Start Address 16-bit Address */
} RecordType;

/**
* @brief          Format Result Type.
* @details        Result after format srec file.
*/
typedef enum {
    NO_ERROR = 0, /* No ERROR */
    BAD_FORMAT,   /* Bad format: invalid character */
    BAD_RECORD,   /* Bad record: record type failure*/
    BAD_CKECKSUM, /* Bad check sum: check sum field failure */
    BAD_COUNT,    /* Bad count: count field failure */
} FomatResultType;

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
 * @brief This structure describes a Record structure
 */
typedef struct {
    RecordType      nType;        /* Record type */
    uint8_t         u8ByteCount;  /* Count */
    uint32_t        u32Address;   /* Address */
    uint8_t         au8Data[256]; /* Data */
    FomatResultType nResult;      /* Result */
} RecordStructureType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

Std_ReturnType SrecFormat_Start( uint8_t* buffer, FILE* fp );

#ifdef __cplusplus
}
#endif

#endif /* SREC_FORMAT_H */

/** @} */
