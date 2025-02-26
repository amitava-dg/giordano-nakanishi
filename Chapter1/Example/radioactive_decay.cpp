//section 1 : radioactive decay
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX = 100;
int  n; 
double n_uranium[MAX]; //initial number of uranium nuclei
double t[MAX]; //store time values
double dt; //time step
double tau; //decay time constant
double t_max; //time to end simulation

void initialize(double nuclei[], double t[] , double& tc, double& dt, double& t_max , int& n);
void calculate(double nuclei[], double t[], double tc, double dt, int n);
void store(double nuclei[], double t[], int n);

int main(){
    initialize(n_uranium,t,tau, dt, t_max, n);
    calculate(n_uranium,t,tau,dt,n);
    store(n_uranium,t, n);
}

//variable initialization
void initialize(double nuclei[], double t[] , double& tc, double& dt, double& t_max, int& n){
    cout << "initial number of nuclei= ";
    cin >> nuclei[0];
    cout << "time constant= " ;
    cin >> tc;
    cout << "time step= "; 
    cin >> dt;
    t[0] = 0.0;
    cout << "total time= ";
    cin >> t_max;
    n = min(int(t_max/dt)+1,MAX);
}

//result calculation
void calculate(double nuclei[], double t[], double tc, double dt, int n){
    int i;
    for(i=0;i<n-1;i++){
        nuclei[i+1] = nuclei[i] - ( nuclei[i] / tc) * dt;
        t[i+1] = t[i] + dt;
    }
}

//result saving
void store(double nuclei[], double t[], int n){
    ofstream fp_out ("decay.dat");
    int i;
    for(i=0;i<n;i++){
        fp_out << fixed << t[i] << "\t" << nuclei[i] << "\n";
    }
    fp_out.close();
}