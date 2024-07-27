#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:    
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while (temp) {
                cout << temp->value;
                cout << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);

            if (length == 0) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;

        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = tail;
                tail = temp->prev;
                tail->next = nullptr;
                delete temp;
            }
            length--;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            }
            else {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }
            else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;
            Node* temp = head;
            if (index < length/2) {
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
            }
            else {
                temp = tail;
                for (int i = length - 1; i > index; i--) {
                    temp = temp->prev;
                }
            } 
            return temp;
        }

        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
                return false;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            } 
            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;
            before->next = newNode;
            after->prev = newNode;
            newNode->next = after;
            newNode->prev = before;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            Node* temp = get(index);
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }
        
};

int main()
{
    DoublyLinkedList* newDLL = new DoublyLinkedList(3);
    //newDLL->append(5);
    newDLL->prepend(2);
    //newDLL->deleteLast();

    newDLL->printList();
}

