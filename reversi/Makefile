CC = gcc
# コンパイルオプションとして、GTK3のヘッダーファイルの場所を指定します
CFLAGS = `pkg-config --cflags gtk+-3.0` -g
# リンクオプションとして、GTK3のライブラリの場所を指定します
LDFLAGS = `pkg-config --libs gtk+-3.0`
# 現在のディレクトリにある全ての.cファイルをソースファイルとします。
SOURCES = $(wildcard *.c)
# ソースファイルの拡張子を除いた名前をターゲットとします。
# これはMakefile独自の文法でパターン置換と呼ばれるもの。
# $(VAR:A=B)でVAR変数の中のパターンAをBに置換する。具体的には、
# SOURCES変数の値(.cで終わるファイル名のリスト)の中で、.cをから文字列に
# 置換する。結果として.cを取り除いたファイル名のリストが得られる
TARGETS = $(SOURCES:.c=)

# allとcleanはphonyターゲットです。これらはファイル名ではなく、
# 常に実行されるルールを定義します。
.PHONY: all clean


# allターゲットは全てのターゲットをビルドします
all: $(TARGETS)

# このパターンルールは、.cファイルから実行可能ファイルをビルドします。
# $@はターゲット名(.cを除いたファイル名), $<は依存ファイル名(.cファイル名)を表します。
%: %.c
	$(CC) $(CFLAGS) -fsanitize=undefined -o $@ $< $(LDFLAGS)

# cleanターゲットは、全ての実行可能ファイルを削除します
clean:
	rm -f $(TARGETS)
