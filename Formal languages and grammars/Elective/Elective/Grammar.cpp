#include "stdafx.h"
#include "Grammar.h"

Grammar::Grammar(void)
{
}

Grammar::~Grammar(void)
{
}

void Grammar::addNonTerminal( string non_terminal )
{
	this->non_terminals.insert( non_terminal );
}
	
void Grammar::addTerminal( string terminal )
{
	this->terminals.insert( terminal );
}
	
void Grammar::addProduction( string left_part, string right_part )
{
	Production *new_production = new Production( left_part, right_part );
	this->productions.insert( new_production );
}
	
void Grammar::setStartSymbol( string start_symbol )
{
	this->start_symbol = start_symbol;
}

set< string > Grammar::getNonTerminals()
{
	return this->non_terminals;
}
	
set< string > Grammar::getTerminals()
{
	return this->terminals;
}

set< Production* > Grammar::getProductions()
{
	return this->productions;
}
	
string Grammar::getStartSymbol()
{
	return this->start_symbol;
}

int Grammar::getCountTerminals()
{
	return this->terminals.size();
}

void Grammar::printGrammar( const char *file_name )
{
	ofstream out( file_name );

	out << this->non_terminals.size() << endl; 
	if ( this->non_terminals.size() )
	{
		for ( set< string > :: iterator it = this->non_terminals.begin(); it != this->non_terminals.end(); it++ )
		{
			out << *it << endl;
		}
	}

	out << this->terminals.size() << endl; 
	if ( this->terminals.size() )
	{
		for ( set< string > :: iterator it = this->terminals.begin(); it != this->terminals.end(); it++ )
		{
			out << *it << endl;
		}
	}

	out << this->productions.size() << endl; 
	if ( this->productions.size() )
	{
		for ( set< Production* > :: iterator it = this->productions.begin(); it != this->productions.end(); it++ )
		{
			out << (*it)->getLeftPart() << " " << (*it)->getRightPart() << endl;
		}
	}

	out << this->start_symbol << endl;

	out.close();
}

void Grammar::readGrammar( const char *file_name )
{
	ifstream in( file_name );

	int count;
	in >> count;
	in.get();
	for ( int i = 0; i < count; i++ )
	{
		string non_terminal;
		getline( in, non_terminal );
		this->non_terminals.insert( non_terminal );
	}

	in >> count;
	in.get();
	for ( int i = 0; i < count; i++ )
	{
		string terminal;
		getline( in, terminal );
		this->terminals.insert( terminal );
	}

	in >> count;
	in.get();
	for ( int i = 0; i < count; i++ )
	{
		string production;
		getline( in, production );

		int j = production.find( " " );
		string left_part = production.substr( 0, j );
		string right_part = production.substr( j + 1, production.size() - j + 1 );

		Production *new_production = new Production( left_part, right_part );
		this->productions.insert( new_production );
	}

	in >> this->start_symbol;

	in.close();
}

void Grammar::replaceTerminalAtNonTerminal( string term, string non_term )
{
	if ( this->productions.size() )
	{
		for ( set< Production* > :: iterator it = this->productions.begin(); it != this->productions.end(); it++ )
		{
			string chain = (*it)->getLeftPart();
			(*it)->setLeftPart( checkAndReplace( chain, term, non_term ) );

			chain = (*it)->getRightPart();
			(*it)->setRightPart( checkAndReplace( chain, term, non_term ) );
		}
	}

	non_terminals.insert( non_term );
	terminals.erase( term );
}

void Grammar::replaceNonTerminalAtNonTerminal( string old_term, string new_term )
{
	if ( this->productions.size() )
	{
		for ( set< Production* > :: iterator it = this->productions.begin(); it != this->productions.end(); it++ )
		{
			string chain = (*it)->getLeftPart();
			(*it)->setLeftPart( checkAndReplace( chain, old_term, new_term ) );

			chain = (*it)->getRightPart();
			(*it)->setRightPart( checkAndReplace( chain, old_term, new_term ) );
		}
	}

	non_terminals.erase( old_term );
	non_terminals.insert( new_term );
}

string Grammar::checkAndReplace( string line, string old_symbol, string new_symbol )
{
	int i = 0;
	while ( i < line.size() )
	{
		bool is_find = false;

		for ( set< string > :: iterator it = this->non_terminals.begin(); it != this->non_terminals.end(); it++ )
		{
			int symbol_size = (*it).size();
			string subline = line.substr( i, symbol_size );

			if ( subline == (*it) )
			{
				if ( subline == old_symbol )
				{
					line.replace( i, old_symbol.size(), new_symbol );
					i += new_symbol.size() - 1;
				}
				else 
					i += symbol_size - 1;

				is_find = true;
				break;
			}
		}

		if ( !is_find )
		{
			for ( set< string > :: iterator it = this->terminals.begin(); it != this->terminals.end(); it++ )
			{
				int symbol_size = (*it).size();
				string subline = line.substr( i, symbol_size );

				if ( subline == (*it) )
				{
					if ( subline == old_symbol )
					{
						line.replace( i, old_symbol.size(), new_symbol );
						i += new_symbol.size() - 1;
					}
					else 
						i += symbol_size - 1;
					break;
				}
			}
		}

		i++;
	}

	return line;
}

string Grammar::checkAndGenerateNewSymbol( string new_symbol, char pair_element1, char pair_element2 )
{
	string generated_new_symbol = new_symbol;
	string start_of_line = "";
	while ( true )
	{
		if ( generated_new_symbol.size() == 1 )
		{
			generated_new_symbol = start_of_line + '"' + pair_element1 + generated_new_symbol + pair_element2 + '"';
		}
		else
		{
			char symbol;
			if ( generated_new_symbol[0] == '\'' )
				symbol = '\'';
			else
				symbol = '"';
			generated_new_symbol = generated_new_symbol.substr( 1, generated_new_symbol.size() - 2 );
			generated_new_symbol = start_of_line + symbol + pair_element1 + generated_new_symbol + pair_element2 + symbol;
		}

		bool is_find = false;

		for ( set< string > :: iterator it = this->non_terminals.begin(); it != this->non_terminals.end(); it++ )
		{
			if ( generated_new_symbol == (*it) )
			{
				is_find = true;
				break;
			}
		}
		if ( !is_find )
		{
			for ( set< string > :: iterator it = this->terminals.begin(); it != this->terminals.end(); it++ )
			{
				if ( generated_new_symbol == (*it) )
				{
					is_find = true;
					break;
				}
			}
		}

		if ( !is_find )
			return generated_new_symbol;
	}

	return generated_new_symbol;
}