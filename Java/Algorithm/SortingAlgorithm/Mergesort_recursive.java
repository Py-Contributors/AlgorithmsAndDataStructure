import java.util.Scanner;
public class Mergesort_recursive
{
    public static void main(String a[])
    {
        int temp;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array size");
        int n = sc.nextInt();
        int[] list = new int[n];
        System.out.println("Enter numbers ");
        for (int i = 0; i < n; i++)
        {
            int number = sc.nextInt();
            list[i] = number;
        }
        System.out.println("List before sorting \n");
        for (int i = 0; i < list.length; i++)
            System.out.print(list[i] + " ");
        System.out.println();

        mergeSort(list, 0, list.length - 1);
        System.out.print("List after sorting \n");
        for (int i = 0; i < list.length; i++)
            System.out.print(list[i] + " ");
        System.out.println();
    }

    public static void mergeSort(int list[], int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int middle = (low + high) / 2;
        mergeSort(list, low, middle);
        mergeSort(list, middle + 1, high);
        merge(list, low, middle, high);
    }
    private static void merge(int list[], int low, int middle, int high)
    {
        int IstList_end = middle;
        int IIndList_start = middle + 1;
        int l = low;
        while ((l <= IstList_end) && (IIndList_start <= high))
        {
            if (list[low] < list[IIndList_start])
            {

                low++;
            }
            else
            {
                int temp = list[IIndList_start];

                for (int j = IIndList_start - 1; j >= low; j--)
                {

                    list[j + 1] = list[j];
                }
                list[low] = temp;
                low++;
                IstList_end++;
                IIndList_start++;
            }
        }
    }
}