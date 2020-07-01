#! /usr/bin/awk -f

function disp(times) {
	for (i = 0; i < times; ++i) {
		print "Don't Panic!";
	}
}

BEGIN {
	disp(2);
}
