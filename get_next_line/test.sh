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
echo "COMPILE (BUFFER_SIZE 1)" >> test_output.txt
echo "---------------" >> test_output.txt
gcc test/test.c test/testutils.c ${code_dir}/get_next_line.c ${code_dir}/get_next_line_utils.c -D BUFFER_SIZE=1 -I"../${code_dir}/" -o output >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "TESTS (BUFFER_SIZE 1)" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1
rm -f output

echo "---------------" >> test_output.txt
echo "COMPILE (BUFFER_SIZE 10)" >> test_output.txt
echo "---------------" >> test_output.txt
gcc test/test.c test/testutils.c ${code_dir}/get_next_line.c ${code_dir}/get_next_line_utils.c -D BUFFER_SIZE=10 -I"../${code_dir}/" -o output >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "TESTS (BUFFER_SIZE 10)" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1
rm -f output

echo "---------------" >> test_output.txt
echo "COMPILE (BUFFER_SIZE 1000)" >> test_output.txt
echo "---------------" >> test_output.txt
gcc test/test.c test/testutils.c ${code_dir}/get_next_line.c ${code_dir}/get_next_line_utils.c -D BUFFER_SIZE=1000 -I"../${code_dir}/" -o output >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "TESTS (BUFFER_SIZE 1000)" >> test_output.txt
echo "---------------" >> test_output.txt
./output >> test_output.txt 2>&1
rm -f output

echo "---------------" >> test_output.txt
echo "BONUS COMPILE (BUFFER_SIZE 10)" >> test_output.txt
echo "---------------" >> test_output.txt
gcc test/test_bonus.c test/testutils.c ${code_dir}/get_next_line_bonus.c ${code_dir}/get_next_line_utils_bonus.c -D BUFFER_SIZE=10 -I"../${code_dir}/" -o output_bonus >> test_output.txt 2>&1

echo "---------------" >> test_output.txt
echo "BONUS TESTS (BUFFER_SIZE 10)" >> test_output.txt
echo "---------------" >> test_output.txt
./output_bonus >> test_output.txt 2>&1
rm -f output_bonus