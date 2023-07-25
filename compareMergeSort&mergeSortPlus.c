#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MergeSort implementation
void Merge(int arr[], int left, int middle, int right) {
    // Same as your Merge function implementation
}

void MergeSort(int arr[], int left, int right) {
    // Same as your MergeSort function implementation
}

// MergeSortPlus implementation
void InsertionSort(int arr[], int left, int right) {
    // Same as your InsertionSort function implementation
}

void MergeSortPlus(int arr[], int left, int right, int threshold) {
    // Same as your MergeSortPlus function implementation
}

// Function to generate random arrays of a given size
void generateRandomArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
    }
}

int main() {
    int arraySizes[] = {1000, 5000, 10000, 50000, 100000};
    int threshold = 5; // Threshold for MergeSortPlus

    for (int i = 0; i < sizeof(arraySizes) / sizeof(arraySizes[0]); i++) {
        int size = arraySizes[i];
        int* arr = (int*)malloc(size * sizeof(int));

        // Generate random array
        generateRandomArray(arr, size);

        // Measure MergeSort execution time
        clock_t startMergeSort = clock();
        MergeSort(arr, 0, size - 1);
        clock_t endMergeSort = clock();
        double mergeSortDuration = (double)(endMergeSort - startMergeSort) / CLOCKS_PER_SEC;

        // Reset array for MergeSortPlus
        generateRandomArray(arr, size);

        // Measure MergeSortPlus execution time
        clock_t startMergeSortPlus = clock();
        MergeSortPlus(arr, 0, size - 1, threshold);
        clock_t endMergeSortPlus = clock();
        double mergeSortPlusDuration = (double)(endMergeSortPlus - startMergeSortPlus) / CLOCKS_PER_SEC;

        printf("Array size: %d\n", size);
        printf("MergeSort time: %f seconds\n", mergeSortDuration);
        printf("MergeSortPlus time: %f seconds\n", mergeSortPlusDuration);
        printf("\n");

        free(arr);
    }

    return 0;
}
