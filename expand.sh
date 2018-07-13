#!/bin/bash

echo "" > "graphene-layer0.tmp"
for i in {-2..2}
do
	for j in {-2..2}
	do
		./move-more $i $j < graphene-single.txt | sort -k2n |uniq > "graphene-layer0-$i-$j.txt"
		cat "graphene-layer0-$i-$j.txt" >> 'graphene-layer0.tmp'
	done
done

sort -k2n graphene-layer0.tmp |uniq > graphene-layer0.txt

sed -i '/^$/d' graphene-layer0.txt
sed -i 's/^/ C\t/g' graphene-layer0.txt
