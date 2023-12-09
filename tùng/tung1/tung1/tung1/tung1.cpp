#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    int ma;
    string ten;
    float luong;
    int ngayVaoLam;
    bool gioiTinh;
};

struct PhongBan {
    char tenPB[20];
    int maPB;
    int soNhanVien;
    NhanVien* dsNhanVien;
};

// 1. Hàm nhập nhân viên
void nhapNhanVien(NhanVien& nv) {
    cout << "Nhap ma nhan vien: ";
    cin >> nv.ma;
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, nv.ten);
    cout << "Nhap luong: ";
    cin >> nv.luong;
    cout << "Nhap ngay vao lam (dd/mm/yyyy): ";
    cin >> nv.ngayVaoLam;
    cout << "Nhap gioi tinh (0 - Nu, 1 - Nam): ";
    cin >> nv.gioiTinh;
}

// 2. Hàm nhập phòng ban  
void nhapPhongBan(PhongBan& pb) {
    cout << "\nnhap ma phong ban: "; cin >> pb.maPB;
    cout << "\nnhap ten phong ban: "; cin.ignore(); cin.getline(pb.tenPB, 20);
    cout << "Nhap so nhan vien: ";
    cin >> pb.soNhanVien;

    pb.dsNhanVien = new NhanVien[pb.soNhanVien];

    for (int i = 0; i < pb.soNhanVien; i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        nhapNhanVien(pb.dsNhanVien[i]);
    }
}

// 3. Hàm xuất nhân viên
void xuatNhanVien(NhanVien nv) {
    cout << nv.ma << " - " << nv.ten << " - " << nv.luong<<" - " <<(nv.gioiTinh?"Nam":"Nu")<<" - " << nv.ngayVaoLam << " - ";
   
}

// 4. Hàm xuất phòng ban
void xuatPhongBan(PhongBan pb) {
    cout << "\nMa phong: " << pb.maPB;
    cout << "\nTen phong: " << pb.tenPB;
    cout << "\nCo " << pb.soNhanVien << " nhan vien.";

    for (int i = 0; i < pb.soNhanVien; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":";
        xuatNhanVien(pb.dsNhanVien[i]);
    }
}

// 5. Hàm thêm phòng ban
void themPhongBan(PhongBan pbs[], int& soPB) {
    PhongBan pbMoi;
    nhapPhongBan(pbMoi);

    pbs[soPB] = pbMoi;
    soPB++;
}

// 6. Xuất tất cả NV trong DS phòng ban
void xuatDSNhanVien(PhongBan pbs[], int soPB) {

    for (int i = 0; i < soPB; i++) {
        xuatPhongBan(pbs[i]);
    }
}

// 7. Xuất DS NV làm việc trên 20 năm
void xuatNVLamTren20Nam(PhongBan pbs[], int soPB) {
    int ngayHienTai = 20221230;

    for (int i = 0; i < soPB; i++) {
        for (int j = 0; j < pbs[i].soNhanVien; j++) {
            if (ngayHienTai - pbs[i].dsNhanVien[j].ngayVaoLam > 20000) {
                xuatNhanVien(pbs[i].dsNhanVien[j]);
            }
        }
    }
}

// 8. Xuất DS NV là nữ 
void xuatDSNu(PhongBan pbs[], int soPB) {
    for (int i = 0; i < soPB; i++) {
        for (int j = 0; j < pbs[i].soNhanVien; j++) {
            if (pbs[i].dsNhanVien[j].gioiTinh == 0) {
                xuatNhanVien(pbs[i].dsNhanVien[j]);
            }
        }
    }
}

// 9. Sửa TT NV
void suaNhanVien(PhongBan pbs[], int soPB) {
    int maPB, maNV;
    cout << "\nNhap ma phong ban can tim: ";
    cin >> maPB;

    cout << "Nhap ma nhan vien can sua: ";
    cin >> maNV;

    // Tìm phòng ban
    int found1 = 0;
    int viTriPB;
    for (int i = 0; i < soPB; i++) {
        if (pbs[i].soNhanVien == maPB) {
            found1 = 1;
            viTriPB = i;
            break;
        }
    }

    if (found1 == 0) {
        cout << "Khong tim thay phong ban";
        return;
    }

    // Tìm nhân viên
    int found2 = 0;
    int viTriNV;
    for (int i = 0; i < pbs[viTriPB].soNhanVien; i++) {
        if (pbs[viTriPB].dsNhanVien[i].ma == maNV) {
            found2 = 1;
            viTriNV = i;
            break;
        }
    }

    if (found2 == 0) {
        cout << "Khong tim thay nhan vien";
        return;
    }
    // Sửa TT
    cout << "\nThong tin cu: ";
    xuatNhanVien(pbs[viTriPB].dsNhanVien[viTriNV]);

    nhapNhanVien(pbs[viTriPB].dsNhanVien[viTriNV]);

    cout << "\nDa cap nhat thanh cong!";
}

// 10. Sắp xếp NV tăng dần theo tên
void sapXepTheoTen(PhongBan& pb) {
    for (int i = 0; i < pb.soNhanVien - 1; i++) {
        for (int j = i + 1; j < pb.soNhanVien; j++) {
            if (pb.dsNhanVien[i].ten > pb.dsNhanVien[j].ten) {
                swap(pb.dsNhanVien[i], pb.dsNhanVien[j]);
            }
        }
    }
}

// 11. Sắp xếp NV tăng dần theo lương
void sapXepTheoLuong(PhongBan& pb) {
    for (int i = 0; i < pb.soNhanVien - 1; i++) {
        for (int j = i + 1; j < pb.soNhanVien; j++) {
            if (pb.dsNhanVien[i].luong > pb.dsNhanVien[j].luong) {
                swap(pb.dsNhanVien[i], pb.dsNhanVien[j]);
            }
        }
    }
}

// 12. Đếm số lượng NV mỗi phòng ban
void demSoLuongNV(PhongBan pbs[], int soPB) {
    for (int i = 0; i < soPB; i++) {
        cout << "\nPhong ban " << i + 1 << " co " << pbs[i].soNhanVien << " nhan vien";
    }
}

// 13. Xuất DS NV có mức lương thấp nhất
void xuatNVLuongThapNhat(PhongBan pbs[], int soPB) {
    float minLuong = 1e9;

    for (int i = 0; i < soPB; i++) {
        for (int j = 0; j < pbs[i].soNhanVien; j++) {
            if (pbs[i].dsNhanVien[j].luong < minLuong) {
                minLuong = pbs[i].dsNhanVien[j].luong;
            }
        }
    }

    for (int i = 0; i < soPB; i++) {
        for (int j = 0; j < pbs[i].soNhanVien; j++) {
            if (pbs[i].dsNhanVien[j].luong == minLuong) {
                xuatNhanVien(pbs[i].dsNhanVien[j]);
            }
        }
    }
}

// 14. Chuyển NV từ PB này sang PB khác
void chuyenNhanVien(PhongBan& pb1, PhongBan& pb2) {
    int viTri;
    cout << "Nhap vi tri nhan vien can chuyen: ";
    cin >> viTri;

    if (viTri < 0 || viTri >= pb1.soNhanVien) {
        cout << "Vi tri khong hop le!";
        return;
    }

    pb2.dsNhanVien[pb2.soNhanVien] = pb1.dsNhanVien[viTri];
    pb2.soNhanVien++;

    // Xóa NV khỏi vị trí cũ 
    for (int i = viTri; i < pb1.soNhanVien; i++) {
        pb1.dsNhanVien[i] = pb1.dsNhanVien[i + 1];
    }

    pb1.soNhanVien--;

    cout << "Da chuyen thanh cong!";
}

// 15. Gộp 2 phòng ban  
void ghep2PhongBan(PhongBan& pb1, PhongBan& pb2) {

    for (int i = 0; i < pb2.soNhanVien; i++) {
        pb1.dsNhanVien[pb1.soNhanVien] = pb2.dsNhanVien[i];
        pb1.soNhanVien++;
    }

    cout << "Da ghep thanh cong!";
}

// 16. Menu cho người dùng 
void menu(PhongBan pbs[], int soPB) {
    int luachon;

    while (true) {
        system("cls");

        cout << "===== CHUONG TRINH QUAN LY NHAN VIEN =====\n";
        cout << "1. Them phong ban.\n";
        cout << "2. Xuat danh sach phong ban\n";
        cout << "3. Tim va sua thong tin nhan vien\n";
        cout << "4. Sap xep nhan vien theo ten\n";
        cout << "5. Sap xep nhan vien theo luong\n";
        cout << "6. Dem so luong nhan vien tung phong\n";
        cout << "7. Xuat nhan vien luong thap nhat\n";
        cout << "8. Chuyen nhan vien giua 2 phong\n";
        cout << "9. Ghep 2 phong ban\n";
        cout << "0. Thoat\n\n";

        cout << "Nhap lua chon: ";
        cin >> luachon;

        if (luachon == 1) {
            themPhongBan(pbs, soPB);
        }
        else if (luachon == 2) {
            xuatDSNhanVien(pbs, soPB);
        }
        else if (luachon == 3) {
            suaNhanVien(pbs, soPB);
        }
        else if (luachon == 4) {
            for (int i = 0; i < soPB; i++) {
                sapXepTheoTen(pbs[i]);
            }
        }
        else if (luachon == 5) {
            for (int i = 0; i < soPB; i++) {
                sapXepTheoLuong(pbs[i]);
            }
        }
        else if (luachon == 6) {
            demSoLuongNV(pbs, soPB);
        }
        else if (luachon == 7) {
            xuatNVLuongThapNhat(pbs, soPB);
        }
        else if (luachon == 8) {
            // Giả sử chỉ có 2 phòng 
            chuyenNhanVien(pbs[0], pbs[1]);
        }
        else if (luachon == 9) {
            // Giả sử chỉ có 2 phòng
            ghep2PhongBan(pbs[0], pbs[1]);
        }
        else if (luachon == 0) {
            break;
        }

        system("pause");
    }
}

int main() {
    PhongBan dsPhongBan[100];
    int soPB = 0;

    menu(dsPhongBan, soPB);

    return 0;
}