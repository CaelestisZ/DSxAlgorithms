#include<iostream>

using namespace std;

class DiagonalMatrix {
    private: 
        int *A;
        int n;
    public: 
        DiagonalMatrix(int n) {
            this->n = n;
            A = new int[n];
        }
        void setData(int i, int j, int key);
        int getData(int i, int j);
        void Display();
        ~DiagonalMatrix();
};

void DiagonalMatrix::setData(int i, int j, int key){
    if (i==j) {
        A[i-1] = key;
    }
}

int DiagonalMatrix::getData(int i, int j) {
    if (i==j) {
        return A[i-1];
    }
    return 0;
}

void DiagonalMatrix::Display() {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (i==j) {
                cout<<A[i]<<" ";
            }
            else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

DiagonalMatrix::~DiagonalMatrix() {
    delete []A;
}

int main() {
    DiagonalMatrix dm(5);

    dm.setData(1, 1, 5);
    dm.setData(2, 2, 6);
    dm.setData(3, 3, 6);
    dm.setData(4, 4, 7);
    dm.setData(5, 5, 8);

    cout<<"Element at position "<< "(1, 1)" << " is " << dm.getData(1, 1) << endl;

    dm.Display();

    return 0;
}