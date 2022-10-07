#include <iostream>
#include "constants.h"
#include "CTable.h"
#include "helper.h"
#include "allocation_functions.h"

//#define DEBUG

void v_mod_tab(CTable *pcTab, int iNewSize){
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize){
	cTab.bSetNewSize(iNewSize);
}

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
	std::cout << "Declaring static CTable variable with parameters (\"Tablica\", 5)\n";
	CTable table("tablica", CONST_5);

	std::cout << "Declaring dynamic CTable variable\n";
	CTable *newTable = table.pcClone();

	std::cout << "Set name for dynamic var to \"Kopia\"\n";
	newTable->vSetName("Kopia");

	std::cout << "Set new size (15) for dynamic var, return: " << std::boolalpha << newTable->bSetNewSize(CONST_15) << std::endl;

	std::cout << "Deleting dynamic variable\n";
	delete newTable;

	std::cout << "Return from test function...\n";
}

int main() {
	std::cout << "Start testing allocation functions...\n";
	test_alloc();
	std::cout << "End testing allocation functions...\n";

	std::cout << "Start testing CTable methods...\n";
	test_CTable();
	std::cout << "End testing CTable methods...\n";

	return 0;
}
