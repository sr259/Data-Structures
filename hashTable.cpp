#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

class HashTable{


};


int main() {
  int buckets;
  std::cout << "Please specify how many buckets are in the hash table: ";
  std::cin >> buckets;
  std::vector<std::list<int>> bucky(buckets);

  for (int i = 0; i < 50; i++) {
    int random = rand()%100;
    int index =  random % buckets;
    bucky[index].push_back(random);
  }
  for (std::list i : bucky){
   for (int t : i){
     std::cout << t << ", ";
   }
   std::cout << std::endl;
  }
} 