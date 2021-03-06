一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

如果是一个只出现一次的数字，那么可以采用异或的方式来。。。因为异或的定义就是相同的为0，不同的为1。
这个题目是找两个。那么将其拆分成两个，每个分别找一个，就行了。

拆法：
将数组的所有数字进行异或，得到的结果一定是两个不同的数的异或，所以我们可以找到这个结果值的第一位为1的那个数字的位置，然后按照这位是否为1，将数组中
的数字拆成两个。分别进行寻找。
上面的那个算法的时间的复杂度是O（n）

我的想法是，先将数组排序然后，再遍历寻找。

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int tmp=0;
        for(auto & d : data)
        {
            tmp = tmp ^ d;
        }
        int i =0;
        while(tmp > 0)
        {
            if((tmp & 1) == 1)
            {
                break;
            }
            tmp = tmp >> 1;
            ++i;
        }
        i = 1 << i;
        int n1=0,n2 = 0;
        for(auto & d :data)
        {
            if((d & i) == i){
                n1 = n1 ^ d;
            }
            else{
                n2 = n2 ^ d;
            }
        }
        *num1 = n1;
        *num2 = n2;
    }
};
