#include <stdio.h>
#include <string.h>

#define MAX 256

char firstNonRepeatingChar(char str[]) {
    int freq[MAX] = {0};

    // Step 1: count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    // Step 2: find first non-repeating
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(int)str[i]] == 1)
            return str[i];
    }

    return '\0'; // no non-repeating character
}

int main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    char result = firstNonRepeatingChar(str);

    if (result != '\0')
        printf("First Non-Repeating Character: %c\n", result);
    else
        printf("No non-repeating character found\n");

    return 0;
}