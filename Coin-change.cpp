#include<iostream>
using namespace std;

main(){
	int x, size;
	cout<<"Enter size: ";
	cin>>size;
	int *arr = new int[size];
	
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
		 	if(arr[j]<arr[j+1]){
		 		swap(arr[j],arr[j+1]);
			 }
		}
	}
	
	
	cout<<"Input targeted value: ";
	cin>>x;
	int sum = 0, count = 0;
	for(int i=0;i<size;i++){
		
		if(x>=arr[i]){
		
		while( x >= arr[i] ){
			sum = sum + arr[i];
			x = x - arr[i] ;
			count++;
		}
			
	}	
}

//	for(int i=0;i<size;i++){
//		count = count + x/arr[i];
//		x = x - x/arr[i]*arr[i];	
//}

	cout<<"\nMinimum denomination:"<<count<<"\nsum"<<sum;

}
