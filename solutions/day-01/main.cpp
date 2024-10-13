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
  vector<int> arrNum;
  int k, element; 
  bool isSum = false;

  cout << "ENTER LIST OF NUMBERS" << endl // ask list
    << "(Separate with spaces and press enter to end)" << endl
    << ":: ";
  
  stringstream s(input);
  while (s >> element) {
    //! process input
  }

  cout << "ENTER k" << endl
    << ":: ";
  cin >> k;

  //! return true or false

  cout << "Can any of the elements in the list add up to " << k << "? "
    << isSum << endl;
  return 0;
}
