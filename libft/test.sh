rm -f test_output.txt

echo "NORMINETTE" >> test_output.txt
echo "---------------" >> test_output.txt
norminette repo/ >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "COMPILE" >> test_output.txt
echo "---------------" >> test_output.txt
make -C repo/ -s bonus clean >> test_output.txt 2>&1
gcc test/*.c ../test/testutils.c repo/libft.a -o output >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "TESTS" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1

rm -f output
make -C repo/ -s fclean