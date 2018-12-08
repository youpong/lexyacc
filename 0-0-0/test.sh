# returns 1 .. failed
#         0 .. success 
check_equality() {
    cat "$2" | "$1" > tmp
    if ! cmp "$3" tmp; then
        return 1
    fi

    return 0
}

echo -n "Test: cl0  ..."
if check_equality ./cl0 sample/0.input sample/0.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: cl1  ..."
if check_equality ./cl1 sample/0.input sample/1.output; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: cl2  ..."
./cl2 sample/0.input sample/1.input >tmp
if cmp "sample/2.output" tmp; then
    echo "passed"
else
    echo "FAILED"
fi

rm tmp
