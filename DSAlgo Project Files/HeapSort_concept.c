//#include <stdio.h>

//void heapify(int array1[], int n, int i)
//{
//    int big = i,left = 2 * i + 1,right = 2 * i + 2;
//    if (left < n && array1[left] > array1[big])
//      big = left;
//    if (right < n && array1[right] > array1[big])
//      big = right;
//    if (big != i)
//    {
//      swaping_function(&array1[i], &array1[big]);
//      heapify(array1, n, big);
//    }
//  }
//
//void heapSort(int array1[], int num)
//{
//    int i;
//    for (i =(num/2)-1;i>=0;i--)
//      heapify(array1, num, i);
//    for (int i = num - 1; i >= 0; i--)
//    {
//      swaping_function(array1[0],array1[i]);
//      heapify(array1, i, 0);
//    }
//}
//
//void swaping_function(int a1, int a2)
//{
//    int temp;
//    temp = a1;
//    a1 = a2;
//    a2 = temp;
//    return;
//}
//
//void display(int array1[], int n)
//{
//    for (int i = 0; i < n; ++i)
//    {
//        printf("%d ", array1[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    int a[20],len,i;
//    printf("enter size\n");
//    scanf("%d",&len);
//    printf("enter data\n");
//    for(i=0;i<len;i++)
//    {
//        scanf("%d",&a[i]);
//    }
//    heapSort(a,len);
//    printf("Sorted array is \n");
//    display(a,len);
//    return 0;
//}

#include <stdio.h>

  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }

  void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }


  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  int main() {
    int arr[20],len,i;
    printf("enter size\n");
    scanf("%d",&len);
    printf("enter data\n");
    for(i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, len);
    printf("Sorted array is \n");
    printArray(arr, len);
  }



