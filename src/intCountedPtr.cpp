
#include "counted_ptr.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

namespace
{

	typedef CountedPtr<int> aCountPtr;

	void printCountedPtr( aCountPtr elem )
	{
		cout << *elem << " ";
	}

}

void s_main()
{
	vector<aCountPtr> v1;
	{
		list<aCountPtr> v2;
		for( int i = 0; i < 5; ++i )
		{
			aCountPtr ptr( new aCountPtr::element_type( i ) );
			v1.push_back( ptr );
			v2.push_front( ptr );
		}

		for_each( v1.begin(), v1.end(), printCountedPtr );
		cout << endl;
		for_each( v2.begin(), v2.end(), printCountedPtr );
		cout << endl;

		*v1[ 2 ] = 42;

		for_each( v1.begin(), v1.end(), printCountedPtr );
		cout << endl;
		for_each( v2.begin(), v2.end(), printCountedPtr );
		cout << endl;
	}

	for_each( v1.begin(), v1.end(), printCountedPtr );
	cout << endl;
}
