/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        vector<int>arr;
        Node*temp =root;
        
        while(temp!= nullptr) {
            Node* temp2 = temp;
            while(temp2!=nullptr) {
                arr.push_back(temp2->data);
                temp2=temp2->bottom;
            }
            temp= temp->next;
        }
        
        sort(arr.begin(), arr.end());
        
        Node* head = new Node(arr[0]);
        Node*  curr= head;
        
        for(int i=1;i<arr.size();i++){
            curr->bottom = new Node(arr[i]);
            curr=curr->bottom;
        }
        
        return head;
    }
};