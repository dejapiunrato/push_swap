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

# Crear directorios para los tests
mkdir -p tests/test_100
mkdir -p tests/test_500
mkdir -p tests/test_5


# Ejecutar pruebas con todas las combinaciones de 5 números sin repetición del 0 al 4
echo -e "${YELLOW}Pruebas con todas las combinaciones de 5 números sin repetición del 0 al 4:${NC}"

generate_combinations() {
    for a in {0..4}; do
        for b in {0..4}; do
            if [ $b -ne $a ]; then
                for c in {0..4}; do
                    if [ $c -ne $a ] && [ $c -ne $b ]; then
                        for d in {0..4}; do
                            if [ $d -ne $a ] && [ $d -ne $b ] && [ $d -ne $c ]; then
                                for e in {0..4}; do
                                    if [ $e -ne $a ] && [ $e -ne $b ] && [ $e -ne $c ] && [ $e -ne $d ]; then
                                        echo "$a $b $c $d $e"
                                    fi
                                done
                            fi
                        done
                    fi
                done
            fi
        done
    done
}

i=1
generate_combinations | while read -r ARG; do
    MOVES=$(./push_swap $ARG)
    RESULT=$(echo "$MOVES" | ./checker_OS $ARG)
    MOVE_COUNT=$(echo "$MOVES" | wc -l)

    # Guardar la lista de números en un archivo
    echo "$ARG" > tests/test_5/test_5_$i

    # Guardar el resultado de ./push_swap en un archivo
 echo "$MOVES" > tests/test_5/test_5_${i}_result

    # Verificar fugas de memoria con valgrind
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        LEAKS_TEXT="${GREEN}[NO LEAKS]${NC}"
    else
        LEAKS_TEXT="${RED}[LEAKS]${NC}"
    fi

    if [ "$RESULT" == "OK" ]; then
        RESULT_TEXT="${GREEN}[OK]${NC}"
    else
        RESULT_TEXT="${RED}[KO]${NC}"
        echo -e "\n${RED}Failed Test $i${NC}"
        echo "Numbers: $ARG"
        echo "Moves count: $MOVE_COUNT"
    fi

    # Contar líneas después de cada test
    if [ $MOVE_COUNT -gt 12 ]; then
        LINE_COUNT_TEXT="${RED}$MOVE_COUNT${NC}"
    else
        LINE_COUNT_TEXT="${GREEN}$MOVE_COUNT${NC}"
    fi

    printf "Test %3d: %b %-10b Line count: %b\n" $i "$RESULT_TEXT" "$LEAKS_TEXT" "$LINE_COUNT_TEXT"
    i=$((i + 1))
done

# Ejecutar pruebas con 100 números desordenados
echo -e "${YELLOW}Pruebas con 100 números desordenados:${NC}"
RESULTS=""
LEAKS=""

for i in {1..15}
do
    ARG=$(generate_random_numbers 100)
    MOVES=$(./push_swap $ARG)
    RESULT=$(echo "$MOVES" | ./checker_OS $ARG)
    MOVE_COUNT=$(echo "$MOVES" | wc -l)

    # Guardar la lista de números en un archivo
    echo "$ARG" > tests/test_100/test_100_$i

    # Guardar el resultado de ./push_swap en un archivo
    echo "$MOVES" > tests/test_100/test_100_${i}_result

    # Verificar fugas de memoria con valgrind
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        LEAKS_TEXT="${GREEN}[NO LEAKS]${NC}"
    else
        LEAKS_TEXT="${RED}[LEAKS]${NC}"
    fi

    if [ "$RESULT" == "OK" ]; then
        RESULT_TEXT="${GREEN}[OK]${NC}"
    else
        RESULT_TEXT="${RED}[KO]${NC}"
        echo -e "\n${RED}Failed Test $i${NC}"
        echo "Numbers: $ARG"
        echo "Moves count: $MOVE_COUNT"
    fi

    # Contar líneas después de cada test
    if [ $MOVE_COUNT -gt 700 ]; then
        LINE_COUNT_TEXT="${YELLOW}$MOVE_COUNT${NC}"
    else
        LINE_COUNT_TEXT="${GREEN}$MOVE_COUNT${NC}"
    fi

    printf "Test %2d: %b %-10b Line count: %b\n" $i "$RESULT_TEXT" "$LEAKS_TEXT" "$LINE_COUNT_TEXT"
done

# Ejecutar pruebas con 500 números desordenados
echo -e "${YELLOW}Pruebas con 500 números desordenados:${NC}"

for i in {1..15}
do
    ARG=$(generate_random_numbers 500)
    MOVES=$(./push_swap $ARG)
    RESULT=$(echo "$MOVES" | ./checker_OS $ARG)
    MOVE_COUNT=$(echo "$MOVES" | wc -l)

    # Guardar la lista de números en un archivo
    echo "$ARG" > tests/test_500/test_500_$i

    # Guardar el resultado de ./push_swap en un archivo
    echo "$MOVES" > tests/test_500/test_500_${i}_result

    # Verificar fugas de memoria con valgrind
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        LEAKS_TEXT="${GREEN}[NO LEAKS]${NC}"
    else
        LEAKS_TEXT="${RED}[LEAKS]${NC}"
    fi

    if [ "$RESULT" == "OK" ]; then
        RESULT_TEXT="${GREEN}[OK]${NC}"
    else
        RESULT_TEXT="${RED}[KO]${NC}"
        echo -e "\n${RED}Failed Test $i${NC}"
        echo "Numbers: $ARG"
        echo "Moves count: $MOVE_COUNT"
    fi

    # Contar líneas después de cada test
    if [ $MOVE_COUNT -gt 5500 ]; then
        LINE_COUNT_TEXT="${YELLOW}$MOVE_COUNT${NC}"
    else
        LINE_COUNT_TEXT="${GREEN}$MOVE_COUNT${NC}"
    fi

    printf "Test %2d: %b %-10b Line count: %b\n" $i "$RESULT_TEXT" "$LEAKS_TEXT" "$LINE_COUNT_TEXT"
done