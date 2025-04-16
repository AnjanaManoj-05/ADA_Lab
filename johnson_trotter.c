#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1


void printPermutation(int* perm, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}


int getMobileElement(int* perm, int* dir, int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i > 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > mobile) mobile = perm[i];
        }
        if (dir[i] == RIGHT && i < n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > mobile) mobile = perm[i];
        }
    }
    return mobile;
}


int findPosition(int* perm, int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i] == mobile)
            return i;
    }
    return -1;
}


void johnsonTrotter(int n) {
    int perm[n];
    int dir[n];


    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);


    while (1) {
        int mobile = getMobileElement(perm, dir, n);
        if (mobile == 0)
            break;

        int pos = findPosition(perm, n, mobile);
        int swapWith = pos + dir[pos];


        int temp = perm[pos];
        perm[pos] = perm[swapWith];
        perm[swapWith] = temp;

        int tempDir = dir[pos];
        dir[pos] = dir[swapWith];
        dir[swapWith] = tempDir;


        for (int i = 0; i < n; i++) {
            if (perm[i] > mobile)
                dir[i] = -dir[i];
        }


        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    johnsonTrotter(n);
    return 0;
}
