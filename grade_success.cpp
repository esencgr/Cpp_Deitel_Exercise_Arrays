#include <iostream>
#define STUDENT 3
#define EXAM 4
using namespace std;

void print_array (const int [][EXAM], int,int);
int maximum (const int [][EXAM], int, int);
int minimum (const int [][EXAM], int, int);
double avarage (const int [], int);

int main(){
    int grade_notes [STUDENT][EXAM] = {{90,87,65,45},
		                                  {77,78,23,45},
			                                {34,56,78,90}};

    cout << "list of students notes :" << endl << endl;
    print_array (grade_notes, STUDENT, EXAM);

    cout << " highest note : " << maximum (grade_notes, STUDENT, EXAM) << endl;
    cout << " lowest note : " << minimum (grade_notes, STUDENT, EXAM) << endl;

       for (int i=0;  i<=STUDENT-1;  i++){
	         cout << " Student " << i << "avarage of all notes : "
                << avarage (grade_notes[i], EXAM) << endl;
       }

return 0;
}
void print_array(const int notes[][EXAM], int person, int test){
    for (int i=0;  i<=person-1;  i++){
	      cout << " Student "<< i << " : ";
	  for (int j=0;  j<=test-1;  j++)
        cout <<  notes[i][j]  << " ";
    cout << endl;
    }
 cout << endl;
}

int maximum (const int a[][EXAM], int person , int test){
    int max=0;
    for (int i=0;  i<=person-1;  i++){
        for (int j=0;  j<=test-1;  j++){
	          if ( a[i][j] > max )
	              max = a[i][j];
        }
    }
 return max;
}
int minimum (const int a[][EXAM], int person , int test){
    int min=100;
    for (int i=0;  i<=person-1;  i++){
      	for (int j=0;  j<=test-1;  j++){
	          if ( a[i][j] < min )
               min = a[i][j];
	}
    }
 return min;
}

double avarage (const int n[], int test){
    double total = 0.0;
    for(int k=0;  k<=test-1; k++){
        total += n[k];
    }
 return double( total / test );
}
