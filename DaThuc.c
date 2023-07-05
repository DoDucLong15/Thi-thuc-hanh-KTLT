#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct DaThuc {
	char name[5];
	int m;
	int heso[MAX];
	double x, GT;
	struct DaThuc *next;
} DT;

DT* creatNode(char name[], int m, int heso[], double x) {
	DT* newNode = (DT*)malloc(sizeof(DT));
	strcpy(newNode->name, name);
	newNode->m = m;
	
	double result = 0;
	int i;
	for(i=0; i<=m; i++) {
		newNode->heso[i] = heso[i];
		result += (double)heso[i] * pow(x,i);
	}
	newNode->GT = result;
	newNode->x = x;
	newNode->next = NULL;
	return newNode;
}

DT* insertToLast(DT* head, char name[], int m, int heso[], double x) {
	DT* newNode = creatNode(name, m, heso, x);
	if(head==NULL) {
		head = newNode;
	}
	else {
		DT* p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showDS(DT* head) {
	DT* p = head;
	while(p) {
		printf("Da thuc: %s(x) = ", p->name);
		int i;
		for(i=p->m; i>=0; i--) {
			if(i==p->m && p->heso[i] != 0) {
				if(p->heso[i]>0) printf("%d*x^%d ", p->heso[i], i);
				else printf("- %d*x^%d ", -p->heso[i], i);
				continue;
			}
			if(i==0 && p->heso[i] != 0) {
				if(p->heso[i]>0) printf("+ %d", p->heso[i]);
				else printf("- %d", -p->heso[i]);
				continue;
			}
			if(i==1 && p->heso[i] != 0) {
				if(p->heso[i]>0) printf("+ %d*x ", p->heso[i]);
				else printf("- %d*x ", -p->heso[i]);
				continue;
			}
			if(p->heso[i]==0) continue;
			else if(p->heso[i]>0) printf("+ %d*x^%d ", p->heso[i], i);
			else printf("- %d*x^%d ", -p->heso[i], i);
		}
		printf("\nGia tri da thuc: %s(%.2lf) = %.2lf\n\n\n", p->name, p->x, p->GT);
		p = p->next;
	}	
}

void showSumDT(DT* head) {
	int arr[MAX], i;
	DT* p = head;
	for(i=0; i<=10; i++) arr[i] = 0;
	while(p) {
		for(i=0; i<=p->m; i++) arr[i] += p->heso[i];
		p = p->next;
	}
	printf("Tong cac da thuc T(x) = ");
	for(i=10; i>=0; i--) {
		if(i==0 && arr[i] != 0) {
			if(arr[i]>0) printf("+ %d", arr[i]);
			else printf("- %d", -arr[i]);
			continue;
		}
		if(i==1 && arr[i] != 0) {
			if(arr[i]>0) printf("+ %d*x ", arr[i]);
			else printf("- %d*x ", -arr[i]);
			continue;
		}
		if(arr[i]==0) continue;
		else if(arr[i]>0) printf("+ %d*x^%d ", arr[i], i);
		else printf("- %d*x^%d ", -arr[i], i);
	}
	printf("\n\n");
}

int main() {
	DT* head = NULL;
	char name[5];
	int m, i, line, n, j;
	int heso[MAX];
	double x;
	
	while(1) {
		printf("**************************************\n");
		printf("Do Duc Long - 20215609\n");
		printf("** CHUONG TRINH QUAN LY CAC DA THUC **\n");
		printf("** 1. Nhap cac da thuc, gia tri x **\n");
		printf("** 2. In danh sach da thua va gia tri **\n");
		printf("** 3. In ra tong cac da thuc vua nhap **\n");
		printf("** 0. Thoat **\n");
		printf("**************************************\n");
		
		printf("** Nhap lua chon cua ban **\n");
		scanf("%d", &line);
		getchar();
		switch(line) {
			case 1:
				printf("Nhap so luong da thuc: ");
				scanf("%d", &n); getchar();
				for(i=0; i<n; i++) {
					printf("Nhap da thuc thu %d:\n", (i+1));
					printf("Nhap ten da thuc: ");
					fgets(name, 5, stdin); fflush(stdin);
					name[strlen(name)-1] = '\0';
					printf("\nNhap bac: ");
					scanf("%d", &m); getchar();
					printf("\nNhap x: ");
					scanf("%lf", &x); getchar();
					for(j=m; j>=0; j--) {
						printf("\n\tHe so bac %d: ", j);
						scanf("%d", &heso[j]); getchar();
					}
					printf("\n");
					head = insertToLast(head, name, m, heso, x);
				}
				break;
			case 2:
				showDS(head);
				break;
			case 3:
				showSumDT(head);
				break;
			case 0:
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	return 0;
}
