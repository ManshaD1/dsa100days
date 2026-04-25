#include <stdio.h>
#include <string.h>

#define MAX_N 1000
#define MAX_LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX_N][MAX_LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names lexicographically
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[MAX_LEN];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    char best[MAX_LEN];
    int maxCount = 0;

    int i = 0;
    while (i < n) {
        int j = i;
        int count = 0;

        while (j < n && strcmp(names[i], names[j]) == 0) {
            count++;
            j++;
        }

        if (count > maxCount) {
            maxCount = count;
            strcpy(best, names[i]);
        }

        i = j;
    }

    printf("%s\n", best);

    return 0;
}