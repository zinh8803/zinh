#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct ngayVaoLam {
    int ngay;
    int thang;
    int nam;
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
//void nhapnhanvien(nhanvien& nv) {
//    cout << "Nhap ma nhan vien: ";
//    cin >> nv.maNV;
//    cout << "Nhap ten nhan vien: ";
//    cin.ignore();
//    cin.getline(nv.tenNV, 50);
//    cout << "Nhap luong: ";
//    cin >> nv.luong;
//    cout << "Nhap email: ";
//    cin.ignore();
//    cin.getline(nv.email, 50);
//    cout << "\nnhap gioi tinh (1:Nam ,2:Nu):";
//    cin >> nv.gioitinh;
//    cout << "Nhap ngay vao lam (dd mm yyyy): " << endl;
//    cout << "\n nhap ngay vao lam : ";
//    cin >> nv.ngayvaolam.ngay;
//    cout << "\n nhap thang vao lam : ";
//    cin >> nv.ngayvaolam.thang;
//    cout << "\n nhap nam lam : ";
//    cin >> nv.ngayvaolam.nam;
//}
void nhapnhanvien(nhanvien& nv) {
    cout << "Nhap ma nhan vien: "; cin.ignore();
    cin >> nv.maNV;
    // Đọc ký tự '\n' sau khi nhập số nguyên
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
        nhapnhanvien(pb.dsNV[i]);
    }
}
void nhapdspb(ds_phongban& ds) {
    cout << "Nhap so luong phong ban: ";
    cin >> ds.sl;
    cin.ignore(); // Đọc ký tự '\n' sau khi nhập số nguyên
    cout << "Nhap thong tin cho tung phong ban:\n";
    for (int i = 0; i < ds.sl; ++i) {
        nhapPhongBan(ds.dspb[i]);
    }
}
void xuatNhanVien(nhanvien nv) {
  /*  cout << "Ma nhan vien: " << nv.maNV << endl;
    cout << "Ten nhan vien: " << nv.tenNV << endl;
    cout << "Luong: " << nv.tenNV << endl;
    cout << "Email: " << nv.email << endl;
    cout << "Ngay vao lam: " << nv.ngayvaolam.ngay
        << "/" << nv.ngayvaolam.thang << "/"
        << nv.ngayvaolam.nam;
    cout << "\n****************************************" << endl;*/
    cout << "Ma NV: " << nv.maNV << "\n";
    cout << "Ten NV: " << nv.tenNV << "\n";
    cout << "Luong: " << nv.luong << "\n";
    cout << "Email: " << nv.email << "\n";
    cout << "Gioi tinh: " << (nv.gioitinh ? "Nam" : "Nu") << "\n";
    cout << "Ngay vao lam: " << nv.ngayvaolam.ngay << "/" << nv.ngayvaolam.thang << "/" << nv.ngayvaolam.nam << "\n";
}

void xuatphongban(phongban pb) {
  
    cout << "Ma phong ban: " << pb.maPB << "\n";
    cout << "Ten phong ban: " << pb.tenPB << "\n";
    cout << "So nhan vien trong phong ban: " << pb.sonv << "\n";
    cout << "Danh sach nhan vien trong phong ban:\n";
    for (int i = 0; i < pb.sonv; ++i) {
        cout << "Nhan vien thu " << i + 1 << ":\n";
        xuatNhanVien(pb.dsNV[i]);
    }
}
void xuatdspb(ds_phongban ds) {
    cout << "So luong phong ban: " << ds.sl << "\n";
    cout << "Danh sach phong ban:\n";
    for (int i = 0; i < ds.sl; ++i) {
        cout << "Phong ban thu " << i + 1 << ":\n";
        xuatphongban(ds.dspb[i]);
    }
}
//void themPhongBan(phongban*& dsPhongBan, int& soPhongBan) {
//    phongban* newDsPhongBan = new phongban[soPhongBan + 1];
//
//    for (int i = 0; i < soPhongBan; i++) {
//        newDsPhongBan[i] = dsPhongBan[i];
//    }
//
//    cout << "Nhap thong tin phong ban moi:" << endl;
//    nhapPhongBan(newDsPhongBan[soPhongBan]);
//
//    delete[] dsPhongBan;
//
//    dsPhongBan = newDsPhongBan;
//    soPhongBan++;
//
//    cout << "Them phong ban moi thanh cong!" << endl;
//}


//void luuDanhSachPhongBanVaoFile(const phongban& pb, const char* fileName) {
//    ofstream outFile(fileName);
//    if (!outFile.is_open()) {
//        cout << "Khong the mo file de ghi!" << endl;
//        return;
//    }
//    outFile << pb.tenPB << endl;
//    outFile << pb.maPB << endl;
//    outFile << pb.sonv << endl;
//    for (int i = 0; i < pb.sonv; i++) {
//        outFile << pb.dsNV[i].maNV << endl;
//        outFile << pb.dsNV[i].tenNV << endl;
//        outFile << pb.dsNV[i].luong << endl;
//        outFile << pb.dsNV[i].email << endl;
//        outFile << pb.dsNV[i].ngayvaolam.ngay << " "
//            << pb.dsNV[i].ngayvaolam.thang << " "
//            << pb.dsNV[i].ngayvaolam.nam << endl;
//    }
//    cout << "Luu danh sach phong ban thanh cong!" << endl;
//    outFile.close();
//}

//void docDanhSachPhongBanTuFile(phongban& pb, const char* fileName) {
//    ifstream inFile(fileName);
//    if (!inFile.is_open()) {
//        cout << "Khong the mo file de doc!" << endl;
//        return;
//    }
//    inFile.ignore();
//    inFile.getline(pb.tenPB, 50);
//    inFile.getline(pb.maPB, 10);
//    inFile >> pb.sonv;
//    inFile.ignore();
//    pb.dsNV = new nhanvien[pb.sonv];
//    for (int i = 0; i < pb.sonv; i++) {
//        inFile >> pb.dsNV[i].maNV;
//        inFile.ignore();
//        inFile.getline(pb.dsNV[i].tenNV, 50);
//        inFile >> pb.dsNV[i].luong;
//        inFile.ignore();
//        inFile.getline(pb.dsNV[i].email, 50);
//        inFile >> pb.dsNV[i].ngayvaolam.ngay
//            >> pb.dsNV[i].ngayvaolam.thang
//            >> pb.dsNV[i].ngayvaolam.nam;
//    }
//    cout << "Doc danh sach phong ban thanh cong!" << endl;
//    inFile.close();
//}

void menu() {
   
    ds_phongban b;
    int choice;
   
   
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. them phong ban" << endl;
        cout << "2. xuat phong ban" << endl;
        cout << "3. luu file" << endl;
        cout << "4. doc file" << endl;
        cout << "5. Thoat" << endl;
        cout << "Nhap lua chon cua ban (1-5):";
        cin >> choice;
      
        cout << endl;
        switch (choice) {
        case 1:
          //  themPhongBan(dsPhongBan, soPhongBan);
            nhapdspb(b);
            break;
        case 2:
           xuatdspb(b);
            break;
        case 3:
            //luuDanhSachPhongBanVaoFile(a, "phongban.txt");
            break;
        case 4:
           // docDanhSachPhongBanTuFile(a, "phongban.txt");
            break;
        case 5:
            cout << "Tam biet!";
            break;
        default:
            cout << "Lua chon khong hop le." << endl;
            break;
        }
    } while (choice != 5);
   
}
void main() {
  //  menu();
    nhanvien v;
    phongban a;

    ds_phongban ds;
    nhapnhanvien(v);
    xuatNhanVien(v);
}
