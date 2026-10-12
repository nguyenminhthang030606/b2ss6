#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][15];
    char tenSach[MAX][50];
    int soNgayMuon[MAX];
    int tienPhat[MAX];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ================\n");
        printf("1. Them luot muon sach moi\n");
        printf("2. Hien thi danh sach muon sach\n");
        printf("3. Cap nhat so ngay muon theo Ma phieu\n");
        printf("4. Xoa luot muon sach theo Ma phieu\n");
        printf("5. Thong ke danh sach phieu muon bi phat (Qua han > 14 ngay)\n");
        printf("6. Thoat chuong trinh\n");
        printf("==============================================================================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        while (getchar() != '\n'); 

        switch (luaChon) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("Loi: He thong day, khong the them phieu muon moi!\n");
                    break;
                }
                
                printf("\n=== THEM LUOT MUON SACH MOI ===\n");
                char maTam[15];
                int biTrung;
                
                do {
                    biTrung = 0;
                    printf("Nhap ma phieu muon: ");
                    scanf("%14s", maTam);
                    while (getchar() != '\n');
                    
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], maTam) == 0) {
                            biTrung = 1;
                            printf("Loi: Ma phieu nay da ton tai. Vui long nhap ma khac!\n");
                            break;
                        }
                    }
                } while (biTrung == 1);
                
                strcpy(maPhieu[soLuong], maTam);
                
                printf("Nhap ten sach: ");
                fgets(tenSach[soLuong], sizeof(tenSach[soLuong]), stdin);
                int len = strlen(tenSach[soLuong]);
                if (len > 0 && tenSach[soLuong][len - 1] == '\n') {
                    tenSach[soLuong][len - 1] = '\0';
                }
                
                do {
                    printf("Nhap so ngay muon thuc te: ");
                    scanf("%d", &soNgayMuon[soLuong]);
                    while (getchar() != '\n');
                    
                    if (soNgayMuon[soLuong] <= 0) {
                        printf("Loi: So ngay muon phai lon hon 0!\n");
                    }
                } while (soNgayMuon[soLuong] <= 0);
                
                if (soNgayMuon[soLuong] > 14) {
                    tienPhat[soLuong] = (soNgayMuon[soLuong] - 14) * 5000;
                } else {
                    tienPhat[soLuong] = 0;
                }
                
                printf("\n--> Tien phat tu dong tinh: %d VND\n", tienPhat[soLuong]);
                printf("--> Them luot muon sach thanh cong!\n");
                
                soLuong++;
                break;
            }
            
            case 2: {
                if (soLuong == 0) {
                    printf("\nDanh sach muon sach hien dang rong!\n");
                } else {
                    printf("\n================================ DANH SACH MUON SACH ================================\n");
                    printf("%-5s | %-12s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                    printf("-------------------------------------------------------------------------------------\n");
                    
                    long tongTienPhat = 0;
                    for (int i = 0; i < soLuong; i++) {
                        printf("%-5d | %-12s | %-30s | %-10d | %-15d\n", 
                               i + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        tongTienPhat += tienPhat[i];
                    }
                    
                    printf("-------------------------------------------------------------------------------------\n");
                    printf("Tong tien phat toan he thong: %ld VND\n", tongTienPhat);
                }
                break;
            }
            
            case 3: {
                printf("\n=== CAP NHAT SO NGAY MUON ===\n");
                char maTimKiem[15];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%14s", maTimKiem);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTimKiem) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Loi: Khong tim thay phieu muon co ma: %s\n", maTimKiem);
                } else {
                    printf("Tim thay phieu muon cua sach: %s (So ngay hien tai: %d)\n", tenSach[viTri], soNgayMuon[viTri]);
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay muon thuc te moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');
                        
                        if (ngayMoi <= 0) {
                            printf("Loi: So ngay muon phai lon hon 0!\n");
                        }
                    } while (ngayMoi <= 0);
                    
                    soNgayMuon[viTri] = ngayMoi;
                    if (soNgayMuon[viTri] > 14) {
                        tienPhat[viTri] = (soNgayMuon[viTri] - 14) * 5000;
                    } else {
                        tienPhat[viTri] = 0;
                    }
                    
                    printf("\n--> Tien phat moi: %d VND\n", tienPhat[viTri]);
                    printf("--> Cap nhat so ngay muon thanh cong!\n");
                }
                break;
            }
            
            case 4: {
                printf("\n=== XOA LƯỢT MƯỢN SÁCH ===\n");
                char maXoa[15];
                printf("Nhap ma phieu muon can xoa: ");
                scanf("%14s", maXoa);
                while (getchar() != '\n');
                
                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maXoa) == 0) {
                        viTri = i;
                        break;
                    }
                }
                
                if (viTri == -1) {
                    printf("Loi: Khong tim thay phieu muon co ma: %s\n", maXoa);
                } else {
                    for (int i = viTri; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(tenSach[i], tenSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                        tienPhat[i] = tienPhat[i + 1];
                    }
                    soLuong--;
                    printf("--> Xoa phieu muon thanh cong!\n");
                }
                break;
            }
            
            case 5: {
                printf("\n=== THONG KE DANH SACH PHIEU MUON BI PHAT ===\n");
                int demQuaHan = 0;
                
                for (int i = 0; i < soLuong; i++) {
                    if (soNgayMuon[i] > 14) {
                        if (demQuaHan == 0) {
                            printf("%-5s | %-12s | %-30s | %-10s | %-15s\n", "STT", "Ma Phieu", "Ten Sach", "So Ngay", "Tien Phat (VND)");
                            printf("-------------------------------------------------------------------------------------\n");
                        }
                        printf("%-5d | %-12s | %-30s | %-10d | %-15d\n", 
                               demQuaHan + 1, maPhieu[i], tenSach[i], soNgayMuon[i], tienPhat[i]);
                        demQuaHan++;
                    }
                }
                
                if (demQuaHan == 0) {
                    printf("Khong co luot muon nao bi qua han phat!\n");
                }
                break;
            }
            
            case 6: {
                printf("\nThoat chuong trinh. Chao tam biet!\n");
                break;
            }
            
            default: {
                printf("Loi: Lua chon khong hop le. Vui long thu lai!\n");
                break;
            }
        }
    } while (luaChon != 6);

    return 0;
}