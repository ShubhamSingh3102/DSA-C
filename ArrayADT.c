#include<stdio.h>
#include<stdlib.h>
struct myArray//abstract data type
{
    int total_size;
    int used_size;
    int *ptr;//heap me memory
};
void createArray(struct myArray* a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize*sizeof(int));//integer pointer return krega uss memory ko

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize*sizeof(int));//integer pointer return krega uss memory ko
    //heap me memory request kr rha h 
}
void show(struct myArray *a)
{
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
void setValue(struct myArray *a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter elements %d\n",i);
        scanf("%d\n",&n);
        (a->ptr)[i]=n;
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks,10,2);
    printf("We are running setvalue now\n");
    setValue(&marks);
    printf("We are running show now\n");
    show(&marks);
    return 0;
}
