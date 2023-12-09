#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
struct nhanvien {
	char  maNhanVien[10];
	char  tenNhanVien[50];
	float luong;
	char  email[100];
	time_t ngayvaolam;
};
struct phongban {
	char tenpb[30];
	char mapb[10];
	int sonv;
};
void nhapnhanvien(nhanvien& nv) {
	cout << "\n nhap ten nhan vien";
	cin >> nv.tenNhanVien;
	cout << "\n  nhap ma nhan vien";
	cin >> nv.maNhanVien;
	cout << "\n  nhap luong nhan vien";
	cin >> nv.luong;
	cout << "\n nhap email";
	cin >> nv.email;
	cout << "\n Luong: " << nv.luong << endl;
	cout << "Nhap ngay vao lam (dd mm yyyy): ";
	int day, month, year;
	cin >> day >> month >> year;

	struct tm tmStruct;
	tmStruct.tm_year = year - 1900;
	tmStruct.tm_mon = month - 1;
	tmStruct.tm_mday = day;
	nv.ngayvaolam = mktime(&tmStruct);

}
void xuatNhanVien(nhanvien nv) {
	cout << "Ten nhan vien: " << nv.tenNhanVien<< endl;
	cout << "Ma nhan vien: " << nv.maNhanVien<< endl;
	cout << "Email: " << nv.email << endl;
	tm* tmStruct = localtime(&nv.ngayvaolam);
	cout << "Ngay vao lam: " << tmStruct->tm_mday << "/" << tmStruct->tm_mon + 1 << "/" << tmStruct->tm_year + 1900 << endl;
	cout << "Luong: " << nv.luong << endl;
}
void main() {
	nhanvien a;
	nhapnhanvien(a);
	xuatNhanVien(a);
}