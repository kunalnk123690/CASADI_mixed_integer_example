#include <iostream>
#include <chrono>
#include "casadi/casadi.hpp"

using namespace std;
using namespace chrono;
using namespace casadi;

int main()
{
    SX x = SX::sym("x",2,1);

    SX A, b;
    A = SX::vertcat({ SX::horzcat({4,2}), SX::horzcat({1,2}), SX::horzcat({1,1}) });
    b = SX::vertcat({15, 8, 5});

    // Cost and Constraints
    SX f = SX::dot( x, SX::vertcat({-3,-2}) );
    SX g = SX::mtimes( A, x ) - b;

    SXDict nlp;
    nlp["f"] = f;
    nlp["g"] = g;
    nlp["x"] = x;

    // Constructing MI-NLP
    std::vector<bool> discrete = {0,1};

    casadi::Dict casadiOptions;
    casadiOptions["discrete"] = discrete;

    Function prob = nlpsol( "F", "bonmin", nlp, casadiOptions );

    map<string, DM> res;
    res = prob( DMDict{ {"lbx",DM({0,0})}, {"ubg", DM({0,0,0})} } );

    cout << "xOpt: " << res.at("x") << "\n";

}