#!/bin/bash

python3 gen.py 1 ab 1000 > samples/in01.txt
python3 gen.py 2 ab 10000 > samples/in02.txt
python3 gen.py 3 ab 100000 > samples/in03.txt
python3 gen.py 4 ab 1000 1 > samples/in04.txt
python3 gen.py 5 ab 10000 1 > samples/in05.txt
python3 gen.py 6 ab 100000 1 > samples/in06.txt
python3 gen.py 7 ab 1000 2 > samples/in07.txt
python3 gen.py 8 ab 10000 2 > samples/in08.txt
python3 gen.py 9 ab 100000 2 > samples/in09.txt

python3 gen.py 10 abcdefghijklmnopqrstuvwxyz 1000 > samples/in10.txt
python3 gen.py 11 abcdefghijklmnopqrstuvwxyz 10000 > samples/in11.txt
python3 gen.py 12 abcdefghijklmnopqrstuvwxyz 100000 > samples/in12.txt
python3 gen.py 13 abcdefghijklmnopqrstuvwxyz 1000 1 > samples/in13.txt
python3 gen.py 14 abcdefghijklmnopqrstuvwxyz 10000 1 > samples/in14.txt
python3 gen.py 15 abcdefghijklmnopqrstuvwxyz 100000 1 > samples/in15.txt
python3 gen.py 16 abcdefghijklmnopqrstuvwxyz 1000 2 > samples/in16.txt
python3 gen.py 17 abcdefghijklmnopqrstuvwxyz 10000 2 > samples/in17.txt
python3 gen.py 18 abcdefghijklmnopqrstuvwxyz 100000 2 > samples/in18.txt

python3 gen.py 19 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 > samples/in19.txt
python3 gen.py 20 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 > samples/in20.txt
python3 gen.py 21 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 > samples/in21.txt
python3 gen.py 22 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 1 > samples/in22.txt
python3 gen.py 23 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 1 > samples/in23.txt
python3 gen.py 24 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 1 > samples/in24.txt
python3 gen.py 25 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000 2 > samples/in25.txt
python3 gen.py 26 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 2 > samples/in26.txt
python3 gen.py 27 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 2 > samples/in27.txt
