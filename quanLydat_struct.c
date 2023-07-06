#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct miengdat {
	char maMD[10];
	int donGia;
	char hinh[20];
	double dai, rong, daylon, daynho, chieucao, day, canh;
	double area;
	double thanhTien, datCoc, giamGia;
} MD;

typedef struct company {
	char name[30];
	char address[30];
	int n;
	MD ds[MAX];
	struct company* next;
} company;

company* creatNode(char name[], char address[], int n, MD ds[]) {
	company* newNode = (company*)malloc(sizeof(company));
	strcpy(newNode->name, name);
	strcpy(newNode->address,address);
	newNode->n = n;
	int i;
	for(i=0; i<n; i++) newNode->ds[i] = ds[i];
	newNode->next = NULL;
	return newNode;
}

company* insertToLast(company* head, char name[], char address[], int n, MD ds[]){
	company* newNode = creatNode(name,address,n,ds);
	if(head==NULL) head = newNode;
	else {
		company* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void show(company* head) {
	company* p = head;
	double tongDonGia=0, tongS=0, tongThanhTien=0, tongDatCoc=0, tongGiamGia=0;
	while(p) {
		int i;
		printf("\n\nTen cong ty: %s\n", p->name);
		printf("Dia chi: %s\n", p->address);
		printf("So mieng dat: %d\n", p->n);
		for(i=0; i<p->n; i++) {
			tongDonGia+=p->ds[i].donGia;
			tongS+=p->ds[i].area;
			tongThanhTien+=p->ds[i].thanhTien;
			tongDatCoc+=p->ds[i].datCoc;
			tongGiamGia+=p->ds[i].giamGia;
		}
		printf("Don gia trung binh: %.1lf\n", tongDonGia/p->n);
		printf("Tong dien tich: %.1lf\n", tongS);
		printf("Tong Thanh tien: %.1lf\n", tongThanhTien);
		printf("Tong Dat Coc: %.1lf\n", tongDatCoc);
		printf("Tong giam gia: %.1lf\n", tongGiamGia);
		printf("\t\t\tChi tiet cac Mieng Dat:\n");
		printf("%-15s%-15s%-15s%-15s%-15s%-15s%-15s\n", "MaMD", "Hinh Dang", "Don Gia", "Dien tich", "Thanh tien", "Giam gia", "Dat coc");
		for(i=0; i<p->n; i++) {
			printf("%-15s%-15s%-15d%-15.1lf%-15.1lf%-15.1lf%-15.1lf\n", p->ds[i].maMD, p->ds[i].hinh, p->ds[i].donGia, p->ds[i].area, p->ds[i].thanhTien, p->ds[i].giamGia, p->ds[i].datCoc);
		}
		printf("\n\n");
		p = p->next;
	}
}

int main() {
	company* head = NULL;
	int line, n, i, companyNub, j;
	char name[30], address[30], ma[10], hinh[20];
	
	double a,b,c;
	MD arr[MAX];
	
	while(1) {
		printf("Do Duc Long - 20215619\n");
		printf("**		CHUONG TRINH QUAN LY BAT DONG SAN	**\n");
		printf("**	1. Nhap thong tin cong ty				**\n");
		printf("**	2. In ket qua dien tich mieng dat		**\n");
		printf("**	3. Thoat								**\n");
		printf("**********************************************\n");
		
		printf("**		Nhap lua chon cua ban				**\n");
		scanf("%d", &line);
		getchar();
		switch(line) {
			case 1:
				printf("Ban da chon nhap MIENG DAT VA DO DAI !\n");
				printf("Nhap so cong ty: ");
				scanf("%d", &companyNub); getchar();
				for(j=0; j<companyNub; j++) {
					printf("Nhap thong tin Cong ty %d\n", (j+1));
					printf("Ten cong ty: ");
					fgets(name, 30, stdin); fflush(stdin);
					name[strlen(name)-1] = '\0';
					printf("\nDia chi cong ty: ");
					fgets(address, 30, stdin); fflush(stdin);
					address[strlen(address)-1] = '\0';
					printf("\nSo Mieng Dat: ");
					scanf("%d", &n);
					getchar();
					printf("\nNhap ds cac mieng dat:\n");
					for(i=0; i<n; i++) {
						printf("Ma mieng dat thu (MD001,MD002,MD003) %d: ", i+1); 
						fgets(ma, 10, stdin); fflush(stdin);
						ma[strlen(ma)-1] = '\0';
						strcpy(arr[i].maMD,ma);
						if(strcmp(ma,"MD001")==0) arr[i].donGia = 50;
						else if(strcmp(ma,"MD002")==0) arr[i].donGia = 30;
						else arr[i].donGia = 10;
						printf("\nDon gia theo m^2: %d\n", arr[i].donGia);
						printf("Mieng dat Hinh(Vuong, Thang, Tamgiac, HCNhat): ");
						fgets(hinh, 20, stdin); fflush(stdin);
						hinh[strlen(hinh)-1] = '\0';
						strcpy(arr[i].hinh,hinh);
						if(strcmp(hinh,"Vuong")==0){
							printf("\nCanh hinh vuong: ");
							scanf("%lf", &a);
							getchar();
							arr[i].canh = a;
							arr[i].area = a*a;
							arr[i].thanhTien = arr[i].area * arr[i].donGia;
							arr[i].giamGia = 0;
						}
						else if(strcmp(hinh,"Thang")==0) {
							printf("\nDay nho: ");
							scanf("%lf", &a); getchar();
							arr[i].daynho = a;
							printf("\nDay lon: ");
							scanf("%lf", &b); getchar();
							arr[i].daylon = b;
							printf("\nChieu cao: ");
							scanf("%lf", &c); getchar();
							arr[i].chieucao = c;
							arr[i].area = (a+b)*c/2;
							arr[i].thanhTien = arr[i].area * arr[i].donGia;
							arr[i].giamGia = arr[i].thanhTien*10/100;
						}
						else if(strcmp(hinh,"Tamgiac")==0) {
							printf("\nChieu cao: ");
							scanf("%lf", &a); getchar();
							arr[i].chieucao = a;
							printf("\nCanh day: ");
							scanf("%lf", &b); getchar();
							arr[i].day = b;
							arr[i].area = a*b/2;
							arr[i].thanhTien = arr[i].area * arr[i].donGia;
							arr[i].giamGia = arr[i].thanhTien*10/100;
						}
						else if(strcmp(hinh,"HCNhat")==0) {
							printf("\nChieu dai: ");
							scanf("%lf", &a); getchar();
							arr[i].dai = a;
							printf("\nChieu rong: ");
							scanf("%lf", &b); getchar();
							arr[i].rong = b;
							arr[i].area = a*b;
							arr[i].thanhTien = arr[i].area * arr[i].donGia;
							arr[i].giamGia = 0;
						}
						if(strcmp(ma,"MD001")==0) arr[i].datCoc = arr[i].thanhTien*70/100;
						else if(strcmp(ma,"MD002")==0) arr[i].datCoc = arr[i].thanhTien*50/100;
						else arr[i].datCoc = arr[i].thanhTien*30/100;
						printf("\nDien tich: %.1lf\n", arr[i].area);
						printf("Thanh tien: %.1lf\n", arr[i].thanhTien);
						printf("Tien dat coc: %.1lf\n", arr[i].datCoc);
						printf("Giam gia: %.1lf\n", arr[i].giamGia);
					}
					head = insertToLast(head,name,address,n,arr);
				}
				break;
			case 2:
				printf("Ban da chon IN RA MIENG DAT !\n");
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
