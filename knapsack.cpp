#include<iostream>
using namespace std;

main(){
	int x, size;
	cout<<"Enter size: ";
	cin>>size;

	int *obj = new int[size];
	int *profit = new int[size];
	int *weight = new int[size];
	float *proByWei = new float[size];
	
	for(int i=0;i<size;i++){
		obj[i] = i+1; 
	}
	
	cout<<"Enter profit and weight according to object: \n";
	
	for(int i=0;i<size;i++){
		cout<<"\nProfit for object: "<<obj[i]<<" ";
		cin>>profit[i];
		cout<<"\nWeight for object: "<<obj[i]<<" ";
		cin>>weight[i];
	}
	
	int dif = 0;
	for(int i=0;i<size;i++){
		proByWei[i] =  profit[i] / weight[i];
	}	
//	
//	for(int i=0;i<size;i++){
//		cout<<proByWei[i]<<" ";
//	}
	
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
		 	if(proByWei[j] < proByWei[j+1]){
		 		swap(proByWei[j],proByWei[j+1]);
		 		swap(obj[j],obj[j+1]);
		 		swap(profit[j],profit[j+1]);
		 		swap(weight[j],weight[j+1]);
			 }
		}
	}
	
	
	cout<<"Input Knapsack size: ";
	cin>>x;
	int total = 0, count = 0;
	for(int i=0;i<size;i++){
		
		if(x<=0){
			break;	
		}
		else if(x < weight[i] )
		{
			total = total + ( x/weight[i] * profit[i]);
			dif = weight[i] - x ;
			x = x - (weight[i] - dif) ;
		}else{
			x = x - weight[i];
			total = total + profit[i] ;
			cout<<"\nNow remaining weight is "<<x;
			cout<<" And Total= "<<total;	
		}
		 	
	}
	
	if(x==0)
		cout<<"\nMaximum Profit:"<<total;
}
