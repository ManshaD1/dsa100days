#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int left = 0, right = n-1;
    int min_sum = 2147483647; // max int
    int a = arr[left], b = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(min_sum)) {
            min_sum = sum;
            a = arr[left];
            b = arr[right];
        }
        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", a, b);
    return 0;
}