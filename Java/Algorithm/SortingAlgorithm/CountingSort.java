/**
 * Implements the counting sort algorithm on an input array of integers.
 *
 * @param array - An array of integers to be sorted.
 *
 * @return An array of integers sorted in non-descending order.
 *
 * Time Complexity:
 * - O(n + k), where n is the length of the input array and k is the range of values in the input array.
 *
 * Space Complexity:
 * - O(k), where k is the range of values in the input array.
 */
public static int[] countingSort(int[] array) {
    // determine the maximum value in the input array
    int max = Arrays.stream(array).max().orElse(0);

    // initialize a count array of size max + 1 with all elements set to 0
    int[] count = new int[max + 1];

    // iterate over the input array and increment the count of each element's value
    for (int i = 0; i < array.length; i++) {
        count[array[i]]++;
    }

    // modify the count array to reflect the number of elements <= each element's value
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // create a result array of size array.length with all elements set to 0
    int[] result = new int[array.length];

    // iterate over the input array backwards and place each element in its sorted position in the result array
    for (int i = array.length - 1; i >= 0; i--) {
        result[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // return the sorted result array
    return result;
}

public static void main(String[] args) {
    // define an example array to sort
    int[] array = {3, 1, 7, 4, 9, 2, 6, 5, 8, 0};

    // sort the array using countingSort
    int[] sortedArray = countingSort(array);

    // print the sorted array
    System.out.println(Arrays.toString(sortedArray)); // expected output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
}
