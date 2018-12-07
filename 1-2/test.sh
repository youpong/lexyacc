# returns 1 .. failed
#         0 .. success 
check_equality() {
    cat $2 | "$1" > tmp
    if ! cmp "$3" tmp; then
        return 1
    fi

    return 0
}

echo -n "Test: word0  ..."
if check_equality ./word0 sample.input 0.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: word1  ..."
if check_equality ./word1 sample.input 1.output; then
    echo "passed"
else
    echo "FAILED"
fi

rm tmp
