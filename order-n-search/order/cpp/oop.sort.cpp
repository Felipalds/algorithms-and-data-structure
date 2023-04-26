#include <iostream>
//#include <cstdlib>
#include <climits>

using namespace std;

class Vetor{
    private:
        int *V;
        int n;

        void swap(int &a, int &b); 
        void realloc();
        void merger(int low, int mid, int high);
        int partition(int low, int high);

    public:
        Vetor();
        Vetor(int tam);
        Vetor(const Vetor &A);
        ~Vetor();

        int len();
        void add(int valor);
        int get(int i);
        void set(int i, int v);
        int operator[](int i) const;
        int &operator[](int i);
        void escreve();

        void BubbleSort();
        void ShakerSort();
        void InsertionSort();
        void SelectionSort();
        void ShellSort();
        void MergeSort();
        void QuickSort();

};

Vetor :: Vetor(){
    
    n =0;
    V = NULL;
    cout<< "Construtor default criado" << endl;
};

Vetor::Vetor(int tam){
    if (tam < 0){
        cerr << "Erro, numero de elementos negatico" << endl;
        n = 0;
        V = NULL;
    }else{
        n = tam;

        V = new int[n];
        if (V == NULL){
            cerr << "Não é possivel criar" << endl;
            exit(1);
        } else{
            for(int i = 0; i<n; i++){
                V[i] = 0;
            }
            cout<< "Construtor inicializado criado" << endl;
        }
    }
};

Vetor :: Vetor(const Vetor &A){
    cout<< "construtor de copia"<<endl;
    this->n = A.n;
    this->V = new int[this->n];
    if(this->V == NULL){
        cerr << "Deu pau" << endl;
        exit(2);
    }

    for(int i=0; i<this->n; i++){
        this->V[i]= A.V[i];
        
    }
    cout<<"copia deu bom"<<endl;
};

Vetor::~Vetor(){
    cout<<"deturindo"<<endl;
    delete[] V;
};

void Vetor::realloc(){
    if (this->n == 0){
        V = new int[++this->n];
        if (V == NULL){
            cerr << "Erro" <<endl;
            exit(3);
        }

    }else{
        int *aux = new int[this->n];
        if (aux == NULL){
            cerr << "Erro" <<endl;
            exit(3);
        }
        for (int i = 0; i< (this-> n)-1; i++){
            V[i] = aux [i];
        }

        V[this->n -1] = 0;
        delete[] aux;
    }
    return;
};

int Vetor::len(){
    return this->n;
}

void Vetor::add(int valor){
    realloc();
    V[n-1] = valor;
    return;
}

int Vetor::get(int i){
    if ((i<0) || (i>=n)){
        cerr<<"erro"<<endl;
        return 0;
    }else{
        return V[i];
    }
}



void Vetor::set(int i, int v){
    if ((i<0) || (i>=n)){
        cerr<<"erro"<<endl;
        return;
    }else{
         V[i] = v;
    }
}


int Vetor::operator[](int i) const{
    if ((i<0) || (i>=n)){
        cerr<<"erro"<<endl;
        return 0;
    }else{
        return V[i];
    }
}

int &Vetor::operator[](int i){
    if ((i<0) || (i>=n)){
        cerr<<"erro"<<endl;
        exit(4);
    }else{
        return V[i];
    }
}
int main(){
    Vetor A;
    Vetor B(10);
    Vetor C = B;

    cout << "A" << A.len() << endl;
    cout << "B" << B.len() << endl;
    cout << "C" << C.len() << endl;

    A.add(7);
    B.add(2);
    C.add(3);

    cout << "A" << A.len() << endl;
    cout << "B" << B.len() << endl;
    cout << "C" << C.len() << endl;    

    A.set(0, 7);
    B.set(0, 2);
    C.set(0, 69);

    cout << "A[]" << A.get(0) << endl;
    cout << "B[]" << B.get(0) << endl;
    cout << "C[]" << C.get(0) << endl;    

}