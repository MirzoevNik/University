#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< int > prefixFunction( string line )
{
	vector< int > p;
	p.assign( line.size(), 0 );
	for ( int i = 1; i < line.size(); i++ )
	{
		int k = p[ i - 1 ];
		while ( k > 0 && line[i] != line[k] )
			k = p[ k - 1 ];
		if ( line[i] == line[k] )
			k++;
		p[i] = k;
	}

	return p;
}

int main()
{
	vector< int > prefix = prefixFunction("abcabaaabca");
	for ( int i = 0; i < prefix.size(); i++ )
		cout << prefix[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}