//
// Created by voit on 05.10.2022.
//

#ifndef TEP_LISTA1_CTABLE_H
#define TEP_LISTA1_CTABLE_H

#include <string>

const int I_CTABLE_DEFAULT_SIZE = 10;
const std::string S_CTABLE_NO_PARAM_CONSTRUCTOR = "bezp: ";
const std::string S_CTABLE_DEFAULT_NAME = "Unnamed";
const std::string S_CTABLE_PARAM_CONSTRUCTOR = "parametr: ";
const std::string S_CTABLE_COPY_CONSTRUCTOR = "kopiuj: ";
const std::string S_CTABLE_DESTRUCTOR = "usuwam: ";

class CTable{
	std::string s_name;
	int *pi_tab;
	int i_tab_len;

	void vInitTable();
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable &pcOther);

	~CTable();

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	void vPrint();
};

#endif //TEP_LISTA1_CTABLE_H

