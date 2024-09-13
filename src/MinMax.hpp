#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <vector>
#include <iostream>
#include <fstream> //arquivo
#include <cstdlib> // rand
#include <ctime>  // temporizar
#include <algorithm> // sort
#include <functional> // greater
using namespace std;

vector<int> GerarVetor(int n);
void organizarCrescente(vector<int> vec);
void organizarDecrescente(vector<int> vec);
void printarVetor(const vector<int> vec);
void registrarVetor(const vector<int> vec, const string nomeArquivo);




#endif 
