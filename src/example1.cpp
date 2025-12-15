#include <iostream>
#include <chrono>
#include <casadi/casadi.hpp>


using namespace std;
using namespace chrono;
using namespace casadi;

int main()
{   
    std::vector<bool> discrete = {0,1};
    Opti opti = Opti();
    MX x = opti.variable();
    MX y = opti.variable();
    
    opti.minimize( -3*x-2*y );
    opti.subject_to( 4*x+2*y <= 15 );
    opti.subject_to( x+2*y <= 8 );
    opti.subject_to( x+y <= 5 );
    opti.subject_to( x >= 0 );
    opti.subject_to( y >= 0 );
    casadi::Dict casadiOptions;
    casadi::Dict ipoptOptions;
    casadiOptions["expand"] = true;
    casadiOptions["discrete"] = discrete;
    ipoptOptions["print_level"] = 1;
    ipoptOptions["linear_solver"] = "mumps";

    opti.solver( "bonmin", casadiOptions, ipoptOptions );

    auto start = high_resolution_clock::now();
    casadi::OptiSol sol = opti.solve();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop-start);

    cout << sol.value(x) << " " << sol.value(y) << endl;
    cout << "Time required for function evaluation (milliseconds): " << duration.count() << endl; 
}