#!/bin/bash

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Generar la primera combinación de 5 números sin repetición del 0 al 4
ARG="0 1 2 3 4 5 6 7 8 9 10"

# Ejecutar push_swap y checker_OS
MOVES=$(./push_swap $ARG | tr -d '\r')
RESULT=$(echo "$MOVES" | ./checker_OS $ARG)

if [ "$RESULT" == "OK" ]; then
    RESULT_TEXT="${GREEN}[OK]${NC}"
else
    RESULT_TEXT="${RED}[KO]${NC}"
    echo -e "\n${RED}Failed Test${NC}"
    echo "Numbers: $ARG"
    echo "Moves count: $(echo "$MOVES" | wc -l)"
fi

printf "Test: %b\n" "$RESULT_TEXT"