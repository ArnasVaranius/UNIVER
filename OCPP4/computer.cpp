#include "computer.hpp"

int PC::Computer::computersCounter = 0;

PC::Computer::Computer(){
    setComputerProducer(DEFAULT_PRODUCER_NAME);
    setCpuProducer(DEFAULT_CPU_PRODUCER_NAME);
    setGpuProducer(DEFAULT_GPU_PRODUCER_NAME);
    setComputerPrice(DEFAULT_COMPUTER_PRICE);
    ++computersCounter;
}

PC::Computer::Computer(const string prod, const string cpuProd, const string gpuProd, const int price){
    setComputerProducer(prod);
    setCpuProducer(cpuProd);
    setGpuProducer(gpuProd);
    setComputerPrice(price);
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

bool PC::Computer::checkComputerPrice(int computerPrice){
    if(computerPrice > 0){
        return true;
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

void PC::Computer::setComputerPrice(int priceOfComputer){
    if(checkComputerPrice(priceOfComputer)){
        computerPrice = priceOfComputer;
    }
    else {
        throw invalid_argument("invalid price!");
    }
}

// GETTERS

string PC::Computer::getComputerProducer() const{
    return computerProducer;
}

string PC::Computer::getCpuProducer() const{
    return cpuProducer;
}

string PC::Computer::getGpuProducer() const{
    return gpuProducer;
}

int PC::Computer::getComputerPrice() const{
    return computerPrice;
}

// EXTRAS

string PC::Computer::computerToString() const{
    stringstream fullPc;

    fullPc << "\n";
    fullPc << "Computer producer: " << computerProducer << "\n";
    fullPc << "CPU producer: " << cpuProducer << "\n";
    fullPc << "GPU producer: " << gpuProducer << "\n";
    fullPc << "Price: " << computerPrice << "\n";

    return fullPc.str();
}

bool PC::Computer::operator ==(const Computer& computer){
    if(this->getComputerPrice() == computer.getComputerPrice()){
        return true;
    }
    else{
        return false;
    }
}

bool PC::Computer::operator !=(const Computer& computer){
    return !(*this == computer);
}

bool PC::Computer::operator <(const Computer& computer){
        return !(*this >= computer);
}

bool PC::Computer::operator >(const Computer& computer){
        return (*this <= computer);
}

bool PC::Computer::operator >=(const Computer& computer){
    if(this->getComputerPrice() < computer.getComputerPrice()){
        return false;
    }
    return true;
}

bool PC::Computer::operator <=(const Computer& computer){
    if(this->getComputerPrice() > computer.getComputerPrice()){
        return false;
    }
    return true;
}


PC::Computer PC::Computer::operator ++(int){
    Computer temp = *this;
    int price = this->getComputerPrice();
    this->setComputerPrice(++price);
    return temp;
}
PC::Computer PC::Computer::operator --(int){
    Computer temp = *this;
    int price = this->getComputerPrice();
    this->setComputerPrice(--price);
    return temp;
}



istream& operator >>(istream& input, PC::Computer& computer){
    string tempComputerCPU;
    string tempComputerGPU;
    string tempComputerProducer;
    int tempComputerPrice;

    input >> tempComputerProducer >> tempComputerCPU >> tempComputerGPU >> tempComputerPrice;
    computer.setComputerProducer(tempComputerProducer);
    computer.setCpuProducer(tempComputerCPU);
    computer.setGpuProducer(tempComputerGPU);
    computer.setComputerPrice(tempComputerPrice);

    return input;
}

ostream& operator <<(ostream& output, const PC::Computer& computer){

    output << computer.computerToString();
    return output;
}
