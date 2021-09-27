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
#define BUFFER 4096

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


/* read BUFFER (4096) bytes from an infile into a buffer */
int read_bytes(int infile, uint8_t *buf) {

	int read_ret = 1;

	while (read_ret = read(infile, buf, BUFFER) > 0){
		buf += read_ret;				// increment buffer index
	}

	return read_bytes;
}


int wr2buf(uint8_t *inp_buf, uint8_t *out_buf, uint8_t times) {
	static uint64_t bit_index = 0;

	while (bit_index < BUFFER*BYTE - times) {

		for (uint8_t i = 0; i < times; i++)
			if (get_bit(inp_buf, bit_index/BYTE)) set_bit(out_buf, bit_index);
			else clr_bit(out_buf, bit_index);
		}
		
		bit_index += times;
	}	

	if (bit_index == BUFFER) {
		wr2file(outfile, out_buf);
		bit_index = 0;
	}
}


int wr2file(int outfile, uint8_t *buf) {
	while (write(outfile, buf, BUFFER) > 0) {
	}
	return 0;
}

void flush_buf(int outfile) {
	return;
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

