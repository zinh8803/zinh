#include"graphics.h"
#include<iostream>

#pragma comment(lib,"graphics.lib")
using namespace std;
struct thoigian {
		int giay;
		int phut;
		int gio;
		int ngay;
		int thang;
		int nam;
};
void nhap(thoigian& tg) {
	
	//cout << "\nnhap tg trong duong ham";
	cout << "\nnam: "; cin >> tg.nam;
	cout << "\nthang: "; cin >> tg.thang;
	cout << "\nngay: "; cin >> tg.ngay;
	cout << "\ngio: "; cin >> tg.gio;
	cout << "\nphut: "; cin >> tg.phut;
	cout << "\ngiay: "; cin >> tg.giay;
}
void xuat(thoigian tg) {
	cout << "\ntong giay thoi gian hien tai: " << tg.nam <<" nam "<<tg.thang<<" thang "<< tg.ngay << " ngay " << tg.gio << " gio " << tg.phut << " phut " << tg.giay << " giay "  ;
//	cout << "\ntong giay thoi gian duong ham: " << (tg.giay + tg.phut * 60 + tg.gio * 3600)*7*3600;
}
long long tonggiay(thoigian tf) {
	return tf.nam * 365 * 24 * 3600 + tf.thang * 12 * 24 * 3600 + tf.ngay * 24 * 3600 + tf.gio * 3600 + tf.phut * 60 + tf.giay;
}
thoigian chuyen_doi_thoi_gian(long long thoi_gian_ngoai_doi) {
	thoigian tg;

	// Chuyển đổi giây thành năm, tháng, ngày, giờ, phút và giây
	tg.giay = thoi_gian_ngoai_doi % 60;
	thoi_gian_ngoai_doi /= 60;

	tg.phut = thoi_gian_ngoai_doi % 60;
	thoi_gian_ngoai_doi /= 60;

	tg.gio = thoi_gian_ngoai_doi % 24;
	thoi_gian_ngoai_doi /= 24;

	tg.ngay = thoi_gian_ngoai_doi % 30; // Giả sử tháng có 30 ngày
	thoi_gian_ngoai_doi /= 30;

	tg.thang = thoi_gian_ngoai_doi % 12;
	thoi_gian_ngoai_doi /= 12;

	tg.nam = thoi_gian_ngoai_doi;

	return tg;
}

void main() {
	//thoigian a;
	//long long so_giay;
	//nhap(a);
	//xuat(a);
	//so_giay = tonggiay(a);
	//
	//
	//

	//// Gọi hàm chuyển đổi và lấy kết quả
	//thoigian ket_qua = chuyen_doi_thoi_gian((so_giay)*2520);

	//// Hiển thị kết quả
	//cout << "\nKet qua chuyen doi:\n";
	//cout << "Nam: " << ket_qua.nam << " | Thang: " << ket_qua.thang << " | Ngay: " << ket_qua.ngay << " | Gio: " << ket_qua.gio << " | Phut: " << ket_qua.phut << " | Giay: " << ket_qua.giay << endl;
	initwindow(900, 600, "form");
	circle(400, 400, 100);
	getch();
	closegraph();
}