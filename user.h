#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "Global.h"

void InsertIntoList(Product Pr, List* pl);
void displayProducts(List* pl);
Product BuyProduct (int id, List* pl);
void ShowBestSeller (List* pl, Stack* ps);
#endif // USER_H_INCLUDED
