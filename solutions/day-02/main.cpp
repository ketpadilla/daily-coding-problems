/* // * PROBLEM :: October 14, 2024
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string input;

  system("clear");
  cout << "ENTER LIST OF NUMBERS" << endl //prompt input
    << "(Separate using space and enter space to end)" << endl
    << ":: ";
  getline(cin, input); //get input

  int element;
  vector<int> list;
  stringstream s(input); //separate elements
  while (s >> element) { //place element into list
    list.push_back(element);
  }

  int len = list.size(); //process logic //! IMPROVEMENT (PREFIX-SUFFIX ALGORITHM)
  vector<int> result, prefix(len, 1), suffix(len, 1);
  for (int i = 1; i < len; i++)
    prefix[i] = prefix[i - 1] * list[i - 1];

  for (int i = len - 2; i >= 0; i--) 
    suffix[i] = suffix[i + 1] * list[i + 1];

  for (int i = 0; i < len; i++)
    result.push_back(prefix[i] * suffix[i]);

  cout << endl << "NEW LIST" //print new list
    << endl << ":: ";
  for (int i = 0; i < len; i++) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}

/* //! ANALYSIS
  Time complexity: O(n^2)
  Fastest possible: O(n)

  ! Original logic: O(n^2)
  int len = list.size(), curr = 1;
  vector<int> result;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i == j) continue;
      curr *= list[j];
    }

    result.push_back(curr);
    curr = 1;
  }

*/