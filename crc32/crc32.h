/* Crc - 32 BIT ANSI X3.66 CRC checksum files */

#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned long DWORD;

DWORD crc32(BYTE *buf, size_t len, int use_secure);
