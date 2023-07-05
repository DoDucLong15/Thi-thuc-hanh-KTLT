#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct DaThuc {
	int n;
	double a[11];
	double x;
	struct DaThuc *next;
	char name[5];
} DT;

DT* creatNode(int n, double a[], double x, char name[]) {
	DT* newNode = (DT*)malloc(sizeof(DT));
	newNode->n = n;
	newNode->x = x;
	//
	int i;
	for(i=0; i<=n; i++) newNode->a[i] = a[i];
	for(i=n+1; i<11; i++) newNode->a[i] = 0;
	//
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

DT* insertToLast(DT* head, int n, double a[], double x, char name[]){
	DT* newNode = creatNode(n,a,x,name);
	if(head==NULL) head = newNode;
	else {
		DT* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showDaThuc(DT* head) {
	DT* p = head;
	while(p) {
		double sum = 0;
		int i;
		printf("%s(x) = ", p->name);
		for(i=p->n; i>=0; i--) {
			if(i==p->n) {
				printf("%.1lfx^%d", p->a[i], i);
			}
			else if(i==1) {
				if(p->a[i]>0) printf("%+.1lfx", p->a[i]);
				else if(p->a[i]<0) printf("%.1lfx", p->a[i]);
				else continue;
			}
			else if(i==0) {
				if(p->a[i]>0) printf("%+.1lf", p->a[i]);
				else if(p->a[i]<0) printf("%.1lf", p->a[i]);
				else continue;
			}
			else {
				if(p->a[i]>0) printf("%+.1lfx^%d", p->a[i], i);
				else if(p->a[i]<0) printf("%.1lfx^%d", p->a[i], i);
				else continue;
			}
			sum+=p->a[i] * pow(p->x,i);
		}
		printf("\n");
		printf("%s(%.1lf) = %lf\n", p->name, p->x, sum);
		p = p->next;
	}
}

void showSumDaThuc(DT* head) {
	double sum[11];
	int i, k;
	DT* p = head;
	
	for(i=0; i<11; i++) sum[i] = 0.0;
	while(p) {
		for(i=0; i<11; i++) sum[i]+=p->a[i];
		p = p->next;
	}
	for(i=10; i>=0; i--)
		if(sum[i]!=0) {
			k = i;
			break;
		}
	printf("Tong cac da thuc la: \n");
	for(i=10; i>=0; i--) {
		if(i==k) {
			printf("%.1lfx^%d", sum[i], i);
		}
		else if(i==1) {
			if(sum[i]>0) printf("%+.1lfx", sum[i]);
			else if(sum[i]<0) printf("%.1lfx", sum[i]);
			else continue;
		}
		else if(i==0) {
			if(sum[i]>0) printf("%+.1lf", sum[i]);
			else if(sum[i]<0) printf("%.1lf", sum[i]);
			else continue;
		}
		else {
			if(sum[i]>0) printf("%+.1lfx^%d", sum[i], i);
			else if(sum[i]<0) printf("%.1lfx^%d", sum[i], i);
			else continue;
		}
	}
	printf("\n");	
}

int main() {
	DT* head = NULL;
	int line, n, i;
	double a[11], x;
	char name[5];
	
	while(1) {
		printf("*************************************\n");
		printf("Do Duc Long - 20215609\n");
		printf("**		CHUONG TRINH QUAN LY DA THUC	**\n");
		printf("**	1. Nhap cac da thuc, gia tri x		**\n");
		printf("**	2. In danh sach da thuc, va gia tri	**\n");
		printf("**	3. In ra tong cac da thuc			**\n");
		printf("**	4. Thoat							**\n");
		printf("*************************************\n");
		
		printf("**		Nhap lua chon cua ban		**\n");
		scanf("%d", &line);
		switch(line) {
			case 1:
				printf("Ban da chon nhap da thuc!\n");
				printf("---------------------------------------\n");
				printf("Nhap ten da thuc: ");
				scanf("%s", &name);
				printf("Nhap bac: ");
				scanf("%d", &n);
				printf("Nhap x: ");
				scanf("%lf", &x);
				for(i=n; i>=0; i--) {
					printf("  He so bac %d: ", i);
					scanf("%lf", &a[i]);
				}
				printf("---------------------------------------\n");
				printf("Ban da nhap thanh cong!\n");
				head = insertToLast(head, n, a, x, name);
				break;
			case 2:
				printf("Ban da chon xuat DS da thuc, Gia tri da thuc!\n");
				printf("---------------------------------------\n");
				showDaThuc(head);
				printf("---------------------------------------\n");
				break;
			case 3:
				printf("Ban da chon in tong cac da thuc!\n");
				printf("---------------------------------------\n");
				showSumDaThuc(head);
				printf("---------------------------------------\n");
				break;
			case 4:
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	return 0;
}
