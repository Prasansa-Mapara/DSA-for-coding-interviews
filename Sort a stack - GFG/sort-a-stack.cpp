// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   stack<int> s1;
   while(s.size()){
       int x=s.top();
       s.pop();
       if(s1.empty() || x>=s1.top()){
           s1.push(x);
       }
       else{
           while(s1.size() && x<s1.top()){
               s.push(s1.top());
               s1.pop();
           }
           s1.push(x);
       }
   }
   s=s1;
   return;
}