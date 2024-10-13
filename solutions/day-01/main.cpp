/* // * PROBLEM :: October 13, 2024
  Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

  For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

  Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  string input;
  int k, element, first, second;
  vector<int> list; 
  bool isSum = false;

  system("clear");
  cout << "ENTER LIST OF NUMBERS" << endl // ask list
    << "(Separate with spaces and press enter to end)" << endl
    << ":: ";
  getline(cin, input);

  stringstream s(input);
  while (s >> element) {
    if (element == 0) break;
    list.push_back(element);
  }
  
  cout << endl 
    << "ENTER k" << endl
    << ":: ";
  cin >> k;

  int len = list.size();
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (list[i] + list[j] == k) {
        first = list[i];
        second = list[j];
        isSum = true;
        break;
      }
    }
  }

  //! return true or false
  
  cout << endl 
    << "Can any of the elements in the list add up to " 
    << k << "?" << endl
    << ((isSum) ? "Yes" : "No") << " -> "
    << ((isSum) ? to_string(first) + " + " + to_string(second) + " = " + to_string(first + second) : "") << endl;
  return 0;
}
