.PHONY: init setlang sv run

init:
	@./shell/init.sh

setlang:
	@./shell/setlang.sh

sv:
	@./shell/solve.sh

run:
	@./shell/run.sh
