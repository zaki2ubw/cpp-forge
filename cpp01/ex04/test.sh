#!/bin/bash

BIN=./miniSed
FILE=overlap.txt

make re || exit 1

cat > "$FILE" << 'EOF'
aaaaa
aaaaaa
abcabcabc
world
hello world
world hello
banana
a b  c
EOF

run_test() {
	echo "========================================"
	echo "TEST: $1"
	echo "CMD : $BIN $FILE \"$2\" \"$3\""
	echo "----------------------------------------"
	echo "[INPUT]"
	cat "$FILE"
	echo "----------------------------------------"
	$BIN "$FILE" "$2" "$3"
	echo "----------------------------------------"
	echo "[OUTPUT: $FILE.replace]"
	cat "$FILE.replace"
	echo
}

echo "========================================"
echo "ARGUMENT TESTS"
echo "========================================"

echo "[1] no args"
$BIN
echo

echo "[2] one arg"
$BIN "$FILE"
echo

echo "[3] two args"
$BIN "$FILE" "aa"
echo

echo "[4] too many args"
$BIN "$FILE" "aa" "b" "extra"
echo

echo "========================================"
echo "REPLACE TESTS"
echo "========================================"

run_test "overlap basic" "aa" "b"
run_test "overlap 3 chars" "aaa" "X"
run_test "delete target" "abc" ""
run_test "replace spaces" " " "_"
run_test "empty target" "" "X"
run_test "single char replace" "a" "X"
run_test "word replace" "world" "EARTH"
