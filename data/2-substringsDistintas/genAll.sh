#!/bin/bash

python3 gen.py 1 a 100 > samples/in01.txt
python3 gen.py 1 a 1000 > samples/in02.txt
python3 gen.py 1 a 10000 > samples/in03.txt
python3 gen.py 1 a 100000 > samples/in04.txt
python3 gen.py 1 a 1000000 > samples/in05.txt

python3 gen.py 2 ab 100 > samples/in06.txt
python3 gen.py 3 ab 1000 > samples/in07.txt
python3 gen.py 4 ab 10000 > samples/in08.txt
python3 gen.py 5 ab 100000 > samples/in09.txt
python3 gen.py 6 ab 1000000 > samples/in10.txt

python3 gen.py 7 abcdefghijklmnopqrstuvwxyz 100 > samples/in11.txt
python3 gen.py 8 abcdefghijklmnopqrstuvwxyz 1000 > samples/in12.txt
python3 gen.py 9 abcdefghijklmnopqrstuvwxyz 10000 > samples/in13.txt
python3 gen.py 10 abcdefghijklmnopqrstuvwxyz 100000 > samples/in14.txt
python3 gen.py 11 abcdefghijklmnopqrstuvwxyz 1000000 > samples/in15.txt

python3 gen.py 12 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 > samples/in16.txt
python3 gen.py 13 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 > samples/in17.txt
python3 gen.py 14 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 > samples/in18.txt
python3 gen.py 15 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 > samples/in19.txt
python3 gen.py 16 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000000 > samples/in20.txt
