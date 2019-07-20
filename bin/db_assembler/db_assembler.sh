#!/usr/bin/env bash

unamestr=`uname`
if [[ "$unamestr" == 'Darwin' ]]; then
   SRCPATH=$(greadlink -f "../../")
else
   SRCPATH=$(readlink -f "../../")
fi

source $SRCPATH"/bin/bash_shared/includes.sh"

if [ -f "./config.sh"  ]; then
    source "./config.sh" # should overwrite previous
fi

function assemble() {
    # to lowercase
    database=${1,,}
    start_sql=$2
    with_base=$3
    with_updates=$4
    with_custom=$5

    uc=${database^^}

    name="DB_"$uc"_PATHS"
    v="$name[@]"
    base=("${!v}")

    name="DB_"$uc"_UPDATE_PATHS"
    v="$name[@]"
    updates=("${!v}")

    name='DB_'$uc'_CUSTOM_PATHS'
    v="$name[@]"
    custom=("${!v}")


    suffix_base="_base"
    suffix_upd="_update"
    suffix_custom="_custom"

    curTime=`date +%Y_%m_%d_%H_%M_%S`

    if [ $with_base = true ]; then
        echo "" > $OUTPUT_FOLDER$database$suffix_base".sql"


        if [ ! ${#base[@]} -eq 0 ]; then
            echo "Generating $OUTPUT_FOLDER$database$suffix_base ..."

            for d in "${base[@]}"
            do
                echo "Searching on $d ..."
                if [ ! -z $d ]; then
                    for entry in "$d"/*.sql "$d"/**/*.sql
                    do
                        if [[ -e $entry ]]; then
                            cat "$entry" >> $OUTPUT_FOLDER$database$suffix_base".sql"
                        fi
                    done
                fi
            done
        fi
    fi

    if [ $with_updates = true ]; then
        updFile=$OUTPUT_FOLDER$database$suffix_upd".sql"

        echo "" > $updFile

        if [ ! ${#updates[@]} -eq 0 ]; then
            echo "Generating $OUTPUT_FOLDER$database$suffix_upd ..."

            for d in "${updates[@]}"
            do
                echo "Searching on $d ..."
                if [ ! -z $d ]; then
                    for entry in "$d"/*.sql "$d"/**/*.sql
                    do
                        if [[ ! -e $entry ]]; then
                            continue
                        fi

                        echo "-- $file" >> $updFile
                        cat "$entry" >> $updFile
                    done
                fi
            done
        fi
    fi

    if [ $with_custom = true ]; then
        custFile=$OUTPUT_FOLDER$database$suffix_custom".sql"

        echo "" > $custFile

        if [ ! ${#custom[@]} -eq 0 ]; then
            echo "Generating $OUTPUT_FOLDER$database$suffix_custom ..."

            for d in "${custom[@]}"
            do
                echo "Searching on $d ..."
                if [ ! -z $d ]; then
                    for entry in "$d"/*.sql "$d"/**/*.sql
                    do
                        if [[ ! -e $entry ]]; then
                            continue
                        fi

                        echo "-- $file" >> $custFile
                        cat "$entry" >> $custFile
                    done
                fi
            done
        fi
    fi
}

function run() {
    echo "===== STARTING PROCESS ====="

        mkdir -p $OUTPUT_FOLDER

        for db in ${DATABASES[@]}
        do
            assemble "$db" $version".sql" $1 $2 $3
        done

    echo "===== DONE ====="
}

PS3='Please enter your choice: '
options=("Create ALL" "Create only bases" "Create only updates" "Create only customs" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Create ALL")
            run true true true
            break #avoid loop
            ;;
        "Create only bases")
            run true false false
            break #avoid loop
            ;;
        "Create only updates")
            run false true false
            break #avoid loop
            ;;
        "Create only customs")
            run false false true
            break #avoid loop
            ;;
        "Quit")
            break
            ;;
        *) echo invalid option;;
    esac
done
