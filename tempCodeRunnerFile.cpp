#include<bits/stdc++.h>

using namespace std ;

void findMaxMinMarks(vector<int> &marks)
{
    priority_queue<int, vector<int> , greater<int>> minHeap(marks.begin(), marks.end()) ;

    priority_queue<int> maxHeap(marks.begin(), marks.end()) ;

    int minMarks = minHeap.top() ;

    int maxmarks = maxHeap.top() ;

    cout << "Minimum marks : " << minMarks << endl ;
    cout << "Maximum marks : " << maxmarks << endl ;
}

int main()
{
    vector<int> marks ;
    int choice ;

    do
    {
        cout << "Menu" << endl ;
        cout << "1. Add Marks" << endl ;
        cout << "Display all marks" << endl ;
        cout << "3. Find Minimum and Maximum marks" << endl ;
        cout << "4.Exists" << endl ;
        cout << "Enter your choice : " << endl ;
        cin >> choice ;
        switch (choice)
        {
        case 1:
            int mark;
            cout << "Enter marks to add : " ;
            cin >> mark ;
            marks.push_back(mark) ;
            cout << "Marks added successfully" << endl ;
            break;
        
        case 2 : 
            if (marks.size() == 0)
            {
                cout << "No marks added yet" << endl ;
            }
            else
            {
                for (int i = 0; i < marks.size(); i++)
                {
                    cout << marks[i] << " " ;
                }
            }
            
            break;
        
        case 3 :
            findMaxMinMarks(marks) ;
            break;

        case 4 :
            cout << "Existing Program. Goodbye" << endl ;
            break;

        default:
        cout << "Invalid choice. Please try again" << endl ;
            break;
        }
    } while (choice != 4);
    
    return 0;
}
