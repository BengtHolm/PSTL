#include "counted_ptr.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "Viechle.h"

using namespace std;

namespace
{
	typedef CountedPtr<Viechle> aCountPtr;

	void printCountedPtr( aCountPtr elem )
	{
		elem->printSpecifications();
		elem->makeEngineSound();
		std::cout << std::endl;
	}
}


int main()
{
	vector<aCountPtr> v;
	{
		list<aCountPtr> l;
		{
			aCountPtr ptr( new VolvoFH16() );
			v.push_back( ptr );
			l.push_front( ptr );
		}
		{
			aCountPtr ptr( new AudiA6 );
			v.push_back( ptr );
			l.push_front( ptr );
		}
		{
			aCountPtr ptr( new Skoda() );
			v.push_back( ptr );
			l.push_front( ptr );
		}
		{
			aCountPtr ptr( new AudiA6 );
			v.push_back( ptr );
			l.push_front( ptr );
		}

		cout << "1:" << endl;
		cout << "Vector:" << endl;
		for_each( v.begin(), v.end(), printCountedPtr );
		cout << endl;
		cout << "List:" << endl;
		for_each( l.begin(), l.end(), printCountedPtr );
		cout << endl;

		(v[2])->setColor( Viechle::red );

		cout << "2:" << endl;
		cout << "Vector:" << endl;
		for_each( v.begin(), v.end(), printCountedPtr );
		cout << endl;
		cout << "List:" << endl;
		for_each( l.begin(), l.end(), printCountedPtr );
		cout << endl;
	}
	cout << "3:" << endl;
	cout << "Vector:" << endl;
	for_each( v.begin(), v.end(), printCountedPtr );
	cout << endl;
	cout << "List: Er nedlagt" << endl;

	return 0;
}
