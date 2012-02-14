/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  A simple test file to verify that mem.c
 *    				works as expected.
 *
 *        Version:  1.0
 *        Created:  02/07/2012 03:12:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Armando Diaz Tolentino (adt), adiazt2@uic.edu
 *        Company:  CompuGlobalHyperMegaNet, inc
 *
 * =====================================================================================
 */

#include "mem.h"

void main(int argc, char **argv) {

//	char* cat = "cat" ;
//	char* dogGoesWoof ="dog\0goes\0woof" ;
//	char str[100] ;
//	memset( str, 0, 100 ) ;
//	strcat( str, cat ) ;
//	printf( "%s", str) ;
//	printf("\n") ;
//	strcpy( str, dogGoesWoof ) ;
//	printf( "%s", str) ;
//	printf("\n") ;
//	strcpy( str+1, str ) ;
//	memcpy( str, cat, 22 ) ;
//	printf( "%s", str) ;

//	char* ptr = 0 ;
//	*ptr = 'a' ;

//	char* name = "Ra's Al Ghul", *hero = "Batman" ;
//	int someNum = 19872, otherNum = 45 ;
//	long lNum = 998292 ;
//
//	/* more arguments than format specifiers */
//	printf( "%s\n", name, hero, someNum, otherNum, lNum ) ;
//	printf( "%d\n", someNum, hero, name, otherNum, lNum ) ;
//	printf( "%ld\n", lNum, hero) ;

//	char* hello = "Konnichiwa, minasan :)" ;
//	printf("%s\n%s\n%s\n" ) ;

//	char* iSay="Chunky Bacon ~===~ !!!!!!!" ;
//	printf( "%s\n", 2343432) ;


	/* test case for really large input */
	char buff[ 190 ] ;
	int i;
	for (i = 0; i < 190 - 1; i++) {
		buff[i] = 'A' + i/100 ;
	}
	buff[i] = '\0' ;
	printf( "%s\n\n%s\n\n", buff, buff ) ;

	return ;
}

/* for some reason there was a problem with "consoleout.h" being included in
 * mem.h. Instead only included in mem.c, and the mem.h file contains a
 * re-declaration of size_t type. Don't know why this wasn't a problem earlier on
 */

/* add invalid input stuff to printf()
 * create another macro, called exit to
 * exit cleanly when an error is encountered.
 */

/* define null in only one place */
/* figure out what buffer size is best */
