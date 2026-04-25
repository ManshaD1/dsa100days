#include <stdio.h>
#include <string.h>

#define MAX 256

char firstRepeatedChar(char str[]) {
    int freq[MAX] = {0};

    // count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
    }

    // find first repeated character
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(int)str[i]] > 1)
            return str[i];
    }

    return '\0'; // no repeated character
}

int main() {
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    char result = firstRepeatedChar(str);

    if (result != '\0')
        printf("First Repeated Character: %c\n", result);
    else
        printf("No repeated character\n");

    return 0;
}