//
// Created by voit on 05.10.2022.
//

#include <iostream>
#include "CTable.h"
#include "constants.h"
#include "helper.h"

void CTable::vSetName(std::string sName){
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen){
	if (!is_positive(iTableLen)) return false;
	tab_len = iTableLen;

	if (tab != NULL)
		delete [] tab;
	tab = new int [tab_len];

	return true;
}

void CTable::init(std::string sName, int iTableLen){
	vSetName(sName);
	bSetNewSize(iTableLen);
}

CTable* CTable::pcClone(){
	CTable *newTable = new CTable(*this);

	return newTable;
}

CTable::CTable() {
	init(CTABLE_DEFAULT_NAME, CTABLE_DEFAULT_SIZE);
	std::cout << "bezp: " << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen){
	init(sName, iTableLen);
	std::cout << "parametr: " << s_name << std::endl;
}

CTable::CTable(CTable &pcOther){
	tab = NULL;
	init(pcOther.s_name + "_copy", pcOther.tab_len);
	for (int i = 0; i < tab_len; ++i) {
		tab[i] = pcOther.tab[i];
	}
	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable(){
	std::cout << "usuwam: " << s_name << std::endl;
	delete [] tab;
}

