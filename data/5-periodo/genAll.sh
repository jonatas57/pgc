#!/bin/bash

python3 gen.py 1 a 1 1000000 1000000 1 1 > samples/in01.txt

python3 gen.py 4 atcg 10 5000 10000 1 10000 > samples/in02.txt
python3 gen.py 5 atcg 10 50000 100000 1 100000 > samples/in03.txt
python3 gen.py 6 atcg 10 500000 1000000 1 1000000 > samples/in04.txt

python3 gen.py 7 abcdefghijklmnopqrstuvwxyz 100 5000 10000 1 10000 > samples/in05.txt
python3 gen.py 8 abcdefghijklmnopqrstuvwxyz 100 50000 100000 1 100000 > samples/in06.txt
python3 gen.py 9 abcdefghijklmnopqrstuvwxyz 100 500000 1000000 1 1000000 > samples/in07.txt

python3 gen.py 10 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 5000 10000 1 10000 > samples/in08.txt
python3 gen.py 11 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 50000 100000 1 100000 > samples/in09.txt
python3 gen.py 12 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 500000 1000000 1 1000000 > samples/in10.txt
