import java.util.*;

public class Subsequences {
public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);  
	System.out.print("Enter the number of elements you want to store: ");  
	int n=sc.nextInt();  
	int[] arr= new int[100];  
	System.out.println("Enter the elements of the array: ");  
	for(int i=0; i<n; i++)  {  
		arr[i]=sc.nextInt();  
	}
	System.out.print("Enter Sum: ");
	int X = sc.nextInt();
	System.out.println(countSubsequence(arr, n, X));
}

public static int countSubsequence(int[] A, int N, int X) {
	int[][] dp = new int[N+1][X+1];
	for (int[] row : dp) {
	Arrays.fill(row, 0);
	}
	for (int i = 0; i <= N; i++) {
	for (int j = 0; j <= X; j++) {
		if (i == N) {
		dp[i][j] = 1;
		}
	}
	}

	for (int i = N-1; i >= 0; i--) {
	for (int j = 1; j <= X; j++) {
		if (A[i] <= j) {
		dp[i][j] = dp[i+1][j] + dp[i+1][j-A[i]];
		} else {
		dp[i][j] = dp[i+1][j];
		}
	}
	}
	System.out.print("Number of Subsequences with sum less than or equal to given sum: ");
	return dp[0][X] - 1;
}
}
