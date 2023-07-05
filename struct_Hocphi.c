#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct Monhoc {
	char maMH[10];
	int sotinchi, sotinchiLT, sotinchiBT, sotinchiTH;
	double hocphi, sotinchiHP;
	char loaigio[20], khoiluong[20];
} MHoc;

typedef struct HocVien {
	char maHV[10];
	char name[20];
	int somonhoc, tienhoc1tin, tienhocdanop;
	double tienhocphainop;
	MHoc ds[MAX];
	struct HocVien* next;
} HV;

HV* creatNode(char maHV[], char name[], int somonhoc, int tienhoc1tin,int tienhocphainop, int tienhocdanop, MHoc ds[]) {
	HV* newNode = (HV*)malloc(sizeof(HV));
	strcpy(newNode->name, name);
	strcpy(newNode->maHV, maHV);
	newNode->somonhoc = somonhoc;
	newNode->tienhoc1tin = tienhoc1tin;
	newNode->tienhocphainop = tienhocphainop;
	newNode->tienhocdanop = tienhocdanop;
	int i;
	for(i=0; i<somonhoc; i++) newNode->ds[i] = ds[i];
	newNode->next = NULL;
	return newNode;
}

HV* insertToLast(HV* head, char maHV[], char name[], int somonhoc, int tienhoc1tin,int tienhocphainop, int tienhocdanop, MHoc ds[]) {
	HV* newNode = creatNode(maHV, name, somonhoc, tienhoc1tin, tienhocphainop, tienhocdanop, ds);
	if(head==NULL) head = newNode;
	else {
		HV* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void show(HV* head) {
	HV* p = head;
	while(p) {
		printf("Ten sinh vien: %s\n", p->name);
		printf("Ma sinh vien: %s\n", p->maHV);
		printf("So mon hoc: %d\n", p->somonhoc);
		printf("So tien 1 TC: %d\n", p->tienhoc1tin);
		printf("Phai nop: %.0lf\n", p->tienhocphainop);
		printf("Da nop dot 1: %d\n", p->tienhocdanop);
		int thieu = p->tienhocphainop - p->tienhocdanop;
		printf("To tien thieu: %d\n", thieu);
		if(thieu>0) printf("Tinh trang nop hoc phi: Con thieu\n");
		else printf("Tinh trang nop hoc phi: Nop du\n");
		printf("Chi tiet hoc phi cac mon hoc:\n");
		printf("%-20s%-20s%-20s%-30s\n", "Ma MH", "Loai gio", "Khoi Luong", "HocPhiPhaiNop");
		int i;
		for(i=0; i<p->somonhoc; i++) {
			printf("%-20s%-20s", p->ds[i].maMH, p->ds[i].loaigio);
			printf("%d(%d-%d-%d-%d)\t\t%-30.0lf\n", p->ds[i].sotinchi, p->ds[i].sotinchiLT, p->ds[i].sotinchiBT, p->ds[i].sotinchiTH, p->ds[i].sotinchi*2, p->ds[i].hocphi);
		}
		printf("\n\n");
		
		p = p->next;
	}
}

int main() {
	HV* head = NULL;
	int n, somonhoc, sotien1tin, i, sotinchi, sotinchiLT, sotinchiBT, sotinchiTH, tienhocdanop;
	double tienhocphainop;
	char name[20], maMH[10], maHV[10];
	MHoc arr[MAX];
	
	while(1) {
		printf("Do Duc Long - 20215609\n");
		printf("CHUONG TRINH QUAN LY HOC PHI\n");
		printf("1. Nhap sinh vien va mon hoc\n");
		printf("2. In danh sach sinh vien va hoc phi cac mon\n");
		printf("3. Thoat\n");
		
		printf("Nhap lua chon cua ban\n");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1:
				tienhocphainop = 0;
				printf("Ten sinh vien: ");
				fgets(name, 20, stdin); fflush(stdin);
				name[strlen(name)-1] = '\0';
				printf("\nMa hoc vien: ");
				fgets(maHV, 10, stdin); fflush(stdin);
				maHV[strlen(maHV)-1] = '\0';
				printf("\nSo mon hoc: ");
				scanf("%d", &somonhoc);
				getchar();
				printf("\nSo tien mot tin chi: ");
				scanf("%d", &sotien1tin);
				getchar();
				for(i=0; i<somonhoc; i++) {
					printf("Mon hoc thu %d\n", i+1);
					printf("Ma mon hoc: ");
					fgets(maMH, 20, stdin); fflush(stdin);
					maMH[strlen(maMH)-1] = '\0';
					strcpy(arr[i].maMH,maMH);
					printf("\n\t\tSo tin chi: ");
					scanf("%d", &sotinchi); getchar();
					arr[i].sotinchi = sotinchi;
					printf("\n\t\tNhap tin chi LT: ");
					scanf("%d", &sotinchiLT); getchar();
					arr[i].sotinchiLT = sotinchiLT;
					printf("\n\t\tNhap tin chi BT: ");
					scanf("%d", &sotinchiBT); getchar();
					arr[i].sotinchiBT = sotinchiBT;
					printf("\n\t\tNhap tin chi TH: ");
					scanf("%d", &sotinchiTH); getchar();
					arr[i].sotinchiTH = sotinchiTH;
					arr[i].sotinchiHP = (double)sotinchiLT + (double)sotinchiBT + (double)sotinchiTH*1.5;
					arr[i].hocphi = sotien1tin * arr[i].sotinchiHP;
					tienhocphainop+=arr[i].hocphi;
					//
					if(sotinchiLT>0 && sotinchiBT>0 && sotinchiTH>0) strcpy(arr[i].loaigio,"LT-BT-TH");
					if(sotinchiLT>0 && sotinchiBT==0 && sotinchiTH>0) strcpy(arr[i].loaigio,"LT-TH");
					if(sotinchiLT>0 && sotinchiBT>0 && sotinchiTH==0) strcpy(arr[i].loaigio,"LT-BT");
					
				}
				printf("\nHoc phi da nop: ");
				scanf("%d", &tienhocdanop); getchar();
				head = insertToLast(head, maHV, name, somonhoc, sotien1tin, tienhocphainop, tienhocdanop, arr);
				break;
			case 2:
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
