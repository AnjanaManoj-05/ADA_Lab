#include <stdio.h>
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
    if (n < 2) return;  // Base case: single element is already sorted

    int mid = n / 2;
    int b[mid], c[n - mid];

    for (int i = 0; i < mid; i++) {
        b[i] = a[i];
    }
    for (int i = mid; i < n; i++) {
        c[i - mid] = a[i];
    }

    mergesort(b, mid);
    mergesort(c, n - mid);
    merge(b, mid, c, n - mid, a);
}

int main() {
    int n;
    clock_t start,end;
    double t;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
   // printf("Enter %d elements: ", n);
    int ele=1000;
    for (int i = 0; i < n; i++) {
        arr[i]=ele;
        ele--;
    }
      start=clock();
    mergesort(arr, n);
    end=clock();
    t=(double)(end-start)/CLK_TCK;
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time taken: %lf",t);
    return 0;
}
