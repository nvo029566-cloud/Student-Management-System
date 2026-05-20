#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include "sinhvien.h"

double nhapGPA(){
    double gpa;
    do{
        printf("Nhap GPA: ");
        scanf("%lf", &gpa);
        if(gpa < 0 || gpa > 4){
            printf("GPA khong hop le!\n");
        }
    }while(gpa < 0 || gpa > 4);
    return gpa;
}

Date nhapNgaySinh(){

    Date d;
    printf("Nhap ngay sinh: \n");
    scanf("%d", &d.ngay);
    printf("Nhap thang: \n");
    scanf("%d", &d.thang);
    printf("Nhap nam: \n");
    scanf("%d", &d.nam);
    return d;

}

SinhVien nhap(){
    SinhVien x;
    getchar();

    printf("Nhap ho va ten sinh vien: ");
    fgets(x.ten, sizeof(x.ten), stdin);
    x.ten[strcspn(x.ten, "\n")] = 0;

    printf("Nhap lop: ");
    fgets(x.lop, sizeof(x.lop), stdin);
    x.lop[strcspn(x.lop, "\n")] = 0;

    printf("Nhap ma sinh vien: ");
    fgets(x.maSV, sizeof(x.maSV), stdin);
    x.maSV[strcspn(x.maSV, "\n")] = 0;


    printf("Gioi tinh: ");
    fgets(x.gt, sizeof(x.gt), stdin);
    x.gt[strcspn(x.gt, "\n")] = 0;

    printf("Nhap thong tin ngay sinh:\n");
    x.ns = nhapNgaySinh();


    x.gpa = nhapGPA();


    return x;
}

void nhapDS(SinhVien a[], int n){
    for(int i = 0; i < n; i++){
        printf("\nNhap thong tin sinh vien %d: \n", i + 1);
        a[i] = nhap();
    }
    return;
}

void inTieuDe(){
    printf("\n============================ DANH SACH THONG TIN SINH VIEN ==============================\n");
    printf("%-6s %-20s %-10s %-12s %-15s %-10s %10s\n", 
        "STT",
        "Ten", 
        "Lop",
        "Ma SV",
        "Ngay sinh",
        "Gioi tinh", 
        "GPA");
        printf("=========================================================================================\n");
}

void in(int stt, SinhVien x){
    char sttStr[6], ngayStr[15], gpaStr[8], maStr[12], gioiTinhStr[5];
    sprintf(sttStr, "%d.", stt);
    sprintf(ngayStr, "%02d/%02d/%04d", x.ns.ngay, x.ns.thang, x.ns.nam);
    sprintf(gpaStr, "%.2lf", x.gpa);
    sprintf(maStr, "%s", x.maSV);
    sprintf(gioiTinhStr, "%s", x.gt);
    printf("%-6s %-20s %-10s %-12s %-15s %-10s %10s\n", 
        sttStr,
        x.ten, 
        x.lop,
        maStr,
        ngayStr,
        gioiTinhStr,
        gpaStr);

    return;
}

void inDS(SinhVien a[], int n){
    if(n == 0){
        printf("Danh sach trong!\n");
        return;
    }
    inTieuDe();
    for(int i = 0; i < n; i++){
        in(i + 1, a[i]);
    }
    printf("=========================================================================================\n");
    printf("Tong: %d sinh vien\n", n);
    return;
}

void themSinhVien(SinhVien a[], int *n){
    printf("Nhap thong tin sinh vien moi: \n");
    a[*n] = nhap();
    (*n)++;
    printf("Nhap thanh cong !\n");
}

void xoaSinhVien(SinhVien a[], int *n){
    if(*n == 0){
        printf("Danh sach trong !\n");
        return;
    }
    int k;
    printf("Nhap STT sinh vien can xoa: ");
    scanf("%d", &k);
    if(k < 1 || k > *n){
        printf("STT khong hop le !\n");
        return;
    }
    for(int i = k - 1; i < *n - 1; i++){
        a[i] = a[i + 1];
    }
    (*n)--;
    printf("Xoa sinh vien thanh cong!\n");
    return;
}

void timTen(SinhVien a[], int n){
    char ten[100];
    getchar();
    printf("Nhap ten can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    int found = 0;
    printf("Ket qua tim kiem\n");
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].ten, ten) == 0){
            in(i + 1, a[i]);
            found = 1;
        }
    }
    if(!found){
        printf("Khong tim thay sinh vien !\n");
        return;
    }
}
void timMa(SinhVien a[], int n){
    char ma[50];
    getchar();
    printf("Nhap ma sinh vien can tim: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = 0;
    int found = 0;
    printf("Ket qua tim kiem\n");
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].maSV, ma) == 0){
            in(i + 1, a[i]);
            found = 1;
        }
    }
    if(!found){
        printf("Khong tim thay ma sinh vien !\n");
        return;
    }
}

void xoaTheoMa(SinhVien a[], int *n){
    if(*n == 0){
        printf("Danh sach trong !\n");
        return;
    }

    char ma[50];
    getchar();
    printf("Nhap ma sinh vien can xoa: ");
    fgets(ma , sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = 0;

    int found = 0;
    for(int i = 0; i < *n; i++){
        if(strcmp(a[i].maSV, ma) == 0){
            found = 1;
        }
        for(int j = i; j < *n - 1; j++){
            a[j] = a[j + 1];
        }
        (*n)--;
        printf("Xoa sinh vien thanh cong !\n");
        break;
    }
    if(!found){
        printf("Khong tim thay ma sinh vien !\n");
        return;
    }
}

void suaThongTin(SinhVien a[], int n){
    if(n == 0){
        printf("Danh sach trong !\n");
        return;
    }

    char ma[50];
    getchar();
    printf("Nhap ma can sua: ");
    fgets(ma, sizeof(ma), stdin);
    ma[strcspn(ma, "\n")] = 0;
    int found = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(a[i].maSV, ma) == 0){
            printf("Nhap thong tin moi: \n");
            a[i] = nhap();
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Khong tim thay sinh vien !\n");
        return;
    }
}


