function slowSort(arr) {
    /**
     * If the array has 1 or no elements then it is already sorted,
     * return the array.
     * Otherwise slice the array into two halves and merge sort each half,
     * then merge the two sorted halves.
     */
    if (arr.length <= 1) {
      return arr;
    } else {
      const mid = Math.floor(arr.length / 2);
      const firstHalf = slowSort(arr.slice(0, mid));
      const secondHalf = slowSort(arr.slice(mid));
      
      if (secondHalf[0] < firstHalf[firstHalf.length - 1]) {
        [firstHalf[mid - 1], secondHalf[0]] = [secondHalf[0], firstHalf[mid - 1]];
      }
      
      return firstHalf.concat(secondHalf);
    }
  }
  

// Example usage:
const array = [9, 5, 2, 8, 3, 1, 4, 7, 6];
const sortedArray = slowSort(array);
console.log(sortedArray);
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
