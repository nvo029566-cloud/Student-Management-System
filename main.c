#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include "sinhvien.h"



int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    SinhVien a[100];
    int n = 0;
    int choice;
    do{
        printf("╔══════════════════════════════════╗\n");
        printf("║              MENU                ║\n");
        printf("║══════════════════════════════════║\n");
        printf("║  1. Nhap thong tin sinh vien     ║\n");
        printf("║  2. Hien thi thong tin sinh vien ║\n");
        printf("║  3. Tim GPA cao nhat             ║\n");
        printf("║  4. Sap xep                      ║\n");
        printf("║  5. Them sinh vien               ║\n");
        printf("║  6. Xoa sinh vien                ║\n");
        printf("║  7. Tim kiem sinh vien           ║\n");
        printf("║  8. Tim sinh vien theo ma SV     ║\n");
        printf("║  9. Xoa sinh vien theo ma SV     ║\n");
        printf("║ 10. Sua thong tin Sv             ║\n");
        printf("║ 11. Luu file                     ║\n");
        printf("║ 12. Doc file                     ║\n");
        printf("║  0. Thoat                        ║\n");
        printf("╚══════════════════════════════════╝\n");
        printf("\nNhap lua chon: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nNhap so luong sinh vien: ");
                scanf("%d", &n);
                nhapDS(a, n);
                break;

            case 2:
                inDS(a, n);
                break;

            case 3:
                gpaMax(a, n);
                break;

            case 4: 
                sapXep(a, n);
                break;
            
            case 5:
                themSinhVien(a, &n);
                break;

            case 6:
                xoaSinhVien(a, &n);
                break;

            case 7:
                timTen(a, n);
                break;

            case 8:
                timMa(a, n);
                break;

            case 9:
                xoaTheoMa(a, &n);
                break;

            case 10:
                suaThongTin(a, n);
                break;

            case 11:
                luuFile(a, n);
                break;

            case 12:
                docFile(a, &n);
                break;

            case 0: 
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    }while(choice != 0);
    return 0;
}

