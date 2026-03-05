#include <iostream>

template<class T>
struct BiList 
{
  T val;
  BiList<T>* next;
  BiList<T>* prev;
  void push_back(T data);
  void push_front(T data);
  void print();
  size_t size();
};

template<class T>
void clear(BiList<T>* list) 
{
  while (list->prev != nullptr) 
  {
    list = list->prev;
  }
  while (list != nullptr) 
  {
    BiList<T>* next = list->next;
    delete list;
    list = next;
  }
}

template<class T>
void BiList<T>::push_back(T data) 
{
  BiList<T>* change = this;
  while (change->next != nullptr) 
  {
    change = change->next;
  }
  change->next = new BiList<T>;
  change->next->prev = change;
  change->next->val = data;
  change->next->next = nullptr;
}

template<class T>
void BiList<T>::print() {
  BiList<T>* list_ptr = this;
  while (list_ptr->prev != nullptr) 
  {
    list_ptr = list_ptr->prev;
  }
  while (list_ptr != nullptr) 
  {
    std::cout << list_ptr->val << "\n";
    list_ptr = list_ptr->next;
  }
}

template<class T>
void BiList<T>::push_front(T data) 
{
  BiList<T>* change = this;
  while (change->prev != nullptr) 
  {
    change = change->prev;
  }
  change->prev = new BiList<T>;
  change->prev->val = data;
  change->prev->prev = nullptr;
  change->prev->next = change;
}

template<class T>
size_t BiList<T>::size() 
{
  BiList<T>* now = this;
  while (now->prev != nullptr) 
  {
    now = now->prev;
  }
  size_t count = 0;
  while (now != nullptr) 
  {
    count++;
    now = now->next;
  }
  return count;
}

int main() 
{
  int* massive_to_convert = new int[3];
  massive_to_convert[0] = 3;
  massive_to_convert[1] = 1;
  massive_to_convert[2] = 2;
  BiList<int>* list_ptr = new BiList<int>;
  list_ptr->val = massive_to_convert[0];
  list_ptr->next = nullptr;
  list_ptr->prev = nullptr;
  for (size_t i = 1; i < 3; ++i) 
  {
    list_ptr->push_back(massive_to_convert[i]);
  }
  list_ptr->print();
  delete[] massive_to_convert;
  clear(list_ptr);
}