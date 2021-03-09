#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <exception>
#include <stdexcept>

#include "computer.hpp"
#include "computer.cpp"

using namespace std;
using namespace PC;


int main(){
    try{

    Computer computer1("Apple", "Intel", "NVIDIA", 1590);
    cout << computer1.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    Computer computer2("Lenovo", "AMD", "Gigabyte", 1999);
    cout << computer2.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    cout << "\n\n";

    cout << (computer1 == computer2) << endl;
    cout << (computer1 != computer2) << endl;
    cout << (computer1 > computer2) << endl;
    cout << (computer1 < computer2) << endl;
    cout << (computer1 >= computer2) << endl;
    cout << (computer1 <= computer2) << endl;
    cout << (computer1 <= computer2) << endl;
    cout << (computer1++ >= computer2) << endl;
    cout << (computer1 < computer2--) << endl;
    }

    catch(invalid_argument& err){
        cout << "\nError! Exception occurred: " << err.what() << endl;
    }

    catch(...){
        cout << "\nError! Unknown exception occurred!" << endl;
    }

      return 0;
}

