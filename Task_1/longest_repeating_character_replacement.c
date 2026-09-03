#include <stdio.h>
#include <string.h>

int characterReplacement(char s[], int k) {
    int count[26] = {0};

    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < strlen(s); right++) {

        count[s[right] - 'A']++;

        if (count[s[right] - 'A'] > maxFreq) {
            maxFreq = count[s[right] - 'A'];
        }

        // Number of characters that need to be replaced
        int windowLength = right - left + 1;
        int replacements = windowLength - maxFreq;

        // If replacements are more than k, shrink the window
        while (replacements > k) {
            count[s[left] - 'A']--;
            left++;

            windowLength = right - left + 1;
            replacements = windowLength - maxFreq;
        }

        if (windowLength > maxLength) {
            maxLength = windowLength;
        }
    }

    return maxLength;
}

int main() {
    char s[] = "AABABBBBA";
    int k = 1;

    int result = characterReplacement(s, k);

    printf("Longest Repeating Character Substring = %d\n", result);

    return 0;
}