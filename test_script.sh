#!/bin/bash

# filepath: /home/piesito/42 Madrid/push_swap/test_script.sh

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
for i in {1..15}
do
    ARG=$(generate_random_numbers 3)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    LINE_COUNT=$(./push_swap $ARG | wc -l)
    
    if [ "$RESULT" == "OK" ]; then
        echo -e "Test $i: ${GREEN}$RESULT${NC}, Líneas: $LINE_COUNT"
    else
        echo -e "Test $i: ${RED}$RESULT${NC}, Líneas: $LINE_COUNT"
    fi
    
    # Comprobar fugas de memoria con valgrind
    valgrind --leak-check=full --error-exitcode=1 ./push_swap $ARG > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${RED}Fuga de memoria detectada en la prueba $i${NC}"
    else
        echo -e "${GREEN}No se detectaron fugas de memoria en la prueba $i${NC}"
    fi
done

echo -e "${GREEN}Todas las pruebas pasaron correctamente.${NC}"
