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

    Computer computer1;
    computer1.setComputerProducer("Apple");
    computer1.setCpuProducer("Intel");
    computer1.setGpuProducer("NVIDIA");
    computer1.setComputerPrice("1249");
    cout << computer1.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    Computer computer2;
    computer2.setComputerProducer("Lenovo");
    computer2.setCpuProducer("AMD");
    computer2.setGpuProducer("Gigabyte");
    computer2.setComputerPrice("1999");
    cout << computer2.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    Computer computer3;
    computer3.setComputerProducer("Lenovo");
    computer3.setCpuProducer("IBM");
    computer3.setGpuProducer("EVGA");
    computer3.setComputerPrice("899");
    cout << computer3.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    Computer computer4;
    computer4.setComputerProducer("MSI");
    computer4.setCpuProducer("Intel");
    computer4.setGpuProducer("NVIDIA");
    computer4.setComputerPrice("1799");
    cout << computer4.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;

    Computer computer5;
    computer5.setComputerProducer("HP");
    computer5.setCpuProducer("Qualcomm");
    computer5.setGpuProducer("InsaneGPU"); // mistake for exception to check
    computer5.setComputerPrice("1100");
    cout << computer5.computerToString() << endl;
    cout << "Computers made: " << Computer::computersCounter << endl;
    }

    catch(invalid_argument& err){
        cout << "\nError! Exception occurred: " << err.what() << endl;
    }

    catch(...){
        cout << "\nError! Unknown exception occurred!" << endl;
    }

      return 0;
}

