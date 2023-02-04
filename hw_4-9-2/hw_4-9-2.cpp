#include <iostream>

class Fraction {

private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denumerator) {
		numerator_ = numerator;
		denominator_ = denumerator;
	}

	int GetNum() {
		return numerator_;
	}

	int GetDen() {
		return denominator_;
	}

	Fraction operator + (Fraction other) {
		return Fraction ( (this->numerator_ * other.denominator_) + (other.numerator_ * this->denominator_), (other.denominator_ * this->denominator_));
	}
	Fraction operator - (Fraction other) {
		return Fraction((this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_), (other.denominator_ * this->denominator_));
	}
	Fraction operator * (Fraction other) {
		return Fraction((this->numerator_ * other.numerator_), (other.denominator_ * this->denominator_));
	}
	Fraction operator / (Fraction other) {
		return Fraction((this->numerator_ * other.denominator_), (this->denominator_ * other.numerator_));
	}
	Fraction& operator - () {
		numerator_ = -numerator_;
		return *this;
	}
	Fraction& operator ++ () {
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator ++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	void Print() {
		std::cout << numerator_ << "/" << denominator_ << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int a = 0, a_ = 0, b = 0, b_ = 0;
	
	std::cout << "Введите числитель первой дроби: ";
	std::cin >> a;
	std::cout << "Введите знаменатель первой дроби: ";
	std::cin >> a_;
	std::cout << "Введите числитель второй дроби: ";
	std::cin >> b;
	std::cout << "Введите знаменатель второй дроби: ";
	std::cin >> b_;

	Fraction f1(a, a_);
	Fraction f2(b, b_);
	
	Fraction sum = f1 + f2;
	std::cout << "\n" << f1.GetNum() << "/" << f1.GetDen() << " + " << f2.GetNum() << "/" << f2.GetDen() << " = ";
	sum.Print();
	
	Fraction sub = f1 - f2;
	std::cout << "\n" << f1.GetNum() << "/" << f1.GetDen() << " - " << f2.GetNum() << "/" << f2.GetDen() << " = ";
	sub.Print();
	
	Fraction mult = f1 * f2;
	std::cout << "\n" << f1.GetNum() << "/" << f1.GetDen() << " * " << f2.GetNum() << "/" << f2.GetDen() << " = ";
	mult.Print();

	Fraction div = f1 / f2;
	std::cout << "\n" << f1.GetNum() << "/" << f1.GetDen() << " / " << f2.GetNum() << "/" << f2.GetDen() << " = ";
	div.Print();

	Fraction pre_incr = ++f1;
	std::cout << "\n++" << f1.GetNum() << "/" << f1.GetDen() << " = ";
	pre_incr.Print();

	Fraction post_incr = f1++;
	std::cout << "\n" << f1.GetNum() << "/" << f1.GetDen()<< "++" << " = ";
	post_incr.Print();
	
	Fraction sign_change = -f1;
	std::cout << "\n" << "Изменение знака f1 и результат пост-инкремента: ";
	sign_change.Print();

}
