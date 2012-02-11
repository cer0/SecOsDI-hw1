/*
 * =====================================================================================
 *
 *       Filename:  mem.c
 *
 *    Description:  Implementation file for memory, and string
 *    				functions. See mem.h for more details.
 *
 *        Version:  1.0
 *        Created:  02/07/2012 03:11:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Armando Diaz Tolentino (adt), adiazt2@uic.edu
 *        Company:  CompuGlobalHyperMegaNet, inc
 *
 * =====================================================================================
 */

#include "consoleout.h"
#include "mem.h"
#include <stdarg.h>

typedef enum bool { FALSE = 0, TRUE } bool ;

static int appendULong( char*, int, unsigned long,
		int, char* ) ;

const int MAXSTRLEN = 100 ;
const int MAXWRITE = 10 ;

/**
 * copy n bytes from src and into destination
 * @param dest location to copy to
 * @param src locationt to copy from
 * @param n number of bytes to copy
 * @return a pointer to destination
 */
void* memcpy( void* dest, const void* src, size_t n ) {

	ASSERT( (dest != NULL && src != NULL)) ;
	char* copyTo = (char*) dest ;
	char* copyFrom = (char*) src ;

	int i = 0 ;
	for( ; i < n ; i++ ) {
		*(copyTo + i ) = *(copyFrom + i ) ;
	}

	/* not sure if dest should be returned instead */
	return copyTo ;
}


/**
 * set a memory blocks bytes to a certain value
 * @param s the start of memory buffer
 * @param n the number of bytes to change
 * @param c the value written to each byte
 * @return a pointer to s
 */
void* memset( void* s, int c, size_t n ) {

	ASSERT( s != NULL ) ;
	/* cast to use the memory buffer s */
	char* memBuffer = (char*) s ;

	int i = 0 ;
	for (i = 0; i < n; ++i) {
		/* not sure if casting (char) is necessary */
		*(memBuffer + i ) = (char) c ;
	}

	return s ;
}

/**
 * compare two memory buffers
 * @param s1 the first buffer to compare
 * @param s2 the second buffer to compare
 * @param n the number of bytes to compare
 * @return a number < 0 if, s1 < s2, 0 if s1 == s2 or > 0 if s1 > s2
 */
int memcmp( const void* s1, const void* s2, size_t n ) {

	ASSERT( s1 != NULL && s2 != NULL ) ;
	char* buffer1 = (char*) s1 ;
	char* buffer2 = (char*) s2 ;

	int retVal = 0 ;		/* the return value of memcmp */
	int i = 0 ;
	while ( i < n && 0 == retVal ) {
		retVal = *(buffer1 + i ) - *(buffer2 + i ) ;
		i++ ;
	}

	return retVal ;
}

/**
 * concatenate two strings
 * @param dest the string to concatenate to
 * @param src the string concatenated to dest
 * @return a pointer to the dest string
 */
char* strcat( char* dest, const char* src ) {

	ASSERT( dest != NULL && src != NULL ) ;
	int catLocation = 0 ;
	int i = 0 ;

	/* find end of string dest */
	while( *(dest + catLocation) != '\0') {
		catLocation++ ;
	}

	/* append src to dest */
	while ( *(src+i) != '\0' ) {
		*(dest + catLocation + i) = *(src+i) ;
		i++ ;
	}
	/* add null terminator */
	*(dest + catLocation + i ) = '\0' ;

	return dest ;
}

/**
 * concatenate at most n chars to a string
 * @param dest the string to concatenate to
 * @param src the string concatenated to dest
 * @param n the max number of chars to concatenate
 * @return a pointer to the dest string
 */
char* strncat( char* dest, const char* src, size_t n ) {

	ASSERT( dest != NULL && src != NULL ) ;
	int catLocation = 0 ;
	int i = 0 ;

	/* find end of string dest */
	while( *(dest + catLocation) != '\0') {
		catLocation++ ;
	}

	/* append src to dest */
	while ( *(src+i) != '\0' && i < n ) {
		*(dest + catLocation + i) = *(src+i) ;
		i++ ;
	}
	/* add null terminator */
	*(dest + catLocation + i ) = '\0' ;

	return dest ;
}

/**
 * compare two strings
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @return return > 0, if s1 > s2, return < 0 if s1 < s2 otherwise return 0
 */
int strcmp( const char* s1, const char* s2) {

	ASSERT( s1 != NULL && s2 != NULL ) ;
	int retVal = 0 ;		/* the return value of memcmp */
	int i = 0 ;
	bool seenANull =  FALSE ;

	/* just add to original pointers ???? */
	while ( !seenANull && 0 == retVal ) {
		retVal = *(s1 + i ) - *(s2 + i ) ;
		if ( '\0' == *(s1 + i) || '\0' == *(s2 +i) ) {
			seenANull = TRUE ;
			retVal = 0 ; /* necessary b/c retVal might not be zero */
		}
		i++ ;
	}

	return retVal ;
}

/**
 * compare two strings up to a max number of characters
 * @param s1 first string to compare
 * @param s2 second string to compare
 * @param n max number of chars to compare
 * @return return > 0, if s1 > s2, return < 0 if s1 < s2 otherwise return 0
 */
int strncmp( const char* s1, const char* s2, size_t n ) {

	ASSERT( s1 != NULL && s2 != NULL ) ;
	int retVal = 0 ;		/* the return value of memcmp */
	int i = 0 ;
	bool seenANull =  FALSE ;

	while ( !seenANull && 0 == retVal && i < n ) {
		retVal = *(s1 + i ) - *(s2 + i ) ;
		if ( '\0' == *(s1 + i) || '\0' == *(s2 +i) ) {
			seenANull = TRUE ;
		}
		i++ ;
	}

	return retVal ;
}

/**
 * copy the contents of one string into another.
 * @param dest string to copy into
 * @param src string to copy from
 * @return a pointer to dest
 */
char* strcpy( char* dest, const char* src ) {

	ASSERT( dest != NULL && src != NULL ) ;
	int i = 0 ;
	/* assignment handled in loop condition */
	while( (*(dest+i) = *(src+i)) != '\0' ) {
		i++ ;
	}

	return dest ;
}

/**
 * copy at most n bytes from one string to another
 * @param dest string to copy into
 * @param src string to copy from
 * @param n max number of bytes to copy
 * @return a pointer to dest
 */
char* strncpy( char* dest, const char* src, size_t n ) {

	ASSERT( dest != NULL && src != NULL ) ;
	int i = 0 ;
	/* assignment handled in loop condition
	 * so it must occur after i < n is checked
	 */
	while( i < n && (*(dest+i) = *(src+i)) != '\0' ) {
		i++ ;
	}

	return dest ;
}

/* printing to stdout */
int printf( const char* format, ... ) {

	ASSERT( format != NULL ) ;
	va_list argList ;
	int argCount = 0 ;
	int i = 0 ;
	int buffBytesUsed = 0 ;
	/* argument variables */
	long signedArg ;
	unsigned long notSignedArg ;
	char* str ;
	/* stores string to be printed */
	char buffer[200] ;

	/* initialize buffer for safety reasons */
	memset( buffer, 0, 200 ) ;
	/* initialize the argList */
	va_start ( argList, format ) ;

	/* handle each of the arguments in the format string */

	while( '\0' != format[i] ) {
		if ( '%' == format[i] ) {
			/* format flag seen */
			switch (format[i+1]) {
			case 's':
				/* next arg is a string */
				str = va_arg( argList, char* ) ;
				strcat( buffer, str ) ;
				argCount++ ;
				buffBytesUsed += strlen(str) ;
				/* increment i++ to get past current arg */
				i+=2 ;
				break;
			case 'd':
				if ( 'l' == format[i+2] ) {
					signedArg = va_arg( argList, long ) ;
					i+=2 ;
				}
				else {
					signedArg = va_arg( argList, int ) ;
					i+=2 ;
				}
				buffBytesUsed +=
						appendInt( buffer + buffBytesUsed, MAXWRITE, signedArg, 10 , "") ;
				break ;
			case 'l' :
				signedArg = va_arg( argList, long ) ;
				buffBytesUsed += appendInt( buffer + buffBytesUsed, MAXWRITE, signedArg, 10 , "") ;
				break ;
			case 'x':
				/* what happens when a long is sent, but an int is read ? */
				if ( 'l' == format[i+2] ) {
					signedArg = va_arg( argList, long ) ;
					i+=3 ;
				}
				else {
					signedArg = va_arg( argList, int ) ;
					i+=2 ;
				}
				strcat( buffer, "0x" ) ;
				buffBytesUsed+=2 ;
				buffBytesUsed += appendInt( buffer + buffBytesUsed, MAXWRITE, signedArg, 16 , "ABCDEF") ;
				break;
			case 'u':
				if ( 'l' == format[i+2] ) {
					notSignedArg = va_arg( argList, unsigned long ) ;
					i+= 3 ;
				}
				else {
					notSignedArg = va_arg( argList, unsigned ) ;
					i+=2 ;
				}

				buffBytesUsed += appendULong( buffer + buffBytesUsed, MAXWRITE, notSignedArg, 10, "" ) ;
				break ;
			case '%' :
				strcat( buffer, "%" ) ;
				i += 2 ;
				buffBytesUsed++ ;
				break ;
			default:
				break;
			}
		} else {
			buffer[ buffBytesUsed ] = format[i] ;
			buffBytesUsed++ ;
			i++ ;
		}
	}

	/* ensure a complete write occurs */
	console_write( buffer, buffBytesUsed ) ;

	return argCount ;
}

int appendInt( char* concat, int maxWrite, long value,
		int base, char* extraSymbols ) {

	if ( 0 > value ) {
		concat[0] = '-' ;
		value*=-1 ;
		return (1 + appendULong( concat +1, maxWrite - 1,
				value, base, extraSymbols)) ;
	}
	else {
		return appendULong( concat, maxWrite,
				value, base, extraSymbols );
	}

}

/** for converting an integer to an ascii string & concatenating it */
int appendULong( char* concat, int maxWrite, unsigned long value,
		int base, char* extraSymbols) {

	if ( 0 >= maxWrite ) {
		return 0 ;
	}
	if ( 0 == value ) { 		/* only executed if initial value is 0 */
		concat[0] = '0' ;
		return 1 ;
	}

	int remainder = value % base ;
	int quotient = value / base ;
	int bytesUsed = 0 ;

	if ( quotient != 0 ) {
		bytesUsed += appendULong( concat , maxWrite - 1,
						quotient, base, extraSymbols ) ;
	}

	if ( remainder < 10 ) {
		concat[ bytesUsed ] = remainder + '0' ;
	} else {
		concat[ bytesUsed ] = extraSymbols [ remainder - 10 ] ;
	}

	return bytesUsed + 1;
}

/* should return a size_t type */
int strlen( char* str ) {
	int i = 0 ;
	while( '\0' != str[i] ) {
		i++ ;
	}

	return (i+1) ;
}

