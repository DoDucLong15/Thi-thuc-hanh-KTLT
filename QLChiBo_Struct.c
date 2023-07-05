#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct DangVien {
	char sothedv[10], name[20];
	int day, month, year;
	char chucvudang[10];
	double luong, dangphi, tienphucap;
} DV;

typedef struct ChiBo {
	char nameCB[20], address[20];
	int sodangvien;
	double tongluong, tongdangphithu, chibogiulai, nopcaptren, tongtrocap;
	DV arr[MAX];
	struct ChiBo *next;
} CB;

CB* creatNode(char nameCB[], int sodangvien, double tongluong, double tongdangphithu, double tongtrocap, DV arr[]) {
	CB* newNode = (CB*)malloc(sizeof(CB));
	strcpy(newNode->nameCB, nameCB);
	newNode->sodangvien = sodangvien;
	newNode->tongluong = tongluong;
	newNode->tongdangphithu = tongdangphithu;
	newNode->tongtrocap = tongtrocap;
	newNode->chibogiulai = tongdangphithu*70/100;
	newNode->nopcaptren = tongdangphithu*30/100;
	int i;
	for(i=0; i<sodangvien; i++) newNode->arr[i] = arr[i];
	newNode->next = NULL;
	return newNode;
}

CB* insertToLast(CB* head, char nameCB[], int sodangvien, double tongluong, double tongdangphithu, double tongtrocap, DV arr[]) {
	CB* newNode = creatNode(nameCB, sodangvien, tongluong, tongdangphithu, tongtrocap, arr);
	if(head==NULL) head = newNode;
	else {
		CB* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void show(CB* head) {
	CB* p = head;
	while(p) {
		printf("Ten Chi bo: %s\n", p->nameCB);
		printf("So Dang vien: %d\n", p->sodangvien);
		printf("Tong Luong: %.2lf\n", p->tongluong);
		printf("Tong thu Dang phi: %.2lf\n", p->tongdangphithu);
		printf("Tong nop Dang phi cap tren: %.2lf\n", p->nopcaptren);
		printf("Tong tro Cap chuc vu: %.2lf\n", p->tongtrocap);
		printf("Bang Bang Thu Dang Phi:\n");
		printf("%-10s%-20s%-13s%-10s%-10s%-10s%-10s%-10s\n", "sothe", "HotenDV", "Ngayvaodang", "Tuoidang", "Chucvu", "Trocap", "Luong", "Dangphi");
		int i;
		for(i=0; i<p->sodangvien; i++) {
			printf("%-10s%-20s%d-%d-%d%-5s%-10d%-10s%-10.2lf%-10.2lf%-10.2lf", p->arr[i].sothedv, p->arr[i].name, p->arr[i].day, p->arr[i].month, p->arr[i].year," ", 2023-p->arr[i].year, p->arr[i].chucvudang, p->arr[i].tienphucap, p->arr[i].luong, p->arr[i].dangphi);
			
		}
		p = p->next;
		printf("\n\n\n");
		printf("-------------------------------------------------------------\n");
	}
}

int main() {
	CB* head = NULL;
	char sothedv[10], name[20];
	int day, month, year, n, i;
	char chucvudang[10];
	double luong;
	DV arr[MAX];
	char nameCB[20];
	int sodangvien;
	double tongluong, tongdangphithu, chibogiulai, nopcaptren, tongtrocap;
	
	while(1) {
		printf("CHUONG TRINH QUAN LY Chi bo - Dang Vien\n");
		printf("1. Nhap chi bo\n");
		printf("2. In ket qua danh sach Chi bo Dang vien\n");
		printf("3. Thoat\n");
		printf("************************************************\n");
		printf("Nhap lua chon\n");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1:
				tongluong = 0;
				tongdangphithu = 0;
				tongtrocap = 0;
				printf("\nBan da chon nhap Chi bo Dang Vien!\n");
				printf("\nTen Chi bo: ");
				fgets(nameCB, 20, stdin); fflush(stdin);
				nameCB[strlen(nameCB)-1] = '\0';
				printf("\nSo dang vien: ");
				scanf("%d", &sodangvien); getchar();
				printf("\nNhap danh sach dang vien:");
				for(i=0; i<sodangvien; i++) {
					printf("\nDang vien thu %d", (i+1));
					printf("\n\t\t\tSo the: ");
					fgets(sothedv, 10, stdin); fflush(stdin);
					sothedv[strlen(sothedv)-1] = '\0';
					strcpy(arr[i].sothedv,sothedv);
					printf("\n\t\t\tTen Dang vien: ");
					fgets(name, 20, stdin); fflush(stdin);
					name[strlen(name)-1] = '\0';
					strcpy(arr[i].name, name);
					printf("\n\t\t\tNgay vao dang:");
					printf("\n\t\t\tNgay: ");
					scanf("%d", &day); getchar();
					printf("\t\t\tThang: ");
					scanf("%d", &month); getchar();
					printf("\t\t\tNam: ");
					scanf("%d", &year); getchar();
					arr[i].day = day; arr[i].month = month; arr[i].year = year;
					printf("\n\t\t\tLuong: ");
					scanf("%lf", &luong); getchar();
					arr[i].luong = luong;
					printf("\n\t\t\tChuc vu: ");
					fgets(chucvudang, 10, stdin); fflush(stdin);
					chucvudang[strlen(chucvudang)-1] = '\0';
					strcpy(arr[i].chucvudang, chucvudang);
					arr[i].dangphi = luong/100;
					if(strcmp(chucvudang,"BiThu")==0) arr[i].tienphucap = luong*0.5/100;
					else if(strcmp(chucvudang,"Pbthu")==0) arr[i].tienphucap = luong*0.25/100;
					else if(strcmp(chucvudang,"Uyvien")==0) arr[i].tienphucap = luong*0.15/100;
					else arr[i].tienphucap = 0;
					tongluong+=luong;
					tongdangphithu+=arr[i].dangphi;
					tongtrocap+=arr[i].tienphucap;
				}
				head = insertToLast(head, nameCB, sodangvien, tongluong, tongdangphithu, tongtrocap, arr);
				break;
			case 2:
				printf("Ban da chon xuat DS Chi bo, Dang vien!\n");
				printf("-------------------------------------------------------------\n");
				show(head);
				break;
			case 3:
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	return 0;
}
