#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string name) {
    Node* newNode = new Node{name, nullptr};
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";
    Node* oldFront = front;
    string name = oldFront->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete oldFront;
    return name;
}

void displayQueue(Node* front) {
    if (front == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Waiting customers: ";
    for (Node* current = front; current != nullptr; current = current->next)
        cout << current->data << " ";
    cout << endl;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Ali");
    enqueue(front, rear, "John");
    enqueue(front, rear, "Sara");
    enqueue(front, rear, "David");
    enqueue(front, rear, "Emma");

    displayQueue(front);

    while (front != nullptr) {
        string name = front->data;
        cout << "Now serving: " << name << endl;
        this_thread::sleep_for(chrono::seconds(10));
        dequeue(front, rear);
        cout << "Service completed: " << name << " (10 seconds)" << endl;
    }

    cout << "All customers have been served." << endl;
    displayQueue(front);

    while (front != nullptr) dequeue(front, rear);
    return 0;
}
