/*
 *===================================================================
 *  3GPP AMR Wideband Floating-point Speech Codec
 *===================================================================
 */
#ifndef IF_H
#define IF_H

#include "typedef.h"

/*
 * definition of constants
 */
#define NUM_OF_SPMODES 9

/* number of parameters */
#define PRMNO_7k 18
#define PRMNO_9k 32
#define PRMNO_12k 36
#define PRMNO_14k 36
#define PRMNO_16k 36
#define PRMNO_18k 52
#define PRMNO_20k 52
#define PRMNO_23k 52
#define PRMNO_24k 56
#define PRMNO_SID 7
#define NB_PARM_MAX PRMNO_24k

/* number of bits */
#ifndef NBBITS_7k
#define NBBITS_7k 132
#define NBBITS_9k 177
#define NBBITS_12k 253
#define NBBITS_14k 285
#define NBBITS_16k 317
#define NBBITS_18k 365
#define NBBITS_20k 397
#define NBBITS_23k 461
#define NBBITS_24k 477
#define NBBITS_SID 35
#endif

/* number of total bits */
#define HEADER_SIZE 6   /* real size + 1 */
#define T_NBBITS_7k (NBBITS_7k + HEADER_SIZE)
#define T_NBBITS_9k (NBBITS_9k + HEADER_SIZE)
#define T_NBBITS_12k (NBBITS_12k + HEADER_SIZE)
#define T_NBBITS_14k (NBBITS_14k + HEADER_SIZE)
#define T_NBBITS_16k (NBBITS_16k + HEADER_SIZE)
#define T_NBBITS_18k (NBBITS_18k + HEADER_SIZE)
#define T_NBBITS_20k (NBBITS_20k + HEADER_SIZE)
#define T_NBBITS_23k (NBBITS_23k + HEADER_SIZE)
#define T_NBBITS_24k (NBBITS_24k + HEADER_SIZE)
#define T_NBBITS_SID (NBBITS_SID + HEADER_SIZE)

#define TX_SPEECH 0
#define TX_SID_FIRST 1
#define TX_SID_UPDATE 2
#define TX_NO_DATA 3

#define RX_SPEECH_GOOD              0
#define RX_SPEECH_PROBABLY_DEGRADED 1
#define RX_SPEECH_LOST              2
#define RX_SPEECH_BAD               3
#define RX_SID_FIRST                4
#define RX_SID_UPDATE               5
#define RX_SID_BAD                  6
#define RX_NO_DATA                  7

/* One encoded frame (bytes) */
/*
 * 6 bytes are used both for mode 9 and 10.
 * Mode 9 is used in encoder and mode 10 in IF2
 */
const UWord8 block_size[16]= {18, 24, 33, 37, 41, 47, 51, 59, 61, 6, 6, 0, 0, 0, 1, 1};
/*
 * tables
 */

const Word16 mode_7k[NBBITS_7k << 1] = {
   0, 0x1, 1, 0x8, 1, 0x4, 1, 0x2,
   8, 0x2, 11, 0x2, 14, 0x2, 17, 0x2,
   8, 0x1, 11, 0x1, 1, 0x1, 1, 0x10,
   6, 0x80, 6, 0x40, 6, 0x20, 6, 0x10,
   8, 0x10, 11, 0x10, 14, 0x10, 17, 0x10,
   8, 0x4, 11, 0x4, 14, 0x4, 17, 0x4,
   14, 0x1, 17, 0x1, 17, 0x8, 6, 0x8,
   6, 0x4, 11, 0x20, 17, 0x20, 1, 0x80,
   1, 0x20, 8, 0x20, 14, 0x20, 11, 0x8,
   14, 0x8, 8, 0x8, 1, 0x40, 9, 0x10,
   15, 0x10, 15, 0x8, 12, 0x10, 3, 0x10,
   3, 0x2, 3, 0x1, 9, 0x8, 12, 0x8,
   3, 0x20, 3, 0x8, 3, 0x4, 3, 0x40,
   2, 0x8, 12, 0x4, 6, 0x2, 12, 0x2,
   9, 0x4, 15, 0x4, 2, 0x4, 4, 0x40,
   4, 0x20, 4, 0x10, 4, 0x8, 4, 0x4,
   2, 0x2, 2, 0x1, 6, 0x1, 12, 0x1,
   9, 0x2, 15, 0x2, 2, 0x80, 2, 0x20,
   2, 0x40, 2, 0x10, 9, 0x1, 15, 0x1,
   4, 0x2, 4, 0x1, 5, 0x20, 5, 0x10,
   5, 0x4, 5, 0x8, 5, 0x2, 5, 0x1,
   7, 0x800, 7, 0x20, 10, 0x800, 10, 0x20,
   13, 0x800, 13, 0x20, 16, 0x800, 16, 0x20,
   7, 0x400, 10, 0x400, 13, 0x400, 16, 0x400,
   7, 0x10, 10, 0x10, 13, 0x10, 16, 0x10,
   7, 0x200, 10, 0x200, 13, 0x200, 16, 0x200,
   7, 0x8, 10, 0x8, 13, 0x8, 16, 0x8,
   7, 0x100, 10, 0x100, 13, 0x100, 16, 0x100,
   7, 0x4, 10, 0x4, 13, 0x4, 16, 0x4,
   7, 0x80, 10, 0x80, 13, 0x80, 16, 0x80,
   7, 0x2, 10, 0x2, 13, 0x2, 16, 0x2,
   7, 0x40, 10, 0x40, 13, 0x40, 16, 0x40,
   7, 0x1, 10, 0x1, 13, 0x1, 16, 0x1
};

const Word16 mode_9k[NBBITS_9k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x80, 8, 0x40,
   8, 0x20, 20, 0x80, 20, 0x40, 20, 0x20,
   13, 0x20, 19, 0x20, 25, 0x20, 31, 0x20,
   13, 0x1, 19, 0x1, 25, 0x1, 31, 0x1,
   13, 0x8, 19, 0x8, 25, 0x8, 31, 0x8,
   13, 0x4, 19, 0x4, 25, 0x4, 31, 0x4,
   13, 0x2, 19, 0x2, 25, 0x2, 31, 0x2,
   13, 0x10, 19, 0x10, 25, 0x10, 31, 0x10,
   8, 0x10, 20, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 14, 0x10, 20, 0x8, 26, 0x10,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 20, 0x4, 5, 0x20,
   14, 0x8, 26, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 14, 0x4, 26, 0x4, 8, 0x2,
   20, 0x2, 4, 0x2, 4, 0x4, 14, 0x2,
   26, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   20, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 14, 0x1, 26, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x10, 10, 0x10, 11, 0x10,
   12, 0x10, 15, 0x10, 16, 0x10, 17, 0x10,
   18, 0x10, 21, 0x10, 22, 0x10, 23, 0x10,
   24, 0x10, 27, 0x10, 28, 0x10, 29, 0x10,
   30, 0x10, 9, 0x8, 15, 0x8, 21, 0x8,
   27, 0x8, 10, 0x8, 16, 0x8, 22, 0x8,
   28, 0x8, 11, 0x8, 17, 0x8, 23, 0x8,
   29, 0x8, 12, 0x8, 18, 0x8, 24, 0x8,
   30, 0x8, 9, 0x4, 15, 0x4, 21, 0x4,
   27, 0x4, 10, 0x4, 16, 0x4, 22, 0x4,
   28, 0x4, 11, 0x4, 17, 0x4, 23, 0x4,
   29, 0x4, 12, 0x4, 18, 0x4, 24, 0x4,
   30, 0x4, 9, 0x2, 15, 0x2, 21, 0x2,
   27, 0x2, 10, 0x2, 16, 0x2, 22, 0x2,
   28, 0x2, 11, 0x2, 17, 0x2, 23, 0x2,
   29, 0x2, 12, 0x2, 18, 0x2, 24, 0x2,
   30, 0x2, 9, 0x1, 15, 0x1, 21, 0x1,
   27, 0x1, 10, 0x1, 16, 0x1, 22, 0x1,
   28, 0x1, 11, 0x1, 17, 0x1, 23, 0x1,
   29, 0x1, 12, 0x1, 18, 0x1, 24, 0x1,
   30, 0x1
};

const Word16 mode_12k[NBBITS_12k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 14, 0x40,
   21, 0x40, 28, 0x40, 35, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 22, 0x100,
   22, 0x80, 22, 0x40, 22, 0x20, 22, 0x10,
   14, 0x20, 21, 0x20, 28, 0x20, 35, 0x20,
   14, 0x1, 21, 0x1, 28, 0x1, 35, 0x1,
   14, 0x8, 21, 0x8, 28, 0x8, 35, 0x8,
   14, 0x4, 21, 0x4, 28, 0x4, 35, 0x4,
   15, 0x20, 29, 0x20, 14, 0x2, 21, 0x2,
   28, 0x2, 35, 0x2, 14, 0x10, 21, 0x10,
   28, 0x10, 35, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 15, 0x10, 29, 0x10, 22, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 22, 0x4, 5, 0x20,
   15, 0x8, 29, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 15, 0x4, 29, 0x4, 8, 0x2,
   22, 0x2, 4, 0x2, 4, 0x4, 15, 0x2,
   29, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   22, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 15, 0x1, 29, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 16, 0x1, 23, 0x1,
   30, 0x1, 10, 0x100, 11, 0x100, 12, 0x100,
   13, 0x100, 17, 0x100, 18, 0x100, 19, 0x100,
   20, 0x100, 24, 0x100, 25, 0x100, 26, 0x100,
   27, 0x100, 31, 0x100, 32, 0x100, 33, 0x100,
   34, 0x100, 10, 0x80, 17, 0x80, 24, 0x80,
   31, 0x80, 10, 0x8, 17, 0x8, 24, 0x8,
   31, 0x8, 11, 0x80, 18, 0x80, 25, 0x80,
   32, 0x80, 11, 0x8, 18, 0x8, 25, 0x8,
   32, 0x8, 12, 0x80, 19, 0x80, 26, 0x80,
   33, 0x80, 12, 0x8, 19, 0x8, 26, 0x8,
   33, 0x8, 13, 0x80, 20, 0x80, 27, 0x80,
   34, 0x80, 13, 0x8, 20, 0x8, 27, 0x8,
   34, 0x8, 10, 0x40, 17, 0x40, 24, 0x40,
   31, 0x40, 10, 0x4, 17, 0x4, 24, 0x4,
   31, 0x4, 11, 0x40, 18, 0x40, 25, 0x40,
   32, 0x40, 11, 0x4, 18, 0x4, 25, 0x4,
   32, 0x4, 12, 0x40, 19, 0x40, 26, 0x40,
   33, 0x40, 12, 0x4, 19, 0x4, 26, 0x4,
   33, 0x4, 13, 0x40, 20, 0x40, 27, 0x40,
   34, 0x40, 13, 0x4, 20, 0x4, 27, 0x4,
   34, 0x4, 10, 0x20, 17, 0x20, 24, 0x20,
   31, 0x20, 10, 0x2, 17, 0x2, 24, 0x2,
   31, 0x2, 11, 0x20, 18, 0x20, 25, 0x20,
   32, 0x20, 11, 0x2, 18, 0x2, 25, 0x2,
   32, 0x2, 12, 0x20, 19, 0x20, 26, 0x20,
   33, 0x20, 12, 0x2, 19, 0x2, 26, 0x2,
   33, 0x2, 13, 0x20, 20, 0x20, 27, 0x20,
   34, 0x20, 13, 0x2, 20, 0x2, 27, 0x2,
   34, 0x2, 10, 0x10, 17, 0x10, 24, 0x10,
   31, 0x10, 10, 0x1, 17, 0x1, 24, 0x1,
   31, 0x1, 11, 0x10, 18, 0x10, 25, 0x10,
   32, 0x10, 11, 0x1, 18, 0x1, 25, 0x1,
   32, 0x1, 12, 0x10, 19, 0x10, 26, 0x10,
   33, 0x10, 12, 0x1, 19, 0x1, 26, 0x1,
   33, 0x1, 13, 0x10, 20, 0x10, 27, 0x10,
   34, 0x10, 13, 0x1, 20, 0x1, 27, 0x1,
   34, 0x1
};

const Word16 mode_14k[NBBITS_14k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 14, 0x40,
   21, 0x40, 28, 0x40, 35, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 22, 0x100,
   22, 0x80, 22, 0x40, 22, 0x20, 22, 0x10,
   14, 0x20, 21, 0x20, 28, 0x20, 35, 0x20,
   14, 0x1, 21, 0x1, 28, 0x1, 35, 0x1,
   14, 0x8, 21, 0x8, 28, 0x8, 35, 0x8,
   14, 0x4, 21, 0x4, 28, 0x4, 35, 0x4,
   15, 0x20, 29, 0x20, 14, 0x2, 21, 0x2,
   28, 0x2, 35, 0x2, 14, 0x10, 21, 0x10,
   28, 0x10, 35, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 15, 0x10, 29, 0x10, 22, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 22, 0x4, 5, 0x20,
   15, 0x8, 29, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 15, 0x4, 29, 0x4, 8, 0x2,
   22, 0x2, 4, 0x2, 4, 0x4, 15, 0x2,
   29, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   22, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 15, 0x1, 29, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 16, 0x1, 23, 0x1,
   30, 0x1, 10, 0x80, 17, 0x80, 24, 0x80,
   31, 0x80, 11, 0x80, 18, 0x80, 25, 0x80,
   32, 0x80, 10, 0x1000, 17, 0x1000, 24, 0x1000,
   31, 0x1000, 10, 0x40, 17, 0x40, 24, 0x40,
   31, 0x40, 11, 0x1000, 18, 0x1000, 25, 0x1000,
   32, 0x1000, 11, 0x40, 18, 0x40, 25, 0x40,
   32, 0x40, 12, 0x100, 19, 0x100, 26, 0x100,
   33, 0x100, 13, 0x100, 20, 0x100, 27, 0x100,
   34, 0x100, 12, 0x80, 19, 0x80, 26, 0x80,
   33, 0x80, 13, 0x80, 20, 0x80, 27, 0x80,
   34, 0x80, 12, 0x40, 19, 0x40, 26, 0x40,
   33, 0x40, 13, 0x40, 20, 0x40, 27, 0x40,
   34, 0x40, 12, 0x20, 19, 0x20, 26, 0x20,
   33, 0x20, 13, 0x20, 20, 0x20, 27, 0x20,
   34, 0x20, 10, 0x20, 17, 0x20, 24, 0x20,
   31, 0x20, 11, 0x20, 18, 0x20, 25, 0x20,
   32, 0x20, 10, 0x10, 17, 0x10, 24, 0x10,
   31, 0x10, 11, 0x10, 18, 0x10, 25, 0x10,
   32, 0x10, 12, 0x10, 19, 0x10, 26, 0x10,
   33, 0x10, 13, 0x10, 20, 0x10, 27, 0x10,
   34, 0x10, 10, 0x800, 17, 0x800, 24, 0x800,
   31, 0x800, 10, 0x8, 17, 0x8, 24, 0x8,
   31, 0x8, 11, 0x800, 18, 0x800, 25, 0x800,
   32, 0x800, 11, 0x8, 18, 0x8, 25, 0x8,
   32, 0x8, 12, 0x8, 19, 0x8, 26, 0x8,
   33, 0x8, 13, 0x8, 20, 0x8, 27, 0x8,
   34, 0x8, 10, 0x400, 17, 0x400, 24, 0x400,
   31, 0x400, 10, 0x4, 17, 0x4, 24, 0x4,
   31, 0x4, 11, 0x400, 18, 0x400, 25, 0x400,
   32, 0x400, 11, 0x4, 18, 0x4, 25, 0x4,
   32, 0x4, 12, 0x4, 19, 0x4, 26, 0x4,
   33, 0x4, 13, 0x4, 20, 0x4, 27, 0x4,
   34, 0x4, 10, 0x200, 17, 0x200, 24, 0x200,
   31, 0x200, 10, 0x2, 17, 0x2, 24, 0x2,
   31, 0x2, 11, 0x200, 18, 0x200, 25, 0x200,
   32, 0x200, 11, 0x2, 18, 0x2, 25, 0x2,
   32, 0x2, 12, 0x2, 19, 0x2, 26, 0x2,
   33, 0x2, 13, 0x2, 20, 0x2, 27, 0x2,
   34, 0x2, 10, 0x100, 17, 0x100, 24, 0x100,
   31, 0x100, 10, 0x1, 17, 0x1, 24, 0x1,
   31, 0x1, 11, 0x100, 18, 0x100, 25, 0x100,
   32, 0x100, 11, 0x1, 18, 0x1, 25, 0x1,
   32, 0x1, 12, 0x1, 19, 0x1, 26, 0x1,
   33, 0x1, 13, 0x1, 20, 0x1, 27, 0x1,
   34, 0x1
};

const Word16 mode_16k[NBBITS_16k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 14, 0x40,
   21, 0x40, 28, 0x40, 35, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 22, 0x100,
   22, 0x80, 22, 0x40, 22, 0x20, 22, 0x10,
   14, 0x20, 21, 0x20, 28, 0x20, 35, 0x20,
   14, 0x1, 21, 0x1, 28, 0x1, 35, 0x1,
   14, 0x8, 21, 0x8, 28, 0x8, 35, 0x8,
   14, 0x4, 21, 0x4, 28, 0x4, 35, 0x4,
   15, 0x20, 29, 0x20, 14, 0x2, 21, 0x2,
   28, 0x2, 35, 0x2, 14, 0x10, 21, 0x10,
   28, 0x10, 35, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 15, 0x10, 29, 0x10, 22, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 22, 0x4, 5, 0x20,
   15, 0x8, 29, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 15, 0x4, 29, 0x4, 8, 0x2,
   22, 0x2, 4, 0x2, 4, 0x4, 15, 0x2,
   29, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   22, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 15, 0x1, 29, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 16, 0x1, 23, 0x1,
   30, 0x1, 10, 0x40, 17, 0x40, 24, 0x40,
   31, 0x40, 11, 0x40, 18, 0x40, 25, 0x40,
   32, 0x40, 12, 0x40, 19, 0x40, 26, 0x40,
   33, 0x40, 13, 0x40, 20, 0x40, 27, 0x40,
   34, 0x40, 10, 0x1000, 17, 0x1000, 24, 0x1000,
   31, 0x1000, 11, 0x1000, 18, 0x1000, 25, 0x1000,
   32, 0x1000, 12, 0x1000, 19, 0x1000, 26, 0x1000,
   33, 0x1000, 13, 0x1000, 20, 0x1000, 27, 0x1000,
   34, 0x1000, 10, 0x80, 17, 0x80, 24, 0x80,
   31, 0x80, 11, 0x80, 18, 0x80, 25, 0x80,
   32, 0x80, 12, 0x80, 19, 0x80, 26, 0x80,
   33, 0x80, 13, 0x80, 20, 0x80, 27, 0x80,
   34, 0x80, 10, 0x800, 17, 0x800, 24, 0x800,
   31, 0x800, 11, 0x800, 18, 0x800, 25, 0x800,
   32, 0x800, 12, 0x800, 19, 0x800, 26, 0x800,
   33, 0x800, 13, 0x800, 20, 0x800, 27, 0x800,
   34, 0x800, 10, 0x400, 17, 0x400, 24, 0x400,
   31, 0x400, 10, 0x20, 17, 0x20, 24, 0x20,
   31, 0x20, 10, 0x4, 17, 0x4, 24, 0x4,
   31, 0x4, 11, 0x400, 18, 0x400, 25, 0x400,
   32, 0x400, 11, 0x20, 18, 0x20, 25, 0x20,
   32, 0x20, 11, 0x4, 18, 0x4, 25, 0x4,
   32, 0x4, 12, 0x400, 19, 0x400, 26, 0x400,
   33, 0x400, 12, 0x20, 19, 0x20, 26, 0x20,
   33, 0x20, 12, 0x4, 19, 0x4, 26, 0x4,
   33, 0x4, 13, 0x400, 20, 0x400, 27, 0x400,
   34, 0x400, 13, 0x20, 20, 0x20, 27, 0x20,
   34, 0x20, 13, 0x4, 20, 0x4, 27, 0x4,
   34, 0x4, 10, 0x200, 17, 0x200, 24, 0x200,
   31, 0x200, 10, 0x10, 17, 0x10, 24, 0x10,
   31, 0x10, 10, 0x2, 17, 0x2, 24, 0x2,
   31, 0x2, 11, 0x200, 18, 0x200, 25, 0x200,
   32, 0x200, 11, 0x10, 18, 0x10, 25, 0x10,
   32, 0x10, 11, 0x2, 18, 0x2, 25, 0x2,
   32, 0x2, 12, 0x200, 19, 0x200, 26, 0x200,
   33, 0x200, 12, 0x10, 19, 0x10, 26, 0x10,
   33, 0x10, 12, 0x2, 19, 0x2, 26, 0x2,
   33, 0x2, 13, 0x200, 20, 0x200, 27, 0x200,
   34, 0x200, 13, 0x10, 20, 0x10, 27, 0x10,
   34, 0x10, 13, 0x2, 20, 0x2, 27, 0x2,
   34, 0x2, 10, 0x100, 17, 0x100, 24, 0x100,
   31, 0x100, 10, 0x8, 17, 0x8, 24, 0x8,
   31, 0x8, 10, 0x1, 17, 0x1, 24, 0x1,
   31, 0x1, 11, 0x100, 18, 0x100, 25, 0x100,
   32, 0x100, 11, 0x8, 18, 0x8, 25, 0x8,
   32, 0x8, 11, 0x1, 18, 0x1, 25, 0x1,
   32, 0x1, 12, 0x100, 19, 0x100, 26, 0x100,
   33, 0x100, 12, 0x8, 19, 0x8, 26, 0x8,
   33, 0x8, 12, 0x1, 19, 0x1, 26, 0x1,
   33, 0x1, 13, 0x100, 20, 0x100, 27, 0x100,
   34, 0x100, 13, 0x8, 20, 0x8, 27, 0x8,
   34, 0x8, 13, 0x1, 20, 0x1, 27, 0x1,
   34, 0x1
};

const Word16 mode_18k[NBBITS_18k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 18, 0x40,
   29, 0x40, 40, 0x40, 51, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 30, 0x100,
   30, 0x80, 30, 0x40, 30, 0x20, 30, 0x10,
   18, 0x20, 29, 0x20, 40, 0x20, 51, 0x20,
   18, 0x1, 29, 0x1, 40, 0x1, 51, 0x1,
   18, 0x8, 29, 0x8, 40, 0x8, 51, 0x8,
   18, 0x4, 29, 0x4, 40, 0x4, 51, 0x4,
   19, 0x20, 41, 0x20, 18, 0x2, 29, 0x2,
   40, 0x2, 51, 0x2, 18, 0x10, 29, 0x10,
   40, 0x10, 51, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 19, 0x10, 41, 0x10, 30, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 30, 0x4, 5, 0x20,
   19, 0x8, 41, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 19, 0x4, 41, 0x4, 8, 0x2,
   30, 0x2, 4, 0x2, 4, 0x4, 19, 0x2,
   41, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   30, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 19, 0x1, 41, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 20, 0x1, 31, 0x1,
   42, 0x1, 28, 0x1, 45, 0x1, 21, 0x1,
   17, 0x1, 22, 0x1, 11, 0x1, 39, 0x1,
   10, 0x1, 12, 0x1, 50, 0x1, 23, 0x2,
   23, 0x1, 43, 0x1, 25, 0x1, 10, 0x2,
   33, 0x1, 44, 0x1, 13, 0x2, 32, 0x1,
   22, 0x2, 26, 0x1, 46, 0x2, 35, 0x2,
   13, 0x1, 16, 0x1, 12, 0x2, 14, 0x1,
   43, 0x2, 15, 0x1, 24, 0x1, 24, 0x2,
   21, 0x2, 34, 0x1, 44, 0x2, 46, 0x1,
   49, 0x1, 11, 0x2, 45, 0x2, 27, 0x1,
   48, 0x1, 47, 0x1, 34, 0x2, 32, 0x2,
   38, 0x1, 37, 0x1, 33, 0x2, 36, 0x1,
   50, 0x20, 35, 0x1, 26, 0x2000, 15, 0x40,
   27, 0x2000, 15, 0x20, 26, 0x40, 50, 0x40,
   17, 0x200, 47, 0x2000, 14, 0x2000, 27, 0x40,
   17, 0x20, 48, 0x40, 14, 0x40, 28, 0x40,
   16, 0x20, 27, 0x20, 16, 0x2000, 14, 0x20,
   28, 0x20, 25, 0x20, 49, 0x40, 47, 0x40,
   25, 0x2000, 39, 0x20, 14, 0x200, 48, 0x20,
   26, 0x20, 25, 0x40, 16, 0x200, 49, 0x20,
   17, 0x400, 47, 0x20, 49, 0x2000, 39, 0x40,
   14, 0x400, 17, 0x2000, 27, 0x200, 37, 0x40,
   17, 0x40, 15, 0x2000, 17, 0x80, 28, 0x200,
   37, 0x20, 38, 0x40, 27, 0x400, 14, 0x80,
   28, 0x2000, 16, 0x400, 50, 0x2000, 16, 0x40,
   48, 0x80, 15, 0x200, 49, 0x200, 48, 0x2000,
   49, 0x400, 38, 0x2000, 26, 0x200, 50, 0x200,
   25, 0x200, 15, 0x400, 39, 0x400, 36, 0x20,
   38, 0x20, 47, 0x80, 50, 0x10, 50, 0x400,
   26, 0x80, 36, 0x40, 47, 0x200, 48, 0x200,
   28, 0x400, 39, 0x200, 25, 0x400, 27, 0x80,
   39, 0x2000, 50, 0x80, 38, 0x200, 15, 0x80,
   25, 0x80, 17, 0x10, 28, 0x80, 26, 0x400,
   37, 0x2000, 38, 0x80, 49, 0x80, 47, 0x400,
   38, 0x400, 15, 0x10, 36, 0x2000, 16, 0x80,
   49, 0x10, 36, 0x80, 36, 0x200, 36, 0x400,
   39, 0x80, 37, 0x200, 37, 0x400, 48, 0x400,
   36, 0x10, 47, 0x10, 16, 0x10, 14, 0x10,
   27, 0x10, 39, 0x10, 14, 0x1000, 28, 0x10,
   25, 0x10, 48, 0x10, 27, 0x1000, 37, 0x10,
   37, 0x80, 38, 0x10, 17, 0x8, 26, 0x1000,
   26, 0x10, 50, 0x8, 14, 0x8, 25, 0x1000,
   17, 0x1000, 47, 0x8, 16, 0x1000, 28, 0x1000,
   47, 0x1000, 15, 0x1000, 36, 0x8, 15, 0x8,
   28, 0x8, 17, 0x100, 49, 0x8, 27, 0x8,
   50, 0x1000, 48, 0x1000, 48, 0x8, 39, 0x8,
   37, 0x1000, 26, 0x8, 17, 0x4, 47, 0x4,
   14, 0x100, 50, 0x4, 48, 0x4, 38, 0x1000,
   28, 0x100, 27, 0x100, 39, 0x100, 16, 0x4,
   16, 0x100, 25, 0x8, 16, 0x8, 15, 0x4,
   14, 0x4, 39, 0x1000, 39, 0x4, 37, 0x8,
   36, 0x1000, 38, 0x8, 27, 0x4, 15, 0x100,
   25, 0x4, 36, 0x4, 49, 0x100, 26, 0x4,
   49, 0x1000, 28, 0x4, 49, 0x4, 37, 0x4,
   26, 0x100, 47, 0x100, 25, 0x100, 50, 0x100,
   38, 0x4, 48, 0x100, 38, 0x100, 37, 0x100,
   36, 0x100, 50, 0x2, 26, 0x800, 17, 0x2,
   14, 0x800, 28, 0x800, 27, 0x800, 25, 0x800,
   37, 0x800, 14, 0x2, 47, 0x800, 49, 0x800,
   47, 0x2, 49, 0x2, 17, 0x800, 38, 0x800,
   15, 0x800, 39, 0x2, 16, 0x2, 15, 0x2,
   50, 0x800, 48, 0x800, 27, 0x2, 37, 0x2,
   28, 0x2, 48, 0x2, 16, 0x800, 25, 0x2,
   26, 0x2, 39, 0x800, 36, 0x800, 36, 0x2,
   38, 0x2
};

const Word16 mode_20k[NBBITS_20k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 18, 0x40,
   29, 0x40, 40, 0x40, 51, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 30, 0x100,
   30, 0x80, 30, 0x40, 30, 0x20, 30, 0x10,
   18, 0x20, 29, 0x20, 40, 0x20, 51, 0x20,
   18, 0x1, 29, 0x1, 40, 0x1, 51, 0x1,
   18, 0x8, 29, 0x8, 40, 0x8, 51, 0x8,
   18, 0x4, 29, 0x4, 40, 0x4, 51, 0x4,
   19, 0x20, 41, 0x20, 18, 0x2, 29, 0x2,
   40, 0x2, 51, 0x2, 18, 0x10, 29, 0x10,
   40, 0x10, 51, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 19, 0x10, 41, 0x10, 30, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 30, 0x4, 5, 0x20,
   19, 0x8, 41, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 19, 0x4, 41, 0x4, 8, 0x2,
   30, 0x2, 4, 0x2, 4, 0x4, 19, 0x2,
   41, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   30, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 19, 0x1, 41, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 20, 0x1, 31, 0x1,
   42, 0x1, 10, 0x8, 11, 0x8, 15, 0x100,
   46, 0x2, 14, 0x100, 43, 0x8, 21, 0x8,
   48, 0x100, 22, 0x8, 44, 0x8, 24, 0x2,
   45, 0x2, 26, 0x100, 23, 0x2, 35, 0x2,
   12, 0x2, 25, 0x100, 36, 0x100, 22, 0x200,
   47, 0x100, 10, 0x200, 33, 0x8, 32, 0x8,
   13, 0x2, 34, 0x2, 24, 0x1, 11, 0x200,
   13, 0x1, 28, 0x2000, 16, 0x2000, 37, 0x100,
   21, 0x200, 23, 0x1, 46, 0x1, 35, 0x1,
   45, 0x1, 27, 0x2000, 50, 0x2000, 43, 0x200,
   12, 0x1, 44, 0x200, 49, 0x2000, 17, 0x2000,
   32, 0x200, 33, 0x200, 34, 0x1, 39, 0x2000,
   38, 0x2000, 10, 0x10, 10, 0x100, 22, 0x10,
   11, 0x100, 15, 0x80, 26, 0x80, 43, 0x100,
   21, 0x10, 25, 0x80, 22, 0x100, 11, 0x10,
   50, 0x10, 44, 0x100, 44, 0x10, 47, 0x80,
   16, 0x1000, 14, 0x80, 21, 0x100, 32, 0x100,
   43, 0x10, 17, 0x10, 33, 0x100, 27, 0x100,
   48, 0x80, 32, 0x10, 10, 0x4, 33, 0x10,
   28, 0x1000, 28, 0x20, 21, 0x4, 17, 0x1000,
   44, 0x4, 37, 0x80, 32, 0x4, 39, 0x10,
   27, 0x1000, 27, 0x10, 39, 0x20, 15, 0x40,
   27, 0x20, 36, 0x80, 17, 0x20, 49, 0x1000,
   50, 0x20, 16, 0x20, 43, 0x4, 49, 0x10,
   25, 0x40, 49, 0x20, 14, 0x40, 16, 0x10,
   39, 0x100, 26, 0x40, 11, 0x4, 28, 0x10,
   27, 0x200, 16, 0x100, 39, 0x1000, 28, 0x200,
   49, 0x100, 50, 0x100, 50, 0x1000, 28, 0x100,
   48, 0x40, 17, 0x40, 17, 0x200, 17, 0x100,
   50, 0x40, 22, 0x4, 16, 0x200, 16, 0x40,
   38, 0x1000, 50, 0x200, 39, 0x200, 38, 0x20,
   38, 0x10, 47, 0x40, 28, 0x40, 37, 0x40,
   33, 0x4, 49, 0x200, 50, 0x8, 39, 0x8,
   39, 0x40, 36, 0x40, 17, 0x8, 49, 0x40,
   27, 0x8, 15, 0x8, 27, 0x40, 38, 0x8,
   28, 0x8, 38, 0x100, 38, 0x200, 26, 0x8,
   49, 0x8, 14, 0x8, 22, 0x80, 38, 0x40,
   10, 0x80, 47, 0x8, 43, 0x1, 26, 0x4,
   11, 0x1, 16, 0x8, 44, 0x80, 28, 0x800,
   47, 0x4, 11, 0x80, 15, 0x4, 21, 0x1,
   21, 0x80, 27, 0x800, 10, 0x1, 43, 0x80,
   44, 0x1, 25, 0x8, 48, 0x8, 33, 0x1,
   27, 0x4, 25, 0x4, 36, 0x4, 36, 0x8,
   17, 0x4, 32, 0x1, 27, 0x80, 14, 0x4,
   50, 0x2, 17, 0x800, 15, 0x20, 50, 0x4,
   16, 0x4, 48, 0x4, 38, 0x4, 33, 0x80,
   16, 0x800, 37, 0x8, 39, 0x4, 25, 0x20,
   22, 0x1, 32, 0x80, 37, 0x4, 17, 0x2,
   49, 0x4, 26, 0x20, 39, 0x800, 14, 0x20,
   50, 0x800, 39, 0x2, 17, 0x80, 16, 0x80,
   49, 0x800, 47, 0x20, 48, 0x20, 28, 0x4,
   38, 0x800, 28, 0x2, 10, 0x2, 50, 0x80,
   38, 0x2, 28, 0x80, 16, 0x2, 25, 0x2,
   15, 0x2, 39, 0x80, 49, 0x2, 49, 0x80,
   27, 0x2, 36, 0x20, 26, 0x2, 44, 0x2,
   44, 0x40, 22, 0x2, 37, 0x20, 36, 0x2,
   33, 0x2, 32, 0x2, 11, 0x2, 47, 0x2,
   21, 0x2, 10, 0x40, 14, 0x2, 43, 0x40,
   22, 0x40, 37, 0x2, 48, 0x2, 43, 0x2,
   11, 0x40, 38, 0x80, 25, 0x200, 21, 0x40,
   48, 0x200, 14, 0x200, 15, 0x200, 50, 0x1,
   37, 0x200, 33, 0x40, 26, 0x200, 32, 0x40,
   27, 0x400, 36, 0x200, 28, 0x400, 47, 0x200,
   17, 0x1, 17, 0x400, 39, 0x1, 16, 0x400,
   50, 0x400, 26, 0x10, 16, 0x1, 49, 0x1,
   27, 0x1, 15, 0x10, 39, 0x400, 25, 0x10,
   28, 0x1, 49, 0x400, 38, 0x400, 14, 0x10,
   38, 0x1, 47, 0x1, 47, 0x10, 48, 0x10,
   36, 0x10, 26, 0x1, 25, 0x1, 37, 0x10,
   14, 0x1, 15, 0x1, 21, 0x20, 43, 0x20,
   37, 0x1, 48, 0x1, 11, 0x20, 44, 0x20,
   10, 0x20, 36, 0x1, 22, 0x20, 33, 0x20,
   32, 0x20
};

const Word16 mode_23k[NBBITS_23k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 18, 0x40,
   29, 0x40, 40, 0x40, 51, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 30, 0x100,
   30, 0x80, 30, 0x40, 30, 0x20, 30, 0x10,
   18, 0x20, 29, 0x20, 40, 0x20, 51, 0x20,
   18, 0x1, 29, 0x1, 40, 0x1, 51, 0x1,
   18, 0x8, 29, 0x8, 40, 0x8, 51, 0x8,
   18, 0x4, 29, 0x4, 40, 0x4, 51, 0x4,
   19, 0x20, 41, 0x20, 18, 0x2, 29, 0x2,
   40, 0x2, 51, 0x2, 18, 0x10, 29, 0x10,
   40, 0x10, 51, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 19, 0x10, 41, 0x10, 30, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 30, 0x4, 5, 0x20,
   19, 0x8, 41, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 19, 0x4, 41, 0x4, 8, 0x2,
   30, 0x2, 4, 0x2, 4, 0x4, 19, 0x2,
   41, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   30, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 19, 0x1, 41, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 20, 0x1, 31, 0x1,
   42, 0x1, 23, 0x400, 24, 0x400, 22, 0x400,
   12, 0x400, 10, 0x400, 46, 0x400, 13, 0x400,
   21, 0x400, 35, 0x400, 44, 0x400, 43, 0x400,
   33, 0x400, 11, 0x400, 23, 0x100, 45, 0x400,
   34, 0x400, 24, 0x100, 35, 0x100, 13, 0x100,
   11, 0x100, 23, 0x200, 46, 0x100, 22, 0x100,
   10, 0x100, 13, 0x200, 10, 0x200, 46, 0x200,
   43, 0x100, 21, 0x100, 12, 0x100, 21, 0x200,
   32, 0x400, 22, 0x200, 12, 0x200, 45, 0x200,
   45, 0x100, 44, 0x200, 44, 0x100, 24, 0x200,
   35, 0x200, 11, 0x200, 32, 0x100, 32, 0x200,
   43, 0x200, 33, 0x100, 34, 0x100, 33, 0x200,
   34, 0x200, 23, 0x80, 10, 0x80, 24, 0x80,
   12, 0x80, 13, 0x80, 11, 0x80, 43, 0x80,
   46, 0x80, 22, 0x80, 21, 0x80, 50, 0x200,
   35, 0x80, 45, 0x80, 13, 0x4, 11, 0x4,
   33, 0x80, 10, 0x40, 32, 0x80, 43, 0x4,
   17, 0x200, 47, 0x200, 21, 0x4, 14, 0x200,
   44, 0x80, 24, 0x4, 12, 0x4, 22, 0x4,
   10, 0x4, 13, 0x40, 25, 0x200, 16, 0x200,
   11, 0x40, 39, 0x200, 23, 0x4, 35, 0x4,
   44, 0x40, 45, 0x4, 49, 0x200, 35, 0x40,
   27, 0x200, 46, 0x4, 34, 0x80, 28, 0x200,
   15, 0x200, 26, 0x200, 23, 0x40, 16, 0x20,
   36, 0x200, 46, 0x40, 15, 0x40, 37, 0x200,
   24, 0x40, 38, 0x200, 43, 0x40, 48, 0x200,
   22, 0x40, 10, 0x8, 45, 0x40, 12, 0x40,
   48, 0x40, 26, 0x20, 17, 0x400, 23, 0x8,
   49, 0x400, 15, 0x400, 48, 0x10, 17, 0x20,
   33, 0x40, 21, 0x40, 49, 0x40, 25, 0x20,
   50, 0x40, 26, 0x40, 28, 0x400, 27, 0x40,
   13, 0x8, 34, 0x4, 44, 0x4, 27, 0x20,
   21, 0x8, 32, 0x40, 22, 0x8, 50, 0x400,
   27, 0x400, 48, 0x20, 14, 0x400, 32, 0x4,
   17, 0x40, 16, 0x40, 34, 0x40, 15, 0x20,
   39, 0x10, 24, 0x8, 47, 0x40, 13, 0x20,
   17, 0x10, 28, 0x40, 47, 0x400, 45, 0x8,
   25, 0x10, 16, 0x10, 33, 0x4, 39, 0x20,
   14, 0x40, 28, 0x20, 49, 0x20, 12, 0x8,
   36, 0x400, 50, 0x20, 25, 0x400, 39, 0x40,
   23, 0x20, 14, 0x10, 26, 0x10, 47, 0x20,
   38, 0x40, 37, 0x400, 14, 0x20, 36, 0x20,
   15, 0x10, 16, 0x400, 11, 0x20, 25, 0x40,
   48, 0x400, 26, 0x400, 44, 0x8, 43, 0x8,
   49, 0x10, 10, 0x20, 43, 0x20, 39, 0x400,
   11, 0x8, 50, 0x10, 21, 0x2, 37, 0x40,
   21, 0x20, 28, 0x10, 47, 0x10, 37, 0x20,
   35, 0x8, 24, 0x20, 38, 0x20, 46, 0x20,
   32, 0x8, 10, 0x10, 23, 0x1, 37, 0x10,
   13, 0x10, 21, 0x1, 27, 0x10, 33, 0x20,
   36, 0x40, 23, 0x10, 46, 0x8, 12, 0x20,
   24, 0x2, 13, 0x1, 10, 0x1, 44, 0x20,
   22, 0x20, 38, 0x10, 24, 0x1, 38, 0x400,
   32, 0x20, 45, 0x20, 43, 0x1, 44, 0x10,
   34, 0x8, 35, 0x1, 46, 0x1, 22, 0x2,
   33, 0x1, 36, 0x10, 35, 0x20, 43, 0x10,
   45, 0x1, 23, 0x2, 22, 0x1, 12, 0x1,
   13, 0x2, 14, 0x100, 27, 0x8, 11, 0x1,
   12, 0x2, 11, 0x2, 17, 0x100, 44, 0x1,
   21, 0x10, 24, 0x10, 45, 0x10, 16, 0x100,
   22, 0x10, 48, 0x8, 11, 0x10, 43, 0x2,
   28, 0x100, 27, 0x100, 10, 0x2, 32, 0x2,
   33, 0x8, 17, 0x8, 35, 0x2, 47, 0x100,
   15, 0x100, 12, 0x10, 16, 0x8, 39, 0x8,
   15, 0x8, 34, 0x20, 34, 0x1, 44, 0x2,
   27, 0x4, 45, 0x2, 35, 0x10, 46, 0x10,
   33, 0x2, 50, 0x100, 48, 0x100, 26, 0x8,
   25, 0x8, 25, 0x100, 50, 0x8, 14, 0x8,
   32, 0x1, 49, 0x100, 26, 0x100, 39, 0x100,
   38, 0x8, 17, 0x4, 28, 0x8, 37, 0x100,
   46, 0x2, 50, 0x4, 36, 0x100, 34, 0x10,
   15, 0x4, 14, 0x4, 33, 0x10, 49, 0x8,
   32, 0x10, 48, 0x4, 38, 0x100, 34, 0x2,
   47, 0x4, 25, 0x4, 36, 0x8, 26, 0x4,
   37, 0x8, 16, 0x4, 48, 0x2, 28, 0x4,
   37, 0x4, 39, 0x4, 47, 0x8, 36, 0x4,
   17, 0x2, 38, 0x4, 49, 0x4, 27, 0x2,
   14, 0x2, 25, 0x2, 50, 0x2, 28, 0x2,
   15, 0x2, 47, 0x2, 39, 0x2, 26, 0x2,
   16, 0x2, 49, 0x2, 37, 0x2, 47, 0x80,
   36, 0x2, 38, 0x2, 16, 0x80, 14, 0x80,
   17, 0x80, 50, 0x80, 39, 0x80, 28, 0x80,
   49, 0x80, 15, 0x80, 38, 0x80, 25, 0x80,
   37, 0x80, 26, 0x80, 27, 0x80, 48, 0x80,
   50, 0x1, 36, 0x80, 39, 0x1, 14, 0x1,
   49, 0x1, 26, 0x1, 25, 0x1, 15, 0x1,
   48, 0x1, 38, 0x1, 27, 0x1, 28, 0x1,
   16, 0x1, 17, 0x1, 47, 0x1, 37, 0x1,
   36, 0x1
};

const Word16 mode_24k[NBBITS_24k << 1] = {
   0, 0x1, 1, 0x10, 1, 0x4, 18, 0x40,
   30, 0x40, 42, 0x40, 54, 0x40, 1, 0x2,
   1, 0x8, 1, 0x20, 8, 0x100, 8, 0x80,
   8, 0x40, 8, 0x20, 8, 0x10, 32, 0x100,
   32, 0x80, 32, 0x40, 32, 0x20, 32, 0x10,
   18, 0x20, 30, 0x20, 42, 0x20, 54, 0x20,
   18, 0x1, 30, 0x1, 42, 0x1, 54, 0x1,
   18, 0x8, 30, 0x8, 42, 0x8, 54, 0x8,
   18, 0x4, 30, 0x4, 42, 0x4, 54, 0x4,
   20, 0x20, 44, 0x20, 18, 0x2, 30, 0x2,
   42, 0x2, 54, 0x2, 18, 0x10, 30, 0x10,
   42, 0x10, 54, 0x10, 8, 0x8, 1, 0x40,
   1, 0x80, 20, 0x10, 44, 0x10, 32, 0x8,
   3, 0x8, 3, 0x2, 2, 0x10, 3, 0x20,
   3, 0x10, 3, 0x4, 2, 0x1, 4, 0x10,
   2, 0x8, 2, 0x40, 2, 0x4, 4, 0x20,
   4, 0x40, 3, 0x1, 4, 0x8, 1, 0x1,
   2, 0x2, 8, 0x4, 32, 0x4, 5, 0x20,
   19, 0x8, 19, 0x4, 19, 0x2, 19, 0x1,
   31, 0x8, 31, 0x4, 31, 0x2, 31, 0x1,
   43, 0x8, 43, 0x4, 43, 0x2, 43, 0x1,
   55, 0x8, 55, 0x4, 55, 0x2, 55, 0x1,
   20, 0x8, 44, 0x8, 2, 0x80, 5, 0x8,
   2, 0x20, 20, 0x4, 44, 0x4, 8, 0x2,
   32, 0x2, 4, 0x2, 4, 0x4, 20, 0x2,
   44, 0x2, 5, 0x4, 5, 0x2, 4, 0x1,
   7, 0x1, 5, 0x10, 5, 0x40, 8, 0x1,
   32, 0x1, 6, 0x10, 5, 0x1, 6, 0x4,
   6, 0x8, 6, 0x2, 20, 0x1, 44, 0x1,
   6, 0x1, 7, 0x10, 7, 0x8, 7, 0x4,
   7, 0x2, 9, 0x1, 21, 0x1, 33, 0x1,
   45, 0x1, 24, 0x400, 25, 0x400, 23, 0x400,
   12, 0x400, 10, 0x400, 49, 0x400, 13, 0x400,
   22, 0x400, 37, 0x400, 47, 0x400, 46, 0x400,
   35, 0x400, 11, 0x400, 24, 0x100, 48, 0x400,
   36, 0x400, 25, 0x100, 37, 0x100, 13, 0x100,
   11, 0x100, 24, 0x200, 49, 0x100, 23, 0x100,
   10, 0x100, 13, 0x200, 10, 0x200, 49, 0x200,
   46, 0x100, 22, 0x100, 12, 0x100, 22, 0x200,
   34, 0x400, 23, 0x200, 12, 0x200, 48, 0x200,
   48, 0x100, 47, 0x200, 47, 0x100, 25, 0x200,
   37, 0x200, 11, 0x200, 34, 0x100, 34, 0x200,
   46, 0x200, 35, 0x100, 36, 0x100, 35, 0x200,
   36, 0x200, 24, 0x80, 10, 0x80, 25, 0x80,
   12, 0x80, 13, 0x80, 11, 0x80, 46, 0x80,
   49, 0x80, 23, 0x80, 22, 0x80, 53, 0x200,
   37, 0x80, 48, 0x80, 13, 0x4, 11, 0x4,
   35, 0x80, 10, 0x40, 34, 0x80, 46, 0x4,
   17, 0x200, 50, 0x200, 22, 0x4, 14, 0x200,
   47, 0x80, 25, 0x4, 12, 0x4, 23, 0x4,
   10, 0x4, 13, 0x40, 26, 0x200, 16, 0x200,
   11, 0x40, 41, 0x200, 24, 0x4, 37, 0x4,
   47, 0x40, 48, 0x4, 52, 0x200, 37, 0x40,
   28, 0x200, 49, 0x4, 36, 0x80, 29, 0x200,
   15, 0x200, 27, 0x200, 24, 0x40, 16, 0x20,
   38, 0x200, 49, 0x40, 15, 0x40, 39, 0x200,
   25, 0x40, 40, 0x200, 46, 0x40, 51, 0x200,
   23, 0x40, 10, 0x8, 48, 0x40, 12, 0x40,
   51, 0x40, 27, 0x20, 17, 0x400, 24, 0x8,
   52, 0x400, 15, 0x400, 51, 0x10, 17, 0x20,
   35, 0x40, 22, 0x40, 52, 0x40, 26, 0x20,
   53, 0x40, 27, 0x40, 29, 0x400, 28, 0x40,
   13, 0x8, 36, 0x4, 47, 0x4, 28, 0x20,
   22, 0x8, 34, 0x40, 23, 0x8, 53, 0x400,
   28, 0x400, 51, 0x20, 14, 0x400, 34, 0x4,
   17, 0x40, 16, 0x40, 36, 0x40, 15, 0x20,
   41, 0x10, 25, 0x8, 50, 0x40, 13, 0x20,
   17, 0x10, 29, 0x40, 50, 0x400, 48, 0x8,
   26, 0x10, 16, 0x10, 35, 0x4, 41, 0x20,
   14, 0x40, 29, 0x20, 52, 0x20, 12, 0x8,
   38, 0x400, 53, 0x20, 26, 0x400, 41, 0x40,
   24, 0x20, 14, 0x10, 27, 0x10, 50, 0x20,
   40, 0x40, 39, 0x400, 14, 0x20, 38, 0x20,
   15, 0x10, 16, 0x400, 11, 0x20, 26, 0x40,
   51, 0x400, 27, 0x400, 47, 0x8, 46, 0x8,
   52, 0x10, 10, 0x20, 46, 0x20, 41, 0x400,
   11, 0x8, 53, 0x10, 22, 0x2, 39, 0x40,
   22, 0x20, 29, 0x10, 50, 0x10, 39, 0x20,
   37, 0x8, 25, 0x20, 40, 0x20, 49, 0x20,
   34, 0x8, 10, 0x10, 24, 0x1, 39, 0x10,
   13, 0x10, 22, 0x1, 28, 0x10, 35, 0x20,
   38, 0x40, 24, 0x10, 49, 0x8, 12, 0x20,
   25, 0x2, 13, 0x1, 10, 0x1, 47, 0x20,
   23, 0x20, 40, 0x10, 25, 0x1, 40, 0x400,
   34, 0x20, 48, 0x20, 46, 0x1, 47, 0x10,
   36, 0x8, 37, 0x1, 49, 0x1, 23, 0x2,
   35, 0x1, 38, 0x10, 37, 0x20, 46, 0x10,
   48, 0x1, 24, 0x2, 23, 0x1, 12, 0x1,
   13, 0x2, 14, 0x100, 28, 0x8, 11, 0x1,
   12, 0x2, 11, 0x2, 17, 0x100, 47, 0x1,
   22, 0x10, 25, 0x10, 48, 0x10, 16, 0x100,
   23, 0x10, 51, 0x8, 11, 0x10, 46, 0x2,
   29, 0x100, 28, 0x100, 10, 0x2, 34, 0x2,
   35, 0x8, 17, 0x8, 37, 0x2, 50, 0x100,
   15, 0x100, 12, 0x10, 16, 0x8, 41, 0x8,
   15, 0x8, 36, 0x20, 36, 0x1, 47, 0x2,
   28, 0x4, 48, 0x2, 37, 0x10, 49, 0x10,
   35, 0x2, 53, 0x100, 51, 0x100, 27, 0x8,
   26, 0x8, 26, 0x100, 53, 0x8, 14, 0x8,
   34, 0x1, 52, 0x100, 27, 0x100, 41, 0x100,
   40, 0x8, 17, 0x4, 29, 0x8, 39, 0x100,
   49, 0x2, 53, 0x4, 38, 0x100, 36, 0x10,
   15, 0x4, 14, 0x4, 35, 0x10, 52, 0x8,
   34, 0x10, 51, 0x4, 40, 0x100, 36, 0x2,
   50, 0x4, 26, 0x4, 38, 0x8, 27, 0x4,
   39, 0x8, 16, 0x4, 51, 0x2, 29, 0x4,
   39, 0x4, 41, 0x4, 50, 0x8, 38, 0x4,
   17, 0x2, 40, 0x4, 52, 0x4, 28, 0x2,
   14, 0x2, 26, 0x2, 53, 0x2, 29, 0x2,
   15, 0x2, 50, 0x2, 41, 0x2, 27, 0x2,
   16, 0x2, 52, 0x2, 39, 0x2, 50, 0x80,
   38, 0x2, 40, 0x2, 16, 0x80, 14, 0x80,
   17, 0x80, 53, 0x80, 41, 0x80, 29, 0x80,
   52, 0x80, 15, 0x80, 40, 0x80, 26, 0x80,
   39, 0x80, 27, 0x80, 28, 0x80, 51, 0x80,
   53, 0x1, 38, 0x80, 41, 0x1, 14, 0x1,
   52, 0x1, 27, 0x1, 26, 0x1, 15, 0x1,
   51, 0x1, 40, 0x1, 28, 0x1, 29, 0x1,
   16, 0x1, 17, 0x1, 50, 0x1, 39, 0x1,
   38, 0x1
};

const Word16 mode_DTX[NBBITS_SID << 1] = {
   0, 0x20, 0, 0x10, 0, 0x8, 0, 0x4,
   0, 0x2, 0, 0x1, 1, 0x20, 1, 0x10,
   1, 0x8, 1, 0x4, 1, 0x2, 1, 0x1,
   2, 0x20, 2, 0x10, 2, 0x8, 2, 0x4,
   2, 0x2, 2, 0x1, 3, 0x10, 3, 0x8,
   3, 0x4, 3, 0x2, 3, 0x1, 4, 0x10,
   4, 0x8, 4, 0x4, 4, 0x2, 4, 0x1,
   5, 0x20, 5, 0x10, 5, 0x8, 5, 0x4,
   5, 0x2, 5, 0x1, 6, 0x1
};

const Word16 nb_of_param[NUM_OF_SPMODES]= {
   PRMNO_7k, PRMNO_9k, PRMNO_12k,
   PRMNO_14k, PRMNO_16k, PRMNO_18k,
   PRMNO_20k, PRMNO_23k, PRMNO_24k
};

const Word16 dfh_M7k[PRMNO_7k] = {
   0, 49, 131,
   84, 5, 50,
   29, 2015, 8,
   0, 2061, 8,
   1, 3560, 8,
   0, 2981, 8
};

const Word16 dfh_M9k[PRMNO_9k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 29,
   3, 15, 7,
   15, 8, 16,
   13, 7, 17,
   16, 8, 0,
   16, 20, 16,
   27, 8, 23,
   0, 27, 0,
   27, 8
};

const Word16 dfh_M12k[PRMNO_12k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 7, 63,
   127, 15, 70,
   37, 1, 209,
   210, 224, 96,
   31, 7, 1,
   256, 260, 271,
   443, 31, 47,
   0, 400, 238,
   436, 347, 31
};

const Word16 dfh_M14k[PRMNO_14k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 3847, 3845,
   63, 127, 70,
   34, 0, 3128,
   4517, 192, 96,
   0, 2, 1,
   4160, 8036, 267,
   443, 31, 46,
   0, 3840, 7091,
   432, 395, 31
};

const Word16 dfh_M16k[PRMNO_16k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 3847, 3845,
   3847, 3843, 70,
   31, 0, 3648,
   4764, 824, 2864,
   0, 6, 1,
   4160, 5220, 4319,
   7131, 31, 47,
   0, 112, 3764,
   219, 211, 31
};

const Word16 dfh_M18k[PRMNO_18k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 3, 2,
   3, 2, 7223,
   703, 7223, 703,
   70, 0, 1,
   3, 2, 2,
   3, 9475, 9483,
   3090, 8737, 0,
   0, 1, 0,
   0, 2, 0,
   4112, 4400, 8415,
   14047, 31, 38,
   0, 2, 1,
   3, 1, 91,
   426, 13545, 12955,
   0
};

const Word16 dfh_M20k[PRMNO_20k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 161, 759,
   3, 2, 127,
   516, 6167, 447,
   70, 11, 1,
   264, 641, 2,
   3, 123, 562,
   8347, 4354, 0,
   1, 1, 264,
   408, 3, 0,
   256, 308, 9487,
   14047, 31, 46,
   0, 320, 885,
   2, 2, 464,
   439, 11347, 12739,
   0
};

const Word16 dfh_M23k[PRMNO_23k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 1154, 1729,
   1154, 1761, 447,
   1519, 959, 495,
   70, 27, 1,
   1800, 1253, 665,
   1960, 546, 164,
   1043, 335, 0,
   28, 1, 580,
   196, 1187, 383,
   1031, 1052, 359,
   1531, 31, 45,
   1, 1024, 893,
   1272, 1920, 101,
   876, 203, 1119,
   31
};

const Word16 dfh_M24k[PRMNO_24k] = {
   0, 49, 131,
   55, 49, 38,
   26, 29, 58,
   1, 1729, 1154,
   1761, 1154, 1519,
   959, 495, 447,
   70, 3, 42,
   1, 580, 1436,
   1362, 1250, 901,
   714, 24, 45,
   0, 0, 0,
   1, 68, 708,
   1212, 383, 1048,
   1611, 1756, 1467,
   31, 1, 23,
   0, 1536, 1460,
   861, 1554, 410,
   1368, 1008, 594,
   31, 0
};

/*
 * overall table with the parameters of the
 * decoder homing frames for all modes
 */

const Word16 *dhf[10] = {
   dfh_M7k,
   dfh_M9k,
   dfh_M12k,
   dfh_M14k,
   dfh_M16k,
   dfh_M18k,
   dfh_M20k,
   dfh_M23k,
   dfh_M24k,
   dfh_M24k
};

#endif
