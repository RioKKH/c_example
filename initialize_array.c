#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int main()
{
	// 初期化していないので、すべての要素が不定となってしまう。
	char aaa[N];
	// {}でかこまえれた初期化リストでは、各要素にデフォルト値が
	// 割り当てられる。char型の要素のデフォルト値は\0なのでNULL文字
	// で配列の各要素が初期化される
	char bbb[N] = {};
	// memset関数を使用して初期化する場合、すべての要素が\0で初期化
	// されるが、strlen()関数などの文字列長を取得する関数では正しく
	// 機能市内可能性がある
	char ccc[N];
	memset(ccc, '\0', sizeof(ccc));

	for (int i = 0; i < N; i++) { printf("%d\n", aaa[i]); }
	for (int i = 0; i < N; i++) { printf("%d\n", bbb[i]); }
	for (int i = 0; i < N; i++) { printf("%d\n", ccc[i]); }

	return 0;
}

