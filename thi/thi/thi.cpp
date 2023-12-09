#include <iostream>
#include <iomanip>
using namespace std;

struct ngayVaoLam {
    int ngay, thang, nam;
};

struct nhanvien {
    int maNV;
    char tenNV[50];
    float luong;
    char email[50];
    bool gioitinh;
    ngayVaoLam ngayvaolam;
};

struct phongban {
    char tenPB[50];
    char maPB[10];
    nhanvien dsNV[100];
    int sonv;
};

struct ds_phongban {
    int sl;
    phongban dspb[100];
};

void nhapNhanVien(nhanvien& nv) {
    cout << "Nhap ma nhan vien: ";
    cin >> nv.maNV;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập số nguyên
    cout << "Nhap ten nhan vien: ";
    cin.getline(nv.tenNV, sizeof(nv.tenNV));
    cout << "Nhap luong: ";
    cin >> nv.luong;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập số thực
    cout << "Nhap email: ";
    cin.getline(nv.email, sizeof(nv.email));
    cout << "Nhap gioi tinh (0: Nu, 1: Nam): ";
    cin >> nv.gioitinh;
    cout << "Nhap ngay vao lam (ngay thang nam): ";
    cin >> nv.ngayvaolam.ngay >> nv.ngayvaolam.thang >> nv.ngayvaolam.nam;
}

void xuatNhanVien(const nhanvien& nv) {
    cout << "Ma NV: " << nv.maNV << "\n";
    cout << "Ten NV: " << nv.tenNV << "\n";
    cout << "Luong: " << nv.luong << "\n";
    cout << "Email: " << nv.email << "\n";
    cout << "Gioi tinh: " << (nv.gioitinh ? "Nam" : "Nu") << "\n";
    cout << "Ngay vao lam: " << nv.ngayvaolam.ngay << "/" << nv.ngayvaolam.thang << "/" << nv.ngayvaolam.nam << "\n";
}

void nhapPhongBan(phongban& pb) {
    cout << "Nhap ma phong ban: ";
    cin >> pb.maPB;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập chuỗi
    cout << "Nhap ten phong ban: ";
    cin.getline(pb.tenPB, sizeof(pb.tenPB));
    cout << "Nhap so nhan vien trong phong ban: ";
    cin >> pb.sonv;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập số nguyên
    cout << "Nhap thong tin nhan vien trong phong ban:\n";
    for (int i = 0; i < pb.sonv; ++i) {
        nhapNhanVien(pb.dsNV[i]);
    }
}

void xuatPhongBan(const phongban& pb) {
    cout << "Ma phong ban: " << pb.maPB << "\n";
    cout << "Ten phong ban: " << pb.tenPB << "\n";
    cout << "So nhan vien trong phong ban: " << pb.sonv << "\n";
    cout << "Danh sach nhan vien trong phong ban:\n";
    for (int i = 0; i < pb.sonv; ++i) {
        cout << "Nhan vien thu " << i + 1 << ":\n";
        xuatNhanVien(pb.dsNV[i]);
    }
}

void nhapDanhSachPhongBan(ds_phongban& ds) {
    cout << "Nhap so luong phong ban: ";
    cin >> ds.sl;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập số nguyên
    cout << "Nhap thong tin cho tung phong ban:\n";
    for (int i = 0; i < ds.sl; ++i) {
        nhapPhongBan(ds.dspb[i]);
    }
}

void xuatDanhSachPhongBan(const ds_phongban& ds) {
    cout << "So luong phong ban: " << ds.sl << "\n";
    cout << "Danh sach phong ban:\n";
    for (int i = 0; i < ds.sl; ++i) {
        cout << "Phong ban thu " << i + 1 << ":\n";
        xuatPhongBan(ds.dspb[i]);
    }
}

int main() {
    ds_phongban ds;
    nhapDanhSachPhongBan(ds);
    xuatDanhSachPhongBan(ds);

    return 0;
}
