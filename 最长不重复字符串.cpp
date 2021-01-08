#include<iostream>
#include<vector>
#include<set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = 0;  // ������
    int count = 0;  // �Ӵ���ǰ����
    int max = 0;  // �Ӵ���󳤶�
    int index[128] = { 0 };  // ��¼ÿ���ַ����ֵ��Ⱥ�λ��
    int start = 0;  // �Ӵ���ʼλ��

    for (i = 0; s[i] != '\0'; i++)
    {
        if (index[s[i]] > start)   //��Ϊ�棬���ʾ���Ӵ���ǰ���ֹ�
        {
            count = i - start;  // ��¼��ʱ�Ӵ��ĳ���
            if (count > max)
            {
                max = count;
            }
            start = index[s[i]];  // �����Ӵ�����ʼλ��
        }
        index[s[i]] = i + 1;
    }
    count = i - start;
    return count > max ? count : max;
}