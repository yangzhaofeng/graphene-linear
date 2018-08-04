#include<iostream>
//#include<vector>
#include<armadillo>
#include<iomanip>

using namespace std;
using namespace arma;

int main(int argc, char *argv[]){
	double xa = atof(argv[1]), ya = atof(argv[2]);
	double xb = atof(argv[3]), yb = atof(argv[4]);
	double xc = atof(argv[5]), yc = atof(argv[6]);
	double xd = atof(argv[7]), yd = atof(argv[8]);
	cout << setprecision(8) << fixed;
	vec ab = zeros<vec>(3), bc = zeros<vec>(3), cd = zeros<vec>(3), da = zeros<vec>(3);
	vec ap = zeros<vec>(3), bp = zeros<vec>(3), cp = zeros<vec>(3), dp = zeros<vec>(3);
	ab(0) = xb - xa; ab(1) = yb - ya;
	bc(0) = xc - xb; bc(1) = yc - yb;
	cd(0) = xd - xc; cd(1) = yd - yc;
	da(0) = xa - xd; da(1) = ya - yd;
	//ab.t().raw_print(cout); bc.t().raw_print(cout); cd.t().raw_print(cout); da.t().raw_print(cout);
	char C; double x,y,z;
	while (cin>>C>>x>>y>>z){
		vec p = zeros<vec>(3);
		p(0) = x; p(1) = y; p(2) = z;
		//p.raw_print(cout);
		ap(0) = x - xa; ap(1) = y - ya;
		bp(0) = x - xb; bp(1) = y - yb;
		cp(0) = x - xc; cp(1) = y - yc;
		dp(0) = x - xd; dp(1) = y - yd;
		//ap.t().raw_print(cout); bp.t().raw_print(cout); cp.t().raw_print(cout); dp.t().raw_print(cout);
		vec _a = cross(ab,ap), _b = cross(bc,bp), _c = cross(cd,cp), _d = cross(da,dp);
		//_a.t().raw_print(cout); _b.t().raw_print(cout); _c.t().raw_print(cout); _d.t().raw_print(cout);
		double a = _a(2), b = _b(2), c = _c(2), d = _d(2);
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		if((a >= -0.001 && b >= -0.001 && c >= -0.001 && d >= -0.001) || (a <= 0.001 && b <= 0.001 && c <= 0.001 && d <= 0.001)){
			cout<<" "<<C<<"\t";
			p.t().raw_print(cout);
		}
	}
	return 0;
}
