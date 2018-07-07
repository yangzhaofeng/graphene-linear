#include <iostream>
#include <armadillo>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace arma;

const double pi = 3.14159265359;

int main(int argc, char *argv[]){
	double ang = atof(argv[1]);
	//cout.precision(10);
	mat locat(400,3,fill::zeros);
	double theta= ang / 180 * pi;
	//cout<<locat<<endl;
	mat rotate = {	{ cos(theta),	sin(theta),	0 },
			{ -sin(theta),	cos(theta),	0 },
			{ 0,		0,		1 } };
	//cout <<rotate<<endl;
	char c; double x,y,z; int l=0;
	while (cin>>c>>x>>y>>z){
		//cout<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
		locat(l,0)=x;
		locat(l,1)=y;
		//locat(l,2)=z;
		locat(l,2)=3.4;
		l++;
	}
	//cout<<locat<<endl;
	mat result = locat * rotate;
	cout << setprecision(8) << fixed;
	//cout<<result<<endl;
	result.raw_print(cout);
	return 0;
}
