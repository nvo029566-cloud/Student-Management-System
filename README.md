# 📚 Student Management System — C Language

[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](#)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](#-license)

A console-based **Student Management System** written in **C**, featuring an interactive menu for managing student records — including data entry, search, sorting, editing, and persistent file storage. The project follows a **modular architecture**, with each group of features organized into its own source file.

---

## 📑 Table of Contents

- [Features](#-features)
- [Project Structure](#-project-structure)
- [Data Structure](#️-data-structure)
- [System Requirements](#️-system-requirements)
- [Installation & Build](#-installation--build)
- [Usage Guide](#-usage-guide)
- [Storage File Format](#-storage-file-format)
- [Program Flow Diagram](#-program-flow-diagram)
- [Notes & Limitations](#️-notes--limitations)
- [Roadmap](#-roadmap)
- [Author](#-author)
- [License](#-license)

---

## ✨ Features

| Option | Function | Description |
|:---:|---|---|
| 1 | Input student list | Enter `N` students consecutively |
| 2 | Display student list | Print a table of all students |
| 3 | Find highest GPA | Display the student with the highest GPA |
| 4 | Sort | Sort students by GPA in ascending order (Bubble Sort) |
| 5 | Add student | Append a new student to the end of the list |
| 6 | Delete by index | Remove a student by their displayed index number |
| 7 | Search by name | Search for a student by full name |
| 8 | Search by student ID | Search for a student by ID |
| 9 | Delete by student ID | Remove a student by ID |
| 10 | Edit student info | Update all fields of a student by ID |
| 11 | Save to file | Write the list to `SinhVien.txt` |
| 12 | Load from file | Load the list from `SinhVien.txt` |
| **0** | **Exit** | **End the program** |

---

## 📁 Project Structure

```
project/
├── main.c          # Main function and main menu loop
├── sinhvien.h      # Header file: struct definitions & function declarations
├── nhap_in.c       # Input, display, search, delete, and edit functions
├── sapxep.c        # Sorting functions and highest-GPA lookup
└── file.c          # File read/write functions
```

> 💡 Each module is split into its own `.c` file with shared declarations centralized in `sinhvien.h`, keeping the codebase organized and easy to extend — a good practice for modular C programming.

---

## 🗂️ Data Structure

```c
typedef struct {
    int ngay, thang, nam;   // day, month, year
} Date;

typedef struct {
    char ten[100];      // Full name
    char lop[100];      // Class
    char maSV[20];       // Student ID
    char gt[10];         // Gender
    Date ns;             // Date of birth
    double gpa;          // GPA score (0.0 – 4.0)
} SinhVien;
```

> ℹ️ Field names (`ten`, `lop`, `maSV`, `gt`, `ns`, `gpa`) are kept as-is in the source code (Vietnamese abbreviations) to match the actual implementation. Their English equivalents are: `name`, `class`, `student ID`, `gender`, `date of birth`, `GPA`.

---

## ⚙️ System Requirements

| Requirement | Details |
|---|---|
| Operating System | Windows (uses `windows.h` for UTF-8 console support) |
| Compiler | GCC (MinGW) or MSVC |
| C Standard | C99 or later |

> ⚠️ On Linux/macOS, the `windows.h` includes and any UTF-8 console setup calls must be removed or wrapped in `#ifdef _WIN32 ... #endif` for the program to compile.

---

## 🚀 Installation & Build

### 1. Clone the repository

```bash
git clone https://github.com/<username>/<repo-name>.git
cd <repo-name>
```

### 2. Compile with GCC

```bash
gcc main.c nhap_in.c sapxep.c file.c -o sinhvien -lm
```

Alternatively, if using **Code::Blocks** or **Dev-C++**: add all `.c` files to the project, then **Build & Run**.

### 3. Run the program

```bash
./sinhvien
```

---

## 📖 Usage Guide

When launched, the program displays the main menu:

```
╔══════════════════════════════════╗
║              MENU                ║
║══════════════════════════════════║
║  1. Enter student information    ║
║  2. Display student list         ║
║  3. Find highest GPA              ║
║  4. Sort students                 ║
║  5. Add a student                 ║
║  6. Delete a student              ║
║  7. Search for a student          ║
║  8. Search by student ID          ║
║  9. Delete by student ID          ║
║ 10. Edit student information      ║
║ 11. Save to file                  ║
║ 12. Load from file                ║
║  0. Exit                          ║
╚══════════════════════════════════╝
```

Select an option by entering its corresponding number, then follow the on-screen prompts.

---

## 💾 Storage File Format

Data is saved to `SinhVien.txt` as plain text, in the following format:

```
<number of students>
<student ID>
<full name>
<class>
<gender>
<day> <month> <year>
<GPA>
...
```

**Example:**

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

## 🔄 Program Flow Diagram

```
┌─────────────┐
│   main()    │
└──────┬──────┘
       │
       ▼
┌─────────────────────┐
│  Display menu (0-12) │◄──────────────┐
└──────┬───────────────┘               │
       │                                │
       ▼                                │
┌─────────────────────┐                │
│ Read user choice     │                │
└──────┬───────────────┘                │
       │                                │
       ▼                                │
┌──────────────────────────────┐        │
│ switch(choice)                 │        │
│  ├─ 1,5,9,10  → nhap_in.c      │        │
│  ├─ 2,6,7,8   → nhap_in.c      │        │
│  ├─ 3,4       → sapxep.c       │        │
│  ├─ 11,12     → file.c         │        │
│  └─ 0         → Exit           │        │
└──────┬───────────────────────────┘       │
       │ (operation complete)              │
       ▼                                    │
┌──────────────────────┐                    │
│ Return to main menu   │────────────────────┘
└──────────────────────┘
```

---

## ⚠️ Notes & Limitations

- The program stores a maximum of **100 students** in memory.
- Valid GPA range is **0.0 to 4.0** — the program will prompt for re-entry if an invalid value is given.
- Searching by name requires the **exact full name**, including correct case (case-sensitive).
- The `SinhVien.txt` file is created automatically when **Save to file** is selected.
- The internal struct field names (`ten`, `lop`, `maSV`, etc.) remain in Vietnamese to match the source code; see [Data Structure](#️-data-structure) for their English meanings.

---

## 🔮 Roadmap

- [ ] Replace fixed-size array (max 100 students) with dynamic memory allocation
- [ ] Add case-insensitive and partial-match search by name
- [ ] Add sorting by additional fields (name, class, date of birth)
- [ ] Add input validation for student ID format and date of birth
- [ ] Add cross-platform support (Linux/macOS) via `#ifdef`
- [ ] Export student list to CSV format

---

## 👤 Author

> C programming assignment — 2nd-year student project.

---

## 📄 License

This project is released under the **MIT License** — free to use, modify, and distribute for educational and non-commercial purposes.
