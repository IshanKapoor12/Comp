#include <stdio.h>

#define ARRAY_SIZE 10

void loop_unrolled_sum(int arr[], int n) {
    int sum = 0;

    for(int i = 0; i < n; i += 5) {
        sum += arr[i];
        sum += arr[i + 1];
        sum += arr[i + 2];
        sum += arr[i + 3];
        sum += arr[i + 4];
    }
    printf("Sum: %d\n", sum);
}

int main() {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    loop_unrolled_sum(arr, ARRAY_SIZE);
    return 0;
}

