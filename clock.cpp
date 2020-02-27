#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class LL{
private:
struct Node {
char x;
Node *next;
} *head;
public:
LL(){head = NULL;}
void addValue(char c){
Node *n = new Node();
n->x = c;
n->next = head;
head = n;
}
char delValue(){
Node *n = head;
char ret = n->x;
head = head->next;
delete n;
return ret;
}
};
int main() {
LL a,b,*p,*q;
p = &a; q = &b;
a.addValue('a');
a.addValue('b');
a.addValue('c');
cout << a.delValue() << endl;
b.addValue('d');
b.addValue('e');
(*q).addValue('a');
cout << b.delValue() << endl;
q = p;
cout << q->delValue() << endl;
a = b;
cout << a.delValue() << endl;
return 0;
}
