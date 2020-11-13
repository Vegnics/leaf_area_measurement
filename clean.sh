#!/bin/bash
rm -f mclasses.h
#rm -f classes_t1.cpp
rm -f libmyclasses.a
rm -f readdata.cpp
rm -f contours.cpp
cp ~/eclipse-workspace/myclasses2/libmyclasses2.a ./
cp ~/eclipse-workspace/myclasses2/mclasses.h ./
#cp ~/eclipse-workspace/myclasses2/classes_t1.cpp ./
cp ~/eclipse-workspace/myclasses2/readdata.cpp ./
#cp ~/eclipse-workspace/myclasses/contours.cpp ./
g++ -o classes_t1 classes_t1.cpp libmyclasses2.a
#g++ -o contours contours.cpp libmyclasses.a
#./classes_t1
