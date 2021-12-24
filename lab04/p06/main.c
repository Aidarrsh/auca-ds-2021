#include <stdio.h>
#include "VecInt.h"

void printArraya(int *beg, int *end) {

    while (beg != end) 
    {
        printf(" %d", *beg++);
    }
    printf("\n");
}

void reverse (int *beg, int *end) {
    for (;;) {
        if (beg == end) {
            break;
        }
        --end;

        if (beg == end) {
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;
        ++beg;
    }
}

void p01() 
{
    printf("the size of array: ");
    int n;
    scanf("%d", &n);

    struct VecInt v;
    VecInt_createOfSize(&v, n, 0);

    // int *dynArray = (int *)malloc(n * sizeof(int));
    // if (dynArray == NULL) {
    //     printf("Not enough memory");
    //     exit(1);
    // }

    for (int i =0; i < n; i++) {
        scanf("%d", &v.data[i]);
    }

    reverse(v.data, v.data + n);

    printArraya(v.data, v.data + n);
    VecInt_destroy(&v);
}
 
void p02() {
    struct VecInt v;

    VecInt_createEmpty(&v);

    int x;
    while(scanf("%d", &x) == 1) 
    {
        VecInt_pushback(&v, x);
        
    }
    printArraya(v.data, v.data + v.sz);
    reverse(v.data, v.data + v.sz);
    printArraya(v.data, v.data + v.sz);
    
    VecInt_destroy(&v);
}

int main(void)
{
    p01();
    //p02();
}