//http://www.cnblogs.com/futurehau/articles/5837891.html
//二分法注意点：
/*
1. mid = start + (end - start) / 2;//特定情况下，避免越界。

2.循环控制条件：start + 1 < end，这样处理的好处是可以避免使用start<end或者start<=end对于不同情况的不同处理逻辑。

3.理解二分法的三个层次：

保留首位两个指针，取重点，判断往哪儿走
保留下来的那一半是需要的那一半
满足某个条件的第一个/最后一个位置
*/
public int findPosition(int[] nums, int target) 
{
        // Write your code here
        if(nums == null || nums.length == 0)
            return -1;
        int start = 0;
        int end = nums.length-1;
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else 
            	if(nums[mid] < target)
            	{
            		start = mid;
            	}
            	else
            	{
            		end = mid;
            	}
        }
        if(nums[start] == target)
            return start;
        if(nums[end] == target)
            return end;
        return -1;
}