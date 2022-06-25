class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> sol(n, 0);
        deque<int> dq;
        //maintain a decreasing order;
        for(int i=0; i<n; i++){
            while(dq.size() && temp[i]>temp[dq.back()]){
                int prev=dq.back(); //curr temp is greater than prev temp;
                dq.pop_back();
                sol[prev]=i-prev;
            } 
            dq.push_back(i);            
        }
        return sol;
    }
};