// k19-0209 Syed Muhammad Saad
#include<iostream>
using namespace std;
class MaxHeap{

int capacity,size;
int *array;

public:
MaxHeap(int data)
{
size = 0;
capacity = data;
array = new int (data);
}

int display()
{
cout<<endl<<" Elements in Max Heap"<<endl;
for (int i=0;i<size;i++)
{
cout<<array[i]<<" ";
}
}



int parent(int child)
{
if(child % 2 == 0)
{
return child / 2 - 1;
}
else
{
return child / 2;
}
}

int LeftChild(int parent)
{
return (parent*2 +1);
}

int RightChild(int parent)
{
return (parent*2 +2);
}

int InsertData(int data)
{
array[size]=data;
Shiftup(size);
size++;
}

int Shiftup(int index)
{
if(index==0)
{
return 0;
}
else
{
int parentindex = parent(index);
if(array[parentindex] < array[index])
{
swap(array[parentindex],array[index]);
Shiftup(parentindex);
}
}
}

int Shiftdown(int index)
{
int leftindex = LeftChild(index);
int rightindex = RightChild(index);
int max = index;

if((size > leftindex ) && ( array[leftindex] > array[index]))
{
max = leftindex;
}

if((size > rightindex ) && ( array[rightindex] > array[max]))
{
max = rightindex;
}

if( max != index)
{
swap(array[max],array[index]);
Shiftdown(max);
}
}

int Deletion(int index)
{
array[index] = array[size-1];
size=size-1;

Shiftdown(index);
}
};
main()
{
	int heapsize;

cout<<"Total no: of nodes :";
cin>>heapsize;


MaxHeap Max(heapsize);

cout<<"\nEnter Max Heap Elements\n";
for (int i=0;i<heapsize;i++)
{
int data;
cin>>data;
Max.InsertData(data);
}
Max.display();

int maxindex;
cout<<endl<<"Enter Heap Deletion Index :";
cin>>maxindex;
Max.Deletion(maxindex);
Max.display();
}
