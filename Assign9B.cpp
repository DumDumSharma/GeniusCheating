


#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

struct Job
{
    char ID ;
    int deadline ;
    int profit ;
} ;

static bool cmp(Job a , Job b)
{
    return a.profit > b.profit ;
}

vector <int> JobScheduling(Job jobs[], int n)
{
    sort(jobs, jobs + n , cmp) ;
    int maxDeadline = INT_MIN ;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline) ;
    }
    vector<int> schedule(maxDeadline + 1, -1);
    int cnt = 0 ;
    int maxProfit = 0 ;
    vector<int> selectedJobs ;

    for (int i = 0; i < n; i++)
    {
        int currProfit = jobs[i].profit ;
        int currDeadline = jobs[i].ID ;
        int currJobID = jobs[i].ID ;

        for (int k = currDeadline; k > 0 ; k--)
        {
            if (schedule[k] == -1)
            {
                cnt++ ;
                maxProfit += currProfit ;
                schedule[k] = i ;
                selectedJobs.push_back(currJobID) ;
                break;
            }
        }
    }

    cout << "Selected jobs with deadlines : " << endl ;
    for (int i = 1; i < maxDeadline; i++)
    {
        if (schedule[i] != -1)
        {
            cout << "Job " << jobs[schedule[i]].ID << " at time " << i << endl ;
        }
        
    }
    
    return {cnt, maxProfit} ;
}

int main()
{
    int n ;
    cout << "Enter the number of jobs : " ;
    cin >> n ;

    Job jobs[n] ;
    cout << "Enter job deatils (ID , deadline Profit) :" << endl ;
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i + 1 << " : " ;
        cin >> jobs[i].ID >> jobs[i].deadline >> jobs[i].profit ;
    }
    
    vector<int> result = JobScheduling(jobs, n) ;
    cout << "Number of jobs done : " << result[0] << endl ;
    cout << "Maximum Profit : " << result[1] << endl ;

    return 0 ;
}