#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    int n;                
    int lotto[5][7];       
    int i, j, k;
    int repeat;
    FILE *fp;
    time_t now;
    char date[30];

    srand((unsigned)time(NULL));   

    
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("只能買 1 ~ 5 組喔！\n");
        return 0;
    }

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < 7; j++) {
            do {
                lotto[i][j] = rand() % 69 + 1;   
                repeat = 0;
                for (k = 0; k < j; k++) {       
                    if (lotto[i][k] == lotto[i][j]) {
                        repeat = 1;
                        break;
                    }
                }
            } while (repeat);                    
        }
    }


    now = time(NULL);
    strcpy(date, ctime(&now));
    date[strlen(date) - 1] = '\0';   

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
                fprintf(fp, " %02d", lotto[i][j]);  
            else
                fprintf(fp, " --");                  
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
