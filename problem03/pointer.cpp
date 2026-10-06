#include <iostream>
#include <new>

struct Node {
    int value;
    Node* next;
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int number;

    std::cout << "Enter integers (0 to stop):\n";

    while (std::cin >> number && number != 0) {
        Node* node = nullptr;
        try {
            node = new Node;
        } catch (const std::bad_alloc&) {
            std::cerr << "Memory allocation failed.\n";
            while (head != nullptr) {
                Node* next = head->next;
                delete head;
                head = next;
            }
            return 1;
        }

        node->value = number;
        node->next = nullptr;

        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    long long sum = 0;
    for (Node* current = head; current != nullptr; current = current->next) {
        sum += current->value;
    }
    std::cout << "Sum: " << sum << '\n';

    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }

    return 0;
}
