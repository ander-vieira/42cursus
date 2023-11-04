echo "NORMINETTE"
echo "---------------"
norminette repo/*.c repo/*.h

echo "---------------"
echo "COMPILE"
echo "---------------"
make -C repo/ -s all

echo "---------------"
echo "TESTS"
echo "---------------"
echo "ERROR TEST 1:"
repo/so_long
echo "ERROR TEST 2:"
repo/so_long a
echo "CORRECT CALL TEST:"
repo/so_long a.ber

make -C repo/ -s clean