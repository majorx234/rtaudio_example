#!/bin/bash +x

INFILE=$1
OUTFILE=$2
PITCHSTANDARD="440.0"

echo "$1"
echo "$2"

while IFS= read -r line
do
		NOTE=$(echo "$line"|awk '{print $1}')
		echo "$NOTE"
		DURATION=$(echo "$line"|awk '{print $2}')
		FREQUENCY=$(echo "$PITCHSTANDARD $NOTE"|awk 'END {print ($1*(2^(1.0/12.0))^$2)}')
		echo "$FREQUENCY"
    ./sine_wave_generator $DURATION $FREQUENCY|./adsr_modificator |tail -n +2 >> $OUTFILE

done < "$INFILE"




