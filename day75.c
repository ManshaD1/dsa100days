#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

struct Pair {
    int prefixSum;
    int index;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int findIndex(struct Pair map[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].prefixSum == key)
            return map[i].index;
    }
    return -2;
}

void insert(struct Pair map[], int *size, int key, int index) {
    map[*size].prefixSum = key;
    map[*size].index = index;
    (*size)++;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair map[MAX];
    int size = 0;

    int prefixSum = 0;
    int maxLen = 0;

    insert(map, &size, 0, -1);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int prevIndex = findIndex(map, size, prefixSum);

        if (prevIndex != -2) {
            maxLen = max(maxLen, i - prevIndex);
        } else {
            insert(map, &size, prefixSum, i);
        }
    }

    printf("%d\n", maxLen);

    return 0;
}