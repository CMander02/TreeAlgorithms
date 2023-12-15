#!/bin/bash

for i in {1..20}
do
    echo "performing $i th time..."

    python3 dataset/GDS.py

    ./wilkins_main >> result.txt

    echo "$i th time done。"
done

echo "Complete！"


