#include <iostream>
#include "constants.h"
#include "CTable.h"
#include "helper.h"
#include "allocation_functions.h"

//#define DEBUG

void test_alloc(){
	// zad 1
	std::cout << "First function: \n";
	v_alloc_table_fill_34(CONST_10);

	// zad 2
	int **piTable;
	std::cout << "allocate function return: " << std::boolalpha << b_alloc_table_2_dim(&piTable, CONST_10, CONST_10) << std::endl;

#ifdef DEBUG
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << piTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
#endif //DEBUG

	// zad 3
	std::cout << "deallocate function return: " << std::boolalpha << b_dealloc_table_2_dim(piTable, CONST_10, CONST_10) << std::endl;
}

// zad 4
void test_CTable(){
	std::cout << "Declare static CTable variable with parameters (\"Tablica\", 5)\n";
	CTable table(TEST_NAME, CONST_5);

	std::cout << "Declare dynamic CTable variable that's a clone of the static var\n";
	CTable *newTable = table.pcClone();

	std::cout << "Set name for dynamic var to \"Kopia\"\n";
	newTable->vSetName(TEST_KOPIA);

	std::cout << "Allocate dynamically an array sized 10 of CTable objects\n";
	CTable *array = new CTable [CONST_10];

	std::cout << "Set new size (15) for dynamic var, return: " << std::boolalpha << newTable->bSetNewSize(CONST_15) << std::endl;

	std::cout << "Delete dynamic variable\n";
	delete newTable;

	std::cout << "Delete the array\n";
	delete [] array;

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
	test_alloc();
	std::cout << "End testing allocation functions...\n--------------\n";

	std::cout << "--------------\nStart testing CTable methods...\n";
	test_CTable();
	std::cout << "End testing CTable methods...\n--------------\n";

	std::cout << "--------------\nStart testing mod procedures...\n";
	std::cout << "Initialize 'tab' variable (" << TEST_NAME << ", " << CONST_10 << ")\n";
	CTable tab(TEST_NAME, CONST_10);
	std::cout << "'tab' before the call: ";
	tab.print();
	std::cout << "Call void v_mod_tab(CTable cTab, int iNewSize)\n";
	v_mod_tab(tab, CONST_5);
	std::cout << "'tab' after the call: ";
	tab.print();
	std::cout << "Call void v_mod_tab(CTable *pcTab, int iNewSize)\n";
	v_mod_tab(&tab, CONST_5);
	std::cout << "'tab' after the call: ";
	tab.print();
	std::cout << "End testing mod procedures...\n--------------\n";

	return 0;
}
