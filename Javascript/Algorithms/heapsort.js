
	function sort( arr)
	{
		var N = arr.length;

		for (var i = Math.floor(N / 2) - 1; i >= 0; i--)
			heapify(arr, N, i);

		for (var i = N - 1; i > 0; i--) {
			var temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			heapify(arr, i, 0);
		}
	}

	function heapify(arr, N, i)
	{
		var largest = i;
		var l = 2 * i + 1; 
		var r = 2 * i + 2; 

		if (l < N && arr[l] > arr[largest])
			largest = l;

		if (r < N && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			var swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			heapify(arr, N, largest);
		}
	}

	function printArray(arr)
	{
		var N = arr.length;
		for (var i = 0; i < N; ++i)
			document.write(arr[i] + " ");
		
	}


	var arr = [12, 11, 13, 5, 6, 7];
	var N = arr.length;

	sort(arr);

	document.write( "Sorted array is");
	printArray(arr, N);


