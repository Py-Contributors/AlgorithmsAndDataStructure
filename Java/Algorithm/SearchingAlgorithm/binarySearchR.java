import java.util.Scanner;
public class binarySearchR {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        System.out.print("define your array size: ");
        int n = sc.nextInt();
        
        int arr[] = new int[n];
        
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        
        System.out.println("your target is: ");
        int target= sc.nextInt();
        
        System.out.println(search(arr, target, 0, n-1));
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
