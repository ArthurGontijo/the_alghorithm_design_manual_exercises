/* ------------- Problem 3-4 -------------
Design a stack S that supports S.push(x), S.pop(), and S.findmin(), which returns the minimum
element of S. All operations should run in constant time.
*/
#include <iostream>
#include <memory>
#include <stack>
#include <vector>

struct StackElement {
    int value;
    std::unique_ptr<StackElement> bottom = nullptr;
};

class Stack {
    /* Here we'll use a stack of stack elements to keep track of the minimumElements.
       The top of that stack will be the current minimum value of the main stack.
       In case it ever gets popped off the main stack, we just pop it off from our minimumElements
       stack. This ensures constant time for push(), pop() and findmin().
    */
  private:
    std::unique_ptr<StackElement> top = nullptr;
    std::stack<StackElement *> minimumElements;

  public:
    void push(int value) {
        std::unique_ptr<StackElement> newElement = std::make_unique<StackElement>();
        newElement->value = value;
        if (!top) {
            top = std::move(newElement);
        } else {
            newElement->bottom = std::move(top);
            top = std::move(newElement);
        }
        if (minimumElements.empty() || value < minimumElements.top()->value) {
            minimumElements.push(top.get());
        }
    }

    StackElement *pop() {
        StackElement *returnElement = top.get();
        top = std::move(returnElement->bottom);
        if (returnElement == minimumElements.top()) {
            minimumElements.pop();
        }

        return returnElement;
    }

    StackElement *findmin() { return minimumElements.top(); }

    void print() {
        const StackElement *element = top.get();
        while (element) {
            std::cout << element->value;
            if (element->bottom)
                std::cout << " -> ";
            element = element->bottom.get();
        }
        std::cout << '\n';
    }
};

int main() {
    Stack s = Stack();
    std::vector<int> elements = {6, 4, 7, 2, 1, 10};
    for (int element : elements) {
        s.push(element);
    }
    std::cout << "Stack: ";
    s.print();
    std::cout << "Min value: " << s.findmin()->value << "\n";

    std::cout << "Stack: ";
    s.pop();
    s.pop();
    s.print();
    std::cout << "Min value: " << s.findmin()->value << "\n";

    std::cout << "Stack: ";
    s.pop();
    s.print();
    std::cout << "Min value: " << s.findmin()->value << "\n";
}
