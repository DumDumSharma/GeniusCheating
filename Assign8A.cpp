

#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2 ;
    int len1 = mid - s + 1 ;
    int len2 = e - mid ;

    int *first = new int[len1] ;
    int *second = new int[len2] ;

    int mainArrayIndex = s ;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++] ;
    }

    mainArrayIndex = mid + 1 ;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++] ;
    }
    
    int index1 = 0 ;
    int index2 = 0 ;
    mainArrayIndex = s ;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++] ;
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++] ;
        }
    }
    
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++] ;
    }
    
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++] ;
    }
    
    delete[] first ;
    delete[] second ;
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= 0)
    {
        return ;
    }

    int mid = s + (e - s) / 2 ;

    mergeSort(arr, s, mid) ;
    mergeSort(arr, mid + 1, e) ;
    merge(arr, s, e) ;
    
}

int main()
{
    int n ;
    cout << "Enter the number of students : " ;
    cin >> n ;

    if (n <= 0)
    {
        cout << "Invalid number of students!" << endl ;
        return 0 ;
    }
    
    int *arr = new int[n] ;
    cout << "Enter the credits obtained by the students : " ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    
    mergeSort(arr, 0, n - 1) ;
    
    cout << "Sorted credits : " ;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl ;

    delete[] arr ;

    return 0 ;
}
