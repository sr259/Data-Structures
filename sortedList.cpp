#include <iostream>
#include <list>
#include <algorithm>
#include <string>

namespace csci2100 {
	template <typename ItemType>
	class SortedList{
	private:
		std::list<ItemType> _list;
	public:
		void add(ItemType item) {
      typename std::list<ItemType>::iterator it = _list.begin(); //an iterator is made that begins in the beginning of _list
      while (*it < item && it != _list.end()){ // finds the location where the iterator should place the object comparing the size of the item and the value the iterator is at
        it++;
      }
      if (*it == item && it != _list.end()){ // if the iterator is equal to the item, nothing is inserted
      }else{
        _list.insert(it,item); // the item is inserted at the iterator location
      }
		}

		void remove(ItemType item) {
    typename std::list<ItemType>::iterator it = _list.begin();//an iterator is made that begins in the beginning of _list
      while (*it < item && it != _list.end()){  // finds the location where the iterator should remove the object comparing the size of the item and the value the iterator is at
        it++;
      }
      if (*it == item && it != _list.end()){ // once the iterator finds the value that is equal to the item, the item is erased at the iterator
        _list.erase(it);
        return;
      }else{return;} // if the iterator doesn't find the item, nothing is removed
		}    

		
    bool contains(ItemType item) {
       for (ItemType value: _list){ //iterates through all the values in the list
        if (value == item){return true;} //if the value is equal to the item, _list contains the item
      }
      return false;
			}
		
		ItemType get(int i) {
      int index{0}; //index that helps put a numerical value to the iterator
      try{
        if (i>= _list.size()){ //throwing an exception when the index is >= to the _list size
          throw i;
        }
        for(ItemType value: _list){
         if (index == i){ //if the index is equal to the i value, the value is returned
           return value;
         }
         index++; // index is increased at the end of the for loop
       } 
      }
      catch (int ex){ //catches the exception and 
        std::cout << ex <<" is larger than SortedList size, largest value is returned: ";}
       return _list.back();
       }
		int size() {
			return _list.size(); 
		}
    
    void print(){
      if (_list.size() != 0){// code will not run if the size == 0
      for(auto i: _list){ //iterates through the list
        if (i != _list.back()){ //if i isnt the last item in the list, there needs to be a comma and a space for organization
          std::cout << i << ", ";}
          else{ //there
            std::cout <<i;
          }

      }
      std::cout << std::endl;
    
    }
    }
	};

}

int main() {
	using namespace csci2100;
	SortedList<int> test;
  std::cout << "TEST WITH INTEGERS" <<std::endl;
std::cout <<std::endl;
	test.add(1);
  test.add(1);
  test.add(3);
  test.add(4); 
  std::cout << "After adding the value 1 twice to the set, as well as 3 and 4, how many items are in the set (should be 3): " << test.size() << std::endl;
  std::cout << std:: endl;

  std::cout << "What are the values of the list: ";
  std::cout << std:: endl;

  test.print();
  std::cout << "In a set of 1,3,4, does the set contain 4: " << test.contains(4) << std::endl;
  std::cout << "In a set of 1,3,4, does the set contain 5: " << test.contains(5) << std::endl;
test.remove(1);
std::cout << std:: endl;

  std::cout << "After removing the value 1 from the set how many items are in the set (should be 2): " << test.size() << std::endl;
std::cout << std:: endl;

  std::cout << "After removing the value 1 from the set, the value at index 0 is(should be 3): " << test.get(0)<< std::endl;
  std::cout << "This is what is returned when you want an item in the set that is bigger than the size of the list: " << test.get(20) ;
  
  test.add(5);
  test.add(6);
  test.add(7);
  std::cout << std:: endl;

  std::cout << "After adding the values 5,6,7, how many items are in the set (should be 5): " << test.size() << std::endl;
  test.remove(7);
  std::cout << std:: endl;

std::cout << "After removing the 7 from the list, what is the last item of the list (should be 6): " << test.get(3) << std::endl;
test.remove(3);
test.remove(4);
test.remove(5);
test.remove(6);
std::cout << std:: endl;

std::cout << "When removing all of the items in the list, the size is: " << test.size() << std::endl;
std::cout << std:: endl;
//test w/ strings
std::cout << "*NEW TEST WITH STRINGS*" <<std::endl;
std::cout << std:: endl;
SortedList<std::string> test2;
test2.add("Banana");
test2.add("Apple");
test2.add("Cherry");
std::cout << "When making a new SortedList with strings, what are the items in the list: ";
test2.print();
std::cout << "Does the set contain Apple: " << test2.contains("Apple") << std::endl;
std::cout << "Does the set contain Oranges: " << test2.contains("Oranges") << std::endl;
test2.remove("Apple");
std::cout << "When Apple is removed, what is the value in index 0 (should be Banana): " << test2.get(0) << std::endl;
std::cout << "The current size after removing Apple is (should be 2): " << test2.size() << std::endl;
std::cout << "This is what happens when an index >= the size is inserted in the get function: "<< test2.get(5) << std::endl;
std::cout << "This is the size when two items are in the sortedlist: " << test2.size() <<std::endl;
test2.remove("Cherry");
test2.remove("Banana");
std::cout << "After removing everything else from the set, trying to print the set will get you (expecting nothing): " <<std::endl;
test2.print();
}

