// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> v;
        for(int i=0; i<n; i++){
            double j=(double)arr[i].value/(double)arr[i].weight;
            v.push_back({j, arr[i].weight});
        }
        //v=[{6.00, 10}, {5.00, 20}, {4.00, 30}]
        sort(v.rbegin(), v.rend());
        double sol=0; //240.00
        for(int i=0; i<n; i++){
            double val=v[i].first;
            int w=v[i].second, t=min(W, w);
            if(t==0) return sol;
            sol+=val*t;
            W-=t; //0
        }
        return sol;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends