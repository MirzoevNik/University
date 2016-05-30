#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector< int > zFunction( string line )
{
	vector< int > zf;
	zf.assign( line.size(), 0 );
	int left = 0;
	int right = 0; 
	for ( int i = 1; i < line.size(); i++ )
	{
		if ( i <= right )
			zf[i] = min( right - i + 1, zf[ i - left ] );
		while ( i + zf[i] < line.size() && line[ zf[i] ] == line[ i + zf[i] ] )
			zf[i]++;
		int temp = i + zf[i] - 1;
		if ( temp > right )
		{
	        left = i;
	        right = temp;
		}
	}
	return zf;
}


int main()
{
	vector< int > z = zFunction("abcabaaabca");
	for ( int i = 0; i < z.size(); i++ )
		cout << z[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}