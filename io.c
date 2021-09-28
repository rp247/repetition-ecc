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
	uint64_t read_bytes = 0;

	while ((read_ret = read(infile, buf, BUFFER)) > 0){
		buf += read_ret;				// increment buffer index (read till BUFFER or max)
		read_bytes += read_ret;
	}

	return read_bytes;
}


/* write BUFFER (4096) bytes from a buffer into a outfile */
int wr2file(int oufile, uint8_t *buf) {

	int write_ret = 1;
	uint64_t write_bytes = 0;
	
	while ((write_ret = write(outfile, buf, BUFFER)) > 0 ) {
		buf += write_ret;
		write_bytes += write_ret;
	}

	return write_bytes;
}


/* read from an input buf and write the (repeated bits) to the output buf */
int wr2buf(uint8_t *inp_buf, uint8_t *out_buf, uint8_t times) {

	static uint64_t bit_index = 0;

	while (bit_index < BUFFER*BYTE - times) {

		uint8_t bit = get_bit(inp_buf, bit_index/BYTE);

		if (bit)	{ for (uint8_t i = 0; i < times; i++) { set_bit(out_buf, bit_index); } }
		else		{ for (uint8_t i = 0; i < times; i++) { clr_bit(out_buf, bit_index); } }

		bit_index += times;
	}

	// fix later
	if (bit_index <= BUFFER || bit_index <= BUFFER-times) {
		wr2file(outfile, out_buf);
		bit_index = 0;
	}

}

// void flush2file(int outfile, uint8_t *buf, 


