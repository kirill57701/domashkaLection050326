#include <iostream>

template<class T>
struct BiList {
  T val;
  BiList<T>* next;
  BiList<T>* prev;
  void push_back(T data);
  void push_front(T data);
};

template<class T>
void clear(BiList<T>* list) {
  while (list->prev != nullptr) {
    list = list->prev;
  }
  while (list != nullptr) {
    BiList<T>* next = list->next;
    delete list;
    list = next;
  }
}

template<class T>
void BiList<T>::push_back(T data) {
  BiList<T>* change = this;
  while (change->next != nullptr) {
    change = change->next;
  }
  change->next = new BiList<T>;
  change->next->prev = change;
  change->next->val = data;
  change->next->next = nullptr;
}

template<class T>
void BiList<T>::push_front(T data) {
  BiList<T>* change = this;
  while (change->prev != nullptr) {
    change = change->prev;
  }
  change->prev = new BiList<T>;
  change->prev->val = data;
  change->prev->prev = nullptr;
  change->prev->next = change;
}

int main() {
  BiList<int> q{0, nullptr, nullptr};
  q.push_back(3);
  q.push_front(7);
  BiList<int>* c = &q;
  while (c != nullptr) {
    std::cout << c->val << std::endl;
    c = c->next;
  }
}