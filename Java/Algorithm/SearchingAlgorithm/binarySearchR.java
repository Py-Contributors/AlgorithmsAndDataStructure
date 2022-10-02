public class binarySearchR {
    public static void main(String[] args) {
        int[] arr= {2, 4, 5, 6,8, 9, 10,23,26, 29};
        int target= 4;
        System.out.println(search(arr, target, 0, arr.length-1));
    }
    static int search(int[] arr, int target, int start, int end){
        if (start>end){
            return -1;
        }

        int mid= start+(end-start)/2;

        if (arr[mid]==target){
            return mid;
        }
        if (target <arr[mid]){
            search(arr, target, start, mid-1);
        }
        return search(arr,target, mid+1, end);
    }
}
