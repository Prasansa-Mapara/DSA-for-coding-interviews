class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s;
        for(auto i: strs){
            s+=to_string(i.size())+"#"+i;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n=s.size(), i=0;
        //i will be pointing at num, and j will be pointing at #;
        vector<string> sol;
        while(i<n){
            int j=i+1;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i, j-i));
            string tmp;
            j++;
            while(len--){
                tmp.push_back(s[j]);
                j++;
            }
            sol.push_back(tmp);
            i=j;
        }
        return sol;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));