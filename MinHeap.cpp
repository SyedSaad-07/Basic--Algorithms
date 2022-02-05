// k19-0209 Syed Muhammad Saad
#include<iostream>
using namespace std;
class MinHeap{
int capacity,size;
int *array;

public:
MinHeap(int data)
{
size = 0;
capacity = data;
array = new int (data);
}

int display()
{
cout<<endl<<" Elements in Min Heap"<<endl;
for (int i=0;i<size;i++)
{
cout<<array[i]<<" ";
}
}

bool CheckLeave(int index)
{
if(index>=size)
{
return true;
}
else
{
return false;
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
if(array[parentindex] > array[index])
{
swap(array[parentindex],array[index]);
Shiftup(parentindex);
}
}
}

int shiftdown(int index)
{
int leftindex = LeftChild(index);
int rightindex = RightChild(index);

int Min;
if((size > leftindex) && (array[leftindex] < array[index]))
{
Min = leftindex;
}

if((size > rightindex) && (array[rightindex] < array[Min]))
{
Min = rightindex;
}

if(Min != index)
{
swap(array[Min],array[index]);
shiftdown(Min);
}
}

int Deletion(int index)
{
array[index] = array[size-1];
size=size-1;

shiftdown(index);
}
};

main()
{
	int heapsize;

cout<<"Total no: of nodes :";
cin>>heapsize;

MinHeap Min(heapsize);

cout<<endl<<"Elements in Min Heap "<<endl;
for (int i=0;i<heapsize;i++)
{
int data;
cin>>data;
Min.InsertData(data);
}

Min.display();
}
