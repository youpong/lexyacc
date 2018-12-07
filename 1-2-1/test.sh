# returns 1 .. failed
#         0 .. success 
check_equality() {
    cat $2 | "$1" > tmp
    if ! cmp "$3" tmp; then
        return 1
    fi

    return 0
}

echo -n "Test: word 0..."
if check_equality ./word sample/0.input sample/0.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: word 1..."
if check_equality ./word sample/0.input sample/0.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: word 2..."
if check_equality ./word sample/2.input sample/2.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: word 3..."
if check_equality ./word sample/3.input sample/3.output; then
    echo "passed"
else
    echo "FAILED"
fi

rm tmp
