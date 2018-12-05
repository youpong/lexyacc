./word-h <sample.input >tmp
./word-m <sample.input >tmp2
echo -n "Test 1 .."
if cmp tmp tmp2; then
    echo "pass"
fi
rm tmp tmp2
