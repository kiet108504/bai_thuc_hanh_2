#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char hoten[50];
	int masv;
	float d1,d2,d3;
}Data;

typedef struct tagNode{
	Data infor;
	struct tagNode *link;
}Node;

typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;

void intList(LList*L){
	L -> pHead = NULL;
	L -> pTail = NULL;
	L -> spt = 0;
}

int emptyList(LList L){
	return(L.spt==0);
}
void insert_Head(LList*L,Data x){
	Node*pp;
	pp = (Node*)malloc(sizeof(Node));
	pp -> infor = x;
	pp -> link = NULL;
	if(emptyList(*L)){
		L -> pHead = pp;
		L-> pTail = pp;
	}
	else{
		pp ->link = L->pHead;
		L->pHead = pp;	
	}
	L->spt++;
}

void insert_Tail(LList*L,Data x){
	Node*pp;
	pp = (Node*)malloc(sizeof(Node));
	pp -> infor = x;
	pp -> link = NULL;
	if(emptyList(*L)){
		L -> pHead = pp;
		L-> pTail = pp;
	}
	else{
		L ->pTail->link = pp;
		L->pTail = pp;	
	}
	L->spt++;
}

int insert_after(LList*L,int masv,Data x){
	Node*pp = L->pHead;
	while(pp!=NULL && pp->infor.masv!= masv){
		pp = pp->link;
	}
	if(pp == NULL){
		return 0;
	}
	Node*q  =  (Node*)malloc(sizeof(Node));
	q->infor = x;
	q->link = pp-> link;
	pp->link = q;
	if(pp == L->pTail){
		L->pTail = q;
	}
	L->spt++;
	return 1;
}

void nhap(Data *x){
	printf("Nhap ma sv: ");
	scanf("%d",&(x->masv));
	if(x->masv>0){
		printf("Nhap ho ten: ");
		scanf("%s",&(x->hoten));
		printf("Nhap diem mon 1: ");
		scanf("%f",&(x->d1));
		printf("Nhap diem mon 2: ");
		scanf("%f",&(x->d2));
		printf("Nhap diem mon 3: ");
		scanf("%f",&(x->d3));
	}	
}

void in(Data x){
	printf("Ten: %s, Ma: %d, Diem mon 1: %.2f, Diem mon 2: %.2f, Diem mon 3: %.2f\n",x.hoten,x.masv,x.d1,x.d2,x.d3);
}

void processList(LList L){
	Node*pp = L.pHead;
	while(pp!= NULL){
		in(pp->infor);
		pp = pp->link;
	}
}

int main() {
	LList L;
	int kt  = 0;
	Data x;
	intList(&L);
	do{
		printf("\nChuong trinh lam viec voi dslk don Sv\n");
		printf("\n1 Them nut vao dau danh sach\n1");
		printf("\n2 Them nut vao cuoi danh sach\n2");
		printf("\n3 Them nut vao sau moi nut khac trong danh sach\n3");
		printf("\n9 Duyet ds");
		printf("\n0 Thoat");
		printf("\nMoi ban chon: ");
		int chon;
		scanf("%d",&chon);
		switch(chon){
			case 1:
				printf("Nhap so thong tin sv can them\n");
				nhap(&x);
				if(x.masv>0)
				insert_Head(&L,x);
				break;
			case 2:
				printf("Nhap so thong tin sv can them\n");
				nhap(&x);
				if(x.masv>0)
				insert_Tail(&L,x);
				break;
			case 3:
				{
				int ma;
				printf("Nhap ma sv can them sau: ");
				scanf("%d",&ma);
				printf("Nhap ma sv can them moi: ");
				nhap(&x);
				if(x.masv>0){
					if(insert_after(&L,ma,x))
						printf("Them sv thanh cong");
					else
					printf("Khong tim thay sv %d\n",ma);
					
				}break;}
				
			case 9:
			processList(L);
			break;
			case 0:
			printf("Bye\n");
			kt = 1;
			break;
			default:
			printf("Lua chon khong hop le");		
		}
	}while(kt == 0);	return 0;
}	


