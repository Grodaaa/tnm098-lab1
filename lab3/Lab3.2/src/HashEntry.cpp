#include <iostream>
#include <string>

using namespace std;

class HashEntry {
private:
      int key;
      string value;
public:
      HashEntry(int key, string value) {
            this->key = key;
            this->value = value;
      }
 
      int getKey() {
            return key;
      }
 
      string getValue() {
            return value;
      }
};