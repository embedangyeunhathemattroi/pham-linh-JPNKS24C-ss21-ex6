#include <stdio.h>
#include <string.h>

struct SinhVien {
    int IDmoi;             // ID c?a sinh viên
    char name[50];         // Tên sinh viên
    int age;               // Tu?i sinh viên
    char phone[50];        // S? di?n tho?i sinh viên
};

typedef struct SinhVien SinhVien;

// Hàm thêm sinh viên
void themSinhVien(SinhVien students[], int *size) {
    if (*size >= 5) {
        printf("Danh sach sinh vien da day, khong the them sinh vien moi!\n");
        return;
    }

    // Gán ID cho sinh viên m?i
    students[*size].IDmoi = *size + 1;

    // Nh?p tên sinh viên
    printf("Nhap ten sinh vien: ");
    fgets(students[*size].name, sizeof(students[*size].name), stdin);
    students[*size].name[strcspn(students[*size].name, "\n")] = '\0'; // Xóa ký t? '\n'

    // Nh?p tu?i sinh viên
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &students[*size].age);
    getchar(); // Xóa ký t? '\n' còn l?i trong b? d?m sau khi nh?p tu?i

    // Nh?p s? di?n tho?i sinh viên
    printf("Nhap so dien thoai sinh vien: ");
    fgets(students[*size].phone, sizeof(students[*size].phone), stdin);
    students[*size].phone[strcspn(students[*size].phone, "\n")] = '\0'; // Xóa ký t? '\n'

    // Tang s? lu?ng sinh viên trong m?ng
    (*size)++;
}

// Hàm in danh sách sinh viên
void inDanhSachSinhVien(SinhVien students[], int size) {
    printf("\nDanh sach sinh vien:\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "Ten", "Tuoi", "So Dien Thoai");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-5d %-15s\n", students[i].IDmoi, students[i].name, students[i].age, students[i].phone);
    }
}

// Hàm nh?p danh sách sinh viên (tang d?n s? lu?ng)
void nhapDS(SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].IDmoi = i + 1;  // T? d?ng gán ID cho m?i sinh viên
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        
        printf("Nhap ten sinh vien: ");
        fgets(a[i].name, sizeof(a[i].name), stdin);
        a[i].name[strcspn(a[i].name, "\n")] = '\0'; // Xóa ký t? '\n'

        printf("Nhap tuoi sinh vien: ");
        scanf("%d", &a[i].age);
        getchar();  // Xóa ký t? '\n' còn l?i sau khi nh?p tu?i

        printf("Nhap so dien thoai sinh vien: ");
        fgets(a[i].phone, sizeof(a[i].phone), stdin);
        a[i].phone[strcspn(a[i].phone, "\n")] = '\0'; // Xóa ký t? '\n'
    }
}

// Hàm xu?t danh sách sinh viên
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

    int size = 5; // S? lu?ng sinh viên hi?n t?i trong m?ng

    // In danh sách sinh viên ban d?u
    inDanhSachSinhVien(students, size);

    // Yêu c?u thêm sinh viên m?i
    printf("\nHay them sinh vien moi:\n");
    themSinhVien(students, &size);

    // In l?i danh sách sinh viên sau khi thêm
    printf("\nTong hop danh sach sinh vien sau khi them:\n");
    inDanhSachSinhVien(students, size);

    // Nh?p và xu?t danh sách sinh viên thêm vào
    int n;
    SinhVien newStudents[100]; // M?ng sinh viên m?i d? nh?p thêm
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &n);
    getchar(); // Ð?c ký t? '\n' sau khi nh?p n
    nhapDS(newStudents, n); // Nh?p danh sách sinh viên m?i
    xuatDS(newStudents, n); // Xu?t danh sách sinh viên m?i

    return 0;
}

