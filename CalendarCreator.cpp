#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int GetYear();
int GetStartingDay();
void PrintHeading(int);
string ReadMonthName();
int ReadNumDays();
int PrintMonth(int, string, int);

ifstream myFile;

int main(){
    int year = GetYear();
    int startDate = GetStartingDay();
    int dayTracker = startDate;

    PrintHeading(year);
    
    string monthName;
    int numOfDays;
    
    myFile.open("infile.txt");
    for (int i=1; i<=12; i++){
        monthName = ReadMonthName();
        numOfDays = ReadNumDays();
        dayTracker = PrintMonth(numOfDays, monthName, dayTracker);
    }
    myFile.close();
    return 0;
}
    
int GetYear(){
    int year;
    cout << "Enter the year: " << endl;
    cin >> year;
    return year;
}

int GetStartingDay(){
    int startDate;
    cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat): ";
    cin >> startDate;
    return startDate;
}

void PrintHeading(int year){
    cout << "\t\t\tYEAR -- " << year << endl;
}

string ReadMonthName(){
    string monthName;
    myFile >> monthName;
    return monthName;
}

int ReadNumDays(){
    int numOfDays;
    myFile >> numOfDays;
    return numOfDays;
}

int PrintMonth(int numOfDays, string monthName, int dayTracker)
{
  cout << endl << endl << "\t\t\t\t" << monthName << endl;
  cout << "Sun:\tMon:\tTue:\tWed:\tThu:\tFri:\tSat:" << endl;
  for (int moreTabs=0; moreTabs < (dayTracker % 7); moreTabs++)
    cout << "\t\t";
  int i = 1;
  while (i <= numOfDays){
    dayTracker++;
    if ((dayTracker % 7) == 0){
      cout << i;
      cout << endl;
    }
    else{
      cout << i;
      cout << "\t\t";
    }
    i++;
  }
  return dayTracker;
}

// * * * O U T P U T   C O M M E N T E D   B E L O W * * *
//Enter the year:
//2010
//Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat): 3
//            YEAR -- 2010
//
//
//                January
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                        1       2       3       4
//5       6       7       8       9       10      11
//12      13      14      15      16      17      18
//19      20      21      22      23      24      25
//26      27      28      29      30      31
//
//                February
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                                                1
//2       3       4       5       6       7       8
//9       10      11      12      13      14      15
//16      17      18      19      20      21      22
//23      24      25      26      27      28
//
//                March
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                                                1
//2       3       4       5       6       7       8
//9       10      11      12      13      14      15
//16      17      18      19      20      21      22
//23      24      25      26      27      28      29
//30      31
//
//                April
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                1       2       3       4       5
//6       7       8       9       10      11      12
//13      14      15      16      17      18      19
//20      21      22      23      24      25      26
//27      28      29      30
//
//                May
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                                1       2       3
//4       5       6       7       8       9       10
//11      12      13      14      15      16      17
//18      19      20      21      22      23      24
//25      26      27      28      29      30      31
//
//
//                June
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//1       2       3       4       5       6       7
//8       9       10      11      12      13      14
//15      16      17      18      19      20      21
//22      23      24      25      26      27      28
//29      30
//
//                July
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                1       2       3       4       5
//6       7       8       9       10      11      12
//13      14      15      16      17      18      19
//20      21      22      23      24      25      26
//27      28      29      30      31
//
//                August
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                                        1       2
//3       4       5       6       7       8       9
//10      11      12      13      14      15      16
//17      18      19      20      21      22      23
//24      25      26      27      28      29      30
//31
//
//                September
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//        1       2       3       4       5       6
//7       8       9       10      11      12      13
//14      15      16      17      18      19      20
//21      22      23      24      25      26      27
//28      29      30
//
//                October
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                        1       2       3       4
//5       6       7       8       9       10      11
//12      13      14      15      16      17      18
//19      20      21      22      23      24      25
//26      27      28      29      30      31
//
//                November
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//                                                1
//2       3       4       5       6       7       8
//9       10      11      12      13      14      15
//16      17      18      19      20      21      22
//23      24      25      26      27      28      29
//30
//
//                December
//Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
//        1       2       3       4       5       6
//7       8       9       10      11      12      13
//14      15      16      17      18      19      20
//21      22      23      24      25      26      27
//28      29      30      31
