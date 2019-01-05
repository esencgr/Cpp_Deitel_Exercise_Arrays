
#include<iostream>
#include<math.h>
using namespace std;
int main(){

float value,sum=0.0,avarage;
int count=0;

	cout << "enter integers (exit 9999):";
	cin >> value ;

	while (value!=9999){
      float value,sum=0.0,avarage;
      int count=0;
	    cout << "enter integers (exit 9999):";
	    cin >> value ;
	         while (value!=9999){
	              sum += value;
	              count++;
	              cout << "enter integers (exit 9999):";
	              cin >> value ;

	          }
  }
avarage = sum/count;
cout<< "avarage:"<< (float)avarage;
}
