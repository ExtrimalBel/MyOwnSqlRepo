#include "stdafx.h"
#include "TableDefenition.h"


namespace BaseLogicDef
{

	TableDefenition::TableDefenition(vector<BasicTypes::Type> &TypesOfColumns, vector<string> &NamesOfColumns)
	{
		if ((this->CountOfColumns = TypesOfColumns.size()) != NamesOfColumns.size()) throw Exceptions::TableCreateError("Internal Count of types and their names must match");
		
		this->TypesOfColumns.resize(CountOfColumns);
		copy(TypesOfColumns.begin(), TypesOfColumns.end(), this->TypesOfColumns.begin());
		this->NamesOfColumns.resize(CountOfColumns);
		copy(NamesOfColumns.begin(), NamesOfColumns.end(), NamesOfColumns.begin());
	}


	TableDefenition::~TableDefenition()
	{
	}

	void TableDefenition::DumpTable()
	{

	}
}