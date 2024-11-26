




#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

struct Item 
{
    int value, weight ;
} ;

bool static comp(Item a , Item b)
{
    double r1 = double(a.value) / double(a.weight) ;
    double r2 = double(b.value) / double(b.weight) ;
    return r1 > r2 ;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n , comp) ; 

    int currWeight = 0 ;
    double finalValue = 0.0 ;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= W)    
        {
            currWeight += arr[i].weight ;
            finalValue += arr[i].value ;
        }
        else
        {
            int remain = W - currWeight ;
            finalValue += (arr[i].value / double(arr[i].weight)) * double(remain) ;
            break;
        }
    }
        return finalValue ;
    
}

int main()
{
    int n, W ;
    cout << "Enter the number of items : " ;
    cin >> n ;
    
    cout << "Enter the capacity of the knapsack : " ;
    cin >> W ;

    Item* arr = new Item[n] ;

    cout << "Enter the value and weight of each item : " << endl ;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << endl ;
        cout << "Value : " ;
        cin >> arr[i].value ;
        cout << "Weight : " ;
        cin >> arr[i].weight ;
    }


    double maxValue = fractionalKnapsack(W, arr, n) ;
    cout << "The maximum total value in the knapsack is : " << maxValue << endl ;
    
    delete[] arr ;

    return 0 ;
}


/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

struct Item 
{
    int value , weight ;
} ;

bool static comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight ;
    double r2 = (double)b.value / (double)b.weight ;

    return r1 > r2 ;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), comp) ;

    int n = items.size() ;
    int currWeight = 0 ;
    double finalValue = 0 ;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].weight <= W)
        {
            currWeight += items[i].weight ;
            finalValue += items[i].value ;
        }
        else
        {
            int remain = W = currWeight ;
            finalValue += (((double)items[i].value) / ((double)items[i].weight) * remain) ;
            break ;
        }
        
        return finalValue ;
    }
}

void displayItems(vector<Item> &items)
{
    cout << "Items : " << endl ;
    cout << "Index\tValue\tWeight" << endl ;

    for (int i = 0; i < items.size(); i++)
    {
        cout << i + 1 << "\t" << items[i].value << "\t" << items[i].weight << "\t" << endl ;
    }
    
}

int main()
{
    vector<Item> items ;
    int choice, W ;

    do
    {
        cout << "Menu"
    } while (choice != 5);
    

    return 0 ;
}
*/