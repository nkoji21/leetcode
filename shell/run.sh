#!/bin/bash

set -e

# Colors
RED='\033[0;31m'
YELLOW='\033[0;33m'
RESET='\033[0m'

if [ ! -f ./language ]; then
  echo -e "${RED}❌ Language not set. Run 'make init' or 'make setlang' first.${RESET}"
  exit 1
fi

lang=$(cat ./language)

case "$lang" in
  c)
    gcc main.c -o main && ./main
    ;;
  cpp)
    g++ main.cpp -o main && ./main
    ;;
  python)
    python3 main.py
    ;;
  *)
    echo -e "${RED}❌ Invalid language in ./language: ${lang}${RESET}"
    exit 1
    ;;
esac
