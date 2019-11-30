/*
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/guess-number-higher-or-lower/
作者：shicy
日期：2019-11-30

我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！

示例 :
输入: n = 10, pick = 6
输出: 6
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        unsigned int low = 1, high = n, mid = 0;
        int t;
        
        while (low <= high)
        {
            mid = (low + high)/2;
            t = guess(mid);
            
            if(t == 0)
                return mid;
            else if(t == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
};