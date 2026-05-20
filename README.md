# 📚 Quản Lý Sinh Viên (Student Management System)

Chương trình quản lý thông tin sinh viên viết bằng ngôn ngữ C, chạy trên nền console với giao diện menu tương tác.

---

## 📁 Cấu trúc thư mục

```
project/
├── main.c          # Hàm main, vòng lặp menu chính
├── sinhvien.h      # Header file: định nghĩa struct & khai báo hàm
├── nhap_in.c       # Các hàm nhập liệu, hiển thị, tìm kiếm, xóa, sửa
├── sapxep.c        # Các hàm sắp xếp và tìm GPA cao nhất
└── file.c          # Các hàm đọc/ghi file
```

---

## 🗂️ Cấu trúc dữ liệu

```c
typedef struct {
    int ngay, thang, nam;
} Date;

typedef struct {
    char ten[100];      // Họ và tên
    char lop[100];      // Lớp
    char maSV[20];      // Mã sinh viên
    char gt[10];        // Giới tính
    Date ns;            // Ngày sinh
    double gpa;         // Điểm GPA (0.0 – 4.0)
} SinhVien;
```

---

## ⚙️ Yêu cầu hệ thống

| Yêu cầu | Chi tiết |
|---|---|
| Hệ điều hành | Windows (dùng `windows.h` để hỗ trợ UTF-8) |
| Compiler | GCC (MinGW) hoặc MSVC |
| Chuẩn C | C99 trở lên |

---

## 🔨 Cách biên dịch

```bash
gcc main.c nhap_in.c sapxep.c file.c -o sinhvien -lm
```

Hoặc nếu dùng Code::Blocks / Dev-C++: thêm tất cả file `.c` vào project rồi Build & Run.

---

## 🚀 Cách chạy

```bash
./sinhvien
```

Chương trình sẽ hiển thị menu:

```
╔══════════════════════════════════╗
║              MENU                ║
║══════════════════════════════════║
║  1. Nhap thong tin sinh vien     ║
║  2. Hien thi thong tin sinh vien ║
║  3. Tim GPA cao nhat             ║
║  4. Sap xep                      ║
║  5. Them sinh vien               ║
║  6. Xoa sinh vien                ║
║  7. Tim kiem sinh vien           ║
║  8. Tim sinh vien theo ma SV     ║
║  9. Xoa sinh vien theo ma SV     ║
║ 10. Sua thong tin Sv             ║
║ 11. Luu file                     ║
║ 12. Doc file                     ║
║  0. Thoat                        ║
╚══════════════════════════════════╝
```

---

## 📋 Chức năng

| Lựa chọn | Chức năng | Mô tả |
|---|---|---|
| 1 | Nhập danh sách | Nhập N sinh viên liên tiếp |
| 2 | Hiển thị danh sách | In bảng toàn bộ sinh viên |
| 3 | Tìm GPA cao nhất | Hiển thị sinh viên có GPA cao nhất |
| 4 | Sắp xếp | Sắp xếp theo GPA tăng dần (Bubble Sort) |
| 5 | Thêm sinh viên | Thêm một sinh viên vào cuối danh sách |
| 6 | Xóa theo STT | Xóa sinh viên theo số thứ tự hiển thị |
| 7 | Tìm theo tên | Tìm kiếm sinh viên theo họ tên đầy đủ |
| 8 | Tìm theo mã SV | Tìm kiếm sinh viên theo mã số |
| 9 | Xóa theo mã SV | Xóa sinh viên theo mã số |
| 10 | Sửa thông tin | Cập nhật toàn bộ thông tin theo mã SV |
| 11 | Lưu file | Ghi danh sách ra `SinhVien.txt` |
| 12 | Đọc file | Nạp danh sách từ `SinhVien.txt` |
| 0 | Thoát | Kết thúc chương trình |

---

## 💾 Định dạng file lưu trữ

Dữ liệu được lưu vào file `SinhVien.txt` theo định dạng plaintext:

```
<số lượng sinh viên>
<maSV>
<họ tên>
<lớp>
<giới tính>
<ngày> <tháng> <năm>
<GPA>
...
```

Ví dụ:

```
2
SV001
Nguyen Van A
CNTT01
Nam
15 08 2004
3.50
SV002
Tran Thi B
CNTT02
Nu
20 03 2004
3.85
```

---

## ⚠️ Lưu ý

- Chương trình lưu tối đa **100 sinh viên** trong bộ nhớ.
- GPA hợp lệ trong khoảng **0.0 đến 4.0**, chương trình sẽ yêu cầu nhập lại nếu sai.
- Khi tìm theo tên, cần nhập **chính xác** họ tên đầy đủ (phân biệt hoa/thường).
- File `SinhVien.txt` được tạo tự động khi chọn **Lưu file**.

---

## 👤 Tác giả

> Bài tập lập trình C — Sinh viên năm 2
