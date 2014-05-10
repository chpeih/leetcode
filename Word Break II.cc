class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< string > ans;
        
        if(s.size()==0 || dict.size()==0)return ans;
        vector<int>  dp;
        dp.resize(s.size()+1);
        dp[s.size()] = 1;
        for(int i = s.size()-1;i>=0;i--){
            //int is = 0;
            string k;
            for(int j = i;j<s.size();j++){
                k.push_back(s[j]);
                if(dp[j+1]==1 && dict.find(k)!=dict.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        string tmp,a;
        dfs(s,ans,0,tmp,dict,dp);
        return ans;
        
    }
    void dfs(string &s,vector<string> &ans,int from,string tmp,unordered_set<string> &dict,vector<int> &dp){
        if(from==s.size()){
            tmp.pop_back();
            ans.push_back(tmp);
            return ;
        }
        string k;
        for(int i = from;i<s.size();i++){
            k.push_back(s[i]);
            if(dp[i+1]==1 && dict.find(k)!=dict.end()){
                string t = tmp;
                t = t+k+" ";
                dfs(s,ans,i+1,t,dict,dp);
            }
        }
    }
};
