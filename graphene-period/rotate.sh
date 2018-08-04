#!/bin/bash

#./rotate 0.6185895741 < graphene-layer0-with-H.txt > "graphene-layer1-357.txt"
./rotate < graphene-layer0-with-H.txt > "graphene-layer1-357.txt"
cat gaussian-header.gjf > "graphene-double-357.gjf"
cat graphene-layer0-with-H.txt >> "graphene-double-357.gjf"
cat "graphene-layer1-357.txt" >> "graphene-double-357.gjf"
