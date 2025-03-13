#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Heap
{
   private:
     int *items;
     int size = 0;
     int capacity;



     void swap(int first,int seccond)
     {
         int temp = items[first];
         items[first] = items[seccond];
         items[seccond] = temp;
     }
     int getParentIndex(int index)
     {
      return (index-1)/2;
     }
     void bubbleUp(int index)
     {
      while(index > 0 && items[index] > items[getParentIndex(index)])
      {
           swap(index, getParentIndex(index));
           index = getParentIndex(index);
      } 
     }
    bool isLeaf(int value)
    {
      for(int i = 0;i < size;i++)
      {
        if(value == items[i]){
           return items[(i*2)+1]&&items[(i*2)+2];
        }
      }
      return false;
    }
    int leftChildIndex(int index)
    {
      return index * 2 + 1;
    }
    int rightChildIndex(int index)
    {
      return index * 2 + 2;
    }
    int leftChild(int index)
    {
      return items[leftChildIndex(index)];
    }
    int rightChild(int index)
    {
      return items[rightChildIndex(index)];
    }
    bool ifValidParent(int index)
    {
      if(!hasLeftChild(index))
        return true;
      bool isValid = items[index] >= leftChild(index);
      if(hasLeftChild(index))
         isValid &= items[index] >= rightChild(index);
      return isValid;
    }
    int largerChildIndexf(int index)
    {
      if(!hasLeftChild(index))
        return index;
      if(!hasRightChild(index))
        return leftChildIndex(index);
      return (leftChild(index) > rightChild(index)) ? leftChildIndex(index) :  rightChildIndex(index);
    }
   

    bool hasLeftChild(int index)
    {
      return leftChildIndex(index) <= size;
    }
    bool hasRightChild(int index)
    {
      return rightChildIndex(index) <= size;
    }


    void bubbleDown()
    {
      int index = 0;
      while(index <=size && !ifValidParent(index))
      {
       int largerChildIndex = largerChildIndexf(index);
       swap(index, largerChildIndex);
       index = largerChildIndex;
      }
    }
   public:
   bool isEmpty()
   {
     return size == 0;
   }
   bool isFull()
   {
    return size == capacity;
   }
   Heap(int capacity = 10) : size(0), capacity(capacity) {
    items = new int[capacity];
   }

   ~Heap() {
    delete[] items;
   }
 
   void insert(int value)
   {
    if(isFull())
      throw invalid_argument("Heap is full!");
    items[size++] = value;
    bubbleUp(size-1);
   }
   int remove()
   {
    if(isEmpty())
      throw invalid_argument("The heap is empty");
    int root = items[0];
    items[0] = items[--size];
    bubbleDown();
    return root;
   }
};


class PriorityQueuewithHeap{

 private:
   Heap *heap = new Heap();
 public:

  void enqueue(int item)
  {
     heap->insert(item);
  }

  int dequeue()
  {
   return heap->remove();
  }
  bool isEmpty()
  {
    return heap->isEmpty();
  }
};

class maxHeap{
    private:
    static void heapify(int array[],int size,int index)
    {
      int largerIndex = index;
      int leftIndex = index * 2 + 1;
      int rightIndex = index * 2 + 2;
      if(leftIndex < size && array[leftIndex] > array[largerIndex])
          largerIndex = leftIndex;
      if(rightIndex < size && array[rightIndex] > array[largerIndex])
          largerIndex = rightIndex;
      if(index == largerIndex)
          return;
      swap(array,index,largerIndex);
      heapify(array,6,largerIndex);
    }

    static void swap(int array[],int first,int seccond){
      int temp = array[first];
      array[first] = array[seccond];
      array[seccond] = temp;
    }
    public:
    static void heapify(int array[],int size)
    {
      int lastParentIndex = size/2 -1;
      for(int i = lastParentIndex ;i >= 0;i--)
      {
        heapify(array,size,i);
      }
    }

    static int KthLargestvalue(int array[],int kth,int size)
    {
      Heap heap;
      for(int i = 0;i < size;i++)
        heap.insert(array[i]);
      for(int i=0;i < kth-1;i++)
      {
        heap.remove();
      }
      return heap.remove();
    }


    static bool isMaxHeap(int array[],int size)
    {

      for(int i = 0; i < (size / 2) - 1;i++)
      {
        int leftchild = i * 2 + 1;
        int rightchild = i * 2 + 2;
        if(leftchild < size && array[i] < array[leftchild])
           return false;
        if(rightchild < size && array[i] < array[rightchild])
           return false;
      }

      return true;
    }


};


class minHeap{
 private:
  class Node{
    public:
    int key;
    string value;

    public:

    Node(int k, string v) : key(k), value(v) {};
    
    void setKey(int k){this->key = k;}
    void setValue(string v){this->value = v;}
 
    int getKey() const {return this->key;}
    string getValue() const{return this->value;}
  };


  std::vector<minHeap::Node> heap;

  int parent(int i){return (i - 1)/2;}
  int leftChild(int i){return 2 * i + 1;}
  int rightChild(int i){return 2 * i + 2;}

  void bubbleUp(int i)
  {
    while(i > 0 && heap[parent(i)].getKey() > heap[i].getKey())
    {
      swap(heap[parent(i)],heap[i]);
      i = parent(i);
    }
  }

  void bubbleDown(int i)
  {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if(left < heap.size() && heap[left].getKey() < heap[smallest].getKey())
       smallest = left;
    if(right < heap.size() && heap[right].getKey() < heap[smallest].getKey())
       smallest = right;
    
    if(smallest != i)
    {
      swap(heap[i],heap[smallest]);
      bubbleDown(smallest);
    }
  }


  public:

  void insert(int key, string value)
  {
    Node newNode(key,value);
    heap.push_back(newNode);
    bubbleUp(heap.size() - 1);
  }

  Node extractMin()
  {
    if(heap.empty())
      throw runtime_error("Heap is empty!");
    
    Node minNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    bubbleDown(0);
    return minNode;
  }
 void printHeap()
 {
  for (const auto& node: heap)
  {
    cout<< "("<< node.getKey() << ", " << node.getValue() << ") ";
  }
  cout<<endl;
 }

};


int main()
{
   Heap *heap = new Heap();
   heap->insert(10);
   heap->insert(5);
   heap->insert(17);
   heap->insert(4);
   heap->insert(22);
   heap->remove();
   delete heap; 
   int array[6] = {5,3,10,1,4,2};
   Heap *heap2 = new Heap();

   for(const auto& num: array)
    heap2->insert(num);
  
    for(int i = 0;i<6;i++)
    {
      array[i] = heap2->remove();
      cout<<array[i];
    }
    PriorityQueuewithHeap *queue = new PriorityQueuewithHeap();
    queue->enqueue(5);
    queue->enqueue(3);
    queue->enqueue(10);
    queue->enqueue(1);
    queue->isEmpty();
    cout<<endl;
    int numbers[6] =  {5,3,8,4,1,2};

    maxHeap::heapify(numbers,6);
    for(int num: numbers)
     cout<<num<<endl;
     cout<<"kth largest number"<<endl;
     cout<<maxHeap::KthLargestvalue(numbers,1,6);
     cout << endl;

     if (maxHeap::isMaxHeap(numbers, 6)) {
      std::cout << "The array is a max-heap." << std::endl;
  } else {
      std::cout << "The array is NOT a max-heap." << std::endl;
  }



  minHeap minHeap;

  // Insert nodes into the heap
  minHeap.insert(10, "Apple");
  minHeap.insert(5, "Banana");
  minHeap.insert(15, "Cherry");
  minHeap.insert(3, "Date");
  minHeap.insert(7, "Elderberry");

  // Print the heap
  std::cout << "Heap after insertions: ";
  minHeap.printHeap();

  std::cout << "Extracted min: (" << minHeap.extractMin().getKey() << ", " << minHeap.extractMin().getValue() << ")\n";
    return 0;
}