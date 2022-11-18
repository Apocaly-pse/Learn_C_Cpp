#include <iostream>

using namespace std;

class ZooAnimal {};
class Bear : public ZooAnimal {};
class Panda : public Bear, public Endangered {};
