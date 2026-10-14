class Solution {
public:
    int similarPairs(vector<string>& words) {
        int cnt=0;
        map<string,int>m;

        for(int i =0;i<words.size();i++){
            set<char>st;

            for(int j=0;j<words[i].size();j++)
                st.insert(words[i][j]);

            string s;

            for(auto x:st)
                s += x;
            m[s]++;
        }
        for(auto it:m){
            int y=(it.second-1)*(it.second)/2;
            cnt+=y;
        }
        return cnt;
    }
};