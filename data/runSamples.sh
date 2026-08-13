SAMPLES_DIR=(*/)

structs=(
  "array"
  "arvore"
  "automato"
)

MAX_ITERATIONS=10

if [ -n "$1" ]; then
  MAX_ITERATIONS=$1
fi

if [ -n "$2" ]; then
  SAMPLES_DIR=("${SAMPLES_DIR[$(( $2 - 1 ))]}")
fi

if [ -n "$3" ]; then
  structs=("$3")
fi

for SAMPLE_DIR in "${SAMPLES_DIR[@]}"; do
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
    if [ ! -d "$SAMPLE_DIR/output/$STRUCT" ]; then
      mkdir -p "$SAMPLE_DIR/output/$STRUCT"
    fi
    for INPUT_FILE in $(ls ./$SAMPLE_DIR/samples/*.txt); do
      INPUT_BASENAME=$(basename "$INPUT_FILE" .txt)
      OUTPUT_FILE_NAME="$SAMPLE_DIR/output/$STRUCT/$INPUT_BASENAME"

      for i in $(seq 1 $MAX_ITERATIONS); do
        $PROGRAM_FILE < "$INPUT_FILE" > /dev/null > "$OUTPUT_FILE_NAME-$((i - 1)).out" 2> "$OUTPUT_FILE_NAME-$((i - 1)).perf"
        if [ $? -ne 0 ]; then
          echo "Error running $PROGRAM_FILE with input $INPUT_FILE"
          exit 1
        fi
      done

      # perfResult=$( { gtime -v $PROGRAM_FILE < "$INPUT_FILE" > "$OUTPUT_FILE"; } 2>&1 )
      #
      # totalTime=$(echo "$perfResult" | grep "User time (seconds)" | awk '{print $4}')
      # maxMemory=$(echo "$perfResult" | grep "Maximum resident set size (kbytes)" | awk '{print $6}')
      #
      # echo "$(basename "$INPUT_FILE"): ${totalTime}s, ${maxMemory}KB"
    done
  done
done
