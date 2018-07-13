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
	cout << setprecision(8) << fixed;
	mat locat(1,3,fill::zeros);
	double theta= ang / 180 * pi;
	//cout<<locat<<endl;
	mat rotate = {	{ cos(theta),	sin(theta),	0 },
			{ -sin(theta),	cos(theta),	0 },
			{ 0,		0,		1 } };
	//cout <<rotate<<endl;
	char c; double x,y,z; //int l=0;
	while (cin>>c>>x>>y>>z){
		//cout<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
		locat(0,0)=x;
		locat(0,1)=y;
		//locat(l,2)=z;
		locat(0,2)=3.4;
		//l++;
		mat result = locat * rotate;
		cout<<" "<<c<<"\t";
		result.raw_print(cout);
	}
	//cout<<locat<<endl;
	//mat result = locat * rotate;
	//cout << setprecision(8) << fixed;
	//cout<<result<<endl;
	//result.raw_print(cout);
	return 0;
}
