//
// Created by Omar on 6/3/2021.
//
#include "Global.h"
#include "Owner.h"
#include <stdio.h>
#include <stdlib.h>
void Display(Product P)    //for displaying one product
{

    printf("%d\t",P.P_id);
    printf("%s\t",P.ProductName);
    printf("%f\t",P.P_Price);
    printf("%d\t",P.Quantity);
    printf("\t%d\n",P.NumberOfSales);
}






void displayProducts(List *l)   //for displaying all products
{
    ProductNode *pn = l->head;
    printf("ID\t");
    printf("\tName");
    printf("\tPrice");
    printf("\t\tQuantity");
    printf("\tNumber of Sales\n");
    for (int i = 0; i <l->NumberOfProducts ; i++) {
        Display((pn->P));
        pn = pn->next;

    }
}






void removeProduct(List *l , int ID)
{
    ProductNode *q , *tmp;
    q=l->head;
    if(q->P.P_id == ID) //if 1st product
    {
        tmp = q;
        l->head = q->next;
        l->NumberOfProducts--;
        free(tmp);
    }


    else
    {
        for (int i = 0; i <l->NumberOfProducts ; i++) {

            if(q->next->P.P_id == ID)   // to point on the next node
            {
                tmp=q->next;
                q->next = tmp->next;
                free(tmp);
                l->NumberOfProducts--;
                break;
            }

            else
            {
                q=q->next;
            }


        }
    }
}







void addProduct(List *l , Product p)
{
    ProductNode *pn = (ProductNode*) malloc(sizeof (ProductNode));
    pn->P = p;
    pn->next = l->head;
    l->head = pn;
    l->NumberOfProducts++;
}






void changePrice(List *l , float price , int ID)
{
    ProductNode *q = l->head;
    if(q->P.P_id == ID)
    {
        q->P.P_Price = price;

    }


    else
    {
        q = q->next;//to increase position by 1
        for (int i = 0;  i<l->NumberOfProducts ; i++) {

            if(q->P.P_id == ID)
            {
                q->P.P_Price = price;
                break;
            } else
            {
                q=q->next;
            }
        }



    }
}