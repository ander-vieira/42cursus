cd repo/
norminette
make all clean
cp libftprintf.a libftprintf.h ../test/
make fclean
cd ../test/
gcc test.c libftprintf.a -o output
echo "RUNNING TESTS"
./output
rm libftprintf.a libftprintf.h output