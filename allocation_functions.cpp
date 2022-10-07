//
// Created by voit on 07.10.2022.
//

#include "allocation_functions.h"
#include "helper.h"
#include "constants.h"
#include <iostream>

void v_alloc_table_fill_34(int size){
	if (!is_positive(size)) return;

	int* tab = new int [size];
	for (int i = 0; i < size; ++i) {
		tab[i] = ALLOC_TABLE_32;
	}

	for (int i = 0; i < size; ++i) {
		std::cout << tab[i] << " ";
	}

	std::cout << std::endl;
	delete [] tab;
}

bool b_alloc_table_2_dim(int ***piTableCopy, int iSizeX, int iSizeY){
	if (!is_positive(iSizeX) || !is_positive(iSizeY)) return false;

	*piTableCopy = new int* [iSizeY];

	for (int i = 0; i < iSizeY; ++i) {
		(*piTableCopy)[i] = new int [iSizeX];
	}

#ifdef DEBUG
	int cnt = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			(*piTableCopy)[i][j] = i * 10 + j;
			cnt++;
			std::cout << (*piTableCopy)[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << cnt << std::endl;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			std::cout << (*piTableCopy)[i][j] << " ";
		}
		std::cout << std::endl;
	}

#endif //DEBUG
	return true;
}

// Mozna pominac drugi parametr, bo nie jest uzywany przy dealokacji
bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY){
	if (!is_positive(iSizeX) || !is_positive(iSizeY)) return false;

	for (int i = 0; i < iSizeY; ++i) {
		delete [] piTable[i];
	}

	delete [] piTable;

	return true;
}