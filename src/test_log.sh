#!/bin/bash

RED='\033[1;31m'
GR='\033[1;32m'
NC='\033[0m'

info() {
    if [ "$(grep "FAILED TEST" test.log)" == "" ]
    then
        echo -e "${GR}-------------------------------------------------${NC}"
        echo -e "${GR}SUCCESS${NC}: $(grep "PASSED" test.log)"
        echo -e "${GR}-------------------------------------------------${NC}"
	else
        echo -e "${RED}-------------------------------------------------${NC}"
        echo -e "${RED}FAIL${NC}: $(grep "FAILED TEST" test.log)"
        echo -e "${RED}-------------------------------------------------${NC}"
	fi
}

info
