#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int b[], int p, int c[], int q, int a[]) {
    int i = 0, j = 0, k = 0;

    while (i < p && j < q) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        } else {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while (i < p) {
        a[k] = b[i];
        i++;
        k++;
    }

    while (j < q) {
        a[k] = c[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int n) {
    if (n < 2) return;

    int mid = n / 2;
    int *b = (int *)malloc(mid * sizeof(int));
    int *c = (int *)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        b[i] = a[i];
    }
    for (int i = mid; i < n; i++) {
        c[i - mid] = a[i];
    }

    mergesort(b, mid);
    mergesort(c, n - mid);
    merge(b, mid, c, n - mid, a);

    free(b);
    free(c);
}

int main() {
    int n;
    clock_t start, end;
    double t;

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    start = clock();
    mergesort(arr, n);
    end = clock();

    t = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %lf\n", t);
    free(arr);
    return 0;
}
