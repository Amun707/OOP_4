#include <iostream>
#include <string>

//конструкторы копирования
//операторы класса


class Integer {
public:
	Integer() :data_(0) {}
	Integer(int num) :data_(num) {}

	//пере8грузка оператора как дружественной функции
	friend Integer operator + (Integer A, Integer B) {    //перегружаем + оператора Integer
		Integer result;
		result.data_ = A.data_ + B.data_;
		return result;
	}

	friend std::ostream& operator<<(std::ostream& out, const Integer& obj);  //std::ostream& - ссылка на объект ostream

	int GetNum() {
		return data_;
	}

	//оператор перегружен как метод класса
	Integer& operator=(const Integer& other) {
		this->data_ = other.data_;
		return *this;
	}

private:
	int data_;//первый вариант

	//===========================
	// второй вариант
	// такая реализация нужна для математически достоверных целых чисел
	//bool sign_;              
	//unsigned long long units_;
};

std::ostream& operator<<(std::ostream& out, const Integer& obj) {
	return out << obj.data_;
}

//перегрузка оператора как независимой функции
Integer operator-(Integer a, Integer b) {
	return a.GetNum() - b.GetNum();
}

Integer operator*(Integer a, Integer b) {
	return a.GetNum() * b.GetNum();
}


int main() {
	system("chcp 1251>nul");
	int n;

	Integer a{ 5 };
	Integer b{ 8 };

	//std::cout << 'q' << 3 << "qwerty" << 5 + 9 << '\n';

	

	std::cout << a + b << '\n';
	std::cout << a - b << '\n';
	std::cout << a * b << '\n';
	//============================
	std::cout << a + 5 << '\n';
	std::cout << a - 5 << '\n';
	std::cout << a * 3 << '\n';
	//============================
	std::cout << 4 + b << '\n';
	std::cout << 7 - b << '\n';
	std::cout << 1 * b << '\n';

	Integer c;
	c = a + b;
	




	return 0;
}

/*
правила работы операторов 
1. перегрузка - операторы можно перегружать только для классов. Для встроенных типов данных операторы перегружать нельзя.
2. оператор нельзя перегружать изменяя его поведение (плюс остается плюсом).
3. Ряд операторов запрещено перегружать впринципе: .,  ?: , & - унарный, new, delete[], ::, ->
*/