#!/bin/bash

# Directories
INPUT_DIR=. # contains *.tar.gz file
TEST_CASES_DIR=../testcases # contains all the testcases (both private and public)
SRC_DIR=../files # contains uncompressed source code

RED='\033[1;31m'
NC='\033[0m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'

if [ $# -lt 1 ]
then
  echo "usage: ./eval2.sh <ROLL NUMBER>"
  exit
fi

# Extract student directory
ROLL_NO=$1
tar -xzf ${INPUT_DIR}/${ROLL_NO}_A1.tar.gz -C $SRC_DIR

cd ${SRC_DIR}/${ROLL_NO}_A1/
rm -f a.out
make > /dev/null
if [ ! -f a.out ]; then
  echo "Make failed!"
  exit
fi

cd - > /dev/null

# Execute testcases
marks=0
echo "Evaluating $ROLL_NO"
echo "-------------------"

count=0
for testcase in `ls $TEST_CASES_DIR/*.c`
do
  rm -f output curr exp
  xps=0;
  le=0;
  se=0;
  printf "\n\n---------------------------------------------------------------------"
  printf "\nexecuting ${testcase}\n"
  test_no_c=`echo "$testcase" | sed "s/.*\///"`
  test_no=$(echo "$(cut -d'.' -f1 <<<"$test_no_c")")
  no=$(echo "$(cut -d'_' -f2 <<<"$test_no")")  
  timeout 2 ${SRC_DIR}/${ROLL_NO}_A1/a.out $testcase > output 2>/dev/null
  printf "expected output\n"
  cat ${TEST_CASES_DIR}/output_${no}.txt
  printf "\nyour output\n"
  cat output

  grep -e "***parsing successful***" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  flag=$(wc -c exp | cut -d' ' -f1);
  if(($flag > 0)); then
	rm -f exp	
  	grep -e "***parsing successful***" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "***parsing successful***" output > curr;

  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
	fi
	
	grep -e "#global_declarations" ${TEST_CASES_DIR}/output_${no}.txt > exp;
	grep -e "#global_declarations" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	grep -e "#function_definitions" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "#function_definitions" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	grep -e "#integer_constants" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "#integer_constants" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi
 
  	grep -e "#pointers_declarations" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "#pointers_declarations" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	grep -e "#ifs_without_else" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "#ifs_without_else" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi
 
	grep -e "if-else max-depth" ${TEST_CASES_DIR}/output_${no}.txt > exp;
	grep -e "if-else max-depth" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi
  else
	grep -e "***lexing terminated*** [lexer error]: ill-formed comment" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "***lexing terminated*** [lexer error]: ill-formed comment" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if(($val == 0)); then
		le=$((le+1));
 	fi

  	grep -e "***parsing terminated*** [syntax error]" ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	grep -e "***parsing terminated*** [syntax error]" output > curr;
  
  	val=$(diff exp curr | wc -l)
  	if(($val == 0)); then
		se=$((se+1));
  	fi
  fi

  xdiff=$(diff output ${TEST_CASES_DIR}/output_${no}.txt | wc -l);
  lines=`wc -l output | cut -d' ' -f1`;
  hold=`wc -l ${TEST_CASES_DIR}/output_${no}.txt | cut -d' ' -f1`;

  #echo "xps=${xps}";
  
  if(($xdiff ==  0)); then
	if((${lines} > 0 && ${xps} != 0)); then # parsing-successful complete
  		xps=`echo "scale=2; $xps / 7.0" | bc -l`;
		per=`echo "scale=2; $xps * 100.0" | bc -l`
		count=`echo "scale=2; $count + $xps" | bc -l`;
		echo -e "\ntestcase $no: ${GREEN}passed${NC} ${per}% (complete)"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
  	elif((${lines} > 0 && ${le} != 0)); then # lexer-error
		per=`echo "scale=2; $le * 100.0" | bc -l`
		count=`echo "scale=2; $count + $le" | bc -l`;
		echo -e "\ntestcase $no: ${GREEN}passed${NC} ${per}% (complete)"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
  	elif((${lines} > 0 && ${se} != 0)); then # syntax-error
		per=`echo "scale=2; $le * 100.0" | bc -l`
		count=`echo "scale=2; $count + $se" | bc -l`;
		echo -e "\ntestcase $no: ${GREEN}passed${NC} ${per}% (complete)"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
	fi
  else
	if((${lines} > 0 && ${xps} != 0)); then # parsing-successful partial
  		xps=`echo "scale=2; $xps / 7.0" | bc -l`;
		per=`echo "scale=2; $xps * 100.0" | bc -l`
		count=`echo "scale=2; $count + $xps" | bc -l`;
		echo -e "\ntestcase $no: ${GREEN}passed${NC} ${per}% (partial)"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
	else
		echo -e "\ntestcase $no: ${RED}failed${NC}"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
	fi
  fi

done 

marks=$(echo "scale=2; $count / 2.0" | bc -l)
printf "\n\n*********************************************************************\n\t\t\tMarks: $marks / 7.00\n*********************************************************************\n\n"
rm -f output curr exp
echo "$ROLL_NO $marks" >> eval2.csv
