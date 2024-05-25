#pragma once
#include <iostream>
#define MAX 10
using namespace std;

class Matriz

{
    private:
        int Matrix[MAX][MAX];
        int fil;
        int col;
    public:
        Matriz();
        ~Matriz();
        void set_fil(int _fil);
        int get_fil();
        void set_col(int _col);
        int get_col();
        void mostrarmat();
        void cargarmat(int MAT[MAX][MAX], int m, int n);
        float promedio(int MAT[MAX][MAX], int m, int n);
        int mayor(int MAT[MAX][MAX], int m, int n);
};
