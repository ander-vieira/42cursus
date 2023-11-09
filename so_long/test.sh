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
echo "INCORRECT PARAMS TEST 1:"
repo/so_long
echo "INCORRECT PARAMS TEST 2:"
repo/so_long a b
echo "WRONG FILE EXTENSION TEST:"
repo/so_long a
echo "FILE NOT FOUND TEST:"
repo/so_long a.ber
echo "INCORRECT MAP TEST 1 (map_b1.ber):"
repo/so_long repo/maps/map_b1.ber
echo "INCORRECT MAP TEST 2 (map_b2.ber):"
repo/so_long repo/maps/map_b2.ber
echo "CORRECT TEST (map_g1.ber):"
repo/so_long repo/maps/map_g1.ber

make -C repo/ -s clean