#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

template <typename ElemType>
void merge(vector<ElemType> &arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  ElemType L[n1], R[n2];
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)  {
    if (L[i] <= R[j])  {
      arr[k] = L[i];
      i++;
    }
    else  {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)  {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)  {
    arr[k] = R[j];
    j++;
    k++;
  }
}
template <typename ElemType>
void sort(vector<ElemType> &arr, int num1, int num2) {
  if (num1 < num2) {
    int x = num1 + (num2 - num1)/2;
    sort(arr, num1, x);
    sort(arr, x+1, num2);
    merge(arr, num1, x, num2);
  }
}

int main(int argc, char *argv[]) {
  string temp = argv[1];
  ifstream in1(argv[2]);
  ifstream in2(argv[3]);
  if (temp == "i") {
    vector<int> num1;
    vector<int> num2;
    int temp1, temp2;
    char str[100];
    while (in1 >> temp1) {
      int i = 0;
      num1.push_back(temp1);
      i++;
    }
    while (in2 >> temp2) {
      num2.push_back(temp2);
    }

    int x = num1.size();
    int y = num2.size();
    sort(num1, 0, x-1);
    sort(num2, 0, y-1);
    for (int i = 0; i < x-1; i++) {
      if (num1.at(i) == num1.at(i+1)) {
        num1.erase(num1.begin() + i);
        x = num1.size();
      }
    }
    for (int i = 0; i < y-1; i++) {
      if (num2.at(i) == num2.at(i+1)) {
        num2.erase(num2.begin() + i);
        y = num2.size();
      }
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (num1.at(i) == num2.at(j)) cout << num1.at(i) << endl;
      }
    }
  }
  if (temp == "s") {
    vector<string> str1;
    vector<string> str2;
    char word1[30], word2[30];
    char str[100];
    while (in1 >> word1) {
      int i = 0;
      str1.push_back(word1);
      i++;
    }
    while (in2 >> word2) {
      str2.push_back(word2);
    }
    int x = str1.size();
    int y = str2.size();
    sort(str1, 0, x-1);
    sort(str2, 0, y-1);
    for (int i = 0; i < x-1; i++) {
      if (str1.at(i) == str1.at(i+1)) {
        str1.erase(str1.begin() + i);
        x = str1.size();
      }
    }
    for (int i = 0; i < y-1; i++) {
      if (str2.at(i) == str2.at(i+1)) {
        str2.erase(str2.begin() + i);
        y = str2.size();
      }
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        if (str1.at(i) == str2.at(j)) cout << str1.at(i) << endl;
      }
    }
  }
  in1.close();
  in2.close();
  return 0;
}
