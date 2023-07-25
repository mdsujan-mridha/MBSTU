#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For getRandomInteger function
#include <time.h>   // For seeding random number generator

// Function to generate a random integer between 0 and 1 (inclusive)
int getRandomInteger() {
    return rand() % 2;
}

// Slow Binary Search
bool slowBinSearch(int arr[], int x, int lower, int upper) {
    if (lower > upper) {
        return false; // Element not found
    }

    int mid = (upper + lower) / 2;

    if (x == arr[mid]) {
        return true; // Element found at index mid
    }
    else if (getRandomInteger() % 2 == 0) {
        if (x < arr[mid]) {
            return slowBinSearch(arr, x, lower, mid - 1); // Search left half
        }
        else {
            return slowBinSearch(arr, x, mid + 1, upper); // Search right half
        }
    }
    else {
        return slowBinSearch(arr, x, lower, upper); // Wasted self-call
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool result = slowBinSearch(arr, target, 0, n - 1);

    if (result) {
        printf("Element %d found in the array.\n", target);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
