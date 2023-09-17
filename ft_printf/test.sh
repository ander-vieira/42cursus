rm -f test_output.txt

echo "NORMINETTE" >> test_output.txt
echo "---------------" >> test_output.txt
norminette repo/ >> test_output.txt 2>&1

make -C repo/ -s all clean
gcc test/*.c repo/libftprintf.a -o output

echo "---------------" >> test_output.txt
echo "TESTS" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1

rm -f output
make -C repo/ -s fclean