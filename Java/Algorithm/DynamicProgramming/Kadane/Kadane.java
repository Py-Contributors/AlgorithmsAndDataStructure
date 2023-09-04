import java.util.*;

class KadanesAlgo
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   
	    Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the number of elements you want to store: ");  
        int n=sc.nextInt();  
        int[] a = new int[100];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<n; i++)  {  
            a[i]=sc.nextInt();  
        }  
        int local_max = 0;
        int global_max = Integer.MIN_VALUE;
        
        for(int i=0;i<n;i++)
    	{
    	    local_max = Math.max(a[i], a[i] + local_max);
    	    
    	    if(local_max > global_max)
    	    {
    	        global_max = local_max;
    	    }
    	    
    	}
        System.out.println("Maximum Subarray sum: " +global_max);
	}
}