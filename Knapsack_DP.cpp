#include<iostream>
using namespace std;
int Knapsack(int value[] , int wt[] , int n , int W)
{
	if(n==0 || W==0)
	{
		return 0;
	}
	if(wt[n-1]>W)
	{
		return Knapsack(value,wt,n-1,W);
	}
	return max(Knapsack(value , wt , n-1 , W-wt[n-1]) + value[n-1] , Knapsack(value , wt , n-1 , W));
	
}
main()
{
	int value[]={100,200,30,50,10,20};
	int weight[]={20,30,10,5,40,60};
	cout<<Knapsack(value,weight,6,150);
}
