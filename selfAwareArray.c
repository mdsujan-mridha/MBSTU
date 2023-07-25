#include <stdio.h>
#include <stdbool.h>

bool isSelfAware(int arr[], int n) {
    bool flags[n];
    int i;

    // Initialize flags to false
    for (i = 0; i < n; i++) {
        flags[i] = false;
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0 || arr[i] >= n) {
            return false; // Element is out of range
        }

        if (flags[arr[i]]) {
            return false; // Duplicate element found
        }

        flags[arr[i]] = true;
    }

    // Check if all flags are true 
    for (i = 0; i < n; i++) {
        if (!flags[i]) {
            return false; // Missing element
        }
    }

    return true;
}

int main() {
    int inputArray1[] = {0, 1, 2, 3, 4};
    int inputArray2[] = {2, 1, 0, 3, 4};
    int inputArray3[] = {0, 1, 2, 4, 4};
    int n = sizeof(inputArray1) / sizeof(inputArray1[0]);

    printf("%s\n", isSelfAware(inputArray1, n) ? "true" : "false"); // Output: true
    printf("%s\n", isSelfAware(inputArray2, n) ? "true" : "false"); // Output: false (not self-aware)
    printf("%s\n", isSelfAware(inputArray3, n) ? "true" : "false"); // Output: false (not self-aware)

    return 0;
}
