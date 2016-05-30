#include "stdafx.h"
#include "Production.h"

Production::Production( string left_part, string right_part )
{
	this->left_part = left_part;
	this->right_part = right_part;
}

Production::~Production(void)
{
}

void Production::setLeftPart( string left_part )
{
	this->left_part = left_part;
}
	
void Production::setRightPart( string right_part )
{
	this->right_part = right_part;
}

string Production::getLeftPart()
{
	return this->left_part;
}
	
string Production::getRightPart()
{
	return this->right_part;
}