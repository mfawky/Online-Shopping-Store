//
// Created by Omar on 6/3/2021.
//
#include "Global.h"
#include <stdlib.h>
#ifndef ONLINESTORE_OWNER_H
#define ONLINESTORE_OWNER_H

void displayProducts(List *l);
void removeProduct(List *l ,  int ID);
void addProduct(List *l , Product p);
void changePrice(List *l , float price , int ID);
void Display(Product p);

#endif //ONLINESTORE_OWNER_H
