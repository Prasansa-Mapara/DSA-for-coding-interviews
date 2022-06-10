class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size(), i=0;
        vector<int> v(n, -1), cnt(1, 0);
        
        while(true){
            while(st.size() && nums[i]>nums[st.top()]){
                v[st.top()]=(v[st.top()]==-1?nums[i]:v[st.top()]);
                st.pop();
            }
            if(st.empty() || i!=st.top()){
                if(i==0){
                    if(cnt[i]<2){
                        st.push(i);
                        cnt[i]++;
                    }
                    else{
                        break;
                    }
                }
                else st.push(i);
            }
            else{
                break;
            }
            i++; i%=n;
        }
        
        return v;
    }
};