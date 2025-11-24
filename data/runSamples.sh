# get directories of all samples
SAMPLES_DIR=$(ls -d */)

structs=(
  "array"
  "arvore"
  "automato"
)

for SAMPLE_DIR in $SAMPLES_DIR; do
  SAMPLE_DIR=${SAMPLE_DIR%/}
  echo "Running sample: $SAMPLE_DIR"
  for STRUCT in "${structs[@]}"; do
    SOURCE_FILE="../algoritmos/$SAMPLE_DIR/$STRUCT.cpp"
    PROGRAM_FILE="$SAMPLE_DIR/bin/$STRUCT.out"

    if [ ! -d "$SAMPLE_DIR/bin" ]; then
      mkdir -p "$SAMPLE_DIR/bin"
    fi
    if [ ! -f "$PROGRAM_FILE" ] || [ "$SOURCE_FILE" -nt "$PROGRAM_FILE" ]; then
      g++ -std=c++17 -O3 -o "$PROGRAM_FILE" "$SOURCE_FILE"
    fi

    echo "$STRUCT"
    for INPUT_FILE in $(ls ./$SAMPLE_DIR/samples/*.in); do
      OUTPUT_FILE="${INPUT_FILE%.in}.out"

      perfResult=$( { gtime -v $PROGRAM_FILE < "$INPUT_FILE" > "$OUTPUT_FILE"; } 2>&1 )
      
      totalTime=$(echo "$perfResult" | grep "User time (seconds)" | awk '{print $4}')
      maxMemory=$(echo "$perfResult" | grep "Maximum resident set size (kbytes)" | awk '{print $6}')

      echo "$(basename "$INPUT_FILE"): ${totalTime}s, ${maxMemory}KB"
    done
  done
done
