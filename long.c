#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MatHang {
	char tenMatHang[30];
	char donViTinh[10];
	int soLuong, donGia, thanhTien;
	int soTienVanChuyen;
	struct MatHang *next;
} MH;

typedef struct XuatKho {
	char tenKho[30], maPhieuXuat[10];
	int ngay, thang, nam;
	int soMatHang;
	int soTienDaThanhToan, soTienThanhToan, soTienVanChuyen, soTienThanhTien;
	struct XuatKho *next;
	MH *nextMH;
} XK;

MH* creatMH(char tenMatHang[], char donViTinh[], int soLuong, int donGia) {
	MH* newNode = (MH*)malloc(sizeof(MH));
	strcpy(newNode->tenMatHang, tenMatHang);
	strcpy(newNode->donViTinh, donViTinh);
	newNode->soLuong = soLuong;
	newNode->donGia = donGia;
	newNode->thanhTien = soLuong * donGia;
	if(strcmp(donViTinh, "Thung")) {
		if(soLuong < 20) newNode->soTienVanChuyen = 70;
		else if(soLuong <35) newNode->soTienVanChuyen = 105;
		else if(soLuong <50) newNode->soTienVanChuyen = 125;
		else newNode->soTienVanChuyen = 170;
	}
	else {
		if(soLuong <= 50) newNode->soTienVanChuyen = 50;
		else newNode->soTienVanChuyen = 125;
	}
	newNode->next = NULL;
	return newNode;
}

MH* insertMH(MH* head, char tenMatHang[], char donViTinh[], int soLuong, int donGia) {
	MH* newNode = creatMH(tenMatHang, donViTinh, soLuong, donGia);
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

XK* creatXK(char tenKho[], char maPhieuXuat[], int ngay, int thang, int nam, int soMatHang, int soTienDaThanhToan, MH *nextMH) {
	XK* newNode = (XK*)malloc(sizeof(XK));
	strcpy(newNode->tenKho, tenKho);
	strcpy(newNode->maPhieuXuat, maPhieuXuat);
	newNode->ngay = ngay;
	newNode->thang = thang;
	newNode->nam = nam;
	newNode->soMatHang = soMatHang;
	newNode->soTienDaThanhToan = soTienDaThanhToan;
	newNode->nextMH = nextMH;
	int sum1 = 0, sum2 = 0;
	MH* p = nextMH;
	while(p) {
		sum1 += p->thanhTien;
		sum2 += p->soTienVanChuyen;
		p = p->next;
	}
	newNode->soTienThanhTien = sum1;
	newNode->soTienVanChuyen = sum2;
	newNode->soTienThanhToan = sum1 + sum2;
	newNode->next = NULL;
	return newNode;
}

XK* insertXK(XK* head, char tenKho[], char maPhieuXuat[], int ngay, int thang, int nam, int soMatHang, int soTienDaThanhToan, MH *nextMH) {
	XK* newNode = creatXK(tenKho, maPhieuXuat, ngay, thang, nam, soMatHang, soTienDaThanhToan, nextMH);
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

int main() {
	XK* head = NULL;
	char tenKho[30], maPhieuXuat[10];
	int ngay, thang, nam;
	int soMatHang;
	int soTienDaThanhToan;
	char tenMatHang[30];
	char donViTinh[10];
	int soLuong, donGia, line, n, i, j;
	MH* headMH[100];
	
	while(1) {
		printf("Do Duc Long - 20215609 - 727641 - IT3040 - 2022.2\n");
		printf("** CHUONG TRINH QUAN LY PHIEU XUAT **\n");
		printf("**1. NHAP CAC PHIEU XUAT, MAT HANG **\n");
		printf("**2. IN KET QUA PHIEU XUAT VA MAT HANG **\n");
		printf("**0. Thoat **\n");
		printf("*******************************************************\n");
		printf("** NHap lua chon cua ban **\n");
		scanf("%d", &line);
		getchar();
		switch(line) {
			case 1:
				printf("Ban da chon nhap PHIEU XUAT VA MAT HANG\n");
				printf("Nhap so phieu xuat: ");
				scanf("%d", &n); getchar();
				for(i=0; i<n; i++) {
					printf("Nhap thong tin Phieu Xuat %d :\n", (i+1));
					printf("Ten kho hang: ");
					fgets(tenKho, 30, stdin); fflush(stdin);
					tenKho[strlen(tenKho)-1] = '\0';
					printf("Ma phieu xuat: ");
					fgets(maPhieuXuat, 10, stdin); fflush(stdin);
					maPhieuXuat[strlen(maPhieuXuat)-1] = '\0';
					printf("Ngay lap Phieu Xuat: \n");
					printf("Ngay: ");
					scanf("%d", &ngay); getchar();
					printf("Thang: ");
					scanf("%d", &thang); getchar();
					printf("Nam: ");
					scanf("%d", &nam); getchar();
					printf("So mat hang: ");
					scanf("%d", &soMatHang); getchar();
					headMH[i] = NULL;
					printf("Nhap ds cac mat hang:\n");
					for(j=0; j<soMatHang; j++) {
						printf("Mat hang thu %d\n", (j+1));
						
					}
				}
			case 2:
			case 0:
				printf("Ban da chon thoat chuong trinh\n");
				return 0;
			default:
				printf("Bam phim bat ki de tiep tuc\n");
				continue;
		}
	}
}
