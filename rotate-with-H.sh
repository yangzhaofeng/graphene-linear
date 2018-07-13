#!/bin/bash

for i in {0..30}
do
#	./rotate-vary $i < graphene-layer0-with-H.txt |sort -k2n |uniq |sed -e '/0.00000000 0.00000000 0.00000000/d' > "graphene-double-rotate/graphene-layer1-$i.txt"
	./rotate-single $i < graphene-layer0-with-H.txt > "graphene-double-rotate/graphene-layer1-$i-with-H.txt"
#	sed -i 's/^/ C\t/g' "graphene-double-rotate/graphene-layer1-$i.txt"
	cat gaussian-header.gjf > "graphene-double-rotate/graphene-double-$i-with-H.gjf"
	cat graphene-layer0-with-H.txt >> "graphene-double-rotate/graphene-double-$i-with-H.gjf"
	cat "graphene-double-rotate/graphene-layer1-$i-with-H.txt" >> "graphene-double-rotate/graphene-double-$i-with-H.gjf"
done
