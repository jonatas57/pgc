#!/bin/bash

python3 gen.py 1 a 100 100 > samples/in01.txt
python3 gen.py 2 a 1000 1000 > samples/in02.txt
python3 gen.py 3 a 1000000 1000000 > samples/in03.txt

python3 gen.py 4 ab 100 1000 > samples/in04.txt
python3 gen.py 5 ab 1000 10000 > samples/in05.txt
python3 gen.py 6 ab 100000 1000000 > samples/in06.txt

python3 gen.py 7 abcdefghijklmnopqrstuvwxyz 100 1000 > samples/in07.txt
python3 gen.py 8 abcdefghijklmnopqrstuvwxyz 1000 10000 > samples/in08.txt
python3 gen.py 9 abcdefghijklmnopqrstuvwxyz 100000 1000000 > samples/in09.txt

python3 gen.py 10 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 1000 > samples/in10.txt
python3 gen.py 11 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 10000 > samples/in11.txt
python3 gen.py 12 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 1000000 > samples/in12.txt
