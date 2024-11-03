#include "SrecFormat.h"

int main() {
    FILE* fp;       /* file to read */
    FILE* fp1;      /* file to write */
    long file_size; /* file size of fp */
    int ret;        /* return value*/
    size_t br = 0;

    /* open srec file */
    fp = fopen( "..\\srecfile\\freg", "rb" );
    fseek( fp, 0, SEEK_END );
    file_size = ftell( fp );
    rewind( fp );

    /* Allocate memory in heap to save data from sreg file */
    uint8_t* buffer = (uint8_t*)calloc( 1, file_size );
    if ( buffer == NULL ) {
        fclose( fp );
        fprintf( stderr, "Out of memory!\n" );
        return E_NOT_OK;
    }
    br = fread(buffer, 1, file_size, fp);

    /* close file */
    fclose( fp );

    if ( !br ) {
        fprintf( stderr, "No data to read.\n" );
        free( buffer );
        return E_NOT_OK;
    }

    /* Open file to write data field */
    fopen_s( &fp1, "..\\srecfile\\DataField.txt", "w" );
    ret = SrecFormat_Start( buffer, fp1 );

    /* Close file */
    fclose( fp1 );

    /* Return */
    /* Return */
    switch (ret)
    {
        case E_NOT_OK:
            free(buffer);
            return E_NOT_OK;
            break;
        case E_OK:
            fprintf(stderr, "Parse success and write data field to datafiled.txt done\n");
            free(buffer);
            return E_OK;
    }
}