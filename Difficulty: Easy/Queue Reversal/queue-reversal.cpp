class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>st1;
        //stack<int>st2;
        while(!q.empty()) {
            st1.push(q.front());
            q.pop();
        }
        while(!st1.empty()) {
            q.push(st1.top());
            st1.pop();
        }
        
    }
};