// solution1 DFS
class Solution {
public:
	vector<vector<string>> partition(string s) 
	{
		vector<vector<string>> result;
		vector<string> path;
		dfs(result, path, s, 0);
		return result;
	}
    bool isValidPalindrome(string s,int start,int end)
	{
		if (s.size() <= 1)
		{
			return true;
		}
		for (int i = start, j =end; i < j; i++, j--)
		{
			if (s[i] != s[j])
			{
				return false;
			}

		}
		return true;

	}

	void dfs(vector<vector<string>>&result, vector<string>&path, string s, int start)
	{
		if (start == s.size())
		{
			result.push_back(path);
		}
		for (int i = start; i < s.size();i++)
		{
			if (isValidPalindrome(s, start, i))
			{
				path.push_back(s.substr(start, i - start + 1));
				dfs(result, path, s, i + 1);
				path.pop_back();
			}
		}

	}

};
