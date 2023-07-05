#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
	char s[5];
	double x,y,z;
} Point;

typedef struct HinhTron {
	char name[5];
	Point tam;
	double radius;
	Point arr[3];
	struct HinhTron *next;
} HT;

HT* creatNode(char name[], Point tam, double radius, Point arr[]) {
	HT* newNode = (HT*)malloc(sizeof(HT));
	strcpy(newNode->name, name);
	newNode->tam = tam;
	newNode->radius = radius;
	int i;
	for(i=0; i<3; i++) newNode->arr[i] = arr[i];
	newNode->next = NULL;
	return newNode;
}

HT* insertToLast(HT* head, char name[], Point tam, double radius, Point arr[]) {
	HT* newNode = creatNode(name, tam, radius, arr);
	if(head==NULL) head = newNode;
	else {
		HT* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

double distance(Point A, Point B) {
	return sqrt(pow(A.x-B.x,2) + pow(A.y-B.y,2) + pow(A.z-B.z,2));
}

void show(HT* head) {
	printf("Ban da chon xuat DS hinh tron!\n");
	HT* p = head;
	int i;
	while(p) {
		double x=0, y=0, z=0;
		printf("Hinh tron tam: %s\n", p->name);
		printf("Toa do Tam %s(%.1lf,%.1lf,%.1lf)\n", p->name, p->tam.x, p->tam.y, p->tam.z);
		printf("Ban kinh R: %.1lf\n", p->radius);
		for(i=0; i<3; i++) {
			printf("Toa do Diem %s(%.1lf,%.1lf,%.1lf)\n", p->arr[i].s, p->arr[i].x, p->arr[i].y, p->arr[i].z);
			x+=p->arr[i].x;
			y+=p->arr[i].y;
			z+=p->arr[i].z;
		}
		for(i=0; i<3; i++) {
			printf("Toa do trung diem cua doan thang %s%s(%.1lf,%.1lf,%.1lf)\n", p->name, p->arr[i].s, (p->arr[i].x+p->tam.x)/2, (p->arr[i].y+p->tam.y)/2, (p->arr[i].z+p->tam.z)/2);
		}
		printf("Toa do trong tam G cua tam giac %s%s%s: (%.1lf,%.1lf,%.1lf)\n", p->arr[0].s, p->arr[1].s, p->arr[2].s, x/3, y/3, z/3);
		printf("Chu vi tam giac: %s%s%s = %.4lf\n", p->arr[0].s, p->arr[1].s, p->arr[2].s, distance(p->arr[0], p->arr[1])+distance(p->arr[1], p->arr[2])+distance(p->arr[2], p->arr[0]));
		printf("Chu vi hinh tron: %.2lf\n", 2*p->radius*3.14);
		printf("Dien tich hinh tron: %.2lf\n", 3.14*p->radius*p->radius);
		for(i=0; i<3; i++) {
			double d = distance(p->tam, p->arr[i]);
			if(d > p->radius) printf("Diem %s nam ngoai duong tron\n", p->arr[i].s);
			else if (d == p->radius) printf("Diem %s nam tren duong tron\n", p->arr[i].s);
			else printf("Diem %s nam trong duong tron\n", p->arr[i].s);
		}
		printf("\n\n\n");
		p = p->next;
	}
}

int main() {
	HT* head = NULL;
	int line, i;
	char name[5], s[5];
	double radius, x, y, z;
	Point tam;
	Point arr[3];
	
	while(1) {
		printf("Do Duc Long - 20215609\n");
		printf("CHUONG TRINH QUAN LY CAC DUONG TRON\n");
		printf("1. Nhap cac duong tron va 3 diem bat ky\n");
		printf("2. In toa do tam, diem, ban kinh, vi tri, chu vi, dien tich duong tron va chu vi, toa do trong tam cua tam giac lap tu 3 diem\n");
		printf("3. Thoat\n");
		printf("******************************\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &line); getchar();
		
		switch(line) {
			case 1:
				printf("Ban da chon nhap Hinh tron!\n");
				printf("\t\tTen tam duong tron: ");
				fgets(name, 5, stdin); fflush(stdin);
				name[strlen(name)-1] = '\0';
				printf("\t\t\tx: ");
				scanf("%lf", &x); getchar();
				printf("\t\t\ty: ");
				scanf("%lf", &y); getchar();
				printf("\t\t\tz: ");
				scanf("%lf", &z); getchar();
				strcpy(tam.s, name);
				tam.x = x; tam.y = y; tam.z = z;
				printf("\t\tBan kinh: ");
				scanf("%lf", &radius); getchar();
				for(i=0; i<3; i++) {
					printf("\t\tTen diem %d: ", (i+1));
					fgets(s, 5, stdin); fflush(stdin);
					s[strlen(s)-1] = '\0';
					printf("\t\tx: ");
					scanf("%lf", &x); getchar();
					printf("\t\ty: ");
					scanf("%lf", &y); getchar();
					printf("\t\tz: ");
					scanf("%lf", &z); getchar();
					arr[i].x = x; arr[i].y = y; arr[i].z = z;
					strcpy(arr[i].s,s);
				}
				head = insertToLast(head, name, tam, radius, arr);
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
