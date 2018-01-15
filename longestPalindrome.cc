

class Solution {
	string longestPalindrome(string s) {
		string news = "#";
		for(int i = 0;i<s.size();i++){
			news.push_back(s[i]);
			news.push_back('#');
		}		
		news.push_back('$');
		int nlen = news.size();
		vector<int> dp(nlen, 0);
		int maxn = 0;
		int maxl = 0;
		for(int i = 0; i<nlen;i++)
		{
			if(maxn>i){
				dp[i] = dp[2*maxl-i];
				if(dp[i]+i>maxn)dp[i] = maxn-i;
			}
			while(i+dp[i]+1<nlen && i-dp[i]-1>=0 && news[i+dp[i]+1] == news[i-dp[i]-1])
			{
				dp[i]++;
				if(i+dp[i]>maxn)
				{
					maxn = i+dp[i];
					maxl = i;
				}
			}
		}

		int m = -1, c = 0;
		for(int i = 0;i<dp.size();i++)
		{
			if(dp[i]>m)
			{
				m = dp[i];
				c = i;
			}
		}	

		string ans;
		for(int i = c-dp[c];i<=c+dp[c];i++)
		{
			if(news[i]=='#')continue;
			ans.push_back(news[i]);
		}	
		return ans;

	}
};
