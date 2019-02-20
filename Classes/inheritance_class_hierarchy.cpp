#include <iostream>

class Rectangle {
  public:
    Rectangle(double length, double width) {
      this->l_ = length;
      this->w_ = width;
    }

    void Scale(double sl, double sw) {
      // Scales the dimensions
      this->l_ *= sl;
      this->w_ *= sw; 
    } 

    double Length() const { return this->l_; }
    double Width() const { return this->w_; }
  private:
    double l_;
    double w_;
};

// Can we derive square class from rectangle class?
class Square : public Rectangle {
  // derives from Rectangle class
};

// Base and Derived class
class Base {
  public:
    void print() {
      std::cout << "It's base object with type: " << this->type << std::endl;
    }
  private:
    int type = 1;
};

class Derived : public Base {
  public:
    void print() {
      std::cout << "It's derived object with type: " << this->type << std::endl;  
    }
  private:
    int type = 2;
};

int main() {
  // implicit conversion of derived class to base class
  Derived* d = new Derived;
  Base* b = d; // allowed
  
  b->print();

  Base* b_ = new Base; 

  // Derived* d_ = b_; // not correct, throws error

  // explicit conversion of base class to derived class
  Derived* d_new = static_cast<Derived*>(b_); // correct
   
  // print about the object
  d_new->print();
}
