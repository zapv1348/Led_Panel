#ifndef __POTATO_BUPHA_H__
#define __POTATO_BUPHA_H__

#include <memory>

#define size_t __SIZE_TYPE__

template <class T> class PotatoBupha{
  private:
    bool full;
    bool empty;
    size_t maximumSize;
    size_t currentSize;
    size_t pushTo;
    size_t popFrom;
    std::unique_ptr<T[]> baseAddr;
  public:
    PotatoBupha(size_t size);
    size_t curSize();
    size_t maxSize();
    bool isFull();
    bool isEmpty();
    bool pushToBuf(T * pushee, size_t numElements=1);
    bool popFromBuf(T * popBuf, size_t numElements=1);
};

template <class T>
PotatoBupha<T>::PotatoBupha(size_t size){
  full = false;
  empty = true;
  
  baseAddr = std::make_unique<T[]>(size);
  maximumSize = size;
  currentSize = 0;
  pushTo = 0;
  popFrom = 0;
}

template <class T>
size_t PotatoBupha<T>::curSize(){
  return currentSize;
}

template <class T>
size_t PotatoBupha<T>::maxSize(){
  return maximumSize;
}

template <class T>
bool PotatoBupha<T>::isFull(){
  return full;
}

template <class T>
bool PotatoBupha<T>::isEmpty(){
  return empty;
}

template <class T>
bool PotatoBupha<T>::pushToBuf(T * pushee, size_t numElements){
  if (pushee == NULL || pushee == nullptr) return false;
  if (numElements == 0) return true;
  if (numElements > (maximumSize - currentSize)) return false;
  if (numElements == (maximumSize - currentSize)) full = true;
  empty = false;


  currentSize += numElements;
  while (numElements > 0) {
    baseAddr[pushTo] = *pushee;
    (pushTo + 1 >= maximumSize) ? pushTo=0 : pushTo++;
    pushee++;
    numElements--;
  }
  return true;
}

template <class T>
bool PotatoBupha<T>::popFromBuf(T * popBuf, size_t numElements){
  if (popBuf == NULL || popBuf == nullptr) return false;
  if (numElements == 0) return true;
  if (numElements > currentSize) return false;
  if (numElements == currentSize) empty = true;

  full = false;
  currentSize -= numElements;
  while (numElements){
    *popBuf = baseAddr[popFrom];
    (popFrom + 1 >= maximumSize) ? popFrom = 0 : popFrom++;
    popBuf++;
    numElements--;
  }
  return true;
}

#endif //__POTATO_BUPHA_H__