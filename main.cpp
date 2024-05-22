#include <iostream>
using namespace std;

// Структура для вузла двозв'язного списку
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Клас для двозв'язного списку
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    // Додавання елемента в кінець списку
    void append(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    // Виведення списку
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Функція, що повертає головний елемент списку
    Node* getHead() {
        return head;
    }

    // Видалення списку для звільнення пам'яті
    void deleteList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }
};

// Функція для створення двозв'язного списку з матриці
DoublyLinkedList createListFromMatrix(int** matrix, int rows, int cols) {
    DoublyLinkedList list;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            list.append(matrix[i][j]);
        }
    }
    return list;
}

// Функція для створення двозв'язного списку з транспонованої матриці
DoublyLinkedList createTransposeList(int** matrix, int rows, int cols) {
    DoublyLinkedList list;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            list.append(matrix[i][j]);
        }
    }
    return list;
}

// Функція для створення списку з діагональних елементів матриці
DoublyLinkedList createDiagonalList(int** matrix, int rows, int cols) {
    DoublyLinkedList list;
    int size = (rows < cols) ? rows : cols;
    for (int i = 0; i < size; ++i) {
        list.append(matrix[i][i]);
    }
    return list;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    // Створення та заповнення матриці
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Створення списків
    DoublyLinkedList originalList = createListFromMatrix(matrix, rows, cols);
    DoublyLinkedList transposeList = createTransposeList(matrix, rows, cols);
    DoublyLinkedList diagonalList = createDiagonalList(matrix, rows, cols);

    // Виведення списків
    cout << "Original list: ";
    originalList.printList();

    cout << "Transpose list: ";
    transposeList.printList();

    cout << "Diagonal list: ";
    diagonalList.printList();

    // Звільнення пам'яті
    originalList.deleteList();
    transposeList.deleteList();
    diagonalList.deleteList();

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
