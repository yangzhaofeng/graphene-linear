#include <iostream>
#include <armadillo>
#include <iomanip>

using namespace std;
using namespace arma;

int main(){
	//cout.precision(10);
	mat locat(130,3,fill::zeros);
	//cout<<locat<<endl;
	/*
	 * top-left is 7.3799754, 12.78249235
	 * bottom-right is 14.75995080, 0
	 * bottom-left is 0,0
	 * top-right is 22.13992620, 12.78249235
	 */
	mat move = {	{ 1,	0,	0 },
			{ 0,	1,	0 },
			{ -22.13992620, -12.78249235,	1 } };
	//cout <<rotate<<endl;
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
