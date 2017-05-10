// Solutin 241 
// method1 divide and conquer
class Solution {
public:
    vector<int> dfs(string s)
    {
        vector<int> index;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c=='*'||c=='+'||c=='-')
            {
                index.push_back(i);
            }
        }
        vector<int> res;
        if(index.size()==0)
        {
            int num;
            stringstream ss(s);
            ss>>num;
            res.push_back(num);
            return res;
        }
        for(int i=0;i<index.size();i++)
        {
            char op=s[index[i]];
            vector<int> a=dfs(s.substr(0,index[i]));
            vector<int> b=dfs(s.substr(index[i]+1));
            for(int a1=0;a1<a.size();a1++)
            {
                for(int b1=0;b1<b.size();b1++)
                {
                    if(op=='-')
                    {
                        res.push_back(a[a1]-b[b1]);
                    }
                    if(op=='+')
                    {
                        res.push_back(a[a1]+b[b1]);
                    }
                    if(op=='*')
                    {
                        res.push_back(a[a1]*b[b1]);
                    }
                }
            }
        }
        return res;
        
        
    }
    vector<int> diffWaysToCompute(string input) 
    {
        vector<int> result;
        result=dfs(input);
        return result;
        
    }
};
// use hash to store 
class Solution {
public:
    vector<int> dfs(string s,unordered_map<string,vector<int>>& hash)
    {
        if (hash.count(s) != 0)
        {
            return hash[s]; 
        }
        vector<int> index;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '*' || c == '+' || c == '-')
            {
                index.push_back(i);
            }
        }
        vector<int> res;
        if (index.size() == 0)
        {
            int num;
            stringstream ss(s);
            ss >> num;
            res.push_back(num);
            return res;
        }
        for (int i = 0; i < index.size(); i++)
        {
            char op = s[index[i]];
            vector<int> a = dfs(s.substr(0, index[i]),hash);
            vector<int> b = dfs(s.substr(index[i] + 1),hash);
            for (int a1 = 0; a1 < a.size(); a1++)
            {
                for (int b1 = 0; b1 < b.size(); b1++)
                {
                    if (op == '-')
                    {
                        res.push_back(a[a1] - b[b1]);
                    }
                    if (op == '+')
                    {
                        res.push_back(a[a1] + b[b1]);
                    }
                    if (op == '*')
                    {
                        res.push_back(a[a1] * b[b1]);
                    }
                }
            }
        }
        hash[s] = res;
        return res;


    }
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> result;
        unordered_map<string, vector<int>> hash;
        result = dfs(input,hash);
        return result;

    }
};
