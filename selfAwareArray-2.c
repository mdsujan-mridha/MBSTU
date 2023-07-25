#include <stdio.h>
#include <stdbool.h>

bool isUnique(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return false;
        }
    }
    return true;
}

void generateSelfAwareArrays(int arr[], int index, int n) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int num = 0; num < n; num++) {
        if (isUnique(arr, index, num)) {
            arr[index] = num;
            generateSelfAwareArrays(arr, index + 1, n);
            arr[index] = -1; // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = -1; // Initialize the array with -1 to indicate empty slots
    }

    generateSelfAwareArrays(arr, 0, n);

    return 0;
}


// Time complexity os : time complexity of O(n!).