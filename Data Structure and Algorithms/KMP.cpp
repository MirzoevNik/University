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

vector< int > KMP( string line, string pattern )
{
	int n = line.size();
	int m = pattern.size();
	vector< int > answer;
	vector< int > p = prefixFunction( pattern + "#" + line );
	int count = 0;
	for ( int i = 0; i < n; i++ )
		if ( p[ m + i + 1 ] == m )
			answer.push_back(i);
	return answer;
}

int main()
{
	vector< int > kmp = KMP("accab", "ab" );
	for ( int i = 0; i < kmp.size(); i++ )
		cout << kmp[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}

