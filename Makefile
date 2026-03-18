.PHONY: all init setlang sv run

all:
	@./shell/build.sh

init:
	@./shell/init.sh

setlang:
	@./shell/setlang.sh

sv:
	@./shell/solve.sh

run:
	@./shell/run.sh
