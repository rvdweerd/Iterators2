#include <iostream>
#include <vector>
#include <forward_list>
#include <iterator>
#include "T15funcs.h"
#include <algorithm>

void T15stuff()
{
	std::vector<int> vi = { 0,    1,    2,    3,    4,     5,    6 };

	std::vector<float> vf = { 0.1f, 1.2f, 2.2f, 3.1f, 44.3f, 5.0f, 6.6f };
	//std::string str = "hello";

	//std::forward_list<int> li = { 1,2,3 };

	printI(vi.data(), vi.data() + vi.size());
	//print(vi.begin(),vi.end());
	//print(vf.begin(),vf.end());
	//print(str.cbegin(),str.cend());

	//print(li.begin(),li.end());
	/*for (auto i = vi.begin(), e = vi.end(); i != e; )
	{
		if (*i % 2 == 0)
		{
			i = vi.erase(i);
		}
		else
		{
			++i;
		}
	}*/
	std::vector<float> vfsum;
	//sum(vi.begin(), vi.end(), vf.begin(), std::ostream_iterator<float>(std::cout, ", "));
	sum(vi.begin(), vi.end(), vf.begin(), std::back_inserter(vfsum));

	printX(vfsum.data(), vfsum.data() + vfsum.size());

	/*
	for ( std::vector<int>::iterator L = vi.begin(); L != vi.end(); ++L)
	{
		std::cout << *L << " ";
	}

	int a[] = { 1,2,3,4,5 };
	printI(std::begin(a), std::end(a));
	*/
}

class Element
{
public:
	Element(int a, int b, int c)
		:
		id(a),
		x(b),
		y(c)
	{}
	void Print() const
	{
		std::cout << "id: " << id << " | x: " << x << " | y: " << y << std::endl;
	}
	int GetY() const
	{
		return y;
	}
	const bool operator<(Element& rhs) const
	{
		return id < rhs.id;
	}
//	const bool operator>(Element& rhs) const
//	{
//		return id > rhs.id;
//	}
	class YLess
	{
	public:
		bool operator()( const Element& lhs, const Element& rhs ) const
		{
			return lhs.y < rhs.y;
		}
	};
	class DescId
	{
	public:
		bool operator()(const Element& lhs, const Element& rhs) const
		{
			return lhs.id > rhs.id;
		}
	};
private:
	int id;
	int x;
	int y;
};


int main()
{
	T15stuff();

	std::vector<Element> elementen = { {1,2,2},{4,2,12},{3,0,1},{0,0,0}, {99,4,11} };
	
	class ThresholdTestY
	{
	public:
		ThresholdTestY(int thresh)
			:
			thresh(thresh)
		{}
		bool operator()(const Element& elem) const
		{
			return elem.GetY() > thresh;
		}
	private:
		int thresh;
	};
	
	for (Element& e  : elementen)
	{
		e.Print();
	}
	std::cout << "-------------------------" << std::endl;
	
	std::sort(elementen.begin(), elementen.end(), Element::YLess{} );
	for (Element& e : elementen)
	{
		e.Print();
	}
	std::cout << "-------------------------" << std::endl;

	std::sort(elementen.begin(), elementen.end()  );
	for (Element& e : elementen)
	{
		e.Print();
	}
	std::cout << "-------------------------" << std::endl;

	std::sort(elementen.begin(), elementen.end(), Element::DescId{});
	for (Element& e : elementen)
	{
		e.Print();
	}
	std::cout << "-------------------------" << std::endl;

	//const auto new_end = std::remove_if(elementen.begin(), elementen.end(), ThresholdTestY(3));
	//USE LAMBDA FUNCTION INSTEAD
	auto mylamb = [](const Element& elem)->bool
	{
		return elem.GetY() > 10;
	};
	auto mylambIter = [](const auto iter)->bool
	{
		return iter->GetY() ==1;
	};
	bool test = mylamb(elementen.front());
	test = mylamb(*(elementen.begin() + 1));
	test = mylambIter(elementen.begin() + 2);


	int thresh = 3;
	const auto new_end = std::remove_if(elementen.begin(), elementen.end(), 
		[thresh]( const Element& elem) 
		{
			return elem.GetY() > thresh;
		}
	);
	elementen.erase(new_end,elementen.end());

	for (Element& e : elementen)
	{
		e.Print();
	}
	std::cout << "-------------------------" << std::endl;

	//std::vector<int> vec{9, 8,1,6,1,4,3,2,1,0};
	//std::sort(vec.begin(), vec.end(), std::greater<int>());



	std::cin.get();
	return 0;
}	