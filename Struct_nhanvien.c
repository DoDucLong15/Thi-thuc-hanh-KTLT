#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NhanVien {
	char name[30];
	int yearOfBirth;
	double salary;
	int sex; //0: Nu, 1: Nam
	struct NhanVien* next;
} NV;

NV* creatNode(char name[], int yearOfBirth, double salary, int sex) {
	NV* newNode = (NV*) malloc(sizeof(NV));
	strcpy(newNode->name,name);
	newNode->yearOfBirth = yearOfBirth;
	newNode->salary = salary;
	newNode->sex = sex;
	newNode->next = NULL;
	return newNode;
}

NV* inserttoHeadNV(NV* head, char name[], int yearOfBirth, double salary, int sex) {
	NV* newNode;
	newNode = creatNode(name, yearOfBirth, salary, sex);
	if(head==NULL) head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
	return head;
}

NV* inserttoLastNV(NV* head, char name[], int yearOfBirth, double salary, int sex) {
	NV* newNode;
	newNode = creatNode(name, yearOfBirth, salary, sex);
	if(head==NULL) head = newNode;
	else {
		NV* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showNV(NV* head) {
	printf("%-20s%-20s%20s%20s\n", "HO VA TEN", "NAM SINH", "LUONG", "GIOI TINH");
	NV* p;
	p = head;
	while(p) {
		printf("%-20s%-20d%20.2f%20s\n", p->name, p->yearOfBirth, p->salary, (p->sex==0)?"Nu":"Nam");
		p = p->next;
	}
}

void showNVAgeGreater40(NV* head) {
	printf("%-20s%-20s%20s%20s\n", "HO VA TEN", "NAM SINH", "LUONG", "GIOI TINH");
	NV* p;
	p = head;
	int kt = 0;
	while(p) {
		if(2023-p->yearOfBirth>40) {
			printf("%-20s%-20d%20.2f%20s\n", p->name, p->yearOfBirth, p->salary, (p->sex==0)?"Nu":"Nam");
			kt = 1;
		}
		p = p->next;
	}
	if(!kt) printf("NOT FOUND\n");
}

void showNVSalaryGreater1M(NV* head) {
	printf("%-20s%-20s%20s%20s\n", "HO VA TEN", "NAM SINH", "LUONG", "GIOI TINH");
	NV* p;
	p = head;
	int kt = 0;
	while(p) {
		if(p->salary>1000000) {
			printf("%-20s%-20d%20.2f%20s\n", p->name, p->yearOfBirth, p->salary, (p->sex==0)?"Nu":"Nam");
			kt = 1;
		}
		p = p->next;
	}
	if(!kt) printf("NOT FOUND\n");
} 

void sortYearDecrease(NV* head) {
	NV *m, *n;
	char s[30];

	for(m = head; m!=NULL; m = m->next)
		for(n = m->next; n!=NULL; n = n->next) 
			if(m->yearOfBirth < n->yearOfBirth) {
				strcpy(s,m->name); strcpy(m->name,n->name); strcpy(n->name,s);
				int temp = m->yearOfBirth; m->yearOfBirth = n->yearOfBirth; n->yearOfBirth = temp;
				double type = m->salary; m->salary = n->salary; n->salary = type;
				int temp1 = m->sex; m->sex = n->sex; n->sex = temp1;
			}
}

int main() {
	NV* head;
	head = NULL;
	int n, year, sex;
	char name[30];
	double salary;
	
	while(1) {
		printf("--------------------------------------------------\n");
		printf("Application Manager Employee\n");
		printf("Enter 1: Them nhan vien.\n");
		printf("Enter 2: In danh sach nhan vien.\n");
		printf("Enter 3: In danh sach nhan vien hon 40 tuoi.\n");
		printf("Enter 4: In danh sach nhan vien luong hon 1M.\n");
		printf("Enter 5: Sap xep giam dan theo nam sinh.\n");
		printf("Enter 6: Thoat.\n");
		printf("--------------------------------------------------\n");
		
		printf("Nhap lua chon: ");
		scanf("%d", &n);
		getchar();
		switch(n) {
			case 1:
				printf("Enter name: ");
				fgets(name,30,stdin); fflush(stdin);
				name[strlen(name)-1] = '\0';
				printf("Enter yearOfBirth: ");
				scanf("%d", &year);
				getchar();
				printf("Enter salary: ");
				scanf("%lf", &salary);
				getchar();
				printf("Enter sex (0-Nu,1-Nam): ");
				scanf("%d", &sex);
				getchar();
				head = inserttoHeadNV(head, name, year, salary, sex);
				break;
			case 2:
				showNV(head);
				break;
			case 3:
				showNVAgeGreater40(head);
				break;
			case 4:
				showNVSalaryGreater1M(head);
				break;
			case 5:
				sortYearDecrease(head);
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
