#include <stdio.h>
#include <time.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key = 40;

    clock_t start, end;
    double time_interval;

    start = clock(); 

    linearSearch(arr, n, key);

    end = clock();   

    time_interval = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time interval: %f seconds\n", time_interval);

    return 0;
}
