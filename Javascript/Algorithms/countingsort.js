const countingSort = (arr, min, max) => {
    const count = {};
    // First populate the count object
    for (let i = min; i <= max; i++) {
        count[i] = 0;
    }
    for (let i = 0; i < arr.length; i++) {
        count[arr[i]] += 1;
    }
    /* Now, count is indexed by numbers, with values corresponding to occurrences, eg:
     * {
     *   3: 1,
     *   4: 0,
     *   5: 2,
     *   6: 1,
     *   7: 0,
     *   8: 0,
     *   9: 1
     * }
     */
    
    // Then, iterate over count's properties from min to max:
    const sortedArr = [];
    for (let i = min; i <= max; i++) {
        while (count[i] > 0) {
            sortedArr.push(i);
            count[i]--;
        }
    }
    return sortedArr;
};

console.log(countingSort([3, 6, 5, 5, 9], 3, 9));