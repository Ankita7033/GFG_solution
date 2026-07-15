/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *slow = head, *fast = head;

        // Detect loop using Floyd's Cycle Detection
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        // No loop present
        if (fast == nullptr || fast->next == nullptr)
            return;

        // Special case: loop starts at head
        if (slow == head) {
            while (fast->next != head)
                fast = fast->next;

            fast->next = nullptr;
            return;
        }

        // Find the starting node of the loop
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the loop
        fast->next = nullptr;
    }
};