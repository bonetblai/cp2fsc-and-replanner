#!/bin/bash

FILES=$(find . -regex ".*h.pddl")

for FILE in $FILES
do
    PROBLEM_SET=$(echo $FILE | cut -d'/' -f 2)
    echo  The problem set is: $PROBLEM_SET

    PROBLEM_INSTANCE=$(echo $FILE | cut -d'/' -f 3)
    echo  The problem instance is: $PROBLEM_INSTANCE

    HIDDEN=$(echo $FILE | cut -d'/' -f 4)
    echo The hidden file is: $HIDDEN

    echo Path is: $FILE

    DEFINITION=$(head -1 $FILE)
    echo First line should be: $DEFINITION

    LAST=$(tail -2 $FILE)
    echo First line should be: $LAST

    i=0
    IFS=$'\n'
    for LINE in $(cat $FILE | tail -n +2 |  sed \$d | sed \$d)
    do
        FIRST=$(echo $LINE | awk '{print $1}')
        SEMICOLON=';'
        if [ "$FIRST" != "$SEMICOLON" ]; then
            NEW_FILE=./$PROBLEM_SET/$PROBLEM_INSTANCE/h$i.pddl
            echo NEW FILE: $NEW_FILE WITH:
            touch $NEW_FILE
            echo $DEFINITION
            echo $DEFINITION >> $NEW_FILE
            echo "$LINE" 
            echo "$LINE" >> $NEW_FILE
            echo $LAST
            echo $LAST >> $NEW_FILE
            echo =====
            ((i++))
        fi
    done

    echo ''
done