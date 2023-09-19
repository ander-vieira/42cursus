echo "NORMINETTE"
echo "---------------"
norminette repo/

echo "---------------"
echo "COMPILE (BUFFER_SIZE 1)"
echo "---------------"
gcc test/test.c test/testutils.c repo/get_next_line.c repo/get_next_line_utils.c -Irepo -D BUFFER_SIZE=1 -D TESTFILE_DIR=\"test/\" -o output

echo "---------------"
echo "TESTS (BUFFER_SIZE 1)"
echo "---------------"
./output
rm -f output

echo "---------------"
echo "COMPILE (BUFFER_SIZE 10)"
echo "---------------"
gcc test/test.c test/testutils.c repo/get_next_line.c repo/get_next_line_utils.c -Irepo -D BUFFER_SIZE=10 -D TESTFILE_DIR=\"test/\" -o output

echo "---------------"
echo "TESTS (BUFFER_SIZE 10)"
echo "---------------"
./output
rm -f output

echo "---------------"
echo "COMPILE (BUFFER_SIZE 1000)"
echo "---------------"
gcc test/test.c test/testutils.c repo/get_next_line.c repo/get_next_line_utils.c -Irepo -D BUFFER_SIZE=1000 -D TESTFILE_DIR=\"test/\" -o output

echo "---------------"
echo "TESTS (BUFFER_SIZE 1000)"
echo "---------------"
./output
rm -f output

echo "---------------"
echo "STDIN COMPILE (BUFFER_SIZE 10)"
echo "---------------"
gcc test/test_stdin.c test/testutils.c repo/get_next_line_bonus.c repo/get_next_line_utils_bonus.c -Irepo -D BUFFER_SIZE=10 -D TESTFILE_DIR=\"test/\" -o output

echo "---------------"
echo "STDIN TESTS (BUFFER_SIZE 10)"
echo "---------------"
cat test/stdin.txt | ./output
rm -f output

echo "---------------"
echo "BONUS COMPILE (BUFFER_SIZE 10)"
echo "---------------"
gcc test/test_bonus.c test/testutils.c repo/get_next_line_bonus.c repo/get_next_line_utils_bonus.c -Irepo -D BUFFER_SIZE=10 -D TESTFILE_DIR=\"test/\" -o output

echo "---------------"
echo "BONUS TESTS (BUFFER_SIZE 10)"
echo "---------------"
./output
rm -f output