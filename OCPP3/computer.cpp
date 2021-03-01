#include "computer.hpp"

int PC::Computer::computersCounter = 0;

PC::Computer::Computer(){
    computerProducer = DEFAULT_PRODUCER_NAME;
    cpuProducer = DEFAULT_CPU_PRODUCER_NAME;
    gpuProducer = DEFAULT_GPU_PRODUCER_NAME;
    computerPrice = DEFAULT_COMPUTER_PRICE;
    ++computersCounter;
}

PC::Computer::~Computer(){
}

// CORRECTION CHECKS

bool PC::Computer::checkProducer(string computerProducer){
    for(int i = 0; i < PRODUCERS_COUNT; ++i){
        if(computerProducer == mainComputerProducers[i]){
            return true;
        }
    }
    return false;
}

bool PC::Computer::checkCpuProducer(string cpuProducer){
    for(int i = 0; i < CPU_PRODUCERS_COUNT; ++i){
        if(cpuProducer == mainCpuProducers[i]){
            return true;
        }
    }
    return false;
}

bool PC::Computer::checkGpuProducer(string gpuProducer){
    for(int i = 0; i < GPU_PRODUCERS_COUNT; ++i){
        if(gpuProducer == mainGpuProducers[i]){
            return true;
        }
    }
    return false;
}

bool PC::Computer::checkComputerPrice(string computerPrice){
    for(int i = 0; i < computerPrice.length(); ++i){
        if(isdigit(computerPrice[i]) && computerPrice[0] != '0'){
            return true;
        }
    }
    return false;

}

// SETTERS

void PC::Computer::setComputerProducer(string producerName){
    if(checkProducer(producerName)){
        computerProducer = producerName;
    }
    else{
        throw invalid_argument("unknown manufacturer!");
    }
}

void PC::Computer::setCpuProducer(string cpuProducerName){
    if(checkCpuProducer(cpuProducerName)){
        cpuProducer = cpuProducerName;
    }
    else {
        throw invalid_argument("unknown CPU!");
    }
}

void PC::Computer::setGpuProducer(string gpuProducerName){
    if(checkGpuProducer(gpuProducerName)){
        gpuProducer = gpuProducerName;
    }
    else{
        throw invalid_argument("unknown GPU!");
    }
}

void PC::Computer::setComputerPrice(string priceOfComputer){
    if(checkComputerPrice(priceOfComputer)){
        computerPrice = priceOfComputer;
    }
    else {
        throw invalid_argument("invalid price!");
    }
}

// GETTERS

string PC::Computer::getComputerProducer(){
    return computerProducer;
}

string PC::Computer::getCpuProducer(){
    return cpuProducer;
}

string PC::Computer::getGpuProducer(){
    return gpuProducer;
}

string PC::Computer::getComputerPrice(){
    return computerPrice;
}

// EXTRAS

string PC::Computer::computerToString(){
    stringstream fullPc;

    fullPc << "\n";
    fullPc << "Computer producer: " << computerProducer << "\n";
    fullPc << "CPU producer: " << cpuProducer << "\n";
    fullPc << "GPU producer: " << gpuProducer << "\n";
    fullPc << "Price: " << computerPrice << "\n";

    return fullPc.str();
}
