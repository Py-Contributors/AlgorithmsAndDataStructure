public class InsertionSort {
    
    public static int insertionSort(int[] v){
		int i, j, t, numIteration=0;
		for(i=1; i<=v.length-1; i++){
			t = v[i];
			j=i;
			while(j>=1 && v[j-1]>t){
				swapValue(v, j, j-1);
				j=j-1;
			}
			v[j] = t;
			numIteration++;
		}
		return numIteration;
	}

    public static void insertionSortRicorsive(int[] v, int n){
		if(n>1){
			insertionSortRicorsive(v, n-1);
		}
		
		int value = v[n-1];
		int j = n-1;
		while(j>=1 && v[j-1]>value){
			swapValue(v, j, j-1);
			j = j-1;
		}
		v[j] = value;
	}

    public static void swapValue(int[] v, int i, int j){
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
}
