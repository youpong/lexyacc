./word  <sample.input >tmp
./word2 <sample.input >tmp2
echo -n "Test 1 .."
if cmp tmp tmp2; then
    echo "pass"
fi
rm tmp tmp2
