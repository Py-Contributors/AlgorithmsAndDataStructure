import java.util.*;

public class LIS {
    public static void main(String[] args){

        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the number of elements you want to store: ");  
        int n=sc.nextInt();  
        int[] nums= new int[100];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<n; i++)  {  
            nums[i]=sc.nextInt();  
        }  
        printLIS(nums);
    }
        public static void printLIS(int[] nums){
        String[] paths = new String[nums.length];
        int[] sizes = new int[nums.length];

        for(int i=0; i<nums.length; i++){
            sizes[i] = 1;
            paths[i] = nums[i] + " " ;
        }
    int maxLength = 1; 

    for(int i=1; i<nums.length; i++){ 
        for(int j=0; j<nums.length; j++){
    if(nums[i]>nums[j] && sizes[i] < sizes[j] + 1){;
        sizes[i] = sizes[j] + 1;
        paths[i] = paths[j] + nums[i] + " "; 	
        if(maxLength < sizes[i])
            maxLength = sizes[i];
        }
    }
    }
    for(int i=1; i<nums.length; i++){
        if(sizes[i] == maxLength)
        System.out.println("LIS: " + paths[i]);
    }
    }
}
