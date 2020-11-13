/*
 * classes_t1.cpp
 *
 *  Created on: Feb 7, 2020
 *      Author: amaranth
 */
#include<iostream>
#include"mclasses.h"
#include<new>
#include<cmath>
#include<chrono>
using namespace std;
using namespace geom;

#define LENGTH 6
#define TOTAL 26181
#define data "Ger3data.txt"
#define data3d "Ger3data3D.txt"
int main(){
	triangleList T;
	triangleList tri;
	pixelList Reg;
	pixelList _Reg;
	pixelList pbuffer;
	triangle* tbuffer;
	point3DList points3D;
	pixel p0;
	int pp=0;
	pixel* points;
	int l=LENGTH;
	int i,j;
	int maxT=2*(pow((sqrt(TOTAL)-1),2));
	int tbufferL=0;
	int tidx=0;
	const pixel pNULL=pixel(-10,-10,-1);
	points = new pixel[TOTAL];
	findTriRes res;
	pixel markedpixel;
	int idx=0;
	double AREA;
	auto begin = chrono::high_resolution_clock::now();
	Reg=read2Dpoints(data,TOTAL);
	points3D = read3Dpoints(data3d,TOTAL);
	_Reg=Reg.copy(); //copy region
	markedpixel=Reg.pixels[0];
	p0=Reg.pixels[0]; //first pixel
	tbuffer = new triangle[maxT];
	_Reg.rL=_Reg.L;
	while(_Reg.rL>0){
		res=findTri(p0,_Reg,Reg,markedpixel); //find triangles
		tri=res.triangles;
		_Reg=res.pixels;
		markedpixel=res.nstartpixel;
		for(i=tidx;i<tidx+tri.L;i++){
			tbuffer[i]=tri.triangles[i-tidx];
		}
		tbufferL=tbufferL+tri.L;
		tidx=tidx+tri.L;
		if(_Reg.rL>0){
			while((_Reg.pixels[pp].pixeleq(pNULL))==1){
				pp++;
			}
			p0=_Reg.pixels[pp];
		}
	}
	//Reg.print();
	T.fill(tbuffer,tbufferL);
	//T.print();
	cout<<T.L<<endl;
	AREA=areaCalc(points3D,T);
	cout<<AREA<<endl;
	auto stop = chrono::high_resolution_clock::now();
	auto dur = stop - begin;
	auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
	cout << ms << endl;
	saveTriangles("triangles.txt",T);
	return 0;
}







