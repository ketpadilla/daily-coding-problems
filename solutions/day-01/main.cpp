/* // * PROBLEM :: October 13, 2024
  Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

  For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

  Bonus: Can you do this in one pass?
*/

#include "./includes/helper.h"

int main() {
  string input; //initialize variables
  int k, first, second;
  vector<int> list; 
  bool isSum = false;

  system("clear");
  getList(list, input); //prompt inputs
  getNum(k);
  findAddens(list, k, first, second, isSum); //process logic
  printResults(k, first, second, isSum); //print results

  return 0;
}

/* // * ANALYSIS
  Time complexity: O(n^2)
  Fastest possible: O(n)

  ! Possible Improvement (unchecked)
  @logic
  -----
  1. Create a vector of numbers seen by the program (seenNumbers)
  2. For each number, find if its complement exists in the list
  3. If exists, update variables and return
    • else, add number to seenNumbers
  -----

  @findAddens()
  -----
  void findAddens(vector<int> list, int k, int& first, int& second, bool& isSum) {
    vector<int> seenNumbers; // Vector to store seen numbers

    for (int i = 0; i < list.size(); i++) {
        int complement = k - list[i];
        
        # Check if the complement exists in the seenNumbers vector
        for (int j = 0; j < seenNumbers.size(); j++) {
            if (seenNumbers[j] == complement) {
                first = complement;
                second = list[i];
                isSum = true;
                return; // Exit once we find a pair
            }
        }

        # Add the current number to the seenNumbers vector
        seenNumbers.push_back(list[i]);
      }
  }
  -----
*/
