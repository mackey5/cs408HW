json: main.c jsmn.c
	gcc -fprofile-arcs -ftest-coverage -g -O0 -o $@ $^

clean:
	rm -f json *.gcda *.gcno *.gcov

