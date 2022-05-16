#include "Dictionary.h"

int Dictionary::dictSize=5;

Dictionary** Makenull(Dictionary** A) {
    A = new Dictionary*[Dictionary::dictSize];
    for (int i = 0; i < Dictionary::dictSize; i++) {
        A[i] = nullptr;
    }
    return A;
}

bool Member(const char* x, Dictionary** A) {
    int bucket = h(x);
    Dictionary* current = A[bucket];
    while (current != NULL) {
        if (current->element == x)
            return true;
        else
            current = current->next;
    }
    return false;
}

void Insert(const char* x, Dictionary** A) {
    if (Member(x, A)) {
        cout << endl << x << " is not inserted, already a member." << endl;
        return;
    }
    int bucket = h(x);
    Dictionary* tmp = A[bucket];
    A[bucket] = new Dictionary;
    A[bucket]->next = tmp;
    A[bucket]->element = const_cast<char*>(x);
}

void Delete(const char* x, Dictionary** A) {
    if (!Member(x, A)) {
        cout << endl << x << " is not deleted, not a member." << endl;
        return;
    }
    int bucket;
    bucket = h(x);
    if (A[bucket]->element == x) {
        A[bucket] = A[bucket]->next;
        return;
    }
    else {
        Dictionary* current = A[bucket];
        while (current->next != NULL) {
            if (current->next->element == x) {
                current->next = current->next->next;
                return;
            }
            else
                current = current->next;
        }
    }
}

void Print(Dictionary** A) {
    Dictionary* current;
    for (int i = 0; i < Dictionary::dictSize; i++) {
        cout << "\n" << "[" << i << "]";
        current = A[i];
        while (current != NULL) {
            cout << " {" << current->element << "}";
                current = current->next;
        }
    }
    cout << endl;
}

int h(const char* x) {
    int sum = 0;
    for (int i = 0; i < strlen(x); i++)
        sum += (int)x[i];
    return sum % Dictionary::dictSize;
}