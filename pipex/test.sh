echo "NORMINETTE"
echo "---------------"
norminette repo/

echo "---------------"
echo "COMPILE"
echo "---------------"
make -C repo/ -s all
gcc test/test1.c -o test1.out

echo "---------------"
echo "TESTS"
echo "---------------"
echo "USAGE TEST:"
repo/pipex
echo "TEST 1:"
repo/pipex test/testfile1.txt "./test1.out" "./test1.out" file1.out
<test/testfile1.txt ./test1.out | ./test1.out >file2.out
diff file1.out file2.out
echo "TEST LS/WC:"
repo/pipex test/testfile1.txt "ls -l" "wc -l" file1.out
<test/testfile1.txt ls -l | wc -l >file2.out
diff file1.out file2.out

make -C repo/ -s clean
rm -f test1.out