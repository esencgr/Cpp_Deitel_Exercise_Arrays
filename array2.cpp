#include<iostream>

using namespace std;

int main ()
{
   int a[5];
   for (int i = 0; i <= 4; i++)
   cin>> a[i];

   int eb = a[0];
       for (int i = 0; i <= 4; i++){
	         if (a[i] > eb)
	         eb = a[i];
       }

       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;
       cout<< "en buyuk sayi: " << eb << endl;

   int ek = a[0];
        for (int i = 0; i <= 4; i++){
	         if (a[i] < ek)
	         ek = a[i];
        }

   cout<< "en kucuk sayi: "<< ek <<endl;

    int sum = 0;

        for (int i = 0; i <= 4; i++){
    	    sum += a[i];
	}

    cout<< "dizi elemanlari toplami: "<< sum << endl;
    cout<< "dizi elemanlari ort: " << (float)sum / 5;
    cout<< "dizi elemanlari toplami: "<< sum << endl;
    cout<< "dizi elemanlari ort: " << (float)sum / 5;
    cout<< "dizi elemanlari toplami: "<< sum << endl;

    cout<< "dizi elemanlari ort: " << (float)sum / 5;    
}
