/*
class Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }

}; */

class Solution {
  public:
    int getMiddle(Node* head) {
        // code here
        
        if(head==nullptr){
            return head->data;
        }
        
        Node* fast= head;
        Node* slow= head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};