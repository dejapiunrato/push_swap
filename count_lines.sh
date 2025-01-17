#!/bin/bash

total_lines=0

for i in {1..1000}
do
  numbers=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
  lines=$(./push_swap $numbers | wc -l)
  total_lines=$((total_lines + lines))
done

average=$((total_lines / 1000))
echo "Average lines: $average"
