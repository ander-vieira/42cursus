rm -f test_output.txt

echo "NORMINETTE"
echo "---------------"
norminette -o repo/

echo "---------------"
echo "COMPILE"
echo "---------------"
make -C repo/ -s all clean
gcc test/test.c repo/libftprintf.a -o ft_printf
gcc test/test_printf.c -o printf

echo "---------------"
echo "TESTS (DIFF, OK IF BLANK)"
echo "---------------"
./ft_printf > ft_printf.out
./printf > printf.out
diff ft_printf.out printf.out

rm -f ft_printf printf
make -C repo/ -s fclean

echo "---------------"
echo "BONUS COMPILE"
echo "---------------"
make -C repo/ -s bonus clean
gcc test/test_bonus.c repo/libftprintf.a -o ft_printf
gcc test/test_printf_bonus.c -o printf

echo "---------------"
echo "BONUS TESTS (DIFF, OK IF BLANK)"
echo "---------------"
./ft_printf > ft_printf_bonus.out
./printf > printf_bonus.out
diff ft_printf_bonus.out printf_bonus.out

rm -f ft_printf printf
make -C repo/ -s fclean