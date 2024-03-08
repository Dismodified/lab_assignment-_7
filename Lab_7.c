#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    int totalSwaps = 0; 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
                totalSwaps++; 
            }
        }
   }
   printf("Total swaps for each sort: %d\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    int original_order[n];
    int totalSwaps = 0;
    for (i = 0; i < n; i++) {
        original_order[i] = arr[i];
    }

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            totalSwaps++; 
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i] != original_order[i]) {
            swaps[arr[i]]++;
        }
    }

    printf("Total swaps for each sort: %d\n", totalSwaps); 
}


int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(array1) / sizeof(array1[0]);
    int i;
    int bubbleSwaps[100] = {0};
    int selectionSwaps[100] = {0};

    bubbleSort(array1, n, bubbleSwaps);
    bubbleSort(array2, n, bubbleSwaps);

    selectionSort(array3, n, selectionSwaps);
    selectionSort(array4, n, selectionSwaps);

    printf("array1 bubble sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", array1[i], bubbleSwaps[array1[i]]);
    }

    printf("\narray2 bubble sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", array2[i], bubbleSwaps[array2[i]]);
    }

    printf("\narray3 selection sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", array3[i], selectionSwaps[array3[i]]);
    }
  
    printf("\narray4 selection sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", array4[i], selectionSwaps[array4[i]]);
    }

    return 0;
}
