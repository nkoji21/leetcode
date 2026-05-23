#!/bin/bash

set -e

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
RESET='\033[0m'

echo -ne "${BLUE}📝 Select language (c/cpp/python/typescript): ${RESET}"
read lang

case "$lang" in
  c)
    ext="c"
    ;;
  cpp)
    ext="cpp"
    ;;
  python)
    ext="py"
    ;;
  typescript)
    ext="ts"
    ;;
  *)
    echo -e "${RED}❌ Invalid language: ${lang}${RESET}"
    echo -e "${YELLOW}⚠️  Available: c, cpp, python, typescript${RESET}"
    exit 1
    ;;
esac

echo "$lang" > language

if [ ! -f "_template/${lang}/main.${ext}" ]; then
  echo -e "${RED}❌ Template not found: _template/${lang}/main.${ext}${RESET}"
  exit 1
fi

rm -f ./main.c ./main.cpp ./main.py ./main.ts
cp "_template/${lang}/main.${ext}" "./main.${ext}"

echo -e "${GREEN}✅ Language set: ${lang}${RESET}"
echo -e "${GREEN}📄 Template: main.${ext}${RESET}"
