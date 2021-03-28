//找出数组中重复的数字。在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
#include <stdio.h>
int findRepeatNumber(int *nums, int numsSize)
{
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        while (nums[i] != i)
        {
            if (nums[nums[i]] == nums[i])//建立索引
            {
                return nums[i];
            }
            int temp = nums[nums[i]];//将数组中数字和索引对上，若没有对上则交换
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
    }
    return -1;
}
int main()
{
    int nums[16] = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    printf("%d", findRepeatNumber(nums, 16));
    return 0;
}