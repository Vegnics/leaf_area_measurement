/*
 * mclasses.h
 *
 *  Created on: Feb 6, 2020
 *      Author: amaranth
 */

#ifndef MCLASSES_H_
#define MCLASSES_H_
#include<fstream>
#include<string>
using namespace std;
namespace geom{

struct point3D{
	point3D();
	point3D(float,float,float);
	void print();
	float x,y,z;
	virtual ~point3D();
};

struct point3DList{
	point3DList();
	void fill(point3D* , int);
	void print();
	point3D* points;
	int L;
	virtual ~point3DList();
};

struct pixel{
	pixel();
	pixel(int,int,int);
	void print();
	bool pixeleq(pixel);
	bool lessthan(pixel);
	int i,j,idx;
	virtual ~pixel();
};


struct pixelList{
	pixelList();
	void fillList(pixel*,int);
	void print();
	pixelList copy();
	int L;
	int rL;
	pixel* pixels;
	virtual ~pixelList();
};


struct triangle{
	triangle();
	triangle(int,int,int);
	void print();
	int p0,p1,p2;
	virtual ~triangle();
};

struct triangleList{
	triangleList();
	void fill(triangle*, int);
	void print();
	triangleList copy();
	int L;
	triangle* triangles;
	virtual ~triangleList();
};

struct findTriRes{
	findTriRes();
	triangleList triangles;
	pixelList pixels;
	pixel nstartpixel;
	virtual ~findTriRes();
};

triangleList triangulate2D(pixelList);

double sq(double);

double distance3D(point3D,point3D);

double areaCalc(point3DList,triangleList);

findTriRes findTri(pixel,pixelList,pixelList,pixel);

pixelList read2Dpoints(string,int);

point3DList read3Dpoints(string,int);

void saveTriangles(string, triangleList);
void sayhello(void);

}
#endif /* MCLASSES_H_ */
