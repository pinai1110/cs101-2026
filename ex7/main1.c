#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int n;                 /* 要買幾組 */
    int lotto[5][7];       /* 最多 5 組，每組 7 個數字 */
    int i, j, k;
    int repeat;
    FILE *fp;
    time_t now;
    char date[30];

    srand((unsigned)time(NULL));   /* 用現在時間當亂數種子 */

    /* 1. 開機畫面 + 輸入 n */
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("只能買 1 ~ 5 組喔！\n");
        return 0;
    }

    /* 2. 產生 n 組，每組 7 個不重複的 1 ~ 69 */
    for (i = 0; i < n; i++) {
        for (j = 0; j < 7; j++) {
            do {
                lotto[i][j] = rand() % 69 + 1;   /* 1 ~ 69 */
                repeat = 0;
                for (k = 0; k < j; k++) {        /* 跟同一組前面的數字比 */
                    if (lotto[i][k] == lotto[i][j]) {
                        repeat = 1;
                        break;
                    }
                }
            } while (repeat);                    /* 重複就重抽 */
        }
    }

    /* 3. 取得現在日期時間，例如 "Wed Mar  2 14:12:47 2022" */
    now = time(NULL);
    strcpy(date, ctime(&now));
    date[strlen(date) - 1] = '\0';   /* 去掉 ctime 最後的換行 */

    /* 4. 輸出到 lotto.txt */
    fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    fprintf(fp, "======== lotto649 =========\n");
    fprintf(fp, "= %s =\n", date);

    for (i = 0; i < 5; i++) {
        fprintf(fp, "[%d]:", i + 1);
        for (j = 0; j < 7; j++) {
            if (i < n)
                fprintf(fp, " %02d", lotto[i][j]);   /* %02d 讓 7 變成 07 */
            else
                fprintf(fp, " --");                  /* 沒買的組印 -- */
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
