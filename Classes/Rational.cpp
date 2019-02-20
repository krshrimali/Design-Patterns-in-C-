#include <iostream>

class Rational {
  public:
    Rational(int n, int d) {
      this->n_ = n;
      this->d_ = d;
    }
    Rational& operator += (const Rational& rhs);
    Rational& print();
  private:
    long n_;
    long d_;
    Rational& reduce() {
      // TODO: reduces a function 
      return *this;            
    }
};

Rational& Rational::operator+=(const Rational& rhs) {
  // std::cout << "n_" << rhs.n_ << "d_" << rhs.d_ << std::endl;
  n_ = n_ * rhs.d_ + rhs.n_*d_;
  d_ = d_ * rhs.d_;
  *this = reduce();
  return *this;
}

Rational& Rational::print() {
  std::cout << this->n_ << "/" << this->d_ << std::endl;
  return *this;
}

int main() {
  Rational a(1, 2);
  Rational b(3, 4);
  a.print();
  b.print();
  
  std::cout << "Doing: a + b" << std::endl;

  a += b;
  a.print(); 
}
