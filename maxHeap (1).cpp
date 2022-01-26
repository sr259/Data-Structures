//import dictionaries 
#include <iostream>
#include <vector>
#include <string>

template <typename ItemType>
class maxHeap {
  private:
    int _size = 0;
    std::vector<ItemType> vect;
    
    int parent(int index){ //finds the parent's index, if there isnt, it will return -1
      if (((index-1)/2)<0){return -1;}
      return (index-1)/2;}

    int leftChild(int index){//finds the left childs index, if there isnt one, it will return -1
      if ((index*2)+1 >=_size){return -1;}
      return (index*2)+1;}

    int rightChild(int index) {//finds the right childs index, if there isnt one, it will return -1
      if ((index*2)+2 >= _size){return -1;}
      return (index*2)+2;}
    
    void Up(int index) { 
      while (parent(index) != -1) { //code only runs if there is a parent     
        if (vect[parent(index)] < vect[index]) { //if the parent's index is less than that of the childs
          int tempValue = vect[index]; 
          vect[index] = vect[parent(index)]; //swap the parent and child
          vect[parent(index)] = tempValue; 
          index = parent(index); }
        else { //the maximum is achieved
          break;}
      }
 }
    void Down(int index){ 
      int maxVal;
      if (leftChild(index) != -1){//checks to see if leftChild exists
        if(vect[leftChild(index)] > vect[index]){//checks to see if left child is greater than index value
          maxVal=leftChild(index);}} 
      if (rightChild(index) != -1){ //checks to see if rightChild exists
        if(vect[rightChild(index)]>vect[index]){//checks to see if right child is greater than index value
          maxVal=rightChild(index);}}
      if(maxVal != index){ //if maxVal is equal to the index nothing happens, continues to find the max value if max is not equal
        int tempVal = vect[index];
        vect[index]=vect[maxVal];//switches the values
        vect[maxVal]=tempVal; 
        Down(maxVal);}
        
    }
 
  public:

    ItemType getMax() {// returns the Maximum Value 
      if(_size == 0){//if this index doesn't exist, you return -1
        return -1;}
      else{
        return vect[0];}
    }
 

    void insert(ItemType item){
      if(_size < vect.size()){ //if the size of the maxHeap is less then the vector's length, there is no need to increse the size of the vector by push_back
      vect[_size] = item;}
      else{vect.push_back(item);}
      Up(_size); //allocates the item upwards to the correct spot
      _size++; //size is increased
    }
 
   
    void remove(){//removes max number from the heap
    vect[0] = vect[_size-1]; //brings the back value down to the front
    _size--;
    Down(0); // brings down that value
    }

     bool isEmpty() {//checks to see if _size is 0
      if (_size ==0){
        return true;
      }else{
        return false;
      }
      }

    void clear(){ //simple clear function
      vect.clear();
      vect.resize(0);
      _size = 0;
    }
    void print(){ // prints the values in the vector
      if(_size!=0){
      for(int i =0; i < _size; i++){
        std::cout << vect[i] << " ";
      }
    }      std::cout << std::endl;

    }


};
int main(){
  maxHeap<int> test;
  std::cout << "TEST 1: INTEGERS" << std::endl;
  std::cout << "When making a new heap with nothing in it, it should be empty: " << test.isEmpty() << std::endl;
  test.insert(30);
  test.insert(20);
  test.insert(40);
  test.insert(10);
  std::cout << "Here are the current values in the maxHeap: " << std::endl;
  test.print();
  std::cout << "In a heap with the #s 40,30,20,10, it shouldnt be empty: " << test.isEmpty() << std::endl;
  std::cout << "In a heap with the #s 40,30,20,10, using getMax should give us 40: " << test.getMax() << std::endl;
  test.remove();
  std::cout << "After remove, here are the values in the maxHeap: ";
  test.print();
  std::cout << "After removing the the max value, the now supposed heap with #s 30,20,10, using getMax should give us 30: " << test.getMax() << std::endl;
  test.insert(35);
  std::cout << "Inserting 35 in the list should return 35 when using getMax: " << test.getMax() << std::endl;
  test.clear();
  std::cout << "When clearing the list, I should get no maxVal (should return -1): " << test.getMax() << std::endl;
  test.insert(1);
  test.insert(2);
  test.insert(3);
  test.insert(4);
  test.insert(5);
  test.insert(5);
  std::cout << "After clearing the list and adding 1,2,3,4,5,5 to the heap, the max value should be 5: " << test.getMax() << std::endl;
  test.remove();
  std::cout << "After removing one 5 from the heap, the max still should be 5: " << test.getMax() << std::endl;
  test.clear();
  test.insert(1);
  std::cout << "After clearing the list and adding 1 to the heap, the max value should be 1: " << test.getMax() << std::endl;
  std::cout << std::endl;

  std::cout << "TEST 2: CHARACTERS" << std::endl;
  std::cout << std::endl;
  maxHeap<char> test2;
  std::cout << "When making a new heap with nothing in it, it should be empty: " << test2.isEmpty() << std::endl;
  test2.insert('A');
  test2.insert('B');
  test2.insert('C');
  std::cout << "After making a new maxHeap with when inserting A,B, and C, the values in the maxheap are: ";
  test2.print();
  test2.remove();
  std::cout << "After remove, the maxValue is (should be B): " << test2.getMax() <<std::endl;
  test2.insert('R'); test2.insert('A');
  std::cout << "After inserting A and R, the maxValue is (should be R); " << test2.getMax() <<std::endl;
  std::cout << "The values in the maxheap are: ";
  test2.print();
  test2.remove();
  std::cout << "After remove, the maxValue is (should be B): " << test2.getMax() << std::endl;
  test2.clear();
  std::cout << "After clearing the list, is the test empty: " << test2.isEmpty() <<std::endl;
  std::cout << "Here is the maxHeap (should be nothing): ";
  test2.print();
  test2.insert('G');
  std::cout << "After clearing the list and adding G to the heap, the max value should be G: " << test2.getMax() << std::endl;
  std::cout << std::endl;

}