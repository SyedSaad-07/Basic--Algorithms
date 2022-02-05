#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,pointer;
void Swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
}
int Check(int array[],int left,int right)
{
    for(int i=left;i<right;++i)
    {
        if(array[i] > array[i+1])
        left = i;
        pointer = left;
        for(int k=i-1;k>right;++k)
        {
            if(array[i-1]>array[k+1])
            {
                pointer = 0;
                break;
            }
        }
        return pointer;
    }
    return -1;
}
int OBO(int array[],int left,int right)
{
    if(array[left]<=array[left+1])
    {
        ++left;
        pointer = Check(array,left,right);
        if(pointer == -1)
        return pointer;
    }
    else
    pointer = 0;
    for(int i=pointer;i<right;++i)
    {
        for(int j=i;j<right;++j)
        {
            if(array[i]>=array[j+1])
            {
                Swap(array[i],array[j+1]);
            }
        }
    }return 0;}

int main()
{
	cout << "Enter number of elements: ";
	cin>>n;
    int *arr;
    arr = new int[n];
    cout << "Before Sorting: ";
    for(int i=0; i<n; i++){
    	int a;
    	a=rand() % 100;
    	if(a<0)
    	{
    		a=a*-1;
    	}
	arr[i] = a;
	}
    for(int i=0;i<n;++i)
    cout << arr[i] << " ";
    OBO(arr,0,n);
    cout << "\nAfter Sorting: ";
    for(int i=0;i<n;++i)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}
