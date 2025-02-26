//Exercise 1.1
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX =100;
int n;
double x[MAX]; //stores position
double t[MAX]; //stores time values
double v; //velocity 
const double t_max=10.0; //ending time
double dt; //time step 

void initialize(double x[], double t[], double& dt, const double t_max, int& n);
void calculate(double x[], double t[], double v, double dt, const double t_max, int n);
void store(double x[], double t[], int n);

int main(){
    initialize(x,t,dt,t_max,n);
    calculate(x,t,v,dt,t_max,n);
    store(x,t,n);
}

//variable initialization
void initialize(double x[], double t[] , double& dt, const double t_max, int& n){
    cout << "initial position= ";
    cin >> x[0];
    cout << "velocity= ";
    cin >> v;
    cout << "time step= "; 
    cin >> dt;
    t[0] = 0.0;
    n = min(int(t_max/dt)+1,MAX);
}

//result calculation
void calculate(double x[], double t[], double v, double dt, const double t_max, int n){
    int i;
    for(i=0;i<n-1;i++){
        x[i+1] = x[i] + v * dt;
        t[i+1] = t[i] + dt;
    }
}

//result saving
void store(double v[], double t[], int n){
    ofstream fp_out ("data2.dat");
    int i;
    for(i=0;i<n;i++){
        fp_out << fixed << t[i] << "\t" << v[i] << "\n";
    }
    fp_out.close();
}
