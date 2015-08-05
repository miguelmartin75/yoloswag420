#!/bin/bash

interpreter="${1:-./ys420i}"
samples_dir="${2:-samples}"

[ ! -f $interpreter ] && echo "could not find $interpreter"

for file in $(ls $samples_dir)
do
    $interpreter $samples_dir/$file
done
