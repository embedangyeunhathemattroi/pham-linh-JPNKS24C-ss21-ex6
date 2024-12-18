#include <stdio.h>
#include <string.h>

struct SinhVien {
    int IDmoi;             // ID c?a sinh vi�n
    char name[50];         // T�n sinh vi�n
    int age;               // Tu?i sinh vi�n
    char phone[50];        // S? di?n tho?i sinh vi�n
};

typedef struct SinhVien SinhVien;

// H�m th�m sinh vi�n
void themSinhVien(SinhVien students[], int *size) {
    if (*size >= 5) {
        printf("Danh sach sinh vien da day, khong the them sinh vien moi!\n");
        return;
    }

    // G�n ID cho sinh vi�n m?i
    students[*size].IDmoi = *size + 1;

    // Nh?p t�n sinh vi�n
    printf("Nhap ten sinh vien: ");
    fgets(students[*size].name, sizeof(students[*size].name), stdin);
    students[*size].name[strcspn(students[*size].name, "\n")] = '\0'; // X�a k� t? '\n'

    // Nh?p tu?i sinh vi�n
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &students[*size].age);
    getchar(); // X�a k� t? '\n' c�n l?i trong b? d?m sau khi nh?p tu?i

    // Nh?p s? di?n tho?i sinh vi�n
    printf("Nhap so dien thoai sinh vien: ");
    fgets(students[*size].phone, sizeof(students[*size].phone), stdin);
    students[*size].phone[strcspn(students[*size].phone, "\n")] = '\0'; // X�a k� t? '\n'

    // Tang s? lu?ng sinh vi�n trong m?ng
    (*size)++;
}

// H�m in danh s�ch sinh vi�n
void inDanhSachSinhVien(SinhVien students[], int size) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So Dien Thoai");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-5d %-15s\n", students[i].IDmoi, students[i].name, students[i].age, students[i].phone);
    }
}

// H�m nh?p danh s�ch sinh vi�n (tang d?n s? lu?ng)
void nhapDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].IDmoi = i + 1;  // T? d?ng g�n ID cho m?i sinh vi�n
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        
        printf("Nhap ten sinh vien: ");
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0'; // X�a k� t? '\n'

        printf("Nhap tuoi sinh vien: ");
        scanf("%d", &a[i].age);
        getchar();  // X�a k� t? '\n' c�n l?i sau khi nh?p tu?i

        printf("Nhap so dien thoai sinh vien: ");
        fgets(a[i].phone, sizeof(a[i].phone), stdin);
        a[i].phone[strcspn(a[i].phone, "\n")] = '\0'; // X�a k� t? '\n'
    }
}

// H�m xu?t danh s�ch sinh vi�n
void xuatDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, So dien thoai: %s\n", a[i].IDmoi, a[i].name, a[i].age, a[i].phone);
    }
}

int main() {
    SinhVien students[10] = {
        {1, "Linh Ngoc Pham", 18, "0346333182"},
        {2, "Dang Hai Chau", 16, "09385109083"},
        {3, "Chu Huyen Anh", 17, "0974006455"},
        {4, "Cao Uyen Chi", 19, "09633222"},
        {5, "Chu Tue Anh", 24, "097888888"}
    };

    int size = 5; // S? lu?ng sinh vi�n hi?n t?i trong m?ng

    // In danh s�ch sinh vi�n ban d?u
    inDanhSachSinhVien(students, size);

    // Y�u c?u th�m sinh vi�n m?i
    printf("\nHay them sinh vien moi:\n");
    themSinhVien(students, &size);

    // In l?i danh s�ch sinh vi�n sau khi th�m
    printf("\nTong hop danh sach sinh vien sau khi them:\n");
    inDanhSachSinhVien(students, size);

    // Nh?p v� xu?t danh s�ch sinh vi�n th�m v�o
    int n;
    SinhVien newStudents[100]; // M?ng sinh vi�n m?i d? nh?p th�m
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    getchar(); // �?c k� t? '\n' sau khi nh?p n
    nhapDS(newStudents, n); // Nh?p danh s�ch sinh vi�n m?i
    xuatDS(newStudents, n); // Xu?t danh s�ch sinh vi�n m?i

    return 0;
}

