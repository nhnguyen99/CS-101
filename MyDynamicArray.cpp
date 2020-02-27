#include <iostream>
class MyDynamicArray {
private:
   int size;
   int allocated;
   int *array;
public:
   MyDynamicArray() {
       allocated = 2;
       size = 0;
       array = new int[2];
   }
   MyDynamicArray(int s) {
       allocated = s;
       size = s;
       array = new int[s];
   }
   virtual ~MyDynamicArray() {
       delete array;
   }
   int& operator[](int i) {
       if (i >= size) {
           std::cout << "Out of bounds reference : " << i << std::endl;
           int t = 0;
           int *temp = &t;
           return *temp;
       }
       int *ref = &array[i];
       return *ref;
   }
   void add(int v) {
       if (size == allocated) {
           allocated *= 2;
           int *temp = new int[size];
           for (int i = 0; i < size; ++i) {
               temp[i] = array[i];
           }
           array = new int[allocated];
           for (int i = 0; i < size; ++i) {
               array[i] = temp[i];
           }
           delete[] temp;
           std::cout << "Doubling to : " << allocated << std::endl;
       }
       array[size++] = v;
   }
   void del() {
       if (size == 0) {
           return;
       }
       if (4 * size <= allocated) {
           allocated /= 2;
           int *temp = new int[size];
           for (int i = 0; i < size; ++i) {
               temp[i] = array[i];
           }
           array = new int[allocated];
           for (int i = 0; i < size; ++i) {
               array[i] = temp[i];
           }
           delete[] temp;
           std::cout << "Reducing to : " << allocated << std::endl;
       }
       --size;
   }
   int length() {
       return size;
   }
   void clear() {
       allocated = 2;
       array = new int[allocated];
       size = 0;
   }
};