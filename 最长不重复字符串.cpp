#include<iostream>
#include<vector>
#include<set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = 0;  // 计数器
    int count = 0;  // 子串当前长度
    int max = 0;  // 子串最大长度
    int index[128] = { 0 };  // 记录每个字符出现的先后位置
    int start = 0;  // 子串起始位置

    for (i = 0; s[i] != '\0'; i++)
    {
        if (index[s[i]] > start)   //若为真，则表示该子串以前出现过
        {
            count = i - start;  // 记录此时子串的长度
            if (count > max)
            {
                max = count;
            }
            start = index[s[i]];  // 更新子串的起始位置
        }
        index[s[i]] = i + 1;
    }
    count = i - start;
    return count > max ? count : max;
}