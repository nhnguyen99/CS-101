#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data);

int search(int arr[], int head, int tail, int value);

Node* utility(int in1[], int in2[], int head, int tail, int* num) {
	if (head > tail) return NULL;
	Node* node = newNode(in2[*num]);
	(*num)--;
	if (head == tail) return node;
	int i = search(in1, head, tail, node->data);
	node->right = utility(in1, in2, i + 1, tail, num);
	node->left = utility(in1, in2, head, i - 1, num);
	return node;
}

Node* buildTree(int in1[], int in2[], int n) {
	int num = n - 1;
	return utility(in1, in2, 0, n - 1, &num);
}

int search(int arr[], int head, int tail, int value) {
	int i;
	for (i = head; i <= tail; i++) {
		if (arr[i] == value)
			break;
	}
	return i;
}

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main(int argc, char *argv[]) {
  int in1[100], in2[100], in3[100];
	int i = 0, j = 0;
	int temp1, temp2;
  ifstream myfile1(argv[1]);
  ifstream myfile2(argv[2]);
  ifstream myfile3(argv[3]);
	while (myfile1 >> temp1) {
		in1[i] = temp1;
		i++;
	}
	while (myfile2 >> temp2) {
		in2[j] = temp2;
		j++;
	}
	char num;
	string temp;
	int n = i;
  Node* root = buildTree(in1, in2, n);
	Node* tempNode = root;
	char one, two;
	while (myfile3.get(num)) {
		if (num == '0') {
			if (tempNode->left != NULL) tempNode = tempNode->left;
			else {
				one = char(tempNode->data);
				cout << one;
				tempNode = root;
			}
			if ((tempNode->right == NULL) && (tempNode->left == NULL)) {
				one = char(tempNode->data);
				cout << one;
				tempNode = root;
			}
		}
		else if (num == '1') {
			if (tempNode->right != NULL) tempNode = tempNode->right;
			else {
				two = char(tempNode->data);
				cout << two;
				tempNode = root;
			}
			if ((tempNode->right == NULL) && (tempNode->left == NULL)) {
				two = char(tempNode->data);
				cout << two;
				tempNode = root;
			}
		}
	}
	cout << endl;
	myfile1.close();
	myfile2.close();
	myfile3.close();
}
