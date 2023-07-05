#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NhanVien {
	char maNV[10];
	char nameNV[30];
	int namSinh;
	double hesoLuong;
	char chucDanh[10];
	double PCCV;
	struct NhanVien *next;
} NV;

typedef struct PhongBan {
	char name[30];
	char diachi[30];
	int soluongnv;
	double luongtoithieu;
	double tongLuong, CDP;
	struct PhongBan *next;
	NV* one;
} PB;

NV* creatNV(char maNV[], char nameNV[], double hesoLuong, char chucDanh[]) {
	NV* newNode = (NV*)malloc(sizeof(NV));
	strcpy(newNode->maNV, maNV);
	strcpy(newNode->nameNV, nameNV);
	newNode->hesoLuong = hesoLuong;
	strcpy(newNode->chucDanh, chucDanh);
	if(strcmp(chucDanh, "GVCC")==0) newNode->PCCV = 2000;
	else if(strcmp(chucDanh, "GVC")==0) newNode->PCCV = 1500;
	else if(strcmp(chucDanh, "GV")==0) newNode->PCCV = 1000;
	else if(strcmp(chucDanh, "CBKT")==0) newNode->PCCV = 750;
	else if(strcmp(chucDanh, "CBHC")==0) newNode->PCCV = 500;
	newNode->next = NULL;
	return newNode;
}

NV* insertNV(NV* head, char maNV[], char nameNV[], double hesoLuong, char chucDanh[]) {
	NV* newNode = creatNV(maNV, nameNV, hesoLuong, chucDanh);
	if(head==NULL) {
		head = newNode;
	}
	else {
		NV* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

PB* creatPB(char name[30], char diachi[30], int soluongnv, double luongtoithieu, NV* one) {
	PB* newNode = (PB*)malloc(sizeof(PB));
	strcpy(newNode->name, name);
	strcpy(newNode->diachi, diachi);
	newNode->soluongnv = soluongnv;
	newNode->luongtoithieu = luongtoithieu;
	newNode->one = one;
	
	double sum = 0.0;
	NV* p = one;
	while(p) {
		sum += p->hesoLuong * luongtoithieu + p->PCCV;
		p = p->next;
	}
	newNode->tongLuong = sum;
	newNode->CDP = sum/100;
	newNode->next = NULL;
	return newNode;
}

PB* insertPB(PB* head, char name[30], char diachi[30], int soluongnv, double luongtoithieu, NV* one) {
	PB* newNode = creatPB(name, diachi, soluongnv, luongtoithieu, one);
	if(head==NULL) {
		head = newNode;
	}
	else {
		PB* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showPB(PB *head) {
	PB* p = head;
	while(p) {
		printf("Ten phong ban: %s\n", p->name);
		printf("Dia chi: %s\n", p->diachi);
		printf("Luong TT: %.0lf\n", p->luongtoithieu);
		printf("Tong luong: %.0lf\n", p->tongLuong);
		printf("Tong CD phi: %.2lf\n", p->CDP);
		printf("Bang luong nhan vien\n");
		
		NV* q = p->one;
		printf("%-10s%-30s%-15s%-10s%-10s%-10s%-10s%-15s\n", "MaNV", "HotenNV", "Chucdanh", "PCCV", "HesoL", "Luong", "CDP", "Con nhan");
		while(q) {
			double a = q->hesoLuong*p->luongtoithieu + q->PCCV;
			printf("%-10s%-30s%-15s%-10.0lf%-10.2lf%-10.2lf%-10.2lf%-15.2lf\n", q->maNV, q->nameNV, q->chucDanh, q->PCCV, q->hesoLuong, a, a/100, a*99/100);
			q = q->next;
		}	
		p = p->next;
	}
}

int main() {
	PB* head = NULL;
	char name[30], diachi[30], maNV[10], nameNV[30], chucDanh[10];
	int soluongnv, choose, n, k=0, i, j, namSinh;
	double luongtoithieu, hesoLuong;
	NV* headNV[100];
	
	while(1) {
		printf("Do Duc Long - 20215609\n");
		printf("** CHUONG TRINH QUAN LY PHONG BAN - NHAN VIEN **\n");
		printf("** 1. NHap cac phong ban **\n");
		printf("** 2. In ket qua ds Phong ban **\n");
		printf("** 0. Thoat **\n");
		printf("*****************************************************\n");
		printf("** NHap lua chon cua ban **\n");
		scanf("%d", &choose); getchar();
		switch(choose) {
			case 1:
				printf("Ban da chon nhap thong tin Phong Ban - NhanVien\n\n");
				printf("Nhap so phong ban: ");
				scanf("%d", &n); getchar();
				for(i=0; i<n; i++) {
					printf("Nhap thong tin phong ban thu %d:\n", (i+1));
					printf("\t\tTen Phong Ban: ");
					fgets(name, 30, stdin); fflush(stdin);
					name[strlen(name)-1] = '\0';
					printf("\n\t\tDia chi: ");
					fgets(diachi, 30, stdin); fflush(stdin);
					diachi[strlen(diachi)-1] = '\0';
					printf("\n\t\tLuong toi thieu: ");
					scanf("%lf", &luongtoithieu); getchar();
					printf("\n\t\tSo nhan vien: ");
					scanf("%d", &soluongnv); getchar();
					headNV[i] = NULL;
					printf("\n\t\tNhap ds NhanVien:\n");
					for(j=0; j<soluongnv; j++) {
						printf("\t\tNhan vien thu %d\n", (j+1));
						printf("\t\t\tMANV: ");
						fgets(maNV, 10, stdin); fflush(stdin);
						maNV[strlen(maNV)-1] = '\0';
						printf("\n\t\t\tHo ten Nhan vien: ");
						fgets(nameNV, 30, stdin); fflush(stdin);
						nameNV[strlen(nameNV)-1] = '\0';
						printf("\n\t\t\tNhap Nam sinh: ");
						scanf("%d", &namSinh); getchar();
						printf("\n\t\t\tNhap HS Luong: ");
						scanf("%lf", &hesoLuong); getchar();
						printf("\n\t\t\tNhap chuc danh: ");
						fgets(chucDanh, 10, stdin); fflush(stdin);
						chucDanh[strlen(chucDanh)-1] = '\0';
						headNV[i] = insertNV(headNV[i], maNV, nameNV, hesoLuong, chucDanh);
						printf("\n");
					}
					head = insertPB(head, name, diachi, soluongnv, luongtoithieu, headNV[i]);
				}
				break;
			case 2:
				printf("Ban da chon xuat danh sach phong ban\n");
				showPB(head);
				break;
			case 0:
				printf("Ban da chon thoat chuong trinh\n");
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
}
