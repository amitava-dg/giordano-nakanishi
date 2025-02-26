//Exercise 1.1
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX =100;
int n;
double N[MAX]; //stores population
double t[MAX]; //stores time values
double a;//birth parameter
double b;//death parameter
const double t_max=10.0; //ending time
double dt; //time step 

void initialize(double N[], double t[], double& a , double& b, double& dt, const double t_max, int& n);
void calculate(double N[], double t[], double a , double b, double& dt, const double t_max, int n);
void store(double N[], double t[], int n);

int main(){
    initialize(N,t,a,b,dt,t_max,n);
    calculate(N,t,a,b,dt,t_max,n);
    store(N,t,n);
}

//variable initialization
void initialize(double N[], double t[] , double& a, double& b, double& dt, const double t_max, int& n){
    cout << "initial population= ";
    cin >> N[0];
    cout << "birth parameter= ";
    cin >> a;
    cout << "death parameter= ";
    cin >> b;
    cout << "time step= "; 
    cin >> dt;
    t[0] = 0.0;
    n = min(int(t_max/dt)+1,MAX);
}

//result calculation
void calculate(double N[], double t[], double a, double b, double& dt, const double t_max, int n){
    int i;
    for(i=0;i<n-1;i++){
        N[i+1] = N[i] + (a * N[i] - b * N[i] * N[i]) * dt;
        t[i+1] = t[i] + dt;
    }
}

//result saving
void store(double N[], double t[], int n){
    ofstream fp_out ("data6.dat");
    int i;
    for(i=0;i<n;i++){
        fp_out << fixed << t[i] << "\t" << N[i] << "\n";
    }
    fp_out.close();
}
