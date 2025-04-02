#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r) {
    int p = a[l];
    int i = l;
    int j = r;

    while (i < j) {
        do {
            i++;
        } while (i <= r && a[i] < p);

        do {
            j--;
        } while (a[j] > p);

        if (i < j) {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int s = partition(a, l, r);
        quicksort(a, l, s - 1);
        quicksort(a, s + 1, r);
    }
}

int main() {
    int n;
    clock_t start, end;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", t);

    return 0;
}
