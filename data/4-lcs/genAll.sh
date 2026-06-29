#!/bin/bash

python3 gen.py 1 ab 500 1000 > samples/in01.txt
python3 gen.py 2 ab 5000 10000 > samples/in02.txt
python3 gen.py 3 ab 50000 100000 > samples/in03.txt

python3 gen.py 4 ab 500 1000 1 > samples/in04.txt
python3 gen.py 5 ab 5000 10000 1 > samples/in05.txt
python3 gen.py 6 ab 50000 100000 1 > samples/in06

python3 gen.py 7 abcdefghijklmnopqrstuvwxyz 500 1000 > samples/in07.txt
python3 gen.py 8 abcdefghijklmnopqrstuvwxyz 5000 10000 > samples/in08.txt
python3 gen.py 9 abcdefghijklmnopqrstuvwxyz 50000 100000 > samples/in09.txt

python3 gen.py 10 abcdefghijklmnopqrstuvwxyz 500 1000 1 > samples/in10.txt
python3 gen.py 11 abcdefghijklmnopqrstuvwxyz 5000 10000 1 > samples/in11.txt
python3 gen.py 12 abcdefghijklmnopqrstuvwxyz 50000 100000 1 > samples/in12.txt

python3 gen.py 13 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 500 1000 > samples/in13.txt
python3 gen.py 14 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 5000 10000 > samples/in14.txt
python3 gen.py 15 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 50000 100000 > samples/in15.txt

python3 gen.py 16 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 500 1000 1 > samples/in16.txt
python3 gen.py 17 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 5000 10000 1 > samples/in17.txt
python3 gen.py 18 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 50000 100000 1 > samples/in18.txt
