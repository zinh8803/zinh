#include"Header.h"
void nhapdshd(DS_HOADON& ds) {
    cout << "\nNhap so luong hoa don:";nhapktrasl(ds.n);
    for (int i = 0; i < ds.n; i++) {
        cout << "hoa don thu " << i + 1 << endl;
        cout << "Nhap ma hoa don: ";
        nhapktrakituMHD(ds.dshd[i].MaHD);
        while (kiemTraMaHoaDonTonTai(ds.dshd[i].MaHD, ds, i) || kiemTraMaHoaDonTrongTep(ds.dshd[i].MaHD, ds, i))
        {
            cout << "ma hoa don bi trung,nhap lai ma hoa don: ";
            nhapktrakituMHD(ds.dshd[i].MaHD);
        }
        cout << "nhap ten khach hang:"; cin.ignore();
        cin.getline(ds.dshd[i].tenKH, 100);
        cout << "nhap so dien thoai khach hang:";
        nhaplongsodienthoai(ds.dshd[i].sdt);
        cout << "nhap dia chi khach hang:"; cin.ignore();
        cin.getline(ds.dshd[i].diachi, 100);
        cout << "nhap tong tien hoa don:";
        nhaplonggiatien(ds.dshd[i].tongtien);
        cout << "nhap trang thai hoa don(1 la true, 0 la false):";
        while (true) {
            cin >> ds.dshd[i].trangthai;
            if (cin.fail() || (ds.dshd[i].trangthai != 0 && ds.dshd[i].trangthai != 1)) {
                cin.clear();  
                cin.ignore(INT_MAX, '\n'); 
                cout << "Gia tri khong hop le. Chi nhan 0 hoac 1. Hay nhap lai." << endl;
            }
            else {
                break;  
            }
        }
        cout << endl;
    }
}
void nhaplonggiatien(long& so) {
    long a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban nhap sai gia tien , nhap lai:";
        }
    } while (check);
    so = stol(b);
}
void nhapktrasl(int& so) {
    int a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban nhap sai ki tu so luong , nhap lai:";
        }
    } while (check);
    so = stoi(b);
}
void nhapluachon(int& so) {
    int a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban phai nhap so theo menu, nhap lai:";
        }
    } while (check);
    so = stoi(b);
}
void nhapktrakituMHD(int& so) {
    int a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban nhap sai ki tu ma hoa don , nhap lai:";
        }
    } while (check);
    so = stoi(b);
}
void nhapktrakituMHDXOA(int& so) {
    int a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban nhap sai ki tu ma hoa don de xoa, nhap lai:";
        }
    } while (check);
    so = stoi(b);
}
void nhapktrakituMHDSua(int& so) {
    int a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nban nhap sai ki tu ma hoa don de sua, nhap lai:";
        }
    } while (check);
    so = stoi(b);
}
void nhaplongsodienthoai(long& so) {
    long a;
    string b;
    bool check = false;
    do {
        cin >> b;
        check = false;
        for (int i = 0; i < b.length(); i++) {
            if (!isdigit(b[i])) {
                check = true;
                break;
            }
        }
        if (check) {
            cout << "\nso dien thoai bi loi, nhap lai:";
        }
    } while (check);
    so = stol(b);
}
bool kiemTraMaHoaDonTrongTep(int maHD,DS_HOADON& ds, int k) {
        FILE* fp;
        errno_t fp_in;
        fp_in = fopen_s(&fp, "hoadon.txt", "r");
        if (fp == NULL) {
            cout << "loi doc file\n";
            return false;
        }

        HoaDon hd;
        while (fread(&hd, sizeof(HoaDon), 1, fp)) {
            if (hd.MaHD == maHD && k != -1) {
                fclose(fp);
                return true;
            }
            if (hd.MaHD == maHD && k == -1) {
                fclose(fp);
                return true;
            }
        }

        fclose(fp);
        return false;
    }
bool kiemTraMaHoaDonTonTai(int a, DS_HOADON ds, int k) {
    for (int i = 0; i < ds.n; i++) {
        if (k == i) 
            return false;
        if (a == ds.dshd[i].MaHD) {
            return true;
        }
    }
    return false;
}
void xuat(HoaDon hd) {
    cout << setw(10) << left << hd.MaHD
        << setw(20) << left << hd.tenKH << setw(1) << left << "0"
        << setw(15) << left << hd.sdt
        << setw(30) << left << hd.diachi 
        << setw(20) << left <<hd.tongtien
        << setw(30) << left << (hd.trangthai ? "true" : "false") << endl;
}
void xuatdshd(DS_HOADON ds) {
    cout << setw(10) << left << "Ma HD"
        << setw(20) << left << "Ten KH"
        << setw(15) << left << "SDT"
        << setw(30) << left << "Dia Chi"
        << setw(20) << left << "Tong Tien(VND)"
        << setw(30) << left << "Trang Thai" << endl;
    for (int i = 0; i < ds.n; i++) {
      
        xuat(ds.dshd[i]);
    }
}
void docHoaDon(const char* filename, DS_HOADON& hd) {
    FILE* fp;
    errno_t fp_in;
    fp_in = fopen_s(&fp, filename, "r");
    if (fp == NULL) {
        cout << "loi doc file\n"; return;
    }
    int i = 0;
    HoaDon ds;
    while (fread(&ds, sizeof(HoaDon), 1, fp) == 1 && i < MAX_HOADON)
    {
        hd.dshd[i++] = ds;
    }
    hd.n = i;
    fclose(fp);  
}
void luuHoaDon1(const char* filename, DS_HOADON& hd) {
    FILE* fp;
    errno_t fp_in;
    fp_in = fopen_s(&fp, filename, "w");
    if (fp == NULL) {
        cout << "loi doc file"; return;
    }
    for (int i = 0; i < hd.n; i++) {
        fwrite(&hd.dshd[i], sizeof(HoaDon), 1, fp);
    }
    if (fwrite == 0) {
        cout << "\nloi ghi file" << endl;
        return;
    }
    else cout << "ghi thanh cong"<<endl;
    fclose(fp);
}
void luuHoaDon(const char* filename, DS_HOADON& hd) {
    FILE* fp;
    errno_t fp_in;
    fp_in = fopen_s(&fp, filename, "a");
    if (fp == NULL) {
        cout << "Loi mo tep." << endl;
        return;
    }
    for (int i = 0; i < hd.n; i++) {
        fwrite(&hd.dshd[i], sizeof(HoaDon), 1, fp);
    }
    if (fwrite == 0) {
        cout << "\nloi luu hoa don " << endl;
        return;
    }
    else  cout << "Luu hoa don thanh cong." << endl;

    fclose(fp);
}
void xoadulieu(const char* filename) {
   
    FILE* fp = fopen(filename,"wb");
    cout << "xoa du lieu " << filename << " thanh cong!" << endl;
   fclose(fp); 
   
}
void sapXepTrangThaitrue(DS_HOADON& ds) {
    //selection sort
    //min la true
    for (int i = 0; i < ds.n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < ds.n; j++) {
            if (ds.dshd[j].trangthai && !ds.dshd[min].trangthai) {
                min = j;
            }
        }
        if (min != i) {
            HoaDon temp = ds.dshd[i];
            ds.dshd[i] = ds.dshd[min];
            ds.dshd[min] = temp;
        }
    }
}
void sapXepTrangThaifalse(DS_HOADON& ds) {
    //selection sort 
    //false la max
    for (int i = 0; i < ds.n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < ds.n; j++) {
            if (!ds.dshd[j].trangthai && ds.dshd[max].trangthai) {
                max = j;
            }
        }
        if (max != i) {
            HoaDon temp = ds.dshd[i];
            ds.dshd[i] = ds.dshd[max];
            ds.dshd[max] = temp;
        }
    }
}
void sapXeptongtienMAX(DS_HOADON& ds) {
    //sapxeptangdan
    for (int i = 1; i < ds.n; i++) {
        HoaDon key = ds.dshd[i];
        int j = i - 1;  
        while (j >= 0 && ds.dshd[j].tongtien < key.tongtien) {
            ds.dshd[j + 1] = ds.dshd[j];
            j = j - 1;
        }
        ds.dshd[j + 1] = key;
    }
}
void sapXeptongtienMIN(DS_HOADON& ds) {
    //sapxeptangdan
    for (int i = 1; i < ds.n; i++) {
        HoaDon key = ds.dshd[i];
        int j = i - 1;
        while (j >= 0 && ds.dshd[j].tongtien > key.tongtien) {
            ds.dshd[j + 1] = ds.dshd[j];
            j = j - 1;
        }
        ds.dshd[j + 1] = key;
    }
}
void sapXepMHDMIN(DS_HOADON& ds) {
    for (int i = 0; i < ds.n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < ds.n; j++) {
            if (ds.dshd[j].MaHD < ds.dshd[min].MaHD) {
                min = j;
            }
        }
        if (min != i) {
            HoaDon temp = ds.dshd[i];
            ds.dshd[i] = ds.dshd[min];
            ds.dshd[min] = temp;
        }
    }
}
void sapXepMHDMAX(DS_HOADON& ds) {
    for (int i = 0; i < ds.n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < ds.n; j++) {
            if (ds.dshd[j].MaHD > ds.dshd[max].MaHD) {
                max = j;
            }
        }
        if (max != i) {
            HoaDon temp = ds.dshd[i];
            ds.dshd[i] = ds.dshd[max];
            ds.dshd[max] = temp;
        }
    }
}
void sapXepTheoTen(DS_HOADON& ds) {
    for (int i = 0; i < ds.n - 1; i++) {
        int temp = i;
        string tenTemp = tachTen(ds.dshd[i].tenKH);
        for (int j = i + 1; j < ds.n; j++) {
          string tenKhachHangJ = tachTen(ds.dshd[j].tenKH);
            if (tenKhachHangJ < tenTemp) {
                temp = j;
                tenTemp = tenKhachHangJ;
            }
        }
        if (temp != i) {
            HoaDon tempHoaDon = ds.dshd[i];
            ds.dshd[i] = ds.dshd[temp];
            ds.dshd[temp] = tempHoaDon;
        }
    }
}
void sapXepTheoTen1(DS_HOADON& ds) {
    for (int i = 0; i < ds.n - 1; i++) {
        int temp = i;
        string tenTemp = tachTen(ds.dshd[i].tenKH);
        for (int j = i + 1; j < ds.n; j++) {
            string tenKhachHangJ = tachTen(ds.dshd[j].tenKH);
            if (tenKhachHangJ > tenTemp) {
                temp = j;
                tenTemp = tenKhachHangJ;
            }
        }
        if (temp != i) {
            HoaDon tempHoaDon = ds.dshd[i];
            ds.dshd[i] = ds.dshd[temp];
            ds.dshd[temp] = tempHoaDon;
        }
    }
}
char* tachTen(char* s) {
    char* Ten = new char[strlen(s) + 1];
    int start = 0;
    int end = strlen(s) - 1;
    while (end >= 0 && s[end] != ' ') {
        end--;
    }
    start = end + 1;
    int k = 0;
    for (int i = start; i < strlen(s); i++) {
        Ten[k++] = s[i];
    }
    Ten[k] = '\0';
    return Ten;
}
void xoahoadon(DS_HOADON& ds) {   
        int luaChon;
        bool tiepTuc = true;
        int maHDcanxoa;

        do {
            cout << "\nnhap ma can xoa:";
            nhapktrakituMHDXOA(maHDcanxoa);

            int vitri = -1;
            for (int i = 0; i < ds.n; i++) {
                if (ds.dshd[i].MaHD == maHDcanxoa) {
                    vitri = i;
                    break;
                }
            }

            if (vitri != -1) {
                cout << "------------------------------------------------------------" << endl;
                cout << "--------ban co muon xoa hoa don " << maHDcanxoa << " khong?-------------------- " << endl;
                cout << "| 1. co!                                                   |" << endl;
                cout << "| 2. khong!                                                |" << endl;
                cout << "|__________________________________________________________|" << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "Lua chon tu (1-2): ";
                nhapluachon(luaChon);

                switch (luaChon) {
                case 1: {
                    tiepTuc = false;
                    ds.n--;

                    for (int i = vitri; i < ds.n; i++) {
                        ds.dshd[i] = ds.dshd[i + 1];
                    }

                    luuHoaDon1("hoadon.txt", ds);
                    docHoaDon("hoadon.txt", ds);
                    xuatdshd(ds);

                    break;
                }
                case 2:
                    tiepTuc = false;
                    break;
                default:
                    cout << "vui long chon lai." << endl;
                    break;
                }
            }
            else {
                cout << "Khong tim thay hoa don co ma " << maHDcanxoa << " de xoa." << endl;
                cout << "ban co muon xoa tiep tuc khong?(1 : tiep tuc ,khac 1 : dung lai)" << endl;
                nhapluachon(luaChon);        
                if (luaChon != 1) {
                    tiepTuc = false;
                }
            }
        } while (tiepTuc);
}
void chinhsuahoadon(DS_HOADON& ds) {
    int luaChon;
    bool tiepTuc = true;
    int maHDcansua;

    do {
        cout << "\nnhap ma can sua:";
        nhapktrakituMHDXOA(maHDcansua);

        int vitri = -1;
        for (int i = 0; i < ds.n; i++) {
            if (ds.dshd[i].MaHD == maHDcansua) {
                vitri = i;
                break;
            }
        }

        if (vitri != -1) {
            cout << "------------------------------------------------------------" << endl;
            cout << "--------ban co muon sua hoa don " << maHDcansua << " khong?-------------------- " << endl;
            cout << "| 1. co!                                                   |" << endl;
            cout << "| 2. khong!                                                |" << endl;
            cout << "|__________________________________________________________|" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "Lua chon tu (1-2): ";
            nhapluachon(luaChon);

            switch (luaChon) {
            case 1: {
                tiepTuc = false;
                cout << "nhap ten khach hang:"; cin.ignore();
                cin.getline(ds.dshd[vitri].tenKH, 100);
                cout << "nhap so dien thoai khach hang:(+84)";
                nhaplongsodienthoai(ds.dshd[vitri].sdt);
                cout << "nhap dia chi khach hang:"; cin.ignore();
                cin.getline(ds.dshd[vitri].diachi, 100);
                cout << "nhap tong tien hoa don:";
                nhaplonggiatien(ds.dshd[vitri].tongtien);
                cout << "nhap trang thai hoa don(1 la true, 0 la false):";
                while (true) {
                    cin >> ds.dshd[vitri].trangthai;
                    if (cin.fail() || (ds.dshd[vitri].trangthai != 0 && ds.dshd[vitri].trangthai != 1)) {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Gia tri khong hop le. Chi nhan 0 hoac 1. Hay nhap lai." << endl;
                    }
                    else {
                        break;
                    }
                }
                cout << endl;

                luuHoaDon1("hoadon.txt", ds);
                docHoaDon("hoadon.txt", ds);
                xuatdshd(ds);

                break;
            }
            case 2:
                tiepTuc = false;
                break;
            default:
                cout << "vui long chon lai." << endl;
                break;
            }
        }
        else {
            cout << "Khong tim thay hoa don co ma " << maHDcansua << " de sua." << endl;
            cout << "ban co muon chinh tiep tuc khong?(1 : tiep tuc ,khac 1 : dung lai)" << endl;
            nhapluachon(luaChon);
            if (luaChon != 1) {
                tiepTuc = false;
            }
        }
    } while (tiepTuc);
}
void menu() {
    int luaChon;
    long giatien;
    DS_HOADON hd;
   /* cout << "Hoa don co san trong he thong:"<<endl;
    docHoaDon("hoadon.txt", hd);
    xuatdshd(hd);*/
    do {
        cout << "--------------------------------------------------------------------"<<endl;
        cout << "----------------------------------Menu ------------------------------" << endl;
        cout << "| 1.Nhap danh sach nhan vien        | 6. Tim kiem nhan vien         |" << endl;
        cout << "| 2.Xuat danh sach nhan vien        | 7. Ket thuc chuong trinh      |" << endl;
        cout << "| 3.Them nhan vien                  |                               |" << endl;
        cout << "| 4.Xoa nhan vien                   |                               |" << endl;
        cout << "| 5.Sua thong tin nhan vien         |                               |" << endl;
        cout << "|___________________________________________________________________|" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Lua chon tu (1-7):";
        nhapluachon(luaChon);
        switch (luaChon) {
        case 1: 
        {
            nhapdshd(hd);
            bool tiepTuc = true;
            do {
                cout << "------------------------------------------------------------" << endl;
                cout << "-----------ban co muon luu hoa don vua nhap khong?---------" << endl;
                cout << "| 1. co!                                                   |" << endl;
                cout << "| 2. khong!                                                |" << endl;
                cout << "|__________________________________________________________|" << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "Lua chon tu (1-2): ";
                nhapluachon(luaChon);
                switch (luaChon) {
                case 1: {
                    tiepTuc = false;
                    luuHoaDon("hoadon.txt", hd);  
                    docHoaDon("hoadon.txt", hd);
                    xuatdshd(hd);
                    break;
                }
                case 2:
                    tiepTuc = false;
                    xuatdshd(hd);                    
                    break;
                default:
                    cout << "vui long chon lai." << endl;
                    break;
                
                }
            } while (tiepTuc);
            break;
        }
        case 2:
        {
            xuatdshd(hd);
            break;
        }
        case 3:
        {
            luuHoaDon("hoadon.txt", hd);
            docHoaDon("hoadon.txt", hd);
            xuatdshd(hd);    
            break;
        }
        case 4: 
        {
            xoahoadon(hd);
            break;
     
            break;
        }
        case 5:
        {
            bool tieptuc = true;
            do {
                cout << "------------------------------------------------------------" << endl;
                cout << "----------------------- Sap Xep ---------------------------" << endl;
                cout << "| 1. sap xep ma hoa don                                   |" << endl;
                cout << "| 2. sap xep ten khach hang                               |" << endl;
                cout << "| 3. sap xep tong tien                                    |" << endl;
                cout << "| 4. sap xep trang thai                                   |" << endl;
                cout << "| 5. thoat                                                |" << endl;
                cout << "|_________________________________________________________|" << endl;
                cout << "------------------------------------------------------------" << endl;
                cout << "Lua chon tu (1-5): ";
                nhapluachon(luaChon);
                switch (luaChon) {
                case 1:
                {
                    do {
                        cout << "------------------------------------------------------------" << endl;
                        cout << "----------------------- Sap Xep ---------------------------" << endl;
                        cout << "| 1. tang                                                 |" << endl;
                        cout << "| 2. giam                                                 |" << endl;
                        cout << "|_________________________________________________________|" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << "Lua chon tu (1-2): ";
                        nhapluachon(luaChon);
                        switch (luaChon) {
                        case 1: {
                            tieptuc = false;
                            sapXepMHDMIN(hd);
                            xuatdshd(hd);
                            break;
                        }
                        case 2: {
                            tieptuc = false;
                            sapXepMHDMAX(hd);
                            xuatdshd(hd);
                            break;
                        }
                        default:
                            cout << "vui long chon lai." << endl;
                            break;
                        }
                    } while (tieptuc);

                    break;
                }
                case 2: {
                    bool tieptuc = true;
                    do {
                        cout << "------------------------------------------------------------" << endl;
                        cout << "----------------------- Sap Xep ---------------------------" << endl;
                        cout << "| 1. sap xep tu A-Z                                       |" << endl;
                        cout << "| 2. sap xep tu Z-A                                       |" << endl;
                        cout << "|_________________________________________________________|" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << "Lua chon tu (1-2): ";
                        nhapluachon(luaChon);
                        switch (luaChon) {
                        case 1: {
                            tieptuc = false;
                            sapXepTheoTen(hd);
                            xuatdshd(hd);
                            break;
                        }
                        case 2: {
                            tieptuc = false;
                            sapXepTheoTen1(hd);
                            xuatdshd(hd);
                            break;
                        }
                        default:
                            cout << "vui long chon lai." << endl;
                            break;
                        }
                    } while (tieptuc);
                    break;
                }
                case 3: {
                    bool tieptuc = true;
                    do {
                        cout << "------------------------------------------------------------" << endl;
                        cout << "----------------------- Sap Xep ---------------------------" << endl;
                        cout << "| 1. tang                                                 |" << endl;
                        cout << "| 2. giam                                                 |" << endl;
                        cout << "|_________________________________________________________|" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << "Lua chon tu (1-2): ";
                        nhapluachon(luaChon);
                        switch (luaChon) {
                        case 1: {
                            tieptuc = false;
                            sapXeptongtienMIN(hd);
                            xuatdshd(hd);
                            break;
                        }
                        case 2: {
                            tieptuc = false;
                            sapXeptongtienMAX(hd);
                            xuatdshd(hd);
                            break;
                        }
                        default:
                            cout << "vui long chon lai." << endl;
                            break;
                        }

                    } while (tieptuc);
                    break;
                }
                case 4: {
                    bool tieptuc = true;
                    do {
                        cout << "------------------------------------------------------------" << endl;
                        cout << "----------------------- Sap Xep ---------------------------" << endl;
                        cout << "| 1. trang thai true                                      |" << endl;
                        cout << "| 2. trang thai false                                     |" << endl;
                        cout << "|_________________________________________________________|" << endl;
                        cout << "------------------------------------------------------------" << endl;
                        cout << "Lua chon tu (1-2): ";
                        nhapluachon(luaChon);
                        switch (luaChon) {
                        case 1: {
                            tieptuc = false;
                            sapXepTrangThaitrue(hd);
                            xuatdshd(hd);
                            break;
                        }
                        case 2: {
                            tieptuc = false;
                            sapXepTrangThaifalse(hd);
                            xuatdshd(hd);
                            break;
                        }
                        default:
                            cout << "vui long chon lai." << endl;
                            break;
                        }

                    } while (tieptuc);
                    break;
                }
                case 5: {
                    break;
                }
                default:
                    cout << "vui long chon lai." << endl;
                    break;

                }
            }
            while (luaChon != 5);
            break;
        } 
        case 6:
        {
            chinhsuahoadon(hd);

            break;
        }
        
        case 7:
        {
            xoadulieu("hoadon.txt");
            break;
        }
        case 8:
            break;
        default:
            cout << "vui long chon lai." << endl;
            break;
        }
    } while (luaChon != 8);
}

