#include <stdio.h>
#include <stdlib.h>
#include "Global.h"
#include "user.h"
#include "Ownerr.h"

void InitializeMainData(Stack* ps) {
    PushProduct(ps, P1);
    PushProduct(ps, P2);
    PushProduct(ps, P3);
    PushProduct(ps, P4);
    PushProduct(ps, P5);
}

int main()
{
    Stack s;
    CreateStack(&s);
    InitializeMainData(&s);
    List l;
    CreateList(&l);

    puts("Welcome In Our Online Shopping Store");
    puts("If You Are User Enter u If You Are Owner Enter o ");
    char role;
    scanf(" %c", &role);
        if (role == 'u'){
         Product p;
         puts("Choose Specific Display Way");
         puts("For Most-Recent Enter m And For Bestseller Enter b");
            char DisplayWay;
            scanf(" %c", &DisplayWay);
            if (DisplayWay == 'b') {
                while (s.NumberOfProducts > 0) {
                    GetElementFromStack(&s, &p);
                    InsertIntoList(p, &l);
                }
            }
            else if (DisplayWay == 'm')
                TransferSTL(&s,&l);
            else
                puts("Wrong Input ");

        displayProducts(&l);
        Stack Cart;
        CreateStack(&Cart);
            int id = -50;
            while(1) {
                puts("Enter IDs Of Products You Would Like To Buy & 0 To End Purchasing Process");
                scanf("%d", &id);
                if (id == 0)
                    break;
                Product temp = BuyProduct(id, &l);
                PushProduct(&Cart, temp);
            }

        showReceipt(&Cart);

        }
        else if (role == 'o') {
            TransferSTL(&s,&l);
            displayProducts(&l);
            puts("To Add Product Enter A\nTo Remove Product Enter R\nTo Change Price Enter p\n");
            char mod;
            scanf(" %s", &mod);
            if (mod == 'A') {
                Product S;
                char temp[100];
                puts("Enter Product Name & ID & Price & Quantitiy");
                scanf("%s", temp);
                S.ProductName = temp;
                scanf("%d", &S.P_id);
                scanf("%f", &S.P_Price);
                scanf("%d", &S.Quantity);
                S.NumberOfSales = 0;
                addProduct (&l, S);
                displayProducts(&l);
            }
            else if (mod == 'R') {
                puts ("Enter Product ID");
                int id;
                scanf(" %d", &id);
                removeProduct(&l, id);
                displayProducts(&l);
            }
            else if (mod == 'p') {
                puts("Enter The New Price Then The ID");
                float newPrice;
                int ID;
                scanf("%f", &newPrice);
                scanf("%d", &ID);
                changePrice(&l, newPrice, ID);
                displayProducts(&l);
            }
            else {
                puts("Wrong Input ");
            }
        }
        TransferLTS(&s, &l);
}




