if [$# -ge 1]
then
	code_dir = "$1"
else
	code_dir = "repo"
fi

rm -f test_output.txt

echo "NORMINETTE" >> test_output.txt
echo "---------------" >> test_output.txt
norminette ${code_dir}/ >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "COMPILE" >> test_output.txt
echo "---------------" >> test_output.txt
make -C ${code_dir}/ -s bonus clean >> test_output.txt 2>&1
gcc test/*.c ${code_dir}/libft.a -I"../${code_dir}/" -o output >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "TESTS" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1

rm -f output
make -C ${code_dir}/ -s fclean