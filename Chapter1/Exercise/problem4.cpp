//section 1 : radioactive decay
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX = 100;
int  n; 
double nuclei_A[MAX]; //initial number of A nuclei
double nuclei_B[MAX]; //initial number of B nuclei
double t[MAX]; //store time values
double dt; //time step
double tau_A; //decay time constant of A
double tau_B; //decay time constant of B
double t_max; //time to end simulation

void initialize(double nuclei_A[], double nuclei_B[], double t[] , double& tau_A,double& tau_B, double& dt, double& t_max , int& n);
void calculate(double nuclei_A[], double nuclei_B[], double t[], double& tau_A,double& tau_B, double dt, int n);
void store(double nuclei_A[], double nuclei_B[], double t[], int n);

int main(){
    initialize(nuclei_A,nuclei_B,t,tau_A, tau_B, dt, t_max, n);
    calculate(nuclei_A,nuclei_B,t,tau_A, tau_B,dt,n);
    store(nuclei_A, nuclei_B,t, n);
}

//variable initialization
void initialize(double nuclei_A[],double nuclei_B[], double t[] , double& tau_A, double& tau_B, double& dt, double& t_max, int& n){
    cout << "initial number of nuclei A= ";
    cin >> nuclei_A[0];
    cout << "initial number of nuclei B= ";
    cin >> nuclei_B[0];
    cout << "time constant A= " ;
    cin >> tau_A;
    cout << "time constant B= " ;
    cin >> tau_B;
    cout << "time step= "; 
    cin >> dt;
    t[0] = 0.0;
    cout << "total time= ";
    cin >> t_max;
    n = min(int(t_max/dt)+1,MAX);
}

//result calculation
void calculate(double nuclei_A[], double nuclei_B[], double t[], double& tau_A,double& tau_B, double dt, int n){
    int i;
    for(i=0;i<n-1;i++){
        nuclei_A[i+1] = nuclei_A[i] - ( nuclei_A[i] / tau_A) * dt;
        nuclei_B[i+1] = nuclei_B[i] + ( nuclei_A[i] / tau_A - nuclei_B[i]/tau_B) * dt;
        t[i+1] = t[i] + dt;
    }
}

//result saving
void store(double nuclei_A[], double nuclei_B[], double t[], int n){
    ofstream fp_out ("data4.dat");
    int i;
    for(i=0;i<n;i++){
        fp_out << fixed << t[i] << "\t" << nuclei_A[i] << "\t" << nuclei_B[i] << "\n";
    }
    fp_out.close();
}