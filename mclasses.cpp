/*
 * mclasses.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: amaranth
 */

#include"mclasses.h"
#include<iostream>
#include<new>
#include<cmath>

using namespace std;
namespace geom{
pixel::pixel(){

}

pixel::pixel(int i, int j, int idx){
	this->i=i;
	this->j=j;
	this->idx=idx;
}

void pixel::print(){
	cout<<"p["<<this->idx<<"]"<<"=("<<this->i<<","<<this->j<<")"<<endl;
}

bool pixel::pixeleq(pixel spixel){
	if((spixel.i==this->i)&&(spixel.j==this->j))
		return true;
	else{
		return false;
	}
}

bool pixel::lessthan(pixel spixel){
	if (spixel.i>this->i)
		return true;
	else {
		return false;
		}
}

bool pixel::isneigh(pixel* bound,int boundL){
	int i=0;
	pixel neighbors[8];
	neighbors[0]=pixel(this->i-1,this->j-1,-1);
	neighbors[1]=pixel(this->i-1,this->j,-1);
	neighbors[2]=pixel(this->i-1,this->j+1,-1);
	neighbors[3]=pixel(this->i,this->j-1,-1);
	neighbors[4]=pixel(this->i,this->j+1,-1);
	neighbors[5]=pixel(this->i+1,this->j-1,-1);
	neighbors[6]=pixel(this->i+1,this->j,-1);
	neighbors[7]=pixel(this->i+1,this->j+1,-1);
	while((i<boundL)){
		if(bound[i].pixeleq(neighbors[0])){
			return true;
		}
		else if(bound[i].pixeleq(neighbors[1])){
			return true;
		}
		else if(bound[i].pixeleq(neighbors[2])){
			return true;
				}
		else if(bound[i].pixeleq(neighbors[3])){
			return true;
				}
		else if(bound[i].pixeleq(neighbors[4])){
			return true;
				}
		else if(bound[i].pixeleq(neighbors[5])){
			return true;
				}
		else if(bound[i].pixeleq(neighbors[6])){
			return true;
				}
		else if(bound[i].pixeleq(neighbors[7])){
			return true;
				}
		else{
			i++;
		}
	}
	return false;
}
pixel::~pixel(){

}

point3D::point3D(){

}

void point3D::print(){
	cout<<'('<<this->x<<','<<this->y<<','<<this->z<<')'<<endl;
}

point3D::point3D(float x,float y, float z){
	this->x=x;
	this->y=y;
	this->z=z;
}
point3D::~point3D(){

}

point3DList::point3DList(){
	this->L=0;
}
void point3DList::fill(point3D* points, int Length){
	this->points=points;
	this->L=Length;
}

void point3DList::print(){
	int i;
	for(i=0;i<this->L;i++){
		this->points[i].print();
	}
}
point3DList::~point3DList(){

}


pixelList::pixelList(){
	this->L=0;
}

void pixelList::fillList(pixel* _pixels, int Length){
	this->pixels=_pixels;
	this->L=Length;
}

bool pixelList::find(pixel testpixel,int start){
	bool check=false;
	int i=start;
	while(check==false && i<this->L){
		check=this->pixels[i].pixeleq(testpixel);
		i++;
	}
	return check;
}

indexRes::indexRes(){

}

indexRes::~indexRes(){

}

indexRes pixelList::index(pixel testpixel){
	indexRes res;
	bool check=false;
	int i=0;
		while(check==false && i<this->L){
			check=this->pixels[i].pixeleq(testpixel);
			i++;
		}
		if (check==true){
			i--;
			res.valid=true;
		}
		else{
			i=-1;
			res.valid=false;
		}
		res.index=i;
		return res;
}
pixelList pixelList::copy(){
	pixel* p;
	pixelList copy;
	p=new (nothrow) pixel[this->L];
	for (int i=0;i<this->L;i++){
		p[i]=this->pixels[i];
	}
	copy.pixels=p;
	copy.L=this->L;
	return copy;
}


void pixelList::removeNeighs(pixel pnt){
	pixel neighbors[9];
	neighbors[0]=pixel(pnt.i-1,pnt.j-1,-1);
	neighbors[1]=pixel(pnt.i-1,pnt.j,-1);
	neighbors[2]=pixel(pnt.i-1,pnt.j+1,-1);
	neighbors[3]=pixel(pnt.i,pnt.j-1,-1);
	neighbors[4]=pixel(pnt.i,pnt.j,-1);
	neighbors[5]=pixel(pnt.i,pnt.j+1,-1);
	neighbors[6]=pixel(pnt.i+1,pnt.j-1,-1);
	neighbors[7]=pixel(pnt.i+1,pnt.j,-1);
	neighbors[8]=pixel(pnt.i+1,pnt.j+1,-1);
	int i=0,j=0;
	int k=0;
	bool check=false;
	for (j=0;j<9;j++){
			while(check==false && i<this->L){
				check=this->pixels[i].pixeleq(neighbors[j]);
				i++;
			}
			if (check==true){
				this->pixels[i-1]=pixel(-10,-10,-1);
				check=false;
				k++;
			}
			i=0;
		}
	this->rL=this->rL-k;

}

void pixelList::print(){
	for (int i=0;i<this->L;i++){
		this->pixels[i].print();
	}
}



pixelList::~pixelList(){

}

triangle::triangle(){

}

triangle::triangle(int p0,int p1, int p2){
	this->p0=p0;
	this->p1=p1;
	this->p2=p2;
}

void triangle::print(){
	cout<<'('<<p0<<','<<p1<<','<<p2<<')'<<endl;
}

triangle::~triangle(){

}

triangleList::triangleList(){
	this->L=0;
}

void triangleList::fill(triangle* triangles,int Length){
	this->triangles=triangles;
	this->L=Length;
}
void triangleList::print(){
	for (int i=0;i<this->L;i++){
		this->triangles[i].print();
	}
}

findTriRes::findTriRes(){

}

findTriRes::~findTriRes(){

}
triangleList triangleList::copy(){
		triangle* p;
		triangleList copy;
		p=new (nothrow) triangle[this->L];
		for (int i=0;i<this->L;i++){
			p[i]=this->triangles[i];
		}
		copy.triangles=p;
		copy.L=this->L;
		return copy;
	}


triangleList::~triangleList(){

}


findTriRes findTri(pixel pnt,pixelList region,pixelList Tregion,pixel startpixel){
	int neighcheck[8]={-1,-1,-1,-1,-1,-1,-1,-1};
	pixel* neighbors;
	pixelList _region;
	triangleList triangles;
	neighbors= new pixel[9];
	triangle* tris;
	tris=new triangle[8];
	int k=0,i,j;
	findTriRes res;
	const pixel pxNULL=pixel(-10,-10,-1);
	//pixel newstartpixel=startpixel;
	_region=region;
	neighbors[0]=pixel(pnt.i-1,pnt.j-1,-1);
	neighbors[1]=pixel(pnt.i-1,pnt.j,-1);
	neighbors[2]=pixel(pnt.i-1,pnt.j+1,-1);
	neighbors[3]=pixel(pnt.i,pnt.j-1,-1);
	neighbors[4]=pixel(pnt.i,pnt.j,-1);
	neighbors[5]=pixel(pnt.i,pnt.j+1,-1);
	neighbors[6]=pixel(pnt.i+1,pnt.j-1,-1);
	neighbors[7]=pixel(pnt.i+1,pnt.j,-1);
	neighbors[8]=pixel(pnt.i+1,pnt.j+1,-1);
	i=startpixel.idx;
	j=0;
	while((i<region.L) && (j<9)){
		if((Tregion.pixels[i].pixeleq(neighbors[0]))==true){
			neighcheck[0]=i;
			j++;
			if(startpixel.lessthan(Tregion.pixels[i])){
				startpixel=Tregion.pixels[i];
			}
		}
		else if((Tregion.pixels[i].pixeleq(neighbors[1]))==true){
					neighcheck[1]=i;
					j++;
					if(startpixel.lessthan(Tregion.pixels[i])){
									startpixel=Tregion.pixels[i];
								}
				}
		else if((Tregion.pixels[i].pixeleq(neighbors[2]))==true){
							neighcheck[2]=i;
							j++;
					if(startpixel.lessthan(Tregion.pixels[i])){
									startpixel=Tregion.pixels[i];
								}
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[3]))==true){
							neighcheck[3]=i;
							j++;
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[4]))==true){
							_region.rL--;
							_region.pixels[i]=pixel(-10,-10,-1);
							j++;
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[5]))==true){
							neighcheck[4]=i;
							j++;
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[6]))==true){
							neighcheck[5]=i;
							j++;
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[7]))==true){
							neighcheck[6]=i;
							j++;
						}
		else if((Tregion.pixels[i].pixeleq(neighbors[8]))==true){
							neighcheck[7]=i;
							j++;
						}
		i++;
	}
	if((neighcheck[0]!=-1) && (neighcheck[1]!=-1)){
		if (_region.pixels[neighcheck[0]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[0]].i=-10;
			_region.pixels[neighcheck[0]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[1]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[1]].i=-10;
					_region.pixels[neighcheck[1]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[1],pnt.idx,neighcheck[0]};//tris[k]={neighcheck[0],neighcheck[1],pnt.idx};//tris[k]={pnt.idx,neighcheck[0],neighcheck[1]};
		k++;
	}
	if((neighcheck[1]!=-1) && (neighcheck[2]!=-1)){
		if (_region.pixels[neighcheck[1]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[1]].i=-10;
			_region.pixels[neighcheck[1]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[2]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[2]].i=-10;
					_region.pixels[neighcheck[2]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[1],neighcheck[2],pnt.idx};//tris[k]={neighcheck[1],neighcheck[2],pnt.idx};//tris[k]={pnt.idx,neighcheck[1],neighcheck[2]};
		k++;
	}
	if((neighcheck[2]!=-1) && (neighcheck[4]!=-1)){
		if (_region.pixels[neighcheck[2]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[2]].i=-10;
			_region.pixels[neighcheck[2]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[4]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[4]].i=-10;
					_region.pixels[neighcheck[4]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[4],pnt.idx,neighcheck[2]};//tris[k]={neighcheck[2],pnt.idx,neighcheck[4]};//tris[k]={pnt.idx,neighcheck[2],neighcheck[4]};
		k++;
	}
	if((neighcheck[4]!=-1) && (neighcheck[7]!=-1)){
		if (_region.pixels[neighcheck[4]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[4]].i=-10;
			_region.pixels[neighcheck[4]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[7]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[7]].i=-10;
					_region.pixels[neighcheck[7]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[4],neighcheck[7],pnt.idx};//tris[k]={pnt.idx,neighcheck[4],neighcheck[7]};//tris[k]={pnt.idx,neighcheck[4],neighcheck[7]};
		k++;
	}
	if((neighcheck[7]!=-1) && (neighcheck[6]!=-1)){
		if (_region.pixels[neighcheck[7]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[7]].i=-10;
			_region.pixels[neighcheck[7]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[6]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[6]].i=-10;
					_region.pixels[neighcheck[6]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[6],pnt.idx,neighcheck[7]};//tris[k]={pnt.idx,neighcheck[7],neighcheck[6]};//tris[k]={pnt.idx,neighcheck[7],neighcheck[6]};
		k++;
	}
	if((neighcheck[5]!=-1) && (neighcheck[6]!=-1)){
		if (_region.pixels[neighcheck[5]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[5]].i=-10;
			_region.pixels[neighcheck[5]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[6]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[6]].i=-10;
					_region.pixels[neighcheck[6]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[6],neighcheck[5],pnt.idx};//tris[k]={pnt.idx,neighcheck[6],neighcheck[5]};//tris[k]={pnt.idx,neighcheck[5],neighcheck[6]};
		k++;
	}
	if((neighcheck[5]!=-1) && (neighcheck[3]!=-1)){
		if (_region.pixels[neighcheck[5]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[5]].i=-10;
			_region.pixels[neighcheck[5]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[3]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[3]].i=-10;
					_region.pixels[neighcheck[3]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[3],pnt.idx,neighcheck[5]};//tris[k]={pnt.idx,neighcheck[5],neighcheck[3]};//tris[k]={pnt.idx,neighcheck[5],neighcheck[3]};
		k++;
	}
	if((neighcheck[3]!=-1) && (neighcheck[0]!=-1)){
		if (_region.pixels[neighcheck[3]].pixeleq(pxNULL)==false){
			_region.pixels[neighcheck[3]].i=-10;
			_region.pixels[neighcheck[3]].j=-10;
			_region.rL--;
		}
		if (_region.pixels[neighcheck[0]].pixeleq(pxNULL)==false){
					_region.pixels[neighcheck[0]].i=-10;
					_region.pixels[neighcheck[0]].j=-10;
					_region.rL--;
				}
		tris[k]={neighcheck[3],neighcheck[0],pnt.idx};//tris[k]={neighcheck[0],pnt.idx,neighcheck[3]};//tris[k]={pnt.idx,neighcheck[3],neighcheck[0]};
		k++;
	}
	delete[] neighbors;
	triangles.fill(tris,k);
	res.pixels=_region;
	res.triangles=triangles;
	res.nstartpixel=startpixel;
	return res;
}

pixelList read2Dpoints(string filename,int Length){
	pixel* points;
	ifstream inFile;
	string line;
	string buffer;
	string x,y;
	pixelList List;
	int i,idx=0;
	int xint,yint;
	points = new pixel[Length];
	inFile.open(filename);
	if(!inFile){
		 cout << "Unable to open file";
		 exit(1); // terminate with error
	}
	else{
		while(getline(inFile,line)){
			i=0;
			buffer="";
			while(line[i]!=','){
				buffer=buffer+line[i];
				i++;
			}
			x=buffer;
			buffer="";
			i++;
			while(line[i]!='n'){
				buffer=buffer+line[i];
				i++;
			}
			y=buffer;
			xint=stoi(x);
			yint=stoi(y);
			points[idx]={xint,yint,idx};
			idx++;
		}
	}
	List.fillList(points,Length);
	return List;
}


point3DList read3Dpoints(string filename,int Length){
	point3DList List;
	point3D* points;
	ifstream inFile;
	string line;
	string buffer;
	string x,y,z;
	int i,idx=0;
	float xp,yp,zp;
	points = new point3D[Length];
	inFile.open(filename);
	if(!inFile){
		 cout << "Unable to open file";
		 exit(1); // terminate with error
	}
	else{
		while(getline(inFile,line)){
			i=0;
			buffer="";
			while(line[i]!=';'){
				buffer=buffer+line[i];
				i++;
			}
			x=buffer;
			buffer="";
			i++;
			while(line[i]!=';'){
				buffer=buffer+line[i];
				i++;
			}
			y=buffer;
			buffer="";
			i++;
			while(line[i]!='n'){
				buffer=buffer+line[i];
				i++;
			}
			z=buffer;
			xp=stof(x);
			yp=stof(y);
			zp=stof(z);
			points[idx]=point3D(xp,yp,zp);
			idx++;
		}
	}
	List.fill(points,Length);
	return List;
}
double sq(double num){
	return num*num;
}
double distance3D(point3D p1, point3D p2){
	return pow(sq((p1.x-p2.x))+sq((p1.y-p2.y))+sq((p1.z-p2.z)),0.5);
}

double areaCalc(point3DList points, triangleList triangles){
	int i;
	double totalArea=0;
	double triArea;
	double L1,L2,L3;
	double sp;
	for(i=0;i<triangles.L;i++){
		L1=distance3D(points.points[triangles.triangles[i].p0],points.points[triangles.triangles[i].p1]);
		L2=distance3D(points.points[triangles.triangles[i].p1],points.points[triangles.triangles[i].p2]);
		L3=distance3D(points.points[triangles.triangles[i].p2],points.points[triangles.triangles[i].p0]);
		sp=(L1+L2+L3)/2;
		triArea=pow((sp)*(sp-L1)*(sp-L2)*(sp-L3),0.5);
		totalArea=totalArea+triArea;
	}
	return totalArea;
}

void saveTriangles(string filename, triangleList Tlist){
	int i;
	ofstream file;
	file.open(filename);
	for(i=0;i<Tlist.L;i++){
		file<<to_string(Tlist.triangles[i].p0);
		file<<",";
		file<<to_string(Tlist.triangles[i].p1);
		file<<",";
		file<<to_string(Tlist.triangles[i].p2);
		file<<";\n";
	}
	file.close();
	return;
}


}

