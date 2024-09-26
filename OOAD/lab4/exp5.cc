#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// LinkedList class
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    template <typename U>
    bool findNode(U key) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                std::cout << "Node with value " << key << " found in the linked list." << std::endl;
                return true;
            }
            current = current->next;
        }
        std::cout << "Node with value " << key << " not found in the linked list." << endl;
        return false;
    }
};

int main() {
    LinkedList<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.findNode(20);  


    LinkedList<string> strList;
    strList.insert("apple");
    strList.insert("banana");
    strList.insert("orange");
    strList.findNode("banana");  

    LinkedList<char> charList;
    charList.insert('A');
    charList.insert('B');
    charList.insert('C');
    charList.findNode('D');  

    return 0;
}
