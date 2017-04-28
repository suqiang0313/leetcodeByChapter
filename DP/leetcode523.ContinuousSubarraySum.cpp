// solution 1 baoli
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if(k<0)
        {
            k=-k;
        }
        for(int i=0;i<nums.size();i++)
        {
            int sum=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                sum=sum+nums[j];
                if(k>0&&sum%k==0&&(j-i)>=1)
                {
                    return true;
                }
                if(k==0&&sum==0&&(j-i)>=1)
                {
                    return true;
                }
                
            }
        }
        return false;
        
    }
};
//Solution 2 math
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        if(nums.size()<=1)
        {
            return false;
        }
        unordered_map<int,int> hash;
        hash[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(k!=0)
            {
                sum=sum%k;
            }
            if(hash.find(sum)==hash.end())
            {
                hash[sum]=i;
            }
            else
            {
                if(i-hash[sum]>1)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};
//DP
bool checkSubarraySum(vector<int>& nums, int k)
{
    int size=nums.size();
    if(nums.size()<=1)
    {
        return false;
    }
    int sum=0;
    for (int i = 0; i < nums.size()-1; ++i)
    {
        /* code */
        sum=sum+nums[i];
        if(nums[i]==0&&nums[i+1]==0)
        {
            return true;
        }
    }
    if(k==0)
    {
        if(sum==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    vector<int>dp(size,0);
    for(int i=nums.size()-1;i>=0;i--)
    {
        dp[i]=nums[i];
        for(int j=i+1;j<nums.size();j++)
        {
            dp[j]=dp[j]+nums[i];
            if(dp[j]%k==0)
            {
                return true;
            }
        }
    }
    return false;
}
