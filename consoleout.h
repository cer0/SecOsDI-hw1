/*
 * =====================================================================================
 *
 *       Filename:  consoleout.h
 *
 *    Description:
 *
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

#ifndef CONSOLEOUT_H_
#define CONSOLEOUT_H_

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
#define EXIT()			\
		kill( getpid(), TERM) ;
typedef unsigned long long size_t ;

/**
 * write to standard output
 * @param buffer a memory area to be written
 * @param n number of bytes to write
 */
void console_write( void* buffer, size_t n ) {

	size_t written = 0 ;
	while( written < n ) {
		written += write( 1, buffer + written, n - written ) ;
	}
}
#endif /* CONSOLEOUT_H_ */

