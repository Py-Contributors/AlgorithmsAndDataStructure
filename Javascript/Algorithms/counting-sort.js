const countingSort = (inputArr, n = inputArr.length) => {
    let k = Math.max(...inputArr);
    let t;
    const temp = new Array(k + 1).fill(0);
    
    for(let i = 0; i < n; i++){
      t = inputArr[i];
      temp[t]++;
    }
  
    for(let i = 1; i <= k; i++){
      
      temp[i] = temp[i] + temp[i - 1];  
    }
    
    const outputArr = new Array(n).fill(0);
    
    for(let i = n - 1; i >= 0; i--) {
    
      t = inputArr[i];
      outputArr[temp[t] - 1] = t;  
          
      temp[t] = temp[t] - 1;		
     }
    
    return outputArr;
}