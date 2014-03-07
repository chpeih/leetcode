class Solution {
public:
    void reverseWords(string &s) {
        if ("" == s)return;
        std::string sTemp;
        const int n = s.length();
        for(int i = n-1; i >= 0; i--){
            while(i>=0 && s[i]==' ')i--;
            if (i < 0)break;
            if (!sTemp.empty())sTemp.push_back(' ');
            std::string tmp;
            while (i>=0 && s[i]!=' ')
                tmp.push_back(s[i--]);
            reverse(tmp.begin(), tmp.end());
            sTemp+=tmp;
        }
        s = sTemp;
    }
};
