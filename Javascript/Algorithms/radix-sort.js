const unsortedArr = [31, 27, 28, 42, 13, 3, 50, 46, 25, 18, 33, 47, 4, 45, 39, 23, 2];

const getNum = (num, index) => {
    const strNum = String(num);
    let end = strNum.length - 1;
    const foundNum = strNum[end - index];
  
    if (foundNum === undefined) return 0;
    else return foundNum;
};
  
console.log(getNum(4353, 2));

const largestNum = arr => {
    let largest = "0";
  
    arr.forEach(num => {
      const strNum = String(num);
  
      if (strNum.length > largest.length) largest = strNum;
    });
  
    return largest.length;
};

const radixSort = arr => {
    let maxLength = largestNum(arr);
  
    for (let i = 0; i < maxLength; i++) {
      let buckets = Array.from({ length: 10 }, () => []);
  
      for (let j = 0; j < arr.length; j++) {
        let num = getNum(arr[j], i);
  
        if (num !== undefined) buckets[num].push(arr[j]);
      };
      arr = buckets.flat();
    };
    return arr;
};
  
console.log(radixSort(unsortedArr));