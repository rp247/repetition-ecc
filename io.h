#ifndef IO_H__
#define IO_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER 4096

/* read n bytes from a stream */
int read_bytes(int *fd, uint64_t n, char *buf);

/* write n bytes from a stream */
int write_bytes(int *fd, uint64_t n, char *buf);

/* repeat the byte n times */
int repeat_byte(char *inp, char *out, uint8_t n);


#endif /* end header IO_H__ */
