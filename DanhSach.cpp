#include <iostream>
using namespace std;
struct NODE{
    int Info;
    NODE* pNext;
};

struct LIST{
    NODE* pHead;
    NODE* pTail;
};

NODE* TaoNode(int x){
    NODE* p = new NODE;
    if(!p) return NULL;
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void TaoListRong(LIST& L){
    L.pHead = NULL;
    L.pTail = NULL;
}

void ThemDau(LIST& L, NODE* p){
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else{
        p->pNext = L.pHead;
        L.pHead = p;
    }
}

void ThemCuoi(LIST& L, NODE* p){
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else{
        L.pTail->pNext = p;
        L.pTail = p;    
    }
}

void TaoList(LIST& L){
    int num;
    while (cin >> num && num!= -1){
        NODE* p = TaoNode(num);
	if (!p) continue;
        ThemDau(L, p);
    }
}

void XuatList(LIST L){
    if(L.pHead == NULL){
        cout << "Empty";
        return;
    }
    NODE* p = L.pHead;
    while(p){
        cout << p->Info << " ";
        p = p->pNext;
    }
    cout << "\n";
}

void XuatList(NODE* pHead){
    if(pHead == NULL){
        cout << "Empty";
        return;
    }
    
    for(NODE* p = pHead; p; p = p->pNext){
        cout << p->Info << " ";
    }
    cout << "\n";
}

void add_afterX(LIST& L, int Y, int X){
    NODE* temp = L.pHead;
    
    while (temp) {
        if (temp->Info == X) {
            NODE* newNode = TaoNode(Y);
            newNode->pNext = temp->pNext;
            temp->pNext = newNode;
            if (L.pTail == temp)
                L.pTail = newNode;
            return; // temp = newNode de tiep tuc them
        }
        temp = temp->pNext;
    }
}

void AddAfterQ(LIST &L, NODE* p, NODE* Q) {
    if (p == NULL) return;

    if (Q != NULL) {
        p->pNext = Q->pNext;
        Q->pNext = p;
        if (L.pTail == Q)
            L.pTail = p;
    } else {
        ThemDau(L, p);
    }
}

void RemoveHead(LIST& L){
    if (L.pHead == NULL) return;

    NODE* p = L.pHead;
    L.pHead = L.pHead->pNext;
    
    if (L.pHead == NULL)
        L.pTail = NULL;
    delete p;
}

void RemoveTail(LIST& L){
    if (L.pHead == NULL) return;
    
    if (L.pHead->pNext == NULL){
        delete L.pHead;
        L.pHead = NULL;
        return;
    }
    
    NODE* p = L.pHead;
    while (p->pNext->pNext != NULL)
        p = p->pNext;

    delete p->pNext;
    p->pNext = NULL;
}

int main() {
    LIST L;
    int X, Y;
    TaoListRong(L);
    cout << "Nhap node: ";
    TaoList(L);

    cin >> X >> Y;
    cout << "Danh sach node: ";
    add_afterX(L, Y, X);
    XuatList(L);
    return 0;
}