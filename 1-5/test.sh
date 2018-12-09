./word-h <sample/0.input >tmp
./word-m <sample/0.input >tmp2
echo -n "Test 1 .."
if cmp tmp tmp2; then
    echo "pass"
fi
rm tmp tmp2
