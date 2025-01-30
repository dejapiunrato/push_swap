#!/bin/bash

# Función para generar todas las combinaciones de 5 números sin repetición
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

# Llamar a la función para generar las combinaciones
generate_combinations