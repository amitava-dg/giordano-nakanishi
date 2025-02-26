//Exercise 1.1
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX =100;
int n;
double v[MAX]; //stores velocity
double t[MAX]; //stores time values
double a;//applied force parameter
double b;//friction parameter
const double t_max=10.0; //ending time
double dt; //time step 

void initialize(double v[], double t[], double& a , double& b, double& dt, const double t_max, int& n);
void calculate(double v[], double t[], double a , double b, double& dt, const double t_max, int n);
void store(double v[], double t[], int n);

int main(){
    initialize(v,t,a,b,dt,t_max,n);
    calculate(v,t,a,b,dt,t_max,n);
    store(v,t,n);
}

//variable initialization
void initialize(double v[], double t[] , double& a, double& b, double& dt, const double t_max, int& n){
    cout << "initial velocity= ";
    cin >> v[0];
    cout << "parameter a= ";
    cin >> a;
    cout << "parameter b= ";
    cin >> b;
    cout << "time step= "; 
    cin >> dt;
    t[0] = 0.0;
    n = min(int(t_max/dt)+1,MAX);
}

//result calculation
void calculate(double v[], double t[], double a, double b, double& dt, const double t_max, int n){
    int i;
    for(i=0;i<n-1;i++){
        v[i+1] = v[i] + (a - b * v[i]) * dt;
        t[i+1] = t[i] + dt;
    }
}

//result saving
void store(double v[], double t[], int n){
    ofstream fp_out ("data3.dat");
    int i;
    for(i=0;i<n;i++){
        fp_out << fixed << t[i] << "\t" << v[i] << "\n";
    }
    fp_out.close();
}
