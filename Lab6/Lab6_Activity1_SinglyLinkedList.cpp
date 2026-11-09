#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newNode;
}

void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

void insertFront(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

bool search(Node* head, int value) {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == value)
            return true;
        curr = curr->next;
    }

    return false;
}

int countNodes(Node* head) {
    int count = 0;
    Node* curr = head;

    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    return count;
}

void deleteValue(Node*& head, int value) {
    if (head == nullptr)
        return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Original list: ";
    display(head);

    insertFront(head, 5);
    cout << "After insertFront(5): ";
    display(head);

    cout << "Search for 30: " << (search(head, 30) ? "Found" : "Not found") << endl;
    cout << "Search for 99: " << (search(head, 99) ? "Found" : "Not found") << endl;
    cout << "Number of nodes: " << countNodes(head) << endl;

    deleteValue(head, 5);
    cout << "After deleting first node (5): ";
    display(head);

    deleteValue(head, 20);
    cout << "After deleting middle node (20): ";
    display(head);

    deleteValue(head, 40);
    cout << "After deleting last node (40): ";
    display(head);

    deleteValue(head, 100);
    cout << "After trying to delete 100: ";
    display(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
