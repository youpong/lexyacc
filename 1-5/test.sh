check_equality() {
    ./word-h1 $1 >tmp1
    ./word-m  $1 >tmp2
    
    cmp tmp1 tmp2
    return $?
}

check_equality2() {
    $1 $2 > tmp0
    cmp tmp0 $3
    return $?
}

echo -n "Test 0   .."
if check_equality sample/0.input; then
    echo "pass"
else
    echo "failed"
fi
echo -n "Test 0-0 .."
if check_equality2 ./word-h0 sample/0.input sample/0.output; then
    echo "pass"
else
    echo "faile"
fi


echo -n "Test 1   .."
if check_equality sample/1.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 1-0 .."
if check_equality2 ./word-h0 sample/1.input sample/1.output; then
    echo "pass"
else
    echo "faile"
fi

echo -n "Test 2   .."
if check_equality sample/2.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 2-0 .."
if check_equality2 ./word-h0 sample/2.input sample/2.output; then
    echo "pass"
else
    echo "faile"
fi

echo -n "Test 3   .."
if check_equality sample/3.input; then
    echo "pass"
else
    echo "failed"
fi

echo -n "Test 3-0 .."
if check_equality2 ./word-h0 sample/3.input sample/3.output; then
    echo "pass"
else
    echo "faile"
fi


rm tmp[012]
