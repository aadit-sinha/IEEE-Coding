#include <stdio.h>
#include <string.h>

int matches(int count1[], int count2[]) {
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return 0;
        }
    }

    return 1;
}

int checkInclusion(char s1[], char s2[]) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    if (n1 > n2) {
        return 0;
    }

    int count1[26] = {0};
    int count2[26] = {0};

    // Count characters in s1
    for (int i = 0; i < n1; i++) {
        count1[s1[i] - 'a']++;
    }

    // Create the first window in s2
    for (int i = 0; i < n1; i++) {
        count2[s2[i] - 'a']++;
    }

    // Check the first window
    if (matches(count1, count2)) {
        return 1;
    }

    // Slide the window
    for (int i = n1; i < n2; i++) {
        count2[s2[i - n1] - 'a']--;
        count2[s2[i] - 'a']++;

        if (matches(count1, count2)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char s1[] = "ab";
    char s2[] = "eidbaooo";

    int result = checkInclusion(s1, s2);

    if (result) {
        printf("Permutation exists\n");
    } else {
        printf("Permutation does not exist\n");
    }

    return 0;
}