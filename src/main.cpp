

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

template <typename T>
struct ptr_less
{
	bool operator() ( const T* a, const T* b )
	{
		return std::less<T>()( *a, *b );
	}
};

std::vector<int> v;
std::vector<int*> p;

void initialize()
{
	v.push_back( 3 );
	v.push_back( 2 );
	v.push_back( 8 );
	v.push_back( 4 );
	v.push_back( 3 );
	v.push_back( 9 );

	for( std::vector<int>::iterator it = v.begin(); it!=v.end(); ++it )
	{
		p.push_back( &*it );
	}
}

void sortAndPrint()
{
	std::sort( p.begin(), p.end(), ptr_less<int>() );

	for( std::vector<int*>::iterator it = p.begin(); it!=p.end(); ++it )
	{
		std::cout << **it << " ";
	}
	std::cout << std::endl;
}
/*
int main()
{
	initialize();
	sortAndPrint();

	return 0;
}
*/
