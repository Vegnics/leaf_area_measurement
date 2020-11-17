#!/bin/bash
#rm -f mclasses.h
#rm -f classes_t1.cpp
rm -f libmyclasses.a
rm -f mclasses_v01.a
rm -f mclasses_v01.o
rm -f classes_t1
#rm -f readdata.cpp
#rm -f contours.cpp
#cp ~/eclipse-workspace/myclasses2/libmyclasses2.a ./
#cp ~/eclipse-workspace/myclasses2/mclasses.h ./
#cp ~/eclipse-workspace/myclasses2/classes_t1.cpp ./
#cp ~/eclipse-workspace/myclasses2/readdata.cpp ./
#cp ~/eclipse-workspace/myclasses/contours.cpp ./
g++ -c mclasses_v01.cpp 
ar rvf mclasses_v01.a mclasses_v01.o
mv mclasses_v01.a libmyclasses.a

#g++ -v -o classes_t1 classes_t1.cpp libmyclasses.a
g++ -v -o new_probes new_probes.cpp libmyclasses.a

#g++ -o contours contours.cpp libmyclasses.a
#./classes_t1
