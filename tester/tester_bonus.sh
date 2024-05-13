for var in {1..100}
do
    args="$(seq 1 3 $var | sort -R | xargs)"
    result=$(../push_swap $args | ../checker $args)
    echo "$result"
    echo $args
done