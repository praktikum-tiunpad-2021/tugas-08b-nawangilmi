#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
    T data;
    T priority;
    Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> Q;
  Q.head = nullptr;
  Q.tail = nullptr;
  return Q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> pBaru = new Element<T>;
  pBaru->data = value;
  pBaru->priority = priority;
  pBaru->next = nullptr;

   if(q.head == nullptr && q.tail == nullptr){
    q.head = pBaru;
    q.tail = pBaru;
  }
  else {
    ElementPtr<T> curr = q.head;
    ElementPtr<T> prev = nullptr;
    while(pBaru->priority <= curr->priority){
      if(curr->next == nullptr){
        break;
      }
      prev = curr;
      curr = curr->next;
    }    
    if (curr == q.head && pBaru->priority > curr->priority) {
    pBaru->next = curr;
    q.head = pBaru;
    } else if (curr == q.tail && pBaru->priority < curr->priority) {
    curr->next = pBaru;
    q.tail = pBaru;
    } else {
    prev->next = pBaru;
    pBaru->next = curr;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
   return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> pDel;
  if(q.head == nullptr && q.tail == nullptr) {
  pDel = nullptr;
  } else if(q.head->next == nullptr) {
  pDel = q.head;
  q.head = nullptr;
  q.tail = nullptr;
  } else {
  pDel = q.head;
  q.head = q.head->next;
  pDel->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
