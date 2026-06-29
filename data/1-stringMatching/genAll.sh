#!/bin/bash

sampleFolder=./samples

# params: seed alfabeto, tamanho min, tamanho max, qtd queries, min query size, max query size

python3 gen.py 1 ab 10000 100 10 > $sampleFolder/in01.txt
python3 gen.py 2 ab 10000 100 1000 > $sampleFolder/in02.txt
python3 gen.py 3 ab 100000 100 10 > $sampleFolder/in03.txt
python3 gen.py 4 ab 100000 100 1000 > $sampleFolder/in04.txt
python3 gen.py 5 ab 1000000 100 10 > $sampleFolder/in05.txt
python3 gen.py 6 ab 1000000 100 1000 > $sampleFolder/in06.txt

python3 gen.py 7 abcdefghijklmnopqrstuvwxyz 10000 100 10 > $sampleFolder/in07.txt
python3 gen.py 8 abcdefghijklmnopqrstuvwxyz 10000 100 1000 > $sampleFolder/in08.txt
python3 gen.py 9 abcdefghijklmnopqrstuvwxyz 100000 100 10 > $sampleFolder/in09.txt
python3 gen.py 10 abcdefghijklmnopqrstuvwxyz 100000 100 1000 > $sampleFolder/in10.txt
python3 gen.py 11 abcdefghijklmnopqrstuvwxyz 1000000 100 10 > $sampleFolder/in11.txt
python3 gen.py 12 abcdefghijklmnopqrstuvwxyz 1000000 100 1000 > $sampleFolder/in12.txt

python3 gen.py 13 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 100 10 > $sampleFolder/in13.txt
python3 gen.py 14 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 10000 100 1000 > $sampleFolder/in14.txt
python3 gen.py 15 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 100 10 > $sampleFolder/in15.txt
python3 gen.py 16 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 100000 100 1000 > $sampleFolder/in16.txt
python3 gen.py 17 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000000 100 10 > $sampleFolder/in17.txt
python3 gen.py 18 "\ !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_\`abcdefghijklmnopqrstuvwxyz{|}~" 1000000 100 1000 > $sampleFolder/in18.txt
