// HEADER FILE: helper.h

#ifndef H_Helper
#define H_Helper 

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void getList(vector<int>& list, string input) {
  int element;

  cout << "ENTER LIST OF NUMBERS" << endl //prompt list
    << "(Separate with spaces and press enter to end)" << endl
    << ":: ";
  getline(cin, input); 

  stringstream s(input); //separate input into list elements
  while (s >> element) {
    list.push_back(element); //add element into list
  }
}//end getList

void getNum(int& k) {
  cout << endl //prompt input
    << "ENTER k" << endl
    << ":: ";
  cin >> k;
}//end getNum

void findAddens(vector<int> list, int k, int& first, int& second, bool& isSum) {
  int len = list.size(); //get number of list element
  for (int i = 0; i < len; i++) { //set first num
    for (int j = 0; j < len; j++) { //set the second num
      if (list[i] + list[j] == k) { //check if numbers add to k
        first = list[i];
        second = list[j];
        isSum = true;
        break;
      }//endif
    }//endfor
  }//endfor
}//end findAddens

void printResults(int k, int first, int second, bool isSum) {
  cout << endl //print results
    << "Can any of the elements in the list add up to " 
    << k << "?" << endl
    << ((isSum) ? "Yes" : "No") << " -> "
    << ((isSum) ? to_string(first) + " + " 
      + to_string(second) + " = " 
      + to_string(first + second) : "") 
    << endl;
}//end printResults

#endif