# returns 1 .. failed
#         0 .. success 
check_equality() {
    cat $2 | "$1" > tmp
    if ! cmp "$3" tmp; then
        return 1
    fi

    return 0
}

echo -n "Test: ./comment normal..."
if check_equality ./comment sample/0.input sample/0.output; then
    echo "passed"
else
    echo "FAILED"
fi

rm tmp
