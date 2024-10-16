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

/* // * ANALYSIS
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

  ! Explanation
  * MAIN FUNCTION: logic involving cumulation with exclusion of indices 
    - excludes the element of the current index from calculations
    - can be used to exclude any 'n'th element of the array by adjusting how elements are called relative to the current index 'i'
    
  list[len, 1] -> creates a vector named "listt" with:
    * 'len' number of elements
    * all elements have a value of '1'
      -> use '0' if addition and subtractino
    • create vectors for prefix and suffix calculations

  * prefix logic:
    • start at the second index
    • until the last index (len - 1), do the following:
      1. access the previous element (idx - 1) of the prefix vector AND original list
      2. perform required calculation
      3. increment 

  * suffix logic:
    • start at the second to the last index
    • until the first index (0), do the following:
      1. access the succeeding element (idx + 1) of the prefix vector AND original list
      2. perform required calculation
      3. decrement

  * supplementary: 
    https://www.perplexity.ai/search/only-tell-me-what-is-wrong-int-tG78afPVQ8Gxo5c5kv0GWA
  
*/