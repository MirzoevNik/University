#pragma once

#include <string>

using namespace std;

class Production
{
private:
	string left_part;
	string right_part;

public:
	Production( string left_part, string right_part );
	~Production(void);

	void setLeftPart( string left_part );
	void setRightPart( string right_part );

	string getLeftPart();
	string getRightPart();
};

