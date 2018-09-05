

//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////
// pdfmerge
// Simple workaround using Ghostscript
//////////////////////////////////////////
//////////////////////////////////////////
//////////////////////////////////////////


#include <stdio.h>
#if defined(__linux__) //linux
#define MYOS 1
#elif defined(_WIN32)
#define MYOS 2
#elif defined(_WIN64)
#define MYOS 3
#elif defined(__unix__) 
#define MYOS 4  // freebsd
#define PATH_MAX 2500
#else
#define MYOS 0
#endif

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  //define getcwd



int main( int argc, char *argv[])
{
    int i ;   char cmdi[PATH_MAX];
    if ( argc >= 2)
    {
         for( i = 1 ; i < argc ; i++) 
         {
	       printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i ] );
         }

         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , " gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE=combine.pdf -dBATCH  " , PATH_MAX - strlen( cmdi ) -1 );
         for( i = 1 ; i < argc ; i++) 
         {
	    printf( "%d/%d: %s\n", i, argc-1 ,  argv[ i ] );
            strncat( cmdi , "\"" , PATH_MAX - strlen( cmdi ) -1 );
            strncat( cmdi , argv[i] , PATH_MAX - strlen( cmdi ) -1 );
            strncat( cmdi , "\"  " , PATH_MAX - strlen( cmdi ) -1 );
         }
         strncat( cmdi , "  " , PATH_MAX - strlen( cmdi ) -1 );
         printf( "COMMAND: %s\n", cmdi );
         system( cmdi );
         printf( "pdfmerge: command completed.\n" );

    }
    else
         printf( "pdfmerge: Need arguments\n" );
    return 0;
}


