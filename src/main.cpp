#include <iostream>
#include "MinMax.hpp"

int main(){
    vector<int> vec = GerarVetor(500000);
    registrarVetor(vec,"dataset/vetores.mps.txt");
    return 0;
}