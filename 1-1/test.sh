# returns 1 .. failed
#         0 .. success 
check_equality() {
    for i in 0 1 2; do
	cat input | ./echo"$i" > output
	if ! cmp input output; then
	    return 1
	fi
    done

    return 0
}

echo -n "Test: 0  ..."
echo -ne '' > input
if check_equality; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: 1  ..."
echo -ne '.' > input
if check_equality; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: 2  ..."
echo -ne '\n' > input
if check_equality; then
    echo "passed"
else
    echo "FAILED"
fi

echo -n "Test: 3  ..."
echo -ne '.\n' > input
if check_equality; then
    echo "passed"
else
    echo "FAILED"
fi

rm input output
