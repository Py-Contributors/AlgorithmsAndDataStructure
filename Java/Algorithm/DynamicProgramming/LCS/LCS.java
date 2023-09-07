import java.util.Scanner;  
  
class LCSExample1 {  
    public static String findLengthOfLCS(String str1, String str2, int p, int q) {  
        int[][] tableForLCS = new int[p + 1][q + 1];  
        for (int i = 0; i <= p; i++) {  
            for (int j = 0; j <= q; j++) {  
                if (i == 0 || j == 0)  
                    tableForLCS[i][j] = 0; 
                else if (str1.charAt(i - 1) == str2.charAt(j - 1))  
                    tableForLCS[i][j] = tableForLCS[i - 1][j - 1] + 1;  
                else  
                    tableForLCS[i][j] = Math.max(tableForLCS[i - 1][j], tableForLCS[i][j - 1]);     
            }  
        }
        int index = tableForLCS[p][q];  
        int temp = index;  
        char[] longestCommonSubsequence = new char[index + 1];  
        longestCommonSubsequence[index] = '\0';  
        int i = p, j = q;  
        String lcs ="";  
        while (i > 0 && j > 0) {  
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {  
                  
                longestCommonSubsequence[index - 1] = str1.charAt(i - 1);  
                i--;  
                j--;  
                index--;  
            }  
            else if (tableForLCS[i - 1][j] > tableForLCS[i][j - 1])  
                i--;  
            else  
                j--;  
        }  
        for (int k = 0; k <= temp; k++)  
            lcs = lcs + longestCommonSubsequence[k];  
              
        return lcs;  
    }  
    public static void main(String[] args) {  
          
        String str1, str2, LCS;  
          
        Scanner sc= new Scanner(System.in); 
        System.out.print("Enter first sequence: ");  
        str1 = sc.nextLine(); 
          
        System.out.print("Enter second sequence: ");  
        str2 = sc.nextLine(); 
          
        int p = str1.length();  
        int q = str2.length();  
          
        LCS = findLengthOfLCS(str1, str2, p, q);  
          
        System.out.println("LCS: "+LCS);  
          
    }  
}  