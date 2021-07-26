#include "Global.h"
#include <stdlib.h>
#include <stdio.h>

Product P1 = {"p1",654,465,789,14};
Product P2 = {"p2",1,2,3,5};
Product P3 = {"p3",65,56,54,443};
Product P4 = {"p4",65,56,54,143};
Product P5 = {"p5",65,56,54,743};


int StackEmpty(Stack* ps) {
    return ps->NumberOfProducts == 0;
}

void display(Product p) {
    printf("Product Name : %s\n", p.ProductName);
}
void CreateStack(Stack* ps) {
    ps->Top = NULL;
    ps->NumberOfProducts = 0;
}

void PushProduct(Stack* ps, Product p) {
    ProductNode* pn = (ProductNode*) malloc(sizeof(ProductNode));
    pn->P = p;
    pn->next = ps->Top;
    ps->Top = pn;
    ps->NumberOfProducts++;
}

void CreateList(List* pl) {
    pl->head = NULL;
    pl->NumberOfProducts = 0;
}

void TransferSTL(Stack* ps, List* pl) {
    pl->head = ps->Top;
    ps->Top = NULL;
    pl->NumberOfProducts = ps->NumberOfProducts;
    ps->NumberOfProducts = 0;
}

void TransferLTS(Stack* ps, List* pl) {
    ps->Top = pl->head;
    pl->head = NULL;
    ps->NumberOfProducts = pl->NumberOfProducts;
    pl->NumberOfProducts = 0;
}

void GetElementFromStack (Stack* ps, Product* Pr) {
    ProductNode* pn = ps->Top;
    *Pr = ps->Top->P;
    ps->Top = ps->Top->next;
    free(pn);
    ps->NumberOfProducts--;
}
void showReceipt(Stack *ps) {
    ProductNode* pn = ps->Top;
    for (;pn;pn = pn->next)
        printf("Product Name : %s\n", pn->P.ProductName);
}





