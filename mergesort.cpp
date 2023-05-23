#include <iostream>
#include <vector>

// Function to merge two subarrays
void merge(std::vector<int> &arr, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    std::vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Function to print the array
void printArray(const std::vector<int> &arr)
{
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

// Example usage
int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arrSize = arr.size();

    std::cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arrSize - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
