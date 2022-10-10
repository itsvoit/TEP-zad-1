//
// Created by voit on 05.10.2022.
//

#include <iostream>
#include <cmath>
#include <string>
#include "CTable.h"
#include "constants.h"

void CTable::vSetName(std::string sName){
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen){
	if (iTableLen <= 0) return false;

	i_tab_len = iTableLen;
	int *pi_temp_tab = new int [i_tab_len];

	// We don't care about memory out of range
	// user has to manage it themselves
	for (int i = 0; i < std::min(i_tab_len, iTableLen); ++i) {
		pi_temp_tab[i] = pi_tab[i];
	}

	delete [] pi_tab;
	pi_tab = new int [i_tab_len];

	return true;
}

void CTable::vInitTable(){
	if (i_tab_len <= 0) {
		std::cout << "Table length has to be positive, couldn't initialize table...\n";
		return;
	}

	pi_tab = new int [i_tab_len];
}

CTable* CTable::pcClone(){
	CTable *newTable = new CTable(*this);

	return newTable;
}

void CTable::vPrint() {
	std::cout << "(" << s_name << ", " << i_tab_len << ")" << std::endl;
}

CTable::CTable() :
		s_name(S_CTABLE_DEFAULT_NAME),
		i_tab_len(I_CTABLE_DEFAULT_SIZE){
	vInitTable();

	std::cout << S_CTABLE_NO_PARAM_CONSTRUCTOR << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) :
		s_name(sName),
		i_tab_len(iTableLen){
	vInitTable();

	std::cout << S_CTABLE_PARAM_CONSTRUCTOR << s_name << std::endl;
}

CTable::CTable(CTable &pcOther) :
		s_name(pcOther.s_name),
		i_tab_len(pcOther.i_tab_len){
	vInitTable();

	for (int i = 0; i < i_tab_len; ++i) {
		pi_tab[i] = pcOther.pi_tab[i];
	}

	std::cout << S_CTABLE_COPY_CONSTRUCTOR << s_name << std::endl;
}

CTable::~CTable(){
	std::cout << S_CTABLE_DESTRUCTOR << s_name << std::endl;
	delete [] pi_tab;
}

