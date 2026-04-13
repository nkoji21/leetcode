.PHONY: all init sc sl sv run

all:
	@./shell/build.sh

init:
	@./shell/init.sh

sc:
	@./shell/setcontest.sh

sl:
	@./shell/setlang.sh

sv:
	@./shell/solve.sh

run:
	@./shell/run.sh
