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
    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;

    int x;
    while (scanf("%d", &x) == 1)
    {

        if (sz == cp)
        {
            cp = (cp == 0) ? 1 : cp * 2;
            int *newData = (int *)malloc(sizeof(int) * cp);
            for (size_t i = 0; i < sz; i++)
            {
                newData[i] = data[i];
            }
            free(data);
            data = newData;
        }
        data[sz++] = x;
    }
    printArray(data, data + sz);
    reverse(data, data + sz);
    printArray(data, data + sz);

    free(data);
}