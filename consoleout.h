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


typedef unsigned long long size_t ;

/**
 * write to standard output
 * @param buffer a memory area to be written
 * @param n number of bytes to write
 */
void console_write( void* buffer, size_t n ) {

	write( 1, buffer, n ) ;
}
#endif /* CONSOLEOUT_H_ */

