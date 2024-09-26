#include <iostream>
#include <cmath>
using namespace std;

double solve(double a, double c){
 double b = a*a + c*c ;

 return sqrt(b);

}
int main(){
  double a , c;

  cout<<"Enter perpendicular and base respectively :"<<endl;

  cin>>a>>c;

  cout<<"the hypotenus is : "<<solve(a,c)<<endl;

}