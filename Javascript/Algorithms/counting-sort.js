/**
 * Implements the counting sort algorithm on an input array of integers.
 *
 * @param {number[]} array - A list of integers to be sorted.
 *
 * @returns {number[]} A list of integers sorted in non-descending order.
 *
 * Time Complexity:
 * - O(n + k), where n is the length of the input array and k is the range of values in the input array.
 *
 * Space Complexity:
 * - O(k), where k is the range of values in the input array.
 */
function countingSort(array) {
  // determine the maximum value in the input array
  let n = Math.max(...array) + 1;

  // initialize a count array of size n with all elements set to 0
  let count = new Array(n).fill(0);

  // iterate over the input array and increment the count of each element's value
  for (let i = 0; i < array.length; i++) {
    count[array[i]]++;
  }

  // modify the count array to reflect the number of elements <= each element's value
  for (let i = 1; i < n; i++) {
    count[i] += count[i - 1];
  }

  // create a result array of size array.length with all elements set to 0
  let result = new Array(array.length).fill(0);

  // iterate over the input array backwards and place each element in its sorted position in the result array
  for (let i = array.length - 1; i >= 0; i--) {
    result[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // return the sorted result array
  return result;
}

// define an example array to sort
let array = [3, 1, 7, 4, 9, 2, 6, 5, 8, 0];

// sort the array using countingSort
let sortedArray = countingSort(array);

// print the sorted array
console.log(sortedArray); // expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
