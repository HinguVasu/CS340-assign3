#include <iostream>
 
using namespace std;
 
//merge two halfs to get the sorted data
void mrg(int *a, int low, int high, int mid)
{
	//Low to mid and mid to high are already sorted
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// merge two parts into temp aray
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	//Insert all remaining values in temp aray from i to mid
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	//Insert remaining j to high values in the temp aray
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	//Assign sorted data to aray a.
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
//spliting merge sort function 
void M_S(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		//split into half
		M_S(a, low, mid);
		M_S(a, mid+1, high);
 
		// merge to sort them
		mrg(a, low, high, mid);
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int ar[n];

    cout<<"Enter "<<n<<" element below:"<<endl;
	for(i = 0; i < n; i++)
	{
		cin>>ar[i];
	}
 
	M_S(ar, 0, n-1);
 
	// Print results
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        if(i==0)
        cout<<ar[i];
        else
        cout<<"->"<<ar[i];
 
	return 0;
}