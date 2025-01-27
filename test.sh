#!/bin/bash

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color

# Función para generar una lista de números aleatorios
generate_random_numbers() {
    local count=$1
    shuf -i 1-10000 -n $count | tr '\n' ' '
}

# Ejecutar pruebas con 100 números desordenados
echo -e "${YELLOW}Pruebas con 100 números desordenados:${NC}"
RESULTS=""
LEAKS=""

mkdir -p tests

for i in {1..15}
do
    ARG=$(generate_random_numbers 100)
    MOVES=$(./push_swap $ARG)
    RESULT=$(echo "$MOVES" | ./checker_OS $ARG)
    MOVE_COUNT=$(echo "$MOVES" | wc -l)

    # Guardar la lista de números en un archivo
    echo "$ARG" > tests/test_$i

    # Guardar el resultado de ./push_swap en un archivo
    echo "$MOVES" > tests/test_${i}_result

    if [ "$RESULT" == "OK" ]; then
        RESULT_TEXT="${GREEN}[OK]${NC}"
    else
        RESULT_TEXT="${RED}[KO]${NC}"
        echo -e "\n${RED}Failed Test $i${NC}"
        echo "Numbers: $ARG"
        echo "Moves count: $MOVE_COUNT"
    fi

    # Comprobar fugas de memoria con valgrind
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        LEAKS="${LEAKS} Test $i"
        echo -e "${RED}Memory leak in Test $i${NC}"
        echo "Numbers: $ARG"
    fi

    RESULTS+="$RESULT_TEXT "
done

echo -e "$RESULTS"
if [ -z "$LEAKS" ]; then
    echo -e "${GREEN}No hubo fugas de memoria en ningún test.${NC}"
else
    echo -e "${RED}Hubo fugas de memoria en los siguientes tests:${NC}$LEAKS"
fi
