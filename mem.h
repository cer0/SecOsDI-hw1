/*
 * =====================================================================================
 *
 *       Filename:  mem.h
 *
 *    Description:  Header file for memory manipulation, 
 *    				and string manipulation libraries.
 *    				To be included in nanoOS in the future. All
 *    				functions are re-implementations of
 *    				their std library equivalents.
 *
 *        Version:  1.0
 *        Created:  02/07/2012 03:02:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Armando Diaz Tolentino (adt), adiazt2@uic.edu
 *        Company:  CompuGlobalHyperMegaNet, inc
 *
 * =====================================================================================
 */

#include "consoleout.h"
#include <stdarg.h>

#define NULL 0
/* the signal TERM for process termination */
#define TERM 15
/* assert() implementation
 *	most of this code is from
 *	"A Book On C" 4th Ed.
 *	By Al Kelley & Ira Pohl
 *	pg 389
 * */
#define ASSERT(expr)				\
	if ( !(expr) ) {					\
		printf( "\n%s%s\n%s%s\n%s%d\n\n", \
		"Assert failed: ", #expr, 	\
		" in file ", __FILE__, 		\
		" at line ", __LINE__) ;	\
		kill( getpid(), TERM );	\
	}

/* memory manipulation functions */
void* memcpy( void* dest, const void* src, size_t n ) ;
void* memset( void* s, int c, size_t n ) ;
int memcmp( const void* s1, const void* s2, size_t n ) ;

/* string manipulation functions */
char* strcat( char* dest, const char* src ) ;
char* strncat( char* dest, const char* src, size_t n ) ;
int strcmp( const char* s1, const char* s2) ;
int strncmp( const char* s1, const char* s2, size_t n ) ;
char* strcpy( char* dest, const char* src ) ;
char* strncpy( char* dest, const char* src, size_t n ) ;

/* printing to stdout */
int printf( const char* format, ... ) ;


/* functions added by me
 *  not part of the hwk specifications
 */
int strlen( char* str ) ;
