#!/bin/bash

# Colors
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
RESET='\033[0m'

old_contest=""
if [ -f ./contest ]; then
  old_contest=$(cat ./contest)
fi

echo -ne "${BLUE}📝 Contest? (lc/nc): ${RESET}"
read contest

case "$contest" in
  lc|nc)
    ;;
  *)
    echo -e "${RED}❌ Invalid contest: ${contest}${RESET}"
    echo -e "${YELLOW}⚠️  Available: lc, nc${RESET}"
    exit 1
    ;;
esac

echo "$contest" > ./contest

if [ -z "$old_contest" ]; then
  echo -e "${GREEN}✅ Contest set: ${contest}${RESET}"
else
  echo -e "${GREEN}✅ Contest: ${YELLOW}${old_contest}${RESET} → ${GREEN}${contest}${RESET}"
fi
