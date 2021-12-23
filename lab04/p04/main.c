#include <stdio.h>
#include <stdlib.h>

void printArray(int *begin, int *end)
{
    while (begin != end)
    {
        printf("%d ", *begin++);
    }
    printf("\n");
}
// pointer opeations
// *p
// p ->
// p == q
// p != q
// only for blocks(arrays)
// p++, ++p, q--, --q
// p + n, p - n, p+=n, p-=n
// p < q, p >q, p <= q, p =>q

void reverse(int *begin, int *end)
{
    for (;;)
    {
        if (begin == end)
        {
            break;
        }
        --end;
        if (begin == end)
        {
            break;
        }

        int t = *begin;
        *begin = *end;
        *end = t;
        ++begin;
    }
}

int main(void)
{
    printf("The size of array: ");
    int n;
    scanf("%d", &n);

    int *dynArray = (int *)malloc(n * sizeof(int));
    if (dynArray == NULL)
    {
        printf("Not enought memory");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dynArray[i]);
    }

    reverse(dynArray, dynArray + n);

    printArray(dynArray, dynArray + n);

    free(dynArray);
}