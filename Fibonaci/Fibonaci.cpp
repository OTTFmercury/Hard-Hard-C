

#include <iostream>

using namespace std;

template <int N>
struct fibo {
	static constexpr unsigned long long value = fibo<N - 1>::value + fibo<N - 2>::value;
};

template <>
struct fibo<1> {
	static constexpr unsigned long long value = 1;
};

template <>
struct fibo<2> {
	static constexpr unsigned long long value = 1;
};

int main () {
	
	cout << fibo<114>::value << endl;

	return 0;
}