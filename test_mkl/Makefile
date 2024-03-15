CC = gcc
# intelコンパイラーはなさそうなので、gccを変わりに使う 
# CC = icc

# コンパイラーオプション
#
# -mavx2: AVX2命令セットを使用する
# -mfma:  FMAを使用する
# -march=native: 実行するCPUに合わせて最適化する
CFLAGS = -O3 -march=native -mavx2 -mfma -fopenmp

# -xHOST: ホストCPUに最適化
# CFLAGS = -O3 -xHOST # iccの場合の最適化フラグ。

MKL_INCLUDE_DIR = /opt/intel/oneapi/mkl/latest/include
MKL_LIB_DIR     = /opt/intel/oneapi/mkl/latest/lib/intel64
MKL_LIBS = -Wl,-rpath,$(MKL_LIB_DIR) -L$(MKL_LIB_DIR) -lmkl_intel_lp64 -lmkl_gnu_thread -lmkl_core -lgomp -lpthread -lm

TARGET = matmul

SOURCES = matmul.c

OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(MKL_INCLUDE_DIR) -o $@ $^ $(MKL_LIBS)
	#$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(MKL_LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MKL_INCLUDE_DIR) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: default
default: $(TARGET)
