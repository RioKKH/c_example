#include <stdio.h>   // fopen, fclose, fgets, sscanf, printf
#include <stdlib.h>  // strtol
#include <string.h>  // strtok, strdup, strcmp, strcpy, strlen


#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

int main(int argc, char *argv[])
{
    char line[MAX_LINE_LENGTH];
    char *columns[MAX_COLUMNS];
    char *data[MAX_COLUMNS]; // n番目の列のデータを格納する配列
    int dataIndex = 0; // data配列のインデックス
    int n = 0; // n番目の列

    FILE *file = fopen("data.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    if (argc < 2) {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    } else {
        n = strtol(argv[1], NULL, 10);
        if (n < 0) {
            printf("n must be positive\n");
            return 1;
        }
    }

    /*
    char delimiter[10] = {};
    if (strcmp(delimiter, "space") == 0) {
        strcpy(delimiter, " ");
    } else if (strcmp(delimiter, "tab") == 0) {
        strcpy(delimiter, "\t");
    } else if (strcmp(delimiter, "comma") == 0) {
        strcpy(delimiter, ",");
    } else {
        printf("delimiter must be space, tab, or comma\n");
        return 1;
    }
    */

    while (fgets(line, sizeof(line), file)) {
        // 改行文字を削除する
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            // 改行文字をNULL文字に置き換える
            line[len-1] = '\0';
        }

        // 1行読み込んで、カンマで分割する
        char *token = strtok(line, ",");
        int colIndex = 0;

        // 1列ずつ読み込む
        while (token) {
            columns[colIndex] = token;
            token = strtok(NULL, ",");
            colIndex++;
        }

        // n番目の列のデータをdata配列に格納する
        if (colIndex > n) {
            data[dataIndex] = strdup(columns[n]);
            dataIndex++;
        } else {
            printf("n is too large\n");
            return 1;
        }
    }

    fclose(file);

    // 結果を表示する
    for (int i = 0; i < dataIndex; i++) {
        printf("%s\n", data[i]);
        free(data[i]);
    }
    return 0;
}

