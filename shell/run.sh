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
    echo -e "${YELLOW}ℹ️  For C, run: ./main <args>${RESET}"
    ;;
  cpp)
    echo -e "${YELLOW}ℹ️  For C++, run: ./main <args>${RESET}"
    ;;
  python)
    python3 main.py "$@"
    ;;
  typescript)
    bun run main.ts "$@"
    ;;
  *)
    echo -e "${RED}❌ Invalid language in ./language: ${lang}${RESET}"
    exit 1
    ;;
esac
