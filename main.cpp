#include <iostream>

template<class T>
struct BiList {
  T val;
  BiList<T>* next;
  BiList<T>* prev;
};

template<class T>
void clear(BiList<T>* list) {
  while (list->prev != nullptr) {
    list = list->prev;
  }
  while (list != nullptr) {
    BiLIst<T>* next = list->next;
    delete list;
    list = next;
  }
}

template<class T>
BiList<T> operator=(BiList)

int main() {

}