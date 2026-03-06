#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Array to store the last index of each character
    // Initialized to -1 (meaning character hasn't been seen)
    int lastSeen[128];
    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        unsigned char currChar = s[right];

        // If the character was seen before and is within the current window
        if (lastSeen[currChar] >= left) {
            // Shrink the window by moving 'left' to the right of the previous occurrence
            left = lastSeen[currChar] + 1;
        }

        // Update the character's last seen position
        lastSeen[currChar] = right;

        // Update global max length
        maxLength = MAX(maxLength, right - left + 1);
    }

    return maxLength;
}
