//
// Created by voit on 05.10.2022.
//

#include <iostream>
#include <cmath>
#include <string>
#include "CTable.h"
#include "constants.h"
#include "helper.h"

void CTable::vSetName(std::string sName){
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen){
	if (iTableLen <= 0) return false;

	tab_len = iTableLen;
	int *temp_tab = new int [tab_len];

	// We don't care about memory out of range
	// user has to manage it themselves
	for (int i = 0; i < std::min(tab_len, iTableLen); ++i) {
		temp_tab[i] = tab[i];
	}

	delete [] tab;
	tab = new int [tab_len];

	return true;
}

void CTable::init_table(){
	if (tab_len <= 0) {
		std::cout << "Table length has to be positive, couldn't initialize table...\n";
		return;
	}

	tab = new int [tab_len];
}

CTable* CTable::pcClone(){
	CTable *newTable = new CTable(*this);

	return newTable;
}

void CTable::print() {
	std::cout << "(" << s_name << ", " << tab_len << ")" << std::endl;
}

CTable::CTable() :
s_name(CTABLE_DEFAULT_NAME),
tab_len(CTABLE_DEFAULT_SIZE){
	init_table();

	std::cout << "bezp: " << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) :
s_name(sName),
tab_len(iTableLen){
	init_table();

	std::cout << "parametr: " << s_name << std::endl;
}

CTable::CTable(CTable &pcOther) :
s_name(pcOther.s_name),
tab_len(pcOther.tab_len){
	init_table();

	for (int i = 0; i < tab_len; ++i) {
		tab[i] = pcOther.tab[i];
	}

	std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::~CTable(){
	std::cout << "usuwam: " << s_name << std::endl;
	delete [] tab;
}

