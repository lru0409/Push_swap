max=0
for var in {1..100}
do
    args="$(seq 100 | sort -R)"
    result=$(./push_swap $args | ./checker_Mac $args)
    command_count=$(./push_swap $args | wc -l | tr -d ' ')
    echo $result
    if [ $result == "KO" ]
    then
        echo $args
    else
        echo $command_count
        # echo $args
    fi
    if [ $((command_count)) -gt $((max)) ]
    then
        max=$command_count
    fi
done
printf "max: "
echo $max
