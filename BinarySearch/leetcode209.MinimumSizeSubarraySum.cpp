//solutin 1  Two Pointer
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        int min=INT_MAX;
        int sum=0;
        int start=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            while(sum>=s)
            {
                if(i-start+1<min)
                {
                    min=i-start+1;
                }
                sum=sum-nums[start++];
            }
        }
        if(min==INT_MAX)
        {
            return 0;
        }
        return min;
        
    }
};
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return 0;
        }
        int min=INT_MAX;
        int slow=0,fast=0,sum=0;
        while(fast<nums.size())
        {
            sum=sum+nums[fast++];
            while(sum>=s)
            {
                if(fast-slow<min)
                {
                    min=fast-slow;
                }
                sum=sum-nums[slow++];
            }
        }
        if(min==INT_MAX)
        {
            return 0;
        }
        return min;
        
    }
};
//Binary Search
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int beginlength=1;
        int endlength=nums.size();
        int min=0;
        while(beginlength<=endlength)
        {
            int middlelength=(beginlength+endlength)/2;
            if(checkWidthLen(middlelength,s,nums))
            {
                endlength=middlelength-1;
                min=middlelength;
            }
            else
            {
                beginlength=middlelength+1;
            }
        }
        
        return min;
    }
    bool checkWidthLen(int len,int s,vector<int> &nums)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>=len)
            {
                sum=sum-nums[i-len];
            }
            sum=sum+nums[i];
            if(sum>=s)
            {
                return true;
            }
        }
        return false;
    }
};