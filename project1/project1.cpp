#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int CheckTempText(string temp, char *text) {
  unsigned int x = 0;
  for (unsigned int i = 0; i < temp.size(); i++) {
    if (temp[i] == text[i]) x++;
    else if (temp[i] == '?') x++;
  }
  if (x == strlen(text)) return 1;
  else return 0;
}

void AssignLetters(string & str1, string & str2, char *text, string tempword, string tempstring) {
  for (unsigned int i = 0; i < tempword.size(); i++) {
    if (tempstring[i] == '?') {
      if (str2.find(tempword[i]) == string::npos) {
        str1 += text[i];
        str2 += tempword[i];
      }
    }
  }
  return;
}

int main(int argc, char *argv[]) {
  string str1, str2, str, tempword, tempstring;
  char text[50];
  ifstream myfile1(argv[1]);
  getline(myfile1, str1);
  getline(myfile1, str2);
  ifstream myfile2(argv[2]);
  getline(myfile2, str);
  strcpy(text, argv[3]);
  myfile1.close();
  myfile2.close();
  if (str1.at(str1.size()-1) == '\r') str1.erase(str1.size()-1);
  if (str2.at(str2.size()-1) == '\r') str2.erase(str2.size()-1);
  if (str.at(str.size()-1) == '\r') str.erase(str.size()-1);
  unsigned int x = str.size();
  int v, j = 0;
  int u = strlen(text);

  for (unsigned int i = 0; i < x; i++) {
    if (isalpha(str[i])) {
      j++;
      if (str2.find(str[i]) != string::npos) {
        tempstring.push_back(str1[str2.find(str[i])]);
        tempword.push_back(str1[str2.find(str[i])]);
      }
      else {
        tempstring.push_back('?');
        tempword.push_back(str[i]);
      }
    }
    else {
      v = tempword.size();
      if (v == u) {
        if (CheckTempText(tempstring, text) == 1) {
          AssignLetters(str1, str2, text, tempword, tempstring);
          break;
        }
        else {
          tempword.clear();
          tempstring.clear();
          j = 0;
        }
      }
      else {
        tempword.clear();
        tempstring.clear();
        j = 0;
      }
    }
  }

  char unknownChar1, unknownChar2;
  for (unsigned int a = 0; a < 25; a++) {
    for (unsigned int b = 0; b < str1.size(); b++) {
      if (str2[a] == str1[b]) break;
      else if (b == str1.size() - 1) unknownChar1 = str2[a];
    }
  }
  str1 += unknownChar1;

  for (unsigned int c = 0; c < 25; c++) {
    for (unsigned int d = 0; d < str2.size(); d++) {
      if (str1[c] == str2[d]) break;
      else if (d == str2.size() - 1) unknownChar2 = str1[c];
    }
  }
  str2 += unknownChar2;

  for (unsigned int i = 0; i < x; i++) {
    if (isalpha(str[i])) {
      j++;
      if (str2.find(str[i]) != string::npos) {
        cout << str1[str2.find(str[i])];
      }
      else {
        cout << str[i];
      }
    }
    else {
      cout << str[i];
    }
  }
  cout << endl;
return 0;
}
