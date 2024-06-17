CC=gcc
CFLAGS = -Wall -Wextra
LDFLAGS_STATIC  = -static-libgcc
LDFLAGS_DYNAMIC = -L.

SRC = main.c
OBJ = main.o foo.o

STATIC_TARGET  = app_static
DYNAMIC_TARGET = app_dynamic
SHAREDLIB      = libfoo.so

all: $(STATIC_TARGET) $(DYNAMIC_TARGET)

$(STATIC_TARGET): $(OBJ) libfoo.a
	$(CC) $(LDFLAGS_STATIC)  $(OBJ) libfoo.a -o $@

$(DYNAMIC_TARGET): $(OBJ) $(SHAREDLIB)
	$(CC) $(LDFLAGS_DYNAMIC) $(OBJ) -o $@

# 静的ライブラリを作る
libfoo.a: foo.o
	# c - create: ライブラリを作成する
	# r - replace: 既存のファイルが存在すれば置き換える
	# s - index: インデックスを作成する
	ar rcs $@ $^

# 動的ライブラリを作る
# -shared: 共有ライブラリを作成する為のオプション
# -fPIC: Position Independent Codeを生成するためのオプション
$(SHAREDLIB): foo.o
	$(CC) -shared -fPIC -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.a $(STATIC_TARGET) $(DYNAMIC_TARGET)
