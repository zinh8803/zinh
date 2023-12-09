#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip> 
#include<string>
using namespace std;
const int MAX_HOADON = 100;
struct HoaDon {
	int MaHD;
	char tenKH[100];
	long sdt;
	char diachi[100];
	long tongtien;
	bool trangthai;
	
};
struct DS_HOADON {
	int n;
	HoaDon dshd[MAX_HOADON];
};

void xuat(HoaDon hd);
void nhapdshd(DS_HOADON& ds);
void xuatdshd(DS_HOADON ds);
void nhapktrasl(int& so);
void nhapluachon(int& so);
void nhapktrakituMHD(int& so);
void nhapktrakituMHDXOA(int& so);
void nhapktrakituMHDSua(int& so);
void nhaplonggiatien(long& so);
void nhaplongsodienthoai(long& so);
bool kiemTraMaHoaDonTrongTep(int maHD,  DS_HOADON& ds, int k);
bool kiemTraMaHoaDonTonTai(int a, DS_HOADON ds, int k);
void docHoaDon(const char* filename, DS_HOADON& hd);
void luuHoaDon(const char* filename, DS_HOADON& hd);
void luuHoaDon1(const char* filename, DS_HOADON& hd);
void xoadulieu(const char* filename);
void sapXepTrangThaitrue(DS_HOADON& ds);
void sapXepTrangThaifalse(DS_HOADON& ds);
void sapXepTheoTen(DS_HOADON& ds);
void sapXepTheoTen1(DS_HOADON& ds);
void sapXeptongtienMAX(DS_HOADON& ds);
void sapXeptongtienMIN(DS_HOADON& ds);
void sapXepMHDMIN(DS_HOADON& ds);
void sapXepMHDMAX(DS_HOADON& ds);
char* tachTen(char* s);
void xoahoadon(DS_HOADON& ds);
void chinhsuahoadon(DS_HOADON& ds);
void locTheoGiaTienlonhon(DS_HOADON& ds);
void locTheoGiaTiennhohon(DS_HOADON& ds);
void menu();
