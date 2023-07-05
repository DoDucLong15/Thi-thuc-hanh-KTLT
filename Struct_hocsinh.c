#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	char name[30];
	double diemToan, diemVan, diemTB;
	struct Student* next;
} HS;

HS* creatNode(char name[], double diemToan, double diemVan) {
	HS* newNode = (HS*)malloc(sizeof(HS));
	strcpy(newNode->name,name);
	newNode->diemToan = diemToan;
	newNode->diemVan = diemVan;
	newNode->diemTB = (diemToan+diemVan)/2;
	newNode->next = NULL;
	return newNode;
}

HS* insertToLast(HS* head, char name[], double diemToan, double diemVan) {
	HS* newNode = creatNode(name, diemToan, diemVan);
	if(head==NULL) head = newNode;
	else {
		HS* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showStudent(HS* head) {
	int i = 1;
	printf("%-5s%-30s%10s%10s%10s\n", "STT", "HO VA TEN", "DIEM TOAN", "DIEM VAN", "DTB");
	HS* p = head;
	while(p) {
		printf("%-5d%-30s%10.1f%10.1f%10.1f\n", i, p->name, p->diemToan, p->diemVan, p->diemTB);
		i++;
		p = p->next;
	}
}

void showStudentMathLess5(HS* head) {
	int i = 1;
	printf("%-5s%-30s%10s%10s%10s\n", "STT", "HO VA TEN", "DIEM TOAN", "DIEM VAN", "DTB");
	HS* p = head;
	while(p) {
		if(p->diemToan<5) {
			printf("%-5d%-30s%10.1f%10.1f%10.1f\n", i, p->name, p->diemToan, p->diemVan, p->diemTB);
			i++;
		}
		p = p->next;
	}
}

void CountTVGreater8(HS* head) {
	int count=0;
	HS* p = head;
	while(p) {
		if(p->diemToan>8 && p->diemVan>8) count++;
		p = p->next;
	}
	printf("So hoc sinh co diem toan va diem van lon hon 8 diem: %d\n", count);
}

void sortDTB(HS *head) {
	char s[30];
	double temp;
	HS *m, *n;
	for(m = head; m!=NULL; m = m->next)
		for(n = m->next; n!=NULL; n = n->next)
			if(m->diemTB < n->diemTB) {
				strcpy(s,m->name); strcpy(m->name, n->name); strcpy(n->name,s);
				temp = m->diemToan; m->diemToan = n->diemToan; n->diemToan = temp;
				temp = m->diemVan; m->diemVan = n->diemVan; n->diemVan = temp;
				temp = m->diemTB; m->diemTB = n->diemTB; n->diemTB = temp;
			}
}

int main() {
	HS* head;
	head = NULL;
	char name[30];
	double diemToan, diemVan;
	int n;
	
	while(1) {
		printf("===============================================================\n");
		printf("Application Student\n");
		printf("Enter 1: Them hoc sinh\n");
		printf("Enter 2: Hien thi danh sach hoc sinh\n");
		printf("Enter 3: Liet ke danh sach hoc sinh diem toan nho hon 5\n");
		printf("Enter 4: Dem so luong hoc sinh co diem toan, van lon hon 8\n");
		printf("Enter 5: Sap xep hoc sinh giam dan theo diem trung binh\n");
		printf("Enter 6: Thoat\n");
		printf("===============================================================\n");
		
		printf("Nhap lua chon: ");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1:
				printf("Nhap ten hoc sinh: ");
				fgets(name, 30, stdin); fflush(stdin);
				name[strlen(name)-1] = '\0';
				printf("Nhap diem Toan: ");
				scanf("%lf", &diemToan);
				getchar();
				printf("Nhap diem Van: ");
				scanf("%lf", &diemVan);
				getchar();
				head = insertToLast(head, name, diemToan, diemVan);
				break;
			case 2:
				showStudent(head);
				break;
			case 3:
				showStudentMathLess5(head);
				break;
			case 4:
				CountTVGreater8(head);
				break;
			case 5:
				sortDTB(head);
				break;
			case 6:
				return 0;
			default:
				printf("Invalid\n");
				continue;
		}
	}
	
	return 0;
}
