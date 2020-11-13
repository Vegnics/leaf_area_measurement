/*
 * readdata.cpp
 *
 *  Created on: Feb 9, 2020
 *      Author: amaranth
 */
#include <iostream>
#include <fstream>
#include "mclasses.h"
#include <string>
using namespace std;
using namespace geom;

int main () {
	pixelList myPoints;
	point3DList points3D;
	myPoints=read2Dpoints("data.txt",25);
	points3D = read3Dpoints("data3D.txt",25);
	points3D.print();

	return 0;
}






