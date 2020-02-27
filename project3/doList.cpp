using namespace std;

typedef struct Node {
  float speed;
  float fuel;
  struct Node *prev;
  struct Node *next;
}Node;

class doList {
  private:
    Node* arrayList[100];
    int size;
    Node *head;
    Node *tail;
    struct Node *merge(struct Node *first, struct Node *second) {
      if (!first) return second;
      if (!second) return first;
      if (first->speed < second->speed) {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
      }
      else {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
      }
    }
    struct Node *mergeSort(struct Node *head) {
      if (!head || !head->next) return head;
      struct Node *second = split(head);
      head = mergeSort(head);
      second = mergeSort(second);
      return merge(head,second);
    }
    struct Node *split(struct Node *head) {
      struct Node *fast = head,*slow = head;
      while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
      }
      struct Node *temp = slow->next;
      slow->next = NULL;
      return temp;
    }
  public:
    doList(float speed[], float fuel[], int size) {
      this->size = size;
      int x = speed[0];
      int y = 0;
      head = new(Node);
      head->speed = speed[0];
      head->fuel = fuel[0];
      head->next = NULL;
      head->prev = NULL;
      arrayList[0] = head;
      tail = head;

      for (int i = 1; i < size; i++) {
        if (y < speed[i]) {
          y = i;
        }
        Node* newNode = new(Node);
        newNode->speed = speed[i];
        newNode->fuel = fuel[i];
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        arrayList[i] = newNode;
        tail = newNode;
        if (i == size - 1) tail = newNode;
        else {
          newNode->prev = arrayList[i - 1];
        }
      }
      tail->next = NULL;
      head = mergeSort(head);
      Node *temp = head;
      while (head) {
          temp = head;
          head = head->next;
      }
      tail = temp;

      //domination
      Node* node = tail;
      while (node->prev) {
        if (node->fuel <= node->prev->fuel) {
            node->prev = node->prev->prev;
            node->prev->next = node;
        }
        else node = node->prev;
      }
    }

    void increase_speed(int i, float s) {
      arrayList[i]->speed = arrayList[i]->speed + s;
      Node* temp1 = tail;
      while (temp1->prev) {
        if (arrayList[i]->speed > temp1->speed && arrayList[i]->fuel <= temp1->fuel) {
          if (temp1->next != NULL) {
            arrayList[i]->next = temp1->next;
            arrayList[i]->next->prev = arrayList[i];
          }
          else arrayList[i]->next = NULL;
          temp1->prev = NULL;
          temp1->next = NULL;
        }
        else temp1 = temp1->prev;
      }
      Node* bla = arrayList[i];
      if (bla->next != NULL) {
        while (bla->next) bla = bla->next;
      }
      tail = bla;
      return;
    }
    void decrease_fuel(int i, float f) {
      arrayList[i]->fuel = arrayList[i]->fuel - f;
      Node* temp2 = tail;
      while (temp2) {
        if (arrayList[i]->speed > temp2->speed && arrayList[i]->fuel <= temp2->fuel) {
          if (temp2->prev == NULL) arrayList[i]->prev = NULL;
          else {
            arrayList[i]->prev = temp2->prev;
            arrayList[i]->prev->next = arrayList[i];
          }
          temp2->prev = NULL;
          temp2->next = NULL;
          break;
        }
        else temp2 = temp2->prev;
      }
      Node* bla = arrayList[i];
      if (bla->next != NULL) {
        while (bla->next) bla = bla->next;
      }
      tail = bla;
      return;
    }
    int insert(float s, float f) {
      size++;
      Node *newNode = new(Node);
      newNode->speed = s;
      newNode->fuel = f;
      arrayList[size-1] = newNode;
      newNode->next = NULL;
      Node *temp = tail;
      while (temp->prev) {
        if (temp->speed > newNode->speed && temp->prev->speed < newNode->speed && temp->fuel > newNode->fuel && temp->prev->fuel < newNode->fuel) {
          temp->prev->next = newNode;
          newNode->next = temp;
          break;
        }
        else temp = temp->prev;
      }
    }
    void out(char ch) {
      if (ch == 'd') {
        Node* one = tail;
        while (one->prev) {
          cout << "Speed " << one->speed << " Fuel " << one->fuel << endl;
          one = one->prev;
        }
        if (one->prev == NULL) cout << "Speed " << one->speed << " Fuel " << one->fuel << endl;
      }
      else {
        if (ch == 'a') {
          Node* two = tail;
          while (two->prev) two = two->prev;
          while (two->next) {
            cout << "Speed " << two->speed << " Fuel " << two->fuel << endl;
            two = two->next;
          }
          if (two->next == NULL) cout << "Speed " << two->speed << " Fuel " << two->fuel << endl;
        }
      }
    }
    void out(int i, char ch) {
      int x = 0;
      if (ch == 'd') {
        Node* one = tail;
        while (one) {
          cout << "Speed " << one->speed << " Fuel " << one->fuel << endl;
          one = one->prev;
          x++;
          if (x == i) break;
        }
      }
      else {
        if (ch == 'a') {
          Node* two = tail;
          while (two->prev) two = two->prev;
          while (two->next) {
            cout << "Speed " << two->speed << " Fuel " << two->fuel << endl;
            two = two->prev;
            x++;
            if (x == i) break;
          }
        }
      }
    }
};
