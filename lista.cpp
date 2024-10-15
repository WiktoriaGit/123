#include <iostream>
using namespace std;



class DoublyLinkedList {
    class Node {
        public:
        // 123
        int value;
        Node* nextNode;
        Node* prevNode;

        // Konstruktor
        Node(int value)
        {
            this->value = value;
            this->nextNode = nullptr;
            this->prevNode = nullptr;
        }
    };
private:
    Node* head;

public:
    // Konstruktor listy
    DoublyLinkedList() : head(nullptr) {}

    // Dodaj element na początek listy
    void insertAtStart(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->nextNode = head;
        head->prevNode = newNode;
        head = newNode;
    }

    // Dodaj element na koniec listy
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->nextNode != nullptr) {
            temp = temp->nextNode;
        }

        temp->nextNode = newNode;
        newNode->prevNode = temp;
    }

    // Dodaj element pod wskazany indeks
    void insertIndex(int value, int pos)
    {
        if (pos == 0) {
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->nextNode;
        }

        if (temp == nullptr) {
            cout << "Podano zbyt duży indeks" << endl;
            delete newNode;
            return;
        }

        newNode->nextNode = temp->nextNode;
        newNode->prevNode = temp;
        if (temp->nextNode != nullptr) {
            temp->nextNode->prevNode = newNode;
        }
        temp->nextNode = newNode;
    }

    // Usuń element z początku listy
    void deleteAtStart()
    {
        if (head == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }

        Node* temp = head;
        head = head->nextNode;
        if (head != nullptr) {
            head->prevNode = nullptr;
        }
        delete temp;
    }

    // Usuń element z końca listy
    void deleteAtEnd()
    {
        if (head == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }

        Node* temp = head;
        if (temp->nextNode == nullptr) {
            head = nullptr;
            delete temp;
            return;
        }

        while (temp->nextNode != nullptr) {
            temp = temp->nextNode;
        }

        temp->prevNode->nextNode = nullptr;
        delete temp;
    }

    // Usuń element z pod wskazanego indeksu
    void deleteIndex(int pos)
    {
        if (head == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }

        if (pos == 0) {
            deleteAtStart();
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos; i++) {
            temp = temp->nextNode;
        }

        if (temp == nullptr) {
            cout << "Zły indeks" << endl;
            return;
        }

        if (temp->nextNode != nullptr) {
            temp->nextNode->prevNode = temp->prevNode;
        }
        if (temp->prevNode != nullptr) {
            temp->prevNode->nextNode = temp->nextNode;
        }
        delete temp;
    }

    // Wyświetl całą listę
    void showList()
    {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }
        cout << "Lista: ";
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->nextNode;
        }
        cout << endl;
    }

    // Wyświetl listę w odwrotnej kolejności
    void showReverseList()
    {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "Lista jest pusta" << endl;
            return;
        }

        while (temp->nextNode != nullptr) {
            temp = temp->nextNode;
        }

        cout << "Lista odwrotnie: ";
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->prevNode;
        }
        cout << endl;
    }

    // Czyść całą listę
    void clearList()
    {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->nextNode;
            delete temp;
        }
        head = nullptr;
    }

    // Destruktor
    ~DoublyLinkedList() {
        clearList();
    }
};

int main()
{
    DoublyLinkedList list;

    cout << "Dodajmy element na poczatku: " << endl;
    list.insertAtStart(1);
    list.showList();

    cout << "Dodajmy element na koncu: " << endl;
    list.insertAtEnd(3);
    list.showList();

    cout << "Dodajmy element na 1 indeks (2 miejsce): " << endl;
    list.insertIndex(2, 1);
    list.showList();

    cout << "Wyswietlmy liste na odwrot: " << endl;
    list.showReverseList();

    cout << "Dodajmy jeszcze kilka wartosci: " << endl;
    list.insertAtEnd(6);
    list.insertAtEnd(13);
    list.insertAtEnd(10);
    list.insertAtEnd(0);
    list.showList();

    cout << "Usunmy element na 4 indeksie (5 miejscu): " << endl;
    list.deleteIndex(4);
    list.showList();

    cout << "Usunmy pierwszy element: " << endl;
    list.deleteAtStart();
    list.showList();

    cout << "Usunmy ostatni element: " << endl;
    list.deleteAtEnd();
    list.showList();

    

    return 0;
}
