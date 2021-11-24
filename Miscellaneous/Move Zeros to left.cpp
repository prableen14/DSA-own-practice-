/*
Given an integer array nums, move all 0's to the starting (left) of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [0,0,1,3,12]

*/
/*
Keep two markers: read_index and write_index and point them to the end of the array. Let’s take a look at an overview of the algorithm:
While moving read_index towards the start of the array:
If read_index points to 0, skip.
If read_index points to a non-zero value, write the value at read_index to write_index and decrement write_index.
Assign zeros to all the values before the write_index and to the current position of write_index as well.
*/
void move_zeros_to_left(int A[], int n) {
   
  if (n < 1) return;
  
  int write_index = n - 1;
  int read_index = n - 1;

  while(read_index >= 0) {
    if(A[read_index] != 0) {
      A[write_index] = A[read_index];
      write_index--;
    }

    read_index--;
  }

  while(write_index >= 0) {
    A[write_index] = 0;
    write_index--;
  }
}
