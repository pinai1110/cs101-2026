#include <stdio.h>

int main()
{
    FILE* fp;
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};
    int ra[3];
    char rb[4];
    float rc[3];
    
    //寫入(二進位)
    fp = fopen("a.bin", "wb");
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 4, fp);
    fwrite(c, sizeof(float), 3, fp);
    fclose(fp);
    
    //讀取
    fp = fopen("a.bin", "rb");
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 4, fp);
    fread(rc, sizeof(float), 3, fp);
    fclose(fp);
    
    //輸出
    for (int i = 0; i < 3; i++) printf("%d ", ra[i]);
    printf("\n");
    for (int i = 0; i < 3; i++) printf("%c ", rb[i]);
    printf("\n");
    for (int i = 0; i < 3; i++) printf("%f ", rc[i]);
    printf("\n");
    
    return 0;
}
