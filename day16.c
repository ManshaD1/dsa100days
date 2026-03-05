#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], used[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        used[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                used[j] = 1;
            }
        }
        printf("%d:%d ", arr[i], count);
    }
    return 0;
}