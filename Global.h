#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED


typedef struct product{
    char* ProductName;
    int P_id;
    float P_Price;
    int Quantity;
    int NumberOfSales;
}Product;

typedef struct pronode{
    struct pronode* next;
    Product P;
}ProductNode;


typedef struct stackk{
    ProductNode* Top;
    int NumberOfProducts;
}Stack;


typedef struct list{
    ProductNode* head;
    int NumberOfProducts;
}List;

void showReceipt(Stack *ps);
void CreateStack(Stack* ps);
void PushProduct(Stack* ps, Product p);
int StackEmpty(Stack* ps);
void CreateList(List* pl);
void GetElementFromStack (Stack* ps, Product* Pr);
void TransferSTL(Stack* ps, List* pl);
void TransferLTS(Stack* ps, List* pl);
void display(Product p);
//void ShowBestSeller (List* pl, Stack* ps);
Product P1, P2, P3, P4, P5;
#endif // GLOBAL_H_INCLUDED
