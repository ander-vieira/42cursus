rm -f test_output.txt

echo "NORMINETTE"
echo "---------------"
norminette repo/

echo "---------------"
echo "COMPILE"
echo "---------------"
make -C repo/ -s all clean
gcc test/test.c repo/libftprintf.a -o ft_printf
gcc test/test_printf.c repo/libftprintf.a -o printf

echo "---------------"
echo "TESTS (DIFF, OK IF BLANK)"
echo "---------------"
./ft_printf > ft_printf.out
./printf > printf.out
diff ft_printf.out printf.out

rm -f ft_printf printf
make -C repo/ -s fclean