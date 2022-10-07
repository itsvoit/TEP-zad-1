//
// Created by voit on 05.10.2022.
//

#include "helper.h"
#include<iostream>

bool is_positive (int num){
	return num > 0;
}

void print_table(int *tab, int size){
	for (int i=0; i<size; i++){
		std::cout << tab[i] << " ";
	}
}