#include <iostream>
using namespace std;
#include "retrieveData.h"
#include "VEML6030.h"



void main() {
VEML6030 mySensor;
mySensor.PowerOn();
	cout << "initSensor" << endl;
	int lux = 0;
	lux = mySensor.GetLux();
	cout << "requestData/t"<< lux << endl;
}

void retrieveData::initSensor() {
	
	
}

void retrieveData::requestData() {
	

}

void retrieveData::filterData() {

	cout << "filterData" << endl;

}