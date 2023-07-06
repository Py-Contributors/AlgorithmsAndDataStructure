/**
 * Time Complexity:
 * O(n^2), where n is the length of the input array.
  
 * Space Complexity:
 * O(1), as sorting happens in-place in comb-sort.
**/

/**
 * @param {number[]}
 * @return {number[]}
 */
const combSort = arr => {
  /**
   * @param {number[]}
   * @return {boolean}
   */
  const isArraySorted = arr => {
    for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) return false;
    }
    return true;
  };

  let iterationCount = 0;
  let gap = arr.length - 2;
  let decreaseFactor = 1.25;

  // Repeat iterations Until array is not sorted

  while (!isArraySorted(arr)) {
    // If not first gap  Calculate gap
    if (iterationCount > 0) {
      if (gap != 1) {
        gap = Math.floor(gap / decreaseFactor);
      }
    }
    // Set front and back elements and increment to a gap
    let front = 0;
    let back = gap;
    while (back <= arr.length - 1) {
      // Swap the elements if they are not ordered
      if (arr[front] > arr[back]) {
        let temp = arr[front];
        arr[front] = arr[back];
        arr[back] = temp;
      }

      // Increment and re-run swapping
      front += 1;
      back += 1;
    }
    iterationCount += 1;
  }
  return arr;
};

let arr = [3, 0, 2, 5, -1, -2, -1, 4, 1];

console.log("Original Array Elements");
console.log(arr);
console.log("Sorted Array Elements");
console.log(combSort(arr));
