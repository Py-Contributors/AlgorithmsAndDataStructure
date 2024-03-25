function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        let mid = Math.floor((left + right) / 2);

        // Check if target is present at mid
        if (arr[mid] === target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

// Example usage:
const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const target = 5;
const resultIndex = binarySearch(arr, target);
if (resultIndex !== -1) {
    console.log(`Element ${target} found at index ${resultIndex}`);
} else {
    console.log(`Element ${target} not found`);
}
