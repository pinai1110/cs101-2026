#include <stdio.h>
#include <string.h>

typedef struct employee {
    int id;
    char name[20];
    int age;
    float salary;
} employee_t;

// 印出單一員工資料
void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %f\n", emp.salary);
    printf("\n");
}

// 計算平均年齡
int emp_aveage_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

// 把 n 筆資料寫入 employee.bin
void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
    return;
}

// 從 employee.bin 讀出資料（最多 n 筆），並印出 [i] id name
void emp_readfile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案\n");
        return;
    }
    int i = 0;
    while (i < n && fread(&emp[i], sizeof(employee_t), 1, fp)) {
        printf("[%d] %d %s\n", i, emp[i].id, emp[i].name);
        i++;
    }
    fclose(fp);
    return;
}

int main() {
    employee_t emp[3];
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");

    emp_writefile(emp, 3);
    employee_t read_emp[10];
    emp_readfile(read_emp, 10);

    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}v
