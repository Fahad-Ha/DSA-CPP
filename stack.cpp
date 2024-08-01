
#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        
        Node(int value) {
            this->value = value;
            next = nullptr;
        }

};


class Stack {
    private:
        Node* top;
        // No need for bottom (like tail in LL) because we only add and remove on top
        // Node* bottom;
        int height;

    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack() {
            Node* temp = top;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }


        void getTop() {
            cout << "Top: " << top->value << endl;
        }

        void getHeight() {
            cout << "Height: " << height << endl;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            // INT_MIN the minimum value that an int (integer) type can hold
            // since it represents the smallest possible integer, making it an unlikely real stack value.
            if (height == 0) return INT_MIN;

            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;

            return poppedValue;
        }
};

int main()
{
    Stack* myStack = new Stack(2);

    myStack->getTop();
    myStack->getHeight();

    myStack->push(5);
    myStack->printStack();
}
