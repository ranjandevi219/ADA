#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void heapsort(int n, int a[]);
void heapify(int n, int a[]);
void swap(int* a, int* b);

void main()
{
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while (1)
    {
        printf("\n 1:For sorting of array elements");
        printf("\n 2:To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n 3:To exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter array elements: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            start = clock();
            heapsort(n, a);
            end = clock();
             printf("Sorted array elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
            printf("\nTime taken to sort %d numbers is %f Secs\n", n, (((double)(end - start)) / CLOCKS_PER_SEC));
            break;

        case 2:
                  n=500;
      while(n<=14500) {
      for(i=0;i<n;i++)
 {
   //a[i]=random(1000);
   a[i]=n-i;
 }
      start=clock();
      heapsort(n,a);
          //Dummy loop to create delay
    for(j=0;j<500000;j++){ temp=38/600;}
              end=clock();
         printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
            n=n+1000;
 }

            break;

        case 3:
            exit(0);
        }

        getchar(); // Consume newline character left in input buffer
    }
}

void heapify(int n, int a[])
{
    int i, p, c, item;
    for (p = (n - 1) / 2; p >= 0; p--)
    {
        item = a[p];
        c = 2 * p + 1;
        while (c < n)
        {
            if (c + 1 < n && a[c] < a[c + 1])
            {
                c++;
            }
            if (item >= a[c])
                break;
            a[p] = a[c];
            p = c;
            c = 2 * p + 1;
        }
        a[p] = item;
    }
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapsort(int n, int a[])
{
    int i;
    heapify(n, a);
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(i, a);
    }
}

