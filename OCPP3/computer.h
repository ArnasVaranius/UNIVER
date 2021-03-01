#ifndef COMPUTER_HPP_INCLUDED
#define COMPUTER_HPP_INCLUDED

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

#define PRODUCERS_COUNT 8
#define CPU_PRODUCERS_COUNT 5
#define GPU_PRODUCERS_COUNT 6

#define DEFAULT_PRODUCER_NAME "UNKNOWN"
#define DEFAULT_CPU_PRODUCER_NAME "UNKNOWN"
#define DEFAULT_GPU_PRODUCER_NAME "UNKNOWN"
#define DEFAULT_COMPUTER_PRICE "UNKNOWN"

using namespace std;

//-----------------------------------------------
namespace PC{
    class Computer{
        private:
            string computerProducer;
            string cpuProducer;
            string gpuProducer;
            string computerPrice;

            static const string mainGpuProducers[GPU_PRODUCERS_COUNT];
            static const string mainCpuProducers[CPU_PRODUCERS_COUNT];
            static const string mainComputerProducers[PRODUCERS_COUNT];

            //  CORRECTION CHECKS

            bool checkProducer(string computerProducer);
            bool checkCpuProducer(string cpuProducer);
            bool checkGpuProducer(string gpuProducer);
            bool checkComputerPrice(string computerPrice);

        public:
            static int computersCounter;

            Computer();
            ~Computer();

            // SETTERS

            void setComputerProducer(string producerName);
            void setCpuProducer(string cpuProducerName);
            void setGpuProducer(string gpuProducerName);
            void setComputerPrice(string priceOfComputer);

            // GETTER

            string getComputerProducer();
            string getCpuProducer();
            string getGpuProducer();
            string getComputerPrice();

            // EXTRAS

            string computerToString();


    };
}
    const string PC::Computer::mainCpuProducers[CPU_PRODUCERS_COUNT] = {"Intel", "AMD", "NVIDIA", "IBM", "Qualcomm"};
    const string PC::Computer::mainGpuProducers[GPU_PRODUCERS_COUNT] = {"NVIDIA", "Asus", "MSI", "Gigabyte", "EVGA", "AMD"};
    const string PC::Computer::mainComputerProducers[PRODUCERS_COUNT] = {"Apple", "HP", "Dell", "Lenovo", "Asus", "Acer", "MSI", "Toshiba"};

#endif // COMPUTER_HPP_INCLUDED
