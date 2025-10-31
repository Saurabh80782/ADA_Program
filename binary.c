#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Binary search function
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Sorted array generate karne ka function
void generateSortedArray(int *arr, int n) {
    arr[0] = rand() % 10 + 1;
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + (rand() % 10 + 1);
}

int main() {
    // Array sizes ko exponentially badhaya hai
    int sizes[] = {1000, 2000, 4000, 8000, 16000, 32000, 64000,
                   128000, 256000, 512000, 1024000, 2048000,
                   4096000, 8192000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(0));

    printf("Array Size\tTime per search (ns)\n");
    printf("----------------------------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        generateSortedArray(arr, n);

        // Worst-case scenario ke liye key
int key = arr[n - 1] + 1;

// Iterations ko dynamically set kiya based on array size
long iterations = 50000000 / (int)(log2(n) + 1);
if (iterations < 100000) iterations = 100000;

// Time measurement start
clock_t start = clock();

// Optimization prevent karne ke liye
int dummy = 0;
for (long i = 0; i < iterations; i++) {
    // Key ko thoda change kiya har iteration mein
    int current_key = key + (i % 3);
    int result = binarySearch(arr, n, current_key);
    dummy += result; // Result use kiya
}

clock_t end = clock();

double total_time_sec = (double)(end - start) / CLOCKS_PER_SEC;
double time_per_search_ns = (total_time_sec * 1e9) / iterations;
double log2n = log2(n);

printf("%d\t\t%.2f\t", n, time_per_search_ns);

free(arr);
}
return 0;
