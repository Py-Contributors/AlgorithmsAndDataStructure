import java.util.Arrays;

class BubbleSort{

    public static void main(String [] kichu){
        int [] arr = {7,6,5,3,4,2,1};
        Bubble_Sort(arr);
        System.out.println(Arrays.toString(arr));
        
    }

    /*
    1. Bubble Sort
    At every step comparing adjacent elements
    At the end of the compare and swaping the largest element will be at the end.  */
    static void Bubble_Sort(int [] arr){
        int n = arr.length - 1;
        boolean isAsc;
        
        for(int i = 0; i < n; ++i){
            isAsc = false;
            for(int j = 1; j < n-i; ++j){
                if(arr[j] < arr[j-1]){
                    swap(arr,j,j-1);
                    isAsc = true;
                }
            }
            // if no greater element found in the entire array means it is sorted
            if(!isAsc) return;
        }
    }
