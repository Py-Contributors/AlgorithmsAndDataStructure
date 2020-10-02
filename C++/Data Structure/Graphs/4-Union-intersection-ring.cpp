// PROGRAM 2
// .Write a program to find UNION, INTERSECTION and RING
// SUM of two graphs.

#include <bits/stdc++.h>
using namespace std;
#define crap                     \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define dbg(x) cerr << #x << " = " << x << endl
#define endl "\n"
#define int long long int
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)

int printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			i++;
		else if (arr2[j] < arr1[i])
			j++;
		else /* if arr1[i] == arr2[j] */
		{
			printf(" %d ", arr2[j++]);
			i++;
		}
	}
}
int printUnion(int arr1[], int arr2[], int m, int n)
{
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			printf(" %lld ", arr1[i++]);
		else if (arr2[j] < arr1[i])
			printf(" %lld ", arr2[j++]);
		else
		{
			printf(" %lld ", arr2[j++]);
			i++;
		}
	}
	while (i < m)
		printf(" %lld ", arr1[i++]);
	while (j < n)
		printf(" %lld ", arr2[j++]);
}

signed main()
{

	// freopen("input.txt", "r", stdin);
	int V1[] = {0, 1};
	int V2[] = {0, 1, 2};
	int m = sizeof(V1) / sizeof(V1[0]);
	int n = sizeof(V2) / sizeof(V2[0]);
	int G1[m][m], G2[n][n], E3[m + n][m + n];
	int i, j, k;
	printf("Enter the adjacency matrix for graph G1:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("G1[%lld][%lld]=", i, j);
			scanf("%lld", &G1[i][j]);
		}
	}
	printf("Enter the adjacency matrix for graph G2:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("G2[%lld][%lld]=", i, j);
			scanf("%lld", &G2[i][j]);
		}
	}
	printf("\nSet of vertices in union of the graphs G1 and G2 is:\n");
	printUnion(V1, V2, m, n);
	printf("\n");

	printf("\nSet of vertices in intersection of the graphs G1 and G2 is:\n");
	printIntersection(V1, V2, m, n);
	printf("\n");

	printf("\nSet of vertices in ring sum of the graphs G1 and G2 is:\n");
	printUnion(V1, V2, m, n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (G1[i][j] == G2[i][j] && i < m && j < m)
				E3[i][j] = 0;
			else if (G1[i][j] < G2[i][j] && i < m && j < m)
				E3[i][j] = G2[i][j];
			if (G1[i][j] < G2[i][j] && i < m && j < m)
				E3[i][j] = G1[i][j];
			else
				E3[i][j] = G2[i][j];
		}
	}
	printf("Adjacency matrix of ring sum of graphs G1 and G2 is:\n\t");
	for (i = 0; i < n; i++)
	{
		printf("%lld\t", i);
	}
	printf("\n\t");
	for (i = 0; i < n; i++)
	{
		printf(" ");
	}
	for (i = 0; i < n; i++)
	{
		printf("\n%lld|\t", i);
		for (j = 0; j < n; j++)
		{
			printf("%lld\t", E3[i][j]);
		}
	}

	return 0;
}
// 1 1
// 1 1

// 1 1 1
// 0 0 0
// 1 2 1
