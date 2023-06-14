#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int l, int m, int r)
{
	int i, j, k, nl, nr;

	nl = m - l + 1;

	nr = r - m;

	int la[nl], ra[nr];

	for (i = 0; i < nl; i++)
	{
		la[i] = a[l + i];
	}

	for (j = 0; j < nr; j++)
	{
		ra[j] = a[m + 1 + j];
	}

	i = 0;

	j = 0;

	k = l;

	while (i < nl && j < nr)
	{
		if (la[i] <= ra[j])
		{
			a[k] = la[i];

			i++;
		}
		else
		{
			a[k] = ra[j];

			j++;
		}

		k++;
	}

	while (i < nl)
	{
		a[k] = la[i];

		i++;
		k++;
	}

	while (j < nr)
	{
		a[k] = ra[j];

		j++;
		k++;
	}
}

void mergeSort(int *a, int l, int r)
{
	int m;

	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(a, l, m);

		mergeSort(a, m + 1, r);

		merge(a, l, m, r);
	}
}

int main()
{
	int n;

	cout << "Enter number of elements: ";

	cin >> n;

	int a[n];

	cout << "Enter elements:";

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	mergeSort(a, 0, n - 1);

	cout << "Sorted Array: ";

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	//cout << "\n\nStep count : " << c << endl;
	return 0;
}
