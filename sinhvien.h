#ifndef SinhVien_H
#define SinhVien_H

#define MAX 100

typedef struct {
    int ngay;
    int thang;
    int nam;
} Date;

typedef struct {
    char ten[100];
    char lop[100];
    char maSV[20];
    char gt[10];
    Date ns;
    double gpa;
} SinhVien;


double nhapGPA();
SinhVien nhap();
void in(int stt, SinhVien x);
void nhapDS(SinhVien a[], int n);
void themSinhVien(SinhVien a[], int *n);
void inTieuDe();
void inDS(SinhVien a[], int n);
void gpaMax(SinhVien a[], int n);
void sapXep(SinhVien a[], int n);~
void xoaSinhVien(SinhVien a[], int *n);
void timTen(SinhVien a[], int n);
void timMa(SinhVien a[], int n);
void xoaTheoMa(SinhVien a[], int *n);
void suaThongTin(SinhVien a[], int n);
void luuFile(SinhVien a[], int n);
void docFile(SinhVien a[], int *n);
#endif