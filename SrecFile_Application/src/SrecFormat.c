/**
*   @file    SrecFormat.c
*   @version 1.0.0
*
*   @brief   SrecFormat - API source
*   @details This file implements SrecFormat API
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
#include "SrecFormat.h"

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
static uint8_t FromASCII_ToHex( const char cInput );

static RecordStructureType SrecFormat_Parse( uint8_t * u8RecordCharacter );

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Convert an ASCII character to HEX
* @details    This function convert an ASCII character to HEX.
*
* @param[in]  cInput an ASCII character
*
* @return     uint8_t result after convert
*/
static uint8_t FromASCII_ToHex( const char cInput )
{
    uint8_t u8HexReturnValue = 0;
    if ( cInput >= '0' && cInput <= '9' )
    {
        u8HexReturnValue = cInput - '0';
    }
    else if ( cInput >= 'A' && cInput <= 'F' )
    {
        u8HexReturnValue = cInput - 'A' + 10;
    }
    else if ( cInput >= 'a' && cInput <= 'f' )
    {
        u8HexReturnValue = cInput - 'a' + 10;
    }
    else
    {
        u8HexReturnValue = 0xff;
    }

    return u8HexReturnValue;
}

/**
* @brief      Parse a Srec line
* @details    This function parse a Srec line
*
* @param[in]  u8RecordCharacter A pointer to first character of Srec line
*
* @return     RecordStructureType
* @retval     A Record Structure afer parse from Srec line
*
*/
static RecordStructureType SrecFormat_Parse( uint8_t * u8RecordCharacter )
{
    RecordStructureType nRecord_New; /* Create new record to save into after parse */
    uint8_t u8ByteCount; /* Variable to save count field*/
    uint8_t i; /* The number of byte in a record use for loop and check byte count */

    nRecord_New.nResult = NO_ERROR;

    /* Check for start code */
    if ( u8RecordCharacter[0] != 'S' )
    {
        nRecord_New.nResult = BAD_FORMAT;
    }

    if ( nRecord_New.nResult == NO_ERROR )
    {
        /* Check for valid characters */
        for ( i = 1; u8RecordCharacter[i] != '\r' && u8RecordCharacter[i] != '\n'; i++ )
        {
            if ( FromASCII_ToHex(u8RecordCharacter[i]) > 0x0F )
            {
                nRecord_New.nResult = BAD_FORMAT;
            }
        }
    }

    if ( nRecord_New.nResult == NO_ERROR )
    {
        /* Get the record type */
        nRecord_New.nType = FromASCII_ToHex( u8RecordCharacter[1] );
        if ( nRecord_New.nType > S9 )
        {
            nRecord_New.nResult = BAD_RECORD;
        }
    }

    if ( nRecord_New.nResult == NO_ERROR )
    {
        /* Get the count field */
        u8ByteCount = ( FromASCII_ToHex( u8RecordCharacter[2] ) << 4 ) | FromASCII_ToHex( u8RecordCharacter[3] );
        if (i < u8ByteCount * 2 + 4)
        {
            nRecord_New.nResult = BAD_COUNT;
        }
    }

    if ( nRecord_New.nResult == NO_ERROR )
    {
        /* Get the record address */
        switch (nRecord_New.nType)
        {
            case S0:
                nRecord_New.u32Address = 0;
                nRecord_New.u8ByteCount = u8ByteCount - 3;
                break;
            case S1:
            case S5:
            case S9:
                /* Four hex digits address */
                nRecord_New.u32Address = ( FromASCII_ToHex( u8RecordCharacter[4] ) << 12 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[5] ) << 8 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[6] ) << 4 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[7] ) );
                nRecord_New.u8ByteCount = u8ByteCount - 3;
                break;
            case S2:
            case S6:
            case S8:
                /* Six hex digits address */
                nRecord_New.u32Address = ( FromASCII_ToHex( u8RecordCharacter[4] ) << 20 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[5] ) << 16 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[6] ) << 12 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[7] ) << 8 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[8] ) << 4 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[9] ) );
                nRecord_New.u8ByteCount = u8ByteCount - 4;
                break;
            case S3:
            case S7:
                /* Eight hex digits address */
                nRecord_New.u32Address = ( FromASCII_ToHex( u8RecordCharacter[4] ) << 28 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[5] ) << 24 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[6] ) << 20 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[7] ) << 16 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[8] ) << 12 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[9] ) << 8 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[10] ) << 4 ) |
                                         ( FromASCII_ToHex( u8RecordCharacter[11] ) );
                nRecord_New.u8ByteCount = u8ByteCount - 5;
                break;
            default:
                /* S4 record ignored */
                return nRecord_New;
    }
    }

    /* Calculate checksum and copy data bytes */
    uint8_t u8CheckSum_c = u8ByteCount +
                           ( nRecord_New.u32Address >> 24 ) +
                           ( nRecord_New.u32Address >> 16 ) +
                           ( nRecord_New.u32Address >> 8 ) +
                           ( nRecord_New.u32Address & 0xff );

    if ( nRecord_New.nType < S4 ) {
        nRecord_New.au8Data[nRecord_New.u8ByteCount] = 0;
        size_t data_offset = ( u8ByteCount - nRecord_New.u8ByteCount ) * 2 + 2;
        for (i = 0; i < nRecord_New.u8ByteCount; i++)
        {
            nRecord_New.au8Data[i] = ( FromASCII_ToHex( u8RecordCharacter[data_offset + i * 2] ) << 4) |
                                     ( FromASCII_ToHex( u8RecordCharacter[data_offset + i * 2 + 1] ) );
            u8CheckSum_c += nRecord_New.au8Data[i];
        }
    }

    u8CheckSum_c = ~u8CheckSum_c;

    uint8_t checksum_f = ( FromASCII_ToHex( u8RecordCharacter[u8ByteCount * 2 + 2] ) << 4 ) |
                         ( FromASCII_ToHex( u8RecordCharacter[u8ByteCount * 2 + 3] ) );
    if ( u8CheckSum_c != checksum_f )
    {
        nRecord_New.nResult = BAD_CKECKSUM;
    }

    return nRecord_New;
}

/**
* @brief      Process Srec File
* @details    This function process SREC file
*
* @param[in]  u8RecordCharacter A pointer to first character of Srec line
* @param[in]  fp                A pointer to a file use for store data after process
*
* @return     Std_ReturnType
* @retval     E__NOT_OK Wrong Format
* @retval     E_OK      Successful
*
*/
Std_ReturnType SrecFormat_Start( uint8_t * u8RecordCharacter, FILE* fp )
{
    Std_ReturnType nReturnValue = E_NOT_OK;
    RecordStructureType nRecord_New;
    uint32_t u32Line = 0;
    size_t s0 = 0;
    size_t data_offset;
    int i = 0;

    /* Start format a SREC line */
    while ( u8RecordCharacter )
    {
        if ( ( *u8RecordCharacter == '\r' ) || ( *u8RecordCharacter == '\n' ) )
        {
            /* Skip empty lines */
            u8RecordCharacter++;
            continue;
        }

        /* Parse a record */
        nRecord_New = SrecFormat_Parse( u8RecordCharacter );
        /* Return result */
        switch ( nRecord_New.nResult )
        {
            case BAD_FORMAT:
                break;
            case BAD_RECORD:
                fprintf( stderr, "Error on line %u: bad record type.\n", u32Line);
                break;
            case BAD_COUNT:
                fprintf( stderr, "Error on line %u: bad count.\n", u32Line );
                break;
            case BAD_CKECKSUM:
                fprintf( stderr, "Error on line %u: bad checksum.\n", u32Line );
                break;
            default:
                /* Excute data field */
                switch ( nRecord_New.nType ) {
                    case S0:
                        s0++;
                        fprintf( fp, "%s\n", nRecord_New.au8Data);
                        nReturnValue = E_OK;
                        break;
                    case S1:
                        data_offset = 8;
                        for ( i = 0; i < ( nRecord_New.u8ByteCount * 2 ); i++ )
                        {
                            fprintf( fp, "%c", u8RecordCharacter[data_offset] );
                            ++data_offset;
                        }
                        fprintf(fp, "\n");
                        nReturnValue = E_OK;
                        break;
                    case S2:
                        data_offset = 10;
                        for (i = 0; i < ( nRecord_New.u8ByteCount * 2 ); i++)
                        {
                            fprintf( fp, "%c", u8RecordCharacter[data_offset] );
                            ++data_offset;
                        }
                        fprintf(fp, "\n");
                        nReturnValue = E_OK;
                        break;
                    case S3:
                        data_offset = 12;
                        for (i = 0; i < ( nRecord_New.u8ByteCount * 2 ); i++)
                        {
                            fprintf(fp, "%c", u8RecordCharacter[data_offset]);
                            ++data_offset;
                        }
                        fprintf(fp, "\n");
                        nReturnValue = E_OK;
                        break;
                    case S5:
                    case S6:
                        if ( nRecord_New.u32Address != ( u32Line - 1 - s0 ) )
                        {
                            fprintf( stderr, "Error: wrong record count.\n" );
                            fclose( fp );
                        }
                        break;
                    case S7:
                    case S8:
                    case S9:
                        break;
                    default:
                        fprintf( stderr, "Error on line %u: unknown record type.\n", u32Line );
                        fclose( fp );
                        break;
                }
        }
        /* Find a new line start with character S */
        u32Line++;
        u8RecordCharacter = (uint8_t*)strchr((char*)++u8RecordCharacter, 'S');
    }

    return nReturnValue;
}

#ifdef __cplusplus
}
#endif

/** @} */
