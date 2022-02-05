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
void Count_Sort(int arr[],int n, int pos)
{
	int *count,*final_array,i;
    const int k=10;
	count = new int[10];
	
	//Initialize with 0
	for(i=0 ; i<k ; i++)
	{		
		count[i]=0;
	}
	// Update with the counted elements in original array:
	for(i=0 ; i<n ; i++)
	{		
        count[ (arr[i]/pos) %10 ]++;
	}
	
	//Update the same array by adding consecutive numbers with each other except the number at first index
	for(i=1;i<=k;i++)
	{
		count[i] = count[i] + count[i-1];
	}
	
	// Took another array of same size of original array and fill in the sorted order by finding the index of each element of the original array in 
	//the count array, place the element at the index calculated 
	final_array = new int[n];
	for(i=n-1 ; i>=0 ; i--)
	{
		final_array[--count[ ((arr[i]/pos)%10) ] ]  =  arr[i] ;
        // count[(arr[i] / pos) % 10]--;
	}
	for(i=0 ; i<n ; i++)
	{
        arr[i] = final_array[i];
	}
	
}

void RadaxSort(int arr[] , int n)
{
    int m=0;
    m = max(arr,n);
    for(int pos = 1 ; m/pos>0 ; pos*=10)
    {
        Count_Sort(arr, n , pos);
    }
}

void printArray(int array[], int size) {
  int i;
  cout<<endl<<"4 Final and sorted array: ";
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main()
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
    RadaxSort(arr,n);
    printArray(arr,n);
    return 0;
}