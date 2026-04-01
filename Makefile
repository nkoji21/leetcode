.PHONY: all init sl sv run

all:
	@./shell/build.sh

init:
	@./shell/init.sh

sl:
	@./shell/setlang.sh

sv:
	@./shell/solve.sh

run:
	@./shell/run.sh
