// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
using namespace std;

void max_heapify_bottom(vector <int> &heap,int idx)
{
	if(idx == 0)
		return;

	int parent_idx = (idx-1)/2; // parent for 0-based array
	if(heap[parent_idx] < heap[idx])
	{
		// swap the data present at the two positions.
		// so that, the higher value is at the parent in order to satisfy the max heap property.
		int temp = heap[parent_idx];
		heap[parent_idx] = heap[idx];
		heap[idx] = temp;

		max_heapify_bottom(heap,parent_idx); // now check for the heap property at parent and its parent
	}
	else
	{
		return;
	}
}

void insert(vector <int> &heap,int key)
{
	heap.push_back(key);
	max_heapify_bottom(heap,heap.size()-1);
}

void display(vector <int> &heap)
{
	for(int i=0;i<heap.size();i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;

	return;
}

void max_heapify_topHeapSort(vector<int>&heap,int idx, int HeapSize)
{
	int leftidx = 2*idx + 1;
	int rightidx = 2*idx + 2;

	if(leftidx >= HeapSize && rightidx >= HeapSize)
		return;

	int largestidx = idx;
	if(leftidx < HeapSize && heap[leftidx]>heap[largestidx])
		largestidx = leftidx;
	if(rightidx < HeapSize && heap[rightidx]>heap[largestidx])
		largestidx = rightidx;

	if(largestidx == idx)
		return;

	else
	{
		swap(heap[idx],heap[largestidx]);
		max_heapify_topHeapSort(heap,largestidx,HeapSize);
	}
}

void max_heapify_top(vector<int>&heap,int idx)
{
	int leftidx = 2*idx + 1;
	int rightidx = 2*idx + 2;

	if(leftidx >= heap.size() && rightidx >= heap.size())
		return;

	int largestidx = idx;
	if(leftidx < heap.size() && heap[leftidx]>heap[largestidx])
		largestidx = leftidx;
	if(rightidx < heap.size() && heap[rightidx]>heap[largestidx])
		largestidx = rightidx;

	if(largestidx == idx)
		return;

	else
	{
		swap(heap[idx],heap[largestidx]);
		max_heapify_top(heap,largestidx);
	}
}

void DeletePeak(vector <int> &heap)
{
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	max_heapify_top(heap,0);
}

void BuildHeapOptimal(vector <int> &heap)
{
	for(int i=heap.size()-1;i>=0;i--)
	{
		max_heapify_top(heap,i);
	}

	// This is the O(N) approach as it does more work for less nodes and more work for less nodes;
}

void HeapSort(vector <int> &arr)
{
	int HeapSize = arr.size() - 1;
	BuildHeapOptimal(arr);
	for(int i=arr.size()-1;i>=0;i--)
	{
		swap(arr[0],arr[i]); // i is virtually the last index of heap
		HeapSize-- ;
		max_heapify_topHeapSort(arr,0,HeapSize);
	}
}

int main()
{
	// Type your code here.
	vector <int> arr;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}

	display(arr);
	HeapSort(arr);
	display(arr);


	return 0;
}