#include <iostream>

using namespace std;

struct Node {
    float speed;
    float fuel;
    Node *prev,*next;
};

class doList {
  private:
    Node* arrayList[100];
    int size;
  public:
    doList(float speed[], float fuel[], int size) {
      size = size;
      Node newNode;
      for (int i = 1; i <= size; i++) {
        newNode = Node();
        newNode.speed = speed[i];
        newNode.fuel = fuel[i];
        newNode.next = NULL;
        arrayList[i] = &newNode;
        if (i == 1) {
          newNode.prev = NULL;
        }
        else {
          newNode.prev = arrayList[i - 1];
        }
      }//for
    }//constructor
    void out(char ch) {
      if (ch == 'a') {
        for (int j = 1; j <= size; j++)
          cout << endl << "Element - " << j << " speed - " << arrayList[j]->speed << " fuel - " << arrayList[j]->fuel;
      }
      else {
        for (int j = size; j >= 1; j--)
        cout << endl << "Element - " << j << " speed - " << arrayList[j]->speed << " fuel - " << arrayList[j]->fuel;
      }
    }
    void out(int i, char ch) {
      if (ch == 'a') {
        for (int j = 1; j <= i; j++)
        cout << endl << "Element - " << j << " speed - " << arrayList[j]->speed << " fuel - " << arrayList[j]->fuel;
      }
      else {
        for (int j = i; j >= 1; j--)
        cout << endl << "Element - " << j << " speed - " << arrayList[j]->speed << " fuel - " << arrayList[j]->fuel;
      }
    }
    int insert(float s, float f) {
      Node newNode = Node();
      newNode.speed = s;
      newNode.fuel = f;
      newNode.next = NULL;
      arrayList[++size] = &newNode;
      newNode.prev = arrayList[size - 1];
    }
    void increase_speed(int i, float s) {
      arrayList[i]->speed = arrayList[i]->speed + s;
    }
    void decrease_fuel(int i, float f) {
      arrayList[i]->fuel = arrayList[i]->fuel -f;
    }
};//Class end

int main() {
  float speed[] = { 40,30,70,65,80,90 };
  float fuel[] = { 1.5,1,2,1.25,1.5,1.25 };
  //size of elements is 6 hence passing as parameter
  doList dl = doList(speed, fuel, 6);
  cout << "First Output"<<endl;
  dl.out('d');
  dl.increase_speed(3,1.1);
  dl.decrease_fuel(5,2.1);
  return 1;
}
