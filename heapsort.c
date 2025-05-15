#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, N, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    FILE *file;
    int N;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    clock_t start = clock();
    heapSort(arr, N);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\nTime taken by Heap Sort: %f seconds\n", time_taken);
    free(arr);

    return 0;
}
