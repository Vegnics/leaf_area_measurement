#!/bin/bash
cp ~/PycharmProjects/mywrapper/data.txt .
cp ~/PycharmProjects/mywrapper/data3D.txt .
g++ -o classes_t1 classes_t1.cpp libmyclasses2.a
./classes_t1

