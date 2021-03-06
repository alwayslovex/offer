/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *///单链表排序。由于是nlogn所以应该可以用归并排序。但是题目是要求是常数的空间复杂度所以不能用递归。
//这个是非递归版的。参考https://yq.aliyun.com/articles/334408
class Solution {
public:
    int Getlen(ListNode * root){
        int cnt = 0;
        while(root != nullptr){
            cnt++;
            root = root->next;
        }
        return cnt;
    }
    ListNode * sortList(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode tmp(0);
        tmp.next = head;
        int len = Getlen(head);
        for(int i = 1;i < len;i*=2){
            ListNode * pre = &tmp;
            ListNode * left = tmp.next;
            ListNode * right = tmp.next;

            while(left != nullptr || right != nullptr){
            
                for(int j =0;j < i && right != nullptr;++j){
                    right = right->next;
                }

                int start1 = 0;
                int start2 = 0;

                while(start1 < i && start2 < i && left != nullptr && right != nullptr){
                    if(left->val >= right->val){
                            pre->next = right;
                            right = right->next;
                            pre = pre->next;
                            pre->next = nullptr;
                            start2++;
                    }else{
                            pre->next = left;
                            left = left->next;
                            pre = pre->next;
                            pre->next = nullptr;
                            start1++;
                    }
                }
                while(start1 < i && left != nullptr){
                    pre->next = left;
                    start1++;
                    left = left->next;
                    pre = pre->next;

                }
                while(start2 < i && right != nullptr){
                    pre->next = right;
                    start2++;
                    right = right->next;
                    pre = pre->next;
                }
                
                left = right;
                pre->next = right;

            }
        }
        return tmp.next;
    }
};


//以下是递归版的//未进行校验
