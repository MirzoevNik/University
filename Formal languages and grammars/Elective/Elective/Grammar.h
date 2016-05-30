#pragma once

#include "Production.h"
#include <set>
#include <vector>
#include <fstream>

class Grammar
{
private:
	set< string > non_terminals;
	set< string > terminals;
	set< Production* > productions;
	string start_symbol;

	string checkAndReplace( string line, string old_symbol, string new_symbol );

public:
	Grammar(void);
	~Grammar(void);

	void addNonTerminal( string non_terminal );
	void addTerminal( string terminal );
	void addProduction( string left_part, string right_part );
	void setStartSymbol( string start_symbol );

	set< string > getNonTerminals();
	set< string > getTerminals();
	set< Production* > getProductions();
	string getStartSymbol();

	int getCountTerminals();

	void printGrammar( const char *file_name );
	void readGrammar( const char *file_name );

	void replaceTerminalAtNonTerminal( string term, string non_term );
	void replaceNonTerminalAtNonTerminal( string old_term, string new_term );

	string checkAndGenerateNewSymbol( string new_symbol, char pair_element1, char pair_element2 );

};

