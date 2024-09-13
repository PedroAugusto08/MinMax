#include "MinMax.hpp" 


vector<int> GerarVetor(int n) {
    srand(time(nullptr));
    vector<int> Vetor(n);
    for (int i = 0; i < n; ++i) {
        Vetor[i] = rand() % 1001;
        cout << Vetor[i] << " ";
    }
    return Vetor;
}

void organizarCrescente(vector<int> vec) {
    sort(vec.begin(), vec.end());
}

void organizarDecrescente(vector<int> vec){
    sort(vec.begin(), vec.end(), greater<int>());
}

void printarVetor(const vector<int> vec){
    cout << endl << endl;
    int n = vec.size();
    for(int i=0; i<n;i++){
        cout << vec[i] << " ";
    }
    cout << endl << endl;
}

void registrarVetor(const vector<int> vec, const string nomeArquivo){
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return;
    } else { 
        double tempo_execucao1;
        double tempo_execucao2;
        double tempo_execucao3;
        organizarCrescente(vec);
        for(int a=0;a<3;a++){
            if(a==0){   
                arquivo << endl << "Vetor em ordem aleatória" << endl;
            } else if (a==1){
                organizarCrescente(vec);
                arquivo << endl << "Vetor na ordem crescente" << endl;
            } else if(a==2){
                organizarDecrescente(vec);
                arquivo << endl << "Vetor na ordem decrescente" << endl;
            }
            tempo_execucao1 = Media(vec,1);
            tempo_execucao2 = Media(vec,2);
            tempo_execucao3 = Media(vec,3);
            arquivo << "Tempo de médio de execução MINMAX[1] : " << tempo_execucao1 << endl; 
            arquivo << "Tempo de médio de execução MINMAX[2] : " << tempo_execucao2 << endl; 
            arquivo << "Tempo de médio de execução MINMAX[3] : " << tempo_execucao3 << endl;
        }
        arquivo << endl;
        arquivo.close();
        cout << "O Vetor e o Tempo de execução foram registrados com sucesso no arquivo." << endl;
    }
}

double MinMax1(const vector<int> vec){
    clock_t inicio = clock();
    int n = vec.size();
    int Max=vec[0], Min=vec[0];
    for(int i=0; i<n;i++){
        if(vec[i]>=Max)
            Max = vec[i];
        if(vec[i]<=Min)
            Min = vec[i];
    }
    clock_t fim = clock();
    cout << endl << endl << "Max:" << Max << " Min:" << Min << endl << endl;
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo: " << tempo_execucao << " segundos." << endl;
    return tempo_execucao;
}

double MinMax2(const vector<int> vec){
    clock_t inicio = clock();
    int n = vec.size();
    int Max=vec[0], Min=vec[0];
    for(int i=0; i<n;i++){
        if(vec[i]>=Max)
            Max = vec[i];
        else if(vec[i]<=Min)
            Min = vec[i];
    }
    clock_t fim = clock();
    cout << endl << endl << "Max:" << Max << " Min:" << Min << endl << endl;
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo: " << tempo_execucao << " segundos." << endl;
    return tempo_execucao;
}

double MinMax3(const vector<int> vec){
    clock_t inicio = clock();
    int n = vec.size();
    int Max,Min;
    if(vec[0]>vec[1]){
        Max = vec[0];
        Min = vec[1];
    } else {
        Max = vec[1];
        Min = vec[0];
    }
    for(int i=0; i<n;i+=2){
        if(vec[i]>=vec[i+1]){
            if(vec[i]>=Max)
                Max = vec[i];
            if(vec[i+1]<=Min)
                Min = vec[i+1];
        }
        else{
            if(vec[i+1]>=Max)
                Max = vec[i+1];
            if(vec[i]<=Min)
                Min = vec[i];
        }
    }
    clock_t fim = clock();
    cout << endl << endl << "Max:" << Max << " Min:" << Min << endl << endl;
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo: " << tempo_execucao << " segundos." << endl;
    return tempo_execucao;
}

double Media(const vector<int> vec,int opcao) {
    double media=0;
    for(int j=0;j<10;j++){
        if(opcao==1){
            media+=MinMax1(vec);
        } else if(opcao==2){
            media+=MinMax2(vec);
        } else if(opcao==3){
            media+=MinMax3(vec);
        }
    }
    media/=10;
    return media;
}