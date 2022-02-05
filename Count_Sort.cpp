#include<iostream>
using namespace std;
int max(int *arr,int n)
{	
	int max= arr[0];
	for(int i=0 ; i<n-1 ; i++)
	{
		if(max<arr[i+1])
		{
			max = arr[i+1];
		}
	}
	return max;
}
void Count_Sort(int arr[],int n)
{
	int m,k=0,*count,*final_array,i;
	m = max(arr,n);
	cout<<m<<endl;
	k = m+1;
	count = new int[k];
	
	//Initialize with 0
	for(i=0 ; i<k ; i++)
	{		
		count[i]=0;
	}
	// Update with the counted elements in original array:
	for(i=0 ; i<n ; i++)
	{		
		count[arr[i]]++;
	}
	
	cout<<endl<<"1 count: ";
	for(i=0 ; i<k ; i++)
	{		
		cout<<count[i]<<" "; 
	}
	
	//Update the same array by adding consecutive numbers with each other except the number at first index
	for(i=1;i<=k;i++)
	{
		count[i] = count[i] + count[i-1];
	}
	
	cout<<endl<<"2 Updated count: ";
	for(i=0 ; i<n ; i++)
	{		
		cout<<count[i]<<" ";
	}
	
	// Took another array of same size of original array and fill in the sorted order by finding the index of each element of the original array in 
	//the count array, place the element at the index calculated 
	final_array = new int[n];
	for(i=n-1 ; i>=0 ; i--)
	{
		final_array[--count[arr[i]]]  =  arr[i];
	}
	cout<<endl<<"4 Final and sorted array: ";
	for(i=0 ; i<n ; i++)
	{
		cout<<final_array[i]<<" ";
	}
	
}
main()
{
	int *arr , n;
	cout<<"Enter size: ";
	cin>>n;
	arr = new int[n];
	cout<<endl<<"Enter elements in array: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	Count_Sort(arr,n);
}
