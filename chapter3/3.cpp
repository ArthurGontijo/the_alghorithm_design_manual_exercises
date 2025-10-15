/* ------------- Problem 3-3 -------------
Give an algorithm to reverse the direction of a given singly linked list. In other words, after the
 reversal all pointers should now point backwards. Your algorithm should take linear time.
*/
#include <iostream>
#include <memory>

struct ListNode {
    int value;
    std::unique_ptr<ListNode> next;
};

class LinkedList {
  private:
    std::unique_ptr<ListNode> head = nullptr;
    ListNode *tail = nullptr;

  public:
    ListNode *getHead() const { return head.get(); }
    ListNode *getTail() const { return tail; }

    void pushBack(int value) {
        std::unique_ptr<ListNode> newNode = std::make_unique<ListNode>();
        newNode->value = value;
        newNode->next = nullptr;

        if (!head) {
            head = std::move(newNode);
            tail = head.get();
        } else {
            tail->next = std::move(newNode);
            tail = tail->next.get();
        }
    }

    void reverse() {
        tail = head.get();

        std::unique_ptr<ListNode> prev = nullptr;
        std::unique_ptr<ListNode> current = std::move(head);

        while (current) {
            std::unique_ptr<ListNode> next = std::move(current->next);

            current->next = std::move(prev);
            prev = std::move(current);
            current = std::move(next);
        }
        head = std::move(prev);
    }

    void print() const {
        const ListNode *node = head.get();
        while (node) {
            std::cout << node->value;
            if (node->next)
                std::cout << " -> ";
            node = node->next.get();
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedList ll = LinkedList();
    for (int i = 0; i < 10; i++) {
        ll.pushBack(i);
    }

    std::cout << "Linked List: " << "\n";
    ll.print();

    std::cout << "Reversed Linked List: " << "\n";
    ll.reverse();
    ll.print();
}