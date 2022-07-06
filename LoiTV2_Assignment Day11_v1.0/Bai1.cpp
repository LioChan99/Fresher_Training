#include "Bai1.h"

template <class T, class U>
Pair<T,U>::Pair(T first, U second )
{
    this->first=first;
    this->second=second;
}

template<class T, class U>
U Pair<T,U>::getSecond() const
{
    return this->second;
}

template<class T, class U>
T Pair<T,U>::getFirst() const
{
    return this->first;
}



int main()
{
	Pair<int, double> p1(5, 6.7);
	std::cout << "Pair: " << p1.getFirst() << ' ' << p1.getSecond() << '\n';
 
	const Pair<double, int> p2(2.3, 4);
	std::cout << "Pair: " << p2.getFirst() << ' ' << p2.getSecond() << '\n';
 
	return 0;
}
