#include <iostream>
#include <string>
using namespace std;


int partition(int arr[], string names[], int s, int e) {
    int pivot = arr[s]; 
    int cnt = 0;


    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }


    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]); 
    swap(names[pivotIndex], names[s]); 


    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) 
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < pivotIndex && j > pivotIndex) 
        {
            swap(arr[i++], arr[j--]);
            swap(names[i], names[j]); 
        }
    }

    return pivotIndex; 
}


void quickSort(int arr[], string names[], int s, int e) {
    if (s >= e)
        return;

    int p = partition(arr, names, s, e); 
    quickSort(arr, names, s, p - 1);    
    quickSort(arr, names, p + 1, e);    
}

int main() {
    int n;


    cout << "Enter the number of students: ";
    cin >> n;

    int credits[n];
    string names[n];


    cout << "Enter the names and credits of students:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "Student " << i + 1 << " Name: ";
        cin >> names[i];
        cout << "Student " << i + 1 << " Credits: ";
        cin >> credits[i];
    }


    quickSort(credits, names, 0, n - 1);


    cout << "\nSorted Credits and Names:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << names[i] << ": " << credits[i] << endl;
    }

    
    cout << "\nTop 3 Students:\n";
    for (int i = n - 1; i >= max(0, n - 3); i--) 
    { 
        cout << names[i] << ": " << credits[i] << endl;
    }

    return 0;
}
