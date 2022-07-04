class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp sol is n^2;
        //since we want strictly increasing order, keeping shorter nums
        //is a better way;
        //but even that'll take n^2;
        //but since our formed array will be sorted, we can find the new pos
        //using bs;
        vector<int> v;
        for(auto i: nums){
            if(v.size()==0 || i>v.back()){
                v.push_back(i);
            }
            else{
                int ind=lower_bound(v.begin(), v.end(), i)-v.begin();
                v[ind]=i;
            }
        }
        return v.size();
    }
};