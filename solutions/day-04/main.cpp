/* // * PROBLEM :: October 16, 2024
  Given an array of integers, find the first missing positive integer in linear time and constant space. 
  In other words, find the lowest positive integer that does not exist in the array.
  The array can contain duplicates and negative numbers as well.

  For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
  You can modify the input array in-place.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<int> arr;
  string input;
  int num;

  system("clear");
  cout << "ENTER AN ARRAY OF INTEGERS" << endl //prompt input
    << "(Separate using space and enter space to end)" << endl
    << ":: ";
  getline(cin, input); //get input

  stringstream s(input); //store integers into arr
  while (s >> num) {
    if (num <= 0) continue;
    arr.push_back(num); //!insert as is
  }

  int len = arr.size();
    //!cycle sort 
  for (int i = 0; i < len; ) {
    while (arr[i] > 0 && arr[i] <= len && arr[arr[i] - 1] != arr[i])
      swap(arr[i], arr[arr[i] - 1]); 
        /* 
          swap the value of the current index with the value 
          at the index for the current index' value
        */
    i++;
  }

    //find the lowest missing positive integer //!optimized
  int lowest = len + 1; //assume missing numbers inside array
  for (int i = 0; i < len; i++) {
      if (arr[i] != i + 1) {
          lowest = i + 1;
          break;
      }
  }

  cout << endl //print result
    << "Lowest missing positive integer:" << endl
    << ":: " << lowest << endl << endl;
  return 0;
}

/* // * ANALYSIS
  Solved but did not achieve linear time and constant space.
  
  ! TOPIC TO LEARN
    • Cycle sort (swapping logic)
    • In-place rearrangement
*/