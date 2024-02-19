#include <iostream>
#include <cmath>
using namespace std;
/*Miguel Suarez Sosa
Maria Rosario Menacho 
Elias Torrico*/
//funcion de potencia sin pow
float calcularPotencia(float x, int n) 
{
    float resultado = 1;
    for (int i = 0; i < n; ++i) 
    {resultado *= x;}
    return resultado;
}

//Funcion de factorial
int calcularFactorial(int n)
{
    int result=1;
    for (int i=1; i<=n; i++) 
    {result*=i;}
    return result;
}

// Función para calcular el doble factorial de un número
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Función para calcular la serie
double calcularSerie(double x, int n) 
{
    double suma = 0; // Iniciar la suma desde 0
    for (int i = 0; i <= n; i++) 
    {  suma += pow(x, 2 * i) / factorial(2 * i);}
    return suma + 3;
}

int main() 
{
    double x, resultado;
    int n, op;
    cout << "Ingrese el valor de x: ";
    cin >> x;
    cout << "Ingrese el valor de n (número de términos a sumar): ";
    cin >> n;
    do
    {
        cout<<"Ingrese que opcion desea: "<<endl;
        cout<<"1) Potencia  "<<endl;
        cout<<"2) Factorial "<<endl;
        cout<<"3) Serie "<<endl;
        cout<<"0) Salir"<<endl;
        cin>>op;
        switch(op)
        { 
          case 1:resultado = calcularPotencia(x, n);
          cout<<"el resultado es: "<<resultado<<endl;
          break;
          case 2:
          cout<<"el factorial es: "<<calcularFactorial(n)<<endl;
          break;
          case 3:
          cout<<"el resultado de la serie es: "<<calcularSerie(x, n)<<endl;
          break;
          case 0:cout<<"Salir"<<endl;
          break;
          default: cout<<"la opcion es invalida "<<endl;
        }
    }while(op!=0);
    return 0;
}
