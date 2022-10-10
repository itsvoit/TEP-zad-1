#include <iostream>
#include "constants.h"
#include "CTable.h"
#include "allocation_functions.h"

//#define DEBUG

void v_test_alloc(){
	// zad 1
	std::cout << "First function: \n";
	v_alloc_table_fill_34(I_CONST_10);

	// zad 2
	int **pi_Table;
	std::cout << "allocate function return: " << std::boolalpha << b_alloc_table_2_dim(&pi_Table, I_CONST_10, I_CONST_10) << std::endl;

#ifdef DEBUG
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << pi_Table[i][j] << " ";
		}
		std::cout << std::endl;
	}
#endif //DEBUG

	// zad 3
	std::cout << "deallocate function return: " << std::boolalpha << b_dealloc_table_2_dim(pi_Table, I_CONST_10, I_CONST_10) << std::endl;
}

// zad 4
void v_test_CTable(){
	std::cout << "Declare static CTable variable with parameters (\"Tablica\", 5)\n";
	CTable table(S_TEST_NAME, I_CONST_5);

	std::cout << "Declare dynamic CTable variable that's a clone of the static var\n";
	CTable *c_new_table = table.pcClone();

	std::cout << "Set name for dynamic var to \"Kopia\"\n";
	c_new_table->vSetName(S_TEST_COPY);

	std::cout << "Allocate dynamically an pc_array sized 10 of CTable objects\n";
	CTable *pc_array = new CTable [I_CONST_10];

	std::cout << "Set new size (15) for dynamic var, return: " << std::boolalpha << c_new_table->bSetNewSize(I_CONST_15) << std::endl;

	std::cout << "Delete dynamic variable\n";
	delete c_new_table;

	std::cout << "Delete the pc_array\n";
	delete [] pc_array;

	std::cout << "Return from test function...\n";
}

void v_mod_tab(CTable *pcTab, int iNewSize){
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize){
	cTab.bSetNewSize(iNewSize);
}

int main() {
	std::cout << "--------------\nStart testing allocation functions...\n";
	v_test_alloc();
	std::cout << "End testing allocation functions...\n--------------\n";

	std::cout << "--------------\nStart testing CTable methods...\n";
	v_test_CTable();
	std::cout << "End testing CTable methods...\n--------------\n";

	std::cout << "--------------\nStart testing mod procedures...\n";
	std::cout << "Initialize 'pi_tab' variable (" << S_TEST_NAME << ", " << I_CONST_10 << ")\n";
	CTable tab(S_TEST_NAME, I_CONST_10);

	std::cout << "'pi_tab' before the call: ";
	tab.vPrint();

	std::cout << "Call void v_mod_tab(CTable cTab, int iNewSize)\n";
	v_mod_tab(tab, I_CONST_5);

	std::cout << "'pi_tab' after the call: ";
	tab.vPrint();

	std::cout << "Call void v_mod_tab(CTable *pcTab, int iNewSize)\n";
	v_mod_tab(&tab, I_CONST_5);

	std::cout << "'pi_tab' after the call: ";
	tab.vPrint();

	std::cout << "End testing mod procedures...\n--------------\n";

	return 0;
}
