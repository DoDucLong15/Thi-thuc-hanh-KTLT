#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct MatHang {
	char* tenMatHang;
	char* donViTinh;
	int soLuong;
	int donGia;
	int thanhTien;
	int tienVanChuyen;
	struct MatHang* next;
} MH;

typedef struct XuatKho {
	char* tenKho;
	char* maPhieuXuat;
	int ngay, thang, nam;
	int soMatHang;
	int soTienDaThanhToan;
	int soTienPhaiThanhToan;
	int soTienVanChuyen;
	struct XuatKho* next;
	MH* one; //tro den mat hang thu nhat
} XK;

MH* creatMatHang(char* tenMatHang, char* donViTinh, int soLuong, int donGia) {
	MH* newNode = (MH*)malloc(sizeof(MH));
	newNode->tenMatHang = tenMatHang;
	newNode->donViTinh = donViTinh;
	newNode->soLuong = soLuong;
	newNode->donGia = donGia;
	newNode->thanhTien = soLuong * donGia;
	if(strcmp(donViTinh, "Thung")==0) {
		if(soLuong<20) newNode->tienVanChuyen = 70;
		else if(soLuong<35) newNode->tienVanChuyen = 105;
		else if(soLuong<50) newNode->tienVanChuyen = 125;
		else newNode->tienVanChuyen = 170;
	}
	else {
		if(soLuong<=50) newNode->tienVanChuyen = 50;
		else newNode->tienVanChuyen = 125;
	}
	newNode->next = NULL;
	return newNode;
}

MH* insertMH(MH* head, char* tenMatHang, char* donViTinh, int soLuong, int donGia) {
	MH* newNode = creatMatHang(tenMatHang, donViTinh, soLuong, donGia);
	if(head==NULL) {
		head = newNode;
	}
	else {
		MH* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

XK* creatXuatKho(char* tenKho, char* maPhieuXuat, int ngay, int thang, int nam, int soMatHang, int soTienDaThanhToan, MH* one) {
	XK* newNode = (XK*)malloc(sizeof(XK));
	newNode->tenKho = tenKho;
	newNode->maPhieuXuat = maPhieuXuat;
	newNode->ngay = ngay;
	newNode->thang = thang;
	newNode->nam = nam;
	newNode->soMatHang = soMatHang;
	newNode->soTienDaThanhToan = soTienDaThanhToan;
	newNode->one = one;
	
	int soTienPhaiThanhToan = 0, soTienVanChuyen = 0;
	MH* p = one;
	while(p) {
		soTienPhaiThanhToan += p->thanhTien;
		soTienVanChuyen += p->tienVanChuyen;
		p = p->next;
	}
	newNode->soTienPhaiThanhToan = soTienPhaiThanhToan;
	newNode->soTienVanChuyen = soTienVanChuyen;
	newNode->next = NULL;
	return newNode;
}

XK* insertXK(XK* head, char* tenKho, char* maPhieuXuat, int ngay, int thang, int nam, int soMatHang, int soTienDaThanhToan, MH* one) {
	XK* newNode = creatXuatKho(tenKho, maPhieuXuat, ngay, thang, nam, soMatHang, soTienDaThanhToan, one);
	if(head==NULL) {
		head = newNode;
	}
	else {
		XK* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void show(XK* headXK) {
	printf("Ban da chon IN RA PHIEU XUAT!\n\n");
	XK* p = headXK;
	int sumThanhTien = 0, sumVanChuyen = 0, sumPhaiThanhToan = 0, sumDaThanhToan = 0;
	while(p) {
		printf("\tTen kho hang: %s\n", p->tenKho);
		printf("\tNgay %d thang %d nam %d\n", p->ngay, p->thang, p->nam);
		printf("\tSo mat hang: %d\n", p->soMatHang);
		printf("\tDa thanh toan: %d\n", p->soTienDaThanhToan);
		printf("\tTong thanh tien: %d\n", p->soTienPhaiThanhToan);
		printf("\tTong van chuyen: %d\n", p->soTienVanChuyen);
		printf("\tTong phai thanh toan: %d\n", p->soTienPhaiThanhToan + p->soTienVanChuyen);
		if(p->soTienDaThanhToan >= (p->soTienPhaiThanhToan+p->soTienVanChuyen)) 
			printf("\tTinh trang thanh toan: \t\t Chuyen Phieu Xuat sau so tien: %d\n", p->soTienDaThanhToan - (p->soTienPhaiThanhToan+p->soTienVanChuyen));
		else printf("\tTinh trang thanh toan: \t\t Thanh toan thieu so tien: %d\n", p->soTienPhaiThanhToan+p->soTienVanChuyen-p->soTienDaThanhToan);
		printf("\t\tChi tiet cac Mat Hang:\n");
		printf("\t%-20s%-10s%-6s%-10s%-15s%-15s%-15s\n", "Ten mat hang", "DonVT", "soL", "dongia", "Thanhtien", "VanChuyen", "Cong");
		MH* q = p->one;
		while(q) {
			printf("\t%-20s%-10s%-6d%-10d%-15d%-15d%-15d\n", q->tenMatHang, q->donViTinh, q->soLuong, q->donGia, q->thanhTien, q->tienVanChuyen, q->thanhTien+q->tienVanChuyen);
			q = q->next;
		}
		printf("\n\n");
		sumThanhTien += p->soTienPhaiThanhToan;
		sumVanChuyen += p->soTienVanChuyen;
		sumPhaiThanhToan += p->soTienPhaiThanhToan + p->soTienVanChuyen;
		sumDaThanhToan += p->soTienDaThanhToan;
		p = p->next;
	}
	printf("\tTong Thanh tien cac Phieu xuat: %d\n", sumThanhTien);
	printf("\tTong Van chuyen cac Phieu Xuat: %d\n", sumVanChuyen);
	printf("\tTong phai Thanh toan cac Phieu xuat: %d\n", sumPhaiThanhToan);
	printf("\tTong da Thanh toan cac Phieu xuat: %d\n", sumDaThanhToan);
	if(sumDaThanhToan < sumPhaiThanhToan) printf("Tinh trang thanh toan: \tThanh toan thieu so tien: %d\n", sumPhaiThanhToan - sumDaThanhToan);
	else printf("Tinh trang thanh toan: \tChuyen Phieu xuat sau so tien: %d\n", sumDaThanhToan - sumPhaiThanhToan);
	printf("Bam phim bat ky de tiep tuc!");
	printf("\n\n");
}

int main() {
	XK* headXK = NULL;
	MH* headMH[100];
	char tenKho[100][30];
	char maPhieuXuat[100][30];
	char tenMatHang[100][30], donViTinh[100][30];
	int ngay, thang, nam, soMatHang, soTienDaThanhToan, line, n, i, k = 0;
	
	while(1) {
		printf("Do Duc Long - 20215609 - 727641 - IT3040 - 2022.2\n");
		printf("** CHUONG TRINH QUAN LY PHIEU XUAT **\n");
		printf("**1. Nhap cac phieu xuat, mat hang **\n");
		printf("**2. In ket qua phieu xuat va mat hang **\n");
		printf("**0. Thoat                         **\n");
		printf("************************************\n");
		printf("**  Nhap lua chon cua ban    **\n");
		scanf("%d", &line);
		getchar();
		switch(line) {
			case 1:
				printf("Ban da chon nhap PHIEU XUAT VA MAT HANG\n");
				printf("Ban nhap bao nhieu phieu xuat: ");
				scanf("%d", &n); getchar();
				for(i=0; i<n; i++) {
					printf("Nhap thong tin phieu xuat %d\n", (i+1));
					printf("\tTen Kho hang: ");
					fgets(tenKho[i], 30, stdin); fflush(stdin);
					tenKho[i][strlen(tenKho[i])-1] = '\0';
					printf("\n\tMa phieu xuat: ");
					fgets(maPhieuXuat[i], 30, stdin); fflush(stdin);
					maPhieuXuat[i][strlen(maPhieuXuat[i])-1] = '\0';
					printf("\nNgay lap phieu xuat: \n");
					printf("\n\tNgay: ");
					scanf("%d", &ngay); getchar();
					printf("\n\tThang: ");
					scanf("%d", &thang); getchar();
					printf("\n\tNam: ");
					scanf("%d", &nam); getchar();
					printf("\n\tSo mat hang: ");
					scanf("%d", &soMatHang); getchar();
					
					int soLuong, donGia, j;
					headMH[i] = NULL;
					printf("\n\tNhap ds cac mat hang:\n");
					for(j=0; j<soMatHang; j++) {
						printf("\tMat hang thu %d\n", (j+1));
						printf("\t\tTen mat hang:");
						fgets(tenMatHang[k], 30, stdin); fflush(stdin);
						tenMatHang[k][strlen(tenMatHang[k])-1] = '\0';
						printf("\n\t\tDo vi tinh: ");
						fgets(donViTinh[k], 30, stdin); fflush(stdin);
						donViTinh[k][strlen(donViTinh[k])-1] = '\0';
						printf("\n\t\tSo luong: ");
						scanf("%d", &soLuong); getchar();
						printf("\n\t\tDon gia: ");
						scanf("%d", &donGia); getchar();
						headMH[i] = insertMH(headMH[i], tenMatHang[k], donViTinh[k], soLuong, donGia);
						k++;
					}
					printf("\tSo tien da thanh toan: ");
					scanf("%d", &soTienDaThanhToan); getchar();
					headXK = insertXK(headXK, tenKho[i], maPhieuXuat[i], ngay, thang, nam, soMatHang, soTienDaThanhToan, headMH[i]);
				}
				break;
			case 2:
				show(headXK);
				break;
			case 0:
				printf("Ban da chon thoat chuong trinh\n");
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	return 0;
}
