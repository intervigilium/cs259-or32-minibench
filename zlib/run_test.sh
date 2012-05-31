CC=or32-elf-gcc
CFLAGS="-static -mnewlib -mboard=atlys -DTIMER_HZ=1000 -DUSE_SECURE"
SRC_FILES="zlib_bench.c deflate.c zutil.c crc32.c adler32.c gzlib.c gzflags.c trees.c secure_func.c"
SIM=or32-sim
SIM_CFG="/home/echen/scratch/cs259-w12/minisuite/sim-atlys.cfg"

run_test() {
  local KEY=$1
  $CC ${CFLAGS} "-Wa,-mpufkey=${KEY}" ${SRC_FILES}  -o prog.out
  $SIM -f ${SIM_CFG} prog.out > ${KEY}.out
}

rm *.out

run_test 0x00200000
run_test 0x00600000
run_test 0x00e00000
run_test 0x01e00000
run_test 0x03e00000

run_test 0x00010000
run_test 0x00030000
run_test 0x00070000
run_test 0x000f0000
run_test 0x001f0000

run_test 0x00000800
run_test 0x00001800
run_test 0x00003800
run_test 0x00007800
run_test 0x0000f800
