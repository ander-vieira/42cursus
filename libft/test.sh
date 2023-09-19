rm -f test_output.txt

echo "NORMINETTE"
echo "---------------"
norminette repo/

echo "---------------"
echo "COMPILE"
echo "---------------"
make -C repo/ -s bonus clean
gcc test/*.c repo/libft.a -o output

echo "---------------"
echo "TESTS"
echo "---------------"
./output

rm -f output tmp_fd
make -C repo/ -s fclean