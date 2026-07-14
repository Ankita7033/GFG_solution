/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        vector<int>res;
        
        
        if(head1==nullptr) return head2;
        if(head2 == nullptr) return head1;
        
        while(head1 != nullptr && head2!=nullptr){
            if(head1->data < head2->data){
                res.push_back(head1->data);
                head1=head1->next;
            }
            else if(head1->data > head2->data){
                res.push_back(head2->data);
                head2=head2->next;
            }
            else{
                res.push_back(head1->data);
                res.push_back(head2->data);
                head1=head1->next;
                head2=head2->next;
            }
            
        }
        
        while(head1!=nullptr){
            res.push_back(head1->data);
            head1= head1->next;
        }
        while(head2!=nullptr){
            res.push_back(head2->data);
            head2= head2->next;
        }
        
        
        
        Node* temp = new Node(0);
        Node* curr = temp;
        for(int i=0;i<res.size();i++) {
            curr->next = new Node(res[i]);
            curr = curr->next;
            
        }
        
        return temp->next;
        
    }
    
    
};