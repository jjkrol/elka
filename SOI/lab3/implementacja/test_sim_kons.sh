#!/bin/bash
./prod1 $1 $2  & ./kons1 $1 $2 & ./kons2 $1 $2 & ./test $1 $2
