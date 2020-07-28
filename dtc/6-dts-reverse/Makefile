all:
	dtc -O dtb -b 0 -o init.dtb init.dts
src:
	dtc -I dtb -O dts -o init.dts.new init.dtb
clean:
	rm -rf *.dtb init.dts.new

