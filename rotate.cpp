#include <iostream>
#include <armadillo>
#include <iomanip>

using namespace std;
using namespace arma;

int main(){
	//cout.precision(10);
	mat locat(130,3,fill::zeros);
	//cout<<locat<<endl;
	mat rotate = {	{ 0.92857143,	0.37115374,	0 },
			{ -0.37115374,	0.92857143,	0 },
			{ 0,		0,		1 } };
	//cout <<rotate<<endl;
	char c; double x,y,z; int l=0;
	while (cin>>c>>x>>y>>z){
		//cout<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
		locat(l,0)=x;
		locat(l,1)=y;
		locat(l,2)=z;
		l++;
	}
	//cout<<locat<<endl;
	mat result = locat * rotate;
	cout << setprecision(8) << fixed;
	//cout<<result<<endl;
	result.raw_print(cout);
	return 0;
}
