bool cmp(string s1, string s2){
    string a=s1.substr(0, s1.find(":")), b=s2.substr(0, s2.find(":"));
    if(stoi(a)==stoi(b)){
        string c=s1.substr(s1.find(":")+1), d=s2.substr(s2.find(":")+1);
        return stoi(c)<stoi(d);
    }
    return stoi(a)<stoi(b);
}

class Solution {
public:
    int findMinDifference(vector<string>& pts) {
        int n=pts.size(), ans=INT_MAX;
        sort(pts.begin(), pts.end(), cmp);
        /*for(int i=0; i<n; i++){
            cout<<pts[i]<<" ";
        }
        cout<<endl;*/
        for(int i=1; i<n; i++){
            string s1=pts[i-1], s2=pts[i];
            int h1=stoi(s1.substr(0, s1.find(":"))), m1=stoi(s1.substr(s1.find(":")+1)), a=m1+h1*60;
            int h2=stoi(s2.substr(0, s2.find(":"))), m2=stoi(s2.substr(s2.find(":")+1)), b=m2+h2*60;
            ans=min(ans, abs(b-a)); //1439
        }
        string s1=pts[0], s2=pts[n-1];
        int h1=stoi(s1.substr(0, s1.find(":"))), m1=stoi(s1.substr(s1.find(":")+1));
        int h2=stoi(s2.substr(0, s2.find(":"))), m2=stoi(s2.substr(s2.find(":")+1));
        h1+=24;
        int a=m1+h1*60, b=m2+h2*60;
        ans=min(ans, abs(b-a));
        return ans;
    }
};