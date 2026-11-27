
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char hoten[50];
    int masv;
    float d1, d2, d3;
} Data;

typedef struct tagNode {
    Data infor;
    struct tagNode *next, *prev;
} Node;

typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;

// 
void intList(LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

//
int emptyList(LList L) {
    return L.spt == 0;
}
int fullList(LList L) {
    return L.spt == 50;
}
// 
void insert_Head(LList *L, Data x) {
	if (fullList(*L)) {
        printf("Danh sach da day!\n");
        return;
    }

    Node *pp = (Node*)malloc(sizeof(Node));

    if (pp == NULL) return;

    pp->infor = x;
    pp->next = NULL;
    pp->prev = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pHead->prev = pp;
        pp->next = L->pHead;
        L->pHead = pp;
    }

    L->spt++;
}

// 

void insert_Tail(LList *L, Data x) {
	if (fullList(*L)) {
    printf("Danh sach da day!\n");
    return;
}
    Node *pp = (Node*)malloc(sizeof(Node));

    if (pp == NULL) return;

    pp->infor = x;
    pp->next = NULL;
    pp->prev = NULL;

    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->next = pp;
        pp->prev = L->pTail;
        L->pTail = pp;
    }

    L->spt++;
}

// 
int insert_after(LList *L, int masv, Data x) {
    Node *p = L->pHead;

    while (p != NULL && p->infor.masv != masv) {
        p = p->next;
    }

    if (p == NULL) {
        return 0;
    }

    Node *pp = (Node*)malloc(sizeof(Node));

    if (pp == NULL) return 0;

    pp->infor = x;
    pp->prev = p;
    pp->next = p->next;

    if (p->next != NULL) {
        p->next->prev = pp;
    } else {
        L->pTail = pp;
    }

    p->next = pp;
    L->spt++;

    return 1;
}

// 
void nhap(Data *x) {
    printf("Nhap ma sv: ");
    scanf("%d", &x->masv);

    if (x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf(" %49[^\n]", x->hoten);

        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);

        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);

        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}

// 
void in(Data x) {
    printf("Ten: %s, Ma: %d, Diem mon 1: %.2f, Diem mon 2: %.2f, Diem mon 3: %.2f\n",
        x.hoten, x.masv, x.d1, x.d2, x.d3);
}

//
void processListnext(LList L) {
    Node *pp = L.pHead;

    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }

    while (pp != NULL) {
        in(pp->infor);
        pp = pp->next;
    }
}
void processListprev(LList L) {
    Node *pp = L.pTail;

    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }

    while (pp != NULL) {
        in(pp->infor);
        pp = pp->prev;
    }
}

// 
void freeList(LList *L) {
    Node *pp = L->pHead;

    while (pp != NULL) {
        Node *q = pp;
        pp = pp->next;
        free(q);
    }

    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

// 
int main() {
    LList L;
    int kt = 0;
    Data x;

    intList(&L);

    do {
        printf("\nCHUONG TRINH LAM VIEC VOI DSLK KEP SV\n");
        printf("1. Them nut vao dau danh sach\n");
        printf("2. Them nut vao cuoi danh sach\n");
        printf("3. Them nut vao sau mot nut khac\n");
        printf("9. Duyet danh sach dau ve cuoi\n");
        printf("10. Duyet danh sach tu cuoi ve dau\n");
        printf("0. Thoat\n");

        printf("Moi ban chon: ");

        int chon;
        scanf("%d", &chon);

        switch (chon) {

            case 1:
                printf("Nhap thong tin sinh vien can them:\n");
                nhap(&x);

                if (x.masv > 0) {
                    insert_Head(&L, x);
                    printf("Them thanh cong!\n");
                }
                break;

            case 2:
                printf("Nhap thong tin sinh vien can them:\n");
                nhap(&x);

                if (x.masv > 0) {
                    insert_Tail(&L, x);
                    printf("Them thanh cong!\n");
                }
                break;

            case 3: {
                int ma;

                printf("Nhap ma sv can them sau: ");
                scanf("%d", &ma);

                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);

                if (x.masv > 0) {
                    if (insert_after(&L, ma, x)) {
                        printf("Them sinh vien thanh cong!\n");
                    } else {
                        printf("Khong tim thay sinh vien %d\n", ma);
                    }
                }
                break;
            }

            case 9:
                processListnext(L);
                break;
            case 10:
                processListprev(L);
                break;

            case 0:
                printf("Bye!\n");
                kt = 1;
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (kt == 0);

    freeList(&L);

    return 0;
}
