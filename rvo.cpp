#include <iostream>

// rvo is not applied when return type is different from what actually is returned
// When there are multiple return statements (If else) (For NRVO only)
// When returning a complex expression (For NRVO only)

class Obj {
public: 
  int a;
  Obj(int x) : a(x) {
    std::cout << "Constructor\n";
  }
  Obj() : a(0) {
  std::cout << "Constructor-2 \n";
  }
  ~Obj() {
    std::cout << "Destructor\n";
  }

  Obj(const Obj& other) {
    this->a = other.a;
    std::cout << "Copy constructor \n";
  }

   
  Obj(Obj&& other) noexcept {
    this->a = other.a;
    std::cout << "Move constructor \n";
  }

  Obj& operator=(const Obj& other) {
    if(this==&other) return *this;
    this->a = other.a;

    std::cout << "Copy assignment operator \n";
    return *this;
  }

  Obj& operator=(Obj&& other) noexcept {
    if(this==&other) return *this;
    this->a = other.a;
    
    std::cout << "Move assignment operator \n";
    return *this;
  }

};

Obj createObj() {
  Obj a(3);
  return a;
}

int main() {
  Obj a = createObj(); // C++17 guaranteed copy elision. Use -fno-elide-constructors flag to turn off NRVO
}
