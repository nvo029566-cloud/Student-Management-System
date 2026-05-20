#include <stdio.h>
#include <string.h>
#include "sinhvien.h"

void luuFile(SinhVien a[], int n){

    FILE *f = fopen("SinhVien.txt", "w");

    if(f == NULL){
        printf("Khong mo duoc file!\n");
        return;
    }

    fprintf(f, "%d\n", n);

    for(int i = 0; i < n; i++){

        fprintf(f, "%s\n", a[i].maSV);
        fprintf(f, "%s\n", a[i].ten);
        fprintf(f, "%s\n", a[i].lop);
        fprintf(f, "%s\n", a[i].gt);

        fprintf(f, "%d %d %d\n",
                a[i].ns.ngay,
                a[i].ns.thang,
                a[i].ns.nam);

        fprintf(f, "%.2lf\n", a[i].gpa);
    }

    fclose(f);

    printf("Luu file thanh cong!\n");
}

void docFile(SinhVien a[], int *n){

    FILE *f = fopen("SinhVien.txt", "r");

    if(f == NULL){
        printf("Khong tim thay file!\n");
        return;
    }

    fscanf(f, "%d\n", n);

    for(int i = 0; i < *n; i++){

        fgets(a[i].maSV, sizeof(a[i].maSV), f);
        a[i].maSV[strcspn(a[i].maSV, "\n")] = 0;

        fgets(a[i].ten, sizeof(a[i].ten), f);
        a[i].ten[strcspn(a[i].ten, "\n")] = 0;

        fgets(a[i].lop, sizeof(a[i].lop), f);
        a[i].lop[strcspn(a[i].lop, "\n")] = 0;

        fgets(a[i].gt, sizeof(a[i].gt), f);
        a[i].gt[strcspn(a[i].gt, "\n")] = 0;

        fscanf(f, "%d %d %d\n",
               &a[i].ns.ngay,
               &a[i].ns.thang,
               &a[i].ns.nam);

        fscanf(f, "%lf\n", &a[i].gpa);
    }

    fclose(f);

    printf("Doc file thanh cong!\n");
}