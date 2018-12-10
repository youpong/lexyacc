check_equality() {
    ./word-h0 $1 >tmp0
    ./word-h1 $1 >tmp1
    ./word-m  $1 >tmp2
    
    cmp tmp0 tmp1 && cmp tmp0 tmp2
    return $?
}

echo -n "Test 0 .."
if check_equality sample/0.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 1 .."
if check_equality sample/1.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 2 .."
if check_equality sample/2.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 3 .."
if check_equality sample/3.input; then
    echo "pass"
else
    echo "failed"
fi

rm tmp[012]
