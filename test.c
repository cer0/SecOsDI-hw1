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

const int MAXBUFF = 100 ;
void main(int argc, char **argv) {

	/* constants like this are located on the stack & cannot be changed */
	char* name = "Pikachu\n" ;
	char buff[100] = "I choose you, " ;

//	if ( argc < 2 )
//		return ;
//	int result ;
//	memset( buff, 65, MAXBUFF ) ;
//	memcpy( buff, name, 4 ) ;
//	strncat( buff, name, 1000 ) ;
//	result = strncmp( argv[1], argv[2], 5 ) ;
	strncpy( buff, name, 1 ) ;

	printf( "***%s %d", name, 32490 ) ;
}
