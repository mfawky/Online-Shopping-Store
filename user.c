#include "user.h"
#include "Global.h"
#include <stdlib.h>

void InsertIntoList(Product Pr, List* pl) {
    ProductNode* pn = (ProductNode*) malloc(sizeof(ProductNode));
    pn->P = Pr;
    ProductNode* temp = pl->head;

    if (pl->NumberOfProducts == 0)
        pl->head = pn;
    else {
        if (pl->head->P.NumberOfSales < pn->P.NumberOfSales){
            pn->next = pl->head;
            pl->head = pn;
        }
        else {
            while (temp->next->P.NumberOfSales > pn->P.NumberOfSales)
                temp = temp->next;
        }
        pn->next = temp->next;
        temp->next = pn;
    }
     pl->NumberOfProducts++;
}



void displayProducts(List* pl) {
    int stop = pl->NumberOfProducts;
    ProductNode* temp = pl->head;
    while (stop > 0) {
    puts("===============================================");
        printf("Product Name : %s\n", temp->P.ProductName);
        printf("Product SaleNum : %d\n", temp->P.NumberOfSales);
        printf("Product ID : %d\n", temp->P.P_id);
        printf("Product Quantity : %d\n", temp->P.Quantity);
        printf("Product Price : %0.3f\n", temp->P.P_Price);
        temp = temp->next;
        stop--;
    }
    puts("===============================================");
}



Product BuyProduct (int id, List* pl) {
    ProductNode* prn = pl->head;
    int index = 0;
    while (index < pl->NumberOfProducts) {
        if (prn->P.P_id == id) {
            prn->P.NumberOfSales++;
            prn->P.Quantity--;
            return prn->P;
            break;
        }
        prn = prn->next;
    }
}
void ShowBestSeller (List* pl, Stack* ps) {
    Product p;
    while (!StackEmpty(&ps)) {
        GetElementFromStack(&ps, &p);
        InsertIntoList(p, &pl);
    }
}

