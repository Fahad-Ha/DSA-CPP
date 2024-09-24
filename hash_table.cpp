
#include <iostream>
#include <string> // Include string header
using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key,int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }

};

class HashTable {
    private:
        // Used 7 because a prime number will have less collisions
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:
        int hash(string key) {
            int hash = 0;
            for (int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                // Used 23 because 23 * prime number will be more random
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
};


int main()
{
    HashTable* myHashTable = new HashTable();

    cout << "Hash: " << myHashTable->hash("test");

}
