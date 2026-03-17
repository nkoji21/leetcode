#!/bin/bash

set -e

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
RESET='\033[0m'

echo -e "${GREEN}🔄 Initializing leetcode repository...${RESET}"
echo ""

echo -ne "${BLUE}📝 Select language (c/cpp/python): ${RESET}"
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
  *)
    echo -e "${RED}❌ Invalid language: ${lang}${RESET}"
    echo -e "${YELLOW}⚠️  Available: c, cpp, python${RESET}"
    exit 1
    ;;
esac

echo "$lang" > language

if [ ! -f "_template/${lang}/main.${ext}" ]; then
  echo -e "${RED}❌ Template not found: _template/${lang}/main.${ext}${RESET}"
  exit 1
fi

cp "_template/${lang}/main.${ext}" "./main.${ext}"

echo ""
echo -e "${GREEN}✅ Initialization complete!${RESET}"
echo -e "${GREEN}🌐 Language: ${lang}${RESET}"
echo -e "${GREEN}📄 Working file: main.${ext}${RESET}"
echo ""
echo -e "${YELLOW}📋 Next steps:${RESET}"
echo -e "  1. ✏️  Edit main.${ext}"
echo -e "  2. ▶️  Run with: ${BLUE}make run${RESET}"
echo -e "  3. 💾 Save with: ${BLUE}make sv${RESET}"
