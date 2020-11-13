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
	triangleList T;		//declare the main triangle list
	triangleList tri;	//declare the auxiliary triangle list
	pixelList Reg;		//declare the main connected component 
	pixelList _Reg;		//declare the remaining connected component
	pixelList pbuffer;	//i didn't find a use for this variable
	triangle* tbuffer;	//declare a triangle buffer for all the possible triangles
	point3DList points3D;	//declare the point3d list in order to load the 3d points.
	pixel p0;		//declare the triangulation starter point P0.
	int pp=0;		//declare the next iteration P0.
	pixel* points;		//i didn't find a use for this variable
	int l=LENGTH;		//declare the length of the point list
	int i,j;		//i didn't find a use for j, i is the triangle index
	int maxT=2*(pow((sqrt(TOTAL)-1),2));//calculate the maximum amount of triangles
	int tbufferL=0;	//the length of the main triangle buffer
	int tidx=0;	//declare the initial value for the i index
	const pixel pNULL=pixel(-10,-10,-1);//define the null pixel
	points = new pixel[TOTAL];		//allocate 2D points with the points ptr
	findTriRes res;				//the result of fintri function
	pixel markedpixel;			//the pixel that will be used as a search start pixel in the next iteration 
	int idx=0;				//i didn't find a use for this variable
	double AREA;				//the total computed area 
	auto begin = chrono::high_resolution_clock::now();
	Reg=read2Dpoints(data,TOTAL);
	points3D = read3Dpoints(data3d,TOTAL);
	_Reg=Reg.copy(); //copy main connected component region to the remaining region
	markedpixel=Reg.pixels[0];// begin the searching in the first pixel
	p0=Reg.pixels[0]; //begin the triangulation first pixel
	tbuffer = new triangle[maxT];// allocate triangles with the triangle ptr
	_Reg.rL=_Reg.L;// the length of the remaining elements of _Reg is equal to the total length of _Reg.
	while(_Reg.rL>0){
		res=findTri(p0,_Reg,Reg,markedpixel); //find triangles using findTri function
		tri=res.triangles;		// copy the obtained triangle list 
		_Reg=res.pixels;		// copy the remaining pixels
		markedpixel=res.nstartpixel;	// the search start pixel
		for(i=tidx;i<tidx+tri.L;i++){	// add the tri to tbuffer
			tbuffer[i]=tri.triangles[i-tidx];
		}
		tbufferL=tbufferL+tri.L;	// update the Length of tbuffer
		tidx=tidx+tri.L;		// update the triangle index i
		if(_Reg.rL>0){			// calculate the next P0
			while((_Reg.pixels[pp].pixeleq(pNULL))==1){
				pp++;
			}
			p0=_Reg.pixels[pp];
		}
	}
	//Reg.print();
	T.fill(tbuffer,tbufferL);//fill the main Triangle List with the triangle buffer
	//T.print();
	cout<<T.L<<endl;
	AREA=areaCalc(points3D,T);//compute the total area
	cout<<AREA<<endl;
	auto stop = chrono::high_resolution_clock::now();
	auto dur = stop - begin;
	auto ms = chrono::duration_cast<chrono::milliseconds>(dur).count();
	cout << ms << endl;
	saveTriangles("triangles.txt",T);//save the triangle list
	return 0;
}







