#include <iostream>
#include <armadillo>
#include <iomanip>
#include <cstdlib>

using namespace std;
using namespace arma;

int main(int argc, char *argv[]){
	double mx = atoi(argv[1]), my = atoi(argv[2]);
	//cout.precision(10);
	mat locat(130,3,fill::zeros);
	//cout<<locat<<endl;
	/*
	 * top-left is 7.3799754, 12.78249235
	 * bottom-right is 14.75995080, 0
	 * bottom-left is 0,0
	 * top-right is 22.13992620, 12.78249235
	 */
	const double dxx = 14.75995080, dyx = 7.3799754, dyy = 12.78249235;
	mat move = {	{ 1,			0,		0 },
			{ 0,			1,		0 },
			{ mx * dxx + my * dyx,	my * dyy,	1 } };
	//cout <<move<<endl;
	char c; double x,y,z[130]; int l=0;
	while (cin>>c>>x>>y>>z[l]){
		//cout<<c<<" "<<x<<" "<<y<<" "<<z<<endl;
		locat(l,0)=x;
		locat(l,1)=y;
		//locat(l,2)=z[l];
		locat(l,2)=1;
		l++;
	}
	//cout<<locat<<endl;
	mat result = locat * move;
	for (int i=0;i<l;i++){
		result(i,2)=z[i];
	}
	cout << setprecision(8) << fixed;
	//cout<<result<<endl;
	result.raw_print(cout);
	return 0;
}
