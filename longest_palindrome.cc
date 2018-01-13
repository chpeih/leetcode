
class Solution {
public:
	int longestPalindrome(string s)
	{
		int sum = 0;
		unordered_set<char> single;
		for(int i = 0;i<s.size();i++)
		{
			auto it = single.find(s[i]);

			if(it == single.end())single.insert(s[i]);
			else
			{
				single.erase(it);
				sum+=2;
			}
		}
		if(single.size() != 0)sum++;
		return sum;
	}
};
