#!/bin/bash

python3 gen.py 1 ab 100 1000 100 > samples/in01.txt
python3 gen.py 2 ab 1000 10000 100 > samples/in02.txt
python3 gen.py 3 ab 100000 1000000 100 > samples/in03.txt

python3 gen.py 4 abcdefghijklmnopqrstuvwxyz 100 1000 100 > samples/in04.txt
python3 gen.py 5 abcdefghijklmnopqrstuvwxyz 1000 10000 100 > samples/in05.txt
python3 gen.py 6 abcdefghijklmnopqrstuvwxyz 100000 1000000 100 > samples/in06.txt

python3 gen.py 7 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100 1000 100 > samples/in07.txt
python3 gen.py 8 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 10000 100 > samples/in08.txt
python3 gen.py 9 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 1000000 100 > samples/in09.txt
