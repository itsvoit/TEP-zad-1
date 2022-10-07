//
// Created by voit on 05.10.2022.
//

#ifndef TEP_LISTA1_CLION_CTABLE_H
#define TEP_LISTA1_CLION_CTABLE_H

#include <string>

class CTable{
	std::string s_name;
	int *tab;
	int tab_len;

	void init(std::string sName, int iTableLen);

public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable &pcOther);

	~CTable();

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

};

#endif //TEP_LISTA1_CLION_CTABLE_H

