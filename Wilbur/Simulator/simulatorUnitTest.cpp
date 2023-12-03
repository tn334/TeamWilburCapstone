#include "simulator.h"
using namespace std;

int main() {
    Simulator testSim = Simulator();

    testSim.displayState();
    for (int valveNum = 0; valveNum < 3; valveNum++) {
        testSim.setValve(valveNum, OPEN);
        testSim.displayState();
        testSim.setValve(valveNum, CLOSED);
        testSim.displayState();
    }
    testSim.setPump(0.4);
    testSim.displayState();
    testSim.setPump(0.8);
    testSim.displayState();
    return 0;
}