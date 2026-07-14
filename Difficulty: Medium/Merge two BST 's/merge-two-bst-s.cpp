/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void inorder(Node *root, vector<int>& res){
      if(root==nullptr){
          return ;
      }
      inorder(root->left,res);
      res.push_back(root->data);
      inorder(root->right,res);
  }
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int>res;
        inorder(root1,res);
        inorder(root2,res);
        
        sort(res.begin(),res.end());
        
        return res;
        
        
    }
};