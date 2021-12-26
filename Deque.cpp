#include <iostream>
#include <vector>
#include <array>
#include <string>

namespace csci2100{
template <typename ItemType>

class Deque{
  private:
  std::vector<ItemType> _dector;
  int _back{0},_size{0},_capacity{4},_front{0};
  
  void resize(){ //resize function used throughout to resize the vector when _size ==_capacity
    if(_size != 0){
    std::vector<ItemType> temp; //temp vector used to store _dector data
    temp.resize(_capacity);//temp is made the size of the current capacity
    for(int i = 0; i< _size; i++){ // for loop that copies the dector to the temp in order so _front ends up at index 0
      temp[i] = _dector[_front];
      if (_front == _capacity - 1){
        _front = 0;
      }
      else{_front++;}
    }
  _capacity = _capacity*2; // _capacity is then mulitplied
  _dector = temp;// the organized data is coppied into _dector
  _dector.resize(_capacity);// dector's capacity is now twice that it was before
  _front = 0;//_front is now the beginning of the dector
  _back = _size-1;// _back is size -1
  }}
  
  public:
  void push_front(ItemType item){
    if(_dector.size()!=_capacity){ //used to make sure that the actual vector length matches the capacity 
    _dector.resize(_capacity);}
    if (_size == _capacity){resize();} //if size has reached the limit, the resize function is used
    if (_size == 0){ //if there are no items, then there is no need to change the _front location
      _dector[_front] = item;
      _size++;
    }else if (_front == 0 && _size>0){ // if there is at least one item in the vector and _front == 0, _front will change the position to be _capacity -1
      _front = _capacity - 1;
      _dector[_front] = item;
      _size++;
    }
    else if (_front >0){ //every other instance when _front is not 0, it will be going backwards in the vector
      _front--;
      _dector[_front] = item;
      _size++;
    }
  }
  
  void push_back(ItemType item){ 
    if(_dector.size()!=_capacity){//same as push_front^
    _dector.resize(_capacity);}
    if (_size == _capacity){resize();}//same as push_front^
    if(_size == 0){//if there is no other item, no need to change _back
      _dector[_back] = item;
      _size++;
    }
    if((_back == 0 && _size == 1)|| _back!=_capacity){ //either instances will require you to add one to _back
      _back++;
      _dector[_back]=item;
      _size++;
    } 
  }
  void pop_front(){

    if (_size > 0){//code will not run if there is no items in the vector
    if (_size == _capacity){resize();}//same as push_front^^
    if(_front == _capacity-1){ //if _front is _capacity -1, then _front needs to go back to the front of the vector
      _front = 0;
      _size--;
    }else if(_front == _back){ //this only occurs when both front and back are equal to zero and that there is only one item in the list, when this happens, the vector will be cleared
      _dector.clear();
      _dector.resize(_capacity);
      _size--;

    }
    else{_front++;_size--;} //every other instance will require _front to be increased
    }

}
  
  void pop_back(){
    if(_size>0){//code wont run if there aren't any items
    if (_size == _capacity){resize();}//^^
    
    if(_back == 0 && _front > 0){//if back is equal to zero and _front is larger then back, then _back needs to go to the back of the vector
      _back = _capacity-1;
      _size--;
    }else if(_back >0){ //in this case, _back needs to go down the vector
      _back--;
      _size--;
      
    }if(_back == _front){ // same as pop_front^
      _dector.clear();
      _dector.resize(_capacity);
      _size--;
    }
    }

}
  void peek_front(){ //shows the front value only if there are items in the deque
    if(_size!=0){
    std::cout<< _dector[_front];}
    std::cout << std::endl;

  }
   void peek_back(){//shows the back value only if there are items in the deque
     if(_size!=0){
       std::cout<<  _dector[_back];}
       std::cout << std::endl;
   }
  bool isEmpty(){
    if (_size == 0){
      return true;
    }
    return false;
    }
  
  int getLength(){
    return _size;
  }
  void getDeque(){ //prints the deque
    if (_size!=0){
    int tempFront = _front;
    for(int i = 0; i<_size;i++){
      std::cout << _dector[_front] << " ";
      if (_front == _capacity-1){_front = 0;}
      else{_front++;}        
    }
    std::cout << std:: endl;
    _front = tempFront;}}
  
    
  //MEANT FOR VISUALIZATION FOR TESTS
  void getVector(){ //used to show how the deque is implemented in the tests
    for (int i=0;i!=_capacity;i++){
      std::cout << _dector.at(i) << " ";
    }
    std::cout << std::endl;
  }
  
};
}
namespace csci2100{}
int main() {
csci2100::Deque<int> test;
test.push_front(8);
test.push_front(7);
test.push_back(6);
test.push_back(5);
std::cout << "TEST WITH INTEGERS" << std::endl;
std::cout << std::endl;
std::cout << "With push_front(8), push_front(7), push_back(6), push_back(5), the current Deque is: ";
test.getDeque();
std::cout << "Here is the front value (should be 7): "; test.peek_front();
std::cout << "Here is the back value (should be 5): "; test.peek_back();
std::cout << "Here is the current size (should be 4): " << test.getLength() << std::endl;
std::cout << "Here is the VECTOR without the organization: ";
test.getVector();
test.push_back(4);
std::cout << "When doing push_back(4) to the deque, the vector will resize and organize itself in a total of 8 spaces. Here is the VECTOR: ";
test.getVector();
std::cout << "Here is the Deque: ";
test.getDeque();
test.pop_back();
std::cout << "After pop_back(), the current deque is (should be 7,8,6,5): ";
test.getDeque();
test.pop_front();
std::cout << "After pop_front(), the current deque is (should be 8,6,5): ";
test.getDeque();
std::cout << "Here is the current size (should be 3): " << test.getLength() << std::endl;
std::cout << "Athough the deque is changed, the vector still has the values, but they will never be accessed again: ";test.getVector();
test.push_front(44);
test.push_back(99);
test.push_front(12);
std::cout << "After push_front(44), push_back(99), and push_front(12), the deque is: ";
test.getDeque();
std::cout << "The vector is: ";
test.getVector();
std::cout << "Is the deque empty?: "<< test.isEmpty() << std::endl;
test.pop_front();test.pop_front();test.pop_front();test.pop_back();test.pop_back();test.pop_back();
std::cout << "After we pop_front 3 items and pop_back() 3 items, this is the deque (should be nothing): "<<std::endl;
test.getDeque();
std::cout << "Is the deque empty?: "<< test.isEmpty() << std::endl;
std::cout << "Here is the front value (should be nothing): ";test.peek_front();
std::cout << "Here is the back value (should be nothing): "; test.peek_back();
std::cout << "Here is the current size (should be 0): " << test.getLength() << std::endl;
std::cout << std::endl;
std::cout << "TEST WITH CHARACTERS" << std::endl;
std::cout << std::endl;
csci2100::Deque<char> test2;
test2.push_front('A');
test2.push_back('B');
test2.push_front('C');
std::cout << "After push_front(A), push_back(B), push_front(C), the deque is: ";
test2.getDeque();
std::cout << "Here is the front value (should be C): ";test2.peek_front();
std::cout << "Here is the back value (should be B): ";test2.peek_back();
std::cout << "Here is the current size (should be 3): " << test2.getLength() << std::endl;
std::cout << "Here is the VECTOR without the organization: ";
test2.getVector();
test2.push_back('D');
test2.push_front('E');
std::cout << "When doing push_back(D) and push_front(E) to the deque, the vector will resize and organize itself in a total of 8 spaces. Here is the VECTOR: ";
test2.getVector();
std::cout << "Here is the Deque: ";
test2.getDeque();
test2.pop_back();
test2.pop_back();
std::cout << "After doing pop_back() twice, the current deque is (should be E,C,A): ";
test2.getDeque();
std::cout << "Here is the current size (should be 3): " << test2.getLength() << std::endl;
std::cout << "Athough the deque is changed, the vector still has the values, but they will never be accessed again: ";test2.getVector();
test2.push_front('F');
test2.push_back('G');
test2.push_front('H');
std::cout << "After push_front(F), push_back(G), and push_front(H), the deque is: ";
test2.getDeque();
std::cout << "The vector is: ";
test2.getVector();
std::cout << "Is the deque empty?: "<< test2.isEmpty() << std::endl;
test2.pop_front();test2.pop_front();test2.pop_front();test2.pop_back();test2.pop_back();test2.pop_back();
std::cout << "After we pop_front 3 items and pop_back() 3 items, this is the deque (should be nothing): "<< std::endl;

test2.getDeque();
std::cout << "Is the deque empty?: "<< test2.isEmpty() << std::endl;
std::cout << "Here is the front value (should be nothing): ";test2.peek_front();
std::cout << "Here is the back value (should be nothing): "; test2.peek_back();
std::cout << "Here is the current size (should be 0): " << test2.getLength() << std::endl;
}

  




  




