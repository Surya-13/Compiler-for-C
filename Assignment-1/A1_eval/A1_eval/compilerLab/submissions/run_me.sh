#!/bin/bash

rm -f *.log *.html *.csv
rm -rf reports_eval
mkdir reports_eval

for file in `ls *.tar.gz`;
do
	rollno=`echo $file | cut -d _ -f 1`;
	echo "evaluating $rollno..."
	bash eval.sh $rollno | tee reports_eval/$rollno.log
	bash ansi2html.sh < reports_eval/$rollno.log > reports_eval/$rollno.html
	rm -f reports_eval/$rollno.log
done

rm -f *.log *.html
rm -rf ../files/*

