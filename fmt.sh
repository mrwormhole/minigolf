#!/bin/bash

find . -path ./build -prune -o -iname "*.c" -o -iname "*.h"|sed 's/.\/build//'|xargs clang-format -i --verbose
