#!/bin/bash

set -e

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

if [ ! -f ./language ]; then
  echo -e "${RED}❌ Language not set. Run 'make init' or 'make setlang' first.${RESET}"
  exit 1
fi

lang=$(cat ./language)

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
  *)
    echo -e "${RED}❌ Invalid language in ./language: ${lang}${RESET}"
    exit 1
    ;;
esac

source_file="main.${ext}"

if [ ! -f "./${source_file}" ]; then
  echo -e "${RED}❌ Source file not found: ${source_file}${RESET}"
  exit 1
fi

echo -ne "${BLUE}Problem number? ${RESET}"
read num

if ! [[ "$num" =~ ^[0-9]+$ ]]; then
  echo -e "${RED}❌ Invalid number: ${num}${RESET}"
  exit 1
fi

padded=$(printf "%04d" "$num")
dest_file="_result/${padded}.${ext}"

echo -e "${BLUE}💾 Saving to ${dest_file}${RESET}"
mkdir -p "_result"
cp "${source_file}" "${dest_file}"

echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
git add "${dest_file}"
git commit -m "problem ${padded}"
echo -e "${YELLOW}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"

echo -e "${GREEN}🔄 Resetting ${source_file} from template${RESET}"
cp "_template/${lang}/${source_file}" "./${source_file}"

echo ""
echo -e "${GREEN}✅ Done: leetcode ${padded}${RESET}"
