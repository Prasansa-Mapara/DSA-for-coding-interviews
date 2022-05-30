// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool comp(Job a, Job b){
    return a.profit>b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //we want max profit, we also wanna do job on the last day;
        //basically, dor each day, i want the max profit;
        sort(arr, arr+n, comp);
        //now, jobs are sorted based on max profit;
        
        int mxd=0, prof=0, jb=0;
        for(int i=0; i<n; i++){
            mxd=max(mxd, arr[i].dead);
        }
        vector<int> d(mxd+1, -1);
        for(int i=0; i<n; i++){
            int curP=arr[i].profit, curD=arr[i].dead;
            for(int j=curD; j>0; j--){ //we wanna select the last day;
                if(d[j]==-1){ //if this day's free
                    d[j]=1;
                    prof+=curP;
                    jb++;
                    break;
                }
            }
        }
        return {jb, prof};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends