#!/bin/bash

# Directories
INPUT_DIR=. # contains *.tar.gz file
TEST_CASES_DIR=../../testcases # contains all the testcases (both private and public)
SRC_DIR=../files # contains uncompressed source code

RED='\033[1;31m'
NC='\033[0m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'

if [ $# -lt 1 ]
then
  echo "usage: ./eval.sh <ROLL NUMBER>"
  exit
fi

#pwd > prd

# Extract student directory
ROLL_NO=$1
tar -xzf ${INPUT_DIR}/${ROLL_NO}_A2.tar.gz -C $SRC_DIR

#if test -f "$FILE"; then
#    cd ${SRC_DIR}/${ROLL_NO}/
#else 
#	cd ${SRC_DIR}/${ROLL_NO}_A2/
#fi
cd ${SRC_DIR}/${ROLL_NO}/
rm -f a.out
make > /dev/null
if [ ! -f a.out ]; then
  echo "Make failed!"
  exit
fi

cd - > /dev/null
echo 
# Execute testcases
marks=0
echo "Evaluating $ROLL_NO"
echo "-------------------"
cd ${SRC_DIR}/${ROLL_NO}/
count=0
for testcase in `ls $TEST_CASES_DIR/input*.c`
do
  rm -f output curr exp
  xps=0;
  printf "\n\n---------------------------------------------------------------------"
  test_no_c=`echo "$testcase" | sed "s/.*\///"`
  test_no=$(echo "$(cut -d'.' -f1 <<<"$test_no_c")")
  no=$(echo "$(cut -d'_' -f2 <<<"$test_no")")  
  printf "\nexecuting testcase $no \n"
  #cd ${ROLL_NO}/
  ./a.out < $testcase > output 2>/dev/null
  printf "expected output\n"
  cat ${TEST_CASES_DIR}/output_${no}.txt
  printf "\nyour output\n"
  cat output

  #sed  '1q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
 # flag=$(wc -c exp | cut -d' ' -f1);
  #if(($flag > 0)); then
	#rm -f exp	
  	sed  '1q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	sed  '1q;d' output > curr;
  	val=$(diff -w exp curr | grep "^>" | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
	  fi
	
	sed  '2q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
	sed  '2q;d' output > curr;
  
  	val=$(diff -w exp curr | grep "^>" | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	sed  '3q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	sed  '3q;d' output > curr;
  
  	val=$(diff -w exp curr | grep "^>" | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	sed  '4q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	sed  '4q;d' output > curr;
  
  	val=$(diff -w exp curr | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi
 
  	sed  '5q;d' ${TEST_CASES_DIR}/output_${no}.txt > exp;
  	sed  '5q;d' output > curr;
  
  	val=$(diff -w exp curr | grep "^>" | wc -l)
  	if [ $val -eq 0 ]; then
		xps=$((xps+1));
  	fi

  	  #fi
  #grep -e "error" output > errlines;
  errcount=$(grep -e "error" output | wc -l)
  xdiff=$(diff -w output ${TEST_CASES_DIR}/output_${no}.txt | grep "^>" | wc -l);
  lines=`wc -l output | cut -d' ' -f1`;
  hold=`wc -l ${TEST_CASES_DIR}/output_${no}.txt | cut -d' ' -f1`;

  #echo "xps=${xps}";
  
  if(($xdiff ==  0)); then
	if((${lines} > 0 && ${xps} != 0)); then # parsing-successful complete
  		xps=`echo "scale=2; $xps / 5.0" | bc -l`;
		per=`echo "scale=2; $xps * 100.0" | bc -l`
		if [ $errcount -gt 0 ]; then
			per=0
			xdiff=5
		else
			count=`echo "scale=2; $count + $xps" | bc -l`;
		fi
		echo -e "\ntestcase $no: ${GREEN}passed${NC} ${per}% (complete)"
		printf "${CYAN}diff = $xdiff${NC}\n"
		printf "${YELLOW}#lines (expected)=${hold}\n#lines (your)=${lines}${NC}\n"
	fi
  else
	if((${lines} > 0 && ${xps} != 0)); then # parsing-successful partial
  		xps=`echo "scale=2; $xps / 5.0" | bc -l`;
		per=`echo "scale=2; $xps * 100.0" | bc -l`
		#count=`echo "scale=2; $count + $xps" | bc -l`;
		if [ $errcount -gt 0 ]; then
			per=0;
			xdiff=5;
		else
			count=`echo "scale=2; $count + $xps" | bc -l`;
		fi
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
printf "\n\n*********************************************************************\n\t\t\tMarks: $marks / 10.00\n*********************************************************************\n\n"
rm -f output curr exp errlines
cd ../../submissions
echo "$ROLL_NO $marks" >> marks.txt
