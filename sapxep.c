#include <stdio.h>
#include "sinhvien.h"
#include <string.h>

void sapXep(SinhVien a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j].gpa > a[j + 1].gpa){
                SinhVien tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    printf("Da hoan thanh sap xep!\n");
    return;
}
void gpaMax(SinhVien a[], int n){
    if(n == 0){
        printf("Danh sach trong!\n");
        return;
    }
    double max = a[0].gpa;
    for(int i = 1; i < n; i++){
        if(a[i].gpa > max){
            max = a[i].gpa;
        }
    }
    for(int i = 0; i < n; i++){
        if(max == a[i].gpa){
            in(i + 1, a[i]);
        }
    }
    return;
}