/*
 * MAIN IDEA:
 *  read n bytes from a stream 
 *   pack n bits into a byte 
 *   write/read from a buffer 
 *
 */


#include "io.h"
#include <stdio.h>
#include <stddef.h>

#define BYTE 8

static void set_bit(uint8_t *buf, uint16_t ind) {     
	buf[ind / BYTE] |= ((uint8_t) 1 << (ind % BYTE));
   	return;
} 

static void clr_bit(uint8_t *buf, uint16_t ind) {     
	buf[ind / BYTE] &= ~((uint8_t) 1 << (ind % BYTE));     
	return; 
} 

static uint8_t get_bit(uint8_t *buf, uint16_t ind) {     
	return (buf[ind / BYTE] & ((uint8_t) 1 << (ind % BYTE))) ? 1 : 0; 
}


/* repeat the individual bit n times */
int repeat_byte(char *inp, char *out, uint8_t n) {
	/*
	 * read a byte from a buffer
	 * go through each bit
	 * write the bit to the output buffer (track output buffer index/byte)
	 * write the buffer to output stream if full
	 * flush the written buffer
	 */
}

