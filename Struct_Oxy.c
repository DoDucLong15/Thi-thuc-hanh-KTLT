#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
	double x;
	double y;
	struct Point *next;
} Point;

Point* creatNode(double x, double y) {
	Point* newNode = (Point*)malloc(sizeof(Point));
	newNode->x = x;
	newNode->y = y;
	newNode->next = NULL;
	return newNode;
}

Point* insertToLast(Point* head, double x, double y) {
	Point* newNode = creatNode(x,y);
	if(head==NULL) head = newNode;
	else {
		Point* p = head;
		while(p->next!=NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
	return head;
}

void showPoint(Point* head) {
	printf("Cac diem co trong danh sach:\n");
	Point* p = head;
	while(p) {
		printf("(%5.2f,%5.2f)\n", p->x, p->y);
		p = p->next;
	}
}

void showPointInI(Point* head) {
	printf("Cac diem co trong phan tu thu I:\n");
	Point* p = head;
	while(p) {
		if(p->x>0 && p->y>0) printf("(%5.2f,%5.2f)\n", p->x, p->y);
		p = p->next;
	}
}

void showPointMaxY(Point* head) {
	Point* p = head;
	Point* max = p;
	while(p) {
		if(p->y>max->y) max = p;
		p = p->next;
	}
	printf("Diem co tung do lon nhat la: (%5.2f,%5.2f)\n", max->x, max->y);
}

double distanceO(Point* p) {
	return sqrt(p->x*p->x + p->y*p->y);
}

void sortDistanceO(Point* head) {
	Point *m, *n;
	for(m=head; m!=NULL; m=m->next)
		for(n=m->next; n!=NULL; n=n->next)
			if(distanceO(m)<distanceO(n)) {
				double temp = m->x; m->x = n->x; n->x = temp;
				temp = m->y; m->y = n->y; n->y = temp;
			}
}

int main() {
	Point *head;
	head = NULL;
	double x,y;
	int n;
	
	while(1) {
		printf("===============================================================\n");
		printf("Application Oxy\n");
		printf("Enter 1: Them diem\n");
		printf("Enter 2: Hien thi danh sach cac diem\n");
		printf("Enter 3: Liet ke toa do cac diem trong phan tu thu I\n");
		printf("Enter 4: Tim diem co tung do lon nhat\n");
		printf("Enter 5: Sap xep cac diem gian dan theo khoang cach den O\n");
		printf("Enter 6: Thoat\n");
		printf("===============================================================\n");
		
		printf("Nhap lua chon: \n");
		scanf("%d", &n);
		switch(n) {
			case 1:
				printf("Nhap hoanh do: ");
				scanf("%lf", &x);
				printf("Nhap tung do: ");
				scanf("%lf", &y);
				head = insertToLast(head, x, y);
				break;
			case 2:
				showPoint(head);
				break;
			case 3:
				showPointInI(head);
				break;
			case 4:
				showPointMaxY(head);
				break;
			case 5:
				sortDistanceO(head);
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
