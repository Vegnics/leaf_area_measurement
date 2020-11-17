#include<iostream>
#include"mclasses.h"
#include<new>
#include<cmath>
#include<chrono>
using namespace std;
using namespace geom;

#define LENGTH 6
#define TOTAL 54289
#define data "data.txt"
#define data3d "data3D.txt"
int main(){
	pixelList Reg=read2Dpoints(data,TOTAL);
	triangleList T;
	T=triangulate2D(Reg);
return 0;
}
