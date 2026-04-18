#!/bin/bash

set -e

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

if [ ! -f ./language ]; then
  echo -e "${RED}❌ Language not set. Run 'make init' or 'make setlang' first.${RESET}"
  exit 1
fi

lang=$(cat ./language)

case "$lang" in
  c)
    gcc main.c
    echo -e "${GREEN}✅ Built main${RESET}"
    ;;
  cpp)
    g++-15 -std=c++23 -isysroot "$(xcrun --sdk macosx --show-sdk-path)" main.cpp
    echo -e "${GREEN}✅ Built main${RESET}"
    ;;
  python)
    echo -e "${YELLOW}ℹ️  Interpreted language, nothing to build${RESET}"
    ;;
  *)
    echo -e "${RED}❌ Invalid language in ./language: ${lang}${RESET}"
    exit 1
    ;;
esac
