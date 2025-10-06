#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void push_back(int data) {
        Node* new_node = new Node(data);
        if (!tail) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

        void pop_front() {
        Node* temp = head;
        if (!head) {
            std::cout << "Пустой список" << std::endl;
        }
        else {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
        }
    }

    void pop_back() {
        Node* temp = tail;
        if (!tail) {
            std::cout << "Пустой список" << std::endl;
        }
        else {
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
        }
    }

    void sort() {
    bool swapped = true;
    if (!head && !tail) {
        std::cout << "Пустой список" << std::endl;
    }
    else {
        while (swapped) {
            swapped = false;
            Node* sort = head;
            while (sort->next) {
                if (sort->data > sort->next->data) {
                    int temp = sort->data;
                    sort->data = sort->next->data;
                    sort->next->data = temp;
                    swapped = true;
                }
                sort = sort->next;
            }
        }
    }
}

    void remove_duplicates() {
        Node* current = head;
        while (current && current->next) {
            Node* runner = current->next;
            while (runner) {
                if (runner->data == current->data) {
                    Node* duplicate = runner;
                    if (runner->prev) {
                        runner->prev->next = runner->next;
                    }
                    if (runner->next) {
                        runner->next->prev = runner->prev;
                    }
                    if (runner == tail) {
                        tail = runner->prev;
                    }
                    runner = runner->next;
                    delete duplicate;
                }
                else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    void display() {
        Node* print = head;
        std::cout << "Список: ";
        while (print) {
            std::cout << print->data << " ";
            print = print->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    setlocale(0, "rus");
    DoublyLinkedList list;
    int choice, data;
    while (true) {
        std::cout << "1. Добавить в начало" << std::endl;
        std::cout << "2. Добавить в конец" << std::endl;
        std::cout << "3. Удалить с начала" << std::endl;
        std::cout << "4. Удалить с конца" << std::endl;
        std::cout << "5. Показать список" << std::endl;
        std::cout << "6. Сортировать" << std::endl;
        std::cout << "7. Удалить дубликаты" << std::endl;
        std::cout << "8. Выйти" << std::endl;
        std::cout << "Выберите: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите число: ";
            std::cin >> data;
            list.push_front(data);
            list.display();
            break;
        case 2:
            std::cout << "Введите число: ";
            std::cin >> data;
            list.push_back(data);
            list.display();
            break;
        case 3:
            list.pop_front();
            list.display();
            break;
        case 4:
            list.pop_back();
            list.display();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            std::cout << "Список отсортирован" << std::endl;
            list.display();
            break;
        case 7:
            list.remove_duplicates();
            std::cout << "Дубликаты удалены" << std::endl;
            list.display();
            break;
        case 8:
            std::cout << "Выход" << std::endl;
            return 0;
        default:
            std::cout << "Нет такого выбора" << std::endl;
        }
    }
}
