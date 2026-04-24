class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);//dummy head
        ListNode* temp = dummy;
        ListNode* temp1 = head1;//for list1
        ListNode* temp2 = head2;//for list2

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val<=temp2->val){//yhan pe pehli wali list ki value compare ho rhi hai
                temp->next = temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;//if first list not greater than take from the second list
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1!=nullptr){//last wale ke liye
            temp->next = temp1;
        }else{
            temp->next = temp2;
        }

        return dummy->next;
    }
};