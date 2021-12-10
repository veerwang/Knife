all:	main.rel
	sdcc main.rel

main.rel:	main.c
	sdcc -mmcs51 -c main.c

clean:
	rm -f play*.* play *.rel *.sym *.lst *.asm *.lk *.ihx *.map *.mem *.rst
