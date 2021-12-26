#include <iostream>
#include <vector>
using std::vector,std::cout,std::endl;
class myMaxHeap {
      private:
      vector<int> _myMaxHeap; 
// Store elements in vector 
      int _elements{}; 
// Keeps track of number of elements
      int _getParent(int index) { 
// Returns parent index using child index
          int parentIndex = (index-1)/2; 
// From zybooks 
          if (parentIndex < 0) { 
// For percolate up
          return -1; 
// Null parent, done percolating up
 }
 return parentIndex; 
 }
 int _getLeftChild(int index) { 
// Returns left child index using parent index
 int childIndex = 2*index+1; 
// From zybooks
 if (childIndex >= _elements) { 
// No child, parent node was leaf node
 return -1; 
// Null child, leaf node provided
 }
 return childIndex;
 }
 int _getRightChild(int index) { 
// Returns right child index using parent index
 int childIndex = 2*index+2; 
// Implied from zybooks
 if (childIndex >= _elements) { 
// No child, parent node was leaf node
 return -1; 
// Null child, leaf node provided
 }
 return childIndex;
 }
 public:
 void insert(int item) { 
// Add items to the heap
 if (_elements < _myMaxHeap.size()) { 
// Vector contains junk values
 _myMaxHeap.at(_elements) = item; 
// Overwrite junk value with new item
 }
 else {
 _myMaxHeap.push_back(item); 
// Full vector, no junk values, must pushback
 }
 _elements++; 
// Increment number of elements 
 percolateUp(_elements-1); 
// Maintain maxHeap properties using percolateUp
 }
 void remove() { 
// Removes top item, normal maxHeap delete
 _myMaxHeap.at(0) = _myMaxHeap.at(_elements-1); 
// Move last element to root
 _elements--; 
// Decrement number of elements
 percolateDown(0); 
// Maintain maxHeap properties 
 }
 int peekTop() { 
// Returns max value in heap, utility function
 if (_elements == 0) { 
// Nothing to return, returns null i.e. -1
 return -1;
 }
 return _myMaxHeap.at(0); 
// Return root node which is max value
 }
 void percolateUp(int index) { 
// Moves inserted value to correct index
 while (_getParent(index) != -1) { 
// Parent cannot be null to percolate up
 int parentIndex = _getParent(index); 
// Eventually gives parentIndex = -1
 if (_myMaxHeap.at(parentIndex) < _myMaxHeap.at(index)) { 
// Check parent < child
 int temp = _myMaxHeap.at(index); 
// Temporarily store item to percolate up
 _myMaxHeap.at(index) = _myMaxHeap.at(parentIndex); 
// Swap parent and child
 _myMaxHeap.at(parentIndex) = temp; 
// Swap parent and child
 index = parentIndex; 
// New index to continue percolating up
 }
 else {
 break; 
// Maxheap achieved, break while loop
 } 
 }
 }
 void percolateDown(int index) { 
// Moves root node after removal to proper place
 int left{_getLeftChild(index)}; 
// Store index of left child
 int right{_getRightChild(index)}; 
// Store index of right child
 int max{}; 
// Store index of max(right,left,parent)
 if (left != -1 && _myMaxHeap.at(left) > _myMaxHeap.at(index)) {
 max = left; 
// Left child not null, left child greater than index value, max = left temporarily 
 }
 else {
 max = index; 
// Left is null or less than index val, max = index temporarily 
 }
 if (right != -1 && _myMaxHeap.at(right) > _myMaxHeap.at(max)) {
 max = right; 
// Same as checking left child but now checks against current max, sets final max value if any change
 }
 if (max != index) { // If max = index no change needed
 int temp = _myMaxHeap.at(index); 
// Temporarily Store current index value
 _myMaxHeap.at(index) = _myMaxHeap.at(max); 
// Swap max and current index
 _myMaxHeap.at(max) = temp; 
// Swap max and current index
 percolateDown(max); 
// Continue percolating until max = index
 }
 }
 void coutHeap() { 
// Utility function to visualize heap 
 cout << "myMaxHeap = ";
 for(size_t i{}; i < _elements; i++) { 
// Cout all elements excluding junk values which could be still stored in vector
 cout << _myMaxHeap.at(i) << " ";
 }
 cout << endl;
 }
};
int main() {
 myMaxHeap heap;
 int testSize{7};
 for (size_t i{}; i <= testSize; i++) { 
// Fill heap with misc. values defined by testSize, testing insert function 
 if (i%2 == 0) { 
// Modulo for fun
 heap.insert(i*4); 
// More just for fun
 }
 else {
 heap.insert((i*4)/2); 
// More just for fun
 }
 }
 heap.coutHeap(); 
// Print current heap, checked various size cases on paper, testing coutHeap function
 cout << "The max element in the heap is: " << heap.peekTop() <<endl; // Test peekTop function
 heap.remove(); 
// Test removal function
 cout << "After removing the max element," << endl;
 heap.coutHeap();
 cout << "Which is still a maxHeap and has been restructured accordingly." << endl;
 heap.insert(testSize*4);
 cout << "Inserting another max value (4*testSize) gives" << endl;
 heap.coutHeap();
 cout << "Which may or may not be the original max heap but maintains maxHeap properties." 
 << endl; 
 cout << "Removing each element one by one provides the following maxHeaps:" << endl;
 for (size_t i{}; i <= testSize; i++) {
// Testing fully emptying and refilling the heap with new values
 heap.remove();
 heap.coutHeap();
 }
 cout << "Where the last maxHeap is an empty maxHeap." << endl 
 << "Refilling the max heap with different values gives:" << endl;
 for (size_t i{}; i <= testSize; i++) {
 if (i%2 == 0) { 
 heap.insert(i*3); 
// Guarantees duplicate element when combined with below statement, unique test case
 }
 else {
 heap.insert((i*5)/2);
// Guarantees duplicate element when combined with above statement, unique test case
 }
 }
 heap.coutHeap();
 cout << "Which is guaranteed to have a duplicate element though still maintains " 
 << "maxHeap properties, since parent >= child means two elements may be equal."  << endl;
 return 0;}