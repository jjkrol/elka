#!/bin/bash
./prod1 $1 $2 & ./prod2 $1 $2 & ./test $1 $2 
